params ["_message", ["_speaker", player], ["_voiceKey", ""]];

private _resolved = [_message, _speaker] call FEF_fnc_resolveText;
if (_resolved isEqualTo "") exitWith {};

// remoteExecCall to group so ALL members see the message
[_speaker, _resolved] remoteExecCall ["groupChat", group _speaker];

if (_voiceKey isEqualTo "") exitWith {};
if (!FEF_Voice_EnableVoiceLines) exitWith {};

private _soundClass = [_voiceKey] call FEF_fnc_resolveVoiceLine;
if (_soundClass isEqualTo "") exitWith {};

private _voiceRadius = if (isNil "FEF_Voice_VoiceRadius") then {35} else {FEF_Voice_VoiceRadius};

private _listeners = [getPosATL _speaker, _voiceRadius, false] call FEF_fnc_getNearbyPlayers;
{
    [netId _speaker, _soundClass, _voiceRadius] remoteExecCall ["FEF_fnc_playLocalVoiceLine", _x];
} forEach _listeners;
