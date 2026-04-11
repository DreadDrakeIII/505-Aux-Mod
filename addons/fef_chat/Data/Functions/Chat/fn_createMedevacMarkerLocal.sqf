params ["_unitRef", ["_type", "routine"]];

private _unit = if (_unitRef isEqualType "") then {
    objectFromNetId _unitRef
} else {
    _unitRef
};

if (isNull _unit) exitWith {};

private _markerId = format [
    "FEF_MEDEVAC_%1_%2",
    getPlayerUID _unit,
    floor diag_tickTime
];

private _colour = switch (_type) do {
    case "urgent":   { "ColorRed" };
    case "priority": { "ColorOrange" };
    default          { "ColorYellow" };
};

private _marker = createMarkerLocal [_markerId, getPosATL _unit];
_marker setMarkerTypeLocal "FEF_MarkerMedevac";
_marker setMarkerColorLocal _colour;
_marker setMarkerTextLocal format ["MEDEVAC %1", toUpper _type];

[_markerId, _unit] spawn {
    params ["_markerId", "_unit"];
    private _endTime = time + 120;
    while {time < _endTime && {!isNull _unit}} do {
        _markerId setMarkerPosLocal (getPosATL _unit);
        uiSleep 2;
    };
    deleteMarkerLocal _markerId;
};
