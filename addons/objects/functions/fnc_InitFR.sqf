/*
    505th Expeditionary Force - FR Init Function
    Called by CBA Extended Event Handlers when FR locker spawns

    Params:
        0: OBJECT - The locker object
*/

params ["_locker"];

_locker spawn {
    params ["_locker"];

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

    // Register FR WBK Kits
    [_locker] execVM '\BLU\OLI\addons\objects\functions\fnc_registerFRKits.sqf';
};