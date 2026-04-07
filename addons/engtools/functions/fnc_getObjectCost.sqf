#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_getObjectCost
 * Returns the resource cost for a given classname.
 * Anything not listed falls through to DEFAULT_RESOURCE_COST (20).
 *
 * Parameters:
 *   _classname - Object classname
 *
 * Returns: Number (cost)
 */

params [["_classname", "", [""]]];

private _costs = createHashMapFromArray [
    // ── OPTRE BARRIERS ───────────────────────────────────────────
    ["Land_OPTRE_M72S_barrier",              10],
    ["OPTRE_Ridgco_Barrier_One",             5],   // Barrier One
    ["OPTRE_Ridgco_Barrier_Three",           12.5],   // Barrier Three
    ["OPTRE_Ridgco_Barrier_Four",            12.5],   // Barrier Four
    ["OPTRE_Ridgco_Barrier_Five",            12.5],   // Barrier Five
    ["OPTRE_Ridgco_Barrier_Tower",          25],   // Barrier Tower
    ["OPTRE_Ridgco_Barrier_Tunnel",         12.5],   // Barrier Tunnel

    // ── WALLS & RAMPS ────────────────────────────────────────────
    ["OPTRE_Ridgco_Barrier_Ramp",            5],   // Barrier Ramp
    ["OPTRE_Ridgco_Barrier_Corner",          12.5],   // Corner
    ["OPTRE_Ridgco_Barrier_Corner_Inverted", 12.5],   // Corner Inverted
    ["OPTRE_Ridgco_Barrier_Wall_Short",      12.5],   // Wall Short
    ["OPTRE_Ridgco_Barrier_Wall_Long",       12.5],   // Wall Long
    ["OPTRE_Ridgco_Barrier_Wall_Ramp",       12.5],   // Wall Ramp

    // ── TKE EQUIPMENT ────────────────────────────────────────────
    ["land_TKE_DeployableCover",             5],   // Deployable Cover
    ["land_TKE_HalfBunker",                 10],   // Half Bunker
    ["land_TKE_RoadBarrier",                5],   // Road Barrier
    ["land_TKE_TankTrap",                  12.5],   // Tank Trap
    ["land_TKE_MilLight",                  5]    // Mil Light
];

private _cost = _costs getOrDefault [_classname, DEFAULT_RESOURCE_COST];

_cost
