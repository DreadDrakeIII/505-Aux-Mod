#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_cancelBuild
 * Cancels active building mode, cleans up all event handlers.
 * Note: buildRotation, buildPitch, buildBank intentionally KEPT
 *       so repeat placements inherit the last-used orientation.
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

if (!isNil QGVAR(buildScrollEH)) then {
    (findDisplay 46) displayRemoveEventHandler ["MouseZChanged", GVAR(buildScrollEH)];
    GVAR(buildScrollEH) = nil;
};

GVAR(buildClassname) = nil;
GVAR(canPlaceObject) = nil;

// Snap state cleanup
GVAR(buildSnapBaseDir) = nil;
GVAR(buildSnapLocked) = nil;

// buildRotation, buildPitch, buildBank intentionally preserved

hint "";
