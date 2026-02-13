#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_buildObject
 *
 * Controls:
 *   LMB             – Place (checks resources, starts build timer)
 *   Q / E           – Rotate ±5°  (shows current angle)
 *   PgUp / PgDn     – Height ±0.10m
 *   TAB             – Toggle snap ON/OFF
 *   RMB             – Back to menu
 *   Scroll Wheel    – Back to menu
 *   Shift+RMB       – Delete nearest placed object
 *
 * SNAP MODE:
 *   Ghost locks flush edge-to-edge against nearest placed wall.
 *   Axis is detected per-object (X or Y) so no "shift forward" offset.
 *   Rotation inherited from snapped wall + shown in hint.
 */

params [["_classname", "", [""]]];

if (_classname isEqualTo "") exitWith {
    systemChat "[Engineer] ERROR: No object specified";
};

// ── Globals ───────────────────────────────────────────────────────────────────
if (isNil "OLI_engtools_buildHeight")  then { OLI_engtools_buildHeight  = 0;     };
if (isNil "OLI_engtools_levelTerrain") then { OLI_engtools_levelTerrain = true;  };
if (isNil "OLI_engtools_snapActive")   then { OLI_engtools_snapActive   = false; };
[] call FUNC(cancelBuild);
if (isNil QGVAR(buildRotation)) then { GVAR(buildRotation) = 0; };

// ── Resource check before entering build mode ────────────────────────────────
private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
private _cost = [_classname] call FUNC(getObjectCost);

if (_resourcesEnabled) then {
    private _currentRes = player getVariable [QGVAR(resources), 0];
    if (_currentRes < _cost) exitWith {
        systemChat format ["[Engineer] Not enough resources! Need %1, have %2", _cost, _currentRes];
        hint parseText format [
            "<t size='1.1' color='#FF4444'>INSUFFICIENT RESOURCES</t><br/><br/>" +
            "<t color='#FFFFFF'>Cost: %1</t>  |  <t color='#FF6666'>Available: %2</t>",
            _cost, _currentRes
        ];
    };
};

// Ghost preview
private _previewObj = _classname createVehicleLocal [0,0,0];
_previewObj allowDamage false;
_previewObj enableSimulation false;
GVAR(buildingObject) = _previewObj;
GVAR(buildClassname) = _classname;

// Build HUD
private _snapStr = if (OLI_engtools_snapActive) then {"<t color='#00AAFF'>ON</t>"} else {"<t color='#888888'>OFF</t>"};
private _resStr = if (_resourcesEnabled) then {
    private _res = player getVariable [QGVAR(resources), 0];
    format ["<t color='#FFAA00'>Cost: %1</t>  |  <t color='#55CC66'>Resources: %2</t>", _cost, _res]
} else {
    "<t color='#888888'>Resources: FREE</t>"
};
hint parseText format [
    "<t size='1.1' color='#FFA500'>BUILD MODE</t>  <t size='0.8' color='#AAAAAA'>%1</t><br/>%5<br/><t size='0.85' color='#FFFF00'>Rotation: %2°  |  Height: %3m  |  Snap: %4</t><br/><br/><t color='#FFFFFF'>LMB</t><t color='#AAAAAA'> – Place   </t><t color='#FFFFFF'>Q/E</t><t color='#AAAAAA'> – Rotate 5°   </t><t color='#FFFFFF'>TAB</t><t color='#AAAAAA'> – Toggle Snap<br/>PgUp/PgDn</t><t color='#AAAAAA'> – Height   </t><t color='#FFFFFF'>RMB/Scroll</t><t color='#AAAAAA'> – Back to Menu   </t><t color='#FFFFFF'>Shift+RMB</t><t color='#AAAAAA'> – Delete</t>",
    _classname, GVAR(buildRotation), OLI_engtools_buildHeight, _snapStr, _resStr
];

// ── HELPER: Get wall half-extents and long-axis azimuth ───────────────────────
OLI_engtools_fnc_getWallAxis = {
    params ["_obj", "_refDir"];
    private _bb   = boundingBoxReal _obj;
    private _halfX = abs ((_bb select 1 select 0) - (_bb select 0 select 0)) / 2;
    private _halfY = abs ((_bb select 1 select 1) - (_bb select 0 select 1)) / 2;
    if (_halfX >= _halfY) then {
        [_halfX, _refDir + 90]
    } else {
        [_halfY, _refDir]
    }
};

