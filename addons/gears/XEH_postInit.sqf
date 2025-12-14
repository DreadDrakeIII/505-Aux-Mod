#include "script_component.hpp"

// ============================================================================
// 505th Gears - OPTRE HUD + Medical Scanner
// ============================================================================

if (!hasInterface) exitWith {};

// === STEALTH MASK CONFIG ===
GVAR(maskClass) = QCLASS(Balaclava_OPTREHUD);
GVAR(hudActive) = false;
GVAR(lastGoggles) = "";

// === MEDICAL SCANNER CONFIG ===
GVAR(medGlassesClass) = QCLASS(Glasses_MedScanner);
GVAR(scannerActive) = false;
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
            diag_log "[EHB Gears] Stealth Mask removed -> HUD OFF";
        };

        // Medical Glasses equipped -> Auto-activate scanner
        if (_currentGoggles isEqualTo GVAR(medGlassesClass) && {!GVAR(scannerActive)}) then {
            [] call GVAR(fnc_startScanner);
            diag_log "[EHB Gears] Medical Glasses -> Scanner ON";
        };

        // Medical Glasses removed -> Deactivate scanner
        if (_currentGoggles isNotEqualTo GVAR(medGlassesClass) && {GVAR(scannerActive)}) then {
            [] call GVAR(fnc_stopScanner);
            diag_log "[EHB Gears] Medical Glasses removed -> Scanner OFF";
        };

    }, 0.5, []] call CBA_fnc_addPerFrameHandler;

    // Scroll action: Toggle Squad Cameras (Stealth Mask only)
    player addAction [
        "<t color='#00ffff'>[EHB] Toggle Squad Cameras</t>",
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
        "alive _target && 505th_gears_hudActive"
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
        "alive _target && 505th_gears_hudActive"
    ];

    // ========================================================================
    // MEDICAL SCANNER GLASSES
    // ========================================================================

    // Get medical status function
    GVAR(fnc_getMedicalStatus) = {
        params ["_unit"];

        if (!alive _unit) exitWith { ["DEAD", [0.3, 0.3, 0.3, 1], "KIA"] };

        private _blood = _unit getVariable ["ace_medical_bloodVolume", 6];
        private _pain = _unit getVariable ["ace_medical_pain", 0];
        private _heartRate = _unit getVariable ["ace_medical_heartRate", 80];
        private _unconscious = _unit getVariable ["ace_medical_stateUnconscious", false];
        private _bleeding = _unit getVariable ["ace_medical_woundBleeding", 0];
        private _inCardiacArrest = _unit getVariable ["ace_medical_stateCardiacArrest", false];

        // CASUALTY - Medic urgent (Red)
        if (_unconscious || _inCardiacArrest || _blood < 4.2 || _heartRate < 40 || _heartRate > 180 || _bleeding > 0.5) exitWith {
            ["CASUALTY", [1, 0, 0, 1], "CASUALTY - MEDIC URGENT", _blood, _heartRate, _bleeding, _unconscious]
        };

        // WOUNDED - Medic needed (Orange)
        if (_bleeding > 0 || _blood < 5.5 || _pain > 0.2 || _heartRate < 55 || _heartRate > 150) exitWith {
            ["WOUNDED", [1, 0.7, 0, 1], "WOUNDED - MEDIC NEEDED", _blood, _heartRate, _bleeding, _unconscious]
        };

        // COMBAT READY (Green)
        ["READY", [0, 1, 0, 1], "COMBAT READY", _blood, _heartRate, _bleeding, _unconscious]
    };

    // Start scanner function
    GVAR(fnc_startScanner) = {
        if (GVAR(scannerActive)) exitWith {};

        GVAR(scannerActive) = true;

        GVAR(scannerPFH) = [{
            if (!GVAR(scannerActive)) exitWith {
                [GVAR(scannerPFH)] call CBA_fnc_removePerFrameHandler;
                GVAR(scannerPFH) = -1;
            };

            private _nearUnits = (player nearEntities ["CAManBase", 50]) select {
                alive _x &&
                _x != player &&
                side _x == side player
            };

            {
                private _unit = _x;
                private _result = [_unit] call GVAR(fnc_getMedicalStatus);
                _result params ["_status", "_color", "_text", "_blood", "_hr", "_bleed", "_uncon"];

                private _pos = _unit modelToWorldVisual (_unit selectionPosition "spine3");
                _pos set [2, (_pos select 2) + 0.4];

                private _icon = switch (_status) do {
                    case "CASUALTY": { "\A3\ui_f\data\IGUI\Cfg\Actions\heal_ca.paa" };
                    case "WOUNDED": { "\A3\ui_f\data\IGUI\Cfg\Actions\heal_ca.paa" };
                    default { "\A3\ui_f\data\IGUI\Cfg\Actions\ico_on_ca.paa" };
                };

                drawIcon3D [
                    _icon,
                    _color,
                    _pos,
                    1.2,
                    1.2,
                    0,
                    format ["%1", name _unit],
                    2,
                    0.04,
                    "PuristaBold"
                ];

                private _textPos = _pos vectorAdd [0, 0, -0.15];
                drawIcon3D [
                    "",
                    _color,
                    _textPos,
                    0,
                    0,
                    0,
                    _text,
                    2,
                    0.03,
                    "PuristaMedium"
                ];

                if (cursorObject == _unit) then {
                    private _detailPos = _textPos vectorAdd [0, 0, -0.15];
                    private _bloodPercent = round ((_blood / 6) * 100);

                    drawIcon3D [
                        "",
                        [1, 1, 1, 0.9],
                        _detailPos,
                        0,
                        0,
                        0,
                        format ["Blood: %1%2 | HR: %3", _bloodPercent, "%", round _hr],
                        2,
                        0.025,
                        "PuristaMedium"
                    ];
                };

            } forEach _nearUnits;

        }, 0, []] call CBA_fnc_addPerFrameHandler;
    };

    // Stop scanner function
    GVAR(fnc_stopScanner) = {
        GVAR(scannerActive) = false;
        if (GVAR(scannerPFH) > -1) then {
            [GVAR(scannerPFH)] call CBA_fnc_removePerFrameHandler;
            GVAR(scannerPFH) = -1;
        };
    };

    diag_log "[505th Gears] System ready";

}] call CBA_fnc_waitUntilAndExecute;
