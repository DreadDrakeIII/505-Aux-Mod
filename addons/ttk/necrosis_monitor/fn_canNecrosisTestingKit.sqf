/*
 * fn_canNecrosisTestingKit.sqf
 * [505th] Necrosis Testing Kit - Treatment Condition
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

if (OLI_necrosisTestingKit_medicRequired == 1 && {!([_medic] call ace_medical_treatment_fnc_isMedic)}) exitWith {false};

true
