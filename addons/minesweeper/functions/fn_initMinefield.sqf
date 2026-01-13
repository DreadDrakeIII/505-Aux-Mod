disableSerialization;

params [["_ied", objNull, [objNull]]];

if (isNull _ied) exitWith {false};

private _currentDefuser = _ied getVariable ["MSIED_Defuser", objNull];
if (!isNull _currentDefuser && {_currentDefuser != player}) exitWith {
    hint "Someone else is already defusing this IED!";
    false
};

player setVariable ["MSIED_disarmingObj", _ied, false];
_ied setVariable ["MSIED_Defuser", player, true];

private _mineCount = _ied getVariable ["MSIED_mineCount", 20];
private _timeLimit = _ied getVariable ["MSIED_timeLimit", 90];
private _gridWidth = _ied getVariable ["MSIED_GridWidth", 12];
private _gridHeight = _ied getVariable ["MSIED_GridHeight", 12];

playSound3D ["\BLU\OLI\addons\minesweeper\sounds\start.ogg", _ied, false, getPosASL _ied, 5, 1, 50];

if (!createDialog "MSIED_Minesweeper") exitWith {
    hint "Failed to create minesweeper dialog!";
    false
};

private _display = findDisplay 55500;
if (isNull _display) exitWith {
    hint "Failed to get display!";
    false
};

// Tile dimensions (in screen units before safezone multiplication)
private _tileW = 0.029;
private _tileH = 0.042;
private _headerHeight = 0.08; // Space for timer/mine count display

// Calculate board dimensions
private _boardW = _gridWidth * _tileW;
private _boardH = _gridHeight * _tileH;

// Calculate centered starting position
private _startX = 0.5 - (_boardW / 2);
private _startY = 0.5 - (_boardH / 2) + (_headerHeight / 2);

// Update background size and position
private _bgPadding = 0.015;
private _bgCtrl = _display displayCtrl 9999;
if (!isNull _bgCtrl) then {
    _bgCtrl ctrlSetPosition [
        (_startX - _bgPadding) * safezoneW + safezoneX,
        (_startY - _headerHeight - _bgPadding) * safezoneH + safezoneY,
        (_boardW + _bgPadding * 2) * safezoneW,
        (_boardH + _headerHeight + _bgPadding * 2) * safezoneH
    ];
    _bgCtrl ctrlCommit 0;
};

// Update frame size and position
private _frameCtrl = _display displayCtrl 9998;
if (!isNull _frameCtrl) then {
    _frameCtrl ctrlSetPosition [
        (_startX - _bgPadding) * safezoneW + safezoneX,
        (_startY - _headerHeight - _bgPadding) * safezoneH + safezoneY,
        (_boardW + _bgPadding * 2) * safezoneW,
        (_boardH + _headerHeight + _bgPadding * 2) * safezoneH
    ];
    _frameCtrl ctrlCommit 0;
};

// Position timer and mine count in header area
private _timerCtrl = _display displayCtrl 1000;
if (!isNull _timerCtrl) then {
    _timerCtrl ctrlSetPosition [
        (_startX) * safezoneW + safezoneX,
        (_startY - _headerHeight + 0.01) * safezoneH + safezoneY,
        0.06 * safezoneW,
        0.05 * safezoneH
    ];
    _timerCtrl ctrlCommit 0;
};

private _timerIconCtrl = _display displayCtrl 1002;
if (!isNull _timerIconCtrl) then {
    _timerIconCtrl ctrlSetPosition [
        (_startX + 0.06) * safezoneW + safezoneX,
        (_startY - _headerHeight + 0.01) * safezoneH + safezoneY,
        0.04 * safezoneW,
        0.05 * safezoneH
    ];
    _timerIconCtrl ctrlCommit 0;
};

