params [["_index", 0]];

private _scrollOffset = missionNamespace getVariable ["OLI_Supply_UI_ScrollOffset", 0];
private _actualIndex  = _index + _scrollOffset;

private _items = OLI_Supply_Actions select {
    missionNamespace getVariable [(_x select 8), true]
};

if (_actualIndex < 0 || {_actualIndex >= count _items}) exitWith {
    [] call OLI_Supply_fnc_closeMenu;
};

(_items select _actualIndex) params ["_key"];
private _console = missionNamespace getVariable ["OLI_Supply_UI_Console", objNull];

[] call OLI_Supply_fnc_closeMenu;

if (!isNull _console) then {
    [_console, player, _key] call OLI_Supply_fnc_requestCrate;
};
