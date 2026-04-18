/*
 * XEH_preInit.sqf
 * [505th] Tactical Trauma Kit - CBA Settings
 * All settings under [505th] Medical, organized by subcategory alphabetically.
 */

// ═════════════════════════════════════════════════════════════════════════════
// ─── Biofoam Canister ────────────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_biofoam_treatmentTime",
    "SLIDER",
    ["Application Time", "Time, in seconds, to apply biofoam."],
    ["[505th] Medical", "Biofoam Canister"],
    [0.1, 10, 3, 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_biofoam_painLevel",
    "SLIDER",
    ["Pain on Application", "Amount of pain caused when biofoam is applied. 0 = none, <0.1 = mild pain, 0.1-0.5 = pain, >0.5 = severe pain, 1 = reasonable maximum."],
    ["[505th] Medical", "Biofoam Canister"],
    [0, 1, 0.52, 2],
    true
] call CBA_fnc_addSetting;

[
    "OLI_biofoam_strength",
    "LIST",
    ["Biofoam Strength", "How effectively biofoam bandages wounds on a limb."],
    ["[505th] Medical", "Biofoam Canister"],
    [[0, 1, 2], ["Bandages everything on limb", "Acts as 2x Elastic Bandages", "Acts as 3x Elastic Bandages"], 0],
    true
] call CBA_fnc_addSetting;

// ═════════════════════════════════════════════════════════════════════════════
// ─── Auto-Tourniquet ───────────────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_tourni_applyTime",
    "SLIDER",
    ["Application Time", "Time, in seconds, to apply the tourniquet."],
    ["[505th] Medical", "Auto-Tourniquet"],
    [0.1, 10, 2, 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_tourni_removeTime",
    "SLIDER",
    ["Removal Time", "#Requires Restart. Time, in seconds, to remove the tourniquet."],
    ["[505th] Medical", "Auto-Tourniquet"],
    [0.1, 10, 2, 1],
    true,
    {kat_misc_treatmentTimeDetachTourniquet = OLI_tourni_removeTime;}
] call CBA_fnc_addSetting;

// ═════════════════════════════════════════════════════════════════════════════
// ─── Bone Polyseal ───────────────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_polyseal_treatmentTime",
    "SLIDER",
    ["Injection Time", "Time, in seconds, to inject the bone polyseal."],
    ["[505th] Medical", "Bone Polyseal"],
    [0.1, 10, 2, 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_polyseal_healDelay",
    "SLIDER",
    ["Heal Delay", "Time, in seconds, for the polymer to take effect after injection."],
    ["[505th] Medical", "Bone Polyseal"],
    [0.1, 60, 6, 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_polyseal_painLevel",
    "SLIDER",
    ["Pain on Injection", "Amount of pain caused by the injection. 0 = none, <0.1 = mild pain, 0.1-0.5 = pain, >0.5 = severe pain, 1 = reasonable maximum."],
    ["[505th] Medical", "Bone Polyseal"],
    [0, 1, 0.2, 2],
    true
] call CBA_fnc_addSetting;

// ═════════════════════════════════════════════════════════════════════════════
// ─── Epinephrex ──────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_epi_treatmentTime",
    "SLIDER",
    ["Injection Time", "Time, in seconds, to inject Epinephrex."],
    ["[505th] Medical", "Epinephrex"],
    [0.1, 10, 2, 1],
    true
] call CBA_fnc_addSetting;

// ═════════════════════════════════════════════════════════════════════════════
// ─── Polymorph ──────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_morph_treatmentTime",
    "SLIDER",
    ["Injection Time", "Time, in seconds, to inject Polymorph."],
    ["[505th] Medical", "Polymorph"],
    [0.1, 10, 2, 1],
    true
] call CBA_fnc_addSetting;

// ═════════════════════════════════════════════════════════════════════════════
// ─── Combat Stim ─────────────────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_stim_allowConscious",
    "CHECKBOX",
    ["Allow on Conscious Patients", "Enables combat stim usage on patients who are already conscious."],
    ["[505th] Medical", "Combat Stim"],
    true,
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_allowSelfUse",
    "CHECKBOX",
    ["Allow Self-injection", "Enables self-injection of combat stims."],
    ["[505th] Medical", "Combat Stim"],
    true,
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_autoKnockout",
    "CHECKBOX",
    ["KO on Expiry (Off may cause bugs)", "Forces all stimmed patients unconscious when the stim wears off, regardless of vitals. Turning this off may cause bugs involving invulnerability"],
    ["[505th] Medical", "Combat Stim"],
    true,
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_debuff",
    "LIST",
    ["Debuff on Expiry", "What happens to the patient when the combat stim wears off."],
    ["[505th] Medical", "Combat Stim"],
    [[0, 1, 2], ["No Debuff", "Strained Body (bruises + severe pain)", "Death"], 2],
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_duration",
    "SLIDER",
    ["Stim Duration", "Time, in seconds, the combat stim keeps the patient conscious."],
    ["[505th] Medical", "Combat Stim"],
    [1, 600, 300, 0],
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_medicRequired",
    "LIST",
    ["Skill Level Required", "Training level required to administer a combat stim."],
    ["[505th] Medical", "Combat Stim"],
    [[0, 1], ["Everyone", "Medics"], 0],
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_treatmentTime",
    "SLIDER",
    ["Injection Time", "Time, in seconds, to inject the combat stim."],
    ["[505th] Medical", "Combat Stim"],
    [0.1, 10, 3, 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_disableStamina",
    "CHECKBOX",
    ["Disable Stamina Drain", "Disables stamina drain on the patient for the duration of the combat stim."],
    ["[505th] Medical", "Combat Stim"],
    true,
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_animSpeed",
    "SLIDER",
    ["Animation Speed Multiplier", "How much faster the patient moves while stimmed. 1 = normal, 2 = double speed."],
    ["[505th] Medical", "Combat Stim"],
    [1, 2, 1.15, 2],
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_debugInfo",
    "CHECKBOX",
    ["Show Debug Info", "Shows blood volume, bleed rate, and heart rate in the medic's stim countdown hint."],
    ["[505th] Medical", "Combat Stim"],
    false,
    true
] call CBA_fnc_addSetting;

