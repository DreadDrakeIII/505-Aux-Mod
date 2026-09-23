params [["_console", objNull]];

if (!hasInterface) exitWith {};
if (isNull _console) exitWith {};

if (missionNamespace getVariable ["OLI_Supply_UI_Open", false]) exitWith {
    missionNamespace setVariable ["OLI_Supply_UI_Console", _console];
    missionNamespace setVariable ["OLI_Supply_UI_SelectedIndex", 0];
    missionNamespace setVariable ["OLI_Supply_UI_ScrollOffset", 0];
    [true] call OLI_Supply_fnc_renderMenu;
};

disableSerialization;

missionNamespace setVariable ["OLI_Supply_UI_Open", true];
missionNamespace setVariable ["OLI_Supply_UI_Console", _console];
missionNamespace setVariable ["OLI_Supply_UI_SelectedIndex", 0];
missionNamespace setVariable ["OLI_Supply_UI_ScrollOffset", 0];

private _ctrls = missionNamespace getVariable ["OLI_Supply_UI_Controls", []];
{ ctrlDelete _x; } forEach _ctrls;
missionNamespace setVariable ["OLI_Supply_UI_Controls", []];

// Block ACE scroll interaction
[true] call ace_interact_menu_fnc_blockMouseWheel;

inGameUISetEventHandler ["PrevAction", "true"];
inGameUISetEventHandler ["NextAction", "true"];

private _display46 = findDisplay 46;

private _oldEH = missionNamespace getVariable ["OLI_Supply_UI_ScrollEH", -1];
if (_oldEH >= 0) then {
    _display46 displayRemoveEventHandler ["MouseZChanged", _oldEH];
};

private _scrollEH = _display46 displayAddEventHandler ["MouseZChanged", {
    params ["_display", "_scroll"];
    if !(missionNamespace getVariable ["OLI_Supply_UI_Open", false]) exitWith {};
    [_scroll] call OLI_Supply_fnc_onMouseWheel;
}];
missionNamespace setVariable ["OLI_Supply_UI_ScrollEH", _scrollEH];

private _oldKeyEH = missionNamespace getVariable ["OLI_Supply_UI_KeyEH", -1];
if (_oldKeyEH >= 0) then {
    _display46 displayRemoveEventHandler ["KeyDown", _oldKeyEH];
};

private _keyEH = _display46 displayAddEventHandler ["KeyDown", {
    params ["_display", "_key", "_shift", "_ctrl", "_alt"];
    if !(missionNamespace getVariable ["OLI_Supply_UI_Open", false]) exitWith { false };
    _this call OLI_Supply_fnc_onKeyDown;
}];
missionNamespace setVariable ["OLI_Supply_UI_KeyEH", _keyEH];

[true] call OLI_Supply_fnc_renderMenu;
