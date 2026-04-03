#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_deleteNearestBuilt
 * Deletes nearest engineer-built object (Shift+RMB in build mode).
 * Refunds to the side pool. Fixes lingering key EH on death.
 */

private _nearObjects = nearestObjects [player, [], 10];
_nearObjects = _nearObjects select {_x getVariable [QGVAR(builtObject), false]};

if (count _nearObjects == 0) exitWith {
    hintSilent parseText "<t color='#888888'>No built objects nearby</t>";
};

private _obj     = _nearObjects select 0;
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
        "<t size='1.1' color='#FF4444'>DELETE?</t><br/><br/>%1<br/>Built by: %2%3<br/><br/><t size='0.9'>Y - Confirm | N - Cancel</t>",
        _type, _builtBy, _refundStr
    ];

    GVAR(deleteConfirm) = nil;

    private _keyEH = (findDisplay 46) displayAddEventHandler ["KeyDown", {
        params ["_display", "_key"];
        if (_key == 21) then { GVAR(deleteConfirm) = true;  };
        if (_key == 49) then { GVAR(deleteConfirm) = false; };
        false
    }];

    // Wait for Y/N or player death — clean up EH either way
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
                "<t size='1.1' color='#55CC66'>REMOVED</t><br/><t color='#AAAAAA'>%1</t><br/><t color='#55CC66'>Refunded +%2 to side pool</t><br/><t color='#FFAA00'>Pool: ~%3</t>",
                _type, _cost, _newRes
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

        deleteVehicle _obj;
    } else {
        hintSilent parseText "<t color='#888888'>Cancelled</t>";
    };

    GVAR(deleteConfirm) = nil;
};
