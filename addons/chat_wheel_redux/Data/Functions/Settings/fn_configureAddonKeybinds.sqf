#include "\a3\ui_f\hpp\defineDIKCodes.inc"

// ============================================================================
// CHAT WHEEL MENU (Original)
// ============================================================================
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_OpenMenu",
    ["Open Menu", "Opens the custom chat menu."],
    {
        call CWR_fnc_openChatWheel;
    },
    {},
    [],
    false,
    0,
    false
] call CBA_fnc_addKeybind;


// ============================================================================
// NUMPAD QUICK CHAT - Basic Messages
// ============================================================================

// Numpad 0 - Medic!
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_0",
    ["Medic!", "Send 'I need a medic!' message"],
    {
        "[vl-NeedMedic]I need a medic!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_NUMPAD0, [false, false, false]],
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Numpad 1 - Need Ammo (with voice)
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_1",
    ["Need Ammo", "Send 'I need ammo!' message with voice"],
    {
        "[vl-NeedAmmo]I need ammo!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_NUMPAD1, [false, false, false]],
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Numpad 3 - Call Medic Check
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_3",
    ["Call Medic Check", "Ask squad for medical status"],
    {
        "Sound off, medical status!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_NUMPAD3, [false, false, false]],
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Numpad 4 - Response Medic Check (Status submenu)
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_4",
    ["Medical Status", "Report your medical status"],
    {
        private _message = "[status]";
        [_message] spawn CWR_OpenStatusMenu;
    },
    {},
    [DIK_NUMPAD4, [false, false, false]],
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// ============================================================================
// NUMPAD QUICK CHAT - Custom Messages (Ctrl + Numpad)
// ============================================================================

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_1",
    ["Custom Message 1", "Send custom message 1 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 1"] call CBA_fnc_hashGet;
        if (_msg != "Default") then { _msg call CWR_fnc_sendGroupMessage; };
    },
    {},
    [DIK_NUMPAD1, [true, false, false]],
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_2",
    ["Custom Message 2", "Send custom message 2 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 2"] call CBA_fnc_hashGet;
        if (_msg != "Default") then { _msg call CWR_fnc_sendGroupMessage; };
    },
    {},
    [DIK_NUMPAD2, [true, false, false]],
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_3",
    ["Custom Message 3", "Send custom message 3 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 3"] call CBA_fnc_hashGet;
        if (_msg != "Default") then { _msg call CWR_fnc_sendGroupMessage; };
    },
    {},
    [DIK_NUMPAD3, [true, false, false]],
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_4",
    ["Custom Message 4", "Send custom message 4 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 4"] call CBA_fnc_hashGet;
        if (_msg != "Default") then { _msg call CWR_fnc_sendGroupMessage; };
    },
    {},
    [DIK_NUMPAD4, [true, false, false]],
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_5",
    ["Custom Message 5", "Send custom message 5 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 5"] call CBA_fnc_hashGet;
        if (_msg != "Default") then { _msg call CWR_fnc_sendGroupMessage; };
    },
    {},
    [DIK_NUMPAD5, [true, false, false]],
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_6",
    ["Custom Message 6", "Send custom message 6 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 6"] call CBA_fnc_hashGet;
        if (_msg != "Default") then { _msg call CWR_fnc_sendGroupMessage; };
    },
    {},
    [DIK_NUMPAD6, [true, false, false]],
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_7",
    ["Custom Message 7", "Send custom message 7 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 7"] call CBA_fnc_hashGet;
        if (_msg != "Default") then { _msg call CWR_fnc_sendGroupMessage; };
    },
    {},
    [DIK_NUMPAD7, [true, false, false]],
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_8",
    ["Custom Message 8", "Send custom message 8 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 8"] call CBA_fnc_hashGet;
        if (_msg != "Default") then { _msg call CWR_fnc_sendGroupMessage; };
    },
    {},
    [DIK_NUMPAD8, [true, false, false]],
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_9",
    ["Custom Message 9", "Send custom message 9 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 9"] call CBA_fnc_hashGet;
        if (_msg != "Default") then { _msg call CWR_fnc_sendGroupMessage; };
    },
    {},
    [DIK_NUMPAD9, [true, false, false]],
    false, 0, false
] call CBA_fnc_addKeybind;

// FIX: Custom 10/11/12 were all incorrectly bound to DIK_NUMPAD9.
// Reassigned to Ctrl+Alt+Numpad combos to avoid conflicts.
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_10",
    ["Custom Message 10", "Send custom message 10 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 10"] call CBA_fnc_hashGet;
        if (_msg != "Default") then { _msg call CWR_fnc_sendGroupMessage; };
    },
    {},
    [DIK_NUMPAD0, [true, true, false]], // Ctrl+Alt+Numpad0
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_11",
    ["Custom Message 11", "Send custom message 11 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 11"] call CBA_fnc_hashGet;
        if (_msg != "Default") then { _msg call CWR_fnc_sendGroupMessage; };
    },
    {},
    [DIK_NUMPAD1, [true, true, false]], // Ctrl+Alt+Numpad1 (note: conflicts with EnemyInfantry if that's also Ctrl+Alt+1 on main kb)
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_12",
    ["Custom Message 12", "Send custom message 12 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 12"] call CBA_fnc_hashGet;
        if (_msg != "Default") then { _msg call CWR_fnc_sendGroupMessage; };
    },
    {},
    [DIK_NUMPAD2, [true, true, false]], // Ctrl+Alt+Numpad2
    false, 0, false
] call CBA_fnc_addKeybind;

// ----------------------------------------------------------------------------
// ENEMY CONTACT
// ----------------------------------------------------------------------------

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_EnemyInfantry",
    ["Enemy Infantry", "Report enemy infantry with bearing"],
    {
        "[vl-EnemyInfantry]Enemy Infantry, bearing [bearing]!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_1, [true, true, false]], // Ctrl+Alt+1
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_EnemyVehicle",
    ["Enemy Vehicle", "Report enemy vehicle with bearing"],
    {
        "[vl-EnemyVehicle]Enemy Vehicle, bearing [bearing]!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_2, [true, true, false]], // Ctrl+Alt+2
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_EnemyAir",
    ["Enemy Air", "Report enemy aircraft with bearing"],
    {
        "[vl-EnemyAir]Enemy Air, bearing [bearing]!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_3, [true, true, false]], // Ctrl+Alt+3
    false, 0, false
] call CBA_fnc_addKeybind;

// ----------------------------------------------------------------------------
// MEDICAL CHECK RESPONSES
// ----------------------------------------------------------------------------

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_MedCheck_Ready",
    ["Combat Ready", "Report you are combat ready"],
    {
        "[vl-MedicalCheckReady]Combat Ready!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_7, [true, true, false]], // Ctrl+Alt+7
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_MedCheck_Wounded",
    ["Wounded", "Report you are wounded"],
    {
        "[vl-MedicalCheckWounded]I'm Wounded!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_8, [true, true, false]], // Ctrl+Alt+8
    false, 0, false
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_MedCheck_Casualty",
    ["Casualty Here", "Report casualty at your position (creates map marker)"],
    {
        "[vl-MedicalCheckCasualties][ping]I have a casualty here!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_9, [true, true, false]], // Ctrl+Alt+9
    false, 0, false
] call CBA_fnc_addKeybind;
