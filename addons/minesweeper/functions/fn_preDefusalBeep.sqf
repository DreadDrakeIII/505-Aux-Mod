params [["_ied", objNull, [objNull]]];

if (isNull _ied) exitWith {};
if (!isServer) exitWith {}; // Server only

while {true} do {
    // Check if IED has been detonated or defused
    private _detonated = _ied getVariable ["MSIED_Detonated", false];
    private _defused = _ied getVariable ["MSIED_Defused", false];
    
    // Check if someone is defusing
    private _defuser = _ied getVariable ["MSIED_Defuser", objNull];
    
    // Stop beeping if detonated, defused, or someone is defusing
    if (_detonated || _defused || !isNull _defuser) exitWith {};
    
    // Play 3D beep sound from IED location
    // Play 3D beep sound from IED location
    playSound3D ["\BLU\OLI\addons\minesweeper\sounds\beep.ogg", _ied, false, getPosASL _ied, 5, 1, 50];
    
    // Wait 1.5 seconds before next beep
    sleep 1.5;
};
