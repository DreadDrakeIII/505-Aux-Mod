// Runs on each client to add the defuse and inspect actions
// Called via remoteExec from server

params [["_ied", objNull, [objNull]]];

if (isNull _ied) exitWith {};
if (!hasInterface) exitWith {};

// Prevent duplicate actions (fixes bug when players leave server)
if (_ied getVariable ["MSIED_ActionsAdded_Local", false]) exitWith {};
_ied setVariable ["MSIED_ActionsAdded_Local", true];

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
            default { "The circuitry is partially guarded and uses special made fuses unknown to the UNSC" };
        };
        
        hint _hintText;
    },
    [],
    6,
    true,
    false,
    "",
    "_this distance _target < 4 && !(_target getVariable ['MSIED_Defused', false]) && !(_target getVariable ['MSIED_Detonated', false])"
];

// Add Defuse action (hold action)
private _defuseId = [
    _ied,
    "Defuse",
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",
    "_this distance _target < 4 && !(_target getVariable ['MSIED_Defused', false]) && !(_target getVariable ['MSIED_Detonated', false])",
    "_caller distance _target < 4",
    {},
    {},
    {
        params ["_target", "_caller", "_actionId", "_arguments"];
        [_target] call MSIED_fnc_initMinefield;
    },
    {},
    [],
    3,
    5.9,
    true,
    false
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
    5.95,
    true,
    true,
    "",
    "_this distance _target < 4 && (_target getVariable ['MSIED_Debug', false]) && !(_target getVariable ['MSIED_Defused', false]) && !(_target getVariable ['MSIED_Detonated', false])"
];

_ied setVariable ["MSIED_DebugDefuseId", _debugDefuseId];
