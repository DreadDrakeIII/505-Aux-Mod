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
    ["Land_OPTRE_M72S_barrier",              3],
    ["OPTRE_Ridgco_Barrier_One",             1],   // Barrier One
    ["OPTRE_Ridgco_Barrier_Three",           2],   // Barrier Three
    ["OPTRE_Ridgco_Barrier_Four",            4],   // Barrier Four
    ["OPTRE_Ridgco_Barrier_Five",            5],   // Barrier Five
    ["OPTRE_Ridgco_Barrier_Tower",          20],   // Barrier Tower
    ["OPTRE_Ridgco_Barrier_Tunnel",         15],   // Barrier Tunnel

    // ── WALLS & RAMPS ────────────────────────────────────────────
    ["OPTRE_Ridgco_Barrier_Ramp",            1],   // Barrier Ramp
    ["OPTRE_Ridgco_Barrier_Corner",          6],   // Corner
    ["OPTRE_Ridgco_Barrier_Corner_Inverted", 6],   // Corner Inverted
    ["OPTRE_Ridgco_Barrier_Wall_Short",      5],   // Wall Short
    ["OPTRE_Ridgco_Barrier_Wall_Long",       7],   // Wall Long
    ["OPTRE_Ridgco_Barrier_Wall_Ramp",       4],   // Wall Ramp

    // ── TKE EQUIPMENT ────────────────────────────────────────────
    ["land_TKE_DeployableCover",             3],   // Deployable Cover
    ["land_TKE_HalfBunker",                 5],   // Half Bunker
    ["land_TKE_RoadBarrier",                2],   // Road Barrier
    ["land_TKE_TankTrap",                   4],   // Tank Trap
    ["land_TKE_MilLight",                   1]    // Mil Light
];

private _cost = _costs getOrDefault [_classname, DEFAULT_RESOURCE_COST];

_cost
