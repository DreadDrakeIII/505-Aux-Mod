// OLI_KCS - SERVER (patient local): fracture one limb.
// ACE fracture array + limp/aim effects + a bit of pain.
//
// Arguments: 0: patient <OBJECT>, 1: limb selection name <STRING>

params ["_p", "_limb"];

private _idx = OLI_KCS_BodyParts find _limb;
if (_idx < 2) exitWith {};      // head/body can't fracture in ACE

private _fractures = _p getVariable ["ace_medical_fractures", [0, 0, 0, 0, 0, 0]];
_fractures set [_idx, 1];
_p setVariable ["ace_medical_fractures", _fractures, true];
[_p] call ace_medical_engine_fnc_updateDamageEffects;
[_p, 0.3] call ace_medical_status_fnc_adjustPainLevel;
