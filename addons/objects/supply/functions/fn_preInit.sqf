// OLI_SUPPLY - preInit: hardcoded defaults + CBA Addon Options.
// Runs on every machine before objects init.

// ===========================================================================
//  Default crate classes - the real 505th crates from addons/objects/resupply.
//
//  These are the DEFAULTS for the matching CBA settings below. The mod never
//  touches crate cargo, so whatever loot the class ships with is what the
//  player gets.
//
//  A class that does not exist is caught at spawn time: the player gets an
//  error message, the cooldown is not consumed, and nothing is created.
// ===========================================================================
#define DEFAULT_PLATOON_AMMO      "OLI_Resupply_PlatoonAmmo"
#define DEFAULT_SQUAD_AMMO        "OLI_Resupply_SquadAmmo"
#define DEFAULT_PLATOON_MEDICAL   "OLI_Resupply_PlatoonMedical"
#define DEFAULT_SQUAD_MEDICAL     "OLI_Resupply_SquadMedical"

// ---------------------------------------------------------------------------
// Action keys -> [settings variable, title label, hex colour, icon path]
// Order here is the order the actions appear on the console.
// ---------------------------------------------------------------------------
#define ICON_AMMO     "\BLU\OLI\addons\objects\supply\data\ammo.paa"
#define ICON_MEDICAL  "\A3\ui_f\data\igui\cfg\actions\heal_ca.paa"

OLI_Supply_Actions = [
    ["platoonAmmo",    "OLI_Supply_Class_PlatoonAmmo",    "Spawn Platoon Ammo",    "#FFFF00", ICON_AMMO],
    ["squadAmmo",      "OLI_Supply_Class_SquadAmmo",      "Spawn Squad Ammo",      "#FFFF00", ICON_AMMO],
    ["platoonMedical", "OLI_Supply_Class_PlatoonMedical", "Spawn Platoon Medical", "#FF4040", ICON_MEDICAL],
    ["squadMedical",   "OLI_Supply_Class_SquadMedical",   "Spawn Squad Medical",   "#FF4040", ICON_MEDICAL]
];

// colour used for an action that is greyed out by the cooldown
OLI_Supply_ColorCooldown = "#909090";

// ---------------------------------------------------------------------------
// CBA Addon Options - all global / server-forced (scope 1) so the dedi wins.
// ---------------------------------------------------------------------------
private _cat = ["505th Expeditionary Force Aux Mod", "Supply Console"];

[
    "OLI_Supply_Cooldown", "SLIDER",
    ["Console cooldown (seconds)", "Per player, per console."],
    _cat, [0, 300, 0, 0], 1
] call CBA_fnc_addSetting;

[
    "OLI_Supply_ShowCountdown", "CHECKBOX",
    ["Show countdown in action titles", "While your cooldown on a console is running, its four actions grey out and show your remaining time as m:ss."],
    _cat, true, 1
] call CBA_fnc_addSetting;

[
    "OLI_Supply_Class_PlatoonAmmo", "EDITBOX",
    ["Platoon ammo crate class", "CfgVehicles class spawned by 'Spawn Platoon Ammo'."],
    _cat, DEFAULT_PLATOON_AMMO, 1
] call CBA_fnc_addSetting;

[
    "OLI_Supply_Class_SquadAmmo", "EDITBOX",
    ["Squad ammo crate class", "CfgVehicles class spawned by 'Spawn Squad Ammo'."],
    _cat, DEFAULT_SQUAD_AMMO, 1
] call CBA_fnc_addSetting;

[
    "OLI_Supply_Class_PlatoonMedical", "EDITBOX",
    ["Platoon medical crate class", "CfgVehicles class spawned by 'Spawn Platoon Medical'."],
    _cat, DEFAULT_PLATOON_MEDICAL, 1
] call CBA_fnc_addSetting;

[
    "OLI_Supply_Class_SquadMedical", "EDITBOX",
    ["Squad medical crate class", "CfgVehicles class spawned by 'Spawn Squad Medical'."],
    _cat, DEFAULT_SQUAD_MEDICAL, 1
] call CBA_fnc_addSetting;

[
    "OLI_Supply_IgnoreWeight", "CHECKBOX",
    ["Ignore ACE carry weight limit", "On: a spawned crate is always carryable and never forces the player to walk, however heavy it is. Off: ACE's normal carry weight rules apply, and an overweight crate is dropped in front of the player instead."],
    _cat, true, 1
] call CBA_fnc_addSetting;

[
    "OLI_Supply_ActionRadius", "SLIDER",
    ["Action radius (m)", "How close a player must be for the console actions to appear. Applies to new consoles, not existing ones."],
    _cat, [1, 5, 3, 0], 1
] call CBA_fnc_addSetting;

// client-side list of consoles whose action titles need repainting
if (hasInterface) then {OLI_Supply_LocalConsoles = []};

// distance the server will accept a request from, as a multiple of the action
// radius - guards against desync and replayed events, never trips in normal play
OLI_Supply_ServerRangeFactor = 3;
