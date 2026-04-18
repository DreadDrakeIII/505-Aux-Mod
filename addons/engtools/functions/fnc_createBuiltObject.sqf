#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_createBuiltObject
 * Creates actual object (server-side in MP).
 * Vectors read from ghost at placement time — always explicit.
 * Stores resource cost for demolish refund.
 *
 * v11 FIX: Spawn at high altitude with "NONE" flag so no terrain/physics
 * can nudge the object before simulation is disabled. Then teleport to
 * exact ASL position. Eliminates the position-drift-on-place bug seen
 * on the 505th server.
 */

params [
    ["_classname", "", [""]],
    ["_pos", [0,0,0], [[]]],
    ["_dir", 0, [0]],
    ["_vecDir", [], [[]]],
    ["_vecUp", [], [[]]]
];

if (_classname isEqualTo "") exitWith {objNull};

// Compute final vectors - ALWAYS explicit, never rely on engine defaults
private _finalVecDir = if (count _vecDir == 3) then { _vecDir } else { [sin _dir, cos _dir, 0] };
private _finalVecUp  = if (count _vecUp == 3)  then { _vecUp }  else { [0, 0, 1] };

// ── STEP 1: Spawn at high altitude with "NONE" ─────────────────────────────
// Spawning at [0,0,3000] with "NONE" means there is no terrain, no collision
// surface, and no physics tick to bounce against before we kill simulation.
// CAN_COLLIDE was causing a one-frame engine nudge on the server that shifted
// the final position away from where the player placed it.
private _needsSimulation = _classname in ["land_TKE_MilLight"];
private _obj = createVehicle [_classname, [0, 0, 3000], [], 0, "NONE"];

// ── STEP 2: Kill physics BEFORE moving to final position ────────────────────
_obj enableSimulationGlobal false;
_obj allowDamage false;

// ── STEP 3: Teleport to exact ASL position with correct vectors ─────────────
_obj setPosASL _pos;
_obj setVectorDirAndUp [_finalVecDir, _finalVecUp];
_obj setPosASL _pos;

// ── Metadata ────────────────────────────────────────────────────────────────
_obj setVariable [QGVAR(builtObject), true, true];
_obj setVariable [QGVAR(builtBy), name player, true];
_obj setVariable [QGVAR(builtTime), serverTime, true];

// Store cost for demolish refund
private _cost = [_classname] call FUNC(getObjectCost);
_obj setVariable [QGVAR(builtCost), _cost, true];

// Store vectors for verification
_obj setVariable [QGVAR(builtVecDir), _finalVecDir, true];
_obj setVariable [QGVAR(builtVecUp), _finalVecUp, true];

if (isNil QGVAR(builtObjects)) then {
    GVAR(builtObjects) = [];
};
GVAR(builtObjects) pushBack _obj;
publicVariable QGVAR(builtObjects);

// ── STEP 4: Re-apply vectors across multiple frames for network sync ────────
// Keeps position locked against any late engine adjustments on remote clients.
[_obj, _pos, _finalVecDir, _finalVecUp, _needsSimulation] spawn {
    params ["_o", "_p", "_vd", "_vu", "_sim"];

    // Frame 1
    sleep 0.05;
    if (isNull _o) exitWith {};
    _o setVectorDirAndUp [_vd, _vu];
    _o setPosASL _p;

    // Frame 2
    sleep 0.05;
    if (isNull _o) exitWith {};
    _o setVectorDirAndUp [_vd, _vu];
    _o setPosASL _p;

    // Frame 3 — final lock, re-enable sim if needed
    sleep 0.05;
    if (isNull _o) exitWith {};
    _o setVectorDirAndUp [_vd, _vu];
    _o setPosASL _p;
    if (_sim) then { _o enableSimulationGlobal true; };
};

_obj
