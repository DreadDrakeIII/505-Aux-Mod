/*
 * OLI_fnc_treatEndurex
 * Success callback (medic's machine). Publishes the active flag and the
 * absolute end-time, then starts the effect on the patient's machine.
 * Because the end-time is public, ANY machine that later owns the patient
 * can resume or expire the effect correctly (JIP / disconnect safe).
 *
 * 0: Medic <OBJECT>, 1: Patient <OBJECT>, 2: Body part <STRING>
 */
params ["_medic", "_patient", "_bodyPart"];

if (_patient getVariable ["OLI_endurexActive", false]) exitWith {};

private _duration = missionNamespace getVariable ["OLI_Endurex_duration", 240];

_patient setVariable ["OLI_endurexActive", true, true];
_patient setVariable ["OLI_endurexEndTime", CBA_missionTime + _duration, true];

[_patient, "activity", "%1 administered an Endurex Booster", [[_medic, false, true] call ace_common_fnc_getName]] call ace_medical_treatment_fnc_addToLog;

["OLI_ttk_endurexLocal", [_patient], _patient] call CBA_fnc_targetEvent;
