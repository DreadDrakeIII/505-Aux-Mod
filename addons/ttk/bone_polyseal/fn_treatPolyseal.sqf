/*
 * OLI_fnc_treatPolyseal
 * Success callback (medic's machine). Immediate injection pain on the
 * patient, then the splint effect after a delay. The delay is scheduled
 * on the SERVER via a CBA server event (never remoteExec, which
 * restricted missions like Liberation block) so it survives medic
 * disconnect; at fire time it routes to wherever the patient is local.
 *
 * 0: Medic <OBJECT>, 1: Patient <OBJECT>, 2: Body part <STRING>
 */
params ["_medic", "_patient", "_bodyPart"];

["OLI_ttk_polysealLocal", [_patient], _patient] call CBA_fnc_targetEvent;

["OLI_ttk_polysealSchedule", [_medic, _patient, _bodyPart]] call CBA_fnc_serverEvent;
