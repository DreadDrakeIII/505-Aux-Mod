/*
 * fn_canNecroClear.sqf
 * [505th] NecroClear Vial - Treatment Condition
 *
 * Requires an established IV line (16g IV or FAST IO) on the selected limb.
 *
 * Parameters:
 *   0: _medic    <OBJECT>
 *   1: _patient  <OBJECT>
 *   2: _bodyPart <STRING>
 *
 * Returns: BOOL
 */

params ["_medic", "_patient", "_bodyPart"];

if (!alive _patient) exitWith {false};

if (_patient getVariable ["OLI_NecroClearActive", false]) exitWith {false};

if (_medic == _patient && {!OLI_NecroClear_allowSelfUse}) exitWith {false};

if (OLI_NecroClear_medicRequired == 1 && {!([_medic] call ace_medical_treatment_fnc_isMedic)}) exitWith {false};

// Require established IV access on the selected limb (KAT pharma)
// 0 = none, 1 = FAST IO, 2 = 16g IV
private _partIndex = ["head", "body", "leftarm", "rightarm", "leftleg", "rightleg"] find (toLower _bodyPart);
private _IVarray = _patient getVariable ["kat_pharma_IV", [0,0,0,0,0,0]];
if ((_IVarray select _partIndex) == 0) exitWith {false};

true
