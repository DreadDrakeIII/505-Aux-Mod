/*
 * fn_stimLocal.sqf
 * [505th] Combat Stim - Local Patient Logic
 *
 * Runs on the patient's machine (remoteExecCall'd from stimTreat).
 * Maintains vitals clamping, catches knockouts, handles timer/debuff/death.
 * Survives medic disconnect because the PFH lives here on the patient.
 *
 * Every tick:
 *   - Blood volume held at 5.5 (healthy baseline)
 *   - Pain fully suppressed
 *   - Heart rate stabilized
 *   - Fractures repaired
 *   - Necrosis suppressed
 *   - Unconscious state reversed
 *   - Stamina maintained (if setting enabled)
 *   - Animation speed boosted (configurable)
 *   - Weapon sway eliminated (via ACE sway factor)
 *
 * Parameters:
 *   0: _patient  <OBJECT> - The patient being treated
 */

params ["_patient"];

if (!local _patient) exitWith {};

private _stimDuration = missionNamespace getVariable ["OLI_stim_duration", 120];
private _startTime = CBA_missionTime;

// ─── Save defaults for restoration ──────────────────────────────────────────
private _defaultAnimSpeed = getAnimSpeedCoef _patient;
private _hasACEFatigue    = missionNamespace getVariable ["ace_advanced_fatigue_enabled", false];
private _staminaEnabled   = missionNamespace getVariable ["OLI_stim_disableStamina", true];
private _animSpeedMult    = missionNamespace getVariable ["OLI_stim_animSpeed", 1.15];

// ─── Apply immediate effects ─────────────────────────────────────────────────
// Zero bleeding immediately so no drain happens before per-frame PFH starts
_patient setVariable ["ace_medical_woundBleeding", 0];

// Animation speed
_patient setAnimSpeedCoef (_defaultAnimSpeed * _animSpeedMult);

// Weapon sway: eliminate via ACE sway factor (returns near-zero)
["multiplier", {0.07}, "OLI_stim"] call ace_common_fnc_addSwayFactor;

// Stamina
if (_staminaEnabled) then {
    if (_hasACEFatigue) then {
        ace_advanced_fatigue_anReserve = ace_advanced_fatigue_anReserve + 3000;
        ["OLI_stim", 0] call ace_advanced_fatigue_fnc_addDutyFactor;
        private _exclusions = missionNamespace getVariable ["ace_advanced_fatigue_setAnimExclusions", []];
        _exclusions pushBackUnique "OLI_StimOverride";
    } else {
        _patient enableStamina false;
    };
};

