#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_updateEngineerStatus
 * Refreshes the status bar — now shows shared side resource pool.
 */

disableSerialization;

private _display = findDisplay IDD_ENGINEER_DIALOG;
if (isNull _display) exitWith {};

private _ctrl = _display displayCtrl IDC_STATUS_TEXT;
if (isNull _ctrl) exitWith {};

private _count   = if (!isNil QGVAR(builtObjects)) then { count GVAR(builtObjects) } else { 0 };
private _toolkit = if ("OLI_Combat_Engineer_Toolkit" in items player) then {
    "<t color='#55CC66'>EQUIPPED</t>"
} else {
    "<t color='#CC4444'>MISSING</t>"
};
private _height  = if (!isNil "OLI_engtools_buildHeight")  then { OLI_engtools_buildHeight  } else { 0 };
private _terrain = if (!isNil "OLI_engtools_levelTerrain") then { OLI_engtools_levelTerrain } else { true };
private _snap    = if (!isNil "OLI_engtools_snapActive")   then { OLI_engtools_snapActive   } else { false };

private _terrainStr = if (_terrain) then { "<t color='#55CC66'>ON</t>"  } else { "<t color='#CC4444'>OFF</t>" };
private _snapStr    = if (_snap)    then { "<t color='#5599FF'>ON</t>"  } else { "<t color='#888888'>OFF</t>" };

private _pitch = if (!isNil QGVAR(buildPitch)) then { GVAR(buildPitch) } else { 0 };
private _bank  = if (!isNil QGVAR(buildBank))  then { GVAR(buildBank)  } else { 0 };
private _rotStr = if (_pitch != 0 || _bank != 0) then {
    format ["  |  Pitch: <t color='#CC88FF'>%1°</t>  Bank: <t color='#CC88FF'>%2°</t>", _pitch, _bank]
} else { "" };

// ── Shared side resource display ─────────────────────────────────────────────
private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
private _resStr = "";
if (_resourcesEnabled) then {
    private _playerSide = side player;
    private _resources  = [_playerSide] call FUNC(getSideResources);
    private _sideLabel  = switch (_playerSide) do {
        case WEST:        {"BLUFOR"};
        case EAST:        {"OPFOR"};
        case INDEPENDENT: {"INDFOR"};
        default           {"SIDE"};
    };
    private _resColor = if (_resources > 0) then { "#FFAA00" } else { "#FF4444" };
    _resStr = format ["  |  %1 Pool: <t color='%2'>%3</t>", _sideLabel, _resColor, _resources];
};

_ctrl ctrlSetStructuredText parseText format [
    "<t align='center'>Objects Built: <t color='#DDDDDD'>%1</t>  |  Toolkit: %2  |  Height: <t color='#DDDDDD'>%3m</t>  |  Terrain: %4  |  Snap: %5%6%7</t>",
    _count, _toolkit, _height, _terrainStr, _snapStr, _rotStr, _resStr
];

// ── Resource display control (top-right of dialog) ──────────────────────────
private _resCtrl = _display displayCtrl IDC_RESOURCE_DISPLAY;
if (!isNull _resCtrl && _resourcesEnabled) then {
    private _resources = [side player] call FUNC(getSideResources);
    _resCtrl ctrlSetText format ["⬡ %1", _resources];
};
