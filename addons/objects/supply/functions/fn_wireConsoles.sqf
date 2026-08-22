// OLI_SUPPLY - CLIENT. Attach the console actions and start the countdown
// loop. One-shot: whichever trigger in fn_postInit fires first wins.
//
// This is deferred until CBA's server-forced settings have landed, because
// the action radius is baked into addAction and cannot be changed afterwards.

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

[OLI_Supply_fnc_titleLoop, 0.25, []] call CBA_fnc_addPerFrameHandler;
