/*
 * fn_NecroClearTreat.sqf
 * [505th] NecroClear Autoinjector - Treatment Callback
 *
 * Runs on the medic's machine (ACE callback). Sets the active flag, logs,
 * then remoteExecCall's the drain PFH to the patient's machine so it runs
 * where ACE medical engine ticks and survives medic disconnect.
 *
 * Parameters:
 *   0: _medic    <OBJECT>
 *   1: _patient  <OBJECT>
 *   2: _bodyPart <STRING> (unused)
 */

params ["_medic", "_patient", "_bodyPart"];

if (_patient getVariable ["OLI_NecroClearActive", false]) exitWith {};

_patient setVariable ["OLI_NecroClearActive", true, true];

[_patient, "activity", format ["NecroClear injected by %1", name _medic], [name _patient]] call ace_medical_treatment_fnc_addToLog;

// ─── Drain PFH — runs on the patient's machine ──────────────────────────────
// CBA settings are global, so the patient's machine reads them directly.
[_patient] remoteExecCall ["OLI_fnc_NecroClearLocal", _patient];
