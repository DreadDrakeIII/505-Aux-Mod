/*
    505th Expeditionary Force - CE Init Function
    Called by CBA Extended Event Handlers when CE locker spawns

    Params:
        0: OBJECT - The locker object
*/

params ["_locker"];

// Simple spawn to wait for object initialization
_locker spawn {
    params ["_locker"];

    // Wait for object to be ready
    sleep 0.1;

    _locker setVariable ["ace_dragging_canDrag", false, true];
    _locker setVariable ["ace_dragging_canCarry", false, true];
    _locker setVariable ["ace_cargo_noRename", true, true];

    clearWeaponCargoGlobal _locker;
    clearMagazineCargoGlobal _locker;
    clearItemCargoGlobal _locker;
    clearBackpackCargoGlobal _locker;

    // Setup Limited Arsenal - using universal file
    [_locker] execVM '\BLU\OLI\addons\objects\functions\fnc_limitedArsenal.sqf';

    sleep 0.2;

    // Register CE WBK Kits
    [_locker] execVM '\BLU\OLI\addons\objects\functions\fnc_registerCEKits.sqf';
};
