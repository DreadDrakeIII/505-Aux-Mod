/*
 * fn_treatLimb.sqf
 * [505th] Tactical Trauma Kit - Treatment Callback
 *
 * Stitches all bandaged wounds on the target body part (moves them from
 * bandagedWounds to stitchedWounds), clears bruise/contusion entries
 * (classIDs 20, 21, 22) from openWounds, and handles item consumption.
 *
 * Parameters:
 *   0: _medic    <OBJECT> - The medic performing treatment
 *   1: _patient  <OBJECT> - The patient being treated
 *   2: _bodyPart <STRING> - The body part being treated (e.g. "leftarm")
 */

params ["_medic", "_patient", "_bodyPart"];

_bodyPart = toLower _bodyPart;
private _bruiseIDs = [20, 21, 22];

// ─── Step 1: Stitch all bandaged wounds on this body part ────────────────────
private _bandagedWounds = _patient getVariable ["ace_medical_bandagedWounds", createHashMap];
private _bandagedWoundsOnPart = _bandagedWounds getOrDefault [_bodyPart, []];

if (_bandagedWoundsOnPart isNotEqualTo []) then {
    private _stitchedWounds = _patient getVariable ["ace_medical_stitchedWounds", createHashMap];
    private _stitchedWoundsOnPart = _stitchedWounds getOrDefault [_bodyPart, [], true];

    {
        _x params ["_classID", "_amountOf"];

        private _stitchedIndex = _stitchedWoundsOnPart findIf {(_x select 0) == _classID};

        if (_stitchedIndex == -1) then {
            _stitchedWoundsOnPart pushBack +_x;
        } else {
            private _wound = _stitchedWoundsOnPart select _stitchedIndex;
            _wound set [1, (_wound select 1) + _amountOf];
        };
    } forEach _bandagedWoundsOnPart;

    _bandagedWounds set [_bodyPart, []];

    _patient setVariable ["ace_medical_bandagedWounds", _bandagedWounds, true];
    _patient setVariable ["ace_medical_stitchedWounds", _stitchedWounds, true];
};

// ─── Step 2: Clear bruise/contusion entries from openWounds ──────────────────
private _openWounds = _patient getVariable ["ace_medical_openWounds", createHashMap];
private _openWoundsOnPart = _openWounds getOrDefault [_bodyPart, []];

private _filtered = _openWoundsOnPart select {!((_x select 0) in _bruiseIDs)};

if (count _filtered < count _openWoundsOnPart) then {
    _openWounds set [_bodyPart, _filtered];
    _patient setVariable ["ace_medical_openWounds", _openWounds, true];
};

// ─── Step 3: Clear trauma (body part damage) ─────────────────────────────────
private _bodyParts = ["head", "body", "leftarm", "rightarm", "leftleg", "rightleg"];
private _partIndex = _bodyParts find _bodyPart;

if (_partIndex != -1) then {
    private _damage = _patient getVariable ["ace_medical_bodyPartDamage", [0, 0, 0, 0, 0, 0]];

    if ((_damage select _partIndex) > 0) then {
        _damage set [_partIndex, 0];
        _patient setVariable ["ace_medical_bodyPartDamage", _damage, true];

        private _hitPoints = ["HitHead", "HitBody", "HitLeftArm", "HitRightArm", "HitLeftLeg", "HitRightLeg"];
        _patient setHitPointDamage [_hitPoints select _partIndex, 0, true, _medic];
    };
};

// ─── Step 4: Consume item based on setting ───────────────────────────────────
switch (OLI_TTK_consumeItem) do {
    case 1: {
        _medic removeItem "OLI_TacticalTraumaKit";
    };
    case 2: {
        // WIP - Suture consumption not yet functional
    };
};

// ─── Step 5: Force UI update ─────────────────────────────────────────────────
["ace_medical_engine_updateDamageEffects", _patient, _patient] call CBA_fnc_targetEvent;
