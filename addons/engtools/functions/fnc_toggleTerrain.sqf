#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_toggleTerrain
 * Toggles Level Terrain mode ON/OFF.
 */

disableSerialization;
if (isNil "OLI_engtools_levelTerrain") then { OLI_engtools_levelTerrain = true; };
OLI_engtools_levelTerrain = !OLI_engtools_levelTerrain;

private _display = findDisplay IDD_ENGINEER_DIALOG;
if (!isNull _display) then {
    private _ctrl = _display displayCtrl IDC_TERRAIN_TOGGLE;
    if (!isNull _ctrl) then {
        if (OLI_engtools_levelTerrain) then {
            _ctrl ctrlSetText "[ON] LEVEL TERRAIN";
            _ctrl ctrlSetBackgroundColor [0.10, 0.36, 0.16, 1.0];
        } else {
            _ctrl ctrlSetText "[OFF] LEVEL TERRAIN";
            _ctrl ctrlSetBackgroundColor [0.18, 0.14, 0.10, 1.0];
        };
    };
};
