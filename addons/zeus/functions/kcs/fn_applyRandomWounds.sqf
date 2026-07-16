// OLI_KCS - SERVER (patient local): roll and apply a random wound set.
//
// Arguments: 0: patient <OBJECT>, 1: severity 1-3 <NUMBER>,
//            2: mechanism id, 0 = random <NUMBER>

params ["_p", "_severity", "_mechanism"];

(OLI_KCS_SeverityTable get _severity) params ["_cMin", "_cRnd", "_dmg", "_fracChance", "_sizeW", "_kat"];

if (_mechanism == 0) then {
    _mechanism = selectRandom (OLI_KCS_MechanismsBySeverity select (_severity - 1));
};
(OLI_KCS_MechanismTable get _mechanism) params ["", "_woundTypes", "_partW"];

private _count = _cMin + floor random (_cRnd + 1);
private _hitParts = [];

for "_i" from 1 to _count do {
    private _part = OLI_KCS_BodyParts selectRandomWeighted _partW;
    private _size = [0, 1, 2] selectRandomWeighted _sizeW;

    // keep head/body survivable: no large wounds on head ever,
    // large on body only for Expectant
    if (_part == "head") then { _size = _size min 1; };
    if (_part == "body" && {_severity < 3}) then { _size = _size min 1; };

    private _wDmg = _dmg * (0.8 + random 0.4);
    [_p, _part, [selectRandom _woundTypes, 1, _size, _wDmg]] call ace_medical_fnc_addWound;
    _hitParts pushBackUnique _part;
};

// fractures: two independent rolls on wounded limbs (falling favours legs)
private _limbs = _hitParts arrayIntersect ["leftarm", "rightarm", "leftleg", "rightleg"];
if (_mechanism == 5 && {_limbs isEqualTo []}) then { _limbs = ["leftleg", "rightleg"]; };
if (_limbs isNotEqualTo []) then {
    private _done = [];
    for "_r" from 1 to 2 do {
        if (random 1 < _fracChance) then {
            private _limb = selectRandom _limbs;
            if !(_limb in _done) then {
                _done pushBack _limb;
                [_p, _limb] call OLI_KCS_fnc_addFracture;
            };
        };
    };
};

// KAT complications (Priority / Expectant only), slight delay
if (_kat && OLI_KCS_KatLoaded) then {
    [{
        params ["_p", "_hitParts", "_severity"];
        if (isNull _p || {!alive _p}) exitWith {};

        // airway
        if (random 1 < ([0.25, 0.35] select (_severity >= 3))) then {
            [_p, "obstruction"] call OLI_KCS_fnc_applyKat;
        };
        if (random 1 < ([0.20, 0.30] select (_severity >= 3))) then {
            [_p, "occlusion"] call OLI_KCS_fnc_applyKat;
        };

        // chest
        if ("body" in _hitParts) then {
            if (_severity >= 3) then {
                if (random 1 < 0.6) then {
                    [_p, ["tension", "hemothorax"] select (random 1 < 0.5)] call OLI_KCS_fnc_applyKat;
                } else {
                    [_p, "pneumothorax", 2] call OLI_KCS_fnc_applyKat;
                };
            } else {
                if (random 1 < 0.5) then {
                    [_p, "pneumothorax", 1] call OLI_KCS_fnc_applyKat;
                } else {
                    if (random 1 < 0.4) then { [_p, "openchest"] call OLI_KCS_fnc_applyKat; };
                };
            };
        };
    }, [_p, _hitParts, _severity], 1.5] call CBA_fnc_waitAndExecute;
};
