#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_buildObject
 * v10 — ACE-inspired placement system
 * All feedback via hint (no systemChat/diag_log).
 * LMB always consumed (true) to prevent weapon fire.
 */

params [["_classname", "", [""]]];

if (_classname isEqualTo "") exitWith {};

// ── Location restriction check ───────────────────────────────────────────────
private _locations = missionNamespace getVariable [QGVAR(buildLocations), []];
if (count _locations > 0) then {
    private _inArea = false;
    { if (player inArea _x) exitWith { _inArea = true; }; } forEach _locations;

    if (!_inArea) exitWith {
        hint parseText "<t size='1.1' color='#FF4444'>RESTRICTED AREA</t><br/><t color='#AAAAAA'>You must be inside a designated build zone.</t>";
    };
};

// ── Globals ───────────────────────────────────────────────────────────────────
if (isNil "OLI_engtools_buildHeight")  then { OLI_engtools_buildHeight  = 0;     };
if (isNil "OLI_engtools_levelTerrain") then { OLI_engtools_levelTerrain = true;  };
if (isNil "OLI_engtools_snapActive")   then { OLI_engtools_snapActive   = false; };
[] call FUNC(cancelBuild);
if (isNil QGVAR(buildRotation)) then { GVAR(buildRotation) = 0; };
if (isNil QGVAR(buildPitch)) then { GVAR(buildPitch) = 0; };
if (isNil QGVAR(buildBank))  then { GVAR(buildBank)  = 0; };
if (isNil QGVAR(buildDistOffset)) then { GVAR(buildDistOffset) = 0; };

// ── Resource check before entering build mode ────────────────────────────────
private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
private _cost = [_classname] call FUNC(getObjectCost);

private _canEnter = true;
if (_resourcesEnabled) then {
    private _currentRes = player getVariable [QGVAR(resources), 0];
    if (_currentRes < _cost) then { _canEnter = false; };
};
if (!_canEnter) exitWith {
    private _currentRes = player getVariable [QGVAR(resources), 0];
    hint parseText format [
        "<t size='1.1' color='#FF4444'>INSUFFICIENT RESOURCES</t><br/><br/>" +
        "<t color='#FFFFFF'>Cost: %1</t>  |  <t color='#FF6666'>Available: %2</t>",
        _cost, _currentRes
    ];
};

// ── Ghost preview — create at origin, kill sim, disable collision ─────────────
private _previewObj = _classname createVehicleLocal [0,0,0];
_previewObj enableSimulation false;
_previewObj allowDamage false;
_previewObj disableCollisionWith player;

