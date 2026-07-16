/*
 * OLI_fnc_canFlatline
 * Condition: alive, no active dose, and (if the patient is conscious)
 * conscious use must be enabled. Unconscious and cardiac arrest patients
 * are always valid targets — that is the point of the serum.
 * Medic/self checks handled by ACE via the action config.
 *
 * 0: Patient <OBJECT>, 1: Body part <STRING>
 * Return: BOOL
 */
params ["_patient", "_bodyPart"];

if (!alive _patient) exitWith {false};
if (_patient getVariable ["OLI_flatlineActive", false]) exitWith {false};

private _isDown = (_patient getVariable ["ACE_isUnconscious", false])
    || {_patient getVariable ["ace_medical_inCardiacArrest", false]};

_isDown || {missionNamespace getVariable ["OLI_stim_allowConscious", true]}
