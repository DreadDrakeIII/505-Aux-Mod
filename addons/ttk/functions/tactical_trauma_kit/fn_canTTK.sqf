/*
 * OLI_fnc_canTTK
 * Condition: body part has bandaged wounds to stitch OR contusion wounds
 * (class IDs 20/21/22) to clear. Medic/self checks handled by config.
 *
 * 0: Patient <OBJECT>, 1: Body part <STRING>
 * Return: BOOL
 */
params ["_patient", "_bodyPart"];
_bodyPart = toLower _bodyPart;

private _bandagedWounds = _patient getVariable ["ace_medical_bandagedWounds", createHashMap];
if ((_bandagedWounds getOrDefault [_bodyPart, []]) isNotEqualTo []) exitWith {true};

// Contusion wound class IDs: type index 2 (Contusion) * 10 + severity 0..2
private _openWounds = _patient getVariable ["ace_medical_openWounds", createHashMap];
private _woundsOnPart = _openWounds getOrDefault [_bodyPart, []];

(_woundsOnPart findIf {(_x select 0) in [20, 21, 22] && {(_x select 1) > 0}}) != -1
