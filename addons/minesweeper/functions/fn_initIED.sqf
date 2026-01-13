// This function is called on SERVER, then broadcasts to all clients for action setup
params [
    ["_ied", objNull, [objNull]],
    ["_difficulty", "medium", [""]],
    ["_mineCount", 20, [0]],
    ["_timeLimit", 90, [0]],
    ["_explosionSize", "large", [""]],
    ["_triggerSide", civilian, ["", west]],
    ["_debugMode", false, [false]],
    ["_preDefusalBeep", false, [false]],
    ["_gridWidth", 12, [0]],
    ["_gridHeight", 12, [0]]
];

if (isNull _ied) exitWith {false};
if (!isServer) exitWith {false};

// Check if already initialized AND still active (allow re-init if defused/detonated)
private _initialized = _ied getVariable ["MSIED_Initialized", false];
private _defused = _ied getVariable ["MSIED_Defused", false];
private _detonated = _ied getVariable ["MSIED_Detonated", false];

if (_initialized && !_defused && !_detonated) exitWith {true};

// Convert string to side if needed
if (_triggerSide isEqualType "") then {
    switch (toLower _triggerSide) do {
        case "west": { _triggerSide = west; };
        case "east": { _triggerSide = east; };
        case "resistance": { _triggerSide = resistance; };
        case "civilian": { _triggerSide = civilian; }; // Used as "none"
        default { _triggerSide = civilian; };
    };
};

// Set IED variables (public - syncs to all clients)
_ied setVariable ["MSIED_Initialized", true, true];
_ied setVariable ["MSIED_difficulty", _difficulty, true];
_ied setVariable ["MSIED_mineCount", _mineCount, true];
_ied setVariable ["MSIED_timeLimit", _timeLimit, true];
_ied setVariable ["MSIED_explosionSize", _explosionSize, true];
_ied setVariable ["MSIED_preDefusalBeep", _preDefusalBeep, true];
_ied setVariable ["MSIED_Defuser", objNull, true];
_ied setVariable ["MSIED_Defused", false, true];
_ied setVariable ["MSIED_Detonated", false, true];
_ied setVariable ["MSIED_Side", _triggerSide, true];
_ied setVariable ["MSIED_Debug", _debugMode, true];
_ied setVariable ["MSIED_GridWidth", _gridWidth, true];
_ied setVariable ["MSIED_GridHeight", _gridHeight, true];

// Add debug flag if enabled (server creates, automatically syncs to clients)
if (_debugMode) then {
    private _flagPos = ASLToAGL getPosASL _ied;
    _flagPos set [2, (_flagPos select 2) + 2]; // 2m above object
    
    private _flag = "Sign_Sphere100cm_F" createVehicle _flagPos;
    _flag setObjectTexture [0, "#(rgb,8,8,3)color(1,0,0,0.8)"];
    _flag setPosASL (AGLToASL _flagPos);
    
    _ied setVariable ["MSIED_DebugFlag", _flag, true];
    
    // Clean up flag when IED is defused/detonated
    _ied addEventHandler ["Killed", {
        params ["_unit"];
        private _flag = _unit getVariable ["MSIED_DebugFlag", objNull];
        if (!isNull _flag) then {
            deleteVehicle _flag;
        };
    }];
};

// Start the IED tick (server side only)
[_ied] spawn MSIED_fnc_iedTick;

// Start pre-defusal warning beep if enabled
if (_preDefusalBeep) then {
    [_ied] spawn MSIED_fnc_preDefusalBeep;
};

// Add defuse action on ALL clients (including JIP)
[_ied] remoteExec ["MSIED_fnc_addDefuseAction", 0, _ied];

true
