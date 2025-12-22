// WIKI: https://cbateam.github.io/CBA_A3/docs/files/keybinding/fnc_addKeybind-sqf.html#CBA_fnc_addKeybind

#include "\a3\ui_f\hpp\defineDIKCodes.inc"  // Key Codes

// ============================================================================
// CHAT WHEEL MENU (Original)
// ============================================================================
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_OpenMenu",
    ["Open Menu", "Opens the custom chat menu."],
    {
        call CWR_fnc_openChatWheel;
    },     // KeyDown
    {},    // KeyUp
    [],    // Default Key
    false, // Hold Key
    0,     // Hold Key Delay
    false  // Overwrite
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
    [DIK_NUMPAD0, [false, false, false]], // Numpad 0
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Numpad 1 - Need Ammo (with voice)
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_2",
    ["Need Ammo", "Send 'I need ammo!' message with voice"],
    {
        "[vl-NeedAmmo]I need ammo!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_NUMPAD1, [false, false, false]], // Numpad 1
    false,
    0,
    false
] call CBA_fnc_addKeybind;


// Numpad 2 - Sorry


// Numpad 3 - Call Medic Check
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_3",
    ["Call Medic Check", "Ask squad for medical status"],
    {
        "Sound off, medical status!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_NUMPAD3, [false, false, false]], // Numpad 3
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
    [DIK_NUMPAD4, [false, false, false]], // Numpad 4
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// ============================================================================
// NUMPAD QUICK CHAT - Custom Messages (Ctrl + Numpad)
// ============================================================================

// Ctrl + Numpad 1 - Custom Message 1
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_1",
    ["Custom Message 1", "Send custom message 1 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 1"] call CBA_fnc_hashGet;
        if (_msg != "Default") then {
            _msg call CWR_fnc_sendGroupMessage;
        };
    },
    {},
    [DIK_NUMPAD1, [true, false, false]], // Ctrl + Numpad 1
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl + Numpad 2 - Custom Message 2
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_2",
    ["Custom Message 2", "Send custom message 2 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 2"] call CBA_fnc_hashGet;
        if (_msg != "Default") then {
            _msg call CWR_fnc_sendGroupMessage;
        };
    },
    {},
    [DIK_NUMPAD2, [true, false, false]], // Ctrl + Numpad 2
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl + Numpad 3 - Custom Message 3
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_3",
    ["Custom Message 3", "Send custom message 3 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 3"] call CBA_fnc_hashGet;
        if (_msg != "Default") then {
            _msg call CWR_fnc_sendGroupMessage;
        };
    },
    {},
    [DIK_NUMPAD3, [true, false, false]], // Ctrl + Numpad 3
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl + Numpad 4 - Custom Message 4
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_4",
    ["Custom Message 4", "Send custom message 4 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 4"] call CBA_fnc_hashGet;
        if (_msg != "Default") then {
            _msg call CWR_fnc_sendGroupMessage;
        };
    },
    {},
    [DIK_NUMPAD4, [true, false, false]], // Ctrl + Numpad 4
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl + Numpad 5 - Custom Message 5
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_5",
    ["Custom Message 5", "Send custom message 5 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 5"] call CBA_fnc_hashGet;
        if (_msg != "Default") then {
            _msg call CWR_fnc_sendGroupMessage;
        };
    },
    {},
    [DIK_NUMPAD5, [true, false, false]], // Ctrl + Numpad 5
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl + Numpad 6 - Custom Message 6
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_6",
    ["Custom Message 6", "Send custom message 6 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 6"] call CBA_fnc_hashGet;
        if (_msg != "Default") then {
            _msg call CWR_fnc_sendGroupMessage;
        };
    },
    {},
    [DIK_NUMPAD6, [true, false, false]], // Ctrl + Numpad 6
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl + Numpad 7 - Custom Message 7
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_7",
    ["Custom Message 7", "Send custom message 7 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 7"] call CBA_fnc_hashGet;
        if (_msg != "Default") then {
            _msg call CWR_fnc_sendGroupMessage;
        };
    },
    {},
    [DIK_NUMPAD7, [true, false, false]], // Ctrl + Numpad 7
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl + Numpad 8 - Custom Message 8
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_8",
    ["Custom Message 8", "Send custom message 8 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 8"] call CBA_fnc_hashGet;
        if (_msg != "Default") then {
            _msg call CWR_fnc_sendGroupMessage;
        };
    },
    {},
    [DIK_NUMPAD8, [true, false, false]], // Ctrl + Numpad 8
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl + Numpad 9 - Custom Message 9
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_9",
    ["Custom Message 9", "Send custom message 9 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 9"] call CBA_fnc_hashGet;
        if (_msg != "Default") then {
            _msg call CWR_fnc_sendGroupMessage;
        };
    },
    {},
    [DIK_NUMPAD9, [true, false, false]], // Ctrl + Numpad 9
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl + Numpad 10 - Custom Message 10
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_10",
    ["Custom Message 10", "Send custom message 10 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 10"] call CBA_fnc_hashGet;
        if (_msg != "Default") then {
            _msg call CWR_fnc_sendGroupMessage;
        };
    },
    {},
    [DIK_NUMPAD9, [true, false, false]], // Ctrl + Numpad 9
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl + Numpad 11 - Custom Message 11
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_11",
    ["Custom Message 11", "Send custom message 11 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 11"] call CBA_fnc_hashGet;
        if (_msg != "Default") then {
            _msg call CWR_fnc_sendGroupMessage;
        };
    },
    {},
    [DIK_NUMPAD9, [true, false, false]], // Ctrl + Numpad 9
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl + Numpad 12 - Custom Message 12
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_NumPad_Custom_12",
    ["Custom Message 12", "Send custom message 12 (configurable in settings)"],
    {
        private _msg = [CWR_messagesHashMap, "Custom 12"] call CBA_fnc_hashGet;
        if (_msg != "Default") then {
            _msg call CWR_fnc_sendGroupMessage;
        };
    },
    {},
    [DIK_NUMPAD9, [true, false, false]], // Ctrl + Numpad 9
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// ----------------------------------------------------------------------------
// NEW KEYBINDS FOR ENEMY CONTACT
// ----------------------------------------------------------------------------

