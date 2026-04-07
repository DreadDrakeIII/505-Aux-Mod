params ["_unit", ["_includeRemoteControlled", true]];

isPlayer _unit or {
    _includeRemoteControlled && {
        !isNull (_unit getVariable ["bis_fnc_moduleRemoteControl_owner", objNull])
    }
};
