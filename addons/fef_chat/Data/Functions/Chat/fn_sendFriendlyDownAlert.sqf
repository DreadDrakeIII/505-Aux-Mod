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

// Distribute to every human player in group (filter out AI to avoid SP duplicates)
{
    [_speaker, _message] remoteExecCall ["FEF_fnc_sendLocalMessage", _x];
} forEach (units group _unit select { isPlayer _x });
