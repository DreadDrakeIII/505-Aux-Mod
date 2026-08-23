/*
 * XEH_postInit.sqf — [505th] Tactical Trauma Kit
 * Event wiring. All patient-state mutation happens in *Local functions on
 * the patient's machine, reached via these CBA target events.
 */

// ─── Treatment target events (run where the patient is local) ────────────────
["OLI_ttk_biofoamLocal",   {_this call OLI_fnc_biofoamLocal}]   call CBA_fnc_addEventHandler;
["OLI_ttk_stitchLocal",    {_this call OLI_fnc_ttkLocal}]       call CBA_fnc_addEventHandler;
["OLI_ttk_polysealLocal",  {_this call OLI_fnc_polysealLocal}]  call CBA_fnc_addEventHandler;
["OLI_ttk_polysealApply",  {_this call OLI_fnc_polysealApply}]  call CBA_fnc_addEventHandler;
["OLI_ttk_necroClearLocal",{_this call OLI_fnc_necroClearLocal}] call CBA_fnc_addEventHandler;
["OLI_ttk_endurexLocal",   {_this call OLI_fnc_endurexLocal}]   call CBA_fnc_addEventHandler;
["OLI_ttk_flatlineLocal",  {_this call OLI_fnc_flatlineLocal}]  call CBA_fnc_addEventHandler;

// Multi-use canister consumption, on whichever machine owns the holder.
["OLI_ttk_consumeCanister", {
    params ["_holder"];
    if (!local _holder) exitWith {};
    if (missionNamespace getVariable ["OLI_biofoam_infinite", false]) exitWith {};

    private _mags = magazinesAmmoFull _holder;
    private _idx = _mags findIf {(_x select 0) == "OLI_BiofoamCanister"};
    if (_idx == -1) exitWith {};

    private _current = (_mags select _idx) select 1;
    private _maxUses = missionNamespace getVariable ["OLI_biofoam_uses", 5];
    private _remaining = (_current min _maxUses) - 1;

    _holder removeMagazine "OLI_BiofoamCanister";
    if (_remaining > 0) then {
        _holder addMagazine ["OLI_BiofoamCanister", _remaining];
    };
}] call CBA_fnc_addEventHandler;

// Server-side scheduler for the Polyseal heal delay. Lives on the server
// so it survives medic disconnect; routed via CBA events only (immune to
// mission CfgRemoteExec restrictions, e.g. Liberation).
if (isServer) then {
    ["OLI_ttk_polysealSchedule", {
        params ["_medic", "_patient", "_bodyPart"];
        private _delay = missionNamespace getVariable ["OLI_polyseal_healDelay", 6];
        [{
            params ["_medic", "_patient", "_bodyPart"];
            if (isNull _patient || {!alive _patient}) exitWith {};
            ["OLI_ttk_polysealApply", [_medic, _patient, _bodyPart], _patient] call CBA_fnc_targetEvent;
        }, _this, _delay] call CBA_fnc_waitAndExecute;
    }] call CBA_fnc_addEventHandler;
};

// ─── Treatment action sounds (keyed by lowercase action classname) ───────────
// Fires when a treatment action actually starts (not on success), so the
// cue plays the moment the medic begins using the item. Plays from the
// medic's position since that's where the item is being used.
OLI_ttk_actionSounds = createHashMapFromArray [
    ["endurexboosterinhaler", ["\BLU\OLI\addons\ttk\sounds\endurex01.ogg", 1, 1, 25]]
];

["ace_treatmentStarted", {
    params ["_medic", "_patient", "_bodyPart", "_classname"];

    private _entry = OLI_ttk_actionSounds get (toLower _classname);
    if (isNil "_entry") exitWith {};

    // Debounce: at most one play per medic per second, in case anything
    // upstream ever double-fires the treatment start.
    if (CBA_missionTime - (_medic getVariable ["OLI_ttk_lastActionSound", -10]) < 1) exitWith {};
    _medic setVariable ["OLI_ttk_lastActionSound", CBA_missionTime];

    _entry params ["_file", "_volume", "_pitch", "_distance"];
    playSound3D [_file, objNull, false, getPosASL _medic, _volume, _pitch, _distance];
}] call CBA_fnc_addEventHandler;

// ─── Per-limb necrosis tracking (KAT only, patient-local like KAT's own) ─────
if (OLI_hasKAT) then {
    // Fires on the patient's machine whenever a tourniquet is applied.
    ["ace_medical_treatment_tourniquetLocal", {
        params ["_patient"];
        [_patient] call OLI_fnc_necrosisStart;
    }] call CBA_fnc_addEventHandler;
};

// ─── Medical GUI: body image swap + necrosis tint ────────────────────────────
// Registered one frame late so our handler runs AFTER ACE's (and KAT's)
// updateBodyImage handlers regardless of addon load order.
if (hasInterface) then {
    [{
        ["ace_medical_gui_updateBodyImage", {
            _this call OLI_fnc_updateBodyImage;
        }] call CBA_fnc_addEventHandler;
    }] call CBA_fnc_execNextFrame;

    ["ace_medical_gui_updateInjuryListGeneral", {
        params ["_ctrl", "_target", "_selectionN", "_entries"];

        if (_target getVariable ["OLI_endurexActive", false]) then {
            _entries pushBack ["Under Endurex effect", [0.25, 0.8, 1, 1]];
        };

        if (_target getVariable ["OLI_flatlineActive", false]) then {
            _entries pushBack ["Under Flatline Serum", [1, 0.35, 0.35, 1]];
        };
    }] call CBA_fnc_addEventHandler;
};

// ─── Resume sweep ─────────────────────────────────────────────────────────────
// Covers mission start / save resume / JIP with already-active effects:
// restart patient-local loops for units that are local to this machine.
// Delayed a few seconds so JIP variable sync and CBA settings settle.
[{
    {
        if (local _x) then {
            [_x, true] call OLI_fnc_handleLocality;
        };
    } forEach allUnits;
}, [], 5] call CBA_fnc_waitAndExecute;
