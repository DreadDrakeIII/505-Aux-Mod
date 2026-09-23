disableSerialization;

["closeUI called"] call FEF_fnc_devLog;

missionNamespace setVariable ["FEF_UI_Open", false];
missionNamespace setVariable ["FEF_UI_CurrentMenu", "main"];
missionNamespace setVariable ["FEF_UI_SelectedIndex", 0];
missionNamespace setVariable ["FEF_UI_ScrollOffset", 0];

// Recompute ACE scroll block - vehicle reason (if any) still applies even
// though our own UI is now closed (see fn_updateAceScrollBlock.sqf)
call FEF_fnc_updateAceScrollBlock;

// Restore vanilla Arma action menu (scroll wheel).
// "false" restores default engine handling of these events.
inGameUISetEventHandler ["PrevAction", "false"];
inGameUISetEventHandler ["NextAction", "false"];

private _display46 = findDisplay 46;

private _oldEH = missionNamespace getVariable ["FEF_UI_ScrollEH", -1];
if (_oldEH >= 0) then {
    _display46 displayRemoveEventHandler ["MouseZChanged", _oldEH];
    missionNamespace setVariable ["FEF_UI_ScrollEH", -1];
};

private _oldKeyEH = missionNamespace getVariable ["FEF_UI_KeyEH", -1];
if (_oldKeyEH >= 0) then {
    _display46 displayRemoveEventHandler ["KeyDown", _oldKeyEH];
    missionNamespace setVariable ["FEF_UI_KeyEH", -1];
};

private _ctrls = missionNamespace getVariable ["FEF_UI_Controls", []];
{ ctrlDelete _x; } forEach _ctrls;
missionNamespace setVariable ["FEF_UI_Controls", []];
