/*
 * OLI_fnc_ttkLocal
 * Runs on the PATIENT's machine (via OLI_ttk_stitchLocal target event).
 *  1. Stitches all bandaged wounds on the part (bandaged -> stitched)
 *  2. Clears contusion wounds (class IDs 20/21/22) from open wounds
 *  3. Clears accumulated blunt trauma (bodyPartDamage) on the part
 *
 * 0: Medic <OBJECT>, 1: Patient <OBJECT>, 2: Body part <STRING>
 */
params ["_medic", "_patient", "_bodyPart"];

if (!local _patient || {!alive _patient}) exitWith {};
_bodyPart = toLower _bodyPart;

// ── 1. Stitch all bandaged wounds on this body part ──────────────────────────
private _bandagedWounds = _patient getVariable ["ace_medical_bandagedWounds", createHashMap];
private _bandagedOnPart = _bandagedWounds getOrDefault [_bodyPart, []];

if (_bandagedOnPart isNotEqualTo []) then {
    private _stitchedWounds = _patient getVariable ["ace_medical_stitchedWounds", createHashMap];
    private _stitchedOnPart = _stitchedWounds getOrDefault [_bodyPart, [], true];

    {
        _x params ["_classID", "_amountOf"];
        private _idx = _stitchedOnPart findIf {(_x select 0) == _classID};
        if (_idx == -1) then {
            _stitchedOnPart pushBack (+_x);
        } else {
            private _wound = _stitchedOnPart select _idx;
            _wound set [1, (_wound select 1) + _amountOf];
        };
    } forEach _bandagedOnPart;

    _bandagedWounds set [_bodyPart, []];
    _patient setVariable ["ace_medical_bandagedWounds", _bandagedWounds, true];
    _patient setVariable ["ace_medical_stitchedWounds", _stitchedWounds, true];
};

// ── 2. Clear contusion entries from open wounds ───────────────────────────────
private _openWounds = _patient getVariable ["ace_medical_openWounds", createHashMap];
private _openOnPart = _openWounds getOrDefault [_bodyPart, []];
private _filtered = _openOnPart select {!((_x select 0) in [20, 21, 22])};

if (count _filtered < count _openOnPart) then {
    _openWounds set [_bodyPart, _filtered];
    _patient setVariable ["ace_medical_openWounds", _openWounds, true];
};

// ── 3. Clear blunt trauma on the part ─────────────────────────────────────────
private _partIndex = ["head", "body", "leftarm", "rightarm", "leftleg", "rightleg"] find _bodyPart;
if (_partIndex != -1) then {
    private _damage = _patient getVariable ["ace_medical_bodyPartDamage", [0, 0, 0, 0, 0, 0]];
    if ((_damage select _partIndex) > 0) then {
        _damage set [_partIndex, 0];
        _patient setVariable ["ace_medical_bodyPartDamage", _damage, true];
    };
};

// ── Recalculate and log ───────────────────────────────────────────────────────
[_patient] call ace_medical_status_fnc_updateWoundBloodLoss;
[_patient] call ace_medical_engine_fnc_updateDamageEffects;

[_patient, "activity", "%1 used a Tactical Trauma Kit", [[_medic, false, true] call ace_common_fnc_getName]] call ace_medical_treatment_fnc_addToLog;
