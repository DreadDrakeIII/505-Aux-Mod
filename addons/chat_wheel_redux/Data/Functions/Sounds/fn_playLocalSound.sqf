/*
 * Authors: Leopard20
 * Edited by DartRuffian, RevGamer
 */

params ["_file", "_source"];

if (!CWR_Voice_EnableVoiceLines) exitWith {};

// Convert network ID to object if needed
private _soundSource = if (typeName _source == "STRING") then {
    objectFromNetId _source  // Convert network ID to object
} else {
    _source  // Already an object
};

// Verify we have a valid object
if (isNull _soundSource) exitWith {};

playSound3D [
    _file,
    _soundSource,              // Now it's an object!
    false,
    getPosASL _soundSource,    // This works now!
    CWR_Voice_VoiceVolume,
    1,
    0,
    0,
    true
];