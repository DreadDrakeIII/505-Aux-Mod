/*
 * Runs on the speaker's machine — calls groupChat so Arma replicates to the rest of the group.
 * Used when the caller (e.g. casualty) can't broadcast group chat themselves.
 */
params ["_speaker", "_message"];

if (!FEF_AutoMessages_Enabled) exitWith {};
if (isNull _speaker) exitWith {};

_speaker groupChat _message;
