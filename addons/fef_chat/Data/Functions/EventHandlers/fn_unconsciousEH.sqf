if (!hasInterface) exitWith {};

missionNamespace setVariable ["FEF_LastUnconsciousState", false];

[{
    if (!hasInterface) exitWith {};
    if (isNull player) exitWith {};

    private _currentState = (player getVariable ["ACE_isUnconscious", false]) ||
                            {lifeState player isEqualTo "INCAPACITATED"};
    private _lastState = missionNamespace getVariable ["FEF_LastUnconsciousState", false];

    if (_currentState && !_lastState) then {
        if (FEF_AutoMessages_Enabled && FEF_AutoMessages_Unconscious) then {
            [player] call FEF_fnc_sendFriendlyDownAlert;
        };
    };

    missionNamespace setVariable ["FEF_LastUnconsciousState", _currentState];

}, 0.5, []] call CBA_fnc_addPerFrameHandler;
