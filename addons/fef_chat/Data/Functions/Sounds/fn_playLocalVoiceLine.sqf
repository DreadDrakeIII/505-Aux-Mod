params ["_speakerSource", "_soundClass", ["_maxDistance", 35]];

if (!FEF_Voice_EnableVoiceLines) exitWith {};
if (_soundClass isEqualTo "") exitWith {};

private _speaker = if (_speakerSource isEqualType "") then {
    objectFromNetId _speakerSource
} else {
    _speakerSource
};

if (isNull _speaker) exitWith {};

_speaker say3D [_soundClass, _maxDistance, 1, 1];
