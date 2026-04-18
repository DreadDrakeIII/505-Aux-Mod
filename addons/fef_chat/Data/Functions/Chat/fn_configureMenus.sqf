/*
 * Menu item format:
 * [label, actionType, payload]
 *
 * actionType:
 * - submenu   : payload = menuId
 * - group     : payload = [messageText, voiceKey]
 * - downAlert : payload = []
 * - back      : payload = menuId
 * - reinsert  : payload = 1..5
 * - medevac   : payload = type string
 * - lz        : payload = type string
 */

private _menus = createHashMap;

private _trimLabel = {
    params ["_text", "_fallback"];
    private _value = trim _text;
    if (_value isEqualTo "") exitWith { _fallback };
    if ((count _value) > 24) then {
        (_value select [0, 21]) + "..."
    } else {
        _value
    };
};

private _customMessage = {
    params ["_index", "_fallback"];
    missionNamespace getVariable [format ["FEF_Chat_CustomMessage_%1", _index], _fallback]
};

private _customLabel = {
    params ["_index", "_fallback"];
    private _message = [_index, _fallback] call _customMessage;
    [_message, _fallback] call _trimLabel
};

// ============================================================================
// MAIN
// ============================================================================
_menus set ["main", [
    ["Need Medic",      "group",   ["I need a medic!", "NeedMedic"]],
    ["Need Ammo",       "group",   ["Need ammo for [weapon]!", ""]],
    ["Medic Check",     "group",   ["Medic check, report status!", ""]],
    ["Contact",         "submenu", "contact"],
    ["Medical Status",  "submenu", "medical_status"],
    ["Squad Comms",     "submenu", "squad_comms"],
    ["Fireteam Comms",  "submenu", "fireteam_comms"],
    ["Reinsert",        "submenu", "reinsert"],
    ["MEDEVAC",         "submenu", "medevac"],
    ["LZ Request",      "submenu", "lz_request"],
    ["Custom",          "submenu", "custom_1"]
]];

// ============================================================================
// CONTACT
// ============================================================================
_menus set ["contact", [
    ["Infantry",  "group", ["Enemy infantry, bearing [bearing]!", ""]],
    ["Vehicle",   "group", ["Enemy vehicle, bearing [bearing]!", ""]],
    ["Air",       "group", ["Enemy air contact, bearing [bearing]!", ""]],
    ["< Back",    "back",  "main"]
]];

// ============================================================================
// MEDICAL STATUS
// ============================================================================
_menus set ["medical_status", [
    ["Combat Ready",  "group",     ["Combat ready.", "MedicalCheckReady"]],
    ["Wounded",       "group",     ["Wounded.", "MedicalCheckWounded"]],
    ["Friendly Down", "downAlert", []],
    ["< Back",        "back",      "main"]
]];

// ============================================================================
// SQUAD COMMS
// ============================================================================
_menus set ["squad_comms", [
    ["Column",       "group", ["Column", ""]],
    ["Stag Column",     "group", ["Staggered Column", ""]],
    ["Wedge", "group", ["Wedge", ""]],
    ["L-Ech",         "group", ["Left Echelon", ""]],
    ["R-Ech",    "group", ["Right Echelon", ""]],
    ["B-Line",    "group", ["Battle Line", ""]],
    ["< Back",        "back",  "main"]
]];

// ============================================================================
// FIRETEAM COMMS
// ============================================================================
_menus set ["fireteam_comms", [
    ["Move Up",       "group", ["Fireteam, move up!", ""]],
    ["Fall Back",     "group", ["Fireteam, fall back!", ""]],
    ["Hold Position", "group", ["Fireteam, hold position!", ""]],
    ["On Me",         "group", ["Fireteam, on me!", ""]],
    ["Spread Out",    "group", ["Fireteam, spread out!", ""]],
    ["< Back",        "back",  "main"]
]];

// ============================================================================
// REINSERT
// ============================================================================
_menus set ["reinsert", [
    ["x1 Reinsert", "reinsert", 1],
    ["x2 Reinsert", "reinsert", 2],
    ["x3 Reinsert", "reinsert", 3],
    ["x4 Reinsert", "reinsert", 4],
    ["x5 Reinsert", "reinsert", 5],
    ["< Back",       "back",    "main"]
]];

// ============================================================================
// MEDEVAC — Squad Leader / Pilot only
// ============================================================================
_menus set ["medevac", [
    ["Urgent",   "medevac", "urgent"],
    ["Priority", "medevac", "priority"],
    ["Routine",  "medevac", "routine"],
    ["< Back",   "back",    "main"]
]];

// ============================================================================
// LZ REQUEST — Squad Leader / Pilot only
// ============================================================================
_menus set ["lz_request", [
    ["Pickup",    "lz", "pickup"],
    ["Drop-Off",  "lz", "dropoff"],
    ["CASEVAC",   "lz", "casevac"],
    ["Extract",   "lz", "extract"],
    ["Hot LZ",    "lz", "hot"],
    ["LZ Clear",  "lz", "clear"],
    ["< Back",    "back", "main"]
]];

// ============================================================================
// CUSTOM PAGE 1
// ============================================================================
_menus set ["custom_1", [
    [[1,  "Custom 01"] call _customLabel, "group", [[1,  "Custom 01"] call _customMessage, ""]],
    [[2,  "Custom 02"] call _customLabel, "group", [[2,  "Custom 02"] call _customMessage, ""]],
    [[3,  "Custom 03"] call _customLabel, "group", [[3,  "Custom 03"] call _customMessage, ""]],
    [[4,  "Custom 04"] call _customLabel, "group", [[4,  "Custom 04"] call _customMessage, ""]],
    [[5,  "Custom 05"] call _customLabel, "group", [[5,  "Custom 05"] call _customMessage, ""]],
    [[6,  "Custom 06"] call _customLabel, "group", [[6,  "Custom 06"] call _customMessage, ""]],
    [[7,  "Custom 07"] call _customLabel, "group", [[7,  "Custom 07"] call _customMessage, ""]],
    [[8,  "Custom 08"] call _customLabel, "group", [[8,  "Custom 08"] call _customMessage, ""]],
    [[9,  "Custom 09"] call _customLabel, "group", [[9,  "Custom 09"] call _customMessage, ""]],
    [[10, "Custom 10"] call _customLabel, "group", [[10, "Custom 10"] call _customMessage, ""]],
    [[11, "Custom 11"] call _customLabel, "group", [[11, "Custom 11"] call _customMessage, ""]],
    [[12, "Custom 12"] call _customLabel, "group", [[12, "Custom 12"] call _customMessage, ""]],
    ["< Back",          "back",           "main"]
]];

missionNamespace setVariable ["FEF_Menus", _menus];
