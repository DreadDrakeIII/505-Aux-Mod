/*
 * XEH_preInit.sqf
 * [505th] Tactical Trauma Kit - CBA Settings
 *
 * Capability flags + CBA settings, organized by module.
 * Gating settings used by ACE config resolution (medicRequired /
 * allowSelfTreatment / consumeItem) must be NUMERIC (LIST), never CHECKBOX.
 */

// ─── Capability flags (constant per game session) ────────────────────────────
OLI_hasKAT       = isClass (configFile >> "CfgPatches" >> "kat_misc");
OLI_hasKATPharma = isClass (configFile >> "CfgPatches" >> "kat_pharma");

// ═════════════════════════════════════════════════════════════════════════════
// ─── Biofoam Canister ────────────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_biofoam_treatmentTime",
    "SLIDER",
    ["Application Time", "Time, in seconds, to apply biofoam."],
    ["[505th] Medical", "Biofoam Canister"],
    [0.1, 30, 3, 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_biofoam_painLevel",
    "SLIDER",
    ["Pain on Application", "Pain caused when biofoam is applied. 0 = none, 0.1-0.5 = pain, >0.5 = severe pain."],
    ["[505th] Medical", "Biofoam Canister"],
    [0, 1, 0.5, 2],
    true
] call CBA_fnc_addSetting;

[
    "OLI_biofoam_strength",
    "LIST",
    ["Biofoam Strength", "How effectively biofoam bandages wounds on a body part."],
    ["[505th] Medical", "Biofoam Canister"],
    [[0, 1, 2], ["Bandages everything on the part", "Acts as 2x Elastic Bandages", "Acts as 3x Elastic Bandages"], 0],
    true
] call CBA_fnc_addSetting;

[
    "OLI_biofoam_uses",
    "SLIDER",
    ["Uses Per Canister", "How many times a single canister can be used before it is depleted."],
    ["[505th] Medical", "Biofoam Canister"],
    [1, 10, 5, 0],
    true
] call CBA_fnc_addSetting;

[
    "OLI_biofoam_infinite",
    "CHECKBOX",
    ["Infinite Uses", "If enabled, biofoam canisters are never consumed."],
    ["[505th] Medical", "Biofoam Canister"],
    false,
    true
] call CBA_fnc_addSetting;

// ═════════════════════════════════════════════════════════════════════════════
// ─── Tactical Trauma Kit ─────────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_TTK_timeBehavior",
    "LIST",
    ["Treatment Time Behavior", "ACE Stitch Time: scales with the number of bandaged wounds on the part, using ACE's own per-wound stitch time setting (like the surgical kit). Custom Slider: flat time from the slider below."],
    ["[505th] Medical", "Tactical Trauma Kit"],
    [[0, 1], ["ACE Stitch Time (scales with wounds)", "Custom Slider"], 0],
    true
] call CBA_fnc_addSetting;

