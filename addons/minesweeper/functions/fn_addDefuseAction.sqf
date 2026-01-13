// Runs on each client to add the defuse and inspect actions
// Called via remoteExec from server

params [["_ied", objNull, [objNull]]];

if (isNull _ied) exitWith {};
if (!hasInterface) exitWith {};

// Add Inspect IED action (higher priority, instant)
private _inspectId = _ied addAction [
    "Inspect IED",
    {
        params ["_target", "_caller", "_actionId", "_arguments"];
        
        private _difficulty = _target getVariable ["MSIED_difficulty", "medium"];
        
        private _hintText = switch (toLower _difficulty) do {
            case "easy": { "The circuitry is simple" };
            case "medium": { "The circuitry is not too hard" };
            case "hard": { "The circuitry is complex" };
            case "extreme": { "The circuitry is Beyond All Reason" };
            default { "The circuitry is partially guarded and uses special made fuses unknown to the UNSC" }; // custom
        };
        
        hint _hintText;
    },
    [],
    6,          // Priority (higher than Defuse)
    true,
    false,      // Don't hide on use
    "",
    "_this distance _target < 4 && !(_target getVariable ['MSIED_Defused', false]) && !(_target getVariable ['MSIED_Detonated', false])"
];

// Add Defuse action (hold action)
private _defuseId = [
    _ied,                                                   // Object
    "Defuse",                                               // Title
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",  // Idle icon
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",  // Progress icon
    "_this distance _target < 4 && !(_target getVariable ['MSIED_Defused', false]) && !(_target getVariable ['MSIED_Detonated', false])",  // Condition to show
    "_caller distance _target < 4",                         // Condition to progress
    {},                                                     // Code on start
    {},                                                     // Code on progress
    {
        params ["_target", "_caller", "_actionId", "_arguments"];
        [_target] call MSIED_fnc_initMinefield;
    },                                                      // Code on completion
    {},                                                     // Code on interrupted
    [],                                                     // Arguments
    3,                                                      // Duration (seconds)
    5.9,                                                    // Priority
    true,                                                   // Remove on completion
    false                                                   // Show to unconscious
] call BIS_fnc_holdActionAdd;

_ied setVariable ["MSIED_ActionId", _defuseId];
_ied setVariable ["MSIED_InspectId", _inspectId];

// Add instant defuse action (only shows when debug mode is on)
private _debugDefuseId = _ied addAction [
    "Defuse (Debug - Instant)",
    {
        params ["_target", "_caller", "_actionId", "_arguments"];
        [_target] call MSIED_fnc_initMinefield;
    },
    [],
    5.95,       // Priority (between Inspect and Defuse)
    true,
    true,       // hideOnUse
    "",
    "_this distance _target < 4 && (_target getVariable ['MSIED_Debug', false]) && !(_target getVariable ['MSIED_Defused', false]) && !(_target getVariable ['MSIED_Detonated', false])"
];

_ied setVariable ["MSIED_DebugDefuseId", _debugDefuseId];