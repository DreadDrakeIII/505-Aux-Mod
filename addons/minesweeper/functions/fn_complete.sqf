params [["_ied", objNull, [objNull]]];

if (isNull _ied) exitWith {};

// Play success sound FIRST (before anything else)
playSound3D ["\BLU\OLI\addons\minesweeper\sounds\success.ogg", _ied, false, getPosASL _ied, 5, 1, 50];

// Close dialog
closeDialog 55500;

// Clear player's disarming variable
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

// Server handles: setting variables, removing debug flag
if (isServer) then {
    _ied setVariable ["MSIED_Defuser", objNull, true];
    _ied setVariable ["MSIED_Defused", true, true];
    _ied setVariable ["MSIED_Detonated", true, true];

    private _debugFlag = _ied getVariable ["MSIED_DebugFlag", objNull];
    if (!isNull _debugFlag) then {
        deleteVehicle _debugFlag;
    };

    // Remove from JIP queue
    remoteExecCall ["", _ied];
} else {
    [_ied] remoteExec ["MSIED_fnc_completeServer", 2];
};
