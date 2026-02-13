#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_toggleAutoLevel
 * Toggles auto-level mode ON/OFF.
 *
 * AUTO LEVEL: Objects align to terrain surface slope.
 *   - Green ghost  = flat/gentle (0-15°) — safe to build
 *   - Yellow ghost = moderate slope (15-30°) — auto-leveled
 *   - Red ghost    = too steep (30°+) — placement blocked
 */

disableSerialization;

if (isNil "OLI_engtools_autoLevel") then { OLI_engtools_autoLevel = false; };

OLI_engtools_autoLevel = !OLI_engtools_autoLevel;

private _display = findDisplay IDD_ENGINEER_DIALOG;
if (!isNull _display) then {
    private _ctrl = _display displayCtrl IDC_AUTOLEVEL_TOGGLE;
    if (!isNull _ctrl) then {
        if (OLI_engtools_autoLevel) then {
            _ctrl ctrlSetText "[ON]  AUTO LEVEL";
            _ctrl ctrlSetBackgroundColor [0.08, 0.14, 0.45, 1.0];
            _ctrl ctrlSetTextColor       [0.70, 0.85, 1.00, 1.0];
        } else {
            _ctrl ctrlSetText "[OFF] AUTO LEVEL";
            _ctrl ctrlSetBackgroundColor [0.14, 0.10, 0.30, 1.0];
            _ctrl ctrlSetTextColor       [0.55, 0.55, 0.80, 1.0];
        };
    };
};

systemChat format ["[Engineer] Auto Level: %1", ["OFF","ON"] select OLI_engtools_autoLevel];
