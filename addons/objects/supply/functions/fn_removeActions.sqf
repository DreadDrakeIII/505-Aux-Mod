// OLI_SUPPLY - strip the console actions off an object again.
// Arguments: 0: object <OBJECT>

params [["_console", objNull]];

if (!hasInterface) exitWith {};
if (isNull _console) exitWith {};

{_console removeAction _x} forEach (_console getVariable ["OLI_Supply_ActionIDs", []]);

_console setVariable ["OLI_Supply_ActionIDs", nil];
_console setVariable ["OLI_Supply_ShownSecs", nil];

OLI_Supply_LocalConsoles = OLI_Supply_LocalConsoles - [_console];
