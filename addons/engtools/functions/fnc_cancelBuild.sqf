#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_cancelBuild
 * Cancels active building mode, cleans up all event handlers.
 * Note: buildRotation is intentionally KEPT so repeat placements
 *       inherit the last-used angle.
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

// Scroll wheel handler (added in v8)
if (!isNil QGVAR(buildScrollEH)) then {
    (findDisplay 46) displayRemoveEventHandler ["MouseZChanged", GVAR(buildScrollEH)];
    GVAR(buildScrollEH) = nil;
};

GVAR(buildClassname) = nil;
GVAR(canPlaceObject) = nil;
// buildRotation intentionally preserved for next repeat placement

hint "";
