#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_createBuiltObject
 * Creates actual object (server-side in MP)
 * Supports auto-level via vectorDirAndUp.
 * Stores resource cost for demolish refund.
 */

params [
    ["_classname", "", [""]],
    ["_pos", [0,0,0], [[]]],
    ["_dir", 0, [0]],
    ["_vecDir", [], [[]]],
    ["_vecUp", [], [[]]]
];

if (_classname isEqualTo "") exitWith {objNull};

private _obj = createVehicle [_classname, ASLToAGL _pos, [], 0, "NONE"];

_obj setPosASL _pos;

// Use vectorDirAndUp if provided (auto-level), otherwise derive from direction
if (count _vecDir == 3 && count _vecUp == 3) then {
    _obj setVectorDirAndUp [_vecDir, _vecUp];
} else {
    _obj setVectorDirAndUp [[sin _dir, cos _dir, 0], [0, 0, 1]];
};

_obj setPosASL _pos;

// Disable collision and damage to prevent physics interference
_obj allowDamage false;

// Enable simulation for objects that need it (lights, etc), disable for static fortifications
private _needsSimulation = _classname in ["land_TKE_MilLight"];
_obj enableSimulation _needsSimulation;

// Store metadata
_obj setVariable [QGVAR(builtObject), true, true];
_obj setVariable [QGVAR(builtBy), name player, true];
_obj setVariable [QGVAR(builtTime), serverTime, true];

// Store cost for demolish refund
private _cost = [_classname] call FUNC(getObjectCost);
_obj setVariable [QGVAR(builtCost), _cost, true];

if (isNil QGVAR(builtObjects)) then {
    GVAR(builtObjects) = [];
};
GVAR(builtObjects) pushBack _obj;
publicVariable QGVAR(builtObjects);

diag_log format ["[OLI Engineering] %1 built %2 at %3 (cost: %4)", name player, _classname, _pos, _cost];

_obj
