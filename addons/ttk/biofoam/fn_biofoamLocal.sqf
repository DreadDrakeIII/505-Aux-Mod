/*
 * OLI_fnc_biofoamLocal
 * Runs on the PATIENT's machine (via OLI_ttk_biofoamLocal target event).
 * Bandages wounds through ACE's own bandageLocal so all bookkeeping
 * (bandagedWounds, blood loss, damage effects) stays consistent.
 *
 * Strength setting:
 *   0 = bandage everything on the part
 *   1 = 2x Elastic Bandage
 *   2 = 3x Elastic Bandage
 *
 * 0: Medic <OBJECT>, 1: Patient <OBJECT>, 2: Body part <STRING>
 */
params ["_medic", "_patient", "_bodyPart"];

if (!local _patient || {!alive _patient}) exitWith {};
_bodyPart = toLower _bodyPart;

private _strength = missionNamespace getVariable ["OLI_biofoam_strength", 0];

private _fnc_openAmount = {
    params ["_patient", "_bodyPart"];
    private _openWounds = _patient getVariable ["ace_medical_openWounds", createHashMap];
    private _total = 0;
    {
        _total = _total + (_x select 1);
    } forEach (_openWounds getOrDefault [_bodyPart, []]);
    _total
};

switch (_strength) do {
    // Bandage everything on the part: apply elastic bandages until no
    // open wounds remain (progress-guarded).
    case 0: {
        private _remaining = [_patient, _bodyPart] call _fnc_openAmount;
        private _iterations = 0;
        while {_remaining > 0 && _iterations < 25} do {
            [_patient, _bodyPart, "ElasticBandage"] call ace_medical_treatment_fnc_bandageLocal;
            private _newRemaining = [_patient, _bodyPart] call _fnc_openAmount;
            if (_newRemaining >= _remaining) exitWith {};   // no progress, bail
            _remaining = _newRemaining;
            _iterations = _iterations + 1;
        };
    };
    case 1: {
        for "_i" from 1 to 2 do {
            [_patient, _bodyPart, "ElasticBandage"] call ace_medical_treatment_fnc_bandageLocal;
        };
    };
    case 2: {
        for "_i" from 1 to 3 do {
            [_patient, _bodyPart, "ElasticBandage"] call ace_medical_treatment_fnc_bandageLocal;
        };
    };
};

// Application pain (max-semantics, patient-local as ACE requires)
private _pain = missionNamespace getVariable ["OLI_biofoam_painLevel", 0.5];
if (_pain > 0) then {
    [_patient, _pain] call ace_medical_status_fnc_adjustPainLevel;
};

[_patient] call ace_medical_status_fnc_updateWoundBloodLoss;

[_patient, "activity", "%1 applied Biofoam", [[_medic, false, true] call ace_common_fnc_getName]] call ace_medical_treatment_fnc_addToLog;