GVAR(buildingObject) = _previewObj;
GVAR(buildClassname) = _classname;

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

                private _bbT = boundingBoxReal _nearObj;
                private _tHalfX = abs ((_bbT select 1 select 0) - (_bbT select 0 select 0)) / 2;
                private _tHalfY = abs ((_bbT select 1 select 1) - (_bbT select 0 select 1)) / 2;
                private _tLongIsX = (_tHalfX >= _tHalfY);

                _snapped = true;

                private _flatDir = (_targetVecDir select 0) atan2 (_targetVecDir select 1);
                private _baseDir = (_flatDir + 360) mod 360;

                if (isNil QGVAR(buildSnapLocked)) then {
                    GVAR(buildSnapLocked) = true;
                    GVAR(buildRotation) = _baseDir;
                    OLI_engtools_buildHeight = 0;
                };
                GVAR(buildSnapBaseDir) = _baseDir;

                private _delta = GVAR(buildRotation) - _baseDir;
                private _sinD = sin _delta;
                private _cosD = cos _delta;

                private _vecRight = _targetVecDir vectorCrossProduct _targetVecUp;
                _vecRight = vectorNormalized _vecRight;

                private _rotatedDir = (_targetVecDir vectorMultiply _cosD) vectorAdd (_vecRight vectorMultiply _sinD);
                _rotatedDir = vectorNormalized _rotatedDir;

                private _longAxisWorld = if (_tLongIsX) then { _vecRight } else { _targetVecDir };
                private _cursorDelta = _basePos vectorDiff _targetPos;
                private _sideOffset = _cursorDelta vectorDotProduct _longAxisWorld;

                private _snapPos = _targetPos vectorAdd (_longAxisWorld vectorMultiply _sideOffset);

                if (OLI_engtools_buildHeight != 0) then {
                    _snapPos = _snapPos vectorAdd (_targetVecUp vectorMultiply OLI_engtools_buildHeight);
                };

                GVAR(buildingObject) setPosASL _snapPos;
                GVAR(buildingObject) setVectorDirAndUp [_rotatedDir, _targetVecUp];
                GVAR(buildingObject) setPosASL _snapPos;

                if (player distance GVAR(buildingObject) < 15) then {
                    GVAR(buildingObject) setObjectTextureGlobal [0, "#(argb,8,8,3)color(0.2,0.8,0.3,0.6)"];
                } else {
                    GVAR(buildingObject) setObjectTextureGlobal [0, "#(argb,8,8,3)color(1.0,0.15,0.1,0.6)"];
                };

                GVAR(canPlaceObject) = (player distance GVAR(buildingObject) < 15);
            };
        } else {
            GVAR(buildSnapBaseDir) = nil;
            GVAR(buildSnapLocked) = nil;
        };
    };

    // ── Non-snapped: free placement with camera direction ────────────────────
    if (!_snapped) then {
        private _altHeld = inputAction "tacticView" > 0;
        private _yaw = 180 + GVAR(buildRotation) + getDir player;

        if (_altHeld) then {
            GVAR(buildingObject) setPosASL _basePos;
            GVAR(buildingObject) setDir _yaw;
            GVAR(buildingObject) setVectorUp (surfaceNormal (ASLToAGL _basePos));
        } else {
            private _pitch = if (!isNil QGVAR(buildPitch)) then { GVAR(buildPitch) } else { 0 };
            private _bank  = if (!isNil QGVAR(buildBank))  then { GVAR(buildBank)  } else { 0 };

            if (_pitch == 0 && _bank == 0) then {
                private _r = GVAR(buildRotation);
                GVAR(buildingObject) setPosASL _basePos;
                GVAR(buildingObject) setVectorDirAndUp [[sin _r, cos _r, 0], [0, 0, 1]];
            } else {
                ([_pitch, _bank, GVAR(buildRotation)] call OLI_engtools_fnc_pitchBankYawToVectors)
                    params ["_vecDir", "_vecUp"];
                GVAR(buildingObject) setPosASL _basePos;
                GVAR(buildingObject) setVectorDirAndUp [_vecDir, _vecUp];
            };
        };
        GVAR(buildingObject) setPosASL _basePos;

        if (player distance GVAR(buildingObject) < 15) then {
            GVAR(buildingObject) setObjectTextureGlobal [0, "#(argb,8,8,3)color(0.2,0.8,0.3,0.6)"];
        } else {
            GVAR(buildingObject) setObjectTextureGlobal [0, "#(argb,8,8,3)color(1.0,0.15,0.1,0.6)"];
        };

        GVAR(canPlaceObject) = (player distance GVAR(buildingObject) < 15);
    };

    // ── HUD with persistent controls ─────────────────────────────────────────
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

    // Resource info
    private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
    private _cls = if (!isNil QGVAR(buildClassname)) then { GVAR(buildClassname) } else { "" };
    private _cost = if (_cls != "") then { [_cls] call FUNC(getObjectCost) } else { 0 };
    private _resLine = if (_resourcesEnabled) then {
        private _res = player getVariable [QGVAR(resources), 0];
        format ["<br/><t size='0.85' color='#FFAA00'>Cost: %1</t>  <t size='0.85' color='#55CC66'>Resources: %2</t>", _cost, _res]
    } else { "" };

    private _ctrlHint = "<br/><t size='0.75' color='#666666'>Q/E Yaw  |  Shift+Q/E Pitch  |  Ctrl+Q/E Bank  |  Scroll Distance</t><br/><t size='0.75' color='#666666'>PgUp/PgDn Height  |  ALT Terrain  |  TAB Snap  |  Backspace Reset</t><br/><t size='0.75' color='#666666'>LMB Place  |  RMB Menu  |  Shift+RMB Delete</t>";

    if (_snapped) then {
        hintSilent parseText format [
            "<t color='#00AAFF'>SNAP</t>  <t color='#FFA500'>%1°</t>%2%3%4%5%6",
            round GVAR(buildRotation), _heightStr, _distStr, _pitchBankStr, _resLine, _ctrlHint
        ];
    } else {
        if (!isNil "OLI_engtools_snapActive" && { OLI_engtools_snapActive }) then {
            hintSilent parseText format [
                "<t color='#00AAFF'>SNAP</t><t color='#888888'> Scanning…</t>  <t color='#FFA500'>%1°</t>%2%3%4%5%6%7",
                round GVAR(buildRotation), _heightStr, _distStr, _pitchBankStr, _terrainStr, _resLine, _ctrlHint
            ];
        } else {
            hintSilent parseText format [
                "<t size='1.1' color='#FFA500'>BUILD MODE</t>  <t size='0.9' color='#FFA500'>%1°</t>%2%3%4%5%6%7",
                round GVAR(buildRotation), _heightStr, _distStr, _pitchBankStr, _terrainStr, _resLine, _ctrlHint
            ];
        };
    };
}];

