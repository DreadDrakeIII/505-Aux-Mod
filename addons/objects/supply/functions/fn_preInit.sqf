// OLI_SUPPLY - preInit: action table + CBA Addon Options.
// Runs on every machine before objects init.

// ===========================================================================
//  The action table.
//
//  One line per spawn option the console offers. Everything else in this
//  sub-component is driven off this table, so adding a seventh crate later is
//  one line here and nothing else - the CBA settings, the scroll actions, the
//  cooldown tracking and the countdown all build themselves from it.
//
//  Fields:
//    0: action key         - internal id, also the name of the cooldown
//                            variable stored on the console. Never shown.
//    1: name               - shown as "Spawn <name>" on the console and as
//                            the prefix of this option's three addon options.
//    2: title colour       - hex, used for the scroll action text.
//    3: icon               - .paa shown next to the action text.
//    4: class setting      - CBA setting holding the crate class.
//    5: default class      - the 505th crate from addons/objects/resupply.
//    6: cooldown setting   - CBA setting holding this option's cooldown.
//    7: default cooldown   - seconds.
//    8: enable setting     - CBA setting; off removes the option entirely.
//
//  Order here is the order the actions appear on the console, and it matches
//  the 01-06 numbering on the crate classes themselves.
//
//  The mod never touches crate cargo: whatever loot the class ships with is
//  what the player gets. A class that does not exist is caught at spawn time -
//  the player gets an error message, the cooldown is not consumed, and nothing
//  is created.
// ===========================================================================
#define ICON_AMMO       "\BLU\OLI\addons\objects\supply\data\ammo.paa"
#define ICON_MEDICAL    "\A3\ui_f\data\igui\cfg\actions\heal_ca.paa"
#define ICON_EXPLOSIVE  "\a3\modules_f\data\iconexplosive_ca.paa"
#define ICON_ROCKET     "\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\destroy_ca.paa"

OLI_Supply_Actions = [
    ["squadAmmo",      "Squad Ammo",      "#FFFF00", ICON_AMMO,
        "OLI_Supply_Class_SquadAmmo",      "OLI_Resupply_SquadAmmo",
        "OLI_Supply_Cooldown_SquadAmmo",      60,  "OLI_Supply_Enabled_SquadAmmo"],

    ["platoonAmmo",    "Platoon Ammo",    "#FFFF00", ICON_AMMO,
        "OLI_Supply_Class_PlatoonAmmo",    "OLI_Resupply_PlatoonAmmo",
        "OLI_Supply_Cooldown_PlatoonAmmo",   140, "OLI_Supply_Enabled_PlatoonAmmo"],

    ["squadMedical",   "Squad Medical",   "#FF4040", ICON_MEDICAL,
        "OLI_Supply_Class_SquadMedical",   "OLI_Resupply_SquadMedical",
        "OLI_Supply_Cooldown_SquadMedical",   60,  "OLI_Supply_Enabled_SquadMedical"],

    ["platoonMedical", "Platoon Medical", "#FF4040", ICON_MEDICAL,
        "OLI_Supply_Class_PlatoonMedical", "OLI_Resupply_PlatoonMedical",
        "OLI_Supply_Cooldown_PlatoonMedical", 140, "OLI_Supply_Enabled_PlatoonMedical"],

    ["explosives",     "Explosives",      "#FF9000", ICON_EXPLOSIVE,
        "OLI_Supply_Class_Explosives",     "OLI_Resupply_Explosives",
        "OLI_Supply_Cooldown_Explosives",     180, "OLI_Supply_Enabled_Explosives"],

    ["rockets",        "Rockets",         "#00C8FF", ICON_ROCKET,
        "OLI_Supply_Class_Rockets",        "OLI_Resupply_Rockets",
        "OLI_Supply_Cooldown_Rockets",        180, "OLI_Supply_Enabled_Rockets"]
];

// colour used for an action that is greyed out by its cooldown
OLI_Supply_ColorCooldown = "#909090";

// ---------------------------------------------------------------------------
// CBA Addon Options - all global / server-forced (scope 1) so the dedi wins.
//
// Three settings per option: available (on/off), cooldown, crate class. They
// are registered in table order and their display names carry the crate number
// as a prefix, so they stay grouped per crate in the options menu however CBA
// chooses to sort them.
// ---------------------------------------------------------------------------
private _cat = ["505th Expeditionary Force Aux Mod", "Supply Console"];

{
    _x params ["", "_name", "", "", "_classVar", "_defaultClass", "_cdVar", "_defaultCd", "_enabledVar"];

    private _num = _forEachIndex + 1;
    private _prefix = if (_num < 10) then {format ["0%1", _num]} else {str _num};

    [
        _enabledVar, "CHECKBOX",
        [
            format ["%1 %2 - available", _prefix, _name],
            "Off: this option is removed from the console completely - no scroll action, nothing to select. Use it to run a mission with only the crates you want."
        ],
        _cat, true, 1
    ] call CBA_fnc_addSetting;

    [
        _cdVar, "SLIDER",
        [
            format ["%1 %2 - cooldown (seconds)", _prefix, _name],
            "Cooldown for this option on the console that was used. It is shared by everyone: once one player takes this crate, nobody can take the same crate from that console until the timer runs out. The other options are unaffected and stay available. 0 = no cooldown."
        ],
        _cat, [0, 900, _defaultCd, 0], 1
    ] call CBA_fnc_addSetting;

    [
        _classVar, "EDITBOX",
        [
            format ["%1 %2 - crate class", _prefix, _name],
            format ["CfgVehicles class spawned by this option. Default: %1", _defaultClass]
        ],
        _cat, _defaultClass, 1
    ] call CBA_fnc_addSetting;
} forEach OLI_Supply_Actions;

// ---------------------------------------------------------------------------
// Settings that apply to the console as a whole.
// ---------------------------------------------------------------------------
[
    "OLI_Supply_ShowCountdown", "CHECKBOX",
    ["Show countdown in action titles", "While an option is recharging, its action greys out and shows the remaining time as m:ss."],
    _cat, true, 1
] call CBA_fnc_addSetting;

[
    "OLI_Supply_IgnoreWeight", "CHECKBOX",
    ["Ignore ACE carry weight limit", "On: a spawned crate is always carryable and never forces the player to walk, however heavy it is. Off: ACE's normal carry weight rules apply, and an overweight crate is dropped in front of the player instead."],
    _cat, true, 1
] call CBA_fnc_addSetting;

[
    "OLI_Supply_ActionRadius", "SLIDER",
    ["Action radius (m)", "How close a player must be for the console actions to appear."],
    _cat, [1, 5, 3, 0], 1
] call CBA_fnc_addSetting;

// ---------------------------------------------------------------------------
// Settings whose value is baked into the scroll actions when they are created.
// Changing one of these mid-mission means the actions have to be torn down and
// rebuilt - fn_wireConsoles watches this list.
// ---------------------------------------------------------------------------
OLI_Supply_RebuildSettings = ["OLI_Supply_ActionRadius"];
{
    OLI_Supply_RebuildSettings pushBack (_x select 8);
} forEach OLI_Supply_Actions;

// client-side list of consoles this machine knows about
if (hasInterface) then {OLI_Supply_LocalConsoles = []};

// distance the server will accept a request from, as a multiple of the action
// radius - guards against desync and replayed events, never trips in normal play
OLI_Supply_ServerRangeFactor = 3;
