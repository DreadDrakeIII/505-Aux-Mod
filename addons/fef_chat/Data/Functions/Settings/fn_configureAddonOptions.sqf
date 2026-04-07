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
    "FEF_Auto_EnableGrenadeCallouts",
    "CHECKBOX",
    ["Enable Grenade Callouts", "Automatically send a grenade callout when throwing frag grenades."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    true,
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Auto_EnableSmokeCallouts",
    "CHECKBOX",
    ["Enable Smoke Callouts", "Automatically send a smoke callout when throwing smoke grenades."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    true,
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Auto_EnableUnconsciousCallouts",
    "CHECKBOX",
    ["Enable Unconscious Callouts", "Automatically send a downed/friendly-down callout when a player becomes unconscious."],
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

[
    "FEF_Reinsert_MarkerDuration",
    "SLIDER",
    ["Reinsert Marker Duration", "How long the reinsert marker stays visible on the map, in seconds."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    [5, 300, 20, 0],
    0,
    {},
    false
] call CBA_fnc_addSetting;

// ============================================================================
// CASUALTY MARKER SETTINGS
// ============================================================================

[
    "FEF_Casualty_MarkerDuration",
    "SLIDER",
    ["Casualty Marker Duration", "How long the casualty marker stays visible on the map, in seconds."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    [5, 300, 20, 0],
    0,
    {},
    false
] call CBA_fnc_addSetting;

// ============================================================================
// DEBUG
// ============================================================================

[
    "FEF_Chat_Debug",
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
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "SET HERE.",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_2",
    "EDITBOX",
    ["Custom Message 02", "Custom message slot 02."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "HOLD FIRE.",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_3",
    "EDITBOX",
    ["Custom Message 03", "Custom message slot 03."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "STACK UP.",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_4",
    "EDITBOX",
    ["Custom Message 04", "Custom message slot 04."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "COVER ME.",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_5",
    "EDITBOX",
    ["Custom Message 05", "Custom message slot 05."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_6",
    "EDITBOX",
    ["Custom Message 06", "Custom message slot 06."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_7",
    "EDITBOX",
    ["Custom Message 07", "Custom message slot 07."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_8",
    "EDITBOX",
    ["Custom Message 08", "Custom message slot 08."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_9",
    "EDITBOX",
    ["Custom Message 09", "Custom message slot 09."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_10",
    "EDITBOX",
    ["Custom Message 10", "Custom message slot 10."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_11",
    "EDITBOX",
    ["Custom Message 11", "Custom message slot 11."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "",
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "FEF_Chat_CustomMessage_12",
    "EDITBOX",
    ["Custom Message 12", "Custom message slot 12."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "",
    0,
    {},
    false
] call CBA_fnc_addSetting;
