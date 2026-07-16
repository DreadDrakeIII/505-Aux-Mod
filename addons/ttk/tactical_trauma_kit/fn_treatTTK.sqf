/*
 * OLI_fnc_treatTTK
 * Success callback (medic's machine). Item consumption is handled by ACE
 * via consumeItem = "OLI_TTK_consumeItem". Treatment itself runs on the
 * patient's machine.
 *
 * 0: Medic <OBJECT>, 1: Patient <OBJECT>, 2: Body part <STRING>
 */
params ["_medic", "_patient", "_bodyPart"];

["OLI_ttk_stitchLocal", [_medic, _patient, _bodyPart], _patient] call CBA_fnc_targetEvent;
