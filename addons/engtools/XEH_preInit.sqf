#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

// Initialize globals
GVAR(builtObjects) = [];

// Deploy handlers — custom code array that can block placement
// Mission makers add functions via: OLI_engtools_deployHandlers pushBack { ... };
// Each handler receives [_unit, _object, _classname] and must return true to allow.
GVAR(deployHandlers) = [];

// Build locations — area restriction system
// If empty, building is allowed everywhere.
// If populated, player must be inside at least one area.
// Supports: marker names, trigger objects, or array format [center, a, b, angle, isRect, c]
// Mission makers add via: OLI_engtools_buildLocations pushBack "marker_fob_1";
GVAR(buildLocations) = [];

// ============================================================================
// CBA SETTINGS – Engineering Tools
// ============================================================================

[
    QGVAR(setting_defaultResources),
    "SLIDER",
    ["Default Engineer Resources", "The starting amount of build resources each player receives on spawn."],
    ["505th Expeditionary Force Aux Mod", "Engineering Tools"],
    [0, 500, 100, 0],
    1,
    {},
    false
] call CBA_fnc_addSetting;

[
    QGVAR(setting_resourceCost),
    "SLIDER",
    ["Default Build Cost", "The base resource cost per object placed. Individual objects may override this."],
    ["505th Expeditionary Force Aux Mod", "Engineering Tools"],
    [0, 200, 20, 0],
    1,
    {},
    false
] call CBA_fnc_addSetting;

[
    QGVAR(setting_buildTime),
    "SLIDER",
    ["Build Time (seconds)", "How long it takes to construct each object. Set to 0 for instant placement."],
    ["505th Expeditionary Force Aux Mod", "Engineering Tools"],
    [0, 60, 5, 0],
    1,
    {},
    false
] call CBA_fnc_addSetting;

[
    QGVAR(setting_demolishTime),
    "SLIDER",
    ["Demolish Time (seconds)", "How long it takes to demolish each object. Set to 0 for instant removal."],
    ["505th Expeditionary Force Aux Mod", "Engineering Tools"],
    [0, 60, 5, 0],
    1,
    {},
    false
] call CBA_fnc_addSetting;

[
    QGVAR(setting_enableResources),
    "CHECKBOX",
    ["Enable Resource System", "If enabled, players must spend resources to build objects. If disabled, building is free."],
    ["505th Expeditionary Force Aux Mod", "Engineering Tools"],
    true,
    1,
    {},
    false
] call CBA_fnc_addSetting;

[
    QGVAR(setting_enableBuildTime),
    "CHECKBOX",
    ["Enable Build Timer", "If enabled, objects take time to construct. If disabled, placement is instant."],
    ["505th Expeditionary Force Aux Mod", "Engineering Tools"],
    true,
    1,
    {},
    false
] call CBA_fnc_addSetting;

ADDON = true;
