// OLI_SUPPLY - client PFH: repaint console action titles while a console is
// recharging, so the player sees a live m:ss counter instead of a silent
// "nothing happened".
//
// Cheap by design: it only calls setUserActionText on a console when the
// displayed whole second actually changes.

// Every 5 s, pick up any console that somehow never got its actions (XEH not
// firing for the class, an object created while the client was loading, ...).
// Cheap at 0.2 Hz and it makes "no actions on the console" impossible.
OLI_Supply_SweepTick = (missionNamespace getVariable ["OLI_Supply_SweepTick", 0]) + 1;
if (OLI_Supply_SweepTick >= 20) then {
    OLI_Supply_SweepTick = 0;
    {
        if (isNil {_x getVariable "OLI_Supply_ActionIDs"}) then {
            [_x] call OLI_Supply_fnc_addActions;
        };
    } forEach (allMissionObjects "OLI_Supply_Console");
};

if (isNil "OLI_Supply_LocalConsoles" || {OLI_Supply_LocalConsoles isEqualTo []}) exitWith {};

private _show = missionNamespace getVariable ["OLI_Supply_ShowCountdown", true];
private _now = CBA_missionTime;
private _cdVar = [player] call OLI_Supply_fnc_cooldownVar;   // cooldown is per player
private _stale = false;

{
    private _console = _x;
    private _ids = if (isNull _console) then {[]} else {
        _console getVariable ["OLI_Supply_ActionIDs", []]
    };

    if (_ids isEqualTo []) then {
        _stale = true;
    } else {
        private _remaining = 0;
        if (_show) then {
            _remaining = ((_console getVariable [_cdVar, 0]) - _now) max 0;
        };

        private _secs = ceil _remaining;
        if (_secs != (_console getVariable ["OLI_Supply_ShownSecs", -1])) then {
            _console setVariable ["OLI_Supply_ShownSecs", _secs];
            {
                private _key    = _x select 0;
                private _title  = [_key, _secs > 0, _remaining] call OLI_Supply_fnc_actionTitle;
                private _window = [_key, _secs > 0, _remaining, 1.6] call OLI_Supply_fnc_actionTitle;
                _console setUserActionText [_ids select _forEachIndex, _title, _window];
            } forEach OLI_Supply_Actions;
        };
    };
} forEach OLI_Supply_LocalConsoles;

// drop deleted consoles from the watch list
if (_stale) then {
    OLI_Supply_LocalConsoles = OLI_Supply_LocalConsoles select {
        !isNull _x && {(_x getVariable ["OLI_Supply_ActionIDs", []]) isNotEqualTo []}
    };
};
