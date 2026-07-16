// OLI_KCS - SERVER: delete all tracked patients of a computer.
//
// Arguments: 0: computer <OBJECT>

params ["_computer"];

{
    if (!isNull _x) then { deleteVehicle _x; };
} forEach (_computer getVariable ["OLI_KCS_ActivePatients", []]);

_computer setVariable ["OLI_KCS_ActivePatients", [], true];
