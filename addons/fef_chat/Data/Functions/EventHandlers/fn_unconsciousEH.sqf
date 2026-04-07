if (!hasInterface) exitWith {};

missionNamespace setVariable ["FEF_LastUnconsciousState", false];

[
    {
        if (!hasInterface) exitWith {};
        if (isNull player) exitWith {};

        private _currentState = (player getVariable ["ACE_isUnconscious", false]) || {lifeState player isEqualTo "INCAPACITATED"};
        private _lastState = missionNamespace getVariable ["FEF_LastUnconsciousState", false];

        if (_currentState && !_lastState) then {
            private _unconsciousEnabled = missionNamespace getVariable ["FEF_Auto_EnableUnconsciousCallouts", true];

            if (_unconsciousEnabled) then {
                private _casualty = player;

                private _voiceRadius = missionNamespace getVariable ["FEF_Voice_VoiceRadius", 35];
                if !(_voiceRadius isEqualType 0) then {
                    _voiceRadius = 35;
                };
                if (_voiceRadius < 0) then {
                    _voiceRadius = 35;
                };

                private _nearby = [getPosATL _casualty, _voiceRadius, false] call FEF_fnc_getNearbyPlayers;

                private _speaker = _casualty;
                {
                    if (_x != _casualty && alive _x && !(_x getVariable ["ACE_isUnconscious", false])) exitWith {
                        _speaker = _x;
                    };
                } forEach _nearby;

                private _recipients = [];
                {
                    if (isPlayer _x) then { _recipients pushBackUnique _x; };
                } forEach (units group _casualty);

                {
                    if (isPlayer _x) then { _recipients pushBackUnique _x; };
                } forEach _nearby;

                _recipients pushBackUnique _casualty;

                private _message = format ["%1 is down!", name _casualty];

                {
                    [_speaker, _message] remoteExecCall ["FEF_fnc_sendLocalMessage", _x];
                } forEach _recipients;

                private _voiceEnabled = missionNamespace getVariable ["FEF_Voice_EnableVoiceLines", true];
                if (_voiceEnabled) then {
                    private _soundClass = ["Unconscious"] call FEF_fnc_resolveVoiceLine;
                    if !(_soundClass isEqualTo "") then {
                        {
                            [netId _speaker, _soundClass, _voiceRadius] remoteExecCall ["FEF_fnc_playLocalVoiceLine", _x];
                        } forEach _recipients;
                    };
                };
            };
        };

        missionNamespace setVariable ["FEF_LastUnconsciousState", _currentState];
    },
    0.5,
    []
] call CBA_fnc_addPerFrameHandler;
