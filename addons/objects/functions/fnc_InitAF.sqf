/*
    505th Expeditionary Force - Pilot Init Function
    Called by CBA Extended Event Handlers when Pilot locker spawns

    Params:
        0: OBJECT - The locker object
*/

params ["_locker"];

// Simple spawn to wait for object initialization
_locker spawn {
    params ["_locker"];

    // Wait for object to be ready
    sleep 0.1;

    // // Debug message
    // systemChat "[505th] Pilot Locker initialized!";

    // Register Pilot WBK Kits
    [_locker] execVM '\BLU\OLI\addons\objects\functions\fnc_registerAFKits.sqf';
};
