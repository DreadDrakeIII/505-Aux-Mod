// Check if ZEN is loaded
if (!isClass (configFile >> "CfgPatches" >> "zen_main")) exitWith {false};

// Action 1: Show IED Info
private _actionInfo = [
    "MSIED_Info",
    "IED Info",
    "\a3\ui_f\data\igui\cfg\simpleTasks\types\search_ca.paa",
    {
        params ["_pos", "_objects"];
        
        private _ied = _objects select 0;
        private _difficulty = _ied getVariable ["MSIED_difficulty", "unknown"];
        private _mineCount = _ied getVariable ["MSIED_mineCount", 20];
        private _timeLimit = _ied getVariable ["MSIED_timeLimit", 90];
        private _gridWidth = _ied getVariable ["MSIED_GridWidth", 12];
        private _gridHeight = _ied getVariable ["MSIED_GridHeight", 12];
        private _explosionSize = _ied getVariable ["MSIED_explosionSize", "large"];
        private _triggerSide = _ied getVariable ["MSIED_Side", civilian];
        private _preDefusalBeep = _ied getVariable ["MSIED_preDefusalBeep", false];
        private _defused = _ied getVariable ["MSIED_Defused", false];
        private _detonated = _ied getVariable ["MSIED_Detonated", false];
        private _debugMode = _ied getVariable ["MSIED_Debug", false];
        
        private _sideName = switch (_triggerSide) do {
            case west: {"BLUFOR"};
            case east: {"OPFOR"};
            case resistance: {"Independent"};
            case civilian: {"None (Civilian)"};
            default {"Unknown"};
        };
        
        private _explosionName = switch (toLower _explosionSize) do {
            case "small": {"Small (Grenade)"};
            case "medium": {"Medium (Bomb)"};
            case "large": {"Large (Helicopter)"};
            case "huge": {"Huge (GBU-12)"};
            case "nothing": {"Nothing (Training)"};
            default {"Large"};
        };
        
        private _status = "Active";
        if (_defused) then {_status = "Defused"};
        if (_detonated) then {_status = "Detonated"};
        
        private _message = format [
            "<t align='center' size='1.2'>IED Information</t><br/><br/>" +
            "<t color='#00ff00'>Difficulty:</t> %1<br/>" +
            "<t color='#00ff00'>Grid Size:</t> %2x%3<br/>" +
            "<t color='#00ff00'>Mines:</t> %4<br/>" +
            "<t color='#00ff00'>Time Limit:</t> %5 seconds<br/>" +
            "<t color='#00ff00'>Explosion:</t> %6<br/>" +
            "<t color='#00ff00'>Trigger Side:</t> %7<br/>" +
            "<t color='#00ff00'>Status:</t> %8<br/>" +
            "<t color='#00ff00'>Pre-Defusal Beep:</t> %9<br/>" +
            "<t color='#00ff00'>Debug Mode:</t> %10",
            toUpper _difficulty,
            _gridWidth,
            _gridHeight,
            _mineCount,
            _timeLimit,
            _explosionName,
            _sideName,
            _status,
            if (_preDefusalBeep) then {"Enabled"} else {"Disabled"},
            if (_debugMode) then {"Enabled"} else {"Disabled"}
        ];
        
        ["Minesweeper IED", _message] call zen_common_fnc_showMessage;
    },
    {
        params ["_pos", "_objects"];
        
        if (count _objects != 1) exitWith {false};
        
        private _ied = _objects select 0;
        !isNil {_ied getVariable "MSIED_difficulty"}
    }
] call zen_context_menu_fnc_createAction;

