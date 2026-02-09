#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_openEngineerMenu
 * Opens the engineer tools dialog
 */

if !("OLI_Combat_Engineer_Toolkit" in items player) exitWith {
    hint "Requires 505th Combat Engineer Toolkit";
};

// Cancel any active building
if (!isNil QGVAR(buildingObject)) then {
    [] call FUNC(cancelBuild);
};

createDialog QGVAR(dialog);

[] spawn {
    sleep 0.1;
    [] call FUNC(updateEngineerStatus);
};
