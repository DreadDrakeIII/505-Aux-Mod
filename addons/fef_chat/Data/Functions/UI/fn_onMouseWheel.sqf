params ["_scroll"];

if !(missionNamespace getVariable ["FEF_UI_Open", false]) exitWith {};

private _menuId = missionNamespace getVariable ["FEF_UI_CurrentMenu", "main"];
private _menus  = missionNamespace getVariable ["FEF_Menus", createHashMap];
private _items  = _menus getOrDefault [_menuId, []];

private _count = count _items;
if (_count <= 0) exitWith {};

private _selectedIndex = missionNamespace getVariable ["FEF_UI_SelectedIndex", 0];

if (_scroll > 0) then {
    _selectedIndex = _selectedIndex - 1;
} else {
    _selectedIndex = _selectedIndex + 1;
};

if (_selectedIndex < 0) then { _selectedIndex = _count - 1; };
if (_selectedIndex >= _count) then { _selectedIndex = 0; };

missionNamespace setVariable ["FEF_UI_SelectedIndex", _selectedIndex];
[_menuId, false] call FEF_fnc_renderMenu;
