#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_showObjectList
 * Populates the scrollable object list for the selected category.
 *
 * Parameters:
 *   _category - "Barrier" | "Structure" | "Misc"  [STRING]
 *
 * To add objects: add entries to the relevant array below.
 * Format: [classname, display name, description]
 *
 * Category assignments:
 *   Barrier   — Half Bunker, M72S Barrier, Deployable Cover
 *   Structure — Ridge Block One/Three/Four/Five, Ramp, Corner,
 *               Corner Inverted, Short Wall, Long Wall, Wall Ramp, Tower, Tunnel
 *   Misc      — Road Barrier, Tank Trap, Field Light
 */

params [["_category", "Barrier", [""]]];

private _objects = switch (_category) do {
    case "Barrier": {[
        ["land_TKE_HalfBunker",           "Half Bunker",          "Partial bunker fortification."],
        ["Land_OPTRE_M72S_barrier",       "M72S Barrier",         "UNSC modular barrier section."],
        ["land_TKE_DeployableCover",      "Deployable Cover",     "Portable ballistic cover."]
    ]};
    case "Structure": {[
        ["OPTRE_Ridgco_Barrier_One",           "Ridge Block One",       "Ridgco single barrier unit."],
        ["OPTRE_Ridgco_Barrier_Three",         "Ridge Block Three",     "Ridgco triple-width barrier."],
        ["OPTRE_Ridgco_Barrier_Four",          "Ridge Block Four",      "Ridgco quad-width barrier."],
        ["OPTRE_Ridgco_Barrier_Five",          "Ridge Block Five",      "Ridgco five-wide barrier."],
        ["OPTRE_Ridgco_Barrier_Ramp",          "Ridge Block Ramp",      "Vehicle access ramp."],
        ["OPTRE_Ridgco_Barrier_Corner",        "Corner Block",          "Right-angle corner section."],
        ["OPTRE_Ridgco_Barrier_Corner_Inverted","Corner Inverted",      "Inverse corner for inner walls."],
        ["OPTRE_Ridgco_Barrier_Wall_Short",    "Short Wall Block",      "Short wall segment."],
        ["OPTRE_Ridgco_Barrier_Wall_Long",     "Long Wall Block",       "Long wall segment."],
        ["OPTRE_Ridgco_Barrier_Wall_Ramp",     "Wall Block Ramp",       "Ridgco wall ramp section."],
        ["OPTRE_Ridgco_Barrier_Tower",         "Ridge Block Tower",     "Elevated watch tower section."],
        ["OPTRE_Ridgco_Barrier_Tunnel",        "Ridge Block Tunnel",    "Covered tunnel passthrough."]
    ]};
    case "Misc": {[
        ["land_TKE_RoadBarrier",          "Road Barrier",         "Vehicle blocking road barrier."],
        ["land_TKE_TankTrap",             "Tank Trap",            "Anti-vehicle tank trap."],
        ["land_TKE_MilLight",             "Field Light",          "TKE military light post."]
    ]};
    default { [] };
};

disableSerialization;
private _display = findDisplay IDD_ENGINEER_DIALOG;
if (isNull _display) exitWith {};

// Hide category buttons and the "CATEGORY" column title. The breadcrumb
// label (IDC_CAT_LABEL) sits on top of IDC_CAT_TITLE at the same coords,
// so hiding the title lets the breadcrumb "Category > Barrier" show in
// its place without overlap.
(_display displayCtrl IDC_CAT_BARRIER)   ctrlShow false;
(_display displayCtrl IDC_CAT_STRUCTURE) ctrlShow false;
(_display displayCtrl IDC_CAT_MISC)      ctrlShow false;
(_display displayCtrl IDC_CAT_TITLE)     ctrlShow false;

// Show back button and breadcrumb
(_display displayCtrl IDC_CAT_BACK)  ctrlShow true;
(_display displayCtrl IDC_CAT_LABEL) ctrlSetText format ["Category  >  %1", _category];

// Populate listbox
private _lb = _display displayCtrl IDC_OBJ_LIST;
lbClear _lb;

// Reset scroll-vs-hover lock — fresh list should respond to hover, even
// if the user scrolled a previous category's list before going Back.
_lb setVariable ["OLI_scrollLock", false];

{
    _x params ["_cls", "_name", "_desc"];
    private _idx = _lb lbAdd _name;
    _lb lbSetData    [_idx, _cls];
    _lb lbSetTooltip [_idx, _desc];
} forEach _objects;

(_display displayCtrl IDC_OBJ_LIST) ctrlShow true;

// Give the listbox keyboard focus + mouse focus so scroll wheel cycling
// and the Enter-to-commit handler work immediately. Without ctrlSetFocus,
// Enter keydowns would bubble to the display and our onKeyDown wouldn't
// fire until the user clicked the list once.
ctrlSetFocus _lb;

// Auto-preview first item
if (count _objects > 0) then {
    (_objects select 0) params ["_cls", "_name", "_desc"];
    [_cls, _name, _desc] call FUNC(updatePreview);
};

// Legacy BUILD button — kept hidden. New workflow: click a list row to start placing.
(_display displayCtrl IDC_CAT_BUILD) ctrlShow false;
