/*
 * fn_EndurexTreat.sqf
 * [505th] Vita-Boost Autoinjector - Treatment Callback
 *
 * Runs on medic's machine. Delegates to EndurexLocal on the patient's
 * machine so the PFH survives medic disconnect.
 *
 * Parameters:
 *   0: _medic    <OBJECT>
 *   1: _patient  <OBJECT>
 *   2: _bodyPart <STRING>
 */

params ["_medic", "_patient", "_bodyPart"];

if (_patient getVariable ["OLI_EndurexActive", false]) exitWith {};

_patient setVariable ["OLI_EndurexActive", true, true];
_patient setVariable ["OLI_EndurexStartTime", CBA_missionTime, true];

[_patient, "activity", format ["Vita-Boost injected by %1", name _medic], [name _patient]] call ace_medical_treatment_fnc_addToLog;

[_patient] remoteExecCall ["OLI_fnc_EndurexLocal", _patient];
