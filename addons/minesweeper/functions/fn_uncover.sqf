disableSerialization;

params [
    ["_ied", objNull, [objNull]],
    ["_x", 0, [0]],
    ["_y", 0, [0]],
    ["_soft", false, [false]]
];

if (isNull _ied) exitWith {};

private _gridWidth = _ied getVariable ["MSIED_GridWidth", 12];
private _gridHeight = _ied getVariable ["MSIED_GridHeight", 12];

if (_x < 1 || _x > _gridWidth || _y < 1 || _y > _gridHeight) exitWith {};

private _field = [_x, _y] call MSIED_fnc_getField;
if (isNull _field) exitWith {};

private _fieldText = ctrlText _field;
private _type = _ied getVariable [format ["MSIED_Value%1_%2", _x, _y], "E"];

// Only uncover if tile is still covered and not a bomb (or soft mode)
if ((_fieldText isEqualTo "\BLU\OLI\addons\minesweeper\img\tile.paa") && !(_type isEqualTo "B")) then {
    // Decrease remaining tiles
    private _left = _ied getVariable ["MSIED_left", 0];
    _ied setVariable ["MSIED_left", _left - 1, false];
    
    // Check win condition
    if (_left <= 1) then {
        [_ied] call MSIED_fnc_complete;
    };
    
    // Reveal the tile based on its value
    if (_type isEqualType 0) then {
        // Number tile
        _field ctrlSetText format ["\BLU\OLI\addons\minesweeper\img\%1.paa", _type];
    } else {
        if (_type isEqualTo "E") then {
            // Empty tile - reveal and recursively uncover adjacent tiles
            _field ctrlSetText "\BLU\OLI\addons\minesweeper\img\empty.paa";
            
            // Recursively uncover all 8 adjacent tiles
            for "_dx" from -1 to 1 do {
                for "_dy" from -1 to 1 do {
                    if (_dx != 0 || _dy != 0) then {
                        private _newX = _x + _dx;
                        private _newY = _y + _dy;
                        if (_newX >= 1 && _newX <= _gridWidth && _newY >= 1 && _newY <= _gridHeight) then {
                            [_ied, _newX, _newY, true] call MSIED_fnc_uncover;
                        };
                    };
                };
            };
        };
    };
};

// If clicked on bomb and not in soft mode, detonate
if ((_type isEqualTo "B") && !_soft) then {
    [_ied, true] call MSIED_fnc_detonate; // Pass true for failure
};
