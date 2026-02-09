#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_cancelBuild
 * Cancels building and cleans up
 */

if (!isNil QGVAR(buildingObject)) then {
    deleteVehicle GVAR(buildingObject);
    GVAR(buildingObject) = nil;
};

if (!isNil QGVAR(buildEH)) then {
    removeMissionEventHandler ["EachFrame", GVAR(buildEH)];
    GVAR(buildEH) = nil;
};

if (!isNil QGVAR(buildKeyEH)) then {
    (findDisplay 46) displayRemoveEventHandler ["KeyDown", GVAR(buildKeyEH)];
    GVAR(buildKeyEH) = nil;
};

if (!isNil QGVAR(buildMouseEH)) then {
    (findDisplay 46) displayRemoveEventHandler ["MouseButtonDown", GVAR(buildMouseEH)];
    GVAR(buildMouseEH) = nil;
};

GVAR(buildClassname) = nil;
GVAR(buildRotation) = nil;
GVAR(canPlaceObject) = nil;

hint "";
