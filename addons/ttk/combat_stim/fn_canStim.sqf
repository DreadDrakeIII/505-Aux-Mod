/*
 * fn_canStim.sqf
 * [505th] Combat Stim - Treatment Condition
 *
 * Parameters:
 *   0: _medic    <OBJECT>
 *   1: _patient  <OBJECT>
 *   2: _bodyPart <STRING>
 *
 * Returns: BOOL
 */

params ["_medic", "_patient", "_bodyPart"];

// Must be alive
if (!alive _patient) exitWith {false};

// Already stimmed
if (_patient getVariable ["OLI_stimActive", false]) exitWith {false};

// Self-use check
if (_medic == _patient && {!OLI_stim_allowSelfUse}) exitWith {false};

// Medic requirement
if (OLI_stim_medicRequired == 1 && {!([_medic] call ace_medical_treatment_fnc_isMedic)}) exitWith {false};

// Conscious patient check
if (!(_patient getVariable ["ACE_isUnconscious", false]) && {!OLI_stim_allowConscious}) exitWith {false};

true
