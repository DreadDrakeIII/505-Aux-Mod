if (!hasInterface) exitWith {};

["ace_firedPlayer", {
    params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile"];
    [_unit, _magazine] call FEF_fnc_throwGrenadeMain;
}] call CBA_fnc_addEventHandler;