private _mineCtrl = _display displayCtrl 1001;
if (!isNull _mineCtrl) then {
    _mineCtrl ctrlSetPosition [
        (_startX + _boardW - 0.1) * safezoneW + safezoneX,
        (_startY - _headerHeight + 0.01) * safezoneH + safezoneY,
        0.06 * safezoneW,
        0.05 * safezoneH
    ];
    _mineCtrl ctrlCommit 0;
};

private _mineIconCtrl = _display displayCtrl 1003;
if (!isNull _mineIconCtrl) then {
    _mineIconCtrl ctrlSetPosition [
        (_startX + _boardW - 0.04) * safezoneW + safezoneX,
        (_startY - _headerHeight + 0.01) * safezoneH + safezoneY,
        0.04 * safezoneW,
        0.05 * safezoneH
    ];
    _mineIconCtrl ctrlCommit 0;
};

ctrlSetText [1000, format ["%1", _timeLimit]];
ctrlSetText [1001, format ["%1", _mineCount]];

_ied setVariable ["MSIED_Timer", _timeLimit, false];
_ied setVariable ["MSIED_left", (_gridWidth * _gridHeight) - _mineCount, false];
_ied setVariable ["MSIED_firstClick", true, false];

// Dynamically create tiles
for "_x" from 1 to _gridWidth do {
    for "_y" from 1 to _gridHeight do {
        private _idc = 1000 + (_x * 100) + _y;
        private _ctrl = _display ctrlCreate ["MSIED_RscMineTile", _idc];
        
        private _posX = (_startX + ((_x - 1) * _tileW)) * safezoneW + safezoneX;
        private _posY = (_startY + ((_y - 1) * _tileH)) * safezoneH + safezoneY;
        
        _ctrl ctrlSetPosition [_posX, _posY, _tileW * safezoneW, _tileH * safezoneH];
        _ctrl ctrlSetText "\BLU\OLI\addons\minesweeper\img\tile.paa";
        _ctrl ctrlSetEventHandler ["MouseButtonDown", "_this spawn MSIED_fnc_tileClick"];
        _ctrl ctrlCommit 0;
        
        _ied setVariable [format ["MSIED_Value%1_%2", _x, _y], "E", false];
    };
};

// Place mines randomly
private _placedMines = 0;
while {_placedMines < _mineCount} do {
    private _x = 1 + floor(random _gridWidth);
    private _y = 1 + floor(random _gridHeight);
    
    private _currentValue = _ied getVariable [format ["MSIED_Value%1_%2", _x, _y], "E"];
    if (_currentValue isEqualTo "E") then {
        _ied setVariable [format ["MSIED_Value%1_%2", _x, _y], "B", false];
        _placedMines = _placedMines + 1;
    };
};

// Calculate bomb counts for each tile
for "_x" from 1 to _gridWidth do {
    for "_y" from 1 to _gridHeight do {
        private _currentValue = _ied getVariable [format ["MSIED_Value%1_%2", _x, _y], "E"];
        if !(_currentValue isEqualTo "B") then {
            private _count = [_ied, _x, _y] call MSIED_fnc_bombCount;
            if (_count > 0) then {
                _ied setVariable [format ["MSIED_Value%1_%2", _x, _y], _count, false];
            };
        };
    };
};

// Auto-flag bombs if debug mode is enabled
private _debugMode = _ied getVariable ["MSIED_Debug", false];
if (_debugMode) then {
    for "_x" from 1 to _gridWidth do {
        for "_y" from 1 to _gridHeight do {
            private _value = _ied getVariable [format ["MSIED_Value%1_%2", _x, _y], "E"];
            if (_value isEqualTo "B") then {
                private _field = [_x, _y] call MSIED_fnc_getField;
                if (!isNull _field) then {
                    _field ctrlSetText "\BLU\OLI\addons\minesweeper\img\tileFlag.paa";
                };
            };
        };
    };
    ctrlSetText [1001, "0"];
};

[_ied] spawn MSIED_fnc_sweeperTick;

true