// ── PER-FRAME ─────────────────────────────────────────────────────────────────
GVAR(buildEH) = addMissionEventHandler ["EachFrame", {
    if (isNil QGVAR(buildingObject)) exitWith {};
    if (isNull GVAR(buildingObject)) exitWith {};

    private _pos = screenToWorld [0.5, 0.5];
    private _snapped = false;

    // ── SNAP ─────────────────────────────────────────────────────────────────
    if (!isNil "OLI_engtools_snapActive" && { OLI_engtools_snapActive }) then {

        private _nearObjs = (nearestObjects [_pos, [], 14]) select {
            !isNull _x && { _x getVariable [QGVAR(builtObject), false] }
        };

        if (count _nearObjs > 0) then {

            // Find closest built object to player
            private _nearObj  = objNull;
            private _nearDist = 9999;
            {
                private _d = player distance _x;
                if (_d < _nearDist) then { _nearDist = _d; _nearObj = _x; };
            } forEach _nearObjs;

            if (!isNull _nearObj) then {
                // Get target's actual vectors
                private _targetVecDir = vectorDir _nearObj;
                private _targetVecUp  = vectorUp _nearObj;
                private _targetPos    = getPosASL _nearObj;

                // Bounding boxes
                private _bbT = boundingBoxReal _nearObj;
                private _bbN = boundingBoxReal GVAR(buildingObject);

                // Target dimensions
                private _tHalfX = abs ((_bbT select 1 select 0) - (_bbT select 0 select 0)) / 2;
                private _tHalfY = abs ((_bbT select 1 select 1) - (_bbT select 0 select 1)) / 2;
                private _tHalfZ = abs ((_bbT select 1 select 2) - (_bbT select 0 select 2)) / 2;

                // New piece dimensions
                private _nHalfX = abs ((_bbN select 1 select 0) - (_bbN select 0 select 0)) / 2;
                private _nHalfY = abs ((_bbN select 1 select 1) - (_bbN select 0 select 1)) / 2;
                private _nHalfZ = abs ((_bbN select 1 select 2) - (_bbN select 0 select 2)) / 2;

                // Long axis detection
                private _tLongIsX = (_tHalfX >= _tHalfY);
                private _tHalfLong = if (_tLongIsX) then { _tHalfX } else { _tHalfY };
                private _nHalfLong = if (_tLongIsX) then { _nHalfX } else { _nHalfY };

                _snapped = true;

                // First snap lock: sync rotation, reset height
                private _flatDir = (_targetVecDir select 0) atan2 (_targetVecDir select 1);
                private _baseDir = (_flatDir + 360) mod 360;

                if (isNil QGVAR(buildSnapLocked)) then {
                    GVAR(buildSnapLocked) = true;
                    GVAR(buildRotation) = _baseDir;
                    OLI_engtools_buildHeight = 0;
                };
                GVAR(buildSnapBaseDir) = _baseDir;

                // Calculate rotation delta from base
                private _delta = GVAR(buildRotation) - _baseDir;
                private _sinD = sin _delta;
                private _cosD = cos _delta;

                // Rotate vecDir around vecUp by delta
                private _vecRight = _targetVecDir vectorCrossProduct _targetVecUp;
                _vecRight = vectorNormalized _vecRight;

                private _rotatedDir = (_targetVecDir vectorMultiply _cosD) vectorAdd (_vecRight vectorMultiply _sinD);
                _rotatedDir = vectorNormalized _rotatedDir;

                // ── Side movement: project cursor along wall's long axis ─────
                private _longAxisWorld = if (_tLongIsX) then { _vecRight } else { _targetVecDir };
                private _cursorASL = ATLToASL _pos;
                private _cursorDelta = _cursorASL vectorDiff _targetPos;
                private _sideOffset = _cursorDelta vectorDotProduct _longAxisWorld;

                // Snap position = target center + side offset along long axis
                private _snapPos = _targetPos vectorAdd (_longAxisWorld vectorMultiply _sideOffset);

                // Apply height offset along up vector
                if (OLI_engtools_buildHeight != 0) then {
                    _snapPos = _snapPos vectorAdd (_targetVecUp vectorMultiply OLI_engtools_buildHeight);
                };

                GVAR(buildSnapVecDir) = _rotatedDir;
                GVAR(buildSnapVecUp)  = _targetVecUp;
                GVAR(buildSnapPos)    = _snapPos;

                // Store dimensions for overlap check
                GVAR(buildSnapTargetPos) = _targetPos;
                GVAR(buildSnapLongAxis)  = _longAxisWorld;
                GVAR(buildSnapTHalfLong) = _tHalfLong;
                GVAR(buildSnapNHalfLong) = _nHalfLong;
                GVAR(buildSnapTHalfZ)    = _tHalfZ;
                GVAR(buildSnapNHalfZ)    = _nHalfZ;
            };
        } else {
            GVAR(buildSnapVecDir) = nil;
            GVAR(buildSnapVecUp)  = nil;
            GVAR(buildSnapPos)    = nil;
            GVAR(buildSnapBaseDir) = nil;
            GVAR(buildSnapLocked) = nil;
        };
    };
    // ── END SNAP ─────────────────────────────────────────────────────────────

    // ── POSITION & ORIENTATION ────────────────────────────────────────────────
    if (_snapped && {!isNil QGVAR(buildSnapPos)}) then {
        // Snapped: use snap position and inherited vectors
        private _snapPos = GVAR(buildSnapPos);
        private _sVecDir = GVAR(buildSnapVecDir);
        private _sVecUp  = GVAR(buildSnapVecUp);

        GVAR(buildingObject) setPosASL _snapPos;
        GVAR(buildingObject) setVectorDirAndUp [_sVecDir, _sVecUp];
        GVAR(buildingObject) setPosASL _snapPos;

        // Store for placement
        GVAR(buildVecDir) = _sVecDir;
        GVAR(buildVecUp)  = _sVecUp;

        // ── Overlap detection using bounding box axes ─────────────────────────
        // Project distance onto target's local axes and check per-axis overlap
        private _ghostPos = _snapPos;
        private _isOverlapping = false;

        private _nearBuilt = (nearestObjects [ASLToAGL _snapPos, [], 8]) select {
            !isNull _x
            && { _x getVariable [QGVAR(builtObject), false] }
            && { _x != GVAR(buildingObject) }
        };

        if (count _nearBuilt > 0) then {
            private _sVecDir = GVAR(buildSnapVecDir);
            private _sVecUp  = GVAR(buildSnapVecUp);
            private _sVecRight = _sVecDir vectorCrossProduct _sVecUp;
            _sVecRight = vectorNormalized _sVecRight;

            // Ghost half-extents
            private _bbG = boundingBoxReal GVAR(buildingObject);
            private _gHX = abs ((_bbG select 1 select 0) - (_bbG select 0 select 0)) / 2;
            private _gHY = abs ((_bbG select 1 select 1) - (_bbG select 0 select 1)) / 2;
            private _gHZ = abs ((_bbG select 1 select 2) - (_bbG select 0 select 2)) / 2;

            {
                private _otherPos = getPosASL _x;
                private _bbO = boundingBoxReal _x;
                private _oHX = abs ((_bbO select 1 select 0) - (_bbO select 0 select 0)) / 2;
                private _oHY = abs ((_bbO select 1 select 1) - (_bbO select 0 select 1)) / 2;
                private _oHZ = abs ((_bbO select 1 select 2) - (_bbO select 0 select 2)) / 2;

                private _diff = _ghostPos vectorDiff _otherPos;

                // Project onto each axis
                private _dRight = abs (_diff vectorDotProduct _sVecRight);
                private _dDir   = abs (_diff vectorDotProduct _sVecDir);
                private _dUp    = abs (_diff vectorDotProduct _sVecUp);

                // Combined extents with small tolerance (0.15m)
                private _overlapRight = (_dRight < (_gHX + _oHX - 0.15));
                private _overlapDir   = (_dDir   < (_gHY + _oHY - 0.15));
                private _overlapUp    = (_dUp    < (_gHZ + _oHZ - 0.15));

                // Overlapping only if ALL three axes overlap
                if (_overlapRight && _overlapDir && _overlapUp) exitWith {
                    _isOverlapping = true;
                };
            } forEach _nearBuilt;
        };

        GVAR(buildCanPlace) = !_isOverlapping;
        GVAR(buildSlopeAngle) = 0;

        // Visual: RED when overlapping, GREEN when clear
        if (_isOverlapping) then {
            GVAR(buildingObject) setObjectTextureGlobal [0,
                "#(argb,8,8,3)color(1.0,0.1,0.1,0.7)"
            ];
        } else {
            GVAR(buildingObject) setObjectTextureGlobal [0,
                "#(argb,8,8,3)color(0.2,0.8,0.3,0.6)"
            ];
        };

        GVAR(canPlaceObject) = (player distance GVAR(buildingObject) < 15) && !_isOverlapping;
    } else {
    // ── Non-snapped: free placement with terrain detection ────────────────
    // Z
    private _z = if (OLI_engtools_levelTerrain) then {
        getTerrainHeightASL _pos
    } else {
        (ATLToASL [_pos select 0, _pos select 1, 0]) select 2
    };
    _z = _z + OLI_engtools_buildHeight;

    private _posASL = [_pos select 0, _pos select 1, _z];

    // ── Terrain Detection ─────────────────────────────────────────────────────
    private _normal = surfaceNormal _pos;
    private _slopeAngle = acos ((_normal select 2) min 1 max -1);

    // Multi-point sampling: check 4 corners around the object footprint
    private _bb = boundingBoxReal GVAR(buildingObject);
    private _halfX = (abs ((_bb select 1 select 0) - (_bb select 0 select 0)) / 2) max 1;
    private _halfY = (abs ((_bb select 1 select 1) - (_bb select 0 select 1)) / 2) max 1;
    private _samplePoints = [
        [(_pos select 0) + _halfX, (_pos select 1) + _halfY, 0],
        [(_pos select 0) - _halfX, (_pos select 1) + _halfY, 0],
        [(_pos select 0) + _halfX, (_pos select 1) - _halfY, 0],
        [(_pos select 0) - _halfX, (_pos select 1) - _halfY, 0]
    ];
    private _maxCornerSlope = 0;
    {
        private _n = surfaceNormal _x;
        private _a = acos ((_n select 2) min 1 max -1);
        if (_a > _maxCornerSlope) then { _maxCornerSlope = _a; };
    } forEach _samplePoints;

    // Use worst slope across all sample points
    private _worstSlope = _slopeAngle max _maxCornerSlope;

    // Classify terrain
    // 0-15° green | 15-30° yellow | 30°+ red (blocked)
    private _slopeColor = if (_worstSlope < 15) then {
        [0.2, 0.8, 0.3, 0.6]   // green
    } else {
        if (_worstSlope < 30) then {
            [1.0, 0.8, 0.0, 0.6]   // yellow
        } else {
            [1.0, 0.15, 0.1, 0.6]  // red
        };
    };

    // Surface type
    private _surfRaw = surfaceType _pos;
    // Strip leading # if present
    private _surfName = if ((_surfRaw select [0,1]) == "#") then {
        _surfRaw select [1]
    } else { _surfRaw };
    // Clean up common prefixes
    _surfName = _surfName select [3]; // strip "Gdt" prefix

    // Store slope data for placement check
    GVAR(buildSlopeAngle) = _worstSlope;
    GVAR(buildSurfaceNormal) = _normal;
    GVAR(buildCanPlace) = (_worstSlope < 30);

    // ── Auto-Level ────────────────────────────────────────────────────────────
    private _autoLevel = if (!isNil "OLI_engtools_autoLevel") then { OLI_engtools_autoLevel } else { false };
    private _r = GVAR(buildRotation);
    private _vecDir = [sin _r, cos _r, 0];
    private _vecUp  = [0, 0, 1];

    if (_autoLevel && _worstSlope > 0.5) then {
        // Align object to terrain normal
        _vecUp = _normal;
        // Re-derive vecDir perpendicular to the new up vector
        private _right = _vecDir vectorCrossProduct _vecUp;
        _vecDir = _vecUp vectorCrossProduct _right;
        _vecDir = vectorNormalized _vecDir;
    };

    GVAR(buildVecDir) = _vecDir;
    GVAR(buildVecUp)  = _vecUp;

    GVAR(buildingObject) setPosASL _posASL;
    GVAR(buildingObject) setVectorDirAndUp [_vecDir, _vecUp];
    GVAR(buildingObject) setPosASL _posASL;

    // Apply ghost tint based on slope
    GVAR(buildingObject) setObjectTextureGlobal [0,
        format ["#(argb,8,8,3)color(%1,%2,%3,%4)",
            _slopeColor select 0, _slopeColor select 1,
            _slopeColor select 2, _slopeColor select 3]
    ];

    GVAR(canPlaceObject) = (player distance GVAR(buildingObject) < 15) && GVAR(buildCanPlace);

    // ── Slope HUD only when auto-level ON ────────────────────────────────
    if (_autoLevel) then {
        if (isNil "OLI_engtools_snapActive" || {!OLI_engtools_snapActive}) then {
            private _slopeStr = if (_worstSlope < 15) then {
                format ["<t color='#55CC66'>%1°  FLAT</t>", round _worstSlope]
            } else {
                if (_worstSlope < 30) then {
                    format ["<t color='#FFCC00'>%1°  SLOPE</t>", round _worstSlope]
                } else {
                    format ["<t color='#FF3333'>%1°  TOO STEEP</t>", round _worstSlope]
                };
            };

            private _heightStr = if (OLI_engtools_buildHeight != 0) then {
                format ["  <t color='#FFA500'>H: %1m</t>", OLI_engtools_buildHeight]
            } else { "" };

            hintSilent parseText format [
                "<t size='0.9' color='#5599FF'>AUTO LEVEL</t>  <t size='0.9'>%1  |  %2</t>%3<br/><t size='0.9' color='#FFA500'>%4°</t>",
                _slopeStr, _surfName, _heightStr, round GVAR(buildRotation)
            ];
        };
    } else {
        // Auto-level OFF, not snapped: just show height + angle
        if (isNil "OLI_engtools_snapActive" || {!OLI_engtools_snapActive}) then {
            private _heightStr = if (OLI_engtools_buildHeight != 0) then {
                format ["  <t color='#FFA500'>H: %1m</t>", OLI_engtools_buildHeight]
            } else { "" };

            hintSilent parseText format [
                "<t size='0.9' color='#FFA500'>%1°</t>%2",
                round GVAR(buildRotation), _heightStr
            ];
        };
    };
    }; // end else (not snapped)

    // ── UNIFIED HINT FOR SNAP MODES ──────────────────────────────────────────
    if (_snapped) then {
        private _autoLevel = if (!isNil "OLI_engtools_autoLevel") then { OLI_engtools_autoLevel } else { false };

        private _heightStr = if (OLI_engtools_buildHeight != 0) then {
            format ["  <t color='#FFA500'>H: %1m</t>", OLI_engtools_buildHeight]
        } else { "" };

        private _angleStr = format ["<t color='#FFA500'>%1°</t>", round GVAR(buildRotation)];

        // Overlap status
        private _isOverlapping = if (!isNil QGVAR(buildCanPlace)) then { !GVAR(buildCanPlace) } else { false };
        private _overlapStr = if (_isOverlapping) then {
            "<t color='#FF3333' size='1.1'>■ OVERLAPPING</t>"
        } else {
            "<t color='#55CC66'>■ CLEAR</t>"
        };

        if (_autoLevel) then {
            private _slopeAngle = if (!isNil QGVAR(buildSlopeAngle)) then { round GVAR(buildSlopeAngle) } else { 0 };
            private _slopeStr = if (_slopeAngle < 15) then {
                format ["<t color='#55CC66'>%1° FLAT</t>", _slopeAngle]
            } else {
                if (_slopeAngle < 30) then {
                    format ["<t color='#FFCC00'>%1° SLOPE</t>", _slopeAngle]
                } else {
                    format ["<t color='#FF3333'>%1° STEEP</t>", _slopeAngle]
                };
            };

            hintSilent parseText format [
                "<t color='#00AAFF'>SNAP</t>  %1  %2%3<br/>%4  <t color='#5599FF'>AUTO LEVEL</t><br/>%5<br/><t color='#888888'>Q/E – rotate  |  PgUp/PgDn – height</t>",
                _overlapStr, _angleStr, _heightStr, _slopeStr, ""
            ];
        } else {
            hintSilent parseText format [
                "<t color='#00AAFF'>SNAP</t>  %1  %2%3<br/><t color='#888888'>Q/E – rotate  |  PgUp/PgDn – height</t>",
                _overlapStr, _angleStr, _heightStr
            ];
        };
    } else {
        // Snap active but scanning / no walls
        if (!isNil "OLI_engtools_snapActive" && { OLI_engtools_snapActive } && !_snapped) then {
            private _heightStr = if (OLI_engtools_buildHeight != 0) then {
                format ["  <t color='#FFA500'>H: %1m</t>", OLI_engtools_buildHeight]
            } else { "" };
            hintSilent parseText format [
                "<t color='#00AAFF'>SNAP</t><t color='#888888'> Scanning…</t>  <t color='#FFA500'>%1°</t>%2",
                round GVAR(buildRotation), _heightStr
            ];
        };
    };
}];

