params ["_unitRef", ["_count", 1]];

private _unit = if (_unitRef isEqualType "") then {
    objectFromNetId _unitRef
} else {
    _unitRef
};

if (isNull _unit) exitWith {};

private _markerId = format [
    "FEF_REINSERT_%1_%2",
    getPlayerUID _unit,
    floor diag_tickTime
];

private _markerType = switch (_count) do {
    case 1: { "FEF_MarkerReinsertX1" };
    case 2: { "FEF_MarkerReinsertX2" };
    case 3: { "FEF_MarkerReinsertX3" };
    case 4: { "FEF_MarkerReinsertX4" };
    case 5: { "FEF_MarkerReinsertX5" };
    default { "mil_pickup" };
};

private _marker = createMarkerLocal [_markerId, getPosATL _unit];
_marker setMarkerTypeLocal _markerType;
_marker setMarkerColorLocal "ColorBlue";
_marker setMarkerTextLocal format ["REINSERT x%1", _count];

[_markerId, _unit] spawn {
    params ["_markerId", "_unit"];
    private _endTime = time + 120;
    while {time < _endTime && {!isNull _unit}} do {
        _markerId setMarkerPosLocal (getPosATL _unit);
        uiSleep 2;
    };
    deleteMarkerLocal _markerId;
};
