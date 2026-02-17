#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_createBuiltObject
 * Creates actual object (server-side in MP).
 * Vectors read from ghost at placement time — always explicit.
 * Stores resource cost for demolish refund.
 *
 * v10 FIX: Create at ACTUAL POSITION (ACE approach).
 * Previous [0,0,0] trick caused first-build objects to vanish on
 * some maps where origin has no valid terrain. ACE creates directly
 * at the target position and immediately applies vectors — we do
 * the same but also disable simulation for heavy OPTRE models.
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

// ── STEP 1: Create directly at target position ─────────────────────────────
// ACE approach: create at the actual location, apply vectors immediately.
// Using "CAN_COLLIDE" to prevent engine from searching for empty space.
private _obj = createVehicle [_classname, ASLToAGL _pos, [], 0, "CAN_COLLIDE"];

// ── STEP 2: Kill physics IMMEDIATELY ────────────────────────────────────────
private _needsSimulation = _classname in ["land_TKE_MilLight"];
_obj enableSimulationGlobal false;
_obj allowDamage false;

// ── STEP 3: Apply vectors and position — override any engine alignment ──────
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

// ── STEP 4: Re-apply vectors across multiple frames for network sync ────────
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
