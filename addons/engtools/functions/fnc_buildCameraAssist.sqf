#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_buildCameraAssist
 * Top-down PiP camera for build mode.
 *
 * Parameters:
 *   _enable - true = create/show, false = destroy [BOOL, default true]
 *
 * Called automatically:
 *   [true]  on fnc_buildObject entry
 *   [false] on fnc_cancelBuild AND on engineer dialog onUnload
 *
 * NOTES:
 *   - Use cutFadeOut 0 to remove a cutRsc layer — "RemoveRsc" does not exist
 *   - Use camSetPos (not setPosASL) to position a PiP camera
 *   - Camera must NOT be attached to anything for PiP to render correctly
 *   - setVectorDirAndUp [[0,0,-1],[0,1,0]] = pointing straight down
 */

params [["_enable", true, [false]]];

if (_enable) then {

    // Show PiP overlay
    "OLI_engtools_camLayer" cutRsc ["OLI_engtools_BuildPiP", "PLAIN", 0, false];

    // Create camera if needed
    if (isNil QGVAR(buildCamera) || { isNull GVAR(buildCamera) }) then {
        private _pos = if (!isNil QGVAR(buildingObject) && { !isNull GVAR(buildingObject) }) then {
            ASLToAGL (getPosASL GVAR(buildingObject)) vectorAdd [0, 0, 20]
        } else {
            getPosATL player vectorAdd [0, 0, 20]
        };
        GVAR(buildCamera) = "camera" camCreate _pos;
    };

    // Point straight down — do NOT use attachTo with PiP cameras
    GVAR(buildCamera) setVectorDirAndUp [[0, 0, -1], [0, 1, 0]];

    // camCommit 0 = immediate commit required before cameraEffect
    GVAR(buildCamera) camCommit 0;

    // Assign camera to PiP render target
    GVAR(buildCamera) cameraEffect ["Internal", "Back", "OLI_engtools_rtt"];

    // Auto night-vision on PiP when dark
    if (sunOrMoon < 1) then {
        "OLI_engtools_rtt" setPiPEffect [1];
    } else {
        "OLI_engtools_rtt" setPiPEffect [0];
    };

    cameraEffectEnableHUD true;
    GVAR(buildCameraEnabled) = true;

} else {

    // Destroy camera
    if (!isNil QGVAR(buildCamera) && { !isNull GVAR(buildCamera) }) then {
        GVAR(buildCamera) cameraEffect ["terminate", "back"];
        camDestroy GVAR(buildCamera);
        GVAR(buildCamera) = nil;
    };

    // Remove PiP overlay — cutFadeOut 0, NOT cutRsc ["RemoveRsc",...]
    "OLI_engtools_camLayer" cutFadeOut 0;

    GVAR(buildCameraEnabled) = false;
};
