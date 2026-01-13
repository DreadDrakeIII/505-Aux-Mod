disableSerialization;

params [
    ["_tile", controlNull, [controlNull]],
    ["_button", 0, [0]]
];

if (isNull _tile) exitWith {};

private _ied = player getVariable ["MSIED_disarmingObj", objNull];
if (isNull _ied) exitWith {};

private _gridWidth = _ied getVariable ["MSIED_GridWidth", 12];
private _gridHeight = _ied getVariable ["MSIED_GridHeight", 12];

// Right click - toggle flag
if (_button == 1) exitWith {
    private _currentText = ctrlText _tile;
    
    if (_currentText isEqualTo "\BLU\OLI\addons\minesweeper\img\tile.paa") then {
        private _mines = parseNumber ctrlText 1001;
        if (_mines > 0) then {
            ctrlSetText [1001, format ["%1", _mines - 1]];
            _tile ctrlSetText "\BLU\OLI\addons\minesweeper\img\tileFlag.paa";
        };
    } else {
        if (_currentText isEqualTo "\BLU\OLI\addons\minesweeper\img\tileFlag.paa") then {
            private _mines = parseNumber ctrlText 1001;
            ctrlSetText [1001, format ["%1", _mines + 1]];
            _tile ctrlSetText "\BLU\OLI\addons\minesweeper\img\tile.paa";
        };
    };
};

// Left click - uncover tile
if (_button == 0) then {
    // Decode IDC to get x,y coordinates
    // IDC scheme: 1000 + (x * 100) + y
    private _index = ctrlIDC _tile;
    private _adjusted = _index - 1000;
    private _tileX = floor(_adjusted / 100);
    private _tileY = _adjusted mod 100;
    
    // Check if this is the first click
    private _isFirstClick = _ied getVariable ["MSIED_firstClick", false];
    
    if (_isFirstClick) then {
        _ied setVariable ["MSIED_firstClick", false, false];
        
        // Get mine count from IED variable (handles custom settings)
        private _mineCount = _ied getVariable ["MSIED_mineCount", 20];
        
        // Clear ALL tiles first to avoid doubling mines
        for "_cx" from 1 to _gridWidth do {
            for "_cy" from 1 to _gridHeight do {
                _ied setVariable [format ["MSIED_Value%1_%2", _cx, _cy], "E", false];
            };
        };
        
        // Build safe zone list (3x3 around first click)
        private _safeZone = [];
        for "_dx" from -1 to 1 do {
            for "_dy" from -1 to 1 do {
                private _sx = _tileX + _dx;
                private _sy = _tileY + _dy;
                if (_sx >= 1 && _sx <= _gridWidth && _sy >= 1 && _sy <= _gridHeight) then {
                    _safeZone pushBack [_sx, _sy];
                };
            };
        };
        
        // Place mines avoiding the safe zone
        private _placedMines = 0;
        private _attempts = 0;
        while {_placedMines < _mineCount && _attempts < 10000} do {
            _attempts = _attempts + 1;
            private _mx = 1 + floor(random _gridWidth);
            private _my = 1 + floor(random _gridHeight);
            
            // Check if this position is in the safe zone
            private _inSafeZone = false;
            {
                _x params ["_szx", "_szy"];
                if (_mx == _szx && _my == _szy) then {
                    _inSafeZone = true;
                };
            } forEach _safeZone;
            
            if (!_inSafeZone) then {
                private _currentValue = _ied getVariable [format ["MSIED_Value%1_%2", _mx, _my], "E"];
                if (_currentValue isEqualTo "E") then {
                    _ied setVariable [format ["MSIED_Value%1_%2", _mx, _my], "B", false];
                    _placedMines = _placedMines + 1;
                };
            };
        };
        
        // Recalculate numbers for all tiles
        for "_nx" from 1 to _gridWidth do {
            for "_ny" from 1 to _gridHeight do {
                private _currentValue = _ied getVariable [format ["MSIED_Value%1_%2", _nx, _ny], "E"];
                if !(_currentValue isEqualTo "B") then {
                    private _count = [_ied, _nx, _ny] call MSIED_fnc_bombCount;
                    if (_count > 0) then {
                        _ied setVariable [format ["MSIED_Value%1_%2", _nx, _ny], _count, false];
                    } else {
                        _ied setVariable [format ["MSIED_Value%1_%2", _nx, _ny], "E", false];
                    };
                };
            };
        };
        
        // Auto-flag bombs if debug mode is enabled
        private _debugMode = _ied getVariable ["MSIED_Debug", false];
        if (_debugMode) then {
            for "_fx" from 1 to _gridWidth do {
                for "_fy" from 1 to _gridHeight do {
                    private _value = _ied getVariable [format ["MSIED_Value%1_%2", _fx, _fy], "E"];
                    private _field = [_fx, _fy] call MSIED_fnc_getField;
                    if (!isNull _field) then {
                        if (_value isEqualTo "B") then {
                            _field ctrlSetText "\BLU\OLI\addons\minesweeper\img\tileFlag.paa";
                        } else {
                            // Reset non-bomb tiles to uncovered state in case they were flagged
                            _field ctrlSetText "\BLU\OLI\addons\minesweeper\img\tile.paa";
                        };
                    };
                };
            };
            ctrlSetText [1001, "0"];
        };
    };
    
    // Now uncover the clicked tile
    [_ied, _tileX, _tileY] call MSIED_fnc_uncover;
};
