/*
    File: fn_createFriendlyDownMarkerLocal.sqf
    Purpose:
    Creates a temporary local casualty marker for the supplied unit.
    Runs locally on each recipient client.
*/

params ["_unitRef"];

private _unit = if (_unitRef isEqualType "") then {
    objectFromNetId _unitRef
} else {
    _unitRef
};

if (isNull _unit) exitWith {};

private _markerId = format [
    "FEF_CAS_%1_%2",
    getPlayerUID _unit,
    floor diag_tickTime
];

private _marker = createMarkerLocal [_markerId, getPosATL _unit];
_marker setMarkerTypeLocal "mil_warning";
_marker setMarkerColorLocal "ColorRed";
_marker setMarkerTextLocal format ["CASUALTY - %1", name _unit];

[_markerId, _unit] spawn {
    params ["_markerId", "_unit"];

    private _endTime = time + 20;

    while {time < _endTime && {!isNull _unit}} do {
        _markerId setMarkerPosLocal (getPosATL _unit);
        uiSleep 1;
    };

    deleteMarkerLocal _markerId;
};
