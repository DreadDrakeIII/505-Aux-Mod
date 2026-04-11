params ["_unitRef", ["_type", "pickup"], ["_markerPos", []]];

private _unit = if (_unitRef isEqualType "") then {
    objectFromNetId _unitRef
} else {
    _unitRef
};

if (isNull _unit) exitWith {};

private _pos = if (count _markerPos > 0) then {
    _markerPos
} else {
    getPosATL _unit
};

private _markerId = format [
    "FEF_LZ_%1_%2",
    getPlayerUID _unit,
    floor diag_tickTime
];

private _markerType = switch (_type) do {
    case "dropoff": { "FEF_MarkerLZDropoff" };
    case "casevac": { "FEF_MarkerMedevac" };
    default         { "FEF_MarkerLZPickup" };
};

private _colour = switch (_type) do {
    case "hot":     { "ColorRed" };
    case "clear":   { "ColorGreen" };
    case "casevac": { "ColorRed" };
    case "dropoff": { "ColorGreen" };
    default         { "ColorBlue" };
};

private _label = switch (_type) do {
    case "pickup":  { "LZ PICKUP"};
    case "dropoff": { "LZ DROP-OFF" };
    case "casevac": { "LZ CASEVAC" };
    case "extract": { "LZ EXTRACT" };
    case "hot":     { "HOT LZ" };
    case "clear":   { "LZ CLEAR" };
    default         { format ["LZ - %1", name _unit] };
};

private _marker = createMarkerLocal [_markerId, _pos];
_marker setMarkerTypeLocal _markerType;
_marker setMarkerColorLocal _colour;
_marker setMarkerTextLocal _label;

[{
    params ["_markerId"];
    deleteMarkerLocal _markerId;
}, [_markerId], 120] call CBA_fnc_waitAndExecute;
