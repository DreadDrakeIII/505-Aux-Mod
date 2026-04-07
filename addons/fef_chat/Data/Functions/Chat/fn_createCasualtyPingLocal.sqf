/*
    File: fn_createCasualtyPingLocal.sqf
    Purpose:
    Draws a temporary 3D casualty ping above the unit for local client only.
*/

params ["_unitRef"];

private _unit = if (_unitRef isEqualType "") then {
    objectFromNetId _unitRef
} else {
    _unitRef
};

if (isNull _unit) exitWith {};

private _id = format ["FEF_CASPING_%1_%2", getPlayerUID _unit, floor diag_tickTime];
private _endTime = time + 20;

missionNamespace setVariable [_id, [_unit, _endTime]];

private _eh = addMissionEventHandler ["Draw3D", {
    {
        private _key = _x;
        private _data = missionNamespace getVariable [_key, []];
        if (_data isEqualTo []) then { continue };

        _data params ["_unit", "_endTime"];

        if (isNull _unit || {time > _endTime}) then {
            missionNamespace setVariable [_key, nil];
            continue;
        };

        private _pos = visiblePositionASL _unit;
        _pos set [2, (_pos select 2) + 1.8];

        drawIcon3D [
            "\a3\ui_f\data\map\markers\military\warning_CA.paa",
            [1,0,0,0.9],
            ASLToAGL _pos,
            0.9,
            0.9,
            0,
            "CASUALTY",
            2,
            0.035,
            "RobotoCondensedBold"
        ];
    } forEach ((allVariables missionNamespace) select { _x find "FEF_CASPING_" == 0 });
}];

// remove EH after 20 sec
[_eh] spawn {
    params ["_eh"];
    uiSleep 20;
    removeMissionEventHandler ["Draw3D", _eh];
};
