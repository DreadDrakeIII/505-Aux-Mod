[{
    kat_misc_treatmentTimeDetachTourniquet = OLI_tourni_removeTime;
}, [], 3] call CBA_fnc_waitAndExecute;

// ─── Per-limb necrosis tracker (server only) ──────────────────────────────────
[] call OLI_fnc_necrosisTracker;

// ─── Medical menu necrosis overlay PFH ───────────────────────────────────────
// Runs every 0.5s. Calls updateNecrosisOverlay only when the medical menu is
// actually open, so there is no cost when the menu is closed.
[{
    private _display = uiNamespace getVariable ["ace_medical_gui_menuDisplay", displayNull];
    if (!isNull _display) then {
        [] call OLI_fnc_updateNecrosisOverlay;
    };
}, 0.5] call CBA_fnc_addPerFrameHandler;



// ─── Combat Stim: locality change handler ────────────────────────────────────
// If a stimmed unit's locality transfers to this machine, restart the
// maintenance PFH so the stim continues uninterrupted.
["ace_medical_localityChanged", {
    params ["_unit"];
    if !(local _unit) exitWith {};
    if !(_unit getVariable ["OLI_stimActive", false]) exitWith {};

    private _startTime = _unit getVariable ["OLI_stimStartTime", 0];
    private _duration  = missionNamespace getVariable ["OLI_stim_duration", 120];

    if (CBA_missionTime - _startTime >= _duration) exitWith {
        _unit setVariable ["OLI_stimActive", false, true];
    };

    [_unit] call OLI_fnc_stimLocal;
}] call CBA_fnc_addEventHandler;

// OLI Tactical Trauma Kit - Replace ACE medical GUI body images with UNSC Marine
// Runs once at mission start, registers event handlers

private _basePath = "\BLU\OLI\addons\ttk\body_images\";

// Map of IDC -> texture filename
// IDCs from ace_medical_gui script_component.hpp
private _textureMap = [
    [6005, "marine_head.paa"],          // IDC_BODY_HEAD
    [6010, "marine_torso.paa"],         // IDC_BODY_TORSO
    [6015, "marine_arm_left.paa"],      // IDC_BODY_ARMLEFT
    [6020, "marine_arm_right.paa"],     // IDC_BODY_ARMRIGHT
    [6025, "marine_leg_left.paa"],      // IDC_BODY_LEGLEFT
    [6030, "marine_leg_right.paa"],     // IDC_BODY_LEGRIGHT
    [6035, "marine_arm_left_T.paa"],    // IDC_BODY_ARMLEFT_T
    [6040, "marine_arm_right_T.paa"],   // IDC_BODY_ARMRIGHT_T
    [6045, "marine_leg_left_T.paa"],    // IDC_BODY_LEGLEFT_T
    [6050, "marine_leg_right_T.paa"],   // IDC_BODY_LEGRIGHT_T
    [6055, "marine_arm_left_B.paa"],    // IDC_BODY_ARMLEFT_B
    [6060, "marine_arm_right_B.paa"],   // IDC_BODY_ARMRIGHT_B
    [6065, "marine_leg_left_B.paa"],    // IDC_BODY_LEGLEFT_B
    [6070, "marine_leg_right_B.paa"],   // IDC_BODY_LEGRIGHT_B
    [6080, "marine_head_S.paa"],        // IDC_BODY_HEAD_S
    [6085, "marine_torso_S.paa"],       // IDC_BODY_TORSO_S
    [6090, "marine_arm_left_S.paa"],    // IDC_BODY_ARMLEFT_S
    [6095, "marine_arm_right_S.paa"],   // IDC_BODY_ARMRIGHT_S
    [6100, "marine_leg_left_S.paa"],    // IDC_BODY_LEGLEFT_S
    [6105, "marine_leg_right_S.paa"]    // IDC_BODY_LEGRIGHT_S
];

// Store globally so the event handler can access it
OLI_TTK_textureMap = _textureMap;
OLI_TTK_basePath = _basePath;

// Hook into ACE medical menu opened event
["ace_medicalMenuOpened", {
    params ["_player", "_target", "_display"];

    private _ctrlGroup = _display displayCtrl 6000; // IDC_BODY_GROUP

    {
        _x params ["_idc", "_file"];
        private _ctrl = _ctrlGroup controlsGroupCtrl _idc;
        _ctrl ctrlSetText (OLI_TTK_basePath + _file);
    } forEach OLI_TTK_textureMap;

    // Background IDC is -1; it's the first control in the group
    private _allCtrls = allControls _ctrlGroup;
    if (count _allCtrls > 0) then {
        (_allCtrls select 0) ctrlSetText (OLI_TTK_basePath + "marine_background.paa");
    };
}] call CBA_fnc_addEventHandler;

// Also handle the passive IGUI patient info overlay
["ace_medical_gui_updateBodyImage", {
    params ["_ctrlGroup", "_target", "_selectionN"];

    {
        _x params ["_idc", "_file"];
        private _ctrl = _ctrlGroup controlsGroupCtrl _idc;
        if (!isNull _ctrl) then {
            _ctrl ctrlSetText (OLI_TTK_basePath + _file);
        };
    } forEach OLI_TTK_textureMap;

    private _allCtrls = allControls _ctrlGroup;
    if (count _allCtrls > 0) then {
        (_allCtrls select 0) ctrlSetText (OLI_TTK_basePath + "marine_background.paa");
    };
}] call CBA_fnc_addEventHandler;