// ── KEY HANDLER ───────────────────────────────────────────────────────────────
GVAR(buildKeyEH) = (findDisplay 46) displayAddEventHandler ["KeyDown", {
    params ["_display", "_key"];
    if (isNil QGVAR(buildingObject)) exitWith {false};
    if (isNull GVAR(buildingObject)) exitWith {false};

    switch (_key) do {
        case 16: {
            GVAR(buildRotation) = ((GVAR(buildRotation) - 5) + 360) mod 360;
            false
        };
        case 18: {
            GVAR(buildRotation) = (GVAR(buildRotation) + 5) mod 360;
            false
        };
        case 15: {
            if (isNil "OLI_engtools_snapActive") then { OLI_engtools_snapActive = false; };
            OLI_engtools_snapActive = !OLI_engtools_snapActive;

            // Clear snap state when toggling off
            if (!OLI_engtools_snapActive) then {
                GVAR(buildSnapVecDir) = nil;
                GVAR(buildSnapVecUp) = nil;
                GVAR(buildSnapPos) = nil;
                GVAR(buildSnapBaseDir) = nil;
                GVAR(buildSnapLocked) = nil;
                GVAR(buildSnapTargetPos) = nil;
                GVAR(buildSnapLongAxis) = nil;
                GVAR(buildSnapTHalfLong) = nil;
                GVAR(buildSnapNHalfLong) = nil;
                GVAR(buildSnapTHalfZ) = nil;
                GVAR(buildSnapNHalfZ) = nil;
                OLI_engtools_buildHeight = 0;
            } else {
                // Also reset when toggling on so fresh start
                GVAR(buildSnapLocked) = nil;
                OLI_engtools_buildHeight = 0;
            };

            disableSerialization;
            private _display = findDisplay IDD_ENGINEER_DIALOG;
            if (!isNull _display) then {
                private _sCtrl = _display displayCtrl IDC_SNAP_TOGGLE;
                if (!isNull _sCtrl) then {
                    if (OLI_engtools_snapActive) then {
                        _sCtrl ctrlSetText "[ON]  SNAP";
                        _sCtrl ctrlSetBackgroundColor [0.08, 0.18, 0.45, 1.0];
                    } else {
                        _sCtrl ctrlSetText "[OFF] SNAP";
                        _sCtrl ctrlSetBackgroundColor [0.10, 0.14, 0.30, 1.0];
                    };
                };
            };

            private _msg = if (OLI_engtools_snapActive) then {
                "<t color='#00AAFF'>SNAP</t><t color='#FFFFFF'> ON</t><br/><t color='#888888'>Locking to wall ends</t>"
            } else {
                "<t color='#888888'>SNAP OFF</t><br/><t color='#888888'>Free placement</t>"
            };
            hintSilent parseText _msg;
            false
        };
        case 201: {
            OLI_engtools_buildHeight = parseNumber (str (round ((OLI_engtools_buildHeight + 0.10) * 100) / 100));
            false
        };
        case 209: {
            OLI_engtools_buildHeight = parseNumber (str (round ((OLI_engtools_buildHeight - 0.10) * 100) / 100));
            false
        };
    };
    false
}];

