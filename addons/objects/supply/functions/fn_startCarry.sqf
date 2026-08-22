// OLI_SUPPLY - runs on the requesting player's machine. Waits for the crate
// to replicate, then drops it straight into ACE's fireman carry so the player
// is already holding it when the action finishes.
//
// Arguments: 0: unit <OBJECT>, 1: crate netId <STRING>

params [["_unit", objNull], ["_netId", ""]];

if (isNull _unit || {_unit isNotEqualTo ACE_player} || {_netId isEqualTo ""}) exitWith {};

[{
    params ["_args", "_pfhHandle"];
    _args params ["_unit", "_netId", "_deadline"];

    private _crate = objectFromNetId _netId;

    // not replicated yet - keep waiting, but do not spin forever
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

    // The server already flagged it carryable globally. Doing it locally too
    // is harmless (ACE guards the per-class setup) and covers the case where
    // that global event arrived before the crate existed on this machine.
    private _ignoreWeight = missionNamespace getVariable ["OLI_Supply_IgnoreWeight", true];
    [_crate, true, nil, nil, _ignoreWeight] call ace_dragging_fnc_setCarryable;

    [_unit, _crate] call ace_dragging_fnc_startCarry;

    // The crate is frozen (see fn_spawnCrate). ACE's claim round-trips through
    // the server, so the carry starts a few frames after this call - thaw it
    // the moment it is actually attached, or on timeout so it never stays
    // frozen.
    [{
        params ["_args", "_thawPFH"];
        _args params ["_unit", "_netId", "_crate", "_deadline"];

        private _carrying = (_unit getVariable ["ace_dragging_carriedObject", objNull]) isEqualTo _crate;
        if (!_carrying && {CBA_missionTime < _deadline} && {!isNull _crate}) exitWith {};

        _thawPFH call CBA_fnc_removePerFrameHandler;
        ["OLI_Supply_carryStarted", [_netId]] call CBA_fnc_serverEvent;
    }, 0, [_unit, _netId, _crate, CBA_missionTime + 4]] call CBA_fnc_addPerFrameHandler;
}, 0, [_unit, _netId, CBA_missionTime + 5]] call CBA_fnc_addPerFrameHandler;
