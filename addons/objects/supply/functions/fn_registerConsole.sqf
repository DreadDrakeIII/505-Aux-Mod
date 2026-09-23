params [["_console", objNull]];

if (!isServer) exitWith {};
if (isNull _console) exitWith {};
if (_console getVariable ["OLI_Supply_IsConsole", false]) exitWith {};

_console setVariable ["OLI_Supply_IsConsole", true, true];

private _jipId = format ["OLI_Supply_console_%1", netId _console];
["OLI_Supply_addActions", [_console], _jipId] call CBA_fnc_globalEventJIP;

[_jipId, _console] call CBA_fnc_removeGlobalEventJIP;
