/*
 * fn_canBiofoam.sqf
 * [505th] Biofoam Canister - Treatment Condition
 *
 * Returns true if the target body part has open (unbandaged) wounds.
 *
 * Parameters:
 *   0: _medic    <OBJECT> - The medic performing treatment
 *   1: _patient  <OBJECT> - The patient being treated
 *   2: _bodyPart <STRING> - The body part selected (e.g. "leftarm")
 *
 * Returns: BOOL
 */

params ["_medic", "_patient", "_bodyPart"];

_bodyPart = toLower _bodyPart;

private _openWounds = _patient getVariable ["ace_medical_openWounds", createHashMap];
private _openWoundsOnPart = _openWounds getOrDefault [_bodyPart, []];

// Has at least one open wound with amountOf > 0
(_openWoundsOnPart findIf {(_x select 1) > 0}) != -1
