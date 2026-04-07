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

private _previewMap = createHashMapFromArray [
    ["OPTRE_Ridgco_Barrier_One",             "\BLU\OLI\addons\engtools\data\Preview\Ridge_Block_One.paa"],
    ["OPTRE_Ridgco_Barrier_Three",           "\BLU\OLI\addons\engtools\data\Preview\Ridge_Block_Three.paa"],
    ["OPTRE_Ridgco_Barrier_Four",            "\BLU\OLI\addons\engtools\data\Preview\Ridge_Block_Four.paa"],
    ["OPTRE_Ridgco_Barrier_Five",            "\BLU\OLI\addons\engtools\data\Preview\Ridge_Block_Five.paa"],
    ["OPTRE_Ridgco_Barrier_Ramp",            "\BLU\OLI\addons\engtools\data\Preview\Ridge_Block_Ramp.paa"],
    ["OPTRE_Ridgco_Barrier_Corner",          "\BLU\OLI\addons\engtools\data\Preview\Corner_Ridge_Wall_Block.paa"],
    ["OPTRE_Ridgco_Barrier_Corner_Inverted", "\BLU\OLI\addons\engtools\data\Preview\Corner_Ridge_Wall_Block_Inverted.paa"],
    ["OPTRE_Ridgco_Barrier_Wall_Short",      "\BLU\OLI\addons\engtools\data\Preview\Short_Ridge_Wall_Block.paa"],
    ["OPTRE_Ridgco_Barrier_Wall_Long",       "\BLU\OLI\addons\engtools\data\Preview\Long_Ridge_Wall_Block.paa"],
    ["OPTRE_Ridgco_Barrier_Wall_Ramp",       "\BLU\OLI\addons\engtools\data\Preview\Ridge_Wall_Block_Ramp.paa"],
    ["OPTRE_Ridgco_Barrier_Tower",           "\BLU\OLI\addons\engtools\data\Preview\Ridge_Block_Tower.paa"],
    ["OPTRE_Ridgco_Barrier_Tunnel",          "\BLU\OLI\addons\engtools\data\Preview\Ridge_Block_Tunnel.paa"],
    ["Land_OPTRE_M72S_barrier",              "\BLU\OLI\addons\engtools\data\Preview\M72_MB_S.paa"],
    ["land_TKE_DeployableCover",             "\BLU\OLI\addons\engtools\data\Preview\Deployable_Cover.paa"],
    ["land_TKE_HalfBunker",                  "\BLU\OLI\addons\engtools\data\Preview\Half_Bunker.paa"],
    ["land_TKE_RoadBarrier",                 "\BLU\OLI\addons\engtools\data\Preview\Road_Barrier.paa"],
    ["land_TKE_TankTrap",                    "\BLU\OLI\addons\engtools\data\Preview\Tank_Trap.paa"],
    ["land_TKE_MilLight",                    "\BLU\OLI\addons\engtools\data\Preview\Field_Light.paa"]
];

private _imagePath = _previewMap getOrDefault [_classname, ""];

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
