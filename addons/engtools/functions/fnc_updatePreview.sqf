#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_updatePreview
 *
 * Updates the right-column preview panel.
 *
 * When a classname is provided: hides the placeholder, shows the image
 *   border + image + name + description, and formats the cost line with
 *   affordability colouring based on the side's current resource pool.
 *
 * When called with "": shows the placeholder, hides the preview contents.
 *
 * Layout (see config.cpp two-column layout):
 *   - IDC_PREVIEW_IMG_BORDER  — panel background (matches dialog body)
 *   - IDC_PREVIEW_IMAGE       — the thumbnail (0.272W × 0.300H)
 *   - IDC_PREVIEW_NAME        — display name, bold, centred
 *   - IDC_PREVIEW_DESC        — description + cost, structured, centred
 *   - IDC_PREVIEW_PLACEHOLDER — shown when nothing is selected
 */

params [
    ["_classname",   "", [""]],
    ["_displayName", "", [""]],
    ["_description", "", [""]]
];

disableSerialization;

private _display = findDisplay IDD_ENGINEER_DIALOG;
if (isNull _display) exitWith {};

private _borderCtrl = _display displayCtrl IDC_PREVIEW_IMG_BORDER;
private _imgCtrl    = _display displayCtrl IDC_PREVIEW_IMAGE;
private _nameCtrl   = _display displayCtrl IDC_PREVIEW_NAME;
private _descCtrl   = _display displayCtrl IDC_PREVIEW_DESC;
private _phCtrl     = _display displayCtrl IDC_PREVIEW_PLACEHOLDER;

// Empty state: show placeholder, hide the preview widgets
if (_classname isEqualTo "") exitWith {
    if (!isNull _borderCtrl) then { _borderCtrl ctrlShow false; };
    if (!isNull _imgCtrl)    then { _imgCtrl    ctrlShow false; _imgCtrl ctrlSetText ""; };
    if (!isNull _nameCtrl)   then { _nameCtrl   ctrlShow false; _nameCtrl ctrlSetText ""; };
    if (!isNull _descCtrl)   then { _descCtrl   ctrlShow false; };
    if (!isNull _phCtrl)     then { _phCtrl     ctrlShow true;  };
};

// Populated state: hide placeholder, show preview widgets
if (!isNull _phCtrl)     then { _phCtrl     ctrlShow false; };
if (!isNull _borderCtrl) then { _borderCtrl ctrlShow true;  };
if (!isNull _imgCtrl)    then { _imgCtrl    ctrlShow true;  };
if (!isNull _nameCtrl)   then { _nameCtrl   ctrlShow true;  };
if (!isNull _descCtrl)   then { _descCtrl   ctrlShow true;  };

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

// Cost line + description (structured text, centred)
private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
private _costLine = "";

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
        _costLine = format [
            "<t align='center' color='#55CC66' size='1.15'>Cost: %1</t><br/><t align='center' color='#AAAAAA' size='0.95'>(%2 %3 pool)</t>",
            _cost, _currentRes, _sideLabel
        ];
    } else {
        _costLine = format [
            "<t align='center' color='#FF4444' size='1.15'>Cost: %1</t><br/><t align='center' color='#FF6666' size='0.95'>(Need %2 more)</t>",
            _cost, _cost - _currentRes
        ];
    };
};

if (!isNull _descCtrl) then {
    _descCtrl ctrlSetStructuredText parseText format [
        "%1<br/><br/><t align='center' color='#BBC9BE' size='1.0'>%2</t>",
        _costLine, _description
    ];
};
