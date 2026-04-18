/*
 * fn_canEndurex.sqf
 * [505th] Vita-Boost Autoinjector - Treatment Condition
 *
 * Parameters:
 *   0: _medic    <OBJECT>
 *   1: _patient  <OBJECT>
 *   2: _bodyPart <STRING>
 *
 * Returns: BOOL
 */

params ["_medic", "_patient", "_bodyPart"];

if (!alive _patient) exitWith {false};

// Already active — no stacking / no refresh
if (_patient getVariable ["OLI_EndurexActive", false]) exitWith {false};

// Patient must be conscious to benefit (not for reviving)
if (_patient getVariable ["ACE_isUnconscious", false]) exitWith {false};

// Self-use check
if (_medic == _patient && {!OLI_Endurex_allowSelfUse}) exitWith {false};

true
