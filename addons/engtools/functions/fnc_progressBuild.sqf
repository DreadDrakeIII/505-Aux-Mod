#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_progressBuild
 * ACE3 progress bar with kneeling build animation.
 * Uses shared side resource pool.
 *
 * v13 fixes:
 * - Ghost stays visible at build site until real server object arrives
 * - nearestObjects radius 8m (3m was too small for server position variance)
 * - disableCollisionWith player on ghost
 * - Passes _builtBy to createBuiltObject
 * - Repeat build on success
 */

params [
    ["_classname", "", [""]],
    ["_pos", [0,0,0], [[]]],
    ["_cost", DEFAULT_RESOURCE_COST, [0]],
    ["_vecDir", [], [[]]],
    ["_vecUp", [], [[]]],
    ["_builtBy", "", [""]]
];

if (_classname isEqualTo "") exitWith {};

private _buildTime = missionNamespace getVariable [QGVAR(setting_buildTime), DEFAULT_BUILD_TIME];
if (_buildTime <= 0) then { _buildTime = DEFAULT_BUILD_TIME; };

// Ghost marker at build site — stays visible during progress bar
private _ghost = _classname createVehicleLocal [0,0,0];
_ghost allowDamage false;
_ghost enableSimulation false;
_ghost disableCollisionWith player;
_ghost setPosASL _pos;
_ghost setVectorDirAndUp [
    if (count _vecDir == 3) then { _vecDir } else { [0, 1, 0] },
    if (count _vecUp == 3)  then { _vecUp }  else { [0, 0, 1] }
];
_ghost setPosASL _pos;
_ghost setObjectTexture [0, "#(argb,8,8,3)color(0.2,0.8,0.3,0.6)"];

private _playerSide = side player;

[
    _buildTime,
    [_classname, _pos, _cost, _ghost, _vecDir, _vecUp, _playerSide, _builtBy],

    // ON SUCCESS
    {
        params ["_args"];
        _args params ["_classname", "_pos", "_cost", "_ghost", "_vecDir", "_vecUp", "_playerSide", "_builtBy"];

        private _canAfford = true;
        private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
        if (_resourcesEnabled) then {
            private _currentRes = [_playerSide] call FUNC(getSideResources);
            if (_currentRes < _cost) then {
                _canAfford = false;
            } else {
                [_playerSide, _currentRes - _cost] remoteExec [QFUNC(setSideResources), 2];
            };
        };

        if (!_canAfford) exitWith {
            if (!isNull _ghost) then { deleteVehicle _ghost; };
            [player, "", 1] call ace_common_fnc_doAnimation;
            private _currentRes = [_playerSide] call FUNC(getSideResources);
            hint parseText format [
                "<t size='1.1' color='#FF4444'>INSUFFICIENT RESOURCES</t><br/><br/>" +
                "<t color='#FFFFFF'>Cost: %1</t>  |  <t color='#FF6666'>Side Pool: %2</t>",
                _cost, _currentRes
            ];
        };

        // Keep ghost until real object appears nearby (8m radius), max 8s
        [_ghost, _pos] spawn {
            params ["_ghost", "_pos"];
            private _deadline = diag_tickTime + 8;
            waitUntil {
                sleep 0.05;
                private _finalSeen = false;
                {
                    if (_x getVariable [QGVAR(builtObject), false]) exitWith { _finalSeen = true; };
                } forEach (nearestObjects [ASLToAGL _pos, [], 8]);
                isNull _ghost || _finalSeen || (diag_tickTime > _deadline)
            };
            if (!isNull _ghost) then { deleteVehicle _ghost; };
        };

        if (isMultiplayer) then {
            [_classname, _pos, 0, _vecDir, _vecUp, _builtBy] remoteExec [QFUNC(createBuiltObject), 2];
        } else {
            [_classname, _pos, 0, _vecDir, _vecUp, _builtBy] call FUNC(createBuiltObject);
        };

        [player, "", 1] call ace_common_fnc_doAnimation;

        private _newRes = [_playerSide] call FUNC(getSideResources);
        private _resEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];

        if (_resEnabled) then {
            hint parseText format [
                "<t size='1.1' color='#55CC66'>BUILT</t><br/><br/>" +
                "<t color='#FFFFFF'>%1</t><br/>" +
                "<t color='#FFA500'>Cost: -%2</t>  |  <t color='#55CC66'>Side Pool: ~%3</t>",
                _classname, _cost, _newRes
            ];
        } else {
            hint parseText format [
                "<t size='1.1' color='#55CC66'>BUILT</t><br/><br/><t color='#FFFFFF'>%1</t>",
                _classname
            ];
        };

        // Repeat build
        private _repeatCls = _classname;
        [_repeatCls] spawn {
            params ["_c"];
            sleep 0.15;
            [_c] call FUNC(buildObject);
        };
    },

    // ON CANCEL
    {
        params ["_args"];
        _args params ["_classname", "_pos", "_cost", "_ghost"];
        if (!isNull _ghost) then { deleteVehicle _ghost; };
        [player, "", 1] call ace_common_fnc_doAnimation;
        hint parseText "<t size='1.0' color='#FF8844'>BUILD CANCELLED</t>";
    },

    format ["Building %1...", _classname],

    // Per-frame check
    {
        params ["_args", "_elapsedTime", "_totalTime", "_errorCode"];
        _args params ["_classname", "_pos"];
        if (_totalTime != 0 && {animationState player != "AinvPknlMstpSnonWnonDnon_medic4"}) then {
            [player, "AinvPknlMstpSnonWnonDnon_medic4"] call ace_common_fnc_doAnimation;
        };
        player distance (ASLToAGL _pos) < 15
    },

    ["isNotInside", "isNotSwimming"]

] call ace_common_fnc_progressBar;
