/*
 * OLI_fnc_necrosisStart
 * Starts the per-limb necrosis tracker for a unit on THIS machine (the
 * unit must be local — same locality model as KAT's own tracker, which
 * this runs alongside). Safe to call repeatedly; self-guards.
 *
 * Started from:
 *   - ace_medical_treatment_tourniquetLocal event (tourniquet applied)
 *   - OLI_fnc_handleLocality (ownership transfer / resume sweep)
 *
 * Rates match KAT: +0.16/s under a tourniquet, -0.32/s without, both
 * scaled by KAT's own multiplier settings. Values broadcast on change so
 * medics and the GUI can read them anywhere.
 *
 * 0: Unit <OBJECT>
 */
params ["_unit"];

if (!OLI_hasKAT) exitWith {};
if (!local _unit || {!alive _unit}) exitWith {};
if (_unit getVariable ["OLI_necrosisPFH", -1] != -1) exitWith {};   // already tracking here

// [tourniquet array index, per-limb variable]
private _limbs = [
    [2, "OLI_necrosis_leftArm"],
    [3, "OLI_necrosis_rightArm"],
    [4, "OLI_necrosis_leftLeg"],
    [5, "OLI_necrosis_rightLeg"]
];

// Anything to track at all?
private _tourniquets = _unit getVariable ["ace_medical_tourniquets", [0, 0, 0, 0, 0, 0]];
private _anyActivity = false;
{
    _x params ["_tqIdx", "_varName"];
    if ((_tourniquets select _tqIdx) > 0 || {(_unit getVariable [_varName, 0]) > 0}) exitWith {_anyActivity = true};
} forEach _limbs;
if (!_anyActivity) exitWith {};

private _pfh = [{
    params ["_args", "_idPFH"];
    _args params ["_unit", "_limbs"];

    // Locality moved: stop silently, values are already broadcast and the
    // new owner resumes via the XEH Local handler.
    if (!local _unit) exitWith {
        _unit setVariable ["OLI_necrosisPFH", -1];
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (!alive _unit) exitWith {
        {
            _unit setVariable [_x select 1, 0, true];
        } forEach _limbs;
        _unit setVariable ["OLI_necrosisPFH", -1];
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    // Respect KAT's master toggle: no accumulation while disabled.
    private _effectsEnabled = missionNamespace getVariable ["kat_misc_tourniquetEffects_Enable", true];
    private _accum = 0.16 * (missionNamespace getVariable ["kat_misc_tourniquetEffects_PositiveMultiplier", 1]);
    private _drain = 0.32 * (missionNamespace getVariable ["kat_misc_tourniquetEffects_NegativeMultiplier", 1]);

    private _tourniquets = _unit getVariable ["ace_medical_tourniquets", [0, 0, 0, 0, 0, 0]];
    private _anyLeft = false;

    {
        _x params ["_tqIdx", "_varName"];
        private _old = _unit getVariable [_varName, 0];
        private _new = if ((_tourniquets select _tqIdx) > 0) then {
            if (_effectsEnabled) then {(_old + _accum) min 100} else {_old};
        } else {
            (_old - _drain) max 0
        };

        if (_new != _old) then {
            _unit setVariable [_varName, _new, true];
        };
        if (_new > 0 || {(_tourniquets select _tqIdx) > 0}) then {_anyLeft = true};
    } forEach _limbs;

    // Fully clean and untourniqueted: stop until the next application.
    if (!_anyLeft) then {
        _unit setVariable ["OLI_necrosisPFH", -1];
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

}, 1, [_unit, _limbs]] call CBA_fnc_addPerFrameHandler;

_unit setVariable ["OLI_necrosisPFH", _pfh];
