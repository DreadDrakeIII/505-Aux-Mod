#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_createBuiltObject
 * Creates actual object (server-side in MP)
 */

params [
    ["_classname", "", [""]],
    ["_pos", [0,0,0], [[]]],
    ["_dir", 0, [0]]
];

if (_classname isEqualTo "") exitWith {objNull};

private _obj = createVehicle [_classname, ASLToAGL _pos, [], 0, "NONE"];

// Double-set approach: position before AND after rotation (prevents model-origin shifting)
_obj setPosASL _pos;
_obj setDir _dir;
_obj setPosASL _pos;

// Disable collision and damage to prevent physics interference
_obj allowDamage false;
_obj enableSimulation false;

_obj setVariable [QGVAR(builtObject), true, true];
_obj setVariable [QGVAR(builtBy), name player, true];
_obj setVariable [QGVAR(builtTime), serverTime, true];

if (isNil QGVAR(builtObjects)) then {
    GVAR(builtObjects) = [];
};
GVAR(builtObjects) pushBack _obj;
publicVariable QGVAR(builtObjects);

diag_log format ["[OLI Engineering] %1 built %2 at %3", name player, _classname, _pos];

_obj
