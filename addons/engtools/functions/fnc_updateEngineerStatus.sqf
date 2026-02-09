#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_updateEngineerStatus
 * Updates the status bar
 */

disableSerialization;

private _display = findDisplay IDD_ENGINEER_DIALOG;
if (isNull _display) exitWith {};

private _statusCtrl = _display displayCtrl IDC_STATUS_TEXT;
if (isNull _statusCtrl) exitWith {};

private _builtObjects = if (isNil QGVAR(builtObjects)) then {0} else {count GVAR(builtObjects)};
private _hasToolkit = "OLI_Combat_Engineer_Toolkit" in items player;

private _toolkitStatus = if (_hasToolkit) then {
    "<t color='#00FF00'>EQUIPPED</t>"
} else {
    "<t color='#FF4444'>MISSING</t>"
};

private _statusText = format [
    "<t align='center'>Built objects: %1 | Toolkit: %2</t>",
    _builtObjects,
    _toolkitStatus
];

_statusCtrl ctrlSetStructuredText parseText _statusText;
