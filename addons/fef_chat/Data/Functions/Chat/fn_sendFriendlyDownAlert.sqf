/*
    File: fn_sendFriendlyDownAlert.sqf
*/

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

// Group chat
_unit groupChat _message;

// Same side recipients — marker + ping
private _sideRecipients = allPlayers select {
    isPlayer _x &&
    { side group _x isEqualTo side group _unit }
};

{
    [netId _unit] remoteExecCall ["FEF_fnc_createFriendlyDownMarkerLocal", _x];
    [netId _unit] remoteExecCall ["FEF_fnc_createCasualtyPingLocal", _x];
} forEach _sideRecipients;
