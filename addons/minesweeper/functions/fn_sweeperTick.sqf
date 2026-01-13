disableSerialization;

params [["_ied", objNull, [objNull]]];

if (isNull _ied) exitWith {};

private _timer = _ied getVariable ["MSIED_Timer", 60];

private _startTime = time;
private _lastBeepTime = 0;

while {true} do {
    private _delta = time - _startTime;
    private _curTime = _timer - _delta;
    
    // Update timer display
    ctrlSetText [1000, format ["%1", floor _curTime]];
    
    // Play 3D beeping sounds based on time remaining
    private _beepInterval = 1; // Default: every 1 second

    if (_curTime <= 30) then {
        private _startT = 30;
        private _intervalAtStart = 0.5;
        private _intervalAtEnd = 0.08;

        private _t = (_startT - _curTime) / _startT;
        _t = (_t max 0) min 1;

        private _p = 2;                 // increase to delay panic more 
        private _te = _t ^ _p;           // eased t

        _beepInterval = _intervalAtStart + (_intervalAtEnd - _intervalAtStart) * _te;
    };
    
    // Check if it's time for a beep
    if ((time - _lastBeepTime) >= _beepInterval) then {
        // Play 3D beep from IED location
        playSound3D ["\BLU\OLI\addons\minesweeper\sounds\beep.ogg", _ied, false, getPosASL _ied, 5, 1, 50];
        _lastBeepTime = time;
    };
    
    // Check if time ran out
    if (_curTime < 0) exitWith {
        [_ied, true] call MSIED_fnc_detonate; // Pass true to indicate timer failure
    };
    
    sleep 0.02;
    
    // Exit if dialog is closed
    if (!dialog) exitWith {
        // Only detonate if not already defused
        private _defused = _ied getVariable ["MSIED_Defused", false];
        if (!_defused) then {
            [_ied, true] call MSIED_fnc_detonate; // Pass true to indicate early exit failure
        };
    };
};
