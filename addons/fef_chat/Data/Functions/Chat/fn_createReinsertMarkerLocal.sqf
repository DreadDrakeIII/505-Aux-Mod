/*
    File: fn_createReinsertMarkerLocal.sqf
    Purpose:
    Creates a temporary local reinsert marker.
*/

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

private _marker = createMarkerLocal [_markerId, getPosATL _unit];
_marker setMarkerTypeLocal "mil_pickup";
_marker setMarkerColorLocal "ColorBlue";
_marker setMarkerTextLocal format ["REINSERT x%1 - %2", _count, name _unit];

[_markerId, _unit] spawn {
    params ["_markerId", "_unit"];

    private _endTime = time + 20;

    while {time < _endTime && {!isNull _unit}} do {
        _markerId setMarkerPosLocal (getPosATL _unit);
        uiSleep 2;
    };

    deleteMarkerLocal _markerId;
};