// ── KEY HANDLER ───────────────────────────────────────────────────────────────
GVAR(buildKeyEH) = (findDisplay 46) displayAddEventHandler ["KeyDown", {
    params ["_display", "_key", "_shift", "_ctrl", "_alt"];
    if (isNil QGVAR(buildingObject)) exitWith {false};
    if (isNull GVAR(buildingObject)) exitWith {false};

    // Capture switch result — returning true CONSUMES the key, blocks engine lean
    private _handled = switch (_key) do {
        // Q key (16) — rotate (return true to BLOCK lean)
        case 16: {
            if (_shift) then {
                GVAR(buildPitch) = (GVAR(buildPitch) - 5);
            } else {
                if (_ctrl) then {
                    GVAR(buildBank) = (GVAR(buildBank) - 5);
                } else {
                    GVAR(buildRotation) = ((GVAR(buildRotation) - 5) + 360) mod 360;
                };
            };
            true
        };
        // E key (18) — rotate (return true to BLOCK lean)
        case 18: {
            if (_shift) then {
                GVAR(buildPitch) = (GVAR(buildPitch) + 5);
            } else {
                if (_ctrl) then {
                    GVAR(buildBank) = (GVAR(buildBank) + 5);
                } else {
                    GVAR(buildRotation) = (GVAR(buildRotation) + 5) mod 360;
                };
            };
            true
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
            true
        };
        // PgUp (201)
        case 201: {
            OLI_engtools_buildHeight = parseNumber (str (round ((OLI_engtools_buildHeight + 0.10) * 100) / 100));
            true
        };
        // PgDn (209)
        case 209: {
            OLI_engtools_buildHeight = parseNumber (str (round ((OLI_engtools_buildHeight - 0.10) * 100) / 100));
            true
        };
        // Backspace (14) — reset pitch/bank
        case 14: {
            GVAR(buildPitch) = 0;
            GVAR(buildBank) = 0;
            true
        };
        default { false };
    };
    _handled
}];

