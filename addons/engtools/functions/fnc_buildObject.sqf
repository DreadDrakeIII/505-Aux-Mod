#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_buildObject
 *
 * Controls:
 *   LMB             – Place (checks resources, deploy handlers, starts build timer)
 *   Q / E           – Rotate yaw ±5°
 *   Shift+Q / E     – Rotate pitch ±5°
 *   Ctrl+Q / E      – Rotate bank ±5°
 *   ALT (hold)      – Snap to terrain surface
 *   PgUp / PgDn     – Height ±0.10m
 *   TAB             – Toggle snap ON/OFF
 *   RMB             – Back to menu
 *   Scroll Wheel    – Back to menu
 *   Shift+RMB       – Delete nearest placed object
 *
 * ACE-INSPIRED CHANGES (v10):
 *   - Ghost vectors read directly from object at placement (not globals)
 *   - disableCollisionWith player on ghost
 *   - getCameraViewDirection for ghost positioning
 *   - 3-axis rotation: pitch (Shift), bank (Ctrl), yaw (default)
 *   - ALT hold = terrain surface snap (surfaceNormal)
 *   - Deploy handlers: custom code can block placement
 *   - Location restriction: build areas system
 *   - Placement animation during build timer
 *   - Removed: auto-level, overlap detection
 */

params [["_classname", "", [""]]];

if (_classname isEqualTo "") exitWith {
    systemChat "[Engineer] ERROR: No object specified";
};

// ── Location restriction check ───────────────────────────────────────────────
private _locations = missionNamespace getVariable [QGVAR(buildLocations), []];
if (count _locations > 0) then {
    private _inArea = false;
    {
        if (player inArea _x) exitWith { _inArea = true; };
    } forEach _locations;

    if (!_inArea) exitWith {
        systemChat "[Engineer] Cannot build here – outside designated build area.";
        hint parseText "<t size='1.1' color='#FF4444'>RESTRICTED AREA</t><br/><br/><t color='#AAAAAA'>You must be inside a designated build zone.</t>";
    };
};

// ── Globals ───────────────────────────────────────────────────────────────────
if (isNil "OLI_engtools_buildHeight")  then { OLI_engtools_buildHeight  = 0;     };
if (isNil "OLI_engtools_levelTerrain") then { OLI_engtools_levelTerrain = true;  };
if (isNil "OLI_engtools_snapActive")   then { OLI_engtools_snapActive   = false; };
[] call FUNC(cancelBuild);
if (isNil QGVAR(buildRotation)) then { GVAR(buildRotation) = 0; };

// 3-axis rotation — pitch and bank (yaw is buildRotation)
if (isNil QGVAR(buildPitch)) then { GVAR(buildPitch) = 0; };
if (isNil QGVAR(buildBank))  then { GVAR(buildBank)  = 0; };

// Placement distance offset (scroll wheel adjusts)
if (isNil QGVAR(buildDistOffset)) then { GVAR(buildDistOffset) = 0; };

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

// ── Ghost preview — create at origin, kill sim, disable collision ─────────────
private _previewObj = _classname createVehicleLocal [0,0,0];
_previewObj enableSimulation false;
_previewObj allowDamage false;
_previewObj disableCollisionWith player;

GVAR(buildingObject) = _previewObj;
GVAR(buildClassname) = _classname;

