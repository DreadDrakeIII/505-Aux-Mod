params [["_console", objNull], ["_unit", objNull], ["_key", ""]];

if (!isServer) exitWith {};
if (isNull _console || {isNull _unit} || {!alive _unit} || {_key isEqualTo ""}) exitWith {};
if !(_unit isKindOf "CAManBase") exitWith {};
if !(isPlayer _unit) exitWith {};

if !(_console isKindOf "OLI_Supply_Console" || {_console getVariable ["OLI_Supply_IsConsole", false]}) exitWith {};

private _idx = OLI_Supply_Actions findIf {(_x select 0) == _key};
if (_idx < 0) exitWith {};

(OLI_Supply_Actions select _idx) params ["", "_name", "", "", "_classVar", "", "_cdVar", "", "_enabledVar"];

if !(missionNamespace getVariable [_enabledVar, true]) exitWith {
    ["OLI_Supply_message", [format ["%1 resupply is disabled on this mission", _name]], _unit] call CBA_fnc_targetEvent;
};

private _maxRange = (missionNamespace getVariable ["OLI_Supply_ActionRadius", 4]) * OLI_Supply_ServerRangeFactor;
if (_unit distance _console > _maxRange) exitWith {};

private _cdName = [_key] call OLI_Supply_fnc_cooldownVar;
private _end = _console getVariable [_cdName, 0];
if (CBA_missionTime < _end) exitWith {
    ["OLI_Supply_message", [format ["%1 resupply recharging - %2", _name, [_end - CBA_missionTime] call OLI_Supply_fnc_formatTime]], _unit] call CBA_fnc_targetEvent;
};

private _class = missionNamespace getVariable [_classVar, ""];

if (_class isEqualTo "" || {!isClass (configFile >> "CfgVehicles" >> _class)}) exitWith {
    diag_log format ["[OLI_Supply] '%1' is not a CfgVehicles class - check CBA setting %2", _class, _classVar];
    ["OLI_Supply_message", [format ["%1 unavailable - crate class '%2' is not loaded", _name, _class]], _unit] call CBA_fnc_targetEvent;
};

private _cd = missionNamespace getVariable [_cdVar, 0];
if (_cd > 0) then {
    _console setVariable [_cdName, CBA_missionTime + _cd, true];
};

private _crate = createVehicle [_class, _unit modelToWorld [0, 0, 0], [], 0, "CAN_COLLIDE"];
_crate enableSimulationGlobal false;
_crate setDir (getDir _unit);
_crate setVariable ["OLI_Supply_Crate", _key, true];
_crate setVariable ["OLI_Supply_Source", _console, true];

private _ignoreWeight = missionNamespace getVariable ["OLI_Supply_IgnoreWeight", true];
[_crate, true, nil, nil, _ignoreWeight, true] call ace_dragging_fnc_setCarryable;

["OLI_Supply_startCarry", [_unit, netId _crate], _unit] call CBA_fnc_targetEvent;

[{
    params ["_crate"];
    if (!isNull _crate && {!simulationEnabled _crate}) then {
        _crate enableSimulationGlobal true;
    };
}, [_crate], 6] call CBA_fnc_waitAndExecute;
