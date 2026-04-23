params [["_unit", player]];

if (isNull _unit) exitWith {};

private _messages = [
    format ["Damn it! %1 is down!", name _unit],
    format ["%1 is down, they're hurt bad!", name _unit],
    format ["Jesus Christ! %1 is down!", name _unit],
    format ["%1 is down! Corpsman!!", name _unit],
    format ["We got a man down! %1 is down!", name _unit]
];

private _message = _messages select (floor (random (count _messages)));

// Find a nearby conscious player to be the speaker — not the casualty themselves
private _nearby = [getPosATL _unit, FEF_Voice_VoiceRadius, false] call FEF_fnc_getNearbyPlayers;

private _speaker = objNull;
{
    if (_x != _unit && alive _x && !(_x getVariable ["ACE_isUnconscious", false])) exitWith {
        _speaker = _x;
    };
} forEach _nearby;

// Only send if someone nearby can report it — casualty can't report themselves
if (isNull _speaker) exitWith {};

// Route to speaker's machine so they call groupChat locally — Arma replicates to group from there
[_speaker, _message] remoteExec ["FEF_fnc_speakerGroupChat", _speaker];

// Same side recipients — marker + ping (side-wide, map-scoped)
private _sideRecipients = allPlayers select {
    isPlayer _x &&
    { side group _x isEqualTo side group _unit }
};

{
    [netId _unit] remoteExecCall ["FEF_fnc_createFriendlyDownMarkerLocal", _x];
    [netId _unit] remoteExecCall ["FEF_fnc_createCasualtyPingLocal", _x];
} forEach _sideRecipients;
