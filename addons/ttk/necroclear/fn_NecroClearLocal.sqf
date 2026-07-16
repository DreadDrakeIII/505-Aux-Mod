/*
 * OLI_fnc_necroClearLocal
 * Runs on the PATIENT's machine. Drains necrosis until the public
 * end-time. KAT's combined arm/leg values are patient-local (KAT never
 * broadcasts them), so they are drained locally to stay in sync with
 * KAT's own PFH. Our per-limb values broadcast on change.
 *
 * Resumable: if the patient changes locality mid-drain, this PFH exits
 * and OLI_fnc_handleLocality restarts it on the new owner.
 *
 * 0: Patient <OBJECT>
 */
params ["_patient"];

if (!local _patient || {!alive _patient}) exitWith {};
if (_patient getVariable ["OLI_necroClearPFH", -1] != -1) exitWith {};   // already running here

private _pfh = [{
    params ["_args", "_idPFH"];
    _args params ["_patient"];

    // Locality moved away: stop here, flag stays set for the new owner.
    if (!local _patient) exitWith {
        _patient setVariable ["OLI_necroClearPFH", -1];
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _endTime = _patient getVariable ["OLI_necroClearEndTime", 0];
    if (!alive _patient || {CBA_missionTime >= _endTime} || {!(_patient getVariable ["OLI_necroClearActive", false])}) exitWith {
        _patient setVariable ["OLI_necroClearPFH", -1];
        _patient setVariable ["OLI_necroClearActive", false, true];
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    // Drain per 0.5s tick
    private _drain = (missionNamespace getVariable ["OLI_NecroClear_effectiveness", 15]) * 0.5;

    // KAT combined values: LOCAL writes, matching KAT's own locality model
    {
        private _val = _patient getVariable [_x, 0];
        if (_val > 0) then {
            _patient setVariable [_x, (_val - _drain) max 0];
        };
    } forEach ["kat_misc_Tourniquet_ArmNecrosis", "kat_misc_Tourniquet_LegNecrosis"];

    // Our per-limb values: broadcast on change
    {
        private _val = _patient getVariable [_x, 0];
        if (_val > 0) then {
            _patient setVariable [_x, (_val - _drain) max 0, true];
        };
    } forEach ["OLI_necrosis_leftArm", "OLI_necrosis_rightArm", "OLI_necrosis_leftLeg", "OLI_necrosis_rightLeg"];

}, 0.5, [_patient]] call CBA_fnc_addPerFrameHandler;

_patient setVariable ["OLI_necroClearPFH", _pfh];
