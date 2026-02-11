#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_cancelDemolish
 * Cleans up demolish mode event handlers.
 */

GVAR(demolishActive) = nil;

if (!isNil QGVAR(demolishEH)) then {
    removeMissionEventHandler ["EachFrame", GVAR(demolishEH)];
    GVAR(demolishEH) = nil;
};

if (!isNil QGVAR(demolishMouseEH)) then {
    (findDisplay 46) displayRemoveEventHandler ["MouseButtonDown", GVAR(demolishMouseEH)];
    GVAR(demolishMouseEH) = nil;
};

// Scroll handler (added v8)
if (!isNil QGVAR(demolishScrollEH)) then {
    (findDisplay 46) displayRemoveEventHandler ["MouseZChanged", GVAR(demolishScrollEH)];
    GVAR(demolishScrollEH) = nil;
};

hint "";
