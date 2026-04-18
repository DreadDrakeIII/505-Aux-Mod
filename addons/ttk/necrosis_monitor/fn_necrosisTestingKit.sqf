/*
 * fn_necrosisTestingKit.sqf
 * [505th] Necrosis Testing Kit - Treatment Callback
 *
 * One-shot necrosis readout scoped to the selected limb.
 * Reads OLI per-limb tracking variables (not KAT's combined values),
 * so left and right limbs are reported independently and accurately.
 *
 * Parameters:
 *   0: _medic    <OBJECT>
 *   1: _patient  <OBJECT>
 *   2: _bodyPart <STRING>
 */

params ["_medic", "_patient", "_bodyPart"];

private _fmt = {
    params ["_val"];
    str (round (_val * 100) / 100)
};

private _msg = switch (_bodyPart) do {
    case "leftarm": {
        private _val = _patient getVariable ["OLI_necrosis_leftArm", 0];
        format ["Left Arm: %1", [_val] call _fmt]
    };
    case "rightarm": {
        private _val = _patient getVariable ["OLI_necrosis_rightArm", 0];
        format ["Right Arm: %1", [_val] call _fmt]
    };
    case "leftleg": {
        private _val = _patient getVariable ["OLI_necrosis_leftLeg", 0];
        format ["Left Leg: %1", [_val] call _fmt]
    };
    case "rightleg": {
        private _val = _patient getVariable ["OLI_necrosis_rightLeg", 0];
        format ["Right Leg: %1", [_val] call _fmt]
    };
    default { "Unknown limb" };
};

[_msg, 1.5] call ace_common_fnc_displayTextStructured;
[_patient, "quick_view", _msg, ["[505th] Necrosis Test"]] call ace_medical_treatment_fnc_addToLog;
