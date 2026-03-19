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

deleteVehicle _logic;

if (isNull _target) exitWith {
    hint "No vehicle found for Eject Occupants.";
};

if !(_target isKindOf "AllVehicles") exitWith {
    hint "Target is not a vehicle.";
};

private _crew = crew _target;

{
    unassignVehicle _x;
    moveOut _x;
} forEach _crew;

private _msg = format [
    "ejectOccupants: Ejected %1 occupant(s) from '%2'.",
    count _crew,
    typeOf _target
];
LOG(_msg);