// ── Build HUD ─────────────────────────────────────────────────────────────────
private _snapStr = if (OLI_engtools_snapActive) then {"<t color='#00AAFF'>ON</t>"} else {"<t color='#888888'>OFF</t>"};
private _resStr = if (_resourcesEnabled) then {
    private _res = player getVariable [QGVAR(resources), 0];
    format ["<t color='#FFAA00'>Cost: %1</t>  |  <t color='#55CC66'>Resources: %2</t>", _cost, _res]
} else {
    "<t color='#888888'>Resources: FREE</t>"
};
hint parseText format [
    "<t size='1.1' color='#FFA500'>BUILD MODE</t>  <t size='0.8' color='#AAAAAA'>%1</t><br/>%5<br/><t size='0.85' color='#FFFF00'>Yaw: %2°  |  Height: %3m  |  Snap: %4</t><br/><br/><t color='#FFFFFF'>Q/E</t><t color='#AAAAAA'> – Yaw   </t><t color='#FFFFFF'>Shift+Q/E</t><t color='#AAAAAA'> – Pitch   </t><t color='#FFFFFF'>Ctrl+Q/E</t><t color='#AAAAAA'> – Bank<br/>ALT (hold)</t><t color='#AAAAAA'> – Terrain Snap   </t><t color='#FFFFFF'>Scroll</t><t color='#AAAAAA'> – Distance<br/>TAB</t><t color='#AAAAAA'> – Toggle Snap   </t><t color='#FFFFFF'>PgUp/PgDn</t><t color='#AAAAAA'> – Height<br/>LMB</t><t color='#AAAAAA'> – Place   </t><t color='#FFFFFF'>RMB</t><t color='#AAAAAA'> – Menu   </t><t color='#FFFFFF'>Shift+RMB</t><t color='#AAAAAA'> – Delete</t>",
    _classname, GVAR(buildRotation), OLI_engtools_buildHeight, _snapStr, _resStr
];

// ── HELPER: Convert pitch/bank/yaw to vectorDirAndUp ──────────────────────────
OLI_engtools_fnc_pitchBankYawToVectors = {
    params ["_pitch", "_bank", "_yaw"];
    private _cp = cos _pitch; private _sp = sin _pitch;
    private _cb = cos _bank;  private _sb = sin _bank;
    private _cy = cos _yaw;   private _sy = sin _yaw;

    private _vecDir = [
        _sy * _cp,
        _cy * _cp,
        -_sp
    ];
    private _vecUp = [
        _sb * _cy + _cb * _sp * _sy,
        -_sb * _sy + _cb * _sp * _cy,
        _cb * _cp
    ];

    [vectorNormalized _vecDir, vectorNormalized _vecUp]
};

