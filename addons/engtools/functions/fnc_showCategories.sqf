#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_showCategories
 * Returns to category view — called by [< Back] button only.
 */

disableSerialization;
private _display = findDisplay IDD_ENGINEER_DIALOG;
if (isNull _display) exitWith {};

// Reset the scroll-vs-hover lock on the listbox. If the user scrolled the
// previous category's list, went Back, and picked a new category, we don't
// want the lock to carry over and block hover-preview on the new list.
private _lb = _display displayCtrl IDC_OBJ_LIST;
if (!isNull _lb) then { _lb setVariable ["OLI_scrollLock", false]; };

(_display displayCtrl IDC_OBJ_LIST)      ctrlShow false;
(_display displayCtrl IDC_CAT_BACK)      ctrlShow false;
(_display displayCtrl IDC_CAT_BUILD)     ctrlShow false;
(_display displayCtrl IDC_CAT_LABEL)     ctrlSetText "";
(_display displayCtrl IDC_CAT_TITLE)     ctrlShow true;
(_display displayCtrl IDC_CAT_BARRIER)   ctrlShow true;
(_display displayCtrl IDC_CAT_STRUCTURE) ctrlShow true;
(_display displayCtrl IDC_CAT_MISC)      ctrlShow true;

[] call FUNC(updatePreview);
