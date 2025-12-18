#include "script_component.hpp"

// ============================================================================
// 505th Gears - OPTRE HUD + Medical Scanner (5-Tier Triage System)
// ============================================================================

if (!hasInterface) exitWith {};

// === STEALTH MASK CONFIG ===
GVAR(maskClass) = QCLASS(Stealth_Balaclava);
GVAR(hudActive) = false;
GVAR(lastGoggles) = "";
GVAR(hudHiddenForOptics) = false;

// === MEDICAL SCANNER CONFIG ===
GVAR(medGlassesClass) = QCLASS(Glasses_MedScanner);
GVAR(scannerActive) = false;
GVAR(vitalsEnabled) = false;
GVAR(scannerRunning) = false;
GVAR(scannerEnabled) = false;
GVAR(scannerEH) = -1;

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
        format ["alive _target && %1", QGVAR(hudActive)]
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
        format ["alive _target && %1", QGVAR(hudActive)]
    ];

    // ========================================================================
    // MEDICAL SCANNER GLASSES - 5-Tier Triage System (ACE + KAT)
    // Based on 505th Corpsman Feedback
    // Colors: RED / ORANGE / YELLOW / BLUE / GREEN
    // Display: CASUALTY / WOUNDED / WOUNDED / WOUNDED / COMBAT READY
    // Range: 25m overhead icons, 5m detailed vitals
    // ========================================================================

    GVAR(fnc_getMedicalStatus) = {
        params ["_unit"];

        // === ACE Medical Variables ===
        private _blood = _unit getVariable ["ace_medical_bloodVolume", 6.0];
        private _pain = _unit getVariable ["ace_medical_pain", 0];
        private _heartRate = _unit getVariable ["ace_medical_heartRate", 80];
        private _bleeding = _unit getVariable ["ace_medical_woundBleeding", 0];

        // === Down Detection (MP-safe) ===
        private _isIncapacitated = (lifeState _unit) isEqualTo "INCAPACITATED";

        private _isAwake = true;
        if (!isNil "ace_common_fnc_isAwake") then {
            _isAwake = [_unit] call ace_common_fnc_isAwake;
        };

        private _inCardiacArrest =
            (_unit getVariable ["ace_medical_stateCardiacArrest", false]) ||
            (_unit getVariable ["ace_medical_inCardiacArrest", false]);

        private _isDown = _isIncapacitated || !_isAwake || _inCardiacArrest;

        // === KAT Medical Variables ===
        private _airwayObstructed = (_unit getVariable ["kat_airway_obstructed", 0]) isEqualTo true || {(_unit getVariable ["kat_airway_obstructed", 0]) isEqualTo 1};
        private _airwayOccluded = (_unit getVariable ["kat_airway_occluded", 0]) isEqualTo true || {(_unit getVariable ["kat_airway_occluded", 0]) isEqualTo 1};
        private _pneumothorax = (_unit getVariable ["kat_breathing_pneumothorax", 0]) isEqualTo true || {(_unit getVariable ["kat_breathing_pneumothorax", 0]) isEqualTo 1};
        private _hemothorax = (_unit getVariable ["kat_breathing_hemothorax", 0]) isEqualTo true || {(_unit getVariable ["kat_breathing_hemothorax", 0]) isEqualTo 1};
        private _tensionPneumothorax = (_unit getVariable ["kat_breathing_tensionPneumothorax", 0]) isEqualTo true || {(_unit getVariable ["kat_breathing_tensionPneumothorax", 0]) isEqualTo 1};
        private _needsSurgery = (_unit getVariable ["kat_surgery_requiredSurgery", 0]) isEqualTo true || {(_unit getVariable ["kat_surgery_requiredSurgery", 0]) isEqualTo 1};
        private _opioids = _unit getVariable ["ace_medical_opioids", 0];
        private _opioidOD = if (_opioids isEqualType 0) then { _opioids > 0.8 } else { false };

        // === Chest Seal Check ===
        private _hasChestSeal =
            (_unit getVariable ["kat_breathing_chestseal", false]) ||
            (_unit getVariable ["kat_breathing_leftLung_chestseal", false]) ||
            (_unit getVariable ["kat_breathing_rightLung_chestseal", false]);

        // === Fracture Check ===
        private _hasFracture = false;
        private _fractures = _unit getVariable ["ace_medical_fractures", []];
        if (_fractures isEqualType []) then {
            { if (_x > 0) exitWith { _hasFracture = true; }; } forEach _fractures;
        };

        // === Wound Analysis ===
        // ClassIDs: 0=Abrasion, 1=Avulsion, 2=Contusion, 3=Crush, 4=Cut, 5=Laceration, 6=Velocity, 7=Puncture
        private _openWoundCount = 0;
        private _severeWoundCount = 0;
        private _minorOnlyWounds = true;

        private _allWounds = _unit getVariable ["ace_medical_openWounds", createHashMap];
        if (_allWounds isEqualType createHashMap) then {
            {
                private _wounds = _y;
                {
                    _x params [["_classID", 0], ["_amountOf", 0], ["_bleedRate", 0]];
                    _openWoundCount = _openWoundCount + _amountOf;

                    // Severe wounds: Avulsion(1), Velocity(6), Puncture(7) with high bleeding
                    if (_classID in [1, 6, 7] || _bleedRate > 0.3) then {
                        _severeWoundCount = _severeWoundCount + _amountOf;
                        _minorOnlyWounds = false;
                    };

                    // Check if NOT minor (Abrasion(0) or Contusion(2) with light bleeding)
                    if !(_classID in [0, 2] && _bleedRate < 0.1) then {
                        _minorOnlyWounds = false;
                    };
                } forEach _wounds;
            } forEach _allWounds;
        } else {
            if (_allWounds isEqualType []) then {
                _openWoundCount = count _allWounds;
                if (_openWoundCount > 0) then { _minorOnlyWounds = false; };
            };
        };

        // === Bandaged Wounds (needs stitches) ===
        private _bandagedCount = 0;
        private _bandagedWounds = _unit getVariable ["ace_medical_bandagedWounds", createHashMap];
        if (_bandagedWounds isEqualType createHashMap) then {
            { _bandagedCount = _bandagedCount + (count _y); } forEach _bandagedWounds;
        };

        // === Stitched Wounds ===
        private _stitchCount = 0;
        private _stitchedWounds = _unit getVariable ["ace_medical_stitchedWounds", createHashMap];
        if (_stitchedWounds isEqualType createHashMap) then {
            { _stitchCount = _stitchCount + (count _y); } forEach _stitchedWounds;
        };

        // === Treatment Checks ===
        private _hasChestTrauma = _pneumothorax || _hemothorax || _tensionPneumothorax;
        private _hasAirwayIssue = _airwayObstructed || _airwayOccluded;

        // Needs stitches only: bandaged, no open wounds, no active bleeding, no serious conditions
        private _needsStitchesOnly = (
            _bandagedCount > 0 &&
            _openWoundCount == 0 &&
            _bleeding == 0 &&
            !_hasFracture &&
            !_hasAirwayIssue &&
            (!_hasChestTrauma || _hasChestSeal) &&
            !_opioidOD &&
            !_needsSurgery &&
            _blood >= 4.5
        );

        // Chest seal applied, stabilized but still has chest trauma
        private _chestSealStabilized = _hasChestTrauma && _hasChestSeal;

        // ========================================================================
        // CLASSIFICATION - 5 Tier System
        // ========================================================================

        // RED - CASUALTY (Down only)
        if (_isDown) exitWith {
            ["CRITICAL", [0.8, 0, 0, 1], "CASUALTY", 100, true]
        };

        // ORANGE - WOUNDED Serious
        // Deep penetration, heavy blood loss, explosion, airway/breathing stopped
        if (
            _severeWoundCount >= 2 ||
            {_bleeding > 0.4} ||
            {_blood < 4.2} ||
            {_hasAirwayIssue} ||
            {_hasChestTrauma && !_hasChestSeal} ||
            {_opioidOD} ||
            {_heartRate < 50 || _heartRate > 170}
        ) exitWith {
            ["PRIORITY", [1, 0.4, 0, 1], "WOUNDED", 75, false]
        };

        // YELLOW - WOUNDED Minor
        // Open wounds bleeding, fractures
        if (
            (_openWoundCount > 0 && !_minorOnlyWounds) ||
            {_bleeding > 0.1} ||
            {_hasFracture} ||
            {_needsSurgery}
        ) exitWith {
            ["MINOR", [1, 1, 0, 1], "WOUNDED", 50, false]
        };

        // BLUE - WOUNDED (Needs stitches only OR chest seal stabilized)
        if (_needsStitchesOnly || _chestSealStabilized) exitWith {
            ["STABLE", [0.2, 0.6, 1, 1], "WOUNDED", 25, false]
        };

        // GREEN - COMBAT READY
        // Recovered, minor scrape/bruise, or never hurt
        ["READY", [0, 0.9, 0, 1], "COMBAT READY", 0, false]
    };

    // ========================================================================
    // Detailed vitals for cursorTarget inspection
    // ========================================================================
    GVAR(fnc_getDetailedVitals) = {
        params ["_unit"];

        private _hr = _unit getVariable ["ace_medical_heartRate", 80];
        private _blood = _unit getVariable ["ace_medical_bloodVolume", 6.0];
        private _bloodPercent = round((_blood / 6.0) * 100);

        private _spo2 = _unit getVariable ["kat_breathing_oxygenSaturation", 100];
        private _respRate = _unit getVariable ["kat_breathing_respirationRate", 16];

        if (isNil "kat_breathing_oxygenSaturation") then {
            _spo2 = linearConversion [3.0, 6.0, _blood, 70, 99, true];
            _spo2 = round _spo2;
            _respRate = linearConversion [40, 180, _hr, 8, 30, true];
            _respRate = round _respRate;
        };

        private _hrColor = switch (true) do {
            case (_hr < 45 || _hr > 180): { [1, 0, 0, 1] };
            case (_hr < 55 || _hr > 140): { [1, 0.6, 0, 1] };
            case (_hr < 60 || _hr > 100): { [1, 1, 0, 1] };
            default { [0, 1, 0, 1] };
        };

        private _bloodColor = switch (true) do {
            case (_bloodPercent < 50): { [1, 0, 0, 1] };
            case (_bloodPercent < 70): { [1, 0.6, 0, 1] };
            case (_bloodPercent < 85): { [1, 1, 0, 1] };
            default { [0, 1, 0, 1] };
        };

        private _spo2Color = switch (true) do {
            case (_spo2 < 80): { [1, 0, 0, 1] };
            case (_spo2 < 90): { [1, 0.6, 0, 1] };
            case (_spo2 < 95): { [1, 1, 0, 1] };
            default { [0, 1, 0, 1] };
        };

        private _respColor = switch (true) do {
            case (_respRate < 8 || _respRate > 30): { [1, 0, 0, 1] };
            case (_respRate < 12 || _respRate > 24): { [1, 1, 0, 1] };
            default { [0, 1, 0, 1] };
        };

        [
            ["HR", _hr, "bpm", _hrColor],
            ["BLOOD", _bloodPercent, "%", _bloodColor],
            ["SpO2", _spo2, "%", _spo2Color],
            ["RESP", _respRate, "/min", _respColor]
        ]
    };

    // ========================================================================
    // Start scanner - Uses Draw3D event handler
    // ========================================================================
    GVAR(fnc_startScanner) = {
        if (GVAR(scannerRunning)) exitWith {};

        GVAR(scannerRunning) = true;
        GVAR(scannerEnabled) = true;

        GVAR(scannerEH) = addMissionEventHandler ["Draw3D", {
            if ((goggles player) isNotEqualTo GVAR(medGlassesClass)) exitWith {
                removeMissionEventHandler ["Draw3D", GVAR(scannerEH)];
                GVAR(scannerEH) = -1;
                GVAR(scannerRunning) = false;
                GVAR(scannerEnabled) = false;
            };

            if (!GVAR(scannerEnabled)) exitWith {};

            // Get nearby friendlies within 25m, exclude Zeus and dead
            private _nearUnits = (player nearEntities ["CAManBase", 25]) select {
                _x != player &&
                {lifeState _x != "DEAD"} &&
                {side group _x == side group player} &&
                {isNull (getAssignedCuratorLogic _x)}
            };

            // Draw overhead triage icons
            {
                private _unit = _x;
                private _result = [_unit] call GVAR(fnc_getMedicalStatus);
                _result params ["_status", "_color", "_text", "_severity", "_isDown"];

                private _pos = if (_isDown) then {
                    (getPos _unit) vectorAdd [0, 0, 1.5]
                } else {
                    (_unit modelToWorldVisual (_unit selectionPosition "spine3")) vectorAdd [0, 0, 0.4]
                };

                private _icon = switch (_status) do {
                    case "CRITICAL": { "\A3\ui_f\data\IGUI\Cfg\Revive\overlayIcons\u100_ca.paa" };
                    case "PRIORITY": { "\A3\ui_f\data\IGUI\Cfg\Actions\heal_ca.paa" };
                    case "MINOR":    { "\A3\ui_f\data\IGUI\Cfg\Actions\bandage_ca.paa" };
                    case "STABLE":   { "\A3\ui_f\data\IGUI\Cfg\Actions\ico_cpt_ca.paa" };
                    default          { "\A3\ui_f\data\IGUI\Cfg\Actions\ico_on_ca.paa" };
                };

                drawIcon3D [_icon, _color, _pos, 1.2, 1.2, 0, "", 2, 0.04, "PuristaBold"];
                drawIcon3D ["", _color, _pos vectorAdd [0, 0, -0.15], 0, 0, 0, _text, 2, 0.03, "PuristaMedium"];

            } forEach _nearUnits;

            // Detailed vitals when looking at target within 5m (if enabled)
            if (!GVAR(vitalsEnabled)) exitWith {};

            private _target = cursorTarget;

            if (
                !isNull _target &&
                {alive _target} &&
                {_target isKindOf "CAManBase"} &&
                {_target != player} &&
                {side group _target == side group player} &&
                {(player distance _target) <= 5}
            ) then {
                private _vitals = [_target] call GVAR(fnc_getDetailedVitals);

                private _basePos = _target modelToWorldVisual (_target selectionPosition "spine3");
                _basePos = _basePos vectorAdd [0.6, 0, 0.3];

                drawIcon3D ["", [1, 1, 1, 1], _basePos vectorAdd [0, 0, 0.2], 0, 0, 0, "── VITALS ──", 2, 0.032, "PuristaBold"];

                private _offsetZ = 0;
                {
                    _x params ["_label", "_value", "_vitalUnit", "_vitalColor"];
                    drawIcon3D ["", _vitalColor, _basePos vectorAdd [0, 0, _offsetZ], 0, 0, 0, format ["%1: %2 %3", _label, _value, _vitalUnit], 2, 0.030, "PuristaMedium"];
                    _offsetZ = _offsetZ - 0.1;
                } forEach _vitals;
            };
        }];
    };

    // ========================================================================
    // Stop scanner
    // ========================================================================
    GVAR(fnc_stopScanner) = {
        GVAR(scannerEnabled) = false;
        GVAR(scannerRunning) = false;
        if (GVAR(scannerEH) > -1) then {
            removeMissionEventHandler ["Draw3D", GVAR(scannerEH)];
            GVAR(scannerEH) = -1;
        };
    };

    // ========================================================================
    // Scroll action: Toggle Medical Scanner
    // ========================================================================
    player addAction [
        "<t color='#00ff00'>[505th] Medical Scanner</t>",
        {
            if ((goggles player) isNotEqualTo GVAR(medGlassesClass)) exitWith {};

            if (!GVAR(scannerRunning)) exitWith { [] call GVAR(fnc_startScanner); };
            GVAR(scannerEnabled) = !GVAR(scannerEnabled);

            private _status = ["OFF", "ON"] select GVAR(scannerEnabled);
            systemChat format ["[Medical Scanner] %1", _status];
        },
        [],
        1.5,
        false,
        true,
        "",
        format ["alive _target && (goggles _target) isEqualTo %1", QGVAR(medGlassesClass)]
    ];

    // ========================================================================
    // Scroll action: Toggle Detailed Vitals
    // ========================================================================
    player addAction [
        "<t color='#00ffff'>[505th] Toggle Detailed Vitals</t>",
        {
            if ((goggles player) isNotEqualTo GVAR(medGlassesClass)) exitWith {};
            if (!GVAR(scannerRunning)) exitWith {};

            GVAR(vitalsEnabled) = !GVAR(vitalsEnabled);

            private _status = ["OFF", "ON"] select GVAR(vitalsEnabled);
            systemChat format ["[Medical Scanner] Detailed Vitals: %1", _status];
        },
        [],
        1.4,
        false,
        true,
        "",
        format ["alive _target && (goggles _target) isEqualTo %1 && %2", QGVAR(medGlassesClass), QGVAR(scannerRunning)]
    ];

    diag_log "[505th Gears] 5-Tier Medical Scanner ready (25m range)";

}] call CBA_fnc_waitUntilAndExecute;
