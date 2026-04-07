params ["_message", ["_speaker", player]];

private _resolved = _message;
private _bearing = round (getDir _speaker);
private _direction = _bearing call FEF_fnc_getDirFromBearing;
private _weaponClass = primaryWeapon _speaker;
if (_weaponClass isEqualTo "") then {
    _weaponClass = currentWeapon _speaker;
};

private _weaponName = if (_weaponClass isEqualTo "") then {
    "weapon"
} else {
    getText (configFile >> "CfgWeapons" >> _weaponClass >> "displayName")
};

if (_weaponName isEqualTo "") then {
    _weaponName = _weaponClass;
};

_resolved = [_resolved, "[bearing]", str _bearing] call FEF_fnc_stringReplace;
_resolved = [_resolved, "[direction]", _direction] call FEF_fnc_stringReplace;
_resolved = [_resolved, "[weapon]", _weaponName] call FEF_fnc_stringReplace;
_resolved = [_resolved, "[name]", name _speaker] call FEF_fnc_stringReplace;

_resolved
