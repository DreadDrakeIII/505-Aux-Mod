#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_demolishMode
 * Activates demolish mode – LMB removes nearby built objects.
 * RMB or Scroll Wheel returns to menu.
 */

if (!isNil QGVAR(buildingObject)) then { [] call FUNC(cancelBuild); };
[] call FUNC(cancelDemolish);

GVAR(demolishActive) = true;

hint parseText "<t size='1.1' color='#FF4444'>DEMOLISH MODE</t><br/><br/><t color='#FFFFFF'>LMB</t><t color='#AAAAAA'> – Delete nearest (within 6m)</t><br/><t color='#FFFFFF'>RMB</t><t color='#AAAAAA'> – Back to menu</t><br/><t color='#FFFFFF'>Scroll</t><t color='#AAAAAA'> – Back to menu</t><br/><br/><t color='#FF8888'>Walk near a placed object and press LMB.</t>";

// Per-frame: highlight nearest built object
GVAR(demolishEH) = addMissionEventHandler ["EachFrame", {
    if (isNil QGVAR(demolishActive)) exitWith {};

    private _near = (nearestObjects [player, [], 6]) select {
        _x getVariable [QGVAR(builtObject), false]
    };

    if (count _near > 0) then {
        private _obj  = _near select 0;
        private _dist = round ((player distance _obj) * 10) / 10;
        hintSilent parseText format [
            "<t size='1.1' color='#FF4444'>DEMOLISH MODE</t><br/><t color='#FF8888'>Target: %1</t><br/><t color='#FFAAAA'>Distance: %2m</t><br/><br/><t color='#FFFFFF'>LMB</t><t color='#AAAAAA'> – Delete  |  <t color='#FFFFFF'>RMB/Scroll</t><t color='#AAAAAA'> – Back to menu</t>",
            typeOf _obj, _dist
        ];
    } else {
        hintSilent parseText "<t size='1.1' color='#FF4444'>DEMOLISH MODE</t><br/><t color='#888888'>No built objects within 6m</t><br/><br/><t color='#FFFFFF'>RMB or Scroll</t><t color='#AAAAAA'> – Back to menu</t>";
    };
}];

// ── MOUSE HANDLER ─────────────────────────────────────────────────────────────
GVAR(demolishMouseEH) = (findDisplay 46) displayAddEventHandler ["MouseButtonDown", {
    params ["_display", "_button", "_xPos", "_yPos", "_shift"];
    if (isNil QGVAR(demolishActive)) exitWith {false};

    // RMB – back to menu
    if (_button == 1) exitWith {
        [] call FUNC(cancelDemolish);
        [] spawn { sleep 0.05; [] call FUNC(openEngineerMenu); };
        true
    };

    // LMB – delete nearest
    if (_button == 0) exitWith {
        private _near = (nearestObjects [player, [], 6]) select {
            _x getVariable [QGVAR(builtObject), false]
        };

        if (count _near == 0) exitWith {
            systemChat "[Engineer] No built objects within 6m";
        };

        private _obj  = _near select 0;
        private _type = typeOf _obj;

        if (!isNil QGVAR(builtObjects)) then {
            GVAR(builtObjects) = GVAR(builtObjects) - [_obj];
            publicVariable QGVAR(builtObjects);
        };

        if (isMultiplayer) then {
            [_obj] remoteExec ["deleteVehicle", 2];
        } else {
            deleteVehicle _obj;
        };

        systemChat format ["[Engineer] Demolished: %1", _type];
        true
    };
    false
}];

// ── SCROLL WHEEL HANDLER – back to menu ──────────────────────────────────────
GVAR(demolishScrollEH) = (findDisplay 46) displayAddEventHandler ["MouseZChanged", {
    if (isNil QGVAR(demolishActive)) exitWith {};
    [] call FUNC(cancelDemolish);
    [] spawn { sleep 0.05; [] call FUNC(openEngineerMenu); };
}];
