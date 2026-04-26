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

// Pull class list from the single source of truth. fnc_getBuildableClasses
// also supplies fnc_preloadModels with the same classnames so they can't
// drift out of sync — add new objects there, not here.
private _objects = [_category] call FUNC(getBuildableClasses);

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