// ─── Main PFH ────────────────────────────────────────────────────────────────
[{
    params ["_args", "_idPFH"];
    private _patient          = _args select 0;
    private _startTime        = _args select 1;
    private _stimDuration     = _args select 2;
    private _defaultAnimSpeed = _args select 3;
    private _hasACEFatigue    = _args select 4;
    private _staminaEnabled   = _args select 5;

    // ── Cleanup: restores anim speed, sway, stamina, PP ────────────────
    private _fnCleanup = {
        params ["_patient", "_defaultAnimSpeed", "_hasACEFatigue", "_staminaEnabled"];

        _patient setAnimSpeedCoef _defaultAnimSpeed;
        ["multiplier", "OLI_stim"] call ace_common_fnc_removeSwayFactor;

        if (_staminaEnabled) then {
            if (_hasACEFatigue) then {
                ["OLI_stim"] call ace_advanced_fatigue_fnc_removeDutyFactor;
                private _exclusions = missionNamespace getVariable ["ace_advanced_fatigue_setAnimExclusions", []];
                private _idx = _exclusions find "OLI_StimOverride";
                if (_idx != -1) then { _exclusions deleteAt _idx; };
            } else {
                _patient enableStamina true;
            };
        };
    };

    // Stop if dead
    if (!alive _patient) exitWith {
        _patient setVariable ["OLI_stimActive", false, true];
        [_patient, _defaultAnimSpeed, _hasACEFatigue, _staminaEnabled] call _fnCleanup;
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    // Timer expired
    if (CBA_missionTime - _startTime >= _stimDuration) exitWith {
        _patient setVariable ["OLI_stimActive", false, true];
        [_patient, _defaultAnimSpeed, _hasACEFatigue, _staminaEnabled] call _fnCleanup;
        [_idPFH] call CBA_fnc_removePerFrameHandler;

        if (!alive _patient) exitWith {};

        // ── Debuff on expiry ─────────────────────────────────────────────
        private _debuff = missionNamespace getVariable ["OLI_stim_debuff", 2];
        switch (_debuff) do {
            case 1: {
                private _openWounds = _patient getVariable ["ace_medical_openWounds", createHashMap];
                private _damage = _patient getVariable ["ace_medical_bodyPartDamage", [0, 0, 0, 0, 0, 0]];
                private _bodyParts = ["head", "body", "leftarm", "rightarm", "leftleg", "rightleg"];

                {
                    private _woundsOnPart = _openWounds getOrDefault [_x, [], true];
                    private _bruiseIndex = _woundsOnPart findIf {(_x select 0) == 22};
                    if (_bruiseIndex == -1) then {
                        _woundsOnPart pushBack [22, 5, 0, 0.5];
                    } else {
                        private _wound = _woundsOnPart select _bruiseIndex;
                        _wound set [1, (_wound select 1) + 5];
                    };
                    _damage set [_forEachIndex, (_damage select _forEachIndex) + 0.5];
                } forEach _bodyParts;

                _patient setVariable ["ace_medical_openWounds", _openWounds, true];
                _patient setVariable ["ace_medical_bodyPartDamage", _damage, true];
                _patient setVariable ["ace_medical_pain", 0.55, true];

                [_patient] call ace_medical_status_fnc_updateWoundBloodLoss;
            };
            case 2: {
                _patient setDamage [1, true];
            };
        };

        // ── Auto-knockout on expiry ──────────────────────────────────────
        private _autoKO = missionNamespace getVariable ["OLI_stim_autoKnockout", false];
        if (alive _patient && _autoKO) then {
            [_patient, true] call ace_medical_fnc_setUnconscious;
            if !(_patient getVariable ["ACE_isUnconscious", false]) then {
                [_patient, true] call ace_medical_status_fnc_setUnconsciousState;
            };
        };

        if (alive _patient) then {
            [_patient] call ace_medical_engine_fnc_updateDamageEffects;
        };
    };

    // ── Hold blood volume at max (safety net — bleeding already zeroed) ──
    _patient setVariable ["ace_medical_bloodVolume", 6.0, true];
    _patient setVariable ["ace_medical_hemorrhage", 0, true];

    // ── Keep pain fully suppressed and heart rate stable ──────────────────
    _patient setVariable ["ace_medical_painSuppress", 1, true];
    private _hr = _patient getVariable ["ace_medical_heartRate", 80];
    if (_hr < 40 || _hr > 180) then {
        _patient setVariable ["ace_medical_heartRate", 80, true];
    };

    // ── Continuously repair fractures ────────────────────────────────────
    private _fractures = _patient getVariable ["ace_medical_fractures", [0,0,0,0,0,0]];
    private _fractureChanged = false;
    {
        if (_x == 1) then {
            _fractures set [_forEachIndex, 0];
            _fractureChanged = true;
        };
    } forEach _fractures;
    if (_fractureChanged) then {
        _patient setVariable ["ace_medical_fractures", _fractures, true];
        [_patient] call ace_medical_engine_fnc_updateDamageEffects;
    };

    // ── Keep tourniquet necrosis suppressed ───────────────────────────────
    _patient setVariable ["kat_misc_Tourniquet_ArmNecrosis", 0, true];
    _patient setVariable ["kat_misc_Tourniquet_LegNecrosis", 0, true];
    _patient setVariable ["OLI_necrosis_leftArm",  0, true];
    _patient setVariable ["OLI_necrosis_rightArm", 0, true];
    _patient setVariable ["OLI_necrosis_leftLeg",  0, true];
    _patient setVariable ["OLI_necrosis_rightLeg", 0, true];

    // ── Maintain stamina ─────────────────────────────────────────────────
    if (_staminaEnabled) then {
        if (_hasACEFatigue) then {
            if (ace_advanced_fatigue_anReserve < 2000) then {
                ace_advanced_fatigue_anReserve = ace_advanced_fatigue_anReserve + 3000;
            };
        } else {
            _patient setStamina (getStamina _patient + 100);
        };
    };

    // ── If knocked out during stim, wake them back up ────────────────────
    if (_patient getVariable ["ACE_isUnconscious", false]) then {
        [_patient, false] call ace_medical_status_fnc_setUnconsciousState;
    };

}, 0.5, [_patient, _startTime, _stimDuration, _defaultAnimSpeed, _hasACEFatigue, _staminaEnabled]] call CBA_fnc_addPerFrameHandler;

// ─── Per-frame blood protection ──────────────────────────────────────────────
// Zeros woundBleeding every frame so ACE's getBloodLoss early-exits with 0,
// meaning updateBloodVolume never drains. One local setVariable, no broadcast.
// Self-terminates when stim ends, then updateWoundBloodLoss restores real rate.
[{
    params ["_args", "_idPFH"];
    private _patient = _args select 0;

    if (!alive _patient || {!(_patient getVariable ["OLI_stimActive", false])}) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        // Restore real bleeding rate from actual wounds
        if (alive _patient) then {
            [_patient] call ace_medical_status_fnc_updateWoundBloodLoss;
        };
    };

    _patient setVariable ["ace_medical_woundBleeding", 0];

}, 0, [_patient]] call CBA_fnc_addPerFrameHandler;