// ── HELPER: Get bounding box half-extents ─────────────────────────────────────
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

    private _snapped = false;

    // ── Object dimensions for distance calculation ───────────────────────────
    private _bb = boundingBoxReal GVAR(buildingObject);
    private _halfX = abs ((_bb select 1 select 0) - (_bb select 0 select 0)) / 2;
    private _halfY = abs ((_bb select 1 select 1) - (_bb select 0 select 1)) / 2;
    private _halfZ = abs ((_bb select 1 select 2) - (_bb select 0 select 2)) / 2;
    private _distOffset = if (!isNil QGVAR(buildDistOffset)) then { GVAR(buildDistOffset) } else { 0 };
    private _distance = ((_halfX max _halfY) + 0.5 + _distOffset) max 0.5;

    // ── getCameraViewDirection positioning ────────────────────────────────────
    private _start = eyePos player;
    private _camDir = getCameraViewDirection player;
    private _basePos = _start vectorAdd (_camDir vectorMultiply _distance);
    _basePos set [2, ((_basePos select 2) - _halfZ) max (getTerrainHeightASL _basePos - 0.05)];

    // Apply height offset
    if (OLI_engtools_buildHeight != 0) then {
        _basePos set [2, (_basePos select 2) + OLI_engtools_buildHeight];
    };

    // ── SNAP ─────────────────────────────────────────────────────────────────
    if (!isNil "OLI_engtools_snapActive" && { OLI_engtools_snapActive }) then {

        private _nearObjs = (nearestObjects [ASLToAGL _basePos, [], 14]) select {
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
                private _targetVecDir = vectorDir _nearObj;
                private _targetVecUp  = vectorUp _nearObj;
                private _targetPos    = getPosASL _nearObj;

                // Bounding boxes
                private _bbT = boundingBoxReal _nearObj;
                private _bbN = boundingBoxReal GVAR(buildingObject);

                // Target dimensions
                private _tHalfX = abs ((_bbT select 1 select 0) - (_bbT select 0 select 0)) / 2;
                private _tHalfY = abs ((_bbT select 1 select 1) - (_bbT select 0 select 1)) / 2;

                // Long axis detection
                private _tLongIsX = (_tHalfX >= _tHalfY);

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

                // Side movement: project cursor along wall's long axis
                private _longAxisWorld = if (_tLongIsX) then { _vecRight } else { _targetVecDir };
                private _cursorDelta = _basePos vectorDiff _targetPos;
                private _sideOffset = _cursorDelta vectorDotProduct _longAxisWorld;

                // Snap position = target center + side offset along long axis
                private _snapPos = _targetPos vectorAdd (_longAxisWorld vectorMultiply _sideOffset);

                // Apply height offset along up vector
                if (OLI_engtools_buildHeight != 0) then {
                    _snapPos = _snapPos vectorAdd (_targetVecUp vectorMultiply OLI_engtools_buildHeight);
                };

                GVAR(buildingObject) setPosASL _snapPos;
                GVAR(buildingObject) setVectorDirAndUp [_rotatedDir, _targetVecUp];
                GVAR(buildingObject) setPosASL _snapPos;

                // Ghost tint: green if in range
                if (player distance GVAR(buildingObject) < 15) then {
                    GVAR(buildingObject) setObjectTextureGlobal [0,
                        "#(argb,8,8,3)color(0.2,0.8,0.3,0.6)"
                    ];
                } else {
                    GVAR(buildingObject) setObjectTextureGlobal [0,
                        "#(argb,8,8,3)color(1.0,0.15,0.1,0.6)"
                    ];
                };

                GVAR(canPlaceObject) = (player distance GVAR(buildingObject) < 15);
            };
        } else {
            // Snap active but no nearby walls — clear lock
            GVAR(buildSnapBaseDir) = nil;
            GVAR(buildSnapLocked) = nil;
        };
    };
    // ── END SNAP ─────────────────────────────────────────────────────────────

    // ── Non-snapped: free placement with camera direction ────────────────────
    if (!_snapped) then {
        // Check ALT key for terrain surface snap
        private _altHeld = inputAction "tacticView" > 0;

        // Calculate vectors from 3-axis rotation
        private _yaw = 180 + GVAR(buildRotation) + getDir player;

        if (_altHeld) then {
            // ALT held: snap to terrain surface normal
            GVAR(buildingObject) setPosASL _basePos;
            GVAR(buildingObject) setDir _yaw;
            GVAR(buildingObject) setVectorUp (surfaceNormal (ASLToAGL _basePos));
        } else {
            // Normal: use pitch/bank/yaw
            private _pitch = if (!isNil QGVAR(buildPitch)) then { GVAR(buildPitch) } else { 0 };
            private _bank  = if (!isNil QGVAR(buildBank))  then { GVAR(buildBank)  } else { 0 };

            if (_pitch == 0 && _bank == 0) then {
                // Simple flat placement — most common case
                private _r = GVAR(buildRotation);
                private _vecDir = [sin _r, cos _r, 0];
                private _vecUp  = [0, 0, 1];

                GVAR(buildingObject) setPosASL _basePos;
                GVAR(buildingObject) setVectorDirAndUp [_vecDir, _vecUp];
            } else {
                // 3-axis rotation
                ([_pitch, _bank, GVAR(buildRotation)] call OLI_engtools_fnc_pitchBankYawToVectors)
                    params ["_vecDir", "_vecUp"];

                GVAR(buildingObject) setPosASL _basePos;
                GVAR(buildingObject) setVectorDirAndUp [_vecDir, _vecUp];
            };
        };
        GVAR(buildingObject) setPosASL _basePos;

        // Ghost tint: green if in range, red if too far
        if (player distance GVAR(buildingObject) < 15) then {
            GVAR(buildingObject) setObjectTextureGlobal [0,
                "#(argb,8,8,3)color(0.2,0.8,0.3,0.6)"
            ];
        } else {
            GVAR(buildingObject) setObjectTextureGlobal [0,
                "#(argb,8,8,3)color(1.0,0.15,0.1,0.6)"
            ];
        };

        GVAR(canPlaceObject) = (player distance GVAR(buildingObject) < 15);
    };

    // ── HUD ──────────────────────────────────────────────────────────────────
    private _pitch = if (!isNil QGVAR(buildPitch)) then { GVAR(buildPitch) } else { 0 };
    private _bank  = if (!isNil QGVAR(buildBank))  then { GVAR(buildBank)  } else { 0 };
    private _altHeld = inputAction "tacticView" > 0;

    private _heightStr = if (OLI_engtools_buildHeight != 0) then {
        format ["  <t color='#FFA500'>H: %1m</t>", OLI_engtools_buildHeight]
    } else { "" };

    private _distStr = if (!isNil QGVAR(buildDistOffset) && {GVAR(buildDistOffset) != 0}) then {
        format ["  <t color='#66CCFF'>D: %1m</t>", round ((GVAR(buildDistOffset)) * 10) / 10]
    } else { "" };

    private _pitchBankStr = if (_pitch != 0 || _bank != 0) then {
        format ["  <t color='#CC88FF'>P:%1° B:%2°</t>", round _pitch, round _bank]
    } else { "" };

    private _terrainStr = if (_altHeld) then {
        "  <t color='#55CCFF'>TERRAIN SNAP</t>"
    } else { "" };

    if (_snapped) then {
        hintSilent parseText format [
            "<t color='#00AAFF'>SNAP</t>  <t color='#FFA500'>%1°</t>%2%3%4<br/><t color='#888888'>Q/E – rotate  |  PgUp/PgDn – height</t>",
            round GVAR(buildRotation), _heightStr, _distStr, _pitchBankStr
        ];
    } else {
        if (!isNil "OLI_engtools_snapActive" && { OLI_engtools_snapActive }) then {
            hintSilent parseText format [
                "<t color='#00AAFF'>SNAP</t><t color='#888888'> Scanning…</t>  <t color='#FFA500'>%1°</t>%2%3%4%5",
                round GVAR(buildRotation), _heightStr, _distStr, _pitchBankStr, _terrainStr
            ];
        } else {
            hintSilent parseText format [
                "<t size='0.9' color='#FFA500'>%1°</t>%2%3%4%5",
                round GVAR(buildRotation), _heightStr, _distStr, _pitchBankStr, _terrainStr
            ];
        };
    };
}];

