/*
    File: fn_configureAddonOptions.sqf
    Purpose:
    Registers CBA addon settings for the 505th chat system.
*/

// ============================================================================
// VOICE SETTINGS
// ============================================================================

[
    "FEF_Voice_EnableVoiceLines",
    "CHECKBOX",
    ["Enable Voice Lines", "Enable local 3D voice playback for supported callouts."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    true,
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Voice_Volume",
    "SLIDER",
    ["Voice Line Volume", "Adjust the volume of local voice lines. 1.0 = full, 2.0 = boosted."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    [0, 2, 1.0, 1],
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Voice_VoiceRadius",
    "SLIDER",
    ["Voice Radius", "Maximum distance for local voice lines and local automessages."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    [5, 80, 35, 0],
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Voice_Profile",
    "LIST",
    ["Voice Profile", "Select the active voice language profile."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    [
        ["en_US", "en_GB"],
        ["American English", "British English"],
        0
    ],
    0,
    {},
    false
] call CBA_fnc_addSetting;

// ============================================================================
// AUTOMESSAGE SETTINGS
// ============================================================================

[
    "FEF_AutoMessages_Enabled",
    "CHECKBOX",
    ["Enable Automessages", "Master switch for all automessage features."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    true,
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_AutoMessages_Grenades",
    "CHECKBOX",
    ["Automessage - Grenades", "Automatically send a grenade callout when throwing frag grenades."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    true,
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_AutoMessages_Unconscious",
    "CHECKBOX",
    ["Automessage - Unconscious", "Automatically send a downed/friendly-down callout when a player becomes unconscious."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    true,
    0,
    {},
    false
] call CBA_fnc_addSetting;

// ============================================================================
// REINSERT SETTINGS
// ============================================================================

[
    "FEF_Reinsert_Cooldown",
    "SLIDER",
    ["Reinsert Cooldown", "Cooldown in seconds before another reinsert request can be sent."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    [10, 300, 60, 0],
    0,
    {},
    false
] call CBA_fnc_addSetting;

// ============================================================================
// DEBUG
// ============================================================================

[
    "FEF_Debug_ShowMessages",
    "CHECKBOX",
    ["Debug Mode", "Enable debug output for FEF Chat."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    false,
    0,
    {},
    false
] call CBA_fnc_addSetting;

// ============================================================================
// CUSTOM MESSAGES 01-12
// ============================================================================

[
    "FEF_Chat_CustomMessage_1",
    "EDITBOX",
    ["Custom Message 01", "Custom message slot 01."],
    ["505th Expeditionary Force Aux Mod", "Custom Messages"],
    "Set here.",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_2",
    "EDITBOX",
    ["Custom Message 02", "Custom message slot 02."],
    ["505th Expeditionary Force Aux Mod", "Custom Messages"],
    "On me.",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_3",
    "EDITBOX",
    ["Custom Message 03", "Custom message slot 03."],
    ["505th Expeditionary Force Aux Mod", "Custom Messages"],
    "Cover me.",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_4",
    "EDITBOX",
    ["Custom Message 04", "Custom message slot 04."],
    ["505th Expeditionary Force Aux Mod", "Custom Messages"],
    "Hold fire.",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_5",
    "EDITBOX",
    ["Custom Message 05", "Custom message slot 05."],
    ["505th Expeditionary Force Aux Mod", "Custom Messages"],
    "Need AT on me!",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_6",
    "EDITBOX",
    ["Custom Message 06", "Custom message slot 06."],
    ["505th Expeditionary Force Aux Mod", "Custom Messages"],
    "Need demo on me!",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_7",
    "EDITBOX",
    ["Custom Message 07", "Custom message slot 07."],
    ["505th Expeditionary Force Aux Mod", "Custom Messages"],
    "Stack up.",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_8",
    "EDITBOX",
    ["Custom Message 08", "Custom message slot 08."],
    ["505th Expeditionary Force Aux Mod", "Custom Messages"],
    "Move to me.",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_9",
    "EDITBOX",
    ["Custom Message 09", "Custom message slot 09."],
    ["505th Expeditionary Force Aux Mod", "Custom Messages"],
    "Watch that sector.",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_10",
    "EDITBOX",
    ["Custom Message 10", "Custom message slot 10."],
    ["505th Expeditionary Force Aux Mod", "Custom Messages"],
    "Need pickup!",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_11",
    "EDITBOX",
    ["Custom Message 11", "Custom message slot 11."],
    ["505th Expeditionary Force Aux Mod", "Custom Messages"],
    "Send reinforcements!",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_12",
    "EDITBOX",
    ["Custom Message 12", "Custom message slot 12."],
    ["505th Expeditionary Force Aux Mod", "Custom Messages"],
    "Area secure.",
    0,
    {},
    false
] call CBA_fnc_addSetting;
