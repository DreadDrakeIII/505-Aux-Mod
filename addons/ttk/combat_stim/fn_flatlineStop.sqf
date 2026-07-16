/*
 * OLI_fnc_flatlineStop
 * Runs on the PATIENT's machine. Ends the effect: clears the flag,
 * applies the configured expiry debuff, then re-evaluates the patient
 * naturally — stable vitals stay up, unstable vitals collapse. ACE's
 * vitals loop (level-triggered, ~1s) backs this up for cardiac arrest /
 * bleedout conditions.
 *
 * 0: Patient <OBJECT>
 * 1: Clear global flag + apply debuff <BOOL> (false = locality handoff)
 */
params ["_patient", "_clearGlobal"];

_patient setVariable ["OLI_flatlinePFH", -1];

// Clear the debug hint
if (_patient isEqualTo ACE_player) then {hintSilent ""};

if (!_clearGlobal) exitWith {};

_patient setVariable ["OLI_flatlineActive", false, true];

if (!alive _patient) exitWith {};

// ── Expiry debuff ─────────────────────────────────────────────────────────────
switch (missionNamespace getVariable ["OLI_stim_debuff", 2]) do {
    case 1: {
        // Strained body: blunt trauma to torso and limbs + severe pain
        {
            [_patient, 0.35, _x, "punch", objNull] call ace_medical_fnc_addDamageToUnit;
        } forEach ["body", "leftarm", "rightarm", "leftleg", "rightleg"];
        [_patient, 0.7] call ace_medical_status_fnc_adjustPainLevel;
    };
    case 2: {
        [_patient, "Flatline Serum expiry"] call ace_medical_status_fnc_setDead;
    };
};

if (!alive _patient) exitWith {};

// ── Natural re-evaluation ─────────────────────────────────────────────────────
// Healed enough to stand on their own -> nothing happens, they stay up.
// Otherwise they go down, exactly as ACE would have dropped them.
if (!(_patient getVariable ["ACE_isUnconscious", false])
    && {!(_patient call ace_medical_status_fnc_hasStableVitals)}) then {
    [_patient, true] call ace_medical_fnc_setUnconscious;
};

[_patient, "activity", "Flatline Serum has worn off", []] call ace_medical_treatment_fnc_addToLog;
