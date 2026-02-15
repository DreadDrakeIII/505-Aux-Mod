#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_createBuiltObject
 * Creates actual object (server-side in MP)
 * Supports auto-level via vectorDirAndUp.
 * Stores resource cost for demolish refund.
 *
 * ROTATION FIX (v3 - dedicated server safe):
 *   OPTRE models get auto-aligned by Arma's physics engine during
 *   the first simulation tick after createVehicle. On dedicated servers
 *   this happens before enableSimulation can stop it.
 *
 *   Solution: Create at [0,0,0] (no terrain = nothing to align to),
 *   disable simulation globally, THEN move into position.
 *   Triple re-apply vectors to survive network sync.
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

// ── STEP 1: Create at origin [0,0,0] — NO terrain there = NO auto-align ────
private _obj = createVehicle [_classname, [0,0,0], [], 0, "CAN_COLLIDE"];

// ── STEP 2: Kill physics IMMEDIATELY before engine gets a tick ──────────────
private _needsSimulation = _classname in ["land_TKE_MilLight"];
_obj enableSimulationGlobal false;
_obj allowDamage false;

// ── STEP 3: Now safe to position — engine can't fight us ────────────────────
_obj setVectorDirAndUp [_finalVecDir, _finalVecUp];
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

// Store vectors so we can verify later
_obj setVariable [QGVAR(builtVecDir), _finalVecDir, true];
_obj setVariable [QGVAR(builtVecUp), _finalVecUp, true];

if (isNil QGVAR(builtObjects)) then {
    GVAR(builtObjects) = [];
};
GVAR(builtObjects) pushBack _obj;
publicVariable QGVAR(builtObjects);

// ── STEP 4: Re-apply vectors multiple times to beat network sync ────────────
// On dedicated servers, JIP and locality transfers can reset vectors.
// We hammer it 3 times across 3 frames to guarantee it sticks.
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

diag_log format ["[OLI Engineering] %1 built %2 at %3 vecDir:%4 vecUp:%5",
    name player, _classname, _pos, _finalVecDir, _finalVecUp];

_obj
