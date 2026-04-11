/*
 * Sends a MEDEVAC request over command channel.
 * Restricted to Squad Leaders and Pilots only.
 */
params [
    ["_type", "routine"],
    ["_unit", player]
];

if (isNull _unit) exitWith {};

if !([_unit] call FEF_fnc_isAuthorizedComms) exitWith {
    hint "MEDEVAC channel restricted to Squad Leaders and Pilots only.";
};

private _nextAllowed = _unit getVariable ["FEF_MedevacCooldown", 0];
if (time < _nextAllowed) exitWith {
    hint "MEDEVAC request is on cooldown.";
};
_unit setVariable ["FEF_MedevacCooldown", time + 60];

private _message = switch (_type) do {
    case "urgent":   { format ["MEDEVAC URGENT — %1 requires immediate extraction!", name _unit] };
    case "priority": { format ["MEDEVAC PRIORITY — %1 requesting priority medical extraction!", name _unit] };
    case "routine":  { format ["MEDEVAC ROUTINE — %1 requesting medical extraction.", name _unit] };
    default          { format ["MEDEVAC — %1 requesting medical extraction.", name _unit] };
};

// Command channel — leaders and command chain only
_unit commandChat _message;

// Marker to all same side
private _sideRecipients = allPlayers select {
    isPlayer _x &&
    { side group _x isEqualTo side group _unit }
};

{
    [netId _unit, _type] remoteExecCall ["FEF_fnc_createMedevacMarkerLocal", _x];
} forEach _sideRecipients;
