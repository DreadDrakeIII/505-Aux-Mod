/*
 * OLI_fnc_endurexStop
 * Removes local Endurex effects on THIS machine. Clears the global
 * active flag only when the effect has genuinely ended (_clearGlobal),
 * not when the unit merely changed ownership.
 *
 * 0: Patient <OBJECT>
 * 1: Clear global flag <BOOL>
 * 2: (optional) Was using advanced fatigue <BOOL>
 * 3: (optional) Was the local player <BOOL>
 */
params ["_patient", "_clearGlobal", ["_useAF", nil], ["_isPlayer", nil]];

if (isNil "_isPlayer") then {_isPlayer = _patient isEqualTo ACE_player};
if (isNil "_useAF") then {
    _useAF = !isNil "ace_advanced_fatigue_enabled"
        && {missionNamespace getVariable ["ace_advanced_fatigue_enabled", false]}
        && {_isPlayer};
};

if (_isPlayer) then {
    // This ACE build has no removeSwayFactor; a multiplier of 1 is identity
    // (swayLoop takes the product of all multiplier factors).
    ["multiplier", {1}, "OLI_ttk_endurex"] call ace_common_fnc_addSwayFactor;
};

if (_useAF) then {
    ["OLI_ttk_endurex"] call ace_advanced_fatigue_fnc_removeDutyFactor;
} else {
    _patient enableStamina true;
};

_patient setVariable ["OLI_endurexPFH", -1];

if (_clearGlobal) then {
    _patient setVariable ["OLI_endurexActive", false, true];
};
