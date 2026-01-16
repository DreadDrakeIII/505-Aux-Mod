params ["_pos", "_attachedObject"];

// Find target object
private _ied = objNull;

// First check if attached to an object
if (!isNull _attachedObject) then {
    _ied = _attachedObject;
} else {
    // Find nearest object within 1 meter
    private _nearObjects = nearestObjects [ASLToAGL _pos, ["All"], 1];
    {
        if (!isNull _x && {alive _x}) exitWith {
            _ied = _x;
        };
    } forEach _nearObjects;
};

// Validate object found
if (isNull _ied) exitWith {
    ["Minesweeper IED", "No valid object found! Place the module directly on or very close to an object."] call zen_common_fnc_showMessage;
};

// Create ZEN dialog with advanced options
private _dialogResult = [
    "Minesweeper IED Configuration",
    [
        ["COMBO", ["Difficulty Preset", "Select preset or Custom for manual configuration"], [
            ["easy", "medium", "hard", "extreme", "custom"],
            [
                ["Easy (9x9, 10 mines, 55s)", "Beginner friendly"],
                ["Medium (12x12, 20 mines, 90s)", "Balanced difficulty"],
                ["Hard (16x16, 40 mines, 150s)", "Advanced challenge"],
                ["Extreme (25x16, 75 mines, 360s)", "Expert mode"],
                ["Custom", "Use sliders below"]
            ],
            0  // Easy is default
        ]],
        ["SLIDER", ["Custom Width", "Grid width (only used if Custom preset selected)"], [3, 35, 12, 0]],
        ["SLIDER", ["Custom Height", "Grid height (only used if Custom preset selected)"], [3, 23, 12, 0]],
        ["SLIDER", ["Custom Mines", "Number of mines (only used if Custom preset selected)"], [1, 805, 20, 0]],
        ["SLIDER", ["Custom Time (seconds)", "Defusal time in seconds (only used if Custom preset selected)"], [5, 999, 90, 0]],
        ["COMBO", ["Explosion Size", "Explosion when IED detonates"], [
            ["small", "medium", "large", "huge", "nothing"],
            [
                ["Small (Hand Grenade)", "Minor blast"],
                ["Medium (Small Bomb)", "Moderate explosion"],
                ["Large (Helicopter)", "Standard helicopter explosion"],
                ["Huge (GBU-12)", "Massive explosion"],
                ["Nothing (Training)", "No explosion, plays loser sound"]
            ],
            2  // Large is default
        ]],
        ["SIDES", ["Trigger Side", "Which side triggers the IED (Civilian = none)"], civilian],
        ["TOOLBOX:YESNO", ["Debug Flags", "Auto-flag all bombs when defusing (for testing)"], false],
        ["TOOLBOX:YESNO", ["Pre-Defusal Warning Beep", "IED beeps before anyone starts defusing (3D sound, everyone can hear)"], false]
    ],
    {
        // On Confirm
        params ["_values", "_args"];
        _args params ["_ied"];
        _values params ["_difficultyPreset", "_customWidth", "_customHeight", "_customMines", "_customTime", "_explosionSize", "_triggerSide", "_debugMode", "_preDefusalBeep"];
        
        // Calculate actual values based on preset
        private _actualWidth = 12;
        private _actualHeight = 12;
        private _actualMines = 20;
        private _actualTime = 90;
        private _difficulty = _difficultyPreset;
        
        switch (_difficultyPreset) do {
            case "easy": {
                _actualWidth = 9;
                _actualHeight = 9;
                _actualMines = 10;
                _actualTime = 55;
            };
            case "medium": {
                _actualWidth = 12;
                _actualHeight = 12;
                _actualMines = 20;
                _actualTime = 90;
            };
            case "hard": {
                _actualWidth = 16;
                _actualHeight = 16;
                _actualMines = 40;
                _actualTime = 150;
            };
            case "extreme": {
                _actualWidth = 25;
                _actualHeight = 16;
                _actualMines = 75;
                _actualTime = 360;
            };
            case "custom": {
                _actualWidth = round _customWidth;
                _actualHeight = round _customHeight;
                _actualMines = round _customMines;
                _actualTime = round _customTime;
                
                // Validate mines don't exceed grid size minus safe zone (9 tiles)
                private _maxMines = (_actualWidth * _actualHeight) - 9;
                if (_actualMines > _maxMines) then {
                    _actualMines = _maxMines;
                };
            };
        };
        
        // Set global debug mode if enabled
        if (_debugMode) then {
            missionNamespace setVariable ["MSIED_DebugMode", true, true];
        };
        
        // Initialize the IED with all settings
        if (isServer) then {
            [_ied, _difficulty, _actualMines, _actualTime, _explosionSize, _triggerSide, _debugMode, _preDefusalBeep, _actualWidth, _actualHeight] call MSIED_fnc_initIED;
        } else {
            [_ied, _difficulty, _actualMines, _actualTime, _explosionSize, _triggerSide, _debugMode, _preDefusalBeep, _actualWidth, _actualHeight] remoteExec ["MSIED_fnc_initIED", 2];
        };
        
    },
    {
        // On Cancel
        // Do nothing
    },
    [_ied]
] call zen_dialog_fnc_create;
