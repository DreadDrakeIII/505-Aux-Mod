// OLI_KCS - preInit: CBA settings, data tables, uniform pool
// Runs on every machine before objects init.

// ---------------------------------------------------------------------------
// CBA Addon Options (shared 505th category, "Casualty Spawner" subcategory,
// all global/server-forced). Values are read live via missionNamespace, so
// admins can retune mid-mission.
// ---------------------------------------------------------------------------
private _cat = ["505th Expeditionary Force Aux Mod", "Casualty Spawner"];

[
    "OLI_KCS_AllowDeath", "CHECKBOX",
    ["Allow death", "Patients can die (after the spawn grace period). Off = patients can crash but never die."],
    _cat, true, 1
] call CBA_fnc_addSetting;

[
    "OLI_KCS_DeathGrace", "SLIDER",
    ["Death grace period (s)", "Seconds after spawning during which a patient cannot die."],
    _cat, [0, 120, 25, 0], 1
] call CBA_fnc_addSetting;

[
    "OLI_KCS_MinUnconTime", "SLIDER",
    ["Minimum unconscious time (s)", "Minimum time a fresh patient stays unconscious."],
    _cat, [0, 120, 20, 0], 1
] call CBA_fnc_addSetting;

[
    "OLI_KCS_MinSpacing", "SLIDER",
    ["Casualty spacing (m)", "Minimum distance between spawned casualties."],
    _cat, [0, 5, 0.5, 1], 1
] call CBA_fnc_addSetting;

[
    "OLI_KCS_MinSpawnExtent", "SLIDER",
    ["Minimum area half-size (m)", "Spawn area half-size used when the training spot (or fallback area) is smaller."],
    _cat, [1, 15, 2, 0], 1
] call CBA_fnc_addSetting;

[
    "OLI_KCS_PairRange", "SLIDER",
    ["Computer-to-spot pairing range (m)", "A computer uses the nearest KCS Training Spot within this range. None found = area in front of the computer."],
    _cat, [5, 100, 30, 0], 1
] call CBA_fnc_addSetting;

[
    "OLI_KCS_SpawnAreaMode", "LIST",
    ["Spawning radius", "How multiple casualties spread around the training spot: within its bounding-box footprint, or within a custom radius."],
    _cat, [[0, 1], ["Training Spot Bounding Box", "Custom"], 0], 1
] call CBA_fnc_addSetting;

[
    "OLI_KCS_CustomSpawnRadius", "SLIDER",
    ["Custom spawning radius (m)", "Radius around the training spot used when 'Spawning radius' is set to Custom."],
    _cat, [0.1, 25, 6, 1], 1
] call CBA_fnc_addSetting;

[
    "OLI_KCS_LegacyScan", "CHECKBOX",
    ["Legacy variable-name lanes", "Also attach the menu to objects named KCS_Computer1..99 paired with KCS_TrainingSpot1..99 (old composition support)."],
    _cat, true, 1
] call CBA_fnc_addSetting;

// ---------------------------------------------------------------------------
// Data tables
// ---------------------------------------------------------------------------
OLI_KCS_UnitClass = "I_Survivor_F";   // joins a civilian group, so side stays civ
OLI_KCS_BodyParts = ["head", "body", "leftarm", "rightarm", "leftleg", "rightleg"];

// random civilian look - filtered so missing DLC entries drop out
OLI_KCS_UniformPool = [
    "U_C_Poloshirt_blue", "U_C_Poloshirt_burgundy", "U_C_Poloshirt_stripped",
    "U_C_Poloshirt_tricolour", "U_C_Poloshirt_salmon", "U_C_Poloshirt_redwhite",
    "U_C_Poor_1", "U_C_WorkerCoveralls", "U_C_Journalist", "U_C_Scientist",
    "U_C_Man_casual_1_F", "U_C_Man_casual_2_F", "U_C_Man_casual_3_F",
    "U_C_Man_casual_4_F", "U_C_Man_casual_5_F", "U_C_Man_casual_6_F",
    "U_C_man_sport_1_F", "U_C_man_sport_2_F", "U_C_man_sport_3_F"
] select {isClass (configFile >> "CfgWeapons" >> _x)};

// severity id -> [minWounds, +random, woundDamage, fractureChance,
//                 [smallW, medW, largeW] size weights, KAT complications?]
OLI_KCS_SeverityTable = createHashMapFromArray [
    [1, [1, 2, 0.35, 0.20, [0.75, 0.25, 0.00], false]],   // Routine
    [2, [4, 4, 0.50, 0.30, [0.45, 0.45, 0.10], true ]],   // Priority
    [3, [8, 6, 0.65, 0.40, [0.30, 0.45, 0.25], true ]]    // Expectant
];

