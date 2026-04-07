/*
    File: fn_sendReinsertRequest.sqf
    Purpose:
    Sends a side-chat reinsert request with requested seat count.
*/

params [
    ["_count", 1],
    ["_unit", player]
];

if (isNull _unit) exitWith {};

_count = (_count max 1) min 5;

// Optional cooldown
private _nextAllowed = _unit getVariable ["FEF_ReinsertCooldown", 0];
if (time < _nextAllowed) exitWith {
    hint "Reinsert request is on cooldown.";
};

_unit setVariable ["FEF_ReinsertCooldown", time + 60];

private _message = format ["Reinsert request, x%1 required at my position!", _count];

// Side chat is allowed for reinsert
_unit sideChat _message;

// Optional side-visible marker
private _sideRecipients = allPlayers select {
    isPlayer _x &&
    {side group _x isEqualTo side group _unit}
};

{
    [netId _unit, _count] remoteExecCall ["FEF_fnc_createReinsertMarkerLocal", _x];
} forEach _sideRecipients;
