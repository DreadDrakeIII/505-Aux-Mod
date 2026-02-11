#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_heightUp
 * Raises build height by 0.10m and refreshes the display.
 */

if (isNil "OLI_engtools_buildHeight") then { OLI_engtools_buildHeight = 0; };

OLI_engtools_buildHeight = parseNumber (str (round ((OLI_engtools_buildHeight + 0.10) * 100) / 100));

private _display = findDisplay IDD_ENGINEER_DIALOG;
if (!isNull _display) then {
    private _ctrl = _display displayCtrl IDC_HEIGHT_DISPLAY;
    if (!isNull _ctrl) then {
        _ctrl ctrlSetText format ["%1m", OLI_engtools_buildHeight];
    };
};
