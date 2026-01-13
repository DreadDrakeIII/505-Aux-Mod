// Server-side completion handler
// Called from client when they complete defusal

params [["_ied", objNull, [objNull]]];

if (isNull _ied) exitWith {};
if (!isServer) exitWith {};

_ied setVariable ["MSIED_Defuser", objNull, true];
_ied setVariable ["MSIED_Defused", true, true];
_ied setVariable ["MSIED_Detonated", true, true];

private _debugFlag = _ied getVariable ["MSIED_DebugFlag", objNull];
if (!isNull _debugFlag) then {
    deleteVehicle _debugFlag;
};

// Remove from JIP queue
remoteExecCall ["", _ied];