// mechanism id -> [label, ACE wound classnames, body part weights
//                  [head, body, leftarm, rightarm, leftleg, rightleg]]
OLI_KCS_MechanismTable = createHashMapFromArray [
    [1, ["Gunshot",   ["VelocityWound", "PunctureWound"],          [1, 2, 2, 2, 2, 2]]],
    [2, ["Shrapnel",  ["VelocityWound", "Cut", "Laceration"],      [1, 2, 2, 2, 2, 2]]],
    [3, ["Explosion", ["Avulsion", "CrushWound", "VelocityWound"], [1, 2, 2, 2, 2, 2]]],
    [4, ["Collision", ["CrushWound", "Contusion"],                 [1, 6, 1, 1, 1, 1]]],
    [5, ["Falling",   ["CrushWound", "Contusion", "Laceration"],   [0.5, 1, 0.5, 0.5, 4, 4]]],
    [6, ["Backblast", ["Avulsion", "CrushWound", "Abrasion"],      [1, 3, 2, 2, 1, 1]]]
];

// mechanisms offered per severity (Routine / Priority / Expectant)
OLI_KCS_MechanismsBySeverity = [[1, 2, 4, 5, 6], [1, 2, 3, 4], [1, 2, 3, 4]];

// KAT presence (checked once)
OLI_KCS_KatLoaded = isClass (configFile >> "CfgPatches" >> "kat_breathing")
                 && isClass (configFile >> "CfgPatches" >> "kat_airway");

// scenario presets: [id, menu label, server code run on the fresh patient]
OLI_KCS_Presets = [
    ["hemorrhage", "Massive Hemorrhage", {
        params ["_p"];
        [_p, "leftleg",  ["Avulsion", 2, 2, 0.7]] call ace_medical_fnc_addWound;
        [_p, "rightarm", ["VelocityWound", 1, 1, 0.4]] call ace_medical_fnc_addWound;
    }],
    ["gsw_chest", "GSW Chest", {
        params ["_p"];
        [_p, "body", ["PunctureWound", 2, 1, 0.5]] call ace_medical_fnc_addWound;
        [_p, "pneumothorax", 1] call OLI_KCS_fnc_applyKat;
    }],
    ["tension", "Tension Pneumothorax", {
        params ["_p"];
        [_p, "body", ["PunctureWound", 1, 0, 0.35]] call ace_medical_fnc_addWound;
        [_p, "tension"] call OLI_KCS_fnc_applyKat;
    }],
    ["hemothorax", "Hemopneumothorax", {
        params ["_p"];
        [_p, "body", ["VelocityWound", 1, 1, 0.5]] call ace_medical_fnc_addWound;
        [_p, "hemothorax"] call OLI_KCS_fnc_applyKat;
    }],
    ["openchest", "Open Chest Wound", {
        params ["_p"];
        [_p, "body", ["PunctureWound", 1, 1, 0.4]] call ace_medical_fnc_addWound;
        [_p, "openchest"] call OLI_KCS_fnc_applyKat;
    }],
    ["obstruction", "Airway Obstruction", {
        params ["_p"];
        [_p, "head", ["Contusion", 1, 1, 0.3]] call ace_medical_fnc_addWound;
        [_p, "obstruction"] call OLI_KCS_fnc_applyKat;
    }],
    ["occlusion", "Airway Occlusion", {
        params ["_p"];
        [_p, "head", ["Cut", 2, 0, 0.3]] call ace_medical_fnc_addWound;
        [_p, "occlusion"] call OLI_KCS_fnc_applyKat;
    }],
    ["fractures", "Fractured Legs", {
        params ["_p"];
        [_p, "leftleg",  ["Contusion", 1, 1, 0.4]] call ace_medical_fnc_addWound;
        [_p, "rightleg", ["Contusion", 1, 1, 0.4]] call ace_medical_fnc_addWound;
        [_p, "leftleg"]  call OLI_KCS_fnc_addFracture;
        [_p, "rightleg"] call OLI_KCS_fnc_addFracture;
    }],
    ["polytrauma", "Mixed", {
        params ["_p"];
        [_p, "leftleg",  ["Avulsion", 1, 2, 0.7]] call ace_medical_fnc_addWound;
        [_p, "body",     ["PunctureWound", 1, 1, 0.5]] call ace_medical_fnc_addWound;
        [_p, "rightarm", ["Laceration", 2, 1, 0.4]] call ace_medical_fnc_addWound;
        [_p, "rightarm"] call OLI_KCS_fnc_addFracture;
        [_p, "tension"] call OLI_KCS_fnc_applyKat;
        [_p, "occlusion"] call OLI_KCS_fnc_applyKat;
    }]
];

if (!OLI_KCS_KatLoaded) then {
    diag_log "[OLI_KCS] KAT not loaded - plain ACE casualties only, no scenario menu.";
};
