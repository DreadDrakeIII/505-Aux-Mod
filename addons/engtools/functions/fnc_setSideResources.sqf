#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_setSideResources
 * Sets the shared resource pool for a given side.
 * Must be called on the server (or remoteExec'd to server).
 * Broadcasts the new value to all clients via publicVariable.
 *
 * Parameters:
 *   _side   - Side (WEST, EAST, INDEPENDENT)
 *   _amount - New resource total (clamped >= 0)
 */

params [
    ["_side",   WEST, [WEST]],
    ["_amount", 0,    [0]]
];

_amount = _amount max 0;

private _varName = switch (_side) do {
    case WEST:        { QGVAR(res_WEST) };
    case EAST:        { QGVAR(res_EAST) };
    case INDEPENDENT: { QGVAR(res_GUER) };
    default           { QGVAR(res_WEST) };
};

missionNamespace setVariable [_varName, _amount];
publicVariable _varName;
