params ["_key", ["_onCooldown", false], ["_remaining", 0], ["_iconSize", 1.5]];

private _idx = OLI_Supply_Actions findIf {(_x select 0) == _key};
if (_idx < 0) exitWith {""};

(OLI_Supply_Actions select _idx) params ["", "_name", "_color", "_icon"];

private _label = format ["Spawn %1", _name];

if (_onCooldown) then {
    _color = OLI_Supply_ColorCooldown;
    _label = format ["%1  [%2]", _label, [_remaining] call OLI_Supply_fnc_formatTime];
};

format ["<img image='%1' size='%2' shadow=2 /> <t color='%3'>%4</t>", _icon, _iconSize, _color, _label]
