#include "script_component.hpp"

// ============================================================================
// 505th Gears - OPTRE HUD + Medical Scanner
// ============================================================================

if (!hasInterface) exitWith {};

// === STEALTH MASK CONFIG ===
GVAR(maskClass) = QCLASS(Stealth_Balaclava);
GVAR(hudActive) = false;
GVAR(lastGoggles) = "";

// === MEDICAL SCANNER CONFIG ===
GVAR(medGlassesClass) = QCLASS(Glasses_MedScanner);
GVAR(scannerActive) = false;
GVAR(scannerRunning) = false;
GVAR(scannerEnabled) = false;
GVAR(scannerPFH) = -1;

[{!isNull player}, {

    // ========================================================================
    // STEALTH BALACLAVA - OPTRE HUD
    // ========================================================================

    diag_log format ["[505th Gears] Stealth Mask: %1", GVAR(maskClass)];
    diag_log format ["[505th Gears] Medical Glasses: %1", GVAR(medGlassesClass)];

    // Initialize OPTRE variables
    if (isNil "OPTRE_Hud_On") then { OPTRE_Hud_On = false; };
    if (isNil "OPTRE_Hud_UnFullyLoaded") then { OPTRE_Hud_UnFullyLoaded = true; };
    if (isNil "OPTRE_LHD_Function") then { OPTRE_LHD_Function = 1; };
    if (isNil "OPTRE_Hud_RadarScale") then { OPTRE_Hud_RadarScale = 1; };
    if (isNil "OPTRE_Hud_RadarMode") then { OPTRE_Hud_RadarMode = 2; };
    if (isNil "OPTRE_HUD_CompassWanted") then { OPTRE_HUD_CompassWanted = true; };
    if (isNil "OPTREB_HUD_HelmetOnClass") then { OPTREB_HUD_HelmetOnClass = ""; };

    // Monitor goggles changes for STEALTH MASK
    [{
        params ["_args", "_handle"];

        private _currentGoggles = goggles player;

        if (_currentGoggles isEqualTo GVAR(lastGoggles)) exitWith {};
        GVAR(lastGoggles) = _currentGoggles;

        // Stealth Mask equipped -> Auto-activate OPTRE HUD
        if (_currentGoggles isEqualTo GVAR(maskClass) && {!GVAR(hudActive)}) then {

            OPTREB_HUD_HelmetOnClass = GVAR(maskClass);

            if (!isNil "OPTRE_fnc_ToggleVisor") then {
                OPTRE_Hud_On = false;
                OPTRE_Hud_UnFullyLoaded = true;
                false call OPTRE_fnc_ToggleVisor;
            } else {
                OPTRE_Hud_On = true;

                OPTRE_Hud_ColorScheme_Pictures = profileNamespace getVariable ["OPTRE_GLASS_HUDColourPictNEW", [1,1,0,0.7]];
                OPTRE_Hud_ColorScheme_Text = profileNamespace getVariable ["OPTRE_GLASS_HUDColourPictNEW", [0,0,0,0.9]];
                OPTRE_Hud_ColorScheme_Frame = profileNamespace getVariable ["OPTRE_GLASS_HUDColourPictNEW", [0,0,0,0.9]];

                OPTRE_Hud_MainCurrent = "OPTRE_MarrineGlasses_black";
                300 cutRsc [OPTRE_Hud_MainCurrent, "PLAIN", 0.5, false];

                OPTRE_Hud_LHDCurrent = "OPTRE_LHD_LeftBottom_Radar";
                303 cutRsc [OPTRE_Hud_LHDCurrent, "PLAIN", 0.5, false];
            };

            GVAR(hudActive) = true;
            diag_log "[505th Gears] Stealth Mask -> HUD ON";
        };

        // Stealth Mask removed -> Deactivate HUD
        if (_currentGoggles isNotEqualTo GVAR(maskClass) && {GVAR(hudActive)}) then {

            OPTRE_Hud_On = false;
            OPTRE_Hud_UnFullyLoaded = true;

            300 cutText ["", "PLAIN", 0.1];
            301 cutText ["", "PLAIN", 0.1];
            302 cutText ["", "PLAIN", 0.1];
            303 cutText ["", "PLAIN", 0.1];

            GVAR(hudActive) = false;
            diag_log "[505th Gears] Stealth Mask removed -> HUD OFF";
        };

        // Medical Glasses equipped -> Auto-activate scanner
        if (_currentGoggles isEqualTo GVAR(medGlassesClass) && {!GVAR(scannerRunning)}) then {
            [] call GVAR(fnc_startScanner);
            diag_log "[505th Gears] Medical Glasses -> Scanner ON";
        };

        // Medical Glasses removed -> Deactivate scanner
        if (_currentGoggles isNotEqualTo GVAR(medGlassesClass) && {GVAR(scannerRunning)}) then {
            [] call GVAR(fnc_stopScanner);
            diag_log "[505th Gears] Medical Glasses removed -> Scanner OFF";
        };

    }, 0.5, []] call CBA_fnc_addPerFrameHandler;

    // Scroll action: Toggle Squad Cameras (Stealth Mask only)
    player addAction [
        "<t color='#00ffff'>[505th] Toggle Squad Cameras</t>",
        {
            if (!GVAR(hudActive)) exitWith {};

            if (OPTRE_LHD_Function == 1) then {
                OPTRE_LHD_Function = 2;
                OPTRE_Hud_LHDCurrent = "OPTRE_LHD_LeftBottom_PIP";
                303 cutRsc ["OPTRE_LHD_LeftBottom_PIP", "PLAIN", 0.3, false];
            } else {
                OPTRE_LHD_Function = 1;
                OPTRE_Hud_LHDCurrent = "OPTRE_LHD_LeftBottom_Radar";
                303 cutRsc ["OPTRE_LHD_LeftBottom_Radar", "PLAIN", 0.3, false];
            };
        },
        [],
        1.5,
        false,
        true,
        "",
        "alive _target && OLI_gears_hudActive"
    ];

    // Scroll action: Toggle Nav Map (Stealth Mask only)
    player addAction [
        "<t color='#00ff00'>[505th] Toggle Nav Map</t>",
        {
            if (!GVAR(hudActive)) exitWith {};

            if (OPTRE_LHD_Function == 3) then {
                OPTRE_LHD_Function = 1;
                OPTRE_Hud_LHDCurrent = "OPTRE_LHD_LeftBottom_Radar";
                303 cutRsc ["OPTRE_LHD_LeftBottom_Radar", "PLAIN", 0.3, false];
            } else {
                OPTRE_LHD_Function = 3;
                OPTRE_Hud_LHDCurrent = "OPTRE_LHD_LeftBottom_HudMap";
                303 cutRsc ["OPTRE_LHD_LeftBottom_HudMap", "PLAIN", 0.3, false];
            };
        },
        [],
        1.4,
        false,
        true,
        "",
        "alive _target && OLI_gears_hudActive"
    ];

    // ========================================================================
    // MEDICAL SCANNER GLASSES - ACE + KAT Medical Support
    // ========================================================================

    GVAR(fnc_getMedicalStatus) = {
        params ["_unit"];

        // === ACE Medical Variables ===
        private _blood = _unit getVariable ["ace_medical_bloodVolume", 6];
        private _pain = _unit getVariable ["ace_medical_pain", 0];
        private _heartRate = _unit getVariable ["ace_medical_heartRate", 80];
        private _bleeding = _unit getVariable ["ace_medical_woundBleeding", 0];

        // === DOWN CHECK - Correct ACE variable ===
        private _isUnconscious = _unit getVariable ["ACE_isUnconscious", false];
        private _inCardiacArrest = _unit getVariable ["ace_medical_stateCardiacArrest", false];
        private _lifeState = lifeState _unit;
        private _isIncapacitated = _lifeState == "INCAPACITATED";

        // Combined down check
        private _isDown = _isUnconscious || _inCardiacArrest || _isIncapacitated;

        // === KAT Medical Variables ===
        private _airwayObstructed = (_unit getVariable ["kat_airway_obstructed", 0]) isEqualTo true || {(_unit getVariable ["kat_airway_obstructed", 0]) isEqualTo 1};
        private _airwayOccluded = (_unit getVariable ["kat_airway_occluded", 0]) isEqualTo true || {(_unit getVariable ["kat_airway_occluded", 0]) isEqualTo 1};
        private _pneumothorax = (_unit getVariable ["kat_breathing_pneumothorax", 0]) isEqualTo true || {(_unit getVariable ["kat_breathing_pneumothorax", 0]) isEqualTo 1};
        private _hemothorax = (_unit getVariable ["kat_breathing_hemothorax", 0]) isEqualTo true || {(_unit getVariable ["kat_breathing_hemothorax", 0]) isEqualTo 1};
        private _tensionPneumothorax = (_unit getVariable ["kat_breathing_tensionPneumothorax", 0]) isEqualTo true || {(_unit getVariable ["kat_breathing_tensionPneumothorax", 0]) isEqualTo 1};
        private _needsSurgery = (_unit getVariable ["kat_surgery_requiredSurgery", 0]) isEqualTo true || {(_unit getVariable ["kat_surgery_requiredSurgery", 0]) isEqualTo 1};
        private _opioids = _unit getVariable ["ace_medical_opioids", 0];
        private _opioidOD = if (_opioids isEqualType 0) then { _opioids > 0.8 } else { false };

        // Check open wounds
        private _hasOpenWounds = false;
        private _allWounds = _unit getVariable ["ace_medical_openWounds", createHashMap];
        if (_allWounds isEqualType createHashMap) then {
            { if (count _y > 0) exitWith { _hasOpenWounds = true; }; } forEach _allWounds;
        };
        if (_allWounds isEqualType []) then {
            if (count _allWounds > 0) then { _hasOpenWounds = true; };
        };

        // Check stitched wounds
        private _needsStitches = false;
        private _stitchedWounds = _unit getVariable ["ace_medical_stitchedWounds", createHashMap];
        if (_stitchedWounds isEqualType createHashMap) then {
            { if (count _y > 0) exitWith { _needsStitches = true; }; } forEach _stitchedWounds;
        };

        // === CASUALTY (Red) - Unit is DOWN ===
        if (_isDown) exitWith {
            ["CASUALTY", [1, 0, 0, 1], "CASUALTY - MEDIC URGENT", _blood, _heartRate, _bleeding, true]
        };

        // === WOUNDED (Orange) ===
        if (
            _bleeding > 0 ||
            {_hasOpenWounds} ||
            {_blood < 5.0} ||
            {_pain > 0.3} ||
            {_heartRate < 50} ||
            {_heartRate > 160} ||
            {_pneumothorax} ||
            {_hemothorax} ||
            {_needsSurgery} ||
            {_needsStitches} ||
            {_airwayObstructed} ||
            {_airwayOccluded} ||
            {_tensionPneumothorax} ||
            {_opioidOD}
        ) exitWith {
            ["WOUNDED", [1, 0.7, 0, 1], "WOUNDED - MEDIC NEEDED", _blood, _heartRate, _bleeding, false]
        };

        // === COMBAT READY (Green) ===
        ["READY", [0, 1, 0, 1], "COMBAT READY", _blood, _heartRate, _bleeding, false]
    };

    // ========================================================================
    // Start scanner PFH
    // ========================================================================
    GVAR(fnc_startScanner) = {
        if (GVAR(scannerRunning)) exitWith {};

        GVAR(scannerRunning) = true;
        GVAR(scannerEnabled) = true;

        GVAR(scannerPFH) = [{
            // Stop entirely if glasses removed
            if ((goggles player) isNotEqualTo GVAR(medGlassesClass)) exitWith {
                [GVAR(scannerPFH)] call CBA_fnc_removePerFrameHandler;
                GVAR(scannerPFH) = -1;
                GVAR(scannerRunning) = false;
                GVAR(scannerEnabled) = false;
            };

            if (!GVAR(scannerEnabled)) exitWith {};

            private _nearUnits = (player nearEntities ["CAManBase", 50]) select {
                alive _x && _x != player && side _x == side player
            };

            {
                private _unit = _x;

                private _result = [_unit] call GVAR(fnc_getMedicalStatus);
                _result params ["_status", "_color", "_text", "_blood", "_hr", "_bleed", "_isDown"];

                private _pos = if (_isDown) then {
                    private _groundPos = getPos _unit;
                    [_groundPos select 0, _groundPos select 1, (_groundPos select 2) + 1.5]
                } else {
                    private _modelPos = _unit modelToWorldVisual (_unit selectionPosition "spine3");
                    _modelPos set [2, (_modelPos select 2) + 0.4];
                    _modelPos
                };

                // Fixed icon switch - matches status names
                private _icon = switch (_status) do {
                    case "CASUALTY": { "\A3\ui_f\data\IGUI\Cfg\Actions\warning_ca.paa" };
                    case "WOUNDED":  { "\A3\ui_f\data\IGUI\Cfg\Actions\heal_ca.paa" };
                    default          { "\A3\ui_f\data\IGUI\Cfg\Actions\ico_on_ca.paa" };
                };

                // Icon only (no name)
                drawIcon3D [_icon, _color, _pos, 1.2, 1.2, 0, "", 2, 0.04, "PuristaBold"];

                // Status text only
                private _textPos = _pos vectorAdd [0, 0, -0.15];
                drawIcon3D ["", _color, _textPos, 0, 0, 0, _text, 2, 0.03, "PuristaMedium"];

            } forEach _nearUnits;

        }, 0, []] call CBA_fnc_addPerFrameHandler;
    };

    // ========================================================================
    // Stop scanner display
    // ========================================================================
    GVAR(fnc_stopScanner) = {
        GVAR(scannerEnabled) = false;
        GVAR(scannerRunning) = false;
        if (GVAR(scannerPFH) > -1) then {
            [GVAR(scannerPFH)] call CBA_fnc_removePerFrameHandler;
            GVAR(scannerPFH) = -1;
        };
    };

    // ========================================================================
    // Scroll action: Toggle Medical Scanner (Manual)
    // ========================================================================
    player addAction [
        "<t color='#00ff00'>[505th] Medical Scanner</t>",
        {
            if ((goggles player) isNotEqualTo GVAR(medGlassesClass)) exitWith {};

            if (GVAR(scannerEnabled)) then {
                GVAR(scannerEnabled) = false;
            } else {
                if (!GVAR(scannerRunning)) then {
                    [] call GVAR(fnc_startScanner);
                } else {
                    GVAR(scannerEnabled) = true;
                };
            };
        },
        [],
        1.5,
        false,
        true,
        "",
        "alive _target && (goggles _target) isEqualTo OLI_gears_medGlassesClass"
    ];

    diag_log "[505th Gears] System ready";

}] call CBA_fnc_waitUntilAndExecute;
