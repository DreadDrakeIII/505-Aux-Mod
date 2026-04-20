#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_cancelBuild
 * Cancels active building mode, cleans up all event handlers and state.
 * buildRotation/buildPitch/buildBank intentionally preserved for repeat builds.
 */

// Ghost object
if (!isNil QGVAR(buildingObject)) then {
    deleteVehicle GVAR(buildingObject);
    GVAR(buildingObject) = nil;
};

// Event handlers
if (!isNil QGVAR(buildEH)) then {
    removeMissionEventHandler ["EachFrame", GVAR(buildEH)];
    GVAR(buildEH) = nil;
};
if (!isNil QGVAR(buildKeyEH)) then {
    (findDisplay 46) displayRemoveEventHandler ["KeyDown", GVAR(buildKeyEH)];
    GVAR(buildKeyEH) = nil;
};
if (!isNil QGVAR(buildKeyUpEH)) then {
    (findDisplay 46) displayRemoveEventHandler ["KeyUp", GVAR(buildKeyUpEH)];
    GVAR(buildKeyUpEH) = nil;
};
if (!isNil QGVAR(buildMouseEH)) then {
    (findDisplay 46) displayRemoveEventHandler ["MouseButtonDown", GVAR(buildMouseEH)];
    GVAR(buildMouseEH) = nil;
};
if (!isNil QGVAR(buildScrollEH)) then {
    (findDisplay 46) displayRemoveEventHandler ["MouseZChanged", GVAR(buildScrollEH)];
    GVAR(buildScrollEH) = nil;
};

// FIX 4: Restore engineer scroll action now that build mode is exiting
[] call FUNC(addEngineerAction);

// PiP camera
if (!isNil QGVAR(buildCamera) && { !isNull GVAR(buildCamera) }) then {
    GVAR(buildCamera) cameraEffect ["terminate", "back"];
    camDestroy GVAR(buildCamera);
    GVAR(buildCamera) = nil;
};
"OLI_engtools_camLayer" cutFadeOut 0;
GVAR(buildCameraEnabled) = false;

// FIX 5: Auto-hide HUD on cancel
["hide"] call FUNC(buildHUD);

// General state
GVAR(buildClassname)     = nil;
GVAR(canPlaceObject)     = nil;
GVAR(buildBoost)         = false;
GVAR(buildHeightMode)    = false;
GVAR(buildDistMode)      = false;
GVAR(buildSnapToGround)  = false;
GVAR(buildVectorSurface) = false;
GVAR(buildSnapBaseDir)   = nil;
GVAR(buildSnapLocked)    = nil;
GVAR(buildSnapNudge)     = 0;

// buildRotation, buildPitch, buildBank intentionally preserved
