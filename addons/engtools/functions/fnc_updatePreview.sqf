#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_updatePreview
 * Updates the preview panel on hover
 */

params [
    ["_classname", "", [""]],
    ["_displayName", "", [""]],
    ["_description", "", [""]]
];

disableSerialization;

private _display = findDisplay IDD_ENGINEER_DIALOG;
if (isNull _display) exitWith {};

private _imgCtrl = _display displayCtrl IDC_PREVIEW_IMAGE;
private _nameCtrl = _display displayCtrl IDC_PREVIEW_NAME;
private _descCtrl = _display displayCtrl IDC_PREVIEW_DESC;

private _imagePath = getText (configFile >> "CfgVehicles" >> _classname >> "editorPreview");
if (_imagePath isEqualTo "") then {
    _imagePath = format ["\A3\EditorPreviews_F\Data\CfgVehicles\%1.jpg", _classname];
};

_imgCtrl ctrlSetText _imagePath;
_nameCtrl ctrlSetText _displayName;
_descCtrl ctrlSetStructuredText parseText format ["<t align='center' color='#AAAAAA'>%1</t>", _description];
