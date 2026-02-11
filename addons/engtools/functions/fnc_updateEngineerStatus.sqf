#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_updateEngineerStatus
 * Refreshes the status bar at the bottom of the tablet.
 */

disableSerialization;

private _display = findDisplay IDD_ENGINEER_DIALOG;
if (isNull _display) exitWith {};

private _ctrl = _display displayCtrl IDC_STATUS_TEXT;
if (isNull _ctrl) exitWith {};

private _count    = if (!isNil QGVAR(builtObjects)) then { count GVAR(builtObjects) } else { 0 };
private _toolkit  = if ("OLI_Combat_Engineer_Toolkit" in items player) then {
    "<t color='#55CC66'>EQUIPPED</t>"
} else {
    "<t color='#CC4444'>MISSING</t>"
};
private _height   = if (!isNil "OLI_engtools_buildHeight")  then { OLI_engtools_buildHeight  } else { 0 };
private _terrain  = if (!isNil "OLI_engtools_levelTerrain") then { OLI_engtools_levelTerrain } else { true };
private _snap     = if (!isNil "OLI_engtools_snapActive")   then { OLI_engtools_snapActive   } else { false };

private _terrainStr = if (_terrain) then { "<t color='#55CC66'>ON</t>"  } else { "<t color='#CC4444'>OFF</t>" };
private _snapStr    = if (_snap)    then { "<t color='#5599FF'>ON</t>"  } else { "<t color='#888888'>OFF</t>" };

_ctrl ctrlSetStructuredText parseText format [
    "<t align='center'>Objects Built: <t color='#DDDDDD'>%1</t>  |  Toolkit: %2  |  Height: <t color='#DDDDDD'>%3m</t>  |  Terrain: %4  |  Snap: %5</t>",
    _count, _toolkit, _height, _terrainStr, _snapStr
];
