params ["_logic", "_units", "_activated"];

if (!_activated) exitWith {};

private _difficulty = _logic getVariable ["Difficulty", "easy"];
private _triggerSide = _logic getVariable ["TriggerSide", "everyone"];

// Get object at module position (auto-detect what Zeus placed it on)
private _modulePos = getPos _logic;
private _ied = objNull;

// Method 1: Check for synced objects first (if Zeus operator manually synced)
private _syncedObjects = synchronizedObjects _logic;
if (count _syncedObjects > 0) then {
    _ied = _syncedObjects select 0;
};

// Method 2: If no synced object, find nearest object at module position
if (isNull _ied) then {
    // Get all nearby objects within 1 meter
    private _nearObjects = nearestObjects [_modulePos, ["All"], 3];
    
    // Filter out the module itself and find a valid target
    {
        if (_x != _logic && {!isNull _x} && {alive _x}) exitWith {
            _ied = _x;
        };
    } forEach _nearObjects;
};

// Validation
if (isNull _ied) exitWith {
    // Show error to Zeus operator
    [
        "Minesweeper IED",
        "No valid object found! Place the module directly on or very close to an object.",
        ""
    ] call BIS_fnc_showNotification;
    
    // Delete the module
    deleteVehicle _logic;
    false
};

// Apply difficulty presets (matching zenModule values)
private _gridWidth = 9;
private _gridHeight = 9;
private _mineCount = 10;
private _timeLimit = 55;

switch (toLower _difficulty) do {
    case "easy": {
        _gridWidth = 9;
        _gridHeight = 9;
        _mineCount = 10;
        _timeLimit = 55;
    };
    case "medium": {
        _gridWidth = 12;
        _gridHeight = 12;
        _mineCount = 20;
        _timeLimit = 90;
    };
    case "hard": {
        _gridWidth = 16;
        _gridHeight = 16;
        _mineCount = 40;
        _timeLimit = 150;
    };
};

// Initialize the IED on the server
if (isServer) then {
    [_ied, _difficulty, _mineCount, _timeLimit, "large", _triggerSide, false, false, _gridWidth, _gridHeight] call MSIED_fnc_initIED;
    
    // Notify Zeus operator of success
    [
        "Minesweeper IED",
        format ["IED created on %1 (%2 difficulty, %3 trigger)", getText (configFile >> "CfgVehicles" >> typeOf _ied >> "displayName"), _difficulty, _triggerSide],
        ""
    ] call BIS_fnc_showNotification;
};

// Delete the module logic
deleteVehicle _logic;

true
