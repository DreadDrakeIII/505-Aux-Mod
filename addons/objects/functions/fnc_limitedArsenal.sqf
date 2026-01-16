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
    "OLI_Adamant_Uniform_CE",
    "OLI_Crawford_Uniform_CE",
    "OLI_Crawford_Uniform_Rolled_CE",
    "OLI_Oliver_Uniform_CE",
    "OLI_Doc_Uniform_CE",
    // ========== VESTS ==========
    "OLI_CE_Vest_FR_Davy",
    "OLI_CE_Vest_Adamant_Pouches",
    "OLI_CE_Vest_Crawford",
    "OLI_CE_Vest_Hoffman",
    "OLI_CE_Vest_Oliver",
    "OLI_CE_Vest_Kain",
    "OLI_CE_Vest_Doc",
    // ========== HELMETS ==========
    "OLI_Tuna_Pilot_Helmet",
    "OLI_Malarkey_Pilot_Helmet",
    // Backpacks

    // ========== GOGGLES/FACEWEAR ==========
    "OLI_Davy_Mask_Goggle"
];

// Setup ACE Arsenal with whitelist
[_locker, _whitelist, false] call ace_arsenal_fnc_initBox;
