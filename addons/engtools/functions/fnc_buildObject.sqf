#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_buildObject
 * v15 — All fixes:
 * 1. TerrainToggle/SnapToggle buttons removed from menu (ALT/F replace them)
 * 2. PgUp/PgDn height keybinds restored (cases 201/209)
 * 3. Terrain lock: G key (DIK 34) toggles snapToGround — no ALT conflict
 *    ALT scroll mode removed; ALT now only used for tacticView terrain align
 *    Height scroll mode: hold Ctrl+Shift+Scroll or use dedicated PgUp/PgDn
 * 4. Engineer scroll action hidden during build mode, restored on cancel
 * 5. PiP+HUD auto-show on object select, auto-hide on menu close
 *    TAB is now free — removed from keybind system
 * 6. Snap alignment fix — preserves target object vectorUp correctly
 * 7. Rotation locked to 5° multiples (mod 5 clamp on all rotation changes)
 *
 * KEYBINDS:
 *   Scroll            Rotate (5° steps, always multiple of 5)
 *   ALT + Scroll      Height up/down
 *   Ctrl + Scroll     Distance (push/pull)
 *   Shift + Scroll    5x boost
 *   Q / E             Rotate ±5°
 *   Shift+Q/E         Pitch ±5°
 *   Ctrl+Q/E          Bank ±5°
 *   SPACE             Toggle follow-slope (surfaceNormal)
 *   G                 Toggle snap-to-ground (lock Z to terrain)
 *   PgUp / PgDn       Height up/down (±0.10m steps)
 *   F                 Toggle object snap
 *   ALT               Terrain align (tacticView — hold for surface normal)
 *   Backspace         Reset ALL
 *   LMB               Place
 *   RMB               Cancel, reopen menu
 *   Shift+RMB         Delete nearest built object
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
if (isNil QGVAR(buildRotation))      then { GVAR(buildRotation)      = 0;     };
if (isNil QGVAR(buildPitch))         then { GVAR(buildPitch)         = 0;     };
if (isNil QGVAR(buildBank))          then { GVAR(buildBank)          = 0;     };
if (isNil QGVAR(buildDistOffset))    then { GVAR(buildDistOffset)    = 0;     };
if (isNil QGVAR(buildSnapToGround))  then { GVAR(buildSnapToGround)  = false; };
if (isNil QGVAR(buildVectorSurface)) then { GVAR(buildVectorSurface) = false; };
GVAR(buildBoost)      = false;
GVAR(buildHeightMode) = false;
GVAR(buildDistMode)   = false;

// ── Resource check ────────────────────────────────────────────────────────────
private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
private _cost = [_classname] call FUNC(getObjectCost);
private _playerSide = side player;
private _canEnter = true;
if (_resourcesEnabled) then {
    private _currentRes = [_playerSide] call FUNC(getSideResources);
    if (_currentRes < _cost) then { _canEnter = false; };
};
if (!_canEnter) exitWith {
    private _currentRes = [_playerSide] call FUNC(getSideResources);
    hint parseText format [
        "<t size='1.1' color='#FF4444'>INSUFFICIENT RESOURCES</t><br/><br/>" +
        "<t color='#FFFFFF'>Cost: %1</t>  |  <t color='#FF6666'>Available: %2</t>",
        _cost, _currentRes
    ];
};

// ── Ghost preview ─────────────────────────────────────────────────────────────
private _previewObj = _classname createVehicleLocal [0,0,0];
_previewObj enableSimulation false;
_previewObj allowDamage false;
_previewObj disableCollisionWith player;
GVAR(buildingObject) = _previewObj;
GVAR(buildClassname) = _classname;

// ── FIX 4: Disable engineer scroll action during build mode ──────────────────
if (!isNil QGVAR(engineerActionID)) then {
    player removeAction GVAR(engineerActionID);
};

// ── FIX 5: Auto-show PiP camera + HUD ────────────────────────────────────────
[true] call FUNC(buildCameraAssist);
["show"] call FUNC(buildHUD);