// ── KEY HANDLER ───────────────────────────────────────────────────────────────
GVAR(buildKeyEH) = (findDisplay 46) displayAddEventHandler ["KeyDown", {
    params ["_display", "_key", "_shift", "_ctrl", "_alt"];
    if (isNil QGVAR(buildingObject)) exitWith {false};
    if (isNull GVAR(buildingObject)) exitWith {false};

    switch (_key) do {
        // Q key (16) — rotate
        case 16: {
            if (_shift) then {
                // Shift+Q = pitch down
                GVAR(buildPitch) = (GVAR(buildPitch) - 5);
            } else {
                if (_ctrl) then {
                    // Ctrl+Q = bank left
                    GVAR(buildBank) = (GVAR(buildBank) - 5);
                } else {
                    // Q = yaw left
                    GVAR(buildRotation) = ((GVAR(buildRotation) - 5) + 360) mod 360;
                };
            };
            false
        };
        // E key (18) — rotate
        case 18: {
            if (_shift) then {
                // Shift+E = pitch up
                GVAR(buildPitch) = (GVAR(buildPitch) + 5);
            } else {
                if (_ctrl) then {
                    // Ctrl+E = bank right
                    GVAR(buildBank) = (GVAR(buildBank) + 5);
                } else {
                    // E = yaw right
                    GVAR(buildRotation) = (GVAR(buildRotation) + 5) mod 360;
                };
            };
            false
        };
        // TAB (15) — toggle snap
        case 15: {
            if (isNil "OLI_engtools_snapActive") then { OLI_engtools_snapActive = false; };
            OLI_engtools_snapActive = !OLI_engtools_snapActive;

            if (!OLI_engtools_snapActive) then {
                GVAR(buildSnapBaseDir) = nil;
                GVAR(buildSnapLocked) = nil;
                OLI_engtools_buildHeight = 0;
            } else {
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
        // PgUp (201)
        case 201: {
            OLI_engtools_buildHeight = parseNumber (str (round ((OLI_engtools_buildHeight + 0.10) * 100) / 100));
            false
        };
        // PgDn (209)
        case 209: {
            OLI_engtools_buildHeight = parseNumber (str (round ((OLI_engtools_buildHeight - 0.10) * 100) / 100));
            false
        };
        // Backspace (14) — reset pitch/bank
        case 14: {
            GVAR(buildPitch) = 0;
            GVAR(buildBank) = 0;
            hintSilent parseText "<t color='#AAAAAA'>Pitch & Bank reset to 0°</t>";
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

    // LMB – place
    if (_button == 0) exitWith {
        if !(GVAR(canPlaceObject)) exitWith {
            systemChat "[Engineer] Too far – must be within 15m";
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

        // ── Location restriction check ──────────────────────────────────────
        private _locations = missionNamespace getVariable [QGVAR(buildLocations), []];
        if (count _locations > 0) then {
            private _inArea = false;
            { if (player inArea _x) exitWith { _inArea = true; }; } forEach _locations;

            if (!_inArea) exitWith {
                systemChat "[Engineer] Outside build zone – cannot place here.";
            };
        };

        // ── Deploy handlers check ───────────────────────────────────────────
        private _handlers = missionNamespace getVariable [QGVAR(deployHandlers), []];
        private _blocked = false;
        {
            if (([player, GVAR(buildingObject), _cls] call _x) isEqualTo false) exitWith {
                _blocked = true;
            };
        } forEach _handlers;

        if (_blocked) exitWith {
            systemChat "[Engineer] Placement blocked by mission rules.";
            false
        };

        // ── Read vectors DIRECTLY from ghost object (ACE approach) ──────────
        private _finalPos  = getPosASL GVAR(buildingObject);
        private _vecDir    = vectorDir GVAR(buildingObject);
        private _vecUp     = vectorUp  GVAR(buildingObject);

        diag_log format ["[OLI Eng PLACE] cls:%1 vecDir:%2 vecUp:%3 (read from ghost)",
            _cls, _vecDir, _vecUp];

        [] call FUNC(cancelBuild);

        // ── Build timer or instant ──────────────────────────────────────────
        private _buildTimeEnabled = missionNamespace getVariable [QGVAR(setting_enableBuildTime), true];
        private _buildTime = missionNamespace getVariable [QGVAR(setting_buildTime), DEFAULT_BUILD_TIME];

        if (_buildTimeEnabled && _buildTime > 0) then {
            [_cls, _finalPos, _cost, _vecDir, _vecUp] spawn FUNC(progressBuild);
        } else {
            if (_resourcesEnabled) then {
                private _currentRes = player getVariable [QGVAR(resources), 0];
                player setVariable [QGVAR(resources), _currentRes - _cost, true];
            };

            if (isMultiplayer) then {
                [_cls, _finalPos, 0, _vecDir, _vecUp] remoteExec [QFUNC(createBuiltObject), 2];
            } else {
                [_cls, _finalPos, 0, _vecDir, _vecUp] call FUNC(createBuiltObject);
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


// ── SCROLL WHEEL – adjust placement distance ─────────────────────────────────
GVAR(buildScrollEH) = (findDisplay 46) displayAddEventHandler ["MouseZChanged", {
    params ["_display", "_scroll"];
    if (isNil QGVAR(buildingObject)) exitWith {};
    if (isNull GVAR(buildingObject)) exitWith {};

    // Scroll up = push further, scroll down = pull closer
    private _step = 0.5;
    if (_scroll > 0) then {
        GVAR(buildDistOffset) = GVAR(buildDistOffset) + _step;
    } else {
        GVAR(buildDistOffset) = (GVAR(buildDistOffset) - _step) max -3;
    };
}];
