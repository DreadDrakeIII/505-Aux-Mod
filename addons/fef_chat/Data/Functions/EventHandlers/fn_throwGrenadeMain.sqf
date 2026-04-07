params ["_unit", "_magazine"];

if (!FEF_AutoMessages_Enabled) exitWith {};
if (!FEF_AutoMessages_Grenades) exitWith {};
if (!isPlayer _unit) exitWith {};

private _mag = toLower _magazine;
private _message = "";
private _voiceKey = "";

["Grenade EH fired - magazine: " + _mag] call FEF_fnc_devLog;

if ((_mag find "smoke") >= 0) then {
    _message = "Smoke out!";
    _voiceKey = "ThrowSmoke";
} else {
    if (
        (_mag find "grenade")     >= 0 ||
        (_mag find "frag")        >= 0 ||
        (_mag find "m67")         >= 0 ||
        (_mag find "handgrenade") >= 0 ||
        (_mag find "optre_")      >= 0 ||
        (_mag find "_grenade")    >= 0 ||
        (_mag find "thermal")     >= 0 ||
        (_mag find "incendiary")  >= 0 ||
        (_mag find "flashbang")   >= 0 ||
        (_mag find "flash")       >= 0
    ) then {
        _message = "Grenade out!";
        _voiceKey = "ThrowGrenade";
    };
};

if (_message isEqualTo "") exitWith {
    ["No matching magazine type - mag was: " + _mag] call FEF_fnc_devLog;
};

["Sending callout: " + _message] call FEF_fnc_devLog;

// Get nearby players + include self so thrower sees their own callout
private _recipients = [getPosATL _unit, FEF_Voice_VoiceRadius, false] call FEF_fnc_getNearbyPlayers;
_recipients pushBackUnique _unit;

["Recipients count: " + str (count _recipients)] call FEF_fnc_devLog;

{
    [_unit, _message] remoteExecCall ["FEF_fnc_sendLocalMessage", _x];
} forEach _recipients;

if (!FEF_Voice_EnableVoiceLines) exitWith {};

private _soundClass = [_voiceKey] call FEF_fnc_resolveVoiceLine;
if (_soundClass isEqualTo "") exitWith {};

{
    [netId _unit, _soundClass, FEF_Voice_VoiceRadius] remoteExecCall ["FEF_fnc_playLocalVoiceLine", _x];
} forEach _recipients;
