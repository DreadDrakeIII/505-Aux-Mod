/*
 * Local sink for automessages.
 * This function is intended to be remoteExec'd to specific clients.
 */
params ["_speaker", "_message"];

if (!FEF_AutoMessages_Enabled) exitWith {};

// remoteExecCall to group so ALL members see the message
[_speaker, _message] remoteExecCall ["groupChat", group _speaker];
