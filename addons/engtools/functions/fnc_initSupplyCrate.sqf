#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_initSupplyCrate
 * Adds an ACE Interact action to an engineer supply crate.
 * - Engineer trait gated (ACE interact condition)
 * - +50 to side resource pool
 * - Crate deletes on use
 *
 * Notes:
 * - Must set ACE cargo variables to prevent ACE interact_menu "Type String, expected Number" errors
 *   when crates are dynamically created (e.g. unloaded from pallet)
 * - ACE interact action added per-object via ace_interact_menu_fnc_addActionToObject
 *   (NOT addActionToClass — these are dynamically spawned objects, not pre-placed)
 * - Hint is sent to all players on that side when collected
 * - Double-init guard to prevent duplicate actions if function is accidentally called multiple times on same crate
 *   (e.g. if both initSupplyCrate and initSupplyPallet functions are used, or if pallets are reused after unloading)
 * - If crates are dynamically created (e.g. from unloading supply pallet), initSupplyCrate function must be called on them
 *   to set cargo variables and add action, either by:
 *     * Calling initSupplyCrate from ACE cargo unloaded event handler (recommended)
 *     * Or by calling initSupplyCrate from a loop that checks for new crates (not recommended — less efficient and may
 *       miss crates if not frequent enough)
 */

params [["_crate", objNull, [objNull]]];
if (isNull _crate) exitWith {};

if (_crate getVariable ["OLI_engtools_crateInit", false]) exitWith {};
_crate setVariable ["OLI_engtools_crateInit", true, true];

// Explicitly set ACE cargo variables to prevent type errors
// canLoad MUST be boolean — ACE uses && which expects Bool, not Number
_crate setVariable ["ace_cargo_size", 6];
_crate setVariable ["ace_cargo_canLoad", true];

// ── ACE Interact action — Collect Engineer Supplies ──────────────────────────
// Only runs on machines with interface (players)
if (!hasInterface) exitWith {};

// Statement — runs when player activates the action
// Passed [_target, _player, _params] by ACE
private _statement = {
    params ["_target", "_player", "_params"];

    private _side    = side _player;
    private _current = [_side] call OLI_engtools_fnc_getSideResources;
    private _newTotal = _current + 50;

    [_side, _newTotal] remoteExec ["OLI_engtools_fnc_setSideResources", 2];

    private _sideLabel = switch (_side) do {
        case WEST:        {"BLUFOR"};
        case EAST:        {"OPFOR"};
        case INDEPENDENT: {"INDFOR"};
        default           {"Unknown"};
    };

    // Notify all players on the same side
    {
        if (side _x == _side && isPlayer _x) then {
            [parseText format [
                "<t color='#FFA500'>Engineer Supplies Collected</t><br/>" +
                "<t color='#55CC66'>+50 resources added to %1 pool</t><br/>" +
                "<t color='#FFAA00'>New total: %2</t>",
                _sideLabel, _newTotal
            ]] remoteExec ["hintSilent", _x];
        };
    } forEach allPlayers;

    // Delete the crate
    [_target] remoteExec ["deleteVehicle", 2];
};

// Condition — Engineers only (505th permission system), with resources enabled
// Uses OLI_main_fnc_isEngineer which checks the 505th custom engineer variable
// Passed [_target, _player, _params] by ACE
private _condition = {
    params ["_target", "_player", "_params"];
    (missionNamespace getVariable ["OLI_engtools_setting_enableResources", true])
    && { _player call OLI_main_fnc_isEngineer }
};

// Create ACE action and add to crate
// createAction args: [actionName, displayName, icon, statement, condition, insertChildren, params, position, distance, otherParams]
private _action = [
    "OLI_CollectSupplies",
    "Collect Engineer Supplies (+50)",
    "\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\repair_ca.paa",
    _statement,
    _condition,
    {},         // insertChildren
    [],         // params
    [0, 0, 0],  // position (model center)
    4           // interaction distance
] call ace_interact_menu_fnc_createAction;

// Type 0 = external action (interact with object), parent path = ACE_MainActions
[_crate, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;
