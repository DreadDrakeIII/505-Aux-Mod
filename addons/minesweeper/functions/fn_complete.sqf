params [["_ied", objNull, [objNull]]];

if (isNull _ied) exitWith {};

// Close dialog immediately (local)
closeDialog 55500;

// Clear player's disarming variable (local)
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

// Play success sound
playSound3D ["\minesweeper_ied\sounds\success.ogg", _ied, false, getPosASL _ied, 5, 1, 50];

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
    // Client: ask server to finalize
    [_ied] remoteExec ["MSIED_fnc_completeServer", 2];
};
