/*
 * fn_NecroClearLocal.sqf
 * [505th] NecroClear Autoinjector - Local Drain PFH
 *
 * Runs on the patient's machine (remoteExecCall'd from NecroClearTreat).
 * All settings read fresh each tick with nil-safe defaults in case CBA
 * settings haven't synced yet. All setVariable calls broadcast.
 *
 * Parameters:
 *   0: _patient <OBJECT>
 */

params ["_patient"];

if (!local _patient) exitWith {};

[{
    params ["_args", "_idPFH"];
    private _patient   = _args select 0;
    private _startTime = _args select 1;

    private _duration = missionNamespace getVariable ["OLI_NecroClear_duration", 10];

    // Stop if dead or duration elapsed
    if (!alive _patient || {CBA_missionTime - _startTime >= _duration}) exitWith {
        _patient setVariable ["OLI_NecroClearActive", false, true];
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    private _effectiveness = missionNamespace getVariable ["OLI_NecroClear_effectiveness", 45];
    private _drainPerTick = 0.16 * _effectiveness;

    // Drain arm necrosis (KAT combined + OLI per-limb)
    private _armNecrosis = _patient getVariable ["kat_misc_Tourniquet_ArmNecrosis", 0];
    _patient setVariable ["kat_misc_Tourniquet_ArmNecrosis", ((_armNecrosis - _drainPerTick) max 0), true];

    private _leftArm = ((_patient getVariable ["OLI_necrosis_leftArm", 0]) - _drainPerTick) max 0;
    private _rightArm = ((_patient getVariable ["OLI_necrosis_rightArm", 0]) - _drainPerTick) max 0;
    _patient setVariable ["OLI_necrosis_leftArm", _leftArm, true];
    _patient setVariable ["OLI_necrosis_rightArm", _rightArm, true];

    // Drain leg necrosis (KAT combined + OLI per-limb)
    private _legNecrosis = _patient getVariable ["kat_misc_Tourniquet_LegNecrosis", 0];
    _patient setVariable ["kat_misc_Tourniquet_LegNecrosis", ((_legNecrosis - _drainPerTick) max 0), true];

    private _leftLeg = ((_patient getVariable ["OLI_necrosis_leftLeg", 0]) - _drainPerTick) max 0;
    private _rightLeg = ((_patient getVariable ["OLI_necrosis_rightLeg", 0]) - _drainPerTick) max 0;
    _patient setVariable ["OLI_necrosis_leftLeg", _leftLeg, true];
    _patient setVariable ["OLI_necrosis_rightLeg", _rightLeg, true];

}, 0.5, [_patient, CBA_missionTime]] call CBA_fnc_addPerFrameHandler;
