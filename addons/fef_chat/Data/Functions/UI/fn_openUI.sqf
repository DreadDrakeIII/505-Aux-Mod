disableSerialization;

call FEF_fnc_configureMenus;

if (!isNull findDisplay 88000) exitWith {};

createDialog "FEF_ChatDisplay";

private _display = findDisplay 88000;
if (isNull _display) exitWith {};

missionNamespace setVariable ["FEF_UI_CurrentMenu", "main"];
missionNamespace setVariable ["FEF_UI_SelectedIndex", 0];
missionNamespace setVariable ["FEF_UI_ScrollOffset", 0];

_display displayAddEventHandler ["MouseZChanged", {
    _this call FEF_fnc_onMouseWheel;
}];

_display displayAddEventHandler ["KeyDown", {
    _this call FEF_fnc_onKeyDown;
}];

["main", true] call FEF_fnc_renderMenu;
