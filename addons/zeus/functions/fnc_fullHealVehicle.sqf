#include "..\script_component.hpp"

params [
    ["_logic", objNull, [objNull]],
    ["_units", [], [[]]],
    ["_activated", true, [true]]
];

if (!_activated) exitWith {};

private _target = objNull;

if (count _units > 0) then {
    _target = _units select 0;
};

if (isNull _target) then {
    _target = attachedTo _logic;
};

if (isNull _target) then {
    private _near = (getPosATL _logic) nearEntities ["AllVehicles", 5];
    if (count _near > 0) then {
        _target = _near select 0;
    };
};

// Capture Zeus owner before deleteVehicle removes the curator object
private _zeusOwner = -1;
{
    if (_logic in (getAssignedCuratorLogic _x)) then {
        _zeusOwner = owner _x;
    };
} forEach allPlayers;

deleteVehicle _logic;

if (isNull _target) exitWith {
    if (_zeusOwner > 0) then {
        "No vehicle found for Full Heal Vehicle." remoteExec ["hint", _zeusOwner];
    };
};

if !(_target isKindOf "AllVehicles") exitWith {
    if (_zeusOwner > 0) then {
        "Target is not a vehicle." remoteExec ["hint", _zeusOwner];
    };
};

_target setDamage 0;
_target setFuel 1;

private _hitPointsData = getAllHitPointsDamage _target;
private _hitPoints = [];

if (_hitPointsData isEqualType [] && {count _hitPointsData > 0}) then {
    _hitPoints = _hitPointsData select 0;
};

{
    _target setHitPointDamage [_x, 0, true];
} forEach _hitPoints;

{
    _x setDamage 0;
} forEach crew _target;

private _msg = format [
    "fullHealVehicle: Repaired '%1' and healed %2 occupant(s).",
    typeOf _target,
    count (crew _target)
];
LOG(_msg);
