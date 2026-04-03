/*
 * Author: DartRuffian and Revgamer
 * Modified to support KAT Medical and AI units (friendlies only).
 * Single machine detection, each nearby player sends message as themselves.
 */

if (isDedicated) exitWith {};

private _hasMedical =
    (isClass (configFile >> "CfgPatches" >> "ace_medical")) ||
    (isClass (configFile >> "CfgPatches" >> "kat_main"));

diag_log format ["[CWR_fnc_unconsciousEH] hasMedical: %1", _hasMedical];

if !(_hasMedical) exitWith { diag_log "[CWR_fnc_unconsciousEH] Exiting - no medical mod detected"; };
if !(CWR_AutoMessages_Uncon) exitWith { diag_log "[CWR_fnc_unconsciousEH] Exiting - Uncon setting is false"; };

diag_log "[CWR_fnc_unconsciousEH] PFH registered - watching for unconscious units";

[{
    params ["_args", "_handle"];

    if !(CWR_AutoMessages_Uncon) exitWith {
        [_handle] call CBA_fnc_removePerFrameHandler;
    };

    // Only the first player in allPlayers runs detection to avoid duplicates
    if (player != (allPlayers select 0)) exitWith {};

    {
        private _unit = _x;
        if (isNull _unit) then { continue; };
        if !(alive _unit) then { continue; };

        private _wasDown = _unit getVariable ["CWR_wasDown", false];

        private _isIncapacitated = (lifeState _unit) isEqualTo "INCAPACITATED";
        private _isAwake = true;
        if (!isNil "ace_common_fnc_isAwake") then {
            _isAwake = [_unit] call ace_common_fnc_isAwake;
        };
        private _isDown = _isIncapacitated || !_isAwake;

        // Trigger only on transition from up -> down
        if (_isDown && !_wasDown) then {
            _unit setVariable ["CWR_wasDown", true, true]; // broadcast to all clients

            // Get ALL nearby conscious players excluding the downed unit
            private _nearbyPlayers = (getPosATL _unit) nearEntities ["CAManBase", CWR_Voice_VoiceRadius];
            _nearbyPlayers = _nearbyPlayers select {
                isPlayer _x &&
                {_x != _unit} &&
                {if (!isNil "ace_common_fnc_isAwake") then {
                    [_x] call ace_common_fnc_isAwake
                } else { true }}
            };

            // Fallback: if no players nearby but conscious friendlies exist, use local player
            if (_nearbyPlayers isEqualTo []) then {
                private _nearbyFriendly = (getPosATL _unit) nearEntities ["CAManBase", CWR_Voice_VoiceRadius];
                _nearbyFriendly = _nearbyFriendly select {
                    _x != _unit &&
                    {side group _x == side group player} &&
                    {if (!isNil "ace_common_fnc_isAwake") then {
                        [_x] call ace_common_fnc_isAwake
                    } else { true }}
                };
                if (!(_nearbyFriendly isEqualTo []) && {
                    if (!isNil "ace_common_fnc_isAwake") then {
                        [player] call ace_common_fnc_isAwake
                    } else { true }
                }) then {
                    _nearbyPlayers = [player];
                };
            };

            diag_log format ["[CWR_fnc_unconsciousEH] %1 went down - broadcasting to %2 players", name _unit, count _nearbyPlayers];

            if (_nearbyPlayers isEqualTo []) then { continue; };

            // Send to each nearby player - they send as themselves in group chat
            {
                private _responder = _x;

                // Pick a random message per responder so each player says something different
                private _downMessages = [
                    format ["Damn it! %1 is down!", name _unit],
                    format ["%1 is down, they're hurt bad!", name _unit],
                    format ["Jesus Christ! %1 is down!", name _unit],
                    format ["%1 is down! Corpsman!!", name _unit],
                    format ["We got a man down! %1 is down!", name _unit]
                ];

                // remoteExec to responder's machine - they send as themselves
                [_responder, selectRandom _downMessages] remoteExecCall ["CWR_fnc_sendLocalMessage", _responder];

                private _isOnCooldown = ((time - (_responder getVariable ["CWR_playerLastUsedVoice", -CWR_Voice_CoolDown])) < CWR_Voice_CoolDown);

                private _lang = missionNamespace getVariable ["CWR_voiceLang", "en_US"];
                private _config = (configFile >> "CWR_VoiceLines" >> _lang >> "Unconscious");
                if (!isClass _config) then {
                    _config = (configFile >> "CWR_VoiceLines" >> "en_US" >> "Unconscious");
                };

                if (isClass _config && !_isOnCooldown) then {
                    private _voiceLine = selectRandom getArray (_config >> "voiceLines");
                    [_voiceLine, netId _responder] remoteExecCall ["CWR_fnc_playLocalSound", _responder];
                    _responder setVariable ["CWR_playerLastUsedVoice", time];
                };
            } forEach _nearbyPlayers;
        };

        // Reset flag when unit gets back up
        if (!_isDown && _wasDown) then {
            _unit setVariable ["CWR_wasDown", false, true]; // broadcast to all clients
        };

    } forEach ((getPos player) nearEntities ["CAManBase", 200] select {
        side group _x == side group player
    });

}, 1, []] call CBA_fnc_addPerFrameHandler;