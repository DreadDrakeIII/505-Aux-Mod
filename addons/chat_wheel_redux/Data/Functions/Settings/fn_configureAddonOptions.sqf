// WIKI: https://github.com/CBATeam/CBA_A3/wiki/CBA-Settings-System#creating-a-setting
// Authors: DartRuffian, Revgamer

// ============================================================================
// VOICE LANGUAGE SELECTION
// ============================================================================

[
    "CWR_Voice_Language",
    "LIST",
    ["Voice Language", "Select the language for voice lines. Server must have the language files."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    [
        ["en_US", "en_GB"],                 // values stored
        ["American English", "British English"], // UI labels
        0
    ],
    0, // isGlobal
    {
        params ["_value"];

        // Cache selected language so fn_processTags can read it
        missionNamespace setVariable ["CWR_voiceLang", _value];

        ["CWR_Voice_Language changed to: %1", _value] call CWR_fnc_devLog;
    },
    false
] call CBA_fnc_addSetting;

// Optional: ensure a default exists even before user opens settings
if (isNil { missionNamespace getVariable "CWR_voiceLang" }) then {
    missionNamespace setVariable ["CWR_voiceLang", "en_US"];
};


// ============================================================================
// CUSTOM MESSAGES (1-9)
// ============================================================================

[
    "CWR_CustomMessages_1",
    "EDITBOX",
    ["Custom Message 1", "Custom message that can be used in the Chat Wheel. Custom messages support [tags]."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "Default",
    0,
    {
        [CWR_messagesHashMap, "Custom 1", _this] call CBA_fnc_hashSet;
    }
] call CBA_fnc_addSetting;

[
    "CWR_CustomMessages_2",
    "EDITBOX",
    ["Custom Message 2", "Custom message that can be used in the Chat Wheel. Custom messages support [tags]."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "Default",
    0,
    {
        [CWR_messagesHashMap, "Custom 2", _this] call CBA_fnc_hashSet;
    }
] call CBA_fnc_addSetting;

[
    "CWR_CustomMessages_3",
    "EDITBOX",
    ["Custom Message 3", "Custom message that can be used in the Chat Wheel. Custom messages support [tags]."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "Default",
    0,
    {
        [CWR_messagesHashMap, "Custom 3", _this] call CBA_fnc_hashSet;
    }
] call CBA_fnc_addSetting;

[
    "CWR_CustomMessages_4",
    "EDITBOX",
    ["Custom Message 4", "Custom message that can be used in the Chat Wheel. Custom messages support [tags]."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "Default",
    0,
    {
        [CWR_messagesHashMap, "Custom 4", _this] call CBA_fnc_hashSet;
    }
] call CBA_fnc_addSetting;

[
    "CWR_CustomMessages_5",
    "EDITBOX",
    ["Custom Message 5", "Custom message that can be used in the Chat Wheel. Custom messages support [tags]."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "Default",
    0,
    {
        [CWR_messagesHashMap, "Custom 5", _this] call CBA_fnc_hashSet;
    }
] call CBA_fnc_addSetting;

[
    "CWR_CustomMessages_6",
    "EDITBOX",
    ["Custom Message 6", "Custom message that can be used in the Chat Wheel. Custom messages support [tags]."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "Default",
    0,
    {
        [CWR_messagesHashMap, "Custom 6", _this] call CBA_fnc_hashSet;
    }
] call CBA_fnc_addSetting;

[
    "CWR_CustomMessages_7",
    "EDITBOX",
    ["Custom Message 7", "Custom message that can be used in the Chat Wheel. Custom messages support [tags]."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "Default",
    0,
    {
        [CWR_messagesHashMap, "Custom 7", _this] call CBA_fnc_hashSet;
    }
] call CBA_fnc_addSetting;

[
    "CWR_CustomMessages_8",
    "EDITBOX",
    ["Custom Message 8", "Custom message that can be used in the Chat Wheel. Custom messages support [tags]."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "Default",
    0,
    {
        [CWR_messagesHashMap, "Custom 8", _this] call CBA_fnc_hashSet;
    }
] call CBA_fnc_addSetting;

[
    "CWR_CustomMessages_9",
    "EDITBOX",
    ["Custom Message 9", "Custom message that can be used in the Chat Wheel. Custom messages support [tags]."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "Default",
    0,
    {
        [CWR_messagesHashMap, "Custom 9", _this] call CBA_fnc_hashSet;
    }
] call CBA_fnc_addSetting;

[
    "CWR_CustomMessages_10",
    "EDITBOX",
    ["Custom Message 10", "Custom message that can be used in the Chat Wheel. Custom messages support [tags]."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "Default",
    0,
    {
        [CWR_messagesHashMap, "Custom 10", _this] call CBA_fnc_hashSet;
    }
] call CBA_fnc_addSetting;

[
    "CWR_CustomMessages_11",
    "EDITBOX",
    ["Custom Message 11", "Custom message that can be used in the Chat Wheel. Custom messages support [tags]."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "Default",
    0,
    {
        [CWR_messagesHashMap, "Custom 11", _this] call CBA_fnc_hashSet;
    }
] call CBA_fnc_addSetting;

[
    "CWR_CustomMessages_12",
    "EDITBOX",
    ["Custom Message 12", "Custom message that can be used in the Chat Wheel. Custom messages support [tags]."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    "Default",
    0,
    {
        [CWR_messagesHashMap, "Custom 12", _this] call CBA_fnc_hashSet;
    }
] call CBA_fnc_addSetting;

// ============================================================================
// AUTOMATED MESSAGES - SEPARATE TOGGLES
// ============================================================================

[
    "CWR_AutoMessages_Grenades",
    "CHECKBOX",
    ["Grenade Callouts", "Automatically announce when throwing grenades or smoke."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    true,
    0,
    {}
] call CBA_fnc_addSetting;

if (isClass (configFile >> "CfgPatches" >> "ace_medical")) then
{
    [
        "CWR_AutoMessages_Uncon",
        "CHECKBOX",
        ["Unconscious Callouts", "When a player goes unconscious, the closest player will make a call out. The max radius is still bound by CWR_Voice_VoiceRadius."],
        ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
        true,
        0,
        {}
    ] call CBA_fnc_addSetting;
};

// ============================================================================
// VOICE LINE SETTINGS
// ============================================================================

[
    "CWR_Voice_VoiceRadius",
    "SLIDER",
    ["Voice Lines Radius", "The radius of voice lines and automated messages."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    [10, 50, 30, 0],
    0,
    {},
    false
] call CBA_fnc_addSetting;

[
    "CWR_Voice_VoiceVolume",
    "SLIDER",
    ["Voice Lines Volume", "Volume for custom voice lines."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    [0, 5, 3, 1]
] call CBA_fnc_addSetting;

[
    "CWR_Voice_EnableVoiceLines",
    "CHECKBOX",
    ["Enable Custom VoiceLines", "If enabled, you will hear voice lines when certain actions are done. Such as throwing a grenade, using a chat wheel option, etc."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    true,
    0,
    {},
    false
] call CBA_fnc_addSetting;

CWR_Voice_RCUnitsSendsMessages = false; // Wip
// [
//     "CWR_Voice_RCUnitsSendsMessages",
//     "CHECKBOX",
//     ["RC Units Send Messages", "If enabled, remote (zeus) controlled units will send messages and say voice lines."],
//     ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
//     true,
//     0,
//     {},
//     true
// ] call CBA_fnc_addSetting;

[
    "CWR_Voice_CoolDown",
    "SLIDER",
    ["Custom VoiceLines Cooldown", "The minimum amount of time between custom voicelines. This cooldown is per player."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    [0, 15, 3, 0],
    0,
    {},
    false
] call CBA_fnc_addSetting;


// ============================================================================
// DEVELOPER SETTINGS
// ============================================================================

[
    "CWR_Debug_ShowMessages",
    "CHECKBOX",
    ["CWR - Show Debug Messages", "Shows debug messages for Chat Wheel Redux, useful for trying to figure out if something is going wrong."],
    ["505th Expeditionary Force Aux Mod", "Chat Wheel Menu"],
    false,
    0,
    {},
    false
] call CBA_fnc_addSetting;