// Ctrl+Alt+1 - Enemy Infantry
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_EnemyInfantry",
    ["Enemy Infantry", "Report enemy infantry with bearing"],
    {
        "[vl-EnemyInfantry]Enemy Infantry, bearing [bearing]!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_1, [true, true, false]], // Ctrl+Alt+1
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl+Alt+2 - Enemy Vehicle
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_EnemyVehicle",
    ["Enemy Vehicle", "Report enemy vehicle with bearing"],
    {
        "[vl-EnemyVehicle]Enemy Vehicle, bearing [bearing]!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_2, [true, true, false]], // Ctrl+Alt+2
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl+Alt+3 - Enemy Air
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_EnemyAir",
    ["Enemy Air", "Report enemy aircraft with bearing"],
    {
        "[vl-EnemyAir]Enemy Air, bearing [bearing]!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_3, [true, true, false]], // Ctrl+Alt+3
    false,
    0,
    false
] call CBA_fnc_addKeybind;


// ----------------------------------------------------------------------------
// NEW KEYBINDS FOR MEDICAL CHECK RESPONSES
// ----------------------------------------------------------------------------

// Ctrl+Alt+7 - Combat Ready
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_MedCheck_Ready",
    ["Combat Ready", "Report you are combat ready"],
    {
        "[vl-MedicalCheckReady]Combat Ready!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_7, [true, true, false]], // Ctrl+Alt+7
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl+Alt+8 - Wounded
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_MedCheck_Wounded",
    ["Wounded", "Report you are wounded"],
    {
        "[vl-MedicalCheckWounded]I'm Wounded!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_8, [true, true, false]], // Ctrl+Alt+8
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// Ctrl+Alt+9 - Casualty Here (with map ping)
[
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "CWR_MedCheck_Casualty",
    ["Casualty Here", "Report casualty at your position (creates map marker)"],
    {
        "[vl-MedicalCheckCasualties][ping]I have a casualty here!" call CWR_fnc_sendGroupMessage;
    },
    {},
    [DIK_9, [true, true, false]], // Ctrl+Alt+9
    false,
    0,
    false
] call CBA_fnc_addKeybind;

// ============================================================================
// ALTERNATIVE: If you want different keys, change the DIK codes
// ============================================================================
/*
Available keys:
DIK_F1 through DIK_F12
DIK_1 through DIK_0
DIK_NUMPAD1 through DIK_NUMPAD0
DIK_INSERT, DIK_DELETE, DIK_HOME, DIK_END, DIK_PGUP, DIK_PGDN
etc.

Modifiers (in the array [key, [ctrl, shift, alt]]):
[true, false, false] = Ctrl
[false, true, false] = Shift
[false, false, true] = Alt
[true, true, false] = Ctrl+Shift
[true, false, true] = Ctrl+Alt
etc.
*/
