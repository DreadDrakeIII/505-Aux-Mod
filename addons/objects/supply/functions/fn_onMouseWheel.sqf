params ["_scroll"];

if !(missionNamespace getVariable ["OLI_Supply_UI_Open", false]) exitWith {};

private _items = OLI_Supply_Actions select {
    missionNamespace getVariable [(_x select 8), true]
};
private _count = count _items;
if (_count <= 0) exitWith {};

private _selectedIndex = missionNamespace getVariable ["OLI_Supply_UI_SelectedIndex", 0];

if (_scroll > 0) then {
    _selectedIndex = _selectedIndex - 1;
} else {
    _selectedIndex = _selectedIndex + 1;
};

if (_selectedIndex < 0) then { _selectedIndex = _count - 1; };
if (_selectedIndex >= _count) then { _selectedIndex = 0; };

missionNamespace setVariable ["OLI_Supply_UI_SelectedIndex", _selectedIndex];
[false] call OLI_Supply_fnc_renderMenu;
