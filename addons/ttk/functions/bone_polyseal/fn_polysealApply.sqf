/*
 * OLI_fnc_polysealApply
 * Runs on the PATIENT's machine after the heal delay. Applies the splint
 * through ACE's own splintLocal if the part is still fractured.
 *
 * 0: Medic <OBJECT>, 1: Patient <OBJECT>, 2: Body part <STRING>
 */
params ["_medic", "_patient", "_bodyPart"];

if (!local _patient || {!alive _patient}) exitWith {};

private _partIndex = ["head", "body", "leftarm", "rightarm", "leftleg", "rightleg"] find (toLower _bodyPart);
if (_partIndex == -1) exitWith {};

private _fractures = _patient getVariable ["ace_medical_fractures", [0, 0, 0, 0, 0, 0]];
if ((_fractures select _partIndex) != 1) exitWith {};   // no open fracture anymore

[_medic, _patient, _bodyPart] call ace_medical_treatment_fnc_splintLocal;

[_patient, "activity", "Bone Polyseal has taken effect", []] call ace_medical_treatment_fnc_addToLog;
