/*
 * OLI_fnc_endurexLocal
 * Runs on the PATIENT's machine. Applies sway elimination and exhaustion
 * suppression until the public end-time. Resumable after locality
 * transfer (flag + end-time are public; this function self-guards).
 *
 * Sway factors are per-machine and only affect the local player, so they
 * are only touched when the patient IS the local player.
 *
 * 0: Patient <OBJECT>
 */
params ["_patient"];

if (!local _patient || {!alive _patient}) exitWith {};
if (_patient getVariable ["OLI_endurexPFH", -1] != -1) exitWith {};   // already running here

// Expired before we even started (e.g. resumed after a long transfer)
if (CBA_missionTime >= (_patient getVariable ["OLI_endurexEndTime", 0])) exitWith {
    [_patient, true] call OLI_fnc_endurexStop;
};

// ── Apply effects ─────────────────────────────────────────────────────────────
private _isPlayer = _patient isEqualTo ACE_player;
private _useAF = !isNil "ace_advanced_fatigue_enabled"
    && {missionNamespace getVariable ["ace_advanced_fatigue_enabled", false]}
    && {_isPlayer};

if (_isPlayer) then {
    ["multiplier", {0.01}, "OLI_ttk_endurex"] call ace_common_fnc_addSwayFactor;
};

if (_useAF) then {
    ["OLI_ttk_endurex", 0] call ace_advanced_fatigue_fnc_addDutyFactor;
    ace_advanced_fatigue_anReserve = ace_advanced_fatigue_anReserve + 3000;
} else {
    _patient enableStamina false;
};

// ── Maintenance PFH ───────────────────────────────────────────────────────────
private _pfh = [{
    params ["_args", "_idPFH"];
    _args params ["_patient", "_useAF", "_isPlayer"];

    // Locality moved away: clean local effects, KEEP the global flag so
    // the new owner machine resumes via the XEH Local handler.
    if (!local _patient) exitWith {
        [_patient, false, _useAF, _isPlayer] call OLI_fnc_endurexStop;
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _endTime = _patient getVariable ["OLI_endurexEndTime", 0];
    if (!alive _patient
        || {!(_patient getVariable ["OLI_endurexActive", false])}
        || {CBA_missionTime >= _endTime}) exitWith {
        [_patient, true, _useAF, _isPlayer] call OLI_fnc_endurexStop;
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    // Keep the tank topped up
    if (_useAF) then {
        if (ace_advanced_fatigue_anReserve < 2000) then {
            ace_advanced_fatigue_anReserve = ace_advanced_fatigue_anReserve + 3000;
        };
    } else {
        _patient setStamina (getStamina _patient + 100);
    };

}, 1, [_patient, _useAF, _isPlayer]] call CBA_fnc_addPerFrameHandler;

_patient setVariable ["OLI_endurexPFH", _pfh];
