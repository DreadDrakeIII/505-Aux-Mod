#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_initResources
 * Initializes the shared side resource pools on the server.
 * Clients receive values via publicVariable broadcast.
 * Resources are now SHARED per side (WEST / EAST / GUER), not per-player.
 */

if (!hasInterface && !isServer) exitWith {};

// ── Server: initialize pool variables and broadcast ─────────────────────────
if (isServer) then {
    private _defaultAmount = missionNamespace getVariable [QGVAR(setting_defaultResources), 100];

    // Only initialize if not already set (mission maker may pre-set via initServer.sqf)
    if (isNil QGVAR(res_WEST)) then {
        missionNamespace setVariable [QGVAR(res_WEST), _defaultAmount];
        publicVariable QGVAR(res_WEST);
    };
    if (isNil QGVAR(res_EAST)) then {
        missionNamespace setVariable [QGVAR(res_EAST), _defaultAmount];
        publicVariable QGVAR(res_EAST);
    };
    if (isNil QGVAR(res_GUER)) then {
        missionNamespace setVariable [QGVAR(res_GUER), _defaultAmount];
        publicVariable QGVAR(res_GUER);
    };
};

if (!hasInterface) exitWith {};

// ── Client: wait for player then request a sync ─────────────────────────────
waitUntil {!isNull player};
waitUntil {player == player};

// If server variables haven't arrived yet (JIP), poll until they do
waitUntil {
    !isNil QGVAR(res_WEST) && !isNil QGVAR(res_EAST) && !isNil QGVAR(res_GUER)
};
