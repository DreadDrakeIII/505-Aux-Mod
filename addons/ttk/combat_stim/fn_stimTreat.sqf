/*
 * fn_stimTreat.sqf
 * [505th] Combat Stim - Treatment Callback
 *
 * Runs on medic's machine. Performs immediate one-time setup with broadcast,
 * then hands off ongoing maintenance to stimLocal on the patient's machine.
 *
 * Parameters:
 *   0: _medic    <OBJECT> - The medic performing treatment
 *   1: _patient  <OBJECT> - The patient being treated
 *   2: _bodyPart <STRING> - The body part (unused)
 */

params ["_medic", "_patient", "_bodyPart"];

// Prevent stacking
if (_patient getVariable ["OLI_stimActive", false]) exitWith {};

// Mark the patient as stimmed
_patient setVariable ["OLI_stimActive", true, true];

private _stimDuration = OLI_stim_duration;
private _startTime = CBA_missionTime;

// ─── Clamp vitals to safe values immediately ─────────────────────────────────
_patient setVariable ["ace_medical_woundBleeding", 0, true];
_patient setVariable ["ace_medical_bloodVolume", 6.0, true];
_patient setVariable ["ace_medical_hemorrhage", 0, true];
_patient setVariable ["ace_medical_painSuppress", 1, true];
_patient setVariable ["ace_medical_heartRate", 80, true];

// ─── If unconscious, properly wake them (vitals are now safe) ────────────────
if (_patient getVariable ["ACE_isUnconscious", false]) then {
    [_patient, false] call ace_medical_status_fnc_setUnconsciousState;
};

// ─── Clear tourniquet necrosis (KAT combined + OLI per-limb) ─────────────────
_patient setVariable ["kat_misc_Tourniquet_ArmNecrosis", 0, true];
_patient setVariable ["kat_misc_Tourniquet_LegNecrosis", 0, true];
_patient setVariable ["OLI_necrosis_leftArm",  0, true];
_patient setVariable ["OLI_necrosis_rightArm", 0, true];
_patient setVariable ["OLI_necrosis_leftLeg",  0, true];
_patient setVariable ["OLI_necrosis_rightLeg", 0, true];

// ─── Repair all fractured limbs ───────────────────────────────────────────────
private _fractures = _patient getVariable ["ace_medical_fractures", [0,0,0,0,0,0]];
{
    if (_x == 1) then { _fractures set [_forEachIndex, 0]; };
} forEach _fractures;
_patient setVariable ["ace_medical_fractures", _fractures, true];
["ace_medical_engine_updateDamageEffects", _patient, _patient] call CBA_fnc_targetEvent;

// ─── Hand off ongoing maintenance to patient's machine ───────────────────────
[_patient] remoteExecCall ["OLI_fnc_stimLocal", _patient];

// ─── Countdown hint on medic's screen ────────────────────────────────────────
[{
    params ["_args", "_idPFH"];
    _args params ["_patient", "_startTime", "_stimDuration"];

    if (!alive _patient || {!(_patient getVariable ["OLI_stimActive", false])}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        hint "";
    };

    private _remaining = ceil (_stimDuration - (CBA_missionTime - _startTime));
    private _patientName = [_patient, false, true] call ace_common_fnc_getName;

    if (OLI_stim_debugInfo) then {
        private _blood = _patient getVariable ["ace_medical_bloodVolume", 6.0];
        private _bleed = _patient getVariable ["ace_medical_woundBleeding", 0];
        private _hr    = _patient getVariable ["ace_medical_heartRate", 80];
        private _spo2  = _patient getVariable ["ace_medical_spo2", 97];
        private _pain  = _patient getVariable ["ace_medical_pain", 0];

        hint format [
            "STIM: %1 | %2s remaining\n─────────────────────\nBlood: %3 L | Bleed: %4\nHR: %5 | SpO2: %6\nPain: %7",
            _patientName,
            _remaining,
            (_blood toFixed 2),
            (_bleed toFixed 3),
            round _hr,
            round _spo2,
            (_pain toFixed 2)
        ];
    } else {
        hint format ["STIM GIVEN TO %1: %2s", _patientName, _remaining];
    };

}, 1, [_patient, _startTime, _stimDuration]] call CBA_fnc_addPerFrameHandler;
