#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_getSideResources
 * Returns the shared resource pool for a given side.
 *
 * Parameters:
 *   _side - Side (WEST, EAST, INDEPENDENT, etc.)
 *
 * Returns: Number
 */

params [["_side", WEST, [WEST]]];

private _varName = switch (_side) do {
    case WEST:        { QGVAR(res_WEST) };
    case EAST:        { QGVAR(res_EAST) };
    case INDEPENDENT: { QGVAR(res_GUER) };
    default           { QGVAR(res_WEST) };
};

missionNamespace getVariable [_varName, 0]