// ── PER-FRAME ─────────────────────────────────────────────────────────────────
GVAR(buildEH) = addMissionEventHandler ["EachFrame", {
    if (isNil QGVAR(buildingObject)) exitWith {};
    if (isNull GVAR(buildingObject)) exitWith {};

    private _snapped = false;

    // Object dimensions
    private _bb = boundingBoxReal GVAR(buildingObject);
    private _halfX = abs ((_bb select 1 select 0) - (_bb select 0 select 0)) / 2;
    private _halfY = abs ((_bb select 1 select 1) - (_bb select 0 select 1)) / 2;
    private _halfZ = abs ((_bb select 1 select 2) - (_bb select 0 select 2)) / 2;
    private _distOffset = if (!isNil QGVAR(buildDistOffset)) then { GVAR(buildDistOffset) } else { 0 };
    private _distance = ((_halfX max _halfY) + 0.5 + _distOffset) max 0.5;

    // Camera-based positioning
    private _start = eyePos player;
    private _camDir = getCameraViewDirection player;
    private _basePos = _start vectorAdd (_camDir vectorMultiply _distance);
    _basePos set [2, ((_basePos select 2) - _halfZ) max (getTerrainHeightASL _basePos - 0.05)];

    // FIX 3: snapToGround (G key toggle) — lock Z to terrain surface
    if (!isNil QGVAR(buildSnapToGround) && { GVAR(buildSnapToGround) }) then {
        _basePos set [2, getTerrainHeightASL _basePos];
        OLI_engtools_buildHeight = 0;
    } else {
        if (OLI_engtools_buildHeight != 0) then {
            _basePos set [2, (_basePos select 2) + OLI_engtools_buildHeight];
        };
    };

    // Update PiP camera
    if (!isNil QGVAR(buildCameraEnabled) && { GVAR(buildCameraEnabled) } &&
        { !isNil QGVAR(buildCamera) } && { !isNull GVAR(buildCamera) }) then {
        private _bounding = ((boundingBoxReal GVAR(buildingObject) select 2) * 3) max 10 min 40;
        private _abovePos = (ASLToAGL getPosASL GVAR(buildingObject)) vectorAdd [0, 0, _bounding];
        GVAR(buildCamera) camSetPos _abovePos;
        GVAR(buildCamera) setVectorDirAndUp [[0, 0, -1], [0, 1, 0]];
        GVAR(buildCamera) camCommit 0;
    };

    // Surface vector (SPACE) — follow slope or stay upright
    private _vectorSurface = if (!isNil QGVAR(buildVectorSurface)) then { GVAR(buildVectorSurface) } else { false };
    private _defaultVecUp = if (_vectorSurface) then { surfaceNormal (ASLToAGL _basePos) } else { [0, 0, 1] };

    // FIX 6: Object snap — improved alignment
    if (!isNil "OLI_engtools_snapActive" && { OLI_engtools_snapActive }) then {
        private _nearObjs = (nearestObjects [ASLToAGL _basePos, [], 14]) select {
            !isNull _x && { _x getVariable [QGVAR(builtObject), false] }
        };

        if (count _nearObjs > 0) then {
            private _nearObj  = objNull;
            private _nearDist = 9999;
            { private _d = player distance _x; if (_d < _nearDist) then { _nearDist = _d; _nearObj = _x; }; } forEach _nearObjs;

            if (!isNull _nearObj) then {
                private _targetVecDir = vectorDir _nearObj;
                private _targetVecUp  = vectorUp  _nearObj;
                private _targetPos    = getPosASL _nearObj;
                private _bbT = boundingBoxReal _nearObj;
                private _tHalfX = abs ((_bbT select 1 select 0) - (_bbT select 0 select 0)) / 2;
                private _tHalfY = abs ((_bbT select 1 select 1) - (_bbT select 0 select 1)) / 2;
                private _tLongIsX = (_tHalfX >= _tHalfY);

                // Half-widths of object being placed
                private _myHalfX = _halfX;
                private _myHalfY = _halfY;

                _snapped = true;

                private _flatDir = (_targetVecDir select 0) atan2 (_targetVecDir select 1);
                private _baseDir = (_flatDir + 360) mod 360;
                if (isNil QGVAR(buildSnapLocked)) then {
                    GVAR(buildSnapLocked)    = true;
                    GVAR(buildRotation)      = (round (_baseDir / 5)) * 5 mod 360;
                    OLI_engtools_buildHeight = 0;
                    GVAR(buildSnapNudge)     = 0;
                    GVAR(buildSnapNudgeFwd)  = 0;
                };
                GVAR(buildSnapBaseDir) = _baseDir;

                private _delta = GVAR(buildRotation) - _baseDir;
                private _vecRight = vectorNormalized (_targetVecDir vectorCrossProduct _targetVecUp);

                // Use target direction directly when no rotation offset — avoids
                // floating point skew from round() causing slight misalignment
                private _rotatedDir = if (abs _delta < 1) then {
                    _targetVecDir
                } else {
                    vectorNormalized (
                        (_targetVecDir vectorMultiply (cos _delta)) vectorAdd
                        (_vecRight vectorMultiply (sin _delta))
                    )
                };

                // ── End-to-end chain snap ────────────────────────────────────
                // Long axis = the direction the wall runs (objects chain along this)
                // Place new object end-to-end: target_center ± (target_half + my_half)
                // along the long axis. Cursor determines which end to chain onto.
                // Z/X nudge slides along long axis, Shift+Z/X nudges perpendicular.

                private _longAxisWorld = if (_tLongIsX) then { _vecRight }     else { _targetVecDir };
                private _perpAxisWorld = if (_tLongIsX) then { _targetVecDir } else { _vecRight };

                // Half-lengths along the long axis
                private _tLongHalf = if (_tLongIsX) then { _tHalfX } else { _tHalfY };
                private _myLongHalf = if (_tLongIsX) then { _myHalfX } else { _myHalfY };

                // Which end of the target to chain onto (cursor side)
                private _cursorDelta = _basePos vectorDiff _targetPos;
                private _longSign = if ((_cursorDelta vectorDotProduct _longAxisWorld) >= 0) then { 1 } else { -1 };

                // Chain end-to-end — perfectly flush
                private _snapPos = _targetPos vectorAdd (_longAxisWorld vectorMultiply (_longSign * (_tLongHalf + _myLongHalf)));

                // Nudge offsets: Z/X = along long axis, Shift+Z/X = perpendicular
                private _nudge    = if (!isNil QGVAR(buildSnapNudge))    then { GVAR(buildSnapNudge)    } else { 0 };
                private _nudgeFwd = if (!isNil QGVAR(buildSnapNudgeFwd)) then { GVAR(buildSnapNudgeFwd) } else { 0 };
                _snapPos = _snapPos vectorAdd (_longAxisWorld vectorMultiply _nudge);
                _snapPos = _snapPos vectorAdd (_perpAxisWorld vectorMultiply _nudgeFwd);

                if (OLI_engtools_buildHeight != 0) then {
                    _snapPos = _snapPos vectorAdd (_targetVecUp vectorMultiply OLI_engtools_buildHeight);
                };

                GVAR(buildingObject) setPosASL _snapPos;
                // FIX 6: always use target's vectorUp so placed objects align on slope
                GVAR(buildingObject) setVectorDirAndUp [_rotatedDir, _targetVecUp];
                GVAR(buildingObject) setPosASL _snapPos;
                GVAR(buildingObject) setObjectTexture [0, if (player distance GVAR(buildingObject) < 15) then {"#(argb,8,8,3)color(0.2,0.8,0.3,0.6)"} else {"#(argb,8,8,3)color(1.0,0.15,0.1,0.6)"}];
                GVAR(canPlaceObject) = (player distance GVAR(buildingObject) < 15);
            };
        } else {
            GVAR(buildSnapBaseDir) = nil;
            GVAR(buildSnapLocked) = nil;
            GVAR(buildSnapNudge)   = 0;
            GVAR(buildSnapNudgeFwd) = 0;
        };
    };

    // Free placement
    if (!_snapped) then {
        private _altHeld = inputAction "tacticView" > 0;
        // FIX 7: rotation always a multiple of 5
        private _worldYaw = ((round (GVAR(buildRotation) / 5)) * 5 + getDir player) mod 360;
        private _pitch = if (!isNil QGVAR(buildPitch)) then { GVAR(buildPitch) } else { 0 };
        private _bank  = if (!isNil QGVAR(buildBank))  then { GVAR(buildBank)  } else { 0 };

        if (_altHeld) then {
            // ALT hold = surface normal align (tacticView)
            GVAR(buildingObject) setPosASL _basePos;
            GVAR(buildingObject) setDir _worldYaw;
            GVAR(buildingObject) setVectorUp (surfaceNormal (ASLToAGL _basePos));
        } else {
            if (_pitch == 0 && _bank == 0) then {
                GVAR(buildingObject) setPosASL _basePos;
                GVAR(buildingObject) setVectorDirAndUp [[sin _worldYaw, cos _worldYaw, 0], _defaultVecUp];
            } else {
                ([_pitch, _bank, _worldYaw] call OLI_engtools_fnc_pitchBankYawToVectors) params ["_vd", "_vu"];
                GVAR(buildingObject) setPosASL _basePos;
                GVAR(buildingObject) setVectorDirAndUp [_vd, if (_vectorSurface) then { _defaultVecUp } else { _vu }];
            };
        };
        GVAR(buildingObject) setPosASL _basePos;
        GVAR(buildingObject) setObjectTexture [0, if (player distance GVAR(buildingObject) < 15) then {"#(argb,8,8,3)color(0.2,0.8,0.3,0.6)"} else {"#(argb,8,8,3)color(1.0,0.15,0.1,0.6)"}];
        GVAR(canPlaceObject) = (player distance GVAR(buildingObject) < 15);
    };

    // ── HUD Status ───────────────────────────────────────────────────────────
    private _pitch2 = if (!isNil QGVAR(buildPitch)) then { GVAR(buildPitch) } else { 0 };
    private _bank2  = if (!isNil QGVAR(buildBank))  then { GVAR(buildBank)  } else { 0 };

    private _scrollMode = if (!isNil QGVAR(buildHeightMode) && { GVAR(buildHeightMode) }) then {
        "<t color='#FFA500'>[ALT]H</t>"
    } else { if (!isNil QGVAR(buildDistMode) && { GVAR(buildDistMode) }) then { "<t color='#66CCFF'>[CTRL]D</t>" } else { "<t color='#AAFFAA'>[SCR]ROT</t>" } };

    private _boostStr  = if (!isNil QGVAR(buildBoost) && { GVAR(buildBoost) })                        then { "  <t color='#FFFF44'>5x</t>" }              else { "" };
    private _heightStr = if (OLI_engtools_buildHeight != 0)                                            then { format ["  <t color='#FFA500'>H:%1m</t>", OLI_engtools_buildHeight] } else { "" };
    private _distStr   = if (!isNil QGVAR(buildDistOffset) && { GVAR(buildDistOffset) != 0 })         then { format ["  <t color='#66CCFF'>D:%1m</t>", round (GVAR(buildDistOffset) * 10) / 10] } else { "" };
    private _pbStr     = if (_pitch2 != 0 || _bank2 != 0)                                             then { format ["  <t color='#CC88FF'>P:%1 B:%2</t>", round _pitch2, round _bank2] } else { "" };
    private _snapStr   = if (!isNil "OLI_engtools_snapActive" && { OLI_engtools_snapActive })          then { "  <t color='#00AAFF'>SNAP</t>" }             else { "" };
    private _camStr    = if (!isNil QGVAR(buildCameraEnabled) && { GVAR(buildCameraEnabled) })        then { "  <t color='#88FFFF'>CAM</t>" }              else { "" };
    private _gndStr    = if (!isNil QGVAR(buildSnapToGround) && { GVAR(buildSnapToGround) })          then { "  <t color='#55CCFF'>GND</t>" }              else { "" };
    private _slopeStr  = if (!isNil QGVAR(buildVectorSurface) && { GVAR(buildVectorSurface) })        then { "  <t color='#AAFFCC'>SLOPE</t>" }            else { "" };

    private _cls2  = if (!isNil QGVAR(buildClassname)) then { GVAR(buildClassname) } else { "" };
    private _cost2 = if (_cls2 != "") then { [_cls2] call FUNC(getObjectCost) } else { 0 };
    private _resLine = if (missionNamespace getVariable [QGVAR(setting_enableResources), true]) then {
        private _res = [side player] call FUNC(getSideResources);
        private _sl = switch (side player) do { case WEST:{"BLUFOR"}; case EAST:{"OPFOR"}; case INDEPENDENT:{"INDFOR"}; default{"SIDE"}; };
        format ["  <t color='#FFAA00'>Cost:%1</t>  <t color='#55CC66'>%2:%3</t>", _cost2, _sl, _res]
    } else { "" };

    if (_snapped) then {
        private _nudgeStr = "";
        if (!isNil QGVAR(buildSnapNudge) && { GVAR(buildSnapNudge) != 0 }) then {
            _nudgeStr = format ["  <t color='#FFCC44'>LR:%1m</t>", round (GVAR(buildSnapNudge) * 100) / 100];
        };
        if (!isNil QGVAR(buildSnapNudgeFwd) && { GVAR(buildSnapNudgeFwd) != 0 }) then {
            _nudgeStr = _nudgeStr + format ["  <t color='#FFCC44'>FB:%1m</t>", round (GVAR(buildSnapNudgeFwd) * 100) / 100];
        };
        ["update", format ["<t color='#00AAFF'>SNAP</t>  <t color='#FFA500'>%1°</t>%2%3%4%5%6%7%8%9",
            (round (GVAR(buildRotation) / 5)) * 5 mod 360, _scrollMode, _boostStr, _heightStr, _distStr, _pbStr, _nudgeStr, _camStr, _resLine]] call FUNC(buildHUD);
    } else {
        ["update", format ["<t color='#FFA500'>BUILD</t>  <t color='#FFA500'>%1°</t>%2%3%4%5%6%7%8%9%10",
            (round (GVAR(buildRotation) / 5)) * 5 mod 360, _scrollMode, _boostStr, _heightStr, _distStr, _pbStr, _snapStr, _gndStr, _slopeStr, _resLine]] call FUNC(buildHUD);
    };
}];

