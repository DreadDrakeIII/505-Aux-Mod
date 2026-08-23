/*
 * OLI_fnc_treatFlatline
 * Success callback (medic's machine). Publishes the active flag (which
 * the statemachine condition patches read on every machine) and the
 * absolute end-time, then starts patient-side handling.
 *
 * 0: Medic <OBJECT>, 1: Patient <OBJECT>, 2: Body part <STRING>
 */
params ["_medic", "_patient", "_bodyPart"];

if (_patient getVariable ["OLI_flatlineActive", false]) exitWith {};

private _duration = missionNamespace getVariable ["OLI_stim_duration", 300];

_patient setVariable ["OLI_flatlineActive", true, true];
_patient setVariable ["OLI_flatlineEndTime", CBA_missionTime + _duration, true];

[_patient, "activity", "%1 injected Flatline Serum", [[_medic, false, true] call ace_common_fnc_getName]] call ace_medical_treatment_fnc_addToLog;

["OLI_ttk_flatlineLocal", [_patient], _patient] call CBA_fnc_targetEvent;
