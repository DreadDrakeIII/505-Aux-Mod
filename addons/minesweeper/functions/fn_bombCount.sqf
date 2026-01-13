params [
    ["_ied", objNull, [objNull]],
    ["_x", 0, [0]],
    ["_y", 0, [0]]
];

if (isNull _ied) exitWith {0};

private _gridWidth = _ied getVariable ["MSIED_GridWidth", 12];
private _gridHeight = _ied getVariable ["MSIED_GridHeight", 12];

private _count = 0;
private _currentValue = _ied getVariable [format ["MSIED_Value%1_%2", _x, _y], "E"];

// Don't count if this tile itself is a bomb
if (_currentValue isEqualTo "B") exitWith {0};

// Check all 8 adjacent tiles
for "_dx" from -1 to 1 do {
    for "_dy" from -1 to 1 do {
        // Skip the center tile
        if (_dx != 0 || _dy != 0) then {
            private _checkX = _x + _dx;
            private _checkY = _y + _dy;
            
            // Check bounds
            if (_checkX >= 1 && _checkX <= _gridWidth && _checkY >= 1 && _checkY <= _gridHeight) then {
                private _value = _ied getVariable [format ["MSIED_Value%1_%2", _checkX, _checkY], "E"];
                if (_value isEqualTo "B") then {
                    _count = _count + 1;
                };
            };
        };
    };
};

_count
