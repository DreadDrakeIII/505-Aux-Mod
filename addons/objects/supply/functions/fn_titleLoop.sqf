OLI_Supply_SweepTick = (missionNamespace getVariable ["OLI_Supply_SweepTick", 0]) + 1;
if (OLI_Supply_SweepTick >= 20) then {
    OLI_Supply_SweepTick = 0;
    {
        if (isNil {_x getVariable "OLI_Supply_ActionIDs"}) then {
            [_x] call OLI_Supply_fnc_addActions;
        };
    } forEach (allMissionObjects "OLI_Supply_Console");
};

if (!isNil "OLI_Supply_LocalConsoles" && {OLI_Supply_LocalConsoles isNotEqualTo []}) then {
    if ({isNull _x} count OLI_Supply_LocalConsoles > 0) then {
        OLI_Supply_LocalConsoles = OLI_Supply_LocalConsoles select {!isNull _x};
    };
};

// Live cooldown countdown while the menu is open.
if (missionNamespace getVariable ["OLI_Supply_UI_Open", false]) then {
    private _console = missionNamespace getVariable ["OLI_Supply_UI_Console", objNull];
    if (isNull _console) then {
        [] call OLI_Supply_fnc_closeMenu;
    } else {
        [false] call OLI_Supply_fnc_renderMenu;
    };
};
