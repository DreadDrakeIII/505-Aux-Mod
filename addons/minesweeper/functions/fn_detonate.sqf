params [
    ["_ied", objNull, [objNull]],
    ["_isFailure", false, [false]]
];

if (isNull _ied) exitWith {};

// Check if already detonated or defused
private _detonated = _ied getVariable ["MSIED_Detonated", false];
private _defused = _ied getVariable ["MSIED_Defused", false];

if (_detonated || _defused) exitWith {};

// Close dialog immediately if open
closeDialog 55500;

// Clear local player variable if we're the defuser
player setVariable ["MSIED_disarmingObj", objNull, false];

// Remove local actions
private _actionId = _ied getVariable ["MSIED_ActionId", -1];
if (_actionId >= 0) then {
    [_ied, _actionId] call BIS_fnc_holdActionRemove;
};

private _inspectId = _ied getVariable ["MSIED_InspectId", -1];
if (_inspectId >= 0) then {
    _ied removeAction _inspectId;
};

private _debugDefuseId = _ied getVariable ["MSIED_DebugDefuseId", -1];
if (_debugDefuseId >= 0) then {
    _ied removeAction _debugDefuseId;
};

// Reset local action flag so actions can be re-added if IED is reused
_ied setVariable ["MSIED_ActionsAdded_Local", false];

// If we're server, handle detonation directly
// If we're client, ask server to handle it
if (isServer) then {
    [_ied, _isFailure] call MSIED_fnc_detonateServer;
} else {
    [_ied, _isFailure] remoteExec ["MSIED_fnc_detonateServer", 2];
};
