/*
 * OLI_fnc_polysealLocal
 * Runs on the PATIENT's machine. Immediate injection pain.
 *
 * 0: Patient <OBJECT>
 */
params ["_patient"];

if (!local _patient || {!alive _patient}) exitWith {};

private _pain = missionNamespace getVariable ["OLI_polyseal_painLevel", 0.2];
if (_pain > 0) then {
    [_patient, _pain] call ace_medical_status_fnc_adjustPainLevel;
};
