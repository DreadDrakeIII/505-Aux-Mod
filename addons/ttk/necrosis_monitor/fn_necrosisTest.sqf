/*
 * OLI_fnc_necrosisTest
 * Success callback (medic's machine). One-shot per-limb necrosis readout,
 * reported as the (fictional) Necrotide-B serum titer. Reads the broadcast
 * per-limb values, so it works from any machine.
 *
 * NTB = internal necrosis (0..100) * 0.074  ->  0.00 .. 7.40 umol/L
 *
 * Reference ranges (splits at internal 20 / 40 / 60 / 90):
 *   < 1.48        Nominal
 *   1.48 - 2.96   Early necrosis
 *   2.96 - 4.44   Moderate necrosis (marked motor impairment)
 *   4.44 - 6.66   Advanced necrosis
 *   > 6.66        CRITICAL necrosis
 *
 * 0: Medic <OBJECT>, 1: Patient <OBJECT>, 2: Body part <STRING>
 */
params ["_medic", "_patient", "_bodyPart"];

private _varName = switch (toLower _bodyPart) do {
    case "leftarm":  {"OLI_necrosis_leftArm"};
    case "rightarm": {"OLI_necrosis_rightArm"};
    case "leftleg":  {"OLI_necrosis_leftLeg"};
    case "rightleg": {"OLI_necrosis_rightLeg"};
    default {""};
};
if (_varName == "") exitWith {};

private _label = switch (toLower _bodyPart) do {
    case "leftarm":  {"Left Arm"};
    case "rightarm": {"Right Arm"};
    case "leftleg":  {"Left Leg"};
    default {"Right Leg"};
};

private _val = _patient getVariable [_varName, 0];
private _ntb = _val * 0.074;

private _stage = switch (true) do {
    case (_val > 90): {"CRITICAL necrosis"};
    case (_val > 60): {"Advanced necrosis"};
    case (_val > 40): {"Moderate necrosis"};
    case (_val > 20): {"Early necrosis"};
    default {"Nominal"};
};

private _msg = format ["%1 — NTB: %2 umol/L<br/>%3", _label, _ntb toFixed 2, _stage];

[_msg, 2] call ace_common_fnc_displayTextStructured;
[_patient, "quick_view", "NTB titer, %1: %2 umol/L (%3)", [_label, _ntb toFixed 2, _stage]] call ace_medical_treatment_fnc_addToLog;
