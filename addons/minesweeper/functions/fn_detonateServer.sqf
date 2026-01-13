// Server-side detonation handler
// Handles explosion, sounds, and cleanup

params [
    ["_ied", objNull, [objNull]],
    ["_isFailure", false, [false]]
];

if (isNull _ied) exitWith {};
if (!isServer) exitWith {};

// Check if already detonated or defused (double-check on server)
private _detonated = _ied getVariable ["MSIED_Detonated", false];
private _defused = _ied getVariable ["MSIED_Defused", false];

if (_detonated || _defused) exitWith {};

// Set detonated flag IMMEDIATELY to prevent double calls
_ied setVariable ["MSIED_Detonated", true, true];

// Get settings
private _explosionSize = _ied getVariable ["MSIED_explosionSize", "large"];

// Clear defuser variable
_ied setVariable ["MSIED_Defuser", objNull, true];

// Determine explosion type based on size setting
private _explosionType = "HelicopterExploSmall"; // Default: Large

switch (toLower _explosionSize) do {
    case "small": { _explosionType = "SmallSecondary"; };
    case "medium": { _explosionType = "ammo_Bomb_SDB"; };
    case "large": { _explosionType = "HelicopterExploSmall"; };
    case "huge": { _explosionType = "Bo_GBU12_LGB"; };
};

// Play failure sound if this is a failure
if (_isFailure) then {
    playSound3D ["\BLU\OLI\addons\minesweeper\sounds\failure.ogg", _ied, false, getPosASL _ied, 5, 1, 50];
};

// Create explosion after delay (for failure sound to play)
[_ied, _explosionType, _isFailure] spawn {
    params ["_ied", "_explosionType", "_isFailure"];
    
    // Wait for failure sound to play
    if (_isFailure) then {
        sleep 1.6;
    };
    
    if (!isNull _ied) then {
        private _pos = getPos _ied;
        _pos set [2, 1];
        _explosionType createVehicle _pos;
    };
    
    // Clean up debug flag
    private _debugFlag = _ied getVariable ["MSIED_DebugFlag", objNull];
    if (!isNull _debugFlag) then {
        deleteVehicle _debugFlag;
    };
    
    // Remove from JIP queue
    remoteExecCall ["", _ied];
};
