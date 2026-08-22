// OLI_SUPPLY - client side of an action press. Does the cheap local checks,
// then asks the server, which is the authority on cooldown and spawning.
//
// Arguments: 0: console <OBJECT>, 1: caller <OBJECT>, 2: action key <STRING>

params [["_console", objNull], ["_unit", objNull], ["_key", ""]];

if (isNull _console || {isNull _unit} || {_key isEqualTo ""}) exitWith {};

private _remaining = (_console getVariable [[_unit] call OLI_Supply_fnc_cooldownVar, 0]) - CBA_missionTime;
if (_remaining > 0) exitWith {
    [format ["Supply console recharging - %1", [_remaining] call OLI_Supply_fnc_formatTime]] call ace_common_fnc_displayTextStructured;
};

["OLI_Supply_request", [_console, _unit, _key]] call CBA_fnc_serverEvent;
