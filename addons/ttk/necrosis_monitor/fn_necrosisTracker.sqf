/*
 * fn_necrosisTracker.sqf
 * [505th] Per-Limb Necrosis Tracker
 *
 * Server-side PFH that tracks tourniquet necrosis independently per limb.
 * Runs every 1 second.
 *
 * Optimization: a limb is only tracked once it has been tourniqueted at least
 * once (flag persists even after removal). Players who never receive a
 * tourniquet (command, zeus, etc.) cost one getVariable + skip per tick.
 * Values are only broadcast when they actually change.
 *
 * ace_medical_tourniquets array indices:
 *   0=head, 1=body, 2=leftarm, 3=rightarm, 4=leftleg, 5=rightleg
 *
 * Rates match KAT exactly:
 *   Accumulate: +0.16 per second
 *   Drain:      -0.32 per second
 *
 * Variables written (broadcast only on change):
 *   OLI_necrosis_leftArm, OLI_necrosis_rightArm
 *   OLI_necrosis_leftLeg, OLI_necrosis_rightLeg
 */

if (!isServer) exitWith {};

// Limb config: [tourniquet index, variable name]
private _limbConfig = [
    [2, "OLI_necrosis_leftArm"],
    [3, "OLI_necrosis_rightArm"],
    [4, "OLI_necrosis_leftLeg"],
    [5, "OLI_necrosis_rightLeg"]
];

[{
    params ["_limbConfig"];

    private _accum = 0.16 * (missionNamespace getVariable ["kat_misc_tourniquetEffects_PositiveMultiplier", 1]);
    private _drain = 0.32 * (missionNamespace getVariable ["kat_misc_tourniquetEffects_NegativeMultiplier", 1]);

    {
        private _unit = _x;
        if (!alive _unit) then { continue };

        private _tourniquets = _unit getVariable ["ace_medical_tourniquets", [0,0,0,0,0,0]];

        // Per-limb tracking flags — array of 4 bools matching _limbConfig order
        // Only created/stored once a tourniquet is first detected
        private _tracked = _unit getVariable ["OLI_necrosis_tracked", [false, false, false, false]];
        private _trackedChanged = false;
        private _anyTracked = false;

        // Check for newly tourniqueted limbs and flag them for permanent tracking
        {
            _x params ["_tqIdx", "_varName"];
            if (!(_tracked select _forEachIndex) && {(_tourniquets select _tqIdx) > 0}) then {
                _tracked set [_forEachIndex, true];
                _trackedChanged = true;
            };
            if (_tracked select _forEachIndex) then { _anyTracked = true };
        } forEach _limbConfig;

        // Save tracked flags if changed (server-only, no broadcast needed)
        if (_trackedChanged) then {
            _unit setVariable ["OLI_necrosis_tracked", _tracked];
        };

        // Skip entirely if this unit has never been tourniqueted
        if (!_anyTracked) then { continue };

        // Process only tracked limbs
        {
            _x params ["_tqIdx", "_varName"];

            if (!(_tracked select _forEachIndex)) then { continue };

            private _val = _unit getVariable [_varName, 0];
            private _oldVal = _val;

            if ((_tourniquets select _tqIdx) > 0) then {
                _val = (_val + _accum) min 100;
            } else {
                _val = (_val - _drain) max 0;
            };

            // Only broadcast if the value actually changed
            if (_val != _oldVal) then {
                _unit setVariable [_varName, _val, true];
            };
        } forEach _limbConfig;

    } forEach allPlayers;

}, 1, _limbConfig] call CBA_fnc_addPerFrameHandler;
