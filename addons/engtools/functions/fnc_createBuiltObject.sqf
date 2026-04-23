#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_createBuiltObject
 *
 * DEDICATED-SERVER HARDENED — written for production milsim ops on a
 * dedicated server where any client could have any connection quality.
 * Behaviour on self-hosted Eden preview is unchanged in outcome (the
 * extra hardening is either no-op or redundant when the server IS the
 * client), but it is REQUIRED on a real dedicated server to prevent
 * position drift on remote clients.
 *
 * Differences vs the previous version:
 *
 *  1. hideObjectGlobal true during setup frames — the engine will not
 *     tick physics on an invisible object, which eliminates the
 *     "one-frame settle" bug where createVehicle runs a single physics
 *     step before enableSimulationGlobal false fires.
 *
 *  2. setOwner 2 — forces the server to be the authoritative owner so
 *     clients can't run local simulation on it and desync.
 *
 *  3. setPosWorld is used alongside setPosASL. setPosWorld has Global
 *     Effect (per BI wiki) and forces a network broadcast tick that
 *     setPosASL on its own doesn't reliably trigger on a dedi server.
 *
 *  4. Target settle time reduced from ~2s to 0.2s per user profile.
 *     Three fast re-applies (0.05s / 0.10s / 0.20s) instead of five
 *     spread out to 1.5s. Accept minor edge cases on terrible
 *     connections in exchange for snappier builds for everyone else.
 *
 *  5. RPT logging: if the object's final ASL position differs from
 *     the ghost's captured ASL position by more than 0.05m, a warning
 *     is emitted. Lets you catch placement drift empirically.
 *
 *  6. syncBuiltPos is still broadcast to all clients, but the client
 *     side now has a self-correcting retry loop (see fnc_syncBuiltPos).
 *
 * Parameters:
 *   _classname - Object classname                [STRING]
 *   _pos       - ASL position (ghost snapshot)   [ARRAY]
 *   _dir       - Fallback yaw if vectors empty   [NUMBER]
 *   _vecDir    - Ghost vectorDir                 [ARRAY]
 *   _vecUp    -  Ghost vectorUp                  [ARRAY]
 *   _builtBy   - Builder's display name          [STRING]
 */

params [
    ["_classname", "", [""]],
    ["_pos", [0,0,0], [[]]],
    ["_dir", 0, [0]],
    ["_vecDir", [], [[]]],
    ["_vecUp", [], [[]]],
    ["_builtBy", "", [""]]
];

if (_classname isEqualTo "") exitWith { objNull };

// Fallbacks for orientation — if the caller didn't supply full vectors,
// derive a flat yaw-only orientation from _dir.
private _finalVecDir = if (count _vecDir == 3) then { _vecDir } else { [sin _dir, cos _dir, 0] };
private _finalVecUp  = if (count _vecUp == 3)  then { _vecUp }  else { [0, 0, 1] };

private _builderName = _builtBy;
if (_builderName isEqualTo "") then {
    _builderName = if (!isNull player) then { name player } else { "Unknown" };
};

// Objects that genuinely need physics simulation to function correctly.
// These get enableSimulationGlobal true re-applied at the end of settle.
// Everything else stays frozen forever.
private _needsSimulation = _classname in ["land_TKE_MilLight"];

// ── CREATE ───────────────────────────────────────────────────────────────
// createVehicle with [], 0, "NONE" prevents the engine's placement
// algorithm from adjusting the spawn position. ASLToAGL converts our
// ASL target to the AGL format createVehicle expects.
private _obj = createVehicle [_classname, ASLToAGL _pos, [], 0, "NONE"];
if (isNull _obj) exitWith {
    diag_log format ["[OLI_engtools] createBuiltObject: createVehicle returned objNull for class '%1'", _classname];
    objNull
};

// ── FREEZE BEFORE ANYTHING ELSE ──────────────────────────────────────────
// Order matters: hide → freeze sim → kill damage → zero velocity.
// hideObjectGlobal is the key new step. An invisible object does not
// get physics ticks, so there is no window where the engine can settle
// it between createVehicle and enableSimulationGlobal false.
_obj hideObjectGlobal true;
_obj enableSimulationGlobal false;
_obj allowDamage false;
_obj setVelocity [0,0,0];

