params [["_console", objNull]];

if (!hasInterface) exitWith {};
if (isNull _console) exitWith {};

{_console removeAction _x} forEach (_console getVariable ["OLI_Supply_ActionIDs", []]);

_console setVariable ["OLI_Supply_ActionIDs", nil];
_console setVariable ["OLI_Supply_ActionMap", nil];
_console setVariable ["OLI_Supply_ShownSecs", nil];

OLI_Supply_LocalConsoles = OLI_Supply_LocalConsoles - [_console];

if (missionNamespace getVariable ["OLI_Supply_UI_Open", false]) then {
    if ((missionNamespace getVariable ["OLI_Supply_UI_Console", objNull]) isEqualTo _console) then {
        [] call OLI_Supply_fnc_closeMenu;
    };
};