[
    "OLI_TTK_treatmentTime",
    "SLIDER",
    ["Custom Treatment Time", "Flat time, in seconds, required to treat wounds. Only used when Treatment Time Behavior is set to Custom Slider."],
    ["[505th] Medical", "Tactical Trauma Kit"],
    [0.1, 60, 3, 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_TTK_medicRequired",
    "LIST",
    ["Skill Required", "Training level required to use the Tactical Trauma Kit."],
    ["[505th] Medical", "Tactical Trauma Kit"],
    [[0, 1, 2], ["Everyone", "Medics", "Doctors"], 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_TTK_selfCare",
    "LIST",
    ["Self Care", "Allow treating yourself with the Tactical Trauma Kit."],
    ["[505th] Medical", "Tactical Trauma Kit"],
    [[0, 1], ["No", "Yes"], 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_TTK_consumeItem",
    "LIST",
    ["Consume on Use", "What is consumed after a successful treatment."],
    ["[505th] Medical", "Tactical Trauma Kit"],
    [[0, 1], ["Nothing", "Tactical Trauma Kit"], 0],
    true
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
    [0, 120, 6, 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_polyseal_painLevel",
    "SLIDER",
    ["Pain on Injection", "Pain caused by the injection. 0 = none, 0.1-0.5 = pain, >0.5 = severe pain."],
    ["[505th] Medical", "Bone Polyseal"],
    [0, 1, 0.2, 2],
    true
] call CBA_fnc_addSetting;

// ═════════════════════════════════════════════════════════════════════════════
// ─── Polymorph ───────────────────────────────────────────────────────────────
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
// ─── Epinephrex ──────────────────────────────────────────────────────────────
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
// ─── NecroClear ──────────────────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_NecroClear_treatmentTime",
    "SLIDER",
    ["Injection Time", "Time, in seconds, to inject NecroClear."],
    ["[505th] Medical", "NecroClear"],
    [0.1, 10, 2, 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_NecroClear_duration",
    "SLIDER",
    ["Effect Duration", "Time, in seconds, that NecroClear actively drains necrosis."],
    ["[505th] Medical", "NecroClear"],
    [1, 60, 10, 0],
    true
] call CBA_fnc_addSetting;

[
    "OLI_NecroClear_effectiveness",
    "SLIDER",
    ["Effectiveness", "Necrosis drained per second while active (KAT's natural drain is 0.32/s)."],
    ["[505th] Medical", "NecroClear"],
    [0.5, 15, 15, 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_NecroClear_medicRequired",
    "LIST",
    ["Skill Required", "Training level required to administer NecroClear."],
    ["[505th] Medical", "NecroClear"],
    [[0, 1, 2], ["Everyone", "Medics", "Doctors"], 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_NecroClear_selfUse",
    "LIST",
    ["Allow Self-injection", "Allow injecting NecroClear into yourself."],
    ["[505th] Medical", "NecroClear"],
    [[0, 1], ["No", "Yes"], 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_NecroClear_requireIV",
    "CHECKBOX",
    ["Require IV/IO Access", "NecroClear requires an established IV or IO line on the selected body part (KAT pharma)."],
    ["[505th] Medical", "NecroClear"],
    true,
    true
] call CBA_fnc_addSetting;

// ═════════════════════════════════════════════════════════════════════════════
// ─── Necrosis Testing Kit / Overlay ──────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_necrosisTestingKit_medicRequired",
    "LIST",
    ["Skill Required", "Training level required to use the Necrosis Testing Kit."],
    ["[505th] Medical", "Necrosis Testing Kit"],
    [[0, 1, 2], ["Everyone", "Medics", "Doctors"], 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_necrosis_showOverlay",
    "CHECKBOX",
    ["Necrosis Overlay", "Recolor limbs / tourniquet markers in the medical menu by necrosis severity. Client-side."],
    ["[505th] Medical", "Necrosis Testing Kit"],
    true,
    false
] call CBA_fnc_addSetting;

// ═════════════════════════════════════════════════════════════════════════════
// ─── Flatline Serum ──────────────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_stim_duration",
    "SLIDER",
    ["Duration", "How long, in seconds, the serum forces consciousness and blocks cardiac arrest/death."],
    ["[505th] Medical", "Flatline Serum"],
    [10, 600, 300, 0],
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_treatmentTime",
    "SLIDER",
    ["Injection Time", "Time, in seconds, to inject the serum."],
    ["[505th] Medical", "Flatline Serum"],
    [0.1, 10, 3, 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_medicRequired",
    "LIST",
    ["Skill Required", "Training level required to administer the serum."],
    ["[505th] Medical", "Flatline Serum"],
    [[0, 1, 2], ["Everyone", "Medics", "Doctors"], 0],
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_selfUse",
    "LIST",
    ["Allow Self-injection", "Allow injecting the serum into yourself (while still conscious)."],
    ["[505th] Medical", "Flatline Serum"],
    [[0, 1], ["No", "Yes"], 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_allowConscious",
    "CHECKBOX",
    ["Allow on Conscious Patients", "Allow pre-emptive dosing of patients who are still conscious."],
    ["[505th] Medical", "Flatline Serum"],
    true,
    true
] call CBA_fnc_addSetting;

[
    "OLI_stim_debugHint",
    "CHECKBOX",
    ["Debug Hint (Patient)", "Shows a hint on the dosed player's screen: remaining time, blood volume, bleed rate, HR/BP, SpO2, pain, and whether they will stay up when the serum expires. Client-side."],
    ["[505th] Medical", "Flatline Serum"],
    true,
    false
] call CBA_fnc_addSetting;

[
    "OLI_stim_debuff",
    "LIST",
    ["Debuff on Expiry", "What the body suffers when the serum wears off. Vitals are always re-evaluated: a patient who was healed enough stays up, otherwise they collapse."],
    ["[505th] Medical", "Flatline Serum"],
    [[0, 1, 2], ["None", "Strained body (blunt trauma + pain)", "Death"], 2],
    true
] call CBA_fnc_addSetting;

// ═════════════════════════════════════════════════════════════════════════════
// ─── Endurex Booster ─────────────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_Endurex_duration",
    "SLIDER",
    ["Duration", "How long, in seconds, the Endurex Booster suppresses sway and exhaustion."],
    ["[505th] Medical", "Endurex Booster"],
    [10, 600, 240, 0],
    true
] call CBA_fnc_addSetting;

[
    "OLI_Endurex_treatmentTime",
    "SLIDER",
    ["Application Time", "Time, in seconds, to actuate the Endurex Booster."],
    ["[505th] Medical", "Endurex Booster"],
    [0.1, 10, 2, 1],
    true
] call CBA_fnc_addSetting;

[
    "OLI_Endurex_medicRequired",
    "LIST",
    ["Skill Required", "Training level required to administer the Endurex Booster."],
    ["[505th] Medical", "Endurex Booster"],
    [[0, 1, 2], ["Everyone", "Medics", "Doctors"], 0],
    true
] call CBA_fnc_addSetting;

[
    "OLI_Endurex_selfUse",
    "LIST",
    ["Allow Self-use", "Allow using the Endurex Booster on yourself."],
    ["[505th] Medical", "Endurex Booster"],
    [[0, 1], ["No", "Yes"], 1],
    true
] call CBA_fnc_addSetting;

// ═════════════════════════════════════════════════════════════════════════════
// ─── Body Images ─────────────────────────────────────────────────────────────
// ═════════════════════════════════════════════════════════════════════════════

[
    "OLI_bodyImages_enable",
    "CHECKBOX",
    ["UNSC Marine Body Images", "Replace the ACE medical menu body silhouette with the UNSC Marine art. Client-side."],
    ["[505th] Medical", "Body Images"],
    true,
    false
] call CBA_fnc_addSetting;