// ── MOUSE HANDLER ─────────────────────────────────────────────────────────────
GVAR(buildMouseEH) = (findDisplay 46) displayAddEventHandler ["MouseButtonDown", {
    params ["_display", "_button", "_xPos", "_yPos", "_shift"];
    if (isNil QGVAR(buildingObject)) exitWith {false};
    if (isNull GVAR(buildingObject)) exitWith {false};

    // Shift+RMB – quick delete nearest
    if (_button == 1 && _shift) exitWith {
        [] call FUNC(deleteNearestBuilt);
        true
    };

    // RMB – back to menu
    if (_button == 1 && !_shift) exitWith {
        [] call FUNC(cancelBuild);
        [] spawn { sleep 0.05; [] call FUNC(openEngineerMenu); };
        true
    };

    // LMB – place (ALWAYS return true to block weapon fire)
    if (_button == 0) exitWith {
        if !(GVAR(canPlaceObject)) exitWith {
            hint parseText "<t size='1.0' color='#FF4444'>TOO FAR</t><br/><t color='#AAAAAA'>Must be within 15m to place.</t>";
            true
        };

        private _cls = GVAR(buildClassname);
        private _cost = [_cls] call FUNC(getObjectCost);
        private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];

        // ── Resource check (flag pattern) ───────────────────────────────────
        private _canAfford = true;
        if (_resourcesEnabled) then {
            private _currentRes = player getVariable [QGVAR(resources), 0];
            if (_currentRes < _cost) then {
                _canAfford = false;
            };
        };
        if (!_canAfford) exitWith {
            private _currentRes = player getVariable [QGVAR(resources), 0];
            hint parseText format [
                "<t size='1.1' color='#FF4444'>INSUFFICIENT RESOURCES</t><br/><br/>" +
                "<t color='#FFFFFF'>Cost: %1</t>  |  <t color='#FF6666'>Have: %2</t>",
                _cost, _currentRes
            ];
            true
        };

        // ── Location restriction check ──────────────────────────────────────
        private _inBuildZone = true;
        private _locations = missionNamespace getVariable [QGVAR(buildLocations), []];
        if (count _locations > 0) then {
            _inBuildZone = false;
            { if (player inArea _x) exitWith { _inBuildZone = true; }; } forEach _locations;
        };
        if (!_inBuildZone) exitWith {
            hint parseText "<t size='1.0' color='#FF4444'>RESTRICTED AREA</t><br/><t color='#AAAAAA'>Outside designated build zone.</t>";
            true
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
            hint parseText "<t size='1.0' color='#FF4444'>BLOCKED</t><br/><t color='#AAAAAA'>Placement blocked by mission rules.</t>";
            true
        };

        // ── Read vectors DIRECTLY from ghost object (ACE approach) ──────────
        private _finalPos  = getPosASL GVAR(buildingObject);
        private _vecDir    = vectorDir GVAR(buildingObject);
        private _vecUp     = vectorUp  GVAR(buildingObject);

        [] call FUNC(cancelBuild);

        // ── Build timer or instant ──────────────────────────────────────────
        private _buildTimeEnabled = missionNamespace getVariable [QGVAR(setting_enableBuildTime), true];
        private _buildTime = missionNamespace getVariable [QGVAR(setting_buildTime), DEFAULT_BUILD_TIME];

        if (_buildTimeEnabled && _buildTime > 0) then {
            [_cls, _finalPos, _cost, _vecDir, _vecUp] spawn FUNC(progressBuild);
        } else {
            // Instant build — deduct and create
            if (_resourcesEnabled) then {
                private _currentRes = player getVariable [QGVAR(resources), 0];
                player setVariable [QGVAR(resources), _currentRes - _cost, true];
            };

            if (isMultiplayer) then {
                [_cls, _finalPos, 0, _vecDir, _vecUp] remoteExec [QFUNC(createBuiltObject), 2];
            } else {
                [_cls, _finalPos, 0, _vecDir, _vecUp] call FUNC(createBuiltObject);
            };

            // Show build confirmation hint
            private _newRes = player getVariable [QGVAR(resources), 0];
            if (_resourcesEnabled) then {
                hint parseText format [
                    "<t size='1.1' color='#55CC66'>BUILT</t><br/><br/>" +
                    "<t color='#FFFFFF'>%1</t><br/>" +
                    "<t color='#FFA500'>Cost: -%2</t>  |  <t color='#55CC66'>Remaining: %3</t>",
                    _cls, _cost, _newRes
                ];
            } else {
                hint parseText format [
                    "<t size='1.1' color='#55CC66'>BUILT</t><br/><br/><t color='#FFFFFF'>%1</t>",
                    _cls
                ];
            };

            [_cls] spawn {
                params ["_c"];
                sleep 0.1;
                [_c] call FUNC(buildObject);
            };
        };
        true
    };
    true
}];

// ── SCROLL WHEEL – adjust placement distance ─────────────────────────────────
GVAR(buildScrollEH) = (findDisplay 46) displayAddEventHandler ["MouseZChanged", {
    params ["_display", "_scroll"];
    if (isNil QGVAR(buildingObject)) exitWith {};
    if (isNull GVAR(buildingObject)) exitWith {};

    private _step = 0.5;
    if (_scroll > 0) then {
        GVAR(buildDistOffset) = GVAR(buildDistOffset) + _step;
    } else {
        GVAR(buildDistOffset) = (GVAR(buildDistOffset) - _step) max -3;
    };
}];
