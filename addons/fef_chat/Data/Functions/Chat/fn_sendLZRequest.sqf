/*
 * Sends an LZ request over command channel.
 * Restricted to Squad Leaders and Pilots only.
 */
params [
    ["_type", "pickup"],
    ["_unit", player],
    ["_pos", []]
];

if (isNull _unit) exitWith {};

if !([_unit] call FEF_fnc_isAuthorizedComms) exitWith {
    hint "LZ channel restricted to Squad Leaders and Pilots only.";
};

private _nextAllowed = _unit getVariable ["FEF_LZCooldown", 0];
if (time < _nextAllowed) exitWith {
    hint "LZ request is on cooldown.";
};
_unit setVariable ["FEF_LZCooldown", time + 60];

private _markerPos = if (count _pos > 0) then { _pos } else { getPosATL _unit };

private _message = switch (_type) do {
    case "pickup":  { format ["LZ REQUEST — %1 requesting pickup!", name _unit] };
    case "dropoff": { format ["LZ REQUEST — %1 requesting drop-off!", name _unit] };
    case "casevac": { format ["LZ REQUEST — %1 requesting CASEVAC!", name _unit] };
    case "extract": { format ["LZ REQUEST — %1 requesting full squad extraction!", name _unit] };
    case "hot":     { format ["HOT LZ — %1 reports LZ is HOT!", name _unit] };
    case "clear":   { format ["LZ CLEAR — %1 reports LZ is clear and ready.", name _unit] };
    default         { format ["LZ REQUEST — %1 requesting aviation support.", name _unit] };
};

_unit commandChat _message;

// Marker to leaders and pilots only
private _sideRecipients = allPlayers select {
    isPlayer _x &&
    { side group _x isEqualTo side group _unit } &&
    { [_x] call FEF_fnc_isAuthorizedComms }
};

{
    [netId _unit, _type, _markerPos] remoteExecCall ["FEF_fnc_createLZMarkerLocal", _x];
} forEach _sideRecipients;
