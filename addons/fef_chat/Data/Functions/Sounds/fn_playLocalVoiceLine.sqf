params ["_speakerSource", "_soundClass", ["_maxDistance", 35]];

if (!FEF_Voice_EnableVoiceLines) exitWith {};
if (_soundClass isEqualTo "") exitWith {};

private _speaker = if (_speakerSource isEqualType "") then {
    objectFromNetId _speakerSource
} else {
    _speakerSource
};

if (isNull _speaker) exitWith {};

private _volume = if (isNil "FEF_Voice_Volume") then { 1.0 } else { FEF_Voice_Volume };
private _scaledDistance = _maxDistance * _volume;

_speaker say3D [_soundClass, _scaledDistance, 1, 1];
