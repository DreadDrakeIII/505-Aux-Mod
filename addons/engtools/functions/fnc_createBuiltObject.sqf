#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_createBuiltObject
 * Creates the actual built object (server-side in MP).
 *
 * v13 fixes:
 * - Accepts _builtBy from client (name player on server = "HQ" in MP)
 * - enableSimulationGlobal BEFORE allowDamage — no physics tick can run first
 * - setVelocity [0,0,0] to kill any residual momentum
 * - setPosATL + setPosASL combo avoids sinking on slopes
 * - awake true forces engine to acknowledge final position
 * - 3-frame re-apply loop for reliable network sync
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

private _finalVecDir = if (count _vecDir == 3) then { _vecDir } else { [sin _dir, cos _dir, 0] };
private _finalVecUp  = if (count _vecUp == 3)  then { _vecUp }  else { [0, 0, 1] };

private _builderName = _builtBy;
if (_builderName isEqualTo "") then {
    _builderName = if (!isNull player) then { name player } else { "Unknown" };
};

private _needsSimulation = _classname in ["land_TKE_MilLight"];

private _obj = createVehicle [_classname, ASLToAGL _pos, [], 0, "NONE"];
if (isNull _obj) exitWith { objNull };

// Kill simulation FIRST — must come before allowDamage
_obj enableSimulationGlobal false;
_obj allowDamage false;
_obj setVelocity [0,0,0];

_obj setPosATL (ASLToAGL _pos);
_obj setVectorDirAndUp [_finalVecDir, _finalVecUp];
_obj setPosASL _pos;
_obj setVelocity [0,0,0];
_obj awake true;

// Metadata
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

// Re-apply over 3 frames for reliable network sync
[_obj, _pos, _finalVecDir, _finalVecUp, _needsSimulation] spawn {
    params ["_o", "_p", "_vd", "_vu", "_sim"];

    sleep 0.05;
    if (isNull _o) exitWith {};
    _o setPosASL _p; _o setVectorDirAndUp [_vd, _vu]; _o setVelocity [0,0,0];

    sleep 0.05;
    if (isNull _o) exitWith {};
    _o setPosASL _p; _o setVectorDirAndUp [_vd, _vu]; _o setVelocity [0,0,0];

    sleep 0.05;
    if (isNull _o) exitWith {};
    _o setPosASL _p; _o setVectorDirAndUp [_vd, _vu]; _o setVelocity [0,0,0];
    if (_sim) then { _o enableSimulationGlobal true; };
};

_obj
