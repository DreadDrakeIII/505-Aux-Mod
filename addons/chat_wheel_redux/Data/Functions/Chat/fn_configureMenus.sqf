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
        ["Custom 9", "Default Message"]
    ],
    "Default Message"
] call CBA_fnc_hashCreate;

[
    "Speak!",
    "CWR_Menu_Root",
    [CWR_messagesHashMap] call CBA_fnc_hashKeys,
    "",
    QUOTE([([CWR_messagesHashMap] call CBA_fnc_hashValues) select %2] call CWR_fnc_sendGroupMessage)
] call BIS_fnc_createMenu;


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
