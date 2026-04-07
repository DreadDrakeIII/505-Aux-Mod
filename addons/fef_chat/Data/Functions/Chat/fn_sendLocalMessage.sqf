/*
 * Local sink for automessages.
 * This function is intended to be remoteExec'd to specific clients.
 */
params ["_speaker", "_message"];

if (!FEF_AutoMessages_Enabled) exitWith {};
_speaker groupChat _message;
