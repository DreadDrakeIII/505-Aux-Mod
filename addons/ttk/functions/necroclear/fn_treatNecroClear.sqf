/*
 * OLI_fnc_treatNecroClear
 * Success callback (medic's machine). Marks the dose active with a
 * public end-time, then starts the drain on the patient's machine.
 *
 * 0: Medic <OBJECT>, 1: Patient <OBJECT>, 2: Body part <STRING>
 */
params ["_medic", "_patient", "_bodyPart"];

if (_patient getVariable ["OLI_necroClearActive", false]) exitWith {};

private _duration = missionNamespace getVariable ["OLI_NecroClear_duration", 10];

_patient setVariable ["OLI_necroClearActive", true, true];
_patient setVariable ["OLI_necroClearEndTime", CBA_missionTime + _duration, true];

[_patient, "activity", "%1 injected NecroClear", [[_medic, false, true] call ace_common_fnc_getName]] call ace_medical_treatment_fnc_addToLog;

["OLI_ttk_necroClearLocal", [_patient], _patient] call CBA_fnc_targetEvent;
