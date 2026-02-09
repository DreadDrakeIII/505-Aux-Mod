#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_deleteNearestBuilt
 * Deletes nearest engineer-built object
 */

private _nearObjects = nearestObjects [player, [], 10];
_nearObjects = _nearObjects select {_x getVariable [QGVAR(builtObject), false]};

if (count _nearObjects == 0) exitWith {
    systemChat "[Engineer] No built objects nearby";
};

private _obj = _nearObjects select 0;
private _type = typeOf _obj;
private _builtBy = _obj getVariable [QGVAR(builtBy), "Unknown"];

[_obj, _type, _builtBy] spawn {
    params ["_obj", "_type", "_builtBy"];
    
    hint parseText format [
        "<t size='1.1' color='#FF4444'>DELETE?</t><br/><br/>%1<br/>Built by: %2<br/><br/><t size='0.9'>Y - Confirm | N - Cancel</t>",
        _type, _builtBy
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
        if (!isNil QGVAR(builtObjects)) then {
            GVAR(builtObjects) = GVAR(builtObjects) - [_obj];
            publicVariable QGVAR(builtObjects);
        };
        
        // Removed smoke effect
        deleteVehicle _obj;
        systemChat format ["[Engineer] %1 removed", _type];
    } else {
        systemChat "[Engineer] Cancelled";
    };
    
    hint "";
    GVAR(deleteConfirm) = nil;
};
