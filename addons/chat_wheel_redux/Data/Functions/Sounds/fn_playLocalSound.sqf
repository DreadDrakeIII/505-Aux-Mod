/*
 * Authors: Leopard20
 * Edited by DartRuffian, RevGamer
 */

params ["_file", "_source"];

if (!CWR_Voice_EnableVoiceLines) exitWith {};

private _soundSource = if (typeName _source == "STRING") then {
    objectFromNetId _source
} else {
    _source
};

if (isNull _soundSource) exitWith {};

playSound3D [
    _file,
    _soundSource,
    false,
    getPosASL _soundSource,
    CWR_Voice_VoiceVolume,
    1,
    0,
    0,
    true
];
