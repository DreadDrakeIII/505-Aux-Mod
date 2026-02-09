#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_buildObject
 * Places fortification with ghost preview
 * Can place anywhere within 15m range
 */

params [["_classname", "", [""]]];

if (_classname isEqualTo "") exitWith {
    systemChat "[Engineer] ERROR: No object specified";
};

if !("OLI_Combat_Engineer_Toolkit" in items player) exitWith {
    hint "Requires 505th Combat Engineer Toolkit";
};

// Cancel existing
if (!isNil QGVAR(buildingObject)) then {
    [] call FUNC(cancelBuild);
};

// Create preview
private _previewObj = _classname createVehicleLocal [0,0,0];
_previewObj enableSimulation false;

GVAR(buildingObject) = _previewObj;
GVAR(buildClassname) = _classname;
GVAR(buildRotation) = 0;
GVAR(canPlaceObject) = true;

hint parseText "<t size='1.2' color='#FFA500'>BUILDING MODE</t><br/><br/><t color='#FFFFFF'>LMB - Place</t><br/><t color='#FFFFFF'>Q/E - Rotate</t><br/><t color='#FFFFFF'>Shift+RMB - Delete</t><br/><t color='#FFFFFF'>ESC - Cancel</t>";

// Position update each frame
GVAR(buildEH) = addMissionEventHandler ["EachFrame", {
    if (isNil QGVAR(buildingObject)) exitWith {};
    if (isNull GVAR(buildingObject)) exitWith {};
    
    private _pos = screenToWorld [0.5, 0.5];
    _pos = ATLToASL [_pos select 0, _pos select 1, 0];
    
    // Double-set approach: Set position before AND after rotation
    // This forces the object to stay at the target position regardless of model origin
    GVAR(buildingObject) setPosASL _pos;
    GVAR(buildingObject) setDir GVAR(buildRotation);
    GVAR(buildingObject) setPosASL _pos;
    
    // Only check distance - can place anywhere within 15m
    GVAR(canPlaceObject) = (player distance GVAR(buildingObject) < 15);
}];

// Key handler
GVAR(buildKeyEH) = (findDisplay 46) displayAddEventHandler ["KeyDown", {
    params ["_display", "_key"];
    if (isNil QGVAR(buildingObject)) exitWith {false};
    
    switch (_key) do {
        case 16: {GVAR(buildRotation) = GVAR(buildRotation) - 15; true};
        case 18: {GVAR(buildRotation) = GVAR(buildRotation) + 15; true};
        case 1: {[] call FUNC(cancelBuild); true};
        default {false};
    }
}];

// Mouse click handler
GVAR(buildMouseEH) = (findDisplay 46) displayAddEventHandler ["MouseButtonDown", {
    params ["_display", "_button", "_x", "_y", "_shift"];
    
    // Shift + RMB = Quick delete nearest object
    if (_button == 1 && _shift) exitWith {
        private _nearObjects = nearestObjects [player, [], 10];
        _nearObjects = _nearObjects select {_x getVariable [QGVAR(builtObject), false]};
        
        if (count _nearObjects == 0) exitWith {
            systemChat "[Engineer] No built objects nearby";
        };
        
        private _obj = _nearObjects select 0;
        private _type = typeOf _obj;
        
        if (!isNil QGVAR(builtObjects)) then {
            GVAR(builtObjects) = GVAR(builtObjects) - [_obj];
            publicVariable QGVAR(builtObjects);
        };
        
        deleteVehicle _obj;
        systemChat format ["[Engineer] %1 removed", _type];
        true
    };
    
    // LMB = Place object
    if (_button == 0 && !isNil QGVAR(buildingObject)) then {
        if !(GVAR(canPlaceObject)) exitWith {
            systemChat "[Engineer] Too far - must be within 15m";
        };
        
        private _finalPos = getPosASL GVAR(buildingObject);
        private _finalDir = getDir GVAR(buildingObject);
        private _classname = GVAR(buildClassname);
        
        [] call FUNC(cancelBuild);
        
        if (isMultiplayer) then {
            [_classname, _finalPos, _finalDir] remoteExec [QFUNC(createBuiltObject), 2];
        } else {
            [_classname, _finalPos, _finalDir] call FUNC(createBuiltObject);
        };
        
        systemChat format ["[Engineer] %1 placed", _classname];
        
        // Auto-reopen menu after placement
        [] spawn {
            sleep 0.1;
            [] call FUNC(openEngineerMenu);
        };
    };
}];
