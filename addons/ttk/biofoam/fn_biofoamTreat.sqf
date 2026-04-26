/*
 * fn_biofoamTreat.sqf
 * [505th] Biofoam Canister - Treatment Callback
 *
 * Bandages wounds on a body part based on strength setting:
 *   0: Bandages everything on the limb
 *   1: Acts as 2x Elastic Bandages
 *   2: Acts as 3x Elastic Bandages
 * Then applies pain based on setting.
 * Handles magazine-based consumption (multi-use canister).
 *
 * Parameters:
 *   0: _medic    <OBJECT> - The medic performing treatment
 *   1: _patient  <OBJECT> - The patient being treated
 *   2: _bodyPart <STRING> - The body part being treated
 */

params ["_medic", "_patient", "_bodyPart"];

_bodyPart = toLower _bodyPart;

// ─── Consume one use from the canister (magazine ammo) ───────────────────────
if (!OLI_biofoam_infinite) then {
    private _mags = magazinesAmmoFull _medic;
    private _idx = _mags findIf {(_x select 0) == "OLI_BiofoamCanister"};

    if (_idx != -1) then {
        private _currentAmmo = (_mags select _idx) select 1;
        private _maxUses = OLI_biofoam_uses;

        // Clamp to configured max uses (magazine spawns with count=10 from
        // config, but the slider may be lower — first use corrects it)
        private _effectiveAmmo = _currentAmmo min _maxUses;

        _medic removeMagazine "OLI_BiofoamCanister";

        if (_effectiveAmmo - 1 > 0) then {
            _medic addMagazine ["OLI_BiofoamCanister", _effectiveAmmo - 1];
        };
    };
};

// ─── Treat wounds ────────────────────────────────────────────────────────────
switch (OLI_biofoam_strength) do {

    // ── Strength 0: Bandage everything on the limb ───────────────────────
    case 0: {
        private _openWounds = _patient getVariable ["ace_medical_openWounds", createHashMap];
        private _openWoundsOnPart = _openWounds getOrDefault [_bodyPart, []];

        if (_openWoundsOnPart isNotEqualTo []) then {
            private _bandagedWounds = _patient getVariable ["ace_medical_bandagedWounds", createHashMap];
            private _bandagedWoundsOnPart = _bandagedWounds getOrDefault [_bodyPart, [], true];

            {
                _x params ["_classID", "_amountOf"];
                private _entry = +_x;
                _entry set [2, 0];

                private _bandagedIndex = _bandagedWoundsOnPart findIf {(_x select 0) == _classID};

                if (_bandagedIndex == -1) then {
                    _bandagedWoundsOnPart pushBack _entry;
                } else {
                    private _wound = _bandagedWoundsOnPart select _bandagedIndex;
                    _wound set [1, (_wound select 1) + _amountOf];
                };
            } forEach _openWoundsOnPart;

            _openWounds set [_bodyPart, []];

            _patient setVariable ["ace_medical_openWounds", _openWounds, true];
            _patient setVariable ["ace_medical_bandagedWounds", _bandagedWounds, true];
        };
    };

    // ── Strength 1: 2x Elastic Bandages ──────────────────────────────────
    case 1: {
        for "_i" from 1 to 2 do {
            ["ace_medical_treatment_bandageLocal", [_patient, _bodyPart, "ElasticBandage"], _patient] call CBA_fnc_targetEvent;
        };
    };

    // ── Strength 2: 3x Elastic Bandages ──────────────────────────────────
    case 2: {
        for "_i" from 1 to 3 do {
            ["ace_medical_treatment_bandageLocal", [_patient, _bodyPart, "ElasticBandage"], _patient] call CBA_fnc_targetEvent;
        };
    };
};

// ─── Apply pain ──────────────────────────────────────────────────────────────
if (OLI_biofoam_painLevel > 0) then {
    private _currentPain = _patient getVariable ["ace_medical_pain", 0];
    _patient setVariable ["ace_medical_pain", ((_currentPain max OLI_biofoam_painLevel) min 1), true];
};

// ─── Recalculate bleeding on the patient's machine ───────────────────────────
[_patient] remoteExecCall ["ace_medical_status_fnc_updateWoundBloodLoss", _patient];

// ─── Force UI update ─────────────────────────────────────────────────────────
["ace_medical_engine_updateDamageEffects", _patient, _patient] call CBA_fnc_targetEvent;
