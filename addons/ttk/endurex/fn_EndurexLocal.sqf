/*
 * fn_EndurexLocal.sqf
 * [505th] Vita-Boost Autoinjector - Local Patient Logic
 *
 * Runs on the patient's machine (remoteExecCall'd from EndurexTreat).
 * Applies sway reduction and stamina suppression for the duration.
 *
 * Sway removal is guaranteed by a hard timer (waitAndExecute) independent
 * of the PFH, so it expires on time even if the PFH is disrupted.
 *
 * Parameters:
 *   0: _patient <OBJECT>
 */

params ["_patient"];

if (!local _patient) exitWith {};
if (!alive _patient) exitWith {};

private _duration  = missionNamespace getVariable ["OLI_Endurex_duration", 240];
private _startTime = _patient getVariable ["OLI_EndurexStartTime", CBA_missionTime];

private _hasACEFatigue = missionNamespace getVariable ["ace_advanced_fatigue_enabled", false];

// ─── Apply immediate effects ─────────────────────────────────────────────────
["multiplier", {0.01}, "OLI_Endurex"] call ace_common_fnc_addSwayFactor;

if (_hasACEFatigue) then {
    ace_advanced_fatigue_anReserve = ace_advanced_fatigue_anReserve + 3000;
    ["OLI_Endurex", 0] call ace_advanced_fatigue_fnc_addDutyFactor;
    private _exclusions = missionNamespace getVariable ["ace_advanced_fatigue_setAnimExclusions", []];
    _exclusions pushBackUnique "OLI_EndurexOverride";
} else {
    _patient enableStamina false;
};

// ─── Cleanup helper ──────────────────────────────────────────────────────────
private _fnCleanup = {
    params ["_patient", "_hasACEFatigue"];

    ["multiplier", "OLI_Endurex"] call ace_common_fnc_removeSwayFactor;

    if (_hasACEFatigue) then {
        ["OLI_Endurex"] call ace_advanced_fatigue_fnc_removeDutyFactor;
        private _exclusions = missionNamespace getVariable ["ace_advanced_fatigue_setAnimExclusions", []];
        private _idx = _exclusions find "OLI_EndurexOverride";
        if (_idx != -1) then { _exclusions deleteAt _idx; };
    } else {
        _patient enableStamina true;
    };
};

// ─── Hard-timed sway removal (guaranteed, independent of PFH) ────────────────
// Even if the PFH is disrupted by locality change, script error, or edge case,
// this fires at exactly the right time and cleans up sway + stamina.
private _remaining = _duration - (CBA_missionTime - _startTime);
[{
    params ["_patient", "_hasACEFatigue", "_fnCleanup"];
    _patient setVariable ["OLI_EndurexActive", false, true];
    [_patient, _hasACEFatigue] call _fnCleanup;
}, [_patient, _hasACEFatigue, _fnCleanup], _remaining max 0] call CBA_fnc_waitAndExecute;

// ─── Main PFH (0.5s tick for stamina maintenance + early exit on death) ──────
[{
    params ["_args", "_idPFH"];
    _args params ["_patient", "_startTime", "_duration", "_hasACEFatigue", "_fnCleanup"];

    // Dead or flag cleared — clean up early and exit
    if (!alive _patient || {!(_patient getVariable ["OLI_EndurexActive", false])}) exitWith {
        _patient setVariable ["OLI_EndurexActive", false, true];
        [_patient, _hasACEFatigue] call _fnCleanup;
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    // Timer expired — PFH exits, hard timer handles cleanup
    if (CBA_missionTime - _startTime >= _duration) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    // Maintain stamina
    if (_hasACEFatigue) then {
        if (ace_advanced_fatigue_anReserve < 2000) then {
            ace_advanced_fatigue_anReserve = ace_advanced_fatigue_anReserve + 3000;
        };
    } else {
        _patient setStamina (getStamina _patient + 100);
    };

}, 0.5, [_patient, _startTime, _duration, _hasACEFatigue, _fnCleanup]] call CBA_fnc_addPerFrameHandler;
