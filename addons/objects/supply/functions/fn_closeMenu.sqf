disableSerialization;

missionNamespace setVariable ["OLI_Supply_UI_Open", false];
missionNamespace setVariable ["OLI_Supply_UI_Console", objNull];
missionNamespace setVariable ["OLI_Supply_UI_SelectedIndex", 0];
missionNamespace setVariable ["OLI_Supply_UI_ScrollOffset", 0];

// Unblock ACE scroll interaction
[false] call ace_interact_menu_fnc_blockMouseWheel;

// Restore vanilla Arma action menu (scroll wheel)
inGameUISetEventHandler ["PrevAction", "false"];
inGameUISetEventHandler ["NextAction", "false"];

private _display46 = findDisplay 46;

private _oldEH = missionNamespace getVariable ["OLI_Supply_UI_ScrollEH", -1];
if (_oldEH >= 0) then {
    _display46 displayRemoveEventHandler ["MouseZChanged", _oldEH];
    missionNamespace setVariable ["OLI_Supply_UI_ScrollEH", -1];
};

private _oldKeyEH = missionNamespace getVariable ["OLI_Supply_UI_KeyEH", -1];
if (_oldKeyEH >= 0) then {
    _display46 displayRemoveEventHandler ["KeyDown", _oldKeyEH];
    missionNamespace setVariable ["OLI_Supply_UI_KeyEH", -1];
};

private _ctrls = missionNamespace getVariable ["OLI_Supply_UI_Controls", []];
{ ctrlDelete _x; } forEach _ctrls;
missionNamespace setVariable ["OLI_Supply_UI_Controls", []];
