// OLI_KCS - attach the Casualty Spawner menu to an arbitrary object
// (used by the legacy KCS_Computer<N> scan; also public for mission makers:
//    [someProp, someSpotObject] call OLI_KCS_fnc_addComputer;
// The spot argument is optional - without it the computer pairs with the
// nearest OLI_KCS_TrainingSpot, or uses the area in front of itself).
//
// Arguments: 0: computer <OBJECT>, 1: (optional) spawn spot <OBJECT>

params [["_computer", objNull], ["_spot", objNull]];

if (isNull _computer) exitWith {};

// explicit pairing must be visible on the server (spawn area is resolved
// server-side), hence public
if (!isNull _spot && {isNull (_computer getVariable ["OLI_KCS_Spot", objNull])}) then {
    _computer setVariable ["OLI_KCS_Spot", _spot, true];
};

if (!hasInterface) exitWith {};

// the placeable class already has the menu via config
if (_computer isKindOf "OLI_KCS_Computer") exitWith {};

if (_computer getVariable ["OLI_KCS_MenuDone", false]) exitWith {};
_computer setVariable ["OLI_KCS_MenuDone", true];

private _action = [
    "OLI_KCS_Root", "Casualty Spawner", "",
    {},
    {true},
    { params ["_target", "_player"]; [_target, _player] call OLI_KCS_fnc_menuChildren; },
    [], [0, 0, 0], 5
] call ace_interact_menu_fnc_createAction;

[_computer, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;
