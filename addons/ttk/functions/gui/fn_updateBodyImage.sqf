/*
 * OLI_fnc_updateBodyImage
 * Handler for the "ace_medical_gui_updateBodyImage" CBA event, which ACE
 * fires every time it refreshes a body-image control group (medical menu
 * and IGUI patient info alike). Registered one frame after postInit so it
 * runs after ACE's own update (and KAT's handlers).
 *
 *  1. Swaps in the UNSC Marine body art (client setting).
 *  2. Tints limbs / tourniquet markers by per-limb necrosis stage
 *     (KAT only, client setting). Thresholds match KAT: 20 / 60 / 90.
 *
 * 0: Body image controls group <CONTROL>, 1: Target <OBJECT>, 2: Selection <NUMBER>
 */
params ["_ctrlGroup", "_target", "_selectionN"];

if (isNull _ctrlGroup) exitWith {};

// ── 1. Marine body art ────────────────────────────────────────────────────────
if (missionNamespace getVariable ["OLI_bodyImages_enable", true]) then {
    private _base = "\BLU\OLI\addons\ttk\body_images\";

    {
        _x params ["_idc", "_file"];
        private _ctrl = _ctrlGroup controlsGroupCtrl _idc;
        if (!isNull _ctrl) then {
            _ctrl ctrlSetText (_base + _file);
        };
    } forEach [
        [6005, "marine_head.paa"],
        [6010, "marine_torso.paa"],
        [6015, "marine_arm_left.paa"],
        [6020, "marine_arm_right.paa"],
        [6025, "marine_leg_left.paa"],
        [6030, "marine_leg_right.paa"],
        [6035, "marine_arm_left_t.paa"],
        [6040, "marine_arm_right_t.paa"],
        [6045, "marine_leg_left_t.paa"],
        [6050, "marine_leg_right_t.paa"],
        [6055, "marine_arm_left_b.paa"],
        [6060, "marine_arm_right_b.paa"],
        [6065, "marine_leg_left_b.paa"],
        [6070, "marine_leg_right_b.paa"],
        [6080, "marine_head_s.paa"],
        [6085, "marine_torso_s.paa"],
        [6090, "marine_arm_left_s.paa"],
        [6095, "marine_arm_right_s.paa"],
        [6100, "marine_leg_left_s.paa"],
        [6105, "marine_leg_right_s.paa"]
    ];

    // Background is the group's first control (idc -1 in ACE's layout)
    private _allCtrls = allControls _ctrlGroup;
    if (_allCtrls isNotEqualTo []) then {
        (_allCtrls select 0) ctrlSetText (_base + "marine_background.paa");
    };
};

// ── 2. Necrosis tint (KAT only) ───────────────────────────────────────────────
// Five stages, split at 20 / 40 / 60 / 90 internal units:
//   20/60/90 match KAT's leg effect cutoffs; 40 marks severe arm sway.
// The limb tint ALWAYS applies at stage 1+, including under a tourniquet
// (it runs after ACE's own coloring, so it wins the frame). The tourniquet
// band marker is recolored in step with the same stages.
if (!OLI_hasKAT) exitWith {};
if (!(missionNamespace getVariable ["OLI_necrosis_showOverlay", true])) exitWith {};
if (isNull _target) exitWith {};

private _openWounds = _target getVariable ["ace_medical_openWounds", createHashMap];

// [necrosis var, body part key, limb picture IDC, tourniquet marker IDC]
{
    _x params ["_varName", "_partName", "_limbIDC", "_bandIDC"];

    private _val = _target getVariable [_varName, 0];
    private _stage = switch (true) do {
        case (_val > 90): {4};
        case (_val > 60): {3};
        case (_val > 40): {2};
        case (_val > 20): {1};
        default {0};
    };

    // Tourniquet band marker: ACE blue when clean, escalating toward red.
    // Always set: we own this color once we ever change it.
    private _ctrlBand = _ctrlGroup controlsGroupCtrl _bandIDC;
    if (!isNull _ctrlBand) then {
        _ctrlBand ctrlSetTextColor ([
            [0, 0, 0.8, 1],
            [0.6, 0.75, 0.2, 1],
            [0.85, 0.75, 0.15, 1],
            [0.9, 0.45, 0.1, 1],
            [0.55, 0.08, 0.08, 1]
        ] select _stage);
    };

    // Tint priority: bleeding (ACE red) > necrosis > trauma (ACE blue).
    // Mirror ACE's own display check — it shows the red bleeding tint
    // when the summed wound bleeding on the part is > 0. In that case we
    // stand down and let the red through; otherwise our tint replaces
    // the damage color. Stage 0 leaves ACE's coloring untouched entirely
    // (ACE re-sets it every update).
    private _partBleeding = 0;
    {
        _x params ["", "_amountOf", "_bleedRate"];
        _partBleeding = _partBleeding + (_amountOf * _bleedRate);
    } forEach (_openWounds getOrDefault [_partName, []]);

    if (_stage > 0 && {_partBleeding == 0}) then {
        private _ctrlLimb = _ctrlGroup controlsGroupCtrl _limbIDC;
        if (!isNull _ctrlLimb) then {
            _ctrlLimb ctrlSetTextColor ([
                [1, 1, 1, 1],
                [0.75, 0.78, 0.62, 1],
                [0.62, 0.68, 0.45, 1],
                [0.45, 0.52, 0.30, 1],
                [0.28, 0.34, 0.18, 1]
            ] select _stage);
        };
    };
} forEach [
    ["OLI_necrosis_leftArm",  "leftarm",  6015, 6055],
    ["OLI_necrosis_rightArm", "rightarm", 6020, 6060],
    ["OLI_necrosis_leftLeg",  "leftleg",  6025, 6065],
    ["OLI_necrosis_rightLeg", "rightleg", 6030, 6070]
];
