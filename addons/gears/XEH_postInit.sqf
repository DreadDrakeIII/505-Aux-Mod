#include "script_component.hpp"

// ============================================================================
// 505th Gears - TCP VISR HUD + Medical Scanner (5-Tier Triage System)
// ============================================================================

if (!hasInterface) exitWith {};

// === STEALTH MASK CONFIG ===
GVAR(hudMasks) = [
    QCLASS(Stealth_Mask_Glasses)
];
GVAR(hudActive) = false;

// === MEDICAL SCANNER CONFIG ===
GVAR(medGlassesClass) = QCLASS(Glasses_MedScanner);
GVAR(scannerActive) = false;
GVAR(vitalsEnabled) = false;
GVAR(scannerRunning) = false;
GVAR(scannerEnabled) = false;
GVAR(scannerEH) = -1;

[{!isNull player}, {

    diag_log format ["[505th Gears] Stealth Mask classes: %1", GVAR(hudMasks)];
    diag_log format ["[505th Gears] Medical Glasses: %1", GVAR(medGlassesClass)];

    // ========================================================================
    // STEALTH BALACLAVA - TCP VISR HUD
    // ========================================================================

    player addEventHandler ["SlotItemChanged", {
        params ["_unit", "_name", "_slot", "_assigned"];

        if (_slot != 603) exitWith {}; // 603 = goggles slot

        private _goggles = goggles _unit;

        // Mask equipped -> activate TCP VISR
        if (_assigned && {_goggles in GVAR(hudMasks)} && {!GVAR(hudActive)}) then {
            [_unit, "", true] call TCP_fnc_visrToggleActive;
            GVAR(hudActive) = true;
            diag_log "[505th Gears] Stealth Mask -> TCP VISR ON";
        };

        // Mask removed -> deactivate TCP VISR
        if (!_assigned && {GVAR(hudActive)}) then {
            [_unit, "", false] call TCP_fnc_visrToggleActive;
            GVAR(hudActive) = false;
            diag_log "[505th Gears] Stealth Mask removed -> TCP VISR OFF";
        };

        // Medical Glasses equipped
        if (_assigned && {_goggles isEqualTo GVAR(medGlassesClass)} && {!GVAR(scannerActive)}) then {
            [] call GVAR(fnc_startScanner);
            diag_log "[505th Gears] Medical Glasses -> Scanner ON";
        };

        // Medical Glasses removed
        if (!_assigned && {GVAR(scannerActive)}) then {
            [] call GVAR(fnc_stopScanner);
            diag_log "[505th Gears] Medical Glasses removed -> Scanner OFF";
        };
    }];

    // Handle case where mask/glasses already equipped on login
    if (goggles player in GVAR(hudMasks)) then {
        [player, "", true] call TCP_fnc_visrToggleActive;
        GVAR(hudActive) = true;
        diag_log "[505th Gears] Mask on login -> TCP VISR ON";
    };

    if (goggles player isEqualTo GVAR(medGlassesClass)) then {
        [] call GVAR(fnc_startScanner);
    };

    // ========================================================================
    // MEDICAL SCANNER GLASSES - 5-Tier Triage System (ACE + KAT)
    // Colors: RED / ORANGE / YELLOW / BLUE / GREEN
    // Display: CASUALTY / WOUNDED / WOUNDED / WOUNDED / COMBAT READY
    // Range: 25m overhead icons, 5m detailed vitals
    // ========================================================================

    GVAR(fnc_getMedicalStatus) = {
        params ["_unit"];

        private _blood = _unit getVariable ["ace_medical_bloodVolume", 6.0];
        private _pain = _unit getVariable ["ace_medical_pain", 0];
        private _heartRate = _unit getVariable ["ace_medical_heartRate", 80];
        private _bleeding = _unit getVariable ["ace_medical_woundBleeding", 0];

        private _isIncapacitated = (lifeState _unit) isEqualTo "INCAPACITATED";

        private _isAwake = true;
        if (!isNil "ace_common_fnc_isAwake") then {
            _isAwake = [_unit] call ace_common_fnc_isAwake;
        };

        private _inCardiacArrest =
            (_unit getVariable ["ace_medical_stateCardiacArrest", false]) ||
            (_unit getVariable ["ace_medical_inCardiacArrest", false]);

        private _isDown = _isIncapacitated || !_isAwake || _inCardiacArrest;

        private _airwayObstructed = (_unit getVariable ["kat_airway_obstructed", 0]) isEqualTo true || {(_unit getVariable ["kat_airway_obstructed", 0]) isEqualTo 1};
        private _airwayOccluded = (_unit getVariable ["kat_airway_occluded", 0]) isEqualTo true || {(_unit getVariable ["kat_airway_occluded", 0]) isEqualTo 1};
        private _pneumothorax = (_unit getVariable ["kat_breathing_pneumothorax", 0]) isEqualTo true || {(_unit getVariable ["kat_breathing_pneumothorax", 0]) isEqualTo 1};
        private _hemothorax = (_unit getVariable ["kat_breathing_hemothorax", 0]) isEqualTo true || {(_unit getVariable ["kat_breathing_hemothorax", 0]) isEqualTo 1};
        private _tensionPneumothorax = (_unit getVariable ["kat_breathing_tensionPneumothorax", 0]) isEqualTo true || {(_unit getVariable ["kat_breathing_tensionPneumothorax", 0]) isEqualTo 1};
        private _needsSurgery = (_unit getVariable ["kat_surgery_requiredSurgery", 0]) isEqualTo true || {(_unit getVariable ["kat_surgery_requiredSurgery", 0]) isEqualTo 1};
        private _opioids = _unit getVariable ["ace_medical_opioids", 0];
        private _opioidOD = if (_opioids isEqualType 0) then { _opioids > 0.8 } else { false };

        private _hasChestSeal =
            (_unit getVariable ["kat_breathing_chestseal", false]) ||
            (_unit getVariable ["kat_breathing_leftLung_chestseal", false]) ||
            (_unit getVariable ["kat_breathing_rightLung_chestseal", false]);

        private _hasFracture = false;
        private _fractures = _unit getVariable ["ace_medical_fractures", []];
        if (_fractures isEqualType []) then {
            { if (_x > 0) exitWith { _hasFracture = true; }; } forEach _fractures;
        };

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
                    if (_classID in [1, 6, 7] || _bleedRate > 0.3) then {
                        _severeWoundCount = _severeWoundCount + _amountOf;
                        _minorOnlyWounds = false;
                    };
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

        private _bandagedCount = 0;
        private _bandagedWounds = _unit getVariable ["ace_medical_bandagedWounds", createHashMap];
        if (_bandagedWounds isEqualType createHashMap) then {
            { _bandagedCount = _bandagedCount + (count _y); } forEach _bandagedWounds;
        };

        private _stitchCount = 0;
        private _stitchedWounds = _unit getVariable ["ace_medical_stitchedWounds", createHashMap];
        if (_stitchedWounds isEqualType createHashMap) then {
            { _stitchCount = _stitchCount + (count _y); } forEach _stitchedWounds;
        };

        private _hasChestTrauma = _pneumothorax || _hemothorax || _tensionPneumothorax;
        private _hasAirwayIssue = _airwayObstructed || _airwayOccluded;

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

        private _chestSealStabilized = _hasChestTrauma && _hasChestSeal;

        if (_isDown) exitWith {
            ["CRITICAL", [0.8, 0, 0, 1], "CASUALTY", 100, true]
        };
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
        if (
            (_openWoundCount > 0 && !_minorOnlyWounds) ||
            {_bleeding > 0.1} ||
            {_hasFracture} ||
            {_needsSurgery}
        ) exitWith {
            ["MINOR", [1, 1, 0, 1], "WOUNDED", 50, false]
        };
        if (_needsStitchesOnly || _chestSealStabilized) exitWith {
            ["STABLE", [0.2, 0.6, 1, 1], "WOUNDED", 25, false]
        };

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
        GVAR(scannerActive) = true;

        GVAR(scannerEH) = addMissionEventHandler ["Draw3D", {
            if ((goggles player) isNotEqualTo GVAR(medGlassesClass)) exitWith {
                removeMissionEventHandler ["Draw3D", GVAR(scannerEH)];
                GVAR(scannerEH) = -1;
                GVAR(scannerRunning) = false;
                GVAR(scannerEnabled) = false;
                GVAR(scannerActive) = false;
            };

            if (!GVAR(scannerEnabled)) exitWith {};

            private _nearUnits = (player nearEntities ["CAManBase", 25]) select {
                _x != player &&
                {lifeState _x != "DEAD"} &&
                {side group _x == side group player} &&
                {isNull (getAssignedCuratorLogic _x)}
            };

            {
                private _unit = _x;
                private _result = [_unit] call GVAR(fnc_getMedicalStatus);
                _result params ["_status", "_color", "_text", "_severity", "_isDown"];

                private _pos = if (_isDown) then {
                    (getPos _unit) vectorAdd [0, 0, 1.2]
                } else {
                    (_unit modelToWorldVisual (_unit selectionPosition "head")) vectorAdd [0, 0, 0.35]
                };

                private _icon = switch (_status) do {
                    case "CRITICAL": { "\A3\ui_f\data\IGUI\Cfg\Revive\overlayIcons\u100_ca.paa" };
                    case "PRIORITY": { "\A3\ui_f\data\IGUI\Cfg\Actions\heal_ca.paa" };
                    case "MINOR":    { "\A3\ui_f\data\IGUI\Cfg\Actions\bandage_ca.paa" };
                    case "STABLE":   { "\A3\ui_f\data\IGUI\Cfg\Actions\ico_cpt_ca.paa" };
                    default          { "\A3\ui_f\data\IGUI\Cfg\Actions\ico_on_ca.paa" };
                };

                drawIcon3D [_icon, _color, _pos, 0.6, 0.6, 0, "", 2, 0.025, "PuristaBold"];
                drawIcon3D ["", _color, _pos vectorAdd [0, 0, -0.12], 0, 0, 0, _text, 2, 0.02, "PuristaMedium"];

            } forEach _nearUnits;

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
        GVAR(scannerActive) = false;
        GVAR(scannerRunning) = false;
        if (GVAR(scannerEH) > -1) then {
            removeMissionEventHandler ["Draw3D", GVAR(scannerEH)];
            GVAR(scannerEH) = -1;
        };
    };

    // ========================================================================
    // CBA KEYBINDS - Medical Scanner
    // ========================================================================

    [
        ["505th Expeditionary Force Aux Mod", "Facewears HUD"],
        "OLI_ToggleMedicalScanner",
        ["Toggle Medical Scanner", "Turn scanner overlay on/off (requires Medical Scanner Glasses)"],
        {
            if ((goggles player) != GVAR(medGlassesClass)) exitWith {
                systemChat "[Medical Scanner] Requires Medical Scanner Glasses";
            };
            if (!GVAR(scannerRunning)) exitWith {
                [] call GVAR(fnc_startScanner);
                systemChat "[Medical Scanner] ON";
            };
            GVAR(scannerEnabled) = !GVAR(scannerEnabled);
            private _status = ["OFF", "ON"] select GVAR(scannerEnabled);
            systemChat format ["[Medical Scanner] %1", _status];
        },
        {},
        [],
        false,
        0,
        false
    ] call CBA_fnc_addKeybind;

    [
        ["505th Expeditionary Force Aux Mod", "Facewears HUD"],
        "OLI_ToggleDetailedVitals",
        ["Toggle Detailed Vitals", "Show/hide vitals panel when looking at teammate (requires scanner active)"],
        {
            if ((goggles player) != GVAR(medGlassesClass)) exitWith {};
            if (!GVAR(scannerRunning)) exitWith {
                systemChat "[Medical Scanner] Scanner must be active first";
            };
            GVAR(vitalsEnabled) = !GVAR(vitalsEnabled);
            private _status = ["OFF", "ON"] select GVAR(vitalsEnabled);
            systemChat format ["[Medical Scanner] Detailed Vitals: %1", _status];
        },
        {},
        [],
        false,
        0,
        false
    ] call CBA_fnc_addKeybind;

    diag_log "[505th Gears] TCP VISR + Medical Scanner keybinds ready";

}] call CBA_fnc_waitUntilAndExecute;
