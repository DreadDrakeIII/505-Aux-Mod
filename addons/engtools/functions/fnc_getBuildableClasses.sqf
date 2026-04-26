#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_getBuildableClasses
 *
 * Single source of truth for the buildable object catalogue. Returns the
 * full list grouped by category, as [[classname, displayName, desc], ...].
 *
 * Called by:
 *   - fnc_showObjectList:   builds the listbox contents per category
 *   - fnc_preloadModels:    warms every model at mission start
 *
 * Adding a new object = one edit here. Do NOT duplicate this list elsewhere.
 *
 * Parameters:
 *   _category - "Barrier" | "Structure" | "Misc" | "All"  [STRING, default "All"]
 *
 * Returns:
 *   Array of [classname, displayName, description] entries.
 */

params [["_category", "All", [""]]];

private _barrier = [
    ["land_TKE_HalfBunker",           "Half Bunker",          "Partial bunker fortification."],
    ["Land_OPTRE_M72S_barrier",       "M72S Barrier",         "UNSC modular barrier section."],
    ["land_TKE_DeployableCover",      "Deployable Cover",     "Portable ballistic cover."]
];

private _structure = [
    ["OPTRE_Ridgco_Barrier_One",            "Ridge Block One",       "Ridgco single barrier unit."],
    ["OPTRE_Ridgco_Barrier_Three",          "Ridge Block Three",     "Ridgco triple-width barrier."],
    ["OPTRE_Ridgco_Barrier_Four",           "Ridge Block Four",      "Ridgco quad-width barrier."],
    ["OPTRE_Ridgco_Barrier_Five",           "Ridge Block Five",      "Ridgco five-wide barrier."],
    ["OPTRE_Ridgco_Barrier_Ramp",           "Ridge Block Ramp",      "Vehicle access ramp."],
    ["OPTRE_Ridgco_Barrier_Corner",         "Corner Block",          "Right-angle corner section."],
    ["OPTRE_Ridgco_Barrier_Corner_Inverted","Corner Inverted",       "Inverse corner for inner walls."],
    ["OPTRE_Ridgco_Barrier_Wall_Short",     "Short Wall Block",      "Short wall segment."],
    ["OPTRE_Ridgco_Barrier_Wall_Long",      "Long Wall Block",       "Long wall segment."],
    ["OPTRE_Ridgco_Barrier_Wall_Ramp",      "Wall Block Ramp",       "Ridgco wall ramp section."],
    ["OPTRE_Ridgco_Barrier_Tower",          "Ridge Block Tower",     "Elevated watch tower section."],
    ["OPTRE_Ridgco_Barrier_Tunnel",         "Ridge Block Tunnel",    "Covered tunnel passthrough."]
];

private _misc = [
    ["land_TKE_RoadBarrier",          "Road Barrier",         "Vehicle blocking road barrier."],
    ["land_TKE_TankTrap",             "Tank Trap",            "Anti-vehicle tank trap."],
    ["land_TKE_MilLight",             "Field Light",          "TKE military light post."]
];

switch (_category) do {
    case "Barrier":   { _barrier };
    case "Structure": { _structure };
    case "Misc":      { _misc };
    case "All":       { _barrier + _structure + _misc };
    default           { [] };
};
