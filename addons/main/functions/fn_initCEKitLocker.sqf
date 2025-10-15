/*
    File: fn_initCEKitLocker.sqf
    Purpose: Adds CE Loadout behavior to WBK Kit Locker
*/

params ["_locker"];

// Make sure this runs only on the server or all machines if necessary
if (isNull _locker) exitWith {};

_locker addAction [
    "<t color='#00BFFF'>Access 505th CE Kit Loadouts</t>",
    {
        params ["_target", "_caller", "_actionId", "_arguments"];
        // Run your main loadout script
        _caller call compile preprocessFileLineNumbers "\scripts\initObject1.sqf";
    },
    nil,
    1.5, // priority
    true, // showWindow
    true, // hideOnUse
    "", // condition ("" means always available)
    "alive _target && isPlayer _this" // condition for players only
];
