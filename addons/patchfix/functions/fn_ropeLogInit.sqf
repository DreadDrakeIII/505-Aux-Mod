ASL_RopeLog_show = {
    params ["_msg"];
    systemChat _msg;
};

if (!hasInterface) exitWith {};

ASL_RopeLog_installWrappers = {
    if (!isNil "ASL_RopeLog_WRAPPED") exitWith {};

    if (isNil "ASL_Deploy_Ropes") exitWith {false};
    if (isNil "ASL_Extend_Ropes") exitWith {false};
    if (isNil "ASL_Shorten_Ropes") exitWith {false};
    if (isNil "ASL_Retract_Ropes") exitWith {false};

    ASL_RopeLog_WRAPPED = true;

    ASL_RopeLog_orig_Deploy = ASL_Deploy_Ropes;
    ASL_RopeLog_orig_Extend = ASL_Extend_Ropes;
    ASL_RopeLog_orig_Shorten = ASL_Shorten_Ropes;
    ASL_RopeLog_orig_Retract = ASL_Retract_Ropes;

    ASL_RopeLog_vehName = {
        params ["_vehicle"];
        if (isNull _vehicle) exitWith {"<unknown vehicle>"};

        private _name = getText (configOf _vehicle >> "displayName");
        if (_name isEqualTo "") then {
            _name = typeOf _vehicle;
        };
        _name
    };

    ASL_RopeLog_broadcast = {
        params ["_action", "_vehicle", "_player"];
        if (isNil "_player") exitWith {};
        if (_player isNotEqualTo player) exitWith {};

        private _who = name _player;
        if (_who isEqualTo "") then {
            _who = "Someone";
        };

        private _vehicleName = [_vehicle] call ASL_RopeLog_vehName;
        private _message = format ["%1 %2 (%3)", _who, _action, _vehicleName];

        [_message] remoteExec ["ASL_RopeLog_show", 0];
        diag_log _message;
    };

    ASL_Deploy_Ropes = {
        params ["_vehicle", "_player"];
        ["DEPLOYED cargo ropes", _vehicle, _player] call ASL_RopeLog_broadcast;
        _this call ASL_RopeLog_orig_Deploy;
    };

    ASL_Extend_Ropes = {
        params ["_vehicle", "_player"];
        ["EXTENDED cargo ropes", _vehicle, _player] call ASL_RopeLog_broadcast;
        _this call ASL_RopeLog_orig_Extend;
    };

    ASL_Shorten_Ropes = {
        params ["_vehicle", "_player"];
        ["SHORTENED cargo ropes", _vehicle, _player] call ASL_RopeLog_broadcast;
        _this call ASL_RopeLog_orig_Shorten;
    };

    ASL_Retract_Ropes = {
        params ["_vehicle", "_player"];
        ["RETRACTED cargo ropes", _vehicle, _player] call ASL_RopeLog_broadcast;
        _this call ASL_RopeLog_orig_Retract;
    };

    diag_log "ASL_RopeLog: rope action wrappers installed";
    true
};

[] spawn {
    private _tries = 0;
    while {isNil "ASL_RopeLog_WRAPPED" && _tries < 600} do {
        call ASL_RopeLog_installWrappers;
        _tries = _tries + 1;
        sleep 0.5;
    };
};

player addEventHandler ["Respawn", {
    [] spawn {
        sleep 1;
        call ASL_RopeLog_installWrappers;
    };
}];
