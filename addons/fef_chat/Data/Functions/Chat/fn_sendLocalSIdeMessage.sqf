/*
 * Local sink for side-channel alerts.
 * Intended to be remoteExec'd to specific recipients.
 */
params ["_speaker", "_message"];

_speaker sideChat _message;