// ── KEY DOWN ──────────────────────────────────────────────────────────────────
GVAR(buildKeyEH) = (findDisplay 46) displayAddEventHandler ["KeyDown", {
    params ["_display", "_key", "_shift", "_ctrl", "_alt"];
    if (isNil QGVAR(buildingObject)) exitWith {false};
    if (isNull GVAR(buildingObject)) exitWith {false};

    private _handled = switch (_key) do {
        case 16: { // Q — rotate left / Shift=pitch / Ctrl=bank
            if (_shift) then { GVAR(buildPitch) = GVAR(buildPitch) - 5; } else {
                if (_ctrl) then { GVAR(buildBank) = GVAR(buildBank) - 5; } else {
                    // FIX 7: clamp to 5° multiple
                    GVAR(buildRotation) = ((round ((GVAR(buildRotation) - 5) / 5)) * 5 + 360) mod 360;
                }; };
            true
        };
        case 18: { // E — rotate right / Shift=pitch / Ctrl=bank
            if (_shift) then { GVAR(buildPitch) = GVAR(buildPitch) + 5; } else {
                if (_ctrl) then { GVAR(buildBank) = GVAR(buildBank) + 5; } else {
                    GVAR(buildRotation) = (round ((GVAR(buildRotation) + 5) / 5)) * 5 mod 360;
                }; };
            true
        };
        case 57: { // SPACE — toggle follow-slope
            GVAR(buildVectorSurface) = !(if (isNil QGVAR(buildVectorSurface)) then {false} else {GVAR(buildVectorSurface)});
            true
        };
        case 34: { // G — toggle snap-to-ground (FIX 3: dedicated key, no ALT conflict)
            GVAR(buildSnapToGround) = !(if (isNil QGVAR(buildSnapToGround)) then {false} else {GVAR(buildSnapToGround)});
            if (GVAR(buildSnapToGround)) then {
                OLI_engtools_buildHeight = 0;
                GVAR(buildHeightMode) = false;
            };
            true
        };
        case 56: { // ALT — toggle height scroll mode
            GVAR(buildHeightMode) = !(if (isNil QGVAR(buildHeightMode)) then {false} else {GVAR(buildHeightMode)});
            if (GVAR(buildHeightMode)) then { GVAR(buildDistMode) = false; GVAR(buildSnapToGround) = false; };
            true
        };
        case 29: { // Ctrl — toggle distance scroll mode
            GVAR(buildDistMode) = !(if (isNil QGVAR(buildDistMode)) then {false} else {GVAR(buildDistMode)});
            if (GVAR(buildDistMode)) then { GVAR(buildHeightMode) = false; };
            true
        };
        case 44: { // Z — nudge left / Shift+Z = nudge forward
            if (!isNil QGVAR(buildSnapLocked) && { GVAR(buildSnapLocked) }) then {
                if (_shift) then {
                    GVAR(buildSnapNudgeFwd) = if (isNil QGVAR(buildSnapNudgeFwd)) then { 0.25 } else { GVAR(buildSnapNudgeFwd) + 0.25 };
                } else {
                    GVAR(buildSnapNudge) = if (isNil QGVAR(buildSnapNudge)) then { -0.25 } else { GVAR(buildSnapNudge) - 0.25 };
                };
            };
            true
        };
        case 45: { // X — nudge right / Shift+X = nudge backward
            if (!isNil QGVAR(buildSnapLocked) && { GVAR(buildSnapLocked) }) then {
                if (_shift) then {
                    GVAR(buildSnapNudgeFwd) = if (isNil QGVAR(buildSnapNudgeFwd)) then { -0.25 } else { GVAR(buildSnapNudgeFwd) - 0.25 };
                } else {
                    GVAR(buildSnapNudge) = if (isNil QGVAR(buildSnapNudge)) then { 0.25 } else { GVAR(buildSnapNudge) + 0.25 };
                };
            };
            true
        };
        case 33: { // F — toggle object snap
            if (isNil "OLI_engtools_snapActive") then { OLI_engtools_snapActive = false; };
            OLI_engtools_snapActive = !OLI_engtools_snapActive;
            if (!OLI_engtools_snapActive) then {
                GVAR(buildSnapBaseDir) = nil; GVAR(buildSnapLocked) = nil; OLI_engtools_buildHeight = 0;
            } else { GVAR(buildSnapLocked) = nil; OLI_engtools_buildHeight = 0; };
            true
        };
        case 201: { // PgUp — height up (FIX 2)
            OLI_engtools_buildHeight = parseNumber (str (round ((OLI_engtools_buildHeight + 0.10) * 100) / 100));
            true
        };
        case 209: { // PgDn — height down (FIX 2)
            OLI_engtools_buildHeight = parseNumber (str (round ((OLI_engtools_buildHeight - 0.10) * 100) / 100));
            true
        };
        case 42: { GVAR(buildBoost) = true; true }; // Shift — boost
        case 14: { // Backspace — reset ALL
            GVAR(buildRotation) = 0; GVAR(buildPitch) = 0; GVAR(buildBank) = 0;
            OLI_engtools_buildHeight = 0; GVAR(buildDistOffset) = 0;
            GVAR(buildHeightMode) = false; GVAR(buildDistMode) = false;
            GVAR(buildSnapToGround) = false; GVAR(buildVectorSurface) = false;
            GVAR(buildSnapNudge) = 0;
            GVAR(buildSnapNudgeFwd) = 0;
        };
        default { false };
    };
    _handled
}];

