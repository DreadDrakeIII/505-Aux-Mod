/*
 * OLI_fnc_flatlineLocal
 * Runs on the PATIENT's machine. The statemachine condition patches (in
 * config.cpp) do the heavy lifting: while OLI_flatlineActive is set, the
 * unit cannot transition into Unconscious, CardiacArrest or FatalInjury,
 * and the WakeUp transition ignores the stable-vitals check.
 *
 * This function revives the patient through ACE's own sanctioned paths:
 *   - Cardiac arrest -> fire ace_medical_CPRSucceeded (same event KAT's
 *     AED fires) -> statemachine exits arrest, heart restarts at 40 bpm
 *   - Unconscious   -> ace_medical_fnc_setUnconscious false -> fires the
 *     WakeUp transition, which our patched condition lets through
 * ...then maintains the effect (pain suppression, watchdog re-wake)
 * until the public end-time. Resumable after locality transfer.
 *
 * 0: Patient <OBJECT>
 */
params ["_patient"];

if (!local _patient || {!alive _patient}) exitWith {};
if (_patient getVariable ["OLI_flatlinePFH", -1] != -1) exitWith {};   // already running here

// Expired before we even started (resume edge case)
if (CBA_missionTime >= (_patient getVariable ["OLI_flatlineEndTime", 0])) exitWith {
    [_patient, true] call OLI_fnc_flatlineStop;
};

// ── Revival sequence ──────────────────────────────────────────────────────────
// One-time adrenaline kick so the heart is not left at arrest-exit minimum
private _fnc_revive = {
    params ["_patient"];
    if (_patient getVariable ["ace_medical_inCardiacArrest", false]) then {
        ["ace_medical_CPRSucceeded", _patient] call CBA_fnc_localEvent;
    };
    if ((_patient getVariable ["ace_medical_heartRate", 80]) < 60) then {
        _patient setVariable ["ace_medical_heartRate", 70, true];
    };
    if (_patient getVariable ["ACE_isUnconscious", false]) then {
        [_patient, false] call ace_medical_fnc_setUnconscious;
    };
};
[_patient] call _fnc_revive;

// ── Maintenance PFH ───────────────────────────────────────────────────────────
private _pfh = [{
    params ["_args", "_idPFH"];
    _args params ["_patient", "_fnc_revive"];

    // Locality moved away: stop here, flags stay for the new owner machine
    if (!local _patient) exitWith {
        _patient setVariable ["OLI_flatlinePFH", -1];
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    // Killed through a path that bypasses ACE medical (scripted setDamage,
    // Zeus kill, etc.) — nothing to maintain
    if (!alive _patient) exitWith {
        _patient setVariable ["OLI_flatlinePFH", -1];
        _patient setVariable ["OLI_flatlineActive", false, true];
        if (_patient isEqualTo ACE_player) then {hintSilent ""};
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (CBA_missionTime >= (_patient getVariable ["OLI_flatlineEndTime", 0])
        || {!(_patient getVariable ["OLI_flatlineActive", false])}) exitWith {
        [_patient, true] call OLI_fnc_flatlineStop;
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    // Watchdog: statemachine transitions are blocked, but catch anything
    // that slipped through a direct/manual path and re-revive
    if ((_patient getVariable ["ACE_isUnconscious", false])
        || {_patient getVariable ["ace_medical_inCardiacArrest", false]}) then {
        [_patient] call _fnc_revive;
    };

    // Adrenaline analgesia: full pain suppression while dosed
    // (patient-local; the vitals loop runs on this machine)
    _patient setVariable ["ace_medical_painSuppress", 1];

    // ── Debug hint on the patient's screen ────────────────────────────
    if ((_patient isEqualTo ACE_player)
        && {missionNamespace getVariable ["OLI_stim_debugHint", true]}) then {

        private _remaining = ceil ((_patient getVariable ["OLI_flatlineEndTime", 0]) - CBA_missionTime);
        private _blood = _patient getVariable ["ace_medical_bloodVolume", 6];
        private _bleed = _patient getVariable ["ace_medical_woundBleeding", 0];
        private _hr    = round (_patient getVariable ["ace_medical_heartRate", 80]);
        (_patient getVariable ["ace_medical_bloodPressure", [80, 120]]) params ["_bpL", "_bpH"];
        private _spo2  = round (_patient getVariable ["ace_medical_spo2", 97]);
        private _pain  = _patient getVariable ["ace_medical_pain", 0];
        private _inCA  = _patient getVariable ["ace_medical_inCardiacArrest", false];
        private _stable = _patient call ace_medical_status_fnc_hasStableVitals;

        hintSilent format [
            "FLATLINE: %1s\n─────────────\nBlood: %2 L (%3%4)\nBleed rate: %5\nHR: %6 | BP: %7/%8\nSpO2: %9%4\nPain: %10\n%11\n─────────────\nON EXPIRY: %12",
            _remaining,
            _blood toFixed 2,
            round (_blood / 6 * 100),
            "%",
            _bleed toFixed 3,
            _hr,
            round _bpH,
            round _bpL,
            _spo2,
            _pain toFixed 2,
            ["", "!! CARDIAC ARREST !!"] select _inCA,
            ["COLLAPSES (vitals unstable)", "STAYS UP (vitals stable)"] select _stable
        ];
    };

}, 1, [_patient, _fnc_revive]] call CBA_fnc_addPerFrameHandler;

_patient setVariable ["OLI_flatlinePFH", _pfh];
