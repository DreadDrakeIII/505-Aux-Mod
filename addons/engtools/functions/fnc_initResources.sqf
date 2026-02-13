#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_initResources
 * Initializes the resource system for the local player.
 * Reads the CBA setting for default resources and applies it.
 * Re-initializes on respawn.
 */

if (!hasInterface) exitWith {};

waitUntil {!isNull player};
waitUntil {player == player};

// Set initial resources from CBA setting (default 100)
private _defaultAmount = missionNamespace getVariable [QGVAR(setting_defaultResources), 100];

// Only set if not already initialized (preserves Zeus-granted resources)
if (isNil {player getVariable QGVAR(resources)}) then {
    player setVariable [QGVAR(resources), _defaultAmount, true];
};

// Re-initialize on respawn
player addEventHandler ["Respawn", {
    private _defaultAmount = missionNamespace getVariable [QGVAR(setting_defaultResources), 100];
    player setVariable [QGVAR(resources), _defaultAmount, true];
    systemChat format ["[Engineer] Resources reset to %1", _defaultAmount];
}];

diag_log format ["[OLI Engineering] Resources initialized: %1 for %2",
    player getVariable [QGVAR(resources), 0], name player];
