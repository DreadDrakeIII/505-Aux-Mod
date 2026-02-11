#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_buildObject
 *
 * Controls:
 *   LMB             – Place (repeats)
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

// Ghost preview
private _previewObj = _classname createVehicleLocal [0,0,0];
_previewObj allowDamage false;
_previewObj enableSimulation false;
GVAR(buildingObject) = _previewObj;
GVAR(buildClassname) = _classname;

// Build HUD
private _snapStr = if (OLI_engtools_snapActive) then {"<t color='#00AAFF'>ON</t>"} else {"<t color='#888888'>OFF</t>"};
hint parseText format [
    "<t size='1.1' color='#FFA500'>BUILD MODE</t>  <t size='0.8' color='#AAAAAA'>%1</t><br/><t size='0.85' color='#FFFF00'>Rotation: %2°  |  Height: %3m  |  Snap: %4</t><br/><br/><t color='#FFFFFF'>LMB</t><t color='#AAAAAA'> – Place   </t><t color='#FFFFFF'>Q/E</t><t color='#AAAAAA'> – Rotate 5°   </t><t color='#FFFFFF'>TAB</t><t color='#AAAAAA'> – Toggle Snap<br/>PgUp/PgDn</t><t color='#AAAAAA'> – Height   </t><t color='#FFFFFF'>RMB/Scroll</t><t color='#AAAAAA'> – Back to Menu   </t><t color='#FFFFFF'>Shift+RMB</t><t color='#AAAAAA'> – Delete</t>",
    _classname, GVAR(buildRotation), OLI_engtools_buildHeight, _snapStr
];

// ── HELPER: Get wall half-extents and long-axis azimuth ───────────────────────
// Returns [halfLen, sideAzimuth] for a given object and reference direction.
//
// OPTRE/TKE barriers are NOT all the same orientation in model space.
//   – Some have their length along model X  → world sideAz = dir + 90
//   – Some have their length along model Y  → world sideAz = dir
// We detect which axis is longer from the bounding box and choose accordingly.
//
// _refDir is the getDir of the object.
OLI_engtools_fnc_getWallAxis = {
    params ["_obj", "_refDir"];
    private _bb   = boundingBoxReal _obj;
    private _halfX = abs ((_bb select 1 select 0) - (_bb select 0 select 0)) / 2;
    private _halfY = abs ((_bb select 1 select 1) - (_bb select 0 select 1)) / 2;
    // Long axis in model space
    if (_halfX >= _halfY) then {
        // Model X is longer → wall runs perpendicular to facing → azimuth = dir + 90
        [_halfX, _refDir + 90]
    } else {
        // Model Y is longer → wall runs along facing direction → azimuth = dir
        [_halfY, _refDir]
    }
};

// ── PER-FRAME ─────────────────────────────────────────────────────────────────
GVAR(buildEH) = addMissionEventHandler ["EachFrame", {
    if (isNil QGVAR(buildingObject)) exitWith {};
    if (isNull GVAR(buildingObject)) exitWith {};

    private _pos = screenToWorld [0.5, 0.5];

    // ── SNAP ─────────────────────────────────────────────────────────────────
    if (!isNil "OLI_engtools_snapActive" && { OLI_engtools_snapActive }) then {

        private _nearObjs = (nearestObjects [_pos, [], 14]) select {
            !isNull _x && { _x getVariable [QGVAR(builtObject), false] }
        };

        if (count _nearObjs > 0) then {

            // Closest placed wall to cursor
            private _nearObj  = objNull;
            private _nearDist = 9999;
            {
                private _d = sqrt (((_pos select 0) - (getPosASL _x select 0))^2
                                 + ((_pos select 1) - (getPosASL _x select 1))^2);
                if (_d < _nearDist) then { _nearDist = _d; _nearObj = _x; };
            } forEach _nearObjs;

            if (!isNull _nearObj) then {
                private _snapDir = getDir _nearObj;
                private _nearASL = getPosASL _nearObj;

                // ── EXISTING wall: detect long axis per-object ─────────────
                private _axisE  = [_nearObj, _snapDir] call OLI_engtools_fnc_getWallAxis;
                private _halfE  = _axisE select 0;   // existing half-length
                private _sideAz = _axisE select 1;   // world azimuth of long axis

                // ── NEW object: get its half-extent along the SAME world axis
                // We project the new object's model extents onto the snap axis
                private _bbN    = boundingBoxReal GVAR(buildingObject);
                private _halfXN = abs ((_bbN select 1 select 0) - (_bbN select 0 select 0)) / 2;
                private _halfYN = abs ((_bbN select 1 select 1) - (_bbN select 0 select 1)) / 2;
                // Which model axis of the new object aligns with _sideAz?
                // New object inherits the snap rotation, so its model axes align
                // with the existing wall → use same logic (X vs Y detection)
                private _newLongIsX = (_halfXN >= _halfYN);
                private _halfN = if (_newLongIsX) then { _halfXN } else { _halfYN };

                // ── Candidate centres (edge-to-edge, no overlap, no gap) ───
                private _offset = _halfE + _halfN;

                private _cAx = (_nearASL select 0) + _offset * sin _sideAz;
                private _cAy = (_nearASL select 1) + _offset * cos _sideAz;
                private _cBx = (_nearASL select 0) - _offset * sin _sideAz;
                private _cBy = (_nearASL select 1) - _offset * cos _sideAz;

                private _dA = sqrt ((_cAx - (_pos select 0))^2 + (_cAy - (_pos select 1))^2);
                private _dB = sqrt ((_cBx - (_pos select 0))^2 + (_cBy - (_pos select 1))^2);

                // Snap threshold: cursor within ~1.5× existing half-length of its endpoint
                private _threshold = (_halfE * 1.5) max 4;
                if ((_dA min _dB) < _threshold) then {
                    if (_dA < _dB) then {
                        _pos = [_cAx, _cAy, _pos select 2];
                    } else {
                        _pos = [_cBx, _cBy, _pos select 2];
                    };
                    // Inherit exact direction from snapped wall
                    GVAR(buildRotation) = _snapDir;
                    hintSilent parseText format [
                        "<t color='#00AAFF'>SNAP ▸ Flush</t>   <t color='#FFFF00'>%1°</t><br/><t color='#888888'>TAB – toggle off</t>",
                        _snapDir
                    ];
                } else {
                    hintSilent parseText "<t color='#00AAFF'>SNAP</t><t color='#888888'> Scanning…</t>";
                };
            };
        } else {
            hintSilent parseText "<t color='#00AAFF'>SNAP</t><t color='#888888'> No walls nearby</t>";
        };
    };
    // ── END SNAP ─────────────────────────────────────────────────────────────

    // Z
    private _z = if (OLI_engtools_levelTerrain) then {
        getTerrainHeightASL _pos
    } else {
        (ATLToASL [_pos select 0, _pos select 1, 0]) select 2
    };
    _z = _z + OLI_engtools_buildHeight;

    private _posASL = [_pos select 0, _pos select 1, _z];
    GVAR(buildingObject) setPosASL _posASL;
    GVAR(buildingObject) setDir GVAR(buildRotation);
    GVAR(buildingObject) setPosASL _posASL;

    GVAR(canPlaceObject) = (player distance GVAR(buildingObject) < 15);
}];

