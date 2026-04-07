if (isNull player) exitWith {};

private _existing = player getVariable ["FEF_GrenadeEH", -1];
if (_existing >= 0) then {
    player removeEventHandler ["Fired", _existing];
};

private _ehId = player addEventHandler ["Fired", {
    params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
    [_unit, _magazine] call FEF_fnc_throwGrenadeMain;
}];

player setVariable ["FEF_GrenadeEH", _ehId];
