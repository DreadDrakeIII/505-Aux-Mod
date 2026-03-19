#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_initEngineerMenu
 * Initializes the engineering tools menu
 *
 * REQUIRES: OLI_Combat_Engineer_Toolkit in inventory
 * OPEN: Scroll wheel action OR Ctrl+F1 keybind
 */

// Function to add the scroll wheel action
FUNC(addEngineerAction) = {
    // Remove old action if it exists
    if (!isNil QGVAR(engineerActionID)) then {
        player removeAction GVAR(engineerActionID);
    };

    // Add scroll wheel action
    GVAR(engineerActionID) = player addAction [
        "<t color='#FFA500'><img image='\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\repair_ca.paa'/> Engineer Tools</t>",
        {[] call FUNC(openEngineerMenu)},
        nil,
        1.5,
        false,
        true,
        "",
        "'OLI_Combat_Engineer_Toolkit' in items player"
    ];
};

// Wait for player to be ready
waitUntil {!isNull player};
waitUntil {player == player};

// Add action initially
[] call FUNC(addEngineerAction);

// Re-add action on respawn (critical for multiplayer)
player addEventHandler ["Respawn", {
    [] call FUNC(addEngineerAction);
}];

// CBA keybind (Ctrl+F1)
if (isClass (configFile >> "CfgPatches" >> "cba_keybinding")) then {
    [
        "505th Expeditionary Force Aux Mod",
        QGVAR(openMenu),
        "Open Engineer Tools",
        {
            if ("OLI_Combat_Engineer_Toolkit" in items player) then {
                [] call FUNC(openEngineerMenu);
            } else {
                hint "Requires 505th Combat Engineer Toolkit";
            };
        },
        {},
        [0x3B, [false, true, false]]
    ] call CBA_fnc_addKeybind;
};
