#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_progressBuild
 * Handles the build progress timer using ACE3 progress bar.
 * Supports auto-level vectors.
 */

params [
    ["_classname", "", [""]],
    ["_pos", [0,0,0], [[]]],
    ["_dir", 0, [0]],
    ["_cost", DEFAULT_RESOURCE_COST, [0]],
    ["_vecDir", [], [[]]],
    ["_vecUp", [], [[]]]
];

if (_classname isEqualTo "") exitWith {};

private _buildTime = missionNamespace getVariable [QGVAR(setting_buildTime), DEFAULT_BUILD_TIME];
if (_buildTime <= 0) then { _buildTime = DEFAULT_BUILD_TIME; };

// ── Ghost marker at build site ──────────────────────────────────────────────
private _ghost = _classname createVehicleLocal [0,0,0];
_ghost setPosASL _pos;
if (count _vecDir == 3 && count _vecUp == 3) then {
    _ghost setVectorDirAndUp [_vecDir, _vecUp];
} else {
    _ghost setVectorDirAndUp [[sin _dir, cos _dir, 0], [0, 0, 1]];
};
_ghost setPosASL _pos;
_ghost allowDamage false;
_ghost enableSimulation false;

// ── ACE Progress Bar ────────────────────────────────────────────────────────
[
    _buildTime,
    [_classname, _pos, _dir, _cost, _ghost, _vecDir, _vecUp],

    // ── ON SUCCESS ──────────────────────────────────────────────────────────
    {
        params ["_args"];
        _args params ["_classname", "_pos", "_dir", "_cost", "_ghost", "_vecDir", "_vecUp"];

        deleteVehicle _ghost;

        private _resourcesEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];
        if (_resourcesEnabled) then {
            private _currentRes = player getVariable [QGVAR(resources), 0];
            if (_currentRes < _cost) exitWith {
                systemChat "[Engineer] Not enough resources!";
            };
            player setVariable [QGVAR(resources), _currentRes - _cost, true];
        };

        if (isMultiplayer) then {
            [_classname, _pos, _dir, _vecDir, _vecUp] remoteExec [QFUNC(createBuiltObject), 2];
        } else {
            [_classname, _pos, _dir, _vecDir, _vecUp] call FUNC(createBuiltObject);
        };

        private _newRes = player getVariable [QGVAR(resources), 0];
        private _resEnabled = missionNamespace getVariable [QGVAR(setting_enableResources), true];

        if (_resEnabled) then {
            systemChat format ["[Engineer] Built! -%1 resources (Remaining: %2)", _cost, _newRes];
        } else {
            systemChat "[Engineer] Built!";
        };

        [_classname] spawn {
            params ["_c"];
            sleep 0.15;
            [_c] call FUNC(buildObject);
        };
    },

    // ── ON FAILURE / CANCEL ─────────────────────────────────────────────────
    {
        params ["_args"];
        _args params ["_classname", "_pos", "_dir", "_cost", "_ghost"];

        deleteVehicle _ghost;
        systemChat "[Engineer] Build cancelled.";
    },

    format ["Building %1...", _classname],

    {
        params ["_args"];
        _args params ["_classname", "_pos"];
        player distance (ASLToAGL _pos) < 15
    },

    ["isNotInside", "isNotSwimming"]

] call ace_common_fnc_progressBar;
