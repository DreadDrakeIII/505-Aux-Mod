params [["_ied", objNull, [objNull]]];

if (isNull _ied) exitWith {};
if (!isServer) exitWith {}; // Server only

private _triggerSide = _ied getVariable ["MSIED_Side", civilian];

// If trigger side is civilian, treat as "none" and don't trigger
private _isNone = (_triggerSide == civilian);

while {true} do {
    // Check if IED has been detonated or defused
    private _detonated = _ied getVariable ["MSIED_Detonated", false];
    private _defused = _ied getVariable ["MSIED_Defused", false];
    
    if (_detonated || _defused) exitWith {};
    
    // If set to "none" (civilian), skip trigger checks
    if (!_isNone) then {
        // Get nearby objects
        private _nearObjects = _ied nearObjects 8;
        
        {
            private _obj = _x;
            private _objSide = side _obj;
            
            // Check if object matches trigger side
            private _shouldTrigger = false;
            
            if (_triggerSide isEqualType "") then {
                if (_triggerSide == "everyone") then {
                    _shouldTrigger = (_objSide in [west, east, resistance]);
                };
            } else {
                _shouldTrigger = (_objSide == _triggerSide);
            };
            
            // Trigger if moving fast enough
            if (_shouldTrigger && {speed _obj > 4.9}) exitWith {
                [_ied] call MSIED_fnc_detonate;
            };
            
        } forEach _nearObjects;
    };
    
    sleep 0.5;
};
