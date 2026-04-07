params [
    ["_position", player, [objNull, []]],
    ["_radius", 35, [0]],
    ["_includeRemoteControlled", true, [true]]
];

if (_position isEqualType objNull) then {
    if (isNull _position) exitWith {[]};
    _position = getPosATL _position;
};

if !(_position isEqualType []) exitWith {[]};

if !(_radius isEqualType 0) then {
    _radius = 35;
};

if (_radius < 0) then {
    _radius = 35;
};

private _nearbyUnits = _position nearEntities ["CAManBase", _radius];
_nearbyUnits = _nearbyUnits select { [_x, _includeRemoteControlled] call FEF_fnc_isPlayer };

_nearbyUnits
