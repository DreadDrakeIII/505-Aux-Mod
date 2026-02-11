#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_updatePreview
 * Updates the preview panel on hover.
 * Called with no args to clear the panel.
 */

params [
    ["_classname",   "", [""]],
    ["_displayName", "", [""]],
    ["_description", "", [""]]
];

disableSerialization;

private _display = findDisplay IDD_ENGINEER_DIALOG;
if (isNull _display) exitWith {};

private _imgCtrl  = _display displayCtrl IDC_PREVIEW_IMAGE;
private _nameCtrl = _display displayCtrl IDC_PREVIEW_NAME;
private _descCtrl = _display displayCtrl IDC_PREVIEW_DESC;

// Clear state when called with no object
if (_classname isEqualTo "") exitWith {
    if (!isNull _imgCtrl)  then { _imgCtrl ctrlSetText "" };
    if (!isNull _nameCtrl) then { _nameCtrl ctrlSetText "Hover an object to preview  |  Select to begin building" };
    if (!isNull _descCtrl) then { _descCtrl ctrlSetStructuredText parseText "<t align='left' color='#888888'>Select an object from the list above to begin placement.</t>" };
};

// Find editor preview image
private _imagePath = getText (configFile >> "CfgVehicles" >> _classname >> "editorPreview");
if (_imagePath isEqualTo "") then {
    _imagePath = format ["\A3\EditorPreviews_F\Data\CfgVehicles\%1.jpg", _classname];
};

if (!isNull _imgCtrl)  then { _imgCtrl ctrlSetText _imagePath };
if (!isNull _nameCtrl) then { _nameCtrl ctrlSetText _displayName };
if (!isNull _descCtrl) then {
    _descCtrl ctrlSetStructuredText parseText format [
        "<t align='left' color='#CCCCCC' size='1.1'>%1</t>",
        _description
    ];
};
