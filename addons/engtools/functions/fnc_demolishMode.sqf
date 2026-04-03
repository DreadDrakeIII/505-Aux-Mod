#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_demolishMode
 * Demolish mode — uses shared side resource pool for refunds.
 */

if (!isNil QGVAR(buildingObject)) then { [] call FUNC(cancelBuild); };
[] call FUNC(cancelDemolish);

GVAR(demolishActive) = true;

hint parseText "<t size='1.1' color='#FF4444'>DEMOLISH MODE</t><br/><br/><t color='#FFFFFF'>LMB</t><t color='#AAAAAA'> – Delete nearest (within 6m)</t><br/><t color='#FFFFFF'>RMB</t><t color='#AAAAAA'> – Back to menu</t><br/><t color='#FFFFFF'>Scroll</t><t color='#AAAAAA'> – Back to menu</t><br/><br/><t color='#FF8888'>Walk near a placed object and press LMB.</t>";

// Per-frame highlight
GVAR(demolishEH) = addMissionEventHandler ["EachFrame", {
    if (isNil QGVAR(demolishActive)) exitWith {};

    private _near = (nearestObjects [player, [], 6]) select {
        _x getVariable [QGVAR(builtObject), false]
    };

    if (count _near > 0) then {
        private _obj  = _near select 0;
        private _dist = round ((player distance _obj) * 10) / 10;
        private _cost = _obj getVariable [QGVAR(builtCost), 0];
        private _refundStr = if (_cost > 0) then {
            format ["<br/><t color='#55CC66'>Refund: +%1 to side pool</t>", _cost]
        } else { "" };
        hintSilent parseText format [
            "<t size='1.1' color='#FF4444'>DEMOLISH MODE</t><br/><t color='#FF8888'>Target: %1</t><br/><t color='#FFAAAA'>Distance: %2m</t>%3<br/><br/><t color='#FFFFFF'>LMB</t><t color='#AAAAAA'> – Delete  |  <t color='#FFFFFF'>RMB/Scroll</t><t color='#AAAAAA'> – Back to menu</t>",
            typeOf _obj, _dist, _refundStr
        ];
    } else {
        hintSilent parseText "<t size='1.1' color='#FF4444'>DEMOLISH MODE</t><br/><t color='#888888'>No built objects within 6m</t><br/><br/><t color='#FFFFFF'>RMB or Scroll</t><t color='#AAAAAA'> – Back to menu</t>";
    };
}];

// ── MOUSE HANDLER ─────────────────────────────────────────────────────────────
GVAR(demolishMouseEH) = (findDisplay 46) displayAddEventHandler ["MouseButtonDown", {
    params ["_display", "_button", "_xPos", "_yPos", "_shift"];
    if (isNil QGVAR(demolishActive)) exitWith {false};

    if (_button == 1) exitWith {
        [] call FUNC(cancelDemolish);
        [] spawn { sleep 0.05; [] call FUNC(openEngineerMenu); };
        true
    };

    if (_button == 0) exitWith {
        private _near = (nearestObjects [player, [], 6]) select {
            _x getVariable [QGVAR(builtObject), false]
        };

        if (count _near == 0) exitWith {
            hintSilent parseText "<t size='1.1' color='#FF4444'>DEMOLISH MODE</t><br/><t color='#888888'>No built objects within 6m</t>";
        };

        private _obj  = _near select 0;
        private _type = typeOf _obj;
        private _cost = _obj getVariable [QGVAR(builtCost), 0];
        private _playerSide = side player;
        private _demolishTime = missionNamespace getVariable [QGVAR(setting_demolishTime), DEFAULT_DEMOLISH_TIME];

        if (_demolishTime <= 0) then {
            private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
            if (_resourcesEnabled && _cost > 0) then {
                private _currentRes = [_playerSide] call FUNC(getSideResources);
                private _newRes = _currentRes + _cost;
                [_playerSide, _newRes] remoteExec [QFUNC(setSideResources), 2];
                hintSilent parseText format [
                    "<t size='1.1' color='#55CC66'>DEMOLISHED</t><br/><t color='#AAAAAA'>%1</t><br/><t color='#55CC66'>Refunded +%2 to side pool</t><br/><t color='#FFAA00'>Pool: ~%3</t>",
                    _type, _cost, _newRes
                ];
            } else {
                hintSilent parseText format [
                    "<t size='1.1' color='#55CC66'>DEMOLISHED</t><br/><t color='#AAAAAA'>%1</t>",
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
            if (!isNil QGVAR(demolishEH)) then {
                removeMissionEventHandler ["EachFrame", GVAR(demolishEH)];
                GVAR(demolishEH) = nil;
            };

            [
                _demolishTime,
                [_obj, _type, _cost, _playerSide],

                // ON SUCCESS
                {
                    params ["_args"];
                    _args params ["_obj", "_type", "_cost", "_playerSide"];

                    if (isNull _obj) exitWith {
                        hintSilent parseText "<t color='#888888'>Object already removed.</t>";
                    };

                    private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
                    if (_resourcesEnabled && _cost > 0) then {
                        private _currentRes = [_playerSide] call FUNC(getSideResources);
                        private _newRes = _currentRes + _cost;
                        [_playerSide, _newRes] remoteExec [QFUNC(setSideResources), 2];
                        hintSilent parseText format [
                            "<t size='1.1' color='#55CC66'>DEMOLISHED</t><br/><t color='#AAAAAA'>%1</t><br/><t color='#55CC66'>Refunded +%2 to side pool</t><br/><t color='#FFAA00'>Pool: ~%3</t>",
                            _type, _cost, _newRes
                        ];
                    } else {
                        hintSilent parseText format [
                            "<t size='1.1' color='#55CC66'>DEMOLISHED</t><br/><t color='#AAAAAA'>%1</t>",
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

                    [player, "", 1] call ace_common_fnc_doAnimation;
                    [] spawn { sleep 0.15; [] call FUNC(demolishMode); };
                },

                // ON CANCEL
                {
                    [player, "", 1] call ace_common_fnc_doAnimation;
                    hintSilent parseText "<t color='#888888'>Demolish cancelled.</t>";
                    [] spawn { sleep 0.15; [] call FUNC(demolishMode); };
                },

                format ["Demolishing %1...", _type],

                // Per-frame
                {
                    params ["_args", "_elapsedTime", "_totalTime", "_errorCode"];
                    _args params ["_obj"];
                    if (isNull _obj) exitWith { false };
                    if (_totalTime != 0 && {animationState player != "AinvPknlMstpSnonWnonDnon_medic4"}) then {
                        [player, "AinvPknlMstpSnonWnonDnon_medic4"] call ace_common_fnc_doAnimation;
                    };
                    player distance _obj < 8
                },

                ["isNotInside", "isNotSwimming"]

            ] call ace_common_fnc_progressBar;
        };

        true
    };
    false
}];

// ── SCROLL WHEEL ─────────────────────────────────────────────────────────────
GVAR(demolishScrollEH) = (findDisplay 46) displayAddEventHandler ["MouseZChanged", {
    if (isNil QGVAR(demolishActive)) exitWith {};
    [] call FUNC(cancelDemolish);
    [] spawn { sleep 0.05; [] call FUNC(openEngineerMenu); };
}];
