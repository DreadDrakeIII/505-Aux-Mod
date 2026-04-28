/*
    505th Expeditionary Force - Limited Arsenal Setup
    Universal whitelist for all locker types

    Params:
        0: OBJECT - The locker object
*/

params ["_locker"];

// Remove any existing arsenal first
[_locker] call ace_arsenal_fnc_removeBox;

// ============================================================================
// MASTER WHITELIST - Add all custom gear here
// ============================================================================
private _whitelist = [
    // ========== UNIFORMS ==========
    "OLI_Uniform_CE_Adamant",
    "OLI_Uniform_CE_Crawford",
    "OLI_Uniform_CE_Crawford_Rolled",
    "OLI_Uniform_CE_Oliver",
    "OLI_Uniform_CE_Doc",
    "OLI_Uniform_CE_Kain",
    // ========== VESTS ==========
    "OLI_CE_Vest_FR_Davy",
    "OLI_CE_Vest_Adamant_Pouches",
    "OLI_CE_Vest_Crawford",
    "OLI_CE_Vest_Hoffman",
    "OLI_CE_Vest_Oliver",
    "OLI_CE_Vest_Kain",
    "OLI_CE_Vest_Doc",
    "OLI_CE_Vest_Saint",
    "OLI_CE_Vest_Milan",
    // ========== HELMETS ==========
    "OLI_Tuna_Pilot_Helmet",
    "OLI_Malarkey_Pilot_Helmet",
    "OLI_CE_HELMET_Adamant",
    "OLI_CE_HELMET_Crawford",
    // Backpacks

    // ========== GOGGLES/FACEWEAR ==========
    "OLI_Davy_Mask"
];

// Setup ACE Arsenal with whitelist
[_locker, _whitelist, false] call ace_arsenal_fnc_initBox;