// ═════════════════════════════════════════════════════════════════════════════
// ─── Tactical Trauma Kit ─────────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_TTK_consumeItem",
    "LIST",
    ["Consume Tactical Trauma Kit", "What should be consumed after use."],
    ["[505th] Medical", "Tactical Trauma Kit"],
    [[0, 1, 2], ["Nothing", "Tactical Trauma Kit", "Suture (WIP - Not Functional)"], 0],
    true
] call CBA_fnc_addSetting;

[
    "OLI_TTK_medicRequired",
    "LIST",
    ["Skill Required", "Training level required to use the tactical trauma kit."],
    ["[505th] Medical", "Tactical Trauma Kit"],
    [[0, 1], ["Everyone", "Medics"], 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_TTK_selfCare",
    "LIST",
    ["Self Care", "Enables the use of tactical trauma kits to treat oneself."],
    ["[505th] Medical", "Tactical Trauma Kit"],
    [[0, 1], ["No", "Yes"], 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_TTK_treatmentTime",
    "SLIDER",
    ["Treatment Time", "Time, in seconds, required to treat wounds."],
    ["[505th] Medical", "Tactical Trauma Kit"],
    [0.1, 60, 3, 1],
    true
] call CBA_fnc_addSetting;


// ═════════════════════════════════════════════════════════════════════════════
// ─── NecroClear ─────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_NecroClear_allowSelfUse",
    "CHECKBOX",
    ["Allow Self-injection", "Enables self-use of NecroClear."],
    ["[505th] Medical", "NecroClear"],
    true,
    true
] call CBA_fnc_addSetting;

[
    "OLI_NecroClear_duration",
    "SLIDER",
    ["Effect Duration", "Time, in seconds, that NecroClear actively drains tourniquet necrosis."],
    ["[505th] Medical", "NecroClear"],
    [1, 60, 10, 0],
    true
] call CBA_fnc_addSetting;

[
    "OLI_NecroClear_effectiveness",
    "SLIDER",
    ["Effectiveness", "Necrosis drain rate, multiplying from KAT's negative multipler. Default KAT drain is 0.32/sec"],
    ["[505th] Medical", "NecroClear"],
    [0, 45, 45, 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_NecroClear_medicRequired",
    "LIST",
    ["Skill Required", "Training level required to administer NecroClear."],
    ["[505th] Medical", "NecroClear"],
    [[0, 1], ["Everyone", "Medics"], 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_NecroClear_treatmentTime",
    "SLIDER",
    ["Injection Time", "Time, in seconds, to inject NecroClear."],
    ["[505th] Medical", "NecroClear"],
    [0.1, 10, 2, 1],
    true
] call CBA_fnc_addSetting;




// ═════════════════════════════════════════════════════════════════════════════
// ─── Necrosis Testing Kit ────────────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_necrosisTestingKit_medicRequired",
    "LIST",
    ["Skill Required", "Training level required to use the Necrosis Testing Kit."],
    ["[505th] Medical", "Necrosis Testing Kit"],
    [[0, 1], ["Everyone", "Medics"], 1],
    true
] call CBA_fnc_addSetting;

// ═════════════════════════════════════════════════════════════════════════════
// ─── Endurex Booster Inhaler ─────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_Endurex_duration",
    "SLIDER",
    ["Duration", "How long the Endurex Booster suppresses sway and exhaustion. In seconds."],
    ["[505th] Medical", "Endurex Booster"],
    [0, 480, 240, 0],
    true
] call CBA_fnc_addSetting;

[
    "OLI_Endurex_treatmentTime",
    "SLIDER",
    ["Injection Time", "Time, in seconds, to actuate Endurex Booster."],
    ["[505th] Medical", "Endurex Booster"],
    [0.1, 10, 2, 1],
    true
] call CBA_fnc_addSetting;
