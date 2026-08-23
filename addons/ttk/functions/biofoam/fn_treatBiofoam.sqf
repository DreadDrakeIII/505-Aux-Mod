/*
 * OLI_fnc_treatBiofoam
 * Success callback (runs on the medic's machine).
 * Consumes one canister use on the holder's machine, then hands wound
 * treatment to the patient's machine.
 *
 * 0: Medic <OBJECT>, 1: Patient <OBJECT>, 2: Body part <STRING>
 */
params ["_medic", "_patient", "_bodyPart"];

// Whoever actually carries the canister pays for the use (ACE hasItem
// accepts medic or patient inventory).
private _holder = [_patient, _medic] select ("OLI_BiofoamCanister" in magazines _medic);
["OLI_ttk_consumeCanister", [_holder], _holder] call CBA_fnc_targetEvent;

["OLI_ttk_biofoamLocal", [_medic, _patient, _bodyPart], _patient] call CBA_fnc_targetEvent;
