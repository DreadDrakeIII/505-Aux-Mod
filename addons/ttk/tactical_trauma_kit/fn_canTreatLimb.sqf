/*
 * fn_canTreatLimb.sqf
 * [505th] Tactical Trauma Kit - Treatment Condition
 *
 * Returns true if the medic meets the required training level, self-care
 * is permitted (if treating self), and the body part has treatable conditions.
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
private _bruiseIDs = [20, 21, 22];

// ─── Check self-care setting ─────────────────────────────────────────────────
if (_medic == _patient && {OLI_TTK_selfCare == 0}) exitWith {false};

// ─── Check medic requirement ─────────────────────────────────────────────────
if (OLI_TTK_medicRequired == 1 && {!([_medic] call ace_medical_treatment_fnc_isMedic)}) exitWith {false};

// ─── Check for bandaged wounds on this body part ─────────────────────────────
private _bandagedWounds = _patient getVariable ["ace_medical_bandagedWounds", createHashMap];
private _bandagedWoundsOnPart = _bandagedWounds getOrDefault [_bodyPart, []];

if (_bandagedWoundsOnPart isNotEqualTo []) exitWith {true};

// ─── Check for bruise entries in openWounds on this body part ────────────────
private _openWounds = _patient getVariable ["ace_medical_openWounds", createHashMap];
private _openWoundsOnPart = _openWounds getOrDefault [_bodyPart, []];

(_openWoundsOnPart findIf {(_x select 0) in _bruiseIDs}) != -1
