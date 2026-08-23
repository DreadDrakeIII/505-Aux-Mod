/*
 * OLI_fnc_handleLocality
 * XEH Local handler (CAManBase) + resume sweep entry point.
 * When this machine becomes the owner of a unit with active TTK effects,
 * restart the patient-local loops from the public flags/end-times.
 * Old-owner machines already cleaned up via each PFH's !local exit.
 *
 * 0: Unit <OBJECT>, 1: Is local <BOOL>
 */
params ["_unit", "_isLocal"];

if (!_isLocal || {!alive _unit}) exitWith {};

// ── Endurex ───────────────────────────────────────────────────────────────────
if (_unit getVariable ["OLI_endurexActive", false]) then {
    if (CBA_missionTime < (_unit getVariable ["OLI_endurexEndTime", 0])) then {
        [_unit] call OLI_fnc_endurexLocal;
    } else {
        [_unit, true] call OLI_fnc_endurexStop;
    };
};

// ── Flatline Serum ────────────────────────────────────────────────────────────
if (_unit getVariable ["OLI_flatlineActive", false]) then {
    if (CBA_missionTime < (_unit getVariable ["OLI_flatlineEndTime", 0])) then {
        [_unit] call OLI_fnc_flatlineLocal;
    } else {
        [_unit, true] call OLI_fnc_flatlineStop;
    };
};

// ── NecroClear ────────────────────────────────────────────────────────────────
if (_unit getVariable ["OLI_necroClearActive", false]) then {
    if (CBA_missionTime < (_unit getVariable ["OLI_necroClearEndTime", 0])) then {
        [_unit] call OLI_fnc_necroClearLocal;
    } else {
        _unit setVariable ["OLI_necroClearActive", false, true];
    };
};

// ── Per-limb necrosis tracker ─────────────────────────────────────────────────
if (OLI_hasKAT) then {
    [_unit] call OLI_fnc_necrosisStart;   // self-guards: only runs if needed
};
