params ["_menuId"];

call FEF_fnc_configureMenus;

private _menus = missionNamespace getVariable ["FEF_Menus", createHashMap];
if (isNil { _menus get _menuId }) exitWith {
    [format ["Unknown menu id: %1", _menuId]] call FEF_fnc_devLog;
};

private _items = _menus get _menuId;

private _labels = _items apply { _x select 0 };
private _menuVarName = format ["FEF_Menu_%1", _menuId];

private _callback = format [
    "[""%1"", %%2] call FEF_fnc_executeMenuSelection;",
    _menuId
];

[
    "505th Chat Wheel",
    _menuVarName,
    _labels,
    "",
    _callback
] call BIS_fnc_createMenu;

showCommandingMenu (format ["#USER:%1_0", _menuVarName]);
