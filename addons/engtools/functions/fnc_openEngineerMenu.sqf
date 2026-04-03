#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_openEngineerMenu
 * Opens the Combat Engineer Tool Tablet dialog.
 * Resource display now shows shared side pool.
 */

if !("OLI_Combat_Engineer_Toolkit" in items player) exitWith {
    hint "Requires 505th Combat Engineer Toolkit";
};

if (!isNil QGVAR(buildingObject)) then { [] call FUNC(cancelBuild); };
if (!isNil QGVAR(demolishActive)) then { [] call FUNC(cancelDemolish); };

if (isNil "OLI_engtools_buildHeight")  then { OLI_engtools_buildHeight  = 0;     };
if (isNil "OLI_engtools_levelTerrain") then { OLI_engtools_levelTerrain = true;  };
if (isNil "OLI_engtools_snapActive")   then { OLI_engtools_snapActive   = false; };

createDialog QGVAR(dialog);

[] spawn {
    sleep 0.1;
    private _display = findDisplay IDD_ENGINEER_DIALOG;
    if (isNull _display) exitWith {};

    // Height display
    private _hCtrl = _display displayCtrl IDC_HEIGHT_DISPLAY;
    if (!isNull _hCtrl) then {
        private _hStr = str OLI_engtools_buildHeight;
        if ((_hStr find ".") == -1) then { _hStr = _hStr + ".0"; };
        _hCtrl ctrlSetText (_hStr + "m");
    };

    // Level Terrain toggle
    private _tCtrl = _display displayCtrl IDC_TERRAIN_TOGGLE;
    if (!isNull _tCtrl) then {
        if (OLI_engtools_levelTerrain) then {
            _tCtrl ctrlSetText "[ON] LEVEL TERRAIN";
            _tCtrl ctrlSetBackgroundColor [0.10, 0.36, 0.16, 1.0];
        } else {
            _tCtrl ctrlSetText "[OFF] LEVEL TERRAIN";
            _tCtrl ctrlSetBackgroundColor [0.18, 0.14, 0.10, 1.0];
        };
    };

    // Snap toggle
    private _sCtrl = _display displayCtrl IDC_SNAP_TOGGLE;
    if (!isNull _sCtrl) then {
        if (OLI_engtools_snapActive) then {
            _sCtrl ctrlSetText "[ON]  SNAP";
            _sCtrl ctrlSetBackgroundColor [0.08, 0.18, 0.45, 1.0];
        } else {
            _sCtrl ctrlSetText "[OFF] SNAP";
            _sCtrl ctrlSetBackgroundColor [0.10, 0.14, 0.30, 1.0];
        };
    };

    // Resource display — side pool
    private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
    private _resCtrl = _display displayCtrl IDC_RESOURCE_DISPLAY;
    if (!isNull _resCtrl) then {
        if (_resourcesEnabled) then {
            private _resources = [side player] call FUNC(getSideResources);
            _resCtrl ctrlSetText format ["⬡ %1", _resources];
        } else {
            _resCtrl ctrlSetText "⬡ FREE";
            _resCtrl ctrlSetTextColor [0.5, 0.8, 0.5, 1];
        };
    };

    [] call FUNC(updateEngineerStatus);
};