// Server authority — clients must not predict this object locally.
// setOwner requires the object to be server-local already (it is,
// because we called createVehicle server-side), so this is a no-op
// on the current owner but prevents any automatic reassignment later.
if (isServer) then { _obj setOwner 2; };

// ── APPLY TRANSFORM ──────────────────────────────────────────────────────
// setVectorDirAndUp can nudge position by a few mm, so the pattern is:
// orientation → position → orientation → position, with setPosWorld
// at the end to force a network broadcast with both committed.
_obj setVectorDirAndUp [_finalVecDir, _finalVecUp];
_obj setPosASL _pos;
_obj setVectorDirAndUp [_finalVecDir, _finalVecUp];
_obj setPosASL _pos;
_obj setPosWorld getPosWorld _obj;  // forces orientation + position broadcast
_obj setVelocity [0,0,0];
_obj awake true;

// ── METADATA (all publicly broadcast so clients can read it too) ─────────
_obj setVariable [QGVAR(builtObject), true, true];
_obj setVariable [QGVAR(builtBy), _builderName, true];
_obj setVariable [QGVAR(builtTime), serverTime, true];

private _cost = [_classname] call FUNC(getObjectCost);
_obj setVariable [QGVAR(builtCost), _cost, true];
_obj setVariable [QGVAR(builtVecDir), _finalVecDir, true];
_obj setVariable [QGVAR(builtVecUp), _finalVecUp, true];

if (isNil QGVAR(builtObjects)) then { GVAR(builtObjects) = []; };
GVAR(builtObjects) pushBack _obj;
publicVariable QGVAR(builtObjects);

// ── SERVER-SIDE FAST SETTLE (0.05 / 0.10 / 0.20s) ────────────────────────
// Three re-applies inside 0.2s. Each one re-asserts position, orientation,
// and zero velocity, then broadcasts via setPosWorld. Final call reveals
// the object (hideObjectGlobal false) and — for the simulation whitelist
// — re-enables physics.
//
// Position-mismatch RPT logging runs at the end: compares the final
// getPosASL against the ghost snapshot _pos and emits a warning if the
// Euclidean distance exceeds 0.05m. Catches drift empirically in real
// ops so you can identify which classnames misbehave.
[_obj, _pos, _finalVecDir, _finalVecUp, _needsSimulation, _classname, _builderName] spawn {
    params ["_o", "_p", "_vd", "_vu", "_sim", "_cls", "_builder"];

    sleep 0.05;
    if (isNull _o) exitWith {};
    _o setVectorDirAndUp [_vd, _vu];
    _o setPosASL _p;
    _o setPosWorld getPosWorld _o;
    _o setVelocity [0,0,0];

    sleep 0.05;  // cumulative 0.10s
    if (isNull _o) exitWith {};
    _o setVectorDirAndUp [_vd, _vu];
    _o setPosASL _p;
    _o setPosWorld getPosWorld _o;
    _o setVelocity [0,0,0];

    sleep 0.10;  // cumulative 0.20s
    if (isNull _o) exitWith {};
    _o setVectorDirAndUp [_vd, _vu];
    _o setPosASL _p;
    _o setPosWorld getPosWorld _o;
    _o setVelocity [0,0,0];

    // Reveal and (optionally) enable simulation
    _o hideObjectGlobal false;
    if (_sim) then { _o enableSimulationGlobal true; };

    // ── Drift check (RPT log) ──────────────────────────────────────────
    // Measure Euclidean distance between ghost snapshot and final pos.
    // 0.05m threshold = 5cm, which is larger than floating-point error
    // but smaller than any real placement bug.
    private _finalPos = getPosASL _o;
    private _drift = _p vectorDistance _finalPos;
    if (_drift > 0.05) then {
        diag_log format [
            "[OLI_engtools] PLACEMENT DRIFT: class=%1 builder=%2 drift=%3m ghost=%4 final=%5",
            _cls, _builder, (round (_drift * 10000) / 10000), _p, _finalPos
        ];
    };
};

// ── CLIENT-SIDE CORRECTION BROADCAST ─────────────────────────────────────
// Fires syncBuiltPos on every machine (server included, -2 target, with
// JIP persistence = true so late-joiners also get it). The client-side
// function has its own retry loop for the "object hasn't arrived yet"
// case — see fnc_syncBuiltPos for details.
[_obj, _pos, _finalVecDir, _finalVecUp] remoteExec [QFUNC(syncBuiltPos), -2, true];

_obj
