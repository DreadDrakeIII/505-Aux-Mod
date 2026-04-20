#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_deleteNearestBuilt
 * Deletes the engineer-built object the player is LOOKING AT (crosshair raycast).
 * Falls back to nearest within 5m if raycast hits nothing.
 * Refunds cost to side pool. Y/N confirmation.
 */

// ── Raycast from camera through crosshair ────────────────────────────────────
private _eyePos = eyePos player;
private _lookDir = getCameraViewDirection player;
private _endPos  = _eyePos vectorAdd (_lookDir vectorMultiply 30);

// Find what the crosshair is pointing at within 30m
private _obj = objNull;

// Use lineIntersectsWith to find built objects along the line of sight
private _candidates = (nearestObjects [player, [], 30]) select {
    !isNull _x && { _x getVariable [QGVAR(builtObject), false] }
};

if (count _candidates > 0) then {
    // Score each candidate by how close it is to the line of sight
    private _best = objNull;
    private _bestScore = 9999;

    {
        private _objPos = getPosASL _x;
        // Project object position onto the ray
        private _toObj  = _objPos vectorDiff _eyePos;
        private _along  = _toObj vectorDotProduct _lookDir;

        // Only consider objects in front of the player
        if (_along > 0 && _along < 30) then {
            private _closest = _eyePos vectorAdd (_lookDir vectorMultiply _along);
            private _perpDist = _objPos vectorDistance _closest;

            // Weight: perpendicular distance to ray (primary) + distance from player (secondary)
            private _score = _perpDist + (_along * 0.05);
            if (_score < _bestScore) then {
                _bestScore = _score;
                _best = _x;
            };
        };
    } forEach _candidates;

    // Accept if perpendicular distance is within ~3m (generous for large objects)
    if (!isNull _best && { _bestScore < 4 }) then {
        _obj = _best;
    };
};

// Fallback: nearest built object within 5m if raycast found nothing
if (isNull _obj) then {
    private _near = (nearestObjects [player, [], 5]) select {
        !isNull _x && { _x getVariable [QGVAR(builtObject), false] }
    };
    if (count _near > 0) then { _obj = _near select 0; };
};

if (isNull _obj) exitWith {
    hintSilent parseText "<t color='#888888'>No built object in sight</t>";
};

// ── Confirmation ─────────────────────────────────────────────────────────────
private _type    = typeOf _obj;
private _builtBy = _obj getVariable [QGVAR(builtBy), "Unknown"];
private _cost    = _obj getVariable [QGVAR(builtCost), 0];
private _playerSide = side player;

[_obj, _type, _builtBy, _cost, _playerSide] spawn {
    params ["_obj", "_type", "_builtBy", "_cost", "_playerSide"];

    private _refundStr = if (_cost > 0) then {
        format ["<br/><t color='#55CC66'>Refund: +%1 to side pool</t>", _cost]
    } else { "" };

    hint parseText format [
        "<t size='1.1' color='#FF4444'>DELETE?</t><br/><br/>%1<br/>Built by: %2%3<br/><br/><t size='0.9'>Y - Confirm  |  N - Cancel</t>",
        _type, _builtBy, _refundStr
    ];

    GVAR(deleteConfirm) = nil;

    private _keyEH = (findDisplay 46) displayAddEventHandler ["KeyDown", {
        params ["_display", "_key"];
        if (_key == 21) then { GVAR(deleteConfirm) = true;  }; // Y
        if (_key == 49) then { GVAR(deleteConfirm) = false; }; // N
        false
    }];

    waitUntil { !isNil QGVAR(deleteConfirm) || !alive player };
    (findDisplay 46) displayRemoveEventHandler ["KeyDown", _keyEH];

    if (!alive player) exitWith {
        GVAR(deleteConfirm) = nil;
        hint "";
    };

    if (GVAR(deleteConfirm)) then {
        private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
        if (_resourcesEnabled && _cost > 0) then {
            private _currentRes = [_playerSide] call FUNC(getSideResources);
            private _newRes = _currentRes + _cost;
            [_playerSide, _newRes] remoteExec [QFUNC(setSideResources), 2];
            hintSilent parseText format [
                "<t size='1.1' color='#55CC66'>REMOVED</t><br/><t color='#AAAAAA'>%1</t><br/><t color='#55CC66'>Refunded +%2 to side pool</t>",
                _type, _cost
            ];
        } else {
            hintSilent parseText format [
                "<t size='1.1' color='#55CC66'>REMOVED</t><br/><t color='#AAAAAA'>%1</t>",
                _type
            ];
        };

        if (!isNil QGVAR(builtObjects)) then {
            GVAR(builtObjects) = GVAR(builtObjects) - [_obj];
            publicVariable QGVAR(builtObjects);
        };

        if (isMultiplayer) then {
            [_obj] remoteExec ["deleteVehicle", 2];
        } else {
            deleteVehicle _obj;
        };
    } else {
        hintSilent parseText "<t color='#888888'>Cancelled</t>";
    };

    GVAR(deleteConfirm) = nil;
};
