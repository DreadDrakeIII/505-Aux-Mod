/*
    File: fn_sendFriendlyDownAlert.sqf
*/

params [["_unit", player]];

if (isNull _unit) exitWith {};

private _message = "Friendly down! Corpsman needed here!";

// 1) group chat text
_unit groupChat _message;

// 2) same-side recipients
private _sideRecipients = allPlayers select {
    isPlayer _x &&
    {side group _x isEqualTo side group _unit}
};

// 3) side-visible local marker + local tactical ping
{
    [netId _unit] remoteExecCall ["FEF_fnc_createFriendlyDownMarkerLocal", _x];
} forEach _sideRecipients;
