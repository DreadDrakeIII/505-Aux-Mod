params ["_message"];

_message call CWR_fnc_devLog;
_message = switch (true) do {
    case ("[distance]" in _message): {
        [_message] spawn CWR_OpenDistanceMenu;
    };

    case ("[status]" in _message): {
        [_message] spawn CWR_OpenStatusMenu;
    };

    case ("[enemy]" in _message): {
        [_message] spawn CWR_OpenEnemyMenu;
    };

    case ("[bearing]" in _message): {
        private _bearing = round direction player;
        _message = [_message, "[bearing]", str _bearing] call CWR_fnc_stringReplace;
        _message call CWR_fnc_processTags;
    };

    case ("[direction]" in _message): {
        private _bearing = round direction player;
        private _facing = _bearing call CWR_fnc_getDirFromBearing;

        _message = [_message, "[direction]", _facing] call CWR_fnc_stringReplace;
        _message call CWR_fnc_processTags;
    };

    case ("[weapon]" in _message): {
        private _currentWeapon = getText (configFile >> "CfgWeapons" >> currentWeapon player >> "displayName");
        _message = [_message, "[weapon]", _currentWeapon] call CWR_fnc_stringReplace;
        _message call CWR_fnc_processTags;
    };

    case ("[launcher]" in _message): {
        [_message] spawn CWR_OpenLauncherMenu;
    };

    case ("[ping]" in _message): {
        private _playerPos = getPosATL player;
        private _nearbyPlayers = [_playerPos, CWR_Voice_VoiceRadius, false] call CWR_fnc_getNearbyPlayers;

        {
            [_playerPos, name player] remoteExecCall ["CWR_fnc_createCasualtyPing", _x];
        } forEach _nearbyPlayers;

        _message = [_message, "[ping]", ""] call CWR_fnc_stringReplace;
        _message call CWR_fnc_processTags;
    };

    case (count (_message call CWR_fnc_findAllVoicelineTags) > 0): {
        private _tag = _message call CWR_fnc_findAllVoicelineTags select 0 select 0 select 0;
        private _configName = _tag call CWR_fnc_getConfigNameFromTag;

        _message = [_message, _tag, ""] call CWR_fnc_stringReplace;

        private _lang = missionNamespace getVariable ["CWR_voiceLang", "en_US"];

            private _config = (configFile >> "CWR_VoiceLines" >> _lang >> _configName);

            // Fallback if GB is missing a tag
            if (!isClass _config) then {
                _config = (configFile >> "CWR_VoiceLines" >> "en_US" >> _configName);
            };

        if (isClass _config) then {
            if ((time - (player getVariable ["CWR_playerLastUsedVoice", -CWR_Voice_CoolDown])) > CWR_Voice_CoolDown ) then {
                private _voiceLine = selectRandom getArray (_config >> "voiceLines");
                private _nearbyPlayers = [getPosATL player, CWR_Voice_VoiceRadius, CWR_Voice_RCUnitsSendsMessages] call CWR_fnc_getNearbyPlayers;
 {
                    [_voiceLine, player] remoteExecCall ["CWR_fnc_playLocalSound", _x];
                } forEach _nearbyPlayers;

                player setVariable ["CWR_playerLastUsedVoice", time];
            };
        };

        _message call CWR_fnc_processTags;
    };

    default {
        params ["_message"];

        _message;
    };
};

_message;
