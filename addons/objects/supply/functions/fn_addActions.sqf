// OLI_SUPPLY - attach ONE scroll-wheel action to a console: "Open Supply
// Menu". Selecting it opens the custom top-left resupply menu (fn_openMenu)
// instead of listing every crate type directly on the vanilla/ACE action
// list. The menu itself reads OLI_Supply_Actions live every time it draws,
// so turning an option on/off in the addon options is reflected the next
// time the menu opens - the action itself no longer needs a rebuild for
// that (only OLI_Supply_ActionRadius still does - see fn_wireConsoles).
//
// The placeable console class gets this automatically. For any other prop use
// OLI_Supply_fnc_registerConsole on the server instead of calling this
// directly - the server has to know the object is a console before it will
// honour requests aimed at it.
//
// Arguments: 0: object <OBJECT>
// Return: action IDs <ARRAY>

params [["_console", objNull]];

if (!hasInterface) exitWith {[]};
if (isNull _console) exitWith {[]};
if !(isNil {_console getVariable "OLI_Supply_ActionIDs"}) exitWith {
    _console getVariable ["OLI_Supply_ActionIDs", []]
};

if (isNil "OLI_Supply_LocalConsoles") then {OLI_Supply_LocalConsoles = []};

private _radius = missionNamespace getVariable ["OLI_Supply_ActionRadius", 4];

// Reuses the ammo icon already shipped with this sub-component (see
// fn_preInit.sqf's ICON_AMMO) as a generic "resupply" symbol for the single
// menu-opening action.
private _icon   = "\BLU\OLI\addons\objects\supply\data\ammo.paa";
private _title  = format ["<img image='%1' size='1.5' shadow=2 /> <t>Open Supply Menu</t>", _icon];
private _window = format ["<img image='%1' size='2.5' shadow=2 /> <t>Open Supply Menu</t>", _icon];

private _id = _console addAction [
    _title,
    {
        params ["_target", "_caller", "_actionId", "_arguments"];
        [_target] call OLI_Supply_fnc_openMenu;
    },
    [],                                                       // arguments (unused - single action now)
    1.5,                                                      // priority
    true,                                                      // showWindow - on-screen prompt, no scrolling needed
    true,                                                      // hideOnUse - re-added by the class/registerConsole flow the same as before
    "",                                                        // shortcut
    "alive _this && {isNull objectParent _this}",              // condition (_this = caller)
    _radius,                                                   // radius (m)
    false,                                                     // unconscious
    "",                                                        // selection
    ""                                                         // memoryPoint
];

_console setUserActionText [_id, _title, _window];

private _ids = [_id];
_console setVariable ["OLI_Supply_ActionIDs", _ids];
OLI_Supply_LocalConsoles pushBackUnique _console;

_ids