// ── KEY UP ────────────────────────────────────────────────────────────────────
GVAR(buildKeyUpEH) = (findDisplay 46) displayAddEventHandler ["KeyUp", {
    params ["_display", "_key"];
    if (isNil QGVAR(buildingObject)) exitWith {};
    if (isNull GVAR(buildingObject)) exitWith {};
    if (_key == 42) then { GVAR(buildBoost) = false; };
}];

// ── MOUSE HANDLER ─────────────────────────────────────────────────────────────
GVAR(buildMouseEH) = (findDisplay 46) displayAddEventHandler ["MouseButtonDown", {
    params ["_display", "_button", "_xPos", "_yPos", "_shift"];
    if (isNil QGVAR(buildingObject)) exitWith {false};
    if (isNull GVAR(buildingObject)) exitWith {false};

    if (_button == 1 && _shift) exitWith { [] call FUNC(deleteNearestBuilt); true };
    if (_button == 1 && !_shift) exitWith {
        [] call FUNC(cancelBuild);
        [] spawn { sleep 0.05; [] call FUNC(openEngineerMenu); };
        true
    };

    if (_button == 0) exitWith {
        if !(GVAR(canPlaceObject)) exitWith {
            hint parseText "<t size='1.0' color='#FF4444'>TOO FAR</t><br/><t color='#AAAAAA'>Must be within 15m to place.</t>";
            true
        };

        private _cls = GVAR(buildClassname);
        private _cost = [_cls] call FUNC(getObjectCost);
        private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
        private _playerSide = side player;

        private _canAfford = true;
        if (_resourcesEnabled) then {
            private _currentRes = [_playerSide] call FUNC(getSideResources);
            if (_currentRes < _cost) then { _canAfford = false; };
        };
        if (!_canAfford) exitWith {
            private _currentRes = [_playerSide] call FUNC(getSideResources);
            hint parseText format ["<t size='1.1' color='#FF4444'>INSUFFICIENT RESOURCES</t><br/><br/><t color='#FFFFFF'>Cost: %1</t>  |  <t color='#FF6666'>Have: %2</t>", _cost, _currentRes];
            true
        };

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

        private _handlers = missionNamespace getVariable [QGVAR(deployHandlers), []];
        private _blocked = false;
        { if (([player, GVAR(buildingObject), _cls] call _x) isEqualTo false) exitWith { _blocked = true; }; } forEach _handlers;
        if (_blocked) exitWith {
            hint parseText "<t size='1.0' color='#FF4444'>BLOCKED</t><br/><t color='#AAAAAA'>Placement blocked by mission rules.</t>";
            true
        };

        private _finalPos = getPosASL GVAR(buildingObject);
        private _vecDir   = vectorDir GVAR(buildingObject);
        private _vecUp    = vectorUp  GVAR(buildingObject);
        private _builder  = name player;

        [] call FUNC(cancelBuild);

        private _buildTimeEnabled = missionNamespace getVariable [QGVAR(setting_enableBuildTime), true];
        private _buildTime = missionNamespace getVariable [QGVAR(setting_buildTime), DEFAULT_BUILD_TIME];

        if (_buildTimeEnabled && _buildTime > 0) then {
            [_cls, _finalPos, _cost, _vecDir, _vecUp, _builder] spawn FUNC(progressBuild);
        } else {
            if (_resourcesEnabled) then {
                private _currentRes = [_playerSide] call FUNC(getSideResources);
                [_playerSide, _currentRes - _cost] remoteExec [QFUNC(setSideResources), 2];
            };

            // Handoff ghost
            private _hg = _cls createVehicleLocal [0,0,0];
            _hg allowDamage false; _hg enableSimulation false; _hg disableCollisionWith player;
            _hg setPosASL _finalPos;
            _hg setVectorDirAndUp [if (count _vecDir == 3) then {_vecDir} else {[0,1,0]}, if (count _vecUp == 3) then {_vecUp} else {[0,0,1]}];
            _hg setPosASL _finalPos;
            _hg setObjectTexture [0, "#(argb,8,8,3)color(0.2,0.8,0.3,0.6)"];

            [_hg, _finalPos] spawn {
                params ["_ghost", "_pos"];
                private _deadline = diag_tickTime + 8;
                waitUntil {
                    sleep 0.05;
                    private _seen = false;
                    { if (_x getVariable [QGVAR(builtObject), false]) exitWith { _seen = true; }; } forEach (nearestObjects [ASLToAGL _pos, [], 8]);
                    isNull _ghost || _seen || (diag_tickTime > _deadline)
                };
                if (!isNull _ghost) then { deleteVehicle _ghost; };
            };

            if (isMultiplayer) then {
                [_cls, _finalPos, 0, _vecDir, _vecUp, _builder] remoteExec [QFUNC(createBuiltObject), 2];
            } else {
                [_cls, _finalPos, 0, _vecDir, _vecUp, _builder] call FUNC(createBuiltObject);
            };

            // Repeat build
            private _repeatCls = _cls;
            [_repeatCls] spawn { params ["_c"]; sleep 0.15; [_c] call FUNC(buildObject); };
        };
        true
    };
    true
}];

// ── SCROLL WHEEL — mode based ─────────────────────────────────────────────────
GVAR(buildScrollEH) = (findDisplay 46) displayAddEventHandler ["MouseZChanged", {
    params ["_display", "_scroll"];
    if (isNil QGVAR(buildingObject)) exitWith {};
    if (isNull GVAR(buildingObject)) exitWith {};

    private _boost = if (!isNil QGVAR(buildBoost) && { GVAR(buildBoost) }) then { 5 } else { 1 };

    if (!isNil QGVAR(buildHeightMode) && { GVAR(buildHeightMode) }) then {
        OLI_engtools_buildHeight = parseNumber (str (round ((OLI_engtools_buildHeight + (_scroll * 0.1 * _boost)) * 100) / 100));
    } else {
        if (!isNil QGVAR(buildDistMode) && { GVAR(buildDistMode) }) then {
            GVAR(buildDistOffset) = (GVAR(buildDistOffset) + (_scroll * 0.2 * _boost)) max -3;
        } else {
            // FIX 7: rotation always multiple of 5
            private _step = 5 * _boost;
            GVAR(buildRotation) = ((round ((GVAR(buildRotation) + (_scroll * _step)) / 5)) * 5 + 3600) mod 360;
        };
    };
}];