// ── MOUSE HANDLER ─────────────────────────────────────────────────────────────
GVAR(buildMouseEH) = (findDisplay 46) displayAddEventHandler ["MouseButtonDown", {
    params ["_display", "_button", "_xPos", "_yPos", "_shift"];
    if (isNil QGVAR(buildingObject)) exitWith {false};
    if (isNull GVAR(buildingObject)) exitWith {false};

    // Shift+RMB – quick delete nearest
    if (_button == 1 && _shift) exitWith {
        [] call FUNC(deleteNearestBuilt);
        false
    };

    // RMB – back to menu
    if (_button == 1 && !_shift) exitWith {
        [] call FUNC(cancelBuild);
        [] spawn { sleep 0.05; [] call FUNC(openEngineerMenu); };
        false
    };

    // LMB – place (with resource check + build timer)
    if (_button == 0) exitWith {
        if !(GVAR(canPlaceObject)) exitWith {
            if (!isNil QGVAR(buildCanPlace) && {!GVAR(buildCanPlace)}) then {
                private _slopeAngle = if (!isNil QGVAR(buildSlopeAngle)) then { round GVAR(buildSlopeAngle) } else { 0 };
                if (_slopeAngle >= 30) then {
                    systemChat format ["[Engineer] Terrain too steep! (%1°) – Cannot build here.", _slopeAngle];
                } else {
                    systemChat "[Engineer] Object overlapping! Use PgUp/PgDn to adjust.";
                };
            } else {
                systemChat "[Engineer] Too far – must be within 15m";
            };
            false
        };

        private _cls = GVAR(buildClassname);
        private _cost = [_cls] call FUNC(getObjectCost);
        private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];

        // ── Resource check ──────────────────────────────────────────────────
        if (_resourcesEnabled) then {
            private _currentRes = player getVariable [QGVAR(resources), 0];
            if (_currentRes < _cost) exitWith {
                systemChat format ["[Engineer] Not enough resources! Need %1, have %2", _cost, _currentRes];
                hintSilent parseText format [
                    "<t size='1.1' color='#FF4444'>INSUFFICIENT RESOURCES</t><br/>" +
                    "<t color='#FFFFFF'>Cost: %1</t>  |  <t color='#FF6666'>Have: %2</t>",
                    _cost, _currentRes
                ];
            };
        };

        private _finalPos = getPosASL GVAR(buildingObject);
        private _finalDir = GVAR(buildRotation);

        // Capture auto-level vectors
        private _vecDir = if (!isNil QGVAR(buildVecDir)) then { GVAR(buildVecDir) } else { [sin _finalDir, cos _finalDir, 0] };
        private _vecUp  = if (!isNil QGVAR(buildVecUp))  then { GVAR(buildVecUp)  } else { [0, 0, 1] };

        [] call FUNC(cancelBuild);

        // ── Build timer or instant ──────────────────────────────────────────
        private _buildTimeEnabled = missionNamespace getVariable [QGVAR(setting_enableBuildTime), true];
        private _buildTime = missionNamespace getVariable [QGVAR(setting_buildTime), DEFAULT_BUILD_TIME];

        if (_buildTimeEnabled && _buildTime > 0) then {
            [_cls, _finalPos, _finalDir, _cost, _vecDir, _vecUp] spawn FUNC(progressBuild);
        } else {
            if (_resourcesEnabled) then {
                private _currentRes = player getVariable [QGVAR(resources), 0];
                player setVariable [QGVAR(resources), _currentRes - _cost, true];
            };

            if (isMultiplayer) then {
                [_cls, _finalPos, _finalDir, _vecDir, _vecUp] remoteExec [QFUNC(createBuiltObject), 2];
            } else {
                [_cls, _finalPos, _finalDir, _vecDir, _vecUp] call FUNC(createBuiltObject);
            };

            [_cls] spawn {
                params ["_c"];
                sleep 0.1;
                [_c] call FUNC(buildObject);
            };
        };
        false
    };
    false
}];

// ── SCROLL WHEEL – back to menu ───────────────────────────────────────────────
GVAR(buildScrollEH) = (findDisplay 46) displayAddEventHandler ["MouseZChanged", {
    if (isNil QGVAR(buildingObject)) exitWith {};
    if (isNull GVAR(buildingObject)) exitWith {};
    [] call FUNC(cancelBuild);
    [] spawn { sleep 0.05; [] call FUNC(openEngineerMenu); };
}];
