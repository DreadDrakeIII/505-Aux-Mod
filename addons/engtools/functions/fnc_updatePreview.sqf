#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_updatePreview
 * Updates the preview panel — cost checked against side pool.
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

if (_classname isEqualTo "") exitWith {
    if (!isNull _imgCtrl)  then { _imgCtrl ctrlSetText "" };
    if (!isNull _nameCtrl) then { _nameCtrl ctrlSetText "Hover an object to preview  |  Select to begin building" };
    if (!isNull _descCtrl) then { _descCtrl ctrlSetStructuredText parseText "<t align='left' color='#888888'>Select an object from the list above to begin placement.</t>" };
};

private _imagePath = getText (configFile >> "CfgVehicles" >> _classname >> "editorPreview");
if (_imagePath isEqualTo "") then {
    _imagePath = format ["\A3\EditorPreviews_F\Data\CfgVehicles\%1.jpg", _classname];
};

if (!isNull _imgCtrl)  then { _imgCtrl ctrlSetText _imagePath };
if (!isNull _nameCtrl) then { _nameCtrl ctrlSetText _displayName };

private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
private _costStr = "";

if (_resourcesEnabled) then {
    private _cost       = [_classname] call FUNC(getObjectCost);
    private _playerSide = side player;
    private _currentRes = [_playerSide] call FUNC(getSideResources);
    private _canAfford  = _currentRes >= _cost;
    private _sideLabel  = switch (_playerSide) do {
        case WEST:        {"BLUFOR"};
        case EAST:        {"OPFOR"};
        case INDEPENDENT: {"INDFOR"};
        default           {"SIDE"};
    };

    if (_canAfford) then {
        _costStr = format [
            "  <t color='#55CC66'>|  Cost: %1</t>  <t color='#AAAAAA'>(%2 %3 pool)</t>",
            _cost, _currentRes, _sideLabel
        ];
    } else {
        _costStr = format [
            "  <t color='#FF4444'>|  Cost: %1</t>  <t color='#FF6666'>(Need %2 more)</t>",
            _cost, _cost - _currentRes
        ];
    };
};

if (!isNull _descCtrl) then {
    _descCtrl ctrlSetStructuredText parseText format [
        "<t align='left' color='#CCCCCC' size='1.1'>%1</t>%2",
        _description, _costStr
    ];
};