// Action 2: Toggle Debug Flag
private _actionToggleDebug = [
    "MSIED_ToggleDebug",
    "Toggle Debug Flag",
    "\a3\ui_f\data\igui\cfg\actions\settimer_ca.paa",
    {
        params ["_pos", "_objects"];
        
        private _ied = _objects select 0;
        private _currentDebug = _ied getVariable ["MSIED_Debug", false];
        private _debugFlag = _ied getVariable ["MSIED_DebugFlag", objNull];
        
        if (_currentDebug && !isNull _debugFlag) then {
            // Remove debug flag
            deleteVehicle _debugFlag;
            _ied setVariable ["MSIED_Debug", false, true];
            _ied setVariable ["MSIED_DebugFlag", objNull, true];
            ["Minesweeper IED", "Debug flag removed"] call zen_common_fnc_showMessage;
        } else {
            // Add debug flag
            private _flagPos = ASLToAGL getPosASL _ied;
            _flagPos set [2, (_flagPos select 2) + 2];
            
            private _flag = "Sign_Sphere100cm_F" createVehicle _flagPos;
            _flag setObjectTexture [0, "#(rgb,8,8,3)color(1,0,0,0.8)"];
            _flag setPosASL (AGLToASL _flagPos);
            
            _ied setVariable ["MSIED_Debug", true, true];
            _ied setVariable ["MSIED_DebugFlag", _flag, true];
            ["Minesweeper IED", "Debug flag added"] call zen_common_fnc_showMessage;
        };
    },
    {
        params ["_pos", "_objects"];
        
        if (count _objects != 1) exitWith {false};
        
        private _ied = _objects select 0;
        private _defused = _ied getVariable ["MSIED_Defused", false];
        private _detonated = _ied getVariable ["MSIED_Detonated", false];
        
        (!isNil {_ied getVariable "MSIED_difficulty"}) && !_defused && !_detonated
    }
] call zen_context_menu_fnc_createAction;

// Action 3: Instant Defuse (for testing)
private _actionInstantDefuse = [
    "MSIED_InstantDefuse",
    "Instant Defuse (Test)",
    "\a3\ui_f\data\igui\cfg\simpleTasks\types\repair_ca.paa",
    {
        params ["_pos", "_objects"];
        
        private _ied = _objects select 0;
        [_ied] call MSIED_fnc_complete;
        ["Minesweeper IED", "IED instantly defused (testing mode)"] call zen_common_fnc_showMessage;
    },
    {
        params ["_pos", "_objects"];
        
        if (count _objects != 1) exitWith {false};
        
        private _ied = _objects select 0;
        private _defused = _ied getVariable ["MSIED_Defused", false];
        private _detonated = _ied getVariable ["MSIED_Detonated", false];
        
        (!isNil {_ied getVariable "MSIED_difficulty"}) && !_defused && !_detonated
    }
] call zen_context_menu_fnc_createAction;

// Action 4: Instant Detonate (for testing)
private _actionInstantDetonate = [
    "MSIED_InstantDetonate",
    "Instant Detonate (Test)",
    "\a3\ui_f\data\igui\cfg\simpleTasks\types\destroy_ca.paa",
    {
        params ["_pos", "_objects"];
        
        private _ied = _objects select 0;
        [_ied] call MSIED_fnc_detonate;
        ["Minesweeper IED", "IED detonated (testing mode)"] call zen_common_fnc_showMessage;
    },
    {
        params ["_pos", "_objects"];
        
        if (count _objects != 1) exitWith {false};
        
        private _ied = _objects select 0;
        private _defused = _ied getVariable ["MSIED_Defused", false];
        private _detonated = _ied getVariable ["MSIED_Detonated", false];
        
        (!isNil {_ied getVariable "MSIED_difficulty"}) && !_defused && !_detonated
    }
] call zen_context_menu_fnc_createAction;

// Register actions under a parent category
private _parentAction = [
    "MSIED_Category",
    "Minesweeper IED",
    "\a3\modules_f\data\iconexplosive_ca.paa",
    {},
    {
        params ["_pos", "_objects"];
        
        if (count _objects != 1) exitWith {false};
        
        private _ied = _objects select 0;
        !isNil {_ied getVariable "MSIED_difficulty"}
    }
] call zen_context_menu_fnc_createAction;

// Add parent category
private _parentPath = [_parentAction, [], 0] call zen_context_menu_fnc_addAction;

// Add child actions
[_actionInfo, _parentPath, 0] call zen_context_menu_fnc_addAction;
[_actionToggleDebug, _parentPath, 1] call zen_context_menu_fnc_addAction;
[_actionInstantDefuse, _parentPath, 2] call zen_context_menu_fnc_addAction;
[_actionInstantDetonate, _parentPath, 3] call zen_context_menu_fnc_addAction;

diag_log "MSIED: Context menu actions registered successfully";

true
