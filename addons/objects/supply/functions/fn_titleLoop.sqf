// OLI_SUPPLY - client PFH: repaint console action titles while an option is
// recharging, so the player sees a live m:ss counter instead of a silent
// "nothing happened".
//
// Each option counts down on its own: taking Platoon Ammo greys out Platoon
// Ammo only, on every player's screen, and leaves the rest of the list live.
//
// Cheap by design: it only calls setUserActionText on an action when the
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
private _stale = false;

{
    private _console = _x;

    if (isNull _console) then {
        _stale = true;
    } else {
        // [[action key, action id], ...] - enabled options only, so the map is
        // what has to be walked, not the full action table.
        private _map = _console getVariable ["OLI_Supply_ActionMap", []];
        private _shown = _console getVariable ["OLI_Supply_ShownSecs", []];

        {
            _x params ["_key", "_id"];

            private _remaining = 0;
            if (_show) then {
                _remaining = ((_console getVariable [[_key] call OLI_Supply_fnc_cooldownVar, 0]) - _now) max 0;
            };

            private _secs = ceil _remaining;
            if (_secs != (_shown param [_forEachIndex, -1])) then {
                _shown set [_forEachIndex, _secs];

                private _title  = [_key, _secs > 0, _remaining] call OLI_Supply_fnc_actionTitle;
                private _window = [_key, _secs > 0, _remaining, 1.6] call OLI_Supply_fnc_actionTitle;
                _console setUserActionText [_id, _title, _window];
            };
        } forEach _map;
    };
} forEach OLI_Supply_LocalConsoles;

// drop deleted consoles from the watch list. Consoles with no actions are kept:
// every option can be switched off in the addon options and switched back on
// mid-mission, and fn_wireConsoles rebuilds from this list when that happens.
if (_stale) then {
    OLI_Supply_LocalConsoles = OLI_Supply_LocalConsoles select {!isNull _x};
};
