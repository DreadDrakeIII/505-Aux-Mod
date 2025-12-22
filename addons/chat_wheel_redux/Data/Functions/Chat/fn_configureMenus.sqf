#define QUOTE(CODE) #CODE

CWR_messagesHashMap =
[
    [
        ["Medic", "[vl-NeedMedic]I need a medic!"],
        ["Ammo", "[vl-NeedAmmo]I need ammo for my [weapon]!"],
        ["Enemy Contact", "[enemy]"],
        ["Med Check", "[vl-AskStatus]Medical check!"],
        ["Med Response", "[status]"],
        ["Custom 1", "Default Message"],
        ["Custom 2", "Default Message"],
        ["Custom 3", "Default Message"],
        ["Custom 4", "Default Message"],
        ["Custom 5", "Default Message"],
        ["Custom 6", "Default Message"],
        ["Custom 7", "Default Message"],
        ["Custom 8", "Default Message"],
        ["Custom 9", "Default Message"],
        ["Custom 10", "Default Message"],
        ["Custom 11", "Default Message"],
        ["Custom 12", "Default Message"]
    ],
    "Default Message"
] call CBA_fnc_hashCreate;

// Helper function to get display label for a menu key
// For custom messages, shows the actual message content (truncated if needed)
// For other entries, shows the original key name
CWR_fnc_getDisplayLabel = {
    params ["_key"];

    // Check if this is a custom message key
    if (_key select [0, 6] == "Custom") then {
        private _message = [CWR_messagesHashMap, _key] call CBA_fnc_hashGet;

        // If empty or default, show placeholder
        if (_message isEqualTo "" || _message isEqualTo "Default Message" || _message isEqualTo "Default") then {
            format ["%1 (empty)", _key]
        } else {
            // Strip any voice line tags for cleaner display
            private _displayMsg = _message;
            // Remove [vl-*] tags
            private _tagStart = _displayMsg find "[vl-";
            while {_tagStart != -1} do {
                private _tagEnd = (_displayMsg select [_tagStart, 50]) find "]";
                if (_tagEnd != -1) then {
                    _displayMsg = (_displayMsg select [0, _tagStart]) + (_displayMsg select [_tagStart + _tagEnd + 1]);
                };
                _tagStart = _displayMsg find "[vl-";
            };

            // Truncate if too long (max 30 chars for menu readability)
            if (count _displayMsg > 30) then {
                (_displayMsg select [0, 27]) + "..."
            } else {
                _displayMsg
            };
        };
    } else {
        // Non-custom entries keep their original label
        _key
    };
};

// Function to build/rebuild the root menu with current display labels
CWR_fnc_buildRootMenu = {
    private _keys = [CWR_messagesHashMap] call CBA_fnc_hashKeys;
    private _displayLabels = _keys apply { [_x] call CWR_fnc_getDisplayLabel };

    [
        "Speak!",
        "CWR_Menu_Root",
        _displayLabels,
        "",
        QUOTE([([CWR_messagesHashMap] call CBA_fnc_hashValues) select %2] call CWR_fnc_sendGroupMessage)
    ] call BIS_fnc_createMenu;
};

// Build initial menu
[] call CWR_fnc_buildRootMenu;


// Enemy Contact Menu
CWR_OpenEnemyMenu = {
    params ["_message"];
    sleep 0.05;

    private _enemyList = ["Infantry", "Vehicle", "Air"];

    // Build per-option messages by replacing [enemy] in the original message
    // This mirrors your Status menu pattern exactly.
    CWR_enemyMessageList = _enemyList apply {
        [_message, "[enemy]", format ["[vl-Enemy%1]Enemy %1, bearing [bearing]!", _x]] call CWR_fnc_stringReplace
    };

    [
        "Enemy Type",
        "CWR_Menu_Enemy",
        _enemyList,
        "",
        QUOTE([[CWR_enemyMessageList select %2] call CWR_fnc_removeQuotes] call CWR_fnc_sendGroupMessage)
    ] call BIS_fnc_createMenu;

    showCommandingMenu "#USER:CWR_Menu_Enemy_0";
};


// Medical Status Menu
CWR_OpenStatusMenu = {
    params ["_message"];
    sleep 0.05;

    private _statusList = ["Combat Ready", "Wounded", "I have casualties here!"];
    CWR_statusMessageList = [
        "[vl-MedicalCheckReady]Combat Ready",
        "[vl-MedicalCheckWounded]Wounded",
        "[vl-MedicalCheckCasualties][ping]I have casualties here!"
    ];

    [
        "Medical Status",
        "CWR_Menu_Status",
        _statusList,
        "",
        QUOTE([[CWR_statusMessageList select %2] call CWR_fnc_removeQuotes] call CWR_fnc_sendGroupMessage)
    ] call BIS_fnc_createMenu;

    showCommandingMenu "#USER:CWR_Menu_Status_0";
};
