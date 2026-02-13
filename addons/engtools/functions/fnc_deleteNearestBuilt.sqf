#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_deleteNearestBuilt
 * Deletes nearest engineer-built object (Shift+RMB in build mode).
 * Full refund on confirm.
 */

private _nearObjects = nearestObjects [player, [], 10];
_nearObjects = _nearObjects select {_x getVariable [QGVAR(builtObject), false]};

if (count _nearObjects == 0) exitWith {
    systemChat "[Engineer] No built objects nearby";
};

private _obj = _nearObjects select 0;
private _type = typeOf _obj;
private _builtBy = _obj getVariable [QGVAR(builtBy), "Unknown"];
private _cost = _obj getVariable [QGVAR(builtCost), 0];

[_obj, _type, _builtBy, _cost] spawn {
    params ["_obj", "_type", "_builtBy", "_cost"];

    private _refundStr = if (_cost > 0) then {
        format ["<br/><t color='#55CC66'>Refund: +%1 resources</t>", _cost]
    } else { "" };

    hint parseText format [
        "<t size='1.1' color='#FF4444'>DELETE?</t><br/><br/>%1<br/>Built by: %2%3<br/><br/><t size='0.9'>Y - Confirm | N - Cancel</t>",
        _type, _builtBy, _refundStr
    ];

    GVAR(deleteConfirm) = nil;

    private _keyEH = (findDisplay 46) displayAddEventHandler ["KeyDown", {
        params ["_display", "_key"];
        if (_key == 21) then {GVAR(deleteConfirm) = true};
        if (_key == 49) then {GVAR(deleteConfirm) = false};
        false
    }];

    waitUntil {!isNil QGVAR(deleteConfirm) || !alive player};
    (findDisplay 46) displayRemoveEventHandler ["KeyDown", _keyEH];

    if (GVAR(deleteConfirm)) then {
        // ── Refund resources ────────────────────────────────────────────────
        private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
        if (_resourcesEnabled && _cost > 0) then {
            private _currentRes = player getVariable [QGVAR(resources), 0];
            player setVariable [QGVAR(resources), _currentRes + _cost, true];
            systemChat format ["[Engineer] %1 removed  |  Refunded +%2 resources", _type, _cost];
        } else {
            systemChat format ["[Engineer] %1 removed", _type];
        };

        if (!isNil QGVAR(builtObjects)) then {
            GVAR(builtObjects) = GVAR(builtObjects) - [_obj];
            publicVariable QGVAR(builtObjects);
        };

        deleteVehicle _obj;
    } else {
        systemChat "[Engineer] Cancelled";
    };

    hint "";
    GVAR(deleteConfirm) = nil;
};
