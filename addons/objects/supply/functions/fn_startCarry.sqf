params [["_unit", objNull], ["_netId", ""]];

if (isNull _unit || {_unit isNotEqualTo ACE_player} || {_netId isEqualTo ""}) exitWith {};

[{
    params ["_args", "_pfhHandle"];
    _args params ["_unit", "_netId", "_deadline"];

    private _crate = objectFromNetId _netId;

    if (isNull _crate) exitWith {
        if (CBA_missionTime > _deadline) then {
            _pfhHandle call CBA_fnc_removePerFrameHandler;
        };
    };

    _pfhHandle call CBA_fnc_removePerFrameHandler;

    if (!alive _unit) exitWith {};

    if (_unit getVariable ["ace_dragging_isCarrying", false]
        || {_unit getVariable ["ace_dragging_isDragging", false]}) exitWith {
        ["OLI_Supply_carryStarted", [_netId]] call CBA_fnc_serverEvent;   // thaw it where it stands
        ["Crate dropped at your feet - your hands are already full."] call ace_common_fnc_displayTextStructured;
    };

    private _ignoreWeight = missionNamespace getVariable ["OLI_Supply_IgnoreWeight", true];
    [_crate, true, nil, nil, _ignoreWeight] call ace_dragging_fnc_setCarryable;

    [_unit, _crate] call ace_dragging_fnc_startCarry;

    [{
        params ["_args", "_thawPFH"];
        _args params ["_unit", "_netId", "_crate", "_deadline"];

        private _carrying = (_unit getVariable ["ace_dragging_carriedObject", objNull]) isEqualTo _crate;
        if (!_carrying && {CBA_missionTime < _deadline} && {!isNull _crate}) exitWith {};

        _thawPFH call CBA_fnc_removePerFrameHandler;
        ["OLI_Supply_carryStarted", [_netId]] call CBA_fnc_serverEvent;
    }, 0, [_unit, _netId, _crate, CBA_missionTime + 4]] call CBA_fnc_addPerFrameHandler;
}, 0, [_unit, _netId, CBA_missionTime + 5]] call CBA_fnc_addPerFrameHandler;
