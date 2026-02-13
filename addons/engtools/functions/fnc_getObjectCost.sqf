#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_getObjectCost
 * Returns the resource cost for a given classname.
 * All objects currently cost DEFAULT_RESOURCE_COST (20).
 * Expand the hash below to assign per-object costs later.
 *
 * Parameters:
 *   _classname - Object classname
 *
 * Returns: Number (cost)
 */

params [["_classname", "", [""]]];

// ── Per-object cost overrides (expand later) ────────────────────────────────
// Format: classname -> cost
// Anything not listed falls through to the default.
private _costs = createHashMapFromArray [
    // ["Land_OPTRE_M72S_barrier",   15],
    // ["OPTRE_Ridgco_Barrier_Tower", 35],
    // Add custom costs here as needed
];

private _cost = _costs getOrDefault [_classname, DEFAULT_RESOURCE_COST];

_cost
