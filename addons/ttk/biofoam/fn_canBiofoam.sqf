/*
 * OLI_fnc_canBiofoam
 * Condition: body part has at least one open (unbandaged) wound.
 * Medic/self/item checks are handled by ACE via the action config.
 *
 * 0: Patient <OBJECT>, 1: Body part <STRING>
 * Return: BOOL
 */
params ["_patient", "_bodyPart"];

private _openWounds = _patient getVariable ["ace_medical_openWounds", createHashMap];
private _woundsOnPart = _openWounds getOrDefault [toLower _bodyPart, []];

(_woundsOnPart findIf {(_x select 1) > 0}) != -1
