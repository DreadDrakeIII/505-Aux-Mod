params ["_message"];

private _final = format ["[FEF Chat] %1", _message];
if (missionNamespace getVariable ["FEF_Debug_ShowMessages", false]) then {
    systemChat _final;
};
diag_log _final;
