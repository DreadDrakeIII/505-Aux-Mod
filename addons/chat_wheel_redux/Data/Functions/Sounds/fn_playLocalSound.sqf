/*
 * Authors: Leopard20
 * Edited by DartRuffian
 * Determines which sound effect should play based on user settings, then plays that sound effect.
 *
 * Arguments:
 * 0: Sound file <STRING>
 * 1: Sound source (object to attach sound to) <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * ["file.ogg", player] call CWR_fnc_playLocalSound;
 */

params ["_file", "_source"];

if (CWR_Voice_EnableVoiceLines) then {
    playSound3D [
        _file,
        _source,
        false,
        getPosASL _source,
        CWR_Voice_VoiceVolume,
        1,
        0,
        0,
        true
    ];
};