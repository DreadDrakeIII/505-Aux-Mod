#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_toggleSnap
 * Toggles wall-snap mode ON/OFF and updates the button colour.
 *
 * SNAP behaviour (when ON):
 *   During placement the ghost preview auto-locks to the nearest endpoint
 *   of any already-placed object within 5 m.  The new piece inherits the
 *   snapped wall's direction so lines stay perfectly straight.
 *
 *   Visual:   ________| ← new piece snaps here
 */

disableSerialization;

if (isNil "OLI_engtools_snapActive") then { OLI_engtools_snapActive = false; };

OLI_engtools_snapActive = !OLI_engtools_snapActive;

private _display = findDisplay IDD_ENGINEER_DIALOG;
if (!isNull _display) then {
    private _ctrl = _display displayCtrl IDC_SNAP_TOGGLE;
    if (!isNull _ctrl) then {
        if (OLI_engtools_snapActive) then {
            _ctrl ctrlSetText "[ON]  SNAP";
            _ctrl ctrlSetBackgroundColor [0.08, 0.18, 0.45, 1.0];
            _ctrl ctrlSetTextColor       [0.70, 0.88, 1.00, 1.0];
        } else {
            _ctrl ctrlSetText "[OFF] SNAP";
            _ctrl ctrlSetBackgroundColor [0.10, 0.14, 0.30, 1.0];
            _ctrl ctrlSetTextColor       [0.55, 0.65, 0.80, 1.0];
        };
    };
};

systemChat format ["[Engineer] Snap mode: %1", ["OFF","ON"] select OLI_engtools_snapActive];
