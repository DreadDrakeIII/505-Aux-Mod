// OLI_SUPPLY - CLIENT. Attach the console actions and start the countdown
// loop. One-shot: whichever trigger in fn_postInit fires first wins.
//
// This is deferred until CBA's server-forced settings have landed, because the
// action radius and the list of enabled options are both baked into addAction
// and cannot be changed afterwards.

if (!hasInterface) exitWith {};
if (missionNamespace getVariable ["OLI_Supply_Wired", false]) exitWith {};
OLI_Supply_Wired = true;

// New consoles (Zeus, scripted spawns). applyRetroactively also sweeps the
// ones that already exist.
["OLI_Supply_Console", "InitPost", {
    params ["_console"];
    [_console] call OLI_Supply_fnc_addActions;
}, true, [], true] call CBA_fnc_addClassEventHandler;

// Belt and braces: catch anything already placed, without depending on XEH
// firing for this class.
{[_x] call OLI_Supply_fnc_addActions} forEach (allMissionObjects "OLI_Supply_Console");

// An admin turning an option on or off - or moving the action radius - has to
// tear the actions down and build them again, because both are fixed at
// addAction time. Everything else (cooldown lengths, crate classes) is read
// when it is used, so those need no rebuild.
["CBA_SettingChanged", {
    params ["_setting"];

    if !(_setting in OLI_Supply_RebuildSettings) exitWith {};

    // copy the list: fn_removeActions edits OLI_Supply_LocalConsoles as it goes
    {
        if (!isNull _x) then {
            [_x] call OLI_Supply_fnc_removeActions;
            [_x] call OLI_Supply_fnc_addActions;
        };
    } forEach (+OLI_Supply_LocalConsoles);
}] call CBA_fnc_addEventHandler;

[OLI_Supply_fnc_titleLoop, 0.25, []] call CBA_fnc_addPerFrameHandler;