// ── KEY HANDLER ───────────────────────────────────────────────────────────────
GVAR(buildKeyEH) = (findDisplay 46) displayAddEventHandler ["KeyDown", {
    params ["_display", "_key"];
    if (isNil QGVAR(buildingObject)) exitWith {false};
    if (isNull GVAR(buildingObject)) exitWith {false};

    switch (_key) do {

        // Q – rotate CCW 5°
        case 16: {
            GVAR(buildRotation) = ((GVAR(buildRotation) - 5) + 360) mod 360;
            hintSilent parseText format [
                "<t size='1.2' color='#FFA500'>%1°</t>  <t color='#AAAAAA'>← CCW</t>",
                GVAR(buildRotation)
            ];
            false
        };

        // E – rotate CW 5°
        case 18: {
            GVAR(buildRotation) = (GVAR(buildRotation) + 5) mod 360;
            hintSilent parseText format [
                "<t size='1.2' color='#FFA500'>%1°</t>  <t color='#AAAAAA'>CW →</t>",
                GVAR(buildRotation)
            ];
            false
        };

        // TAB (key 15) – toggle snap ON/OFF
        case 15: {
            if (isNil "OLI_engtools_snapActive") then { OLI_engtools_snapActive = false; };
            OLI_engtools_snapActive = !OLI_engtools_snapActive;

            // Sync menu button display only (variable already flipped above)
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

        // PgUp – raise +0.10m
        case 201: {
            OLI_engtools_buildHeight = parseNumber (str (round ((OLI_engtools_buildHeight + 0.10) * 100) / 100));
            hintSilent parseText format [
                "<t size='1.2' color='#FFA500'>%1m</t>  <t color='#AAAAAA'>▲ Height</t>",
                OLI_engtools_buildHeight
            ];
            false
        };

        // PgDn – lower -0.10m
        case 209: {
            OLI_engtools_buildHeight = parseNumber (str (round ((OLI_engtools_buildHeight - 0.10) * 100) / 100));
            hintSilent parseText format [
                "<t size='1.2' color='#FFA500'>%1m</t>  <t color='#AAAAAA'>▼ Height</t>",
                OLI_engtools_buildHeight
            ];
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

        private _finalPos = getPosASL GVAR(buildingObject);
        private _finalDir = getDir    GVAR(buildingObject);
        private _cls      = GVAR(buildClassname);

        [] call FUNC(cancelBuild);

        if (isMultiplayer) then {
            [_cls, _finalPos, _finalDir] remoteExec [QFUNC(createBuiltObject), 2];
        } else {
            [_cls, _finalPos, _finalDir] call FUNC(createBuiltObject);
        };

        [_cls] spawn {
            params ["_c"];
            sleep 0.1;
            [_c] call FUNC(buildObject);
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
