/*
 * fn_bonePolyseal.sqf
 * [505th] Bone Polyseal Autoinjector - Treatment Callback
 *
 * Injects the polymer with immediate pain, then after a delay
 * the splint effect kicks in. The delayed callback runs on the server
 * so it survives medic disconnect.
 *
 * Parameters:
 *   0: _medic    <OBJECT> - The medic performing treatment
 *   1: _patient  <OBJECT> - The patient being treated
 *   2: _bodyPart <STRING> - The body part being treated
 */

params ["_medic", "_patient", "_bodyPart"];

// Immediate injection pain
if (OLI_polyseal_painLevel > 0) then {
    private _currentPain = _patient getVariable ["ace_medical_pain", 0];
    _patient setVariable ["ace_medical_pain", (_currentPain + OLI_polyseal_painLevel) min 1, true];
};

// Delayed splint effect — scheduled on server to survive medic disconnect
private _delay = OLI_polyseal_healDelay;
private _medicName = [_medic, false, true] call ace_common_fnc_getName;

[{
    params ["_patient", "_bodyPart", "_medicName"];

    if (!alive _patient) exitWith {};

    private _partIndex = ["head", "body", "leftarm", "rightarm", "leftleg", "rightleg"] find (toLower _bodyPart);
    if (_partIndex == -1) exitWith {};

    private _fractures = _patient getVariable ["ace_medical_fractures", [0, 0, 0, 0, 0, 0]];

    // Only apply if still fractured (1 = fractured, -1 = splinted)
    if ((_fractures select _partIndex) != 1) exitWith {};

    _fractures set [_partIndex, -1];
    _patient setVariable ["ace_medical_fractures", _fractures, true];

    ["ace_medical_engine_updateDamageEffects", _patient, _patient] call CBA_fnc_targetEvent;

    [_patient, "activity", "Bone Polyseal has taken effect", [_medicName]] call ace_medical_treatment_fnc_addToLog;

}, [_patient, _bodyPart, _medicName], _delay] remoteExecCall ["CBA_fnc_waitAndExecute", 2];
