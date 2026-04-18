#include "\a3\ui_f\hpp\defineDIKCodes.inc"

/*
    File: fn_configureAddonKeybinds.sqf
    Purpose:
    Registers CBA keybinds for the 505th chat system.
*/

// ============================================================================
// COMMS WHEEL NAVIGATION
// ============================================================================

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_OpenUI",
    "Open Comms Wheel",
    {
        [] call FEF_fnc_openUI;
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Confirm",
    "Comms Wheel Confirm (Enter)",
    {
        if !(missionNamespace getVariable ["FEF_UI_Open", false]) exitWith {};
        private _selectedIndex = missionNamespace getVariable ["FEF_UI_SelectedIndex", 0];
        private _scrollOffset  = missionNamespace getVariable ["FEF_UI_ScrollOffset", 0];
        [_selectedIndex - _scrollOffset] call FEF_fnc_onButtonClick;
    },
    {},
    [DIK_RETURN, [false, false, false]]
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_ConfirmSpace",
    "Comms Wheel Confirm (Space)",
    {
        if !(missionNamespace getVariable ["FEF_UI_Open", false]) exitWith {};
        private _selectedIndex = missionNamespace getVariable ["FEF_UI_SelectedIndex", 0];
        private _scrollOffset  = missionNamespace getVariable ["FEF_UI_ScrollOffset", 0];
        [_selectedIndex - _scrollOffset] call FEF_fnc_onButtonClick;
    },
    {},
    [DIK_SPACE, [false, false, false]]
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Close",
    "Comms Wheel Close/Back",
    {
        if !(missionNamespace getVariable ["FEF_UI_Open", false]) exitWith {};
        private _menuId = missionNamespace getVariable ["FEF_UI_CurrentMenu", "main"];
        if (_menuId == "main") then {
            [] call FEF_fnc_closeUI;
        } else {
            missionNamespace setVariable ["FEF_UI_SelectedIndex", 0];
            missionNamespace setVariable ["FEF_UI_ScrollOffset", 0];
            ["main", true] call FEF_fnc_renderMenu;
        };
    },
    {},
    [DIK_ESCAPE, [false, false, false]]
] call CBA_fnc_addKeybind;

// ============================================================================
// QUICK CALLOUTS
// ============================================================================

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_QuickMedic",
    "Quick: Need Medic",
    {
        ["I need a medic!", player, "NeedMedic"] call FEF_fnc_sendGroupMessage;
    },
    {},
    [DIK_NUMPAD0, [false, false, false]]
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_QuickAmmo",
    "Quick: Need Ammo",
    {
        ["Need ammo for [weapon]!", player, ""] call FEF_fnc_sendGroupMessage;
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_QuickMedicCheck",
    "Quick: Medic Check",
    {
        ["Medic check, report status!", player, ""] call FEF_fnc_sendGroupMessage;
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_QuickFriendlyDown",
    "Quick: Friendly Down",
    {
        [player] call FEF_fnc_sendFriendlyDownAlert;
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_QuickCombatReady",
    "Quick: Combat Ready",
    {
        ["Combat ready.", player, "MedicalCheckReady"] call FEF_fnc_sendGroupMessage;
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_QuickWounded",
    "Quick: Wounded",
    {
        ["Wounded.", player, "MedicalCheckWounded"] call FEF_fnc_sendGroupMessage;
    },
    {},
    []
] call CBA_fnc_addKeybind;

// ============================================================================
// QUICK CONTACT
// ============================================================================

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_QuickContactInfantry",
    "Quick: Contact Infantry",
    {
        ["Enemy infantry, bearing [bearing]!", player, ""] call FEF_fnc_sendGroupMessage;
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_QuickContactVehicle",
    "Quick: Contact Vehicle",
    {
        ["Enemy vehicle, bearing [bearing]!", player, ""] call FEF_fnc_sendGroupMessage;
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_QuickContactAir",
    "Quick: Contact Air",
    {
        ["Enemy air contact, bearing [bearing]!", player, ""] call FEF_fnc_sendGroupMessage;
    },
    {},
    []
] call CBA_fnc_addKeybind;

// ============================================================================
// CUSTOM MESSAGES 01-12
// ============================================================================

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Custom01",
    "Quick: Custom Message 01",
    {
        private _msg = missionNamespace getVariable ["FEF_Chat_CustomMessage_1", ""];
        if (_msg != "") then { [_msg, player, ""] call FEF_fnc_sendGroupMessage; };
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Custom02",
    "Quick: Custom Message 02",
    {
        private _msg = missionNamespace getVariable ["FEF_Chat_CustomMessage_2", ""];
        if (_msg != "") then { [_msg, player, ""] call FEF_fnc_sendGroupMessage; };
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Custom03",
    "Quick: Custom Message 03",
    {
        private _msg = missionNamespace getVariable ["FEF_Chat_CustomMessage_3", ""];
        if (_msg != "") then { [_msg, player, ""] call FEF_fnc_sendGroupMessage; };
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Custom04",
    "Quick: Custom Message 04",
    {
        private _msg = missionNamespace getVariable ["FEF_Chat_CustomMessage_4", ""];
        if (_msg != "") then { [_msg, player, ""] call FEF_fnc_sendGroupMessage; };
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Custom05",
    "Quick: Custom Message 05",
    {
        private _msg = missionNamespace getVariable ["FEF_Chat_CustomMessage_5", ""];
        if (_msg != "") then { [_msg, player, ""] call FEF_fnc_sendGroupMessage; };
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Custom06",
    "Quick: Custom Message 06",
    {
        private _msg = missionNamespace getVariable ["FEF_Chat_CustomMessage_6", ""];
        if (_msg != "") then { [_msg, player, ""] call FEF_fnc_sendGroupMessage; };
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Custom07",
    "Quick: Custom Message 07",
    {
        private _msg = missionNamespace getVariable ["FEF_Chat_CustomMessage_7", ""];
        if (_msg != "") then { [_msg, player, ""] call FEF_fnc_sendGroupMessage; };
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Custom08",
    "Quick: Custom Message 08",
    {
        private _msg = missionNamespace getVariable ["FEF_Chat_CustomMessage_8", ""];
        if (_msg != "") then { [_msg, player, ""] call FEF_fnc_sendGroupMessage; };
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Custom09",
    "Quick: Custom Message 09",
    {
        private _msg = missionNamespace getVariable ["FEF_Chat_CustomMessage_9", ""];
        if (_msg != "") then { [_msg, player, ""] call FEF_fnc_sendGroupMessage; };
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Custom10",
    "Quick: Custom Message 10",
    {
        private _msg = missionNamespace getVariable ["FEF_Chat_CustomMessage_10", ""];
        if (_msg != "") then { [_msg, player, ""] call FEF_fnc_sendGroupMessage; };
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Custom11",
    "Quick: Custom Message 11",
    {
        private _msg = missionNamespace getVariable ["FEF_Chat_CustomMessage_11", ""];
        if (_msg != "") then { [_msg, player, ""] call FEF_fnc_sendGroupMessage; };
    },
    {},
    []
] call CBA_fnc_addKeybind;

[
    ["505th Expeditionary Force Aux Mod", "Comms Wheel"],
    "FEF_Chat_Custom12",
    "Quick: Custom Message 12",
    {
        private _msg = missionNamespace getVariable ["FEF_Chat_CustomMessage_12", ""];
        if (_msg != "") then { [_msg, player, ""] call FEF_fnc_sendGroupMessage; };
    },
    {},
    []
] call CBA_fnc_addKeybind;
