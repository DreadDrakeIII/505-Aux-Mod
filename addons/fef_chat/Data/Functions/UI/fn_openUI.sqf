disableSerialization;

call FEF_fnc_configureMenus;

private _ctrls = missionNamespace getVariable ["FEF_UI_Controls", []];
{ ctrlDelete _x; } forEach _ctrls;
missionNamespace setVariable ["FEF_UI_Controls", []];

missionNamespace setVariable ["FEF_UI_Open", true];
missionNamespace setVariable ["FEF_UI_CurrentMenu", "main"];
missionNamespace setVariable ["FEF_UI_SelectedIndex", 0];
missionNamespace setVariable ["FEF_UI_ScrollOffset", 0];

// Block ACE scroll interaction
[true] call ace_interact_menu_fnc_blockMouseWheel;

// Block vanilla Arma action menu (scroll wheel) while chat menu is open.
// Returning "true" tells the engine to skip its default handling of these events.
inGameUISetEventHandler ["PrevAction", "true"];
inGameUISetEventHandler ["NextAction", "true"];

private _display46 = findDisplay 46;
private _oldEH = missionNamespace getVariable ["FEF_UI_ScrollEH", -1];
if (_oldEH >= 0) then {
    _display46 displayRemoveEventHandler ["MouseZChanged", _oldEH];
};

private _scrollEH = _display46 displayAddEventHandler ["MouseZChanged", {
    params ["_display", "_scroll"];
    if !(missionNamespace getVariable ["FEF_UI_Open", false]) exitWith {};
    [_scroll] call FEF_fnc_onMouseWheel;
}];

missionNamespace setVariable ["FEF_UI_ScrollEH", _scrollEH];

private _oldKeyEH = missionNamespace getVariable ["FEF_UI_KeyEH", -1];
if (_oldKeyEH >= 0) then {
    _display46 displayRemoveEventHandler ["KeyDown", _oldKeyEH];
};

private _keyEH = _display46 displayAddEventHandler ["KeyDown", {
    params ["_display", "_key", "_shift", "_ctrl", "_alt"];
    if !(missionNamespace getVariable ["FEF_UI_Open", false]) exitWith { false };
    _this call FEF_fnc_onKeyDown;
}];

missionNamespace setVariable ["FEF_UI_KeyEH", _keyEH];

["main", true] call FEF_fnc_renderMenu;
