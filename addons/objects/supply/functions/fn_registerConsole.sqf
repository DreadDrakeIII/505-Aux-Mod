// OLI_SUPPLY - SERVER SIDE. Turn an arbitrary object into a supply console.
//
// The shipped OLI_Supply_Console class does not need this - it is wired up by
// its class event handler. Use this for any other prop:
//
//     [myProp] call OLI_Supply_fnc_registerConsole;   // must run on the server
//
// It marks the object (publicly, so the server can validate later requests)
// and tells every client - present and JIP - to attach the four actions.
//
// Arguments: 0: object <OBJECT>

params [["_console", objNull]];

if (!isServer) exitWith {};
if (isNull _console) exitWith {};
if (_console getVariable ["OLI_Supply_IsConsole", false]) exitWith {};

_console setVariable ["OLI_Supply_IsConsole", true, true];

private _jipId = format ["OLI_Supply_console_%1", netId _console];
["OLI_Supply_addActions", [_console], _jipId] call CBA_fnc_globalEventJIP;

// drop the JIP entry when the object is deleted, so the queue does not grow
[_jipId, _console] call CBA_fnc_removeGlobalEventJIP;
