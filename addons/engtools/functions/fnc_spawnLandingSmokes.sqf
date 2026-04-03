#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_spawnLandingSmoke
 * Creates an orange smoke particle effect at a position.
 * Runs locally on each client (remoteExec'd from server).
 * Smoke lasts ~45 seconds then cleans up.
 */

params [["_pos", [0, 0, 0], [[]]]];

if (_pos isEqualTo [0, 0, 0]) exitWith {};

// Orange smoke particle source
private _smoke = "#particlesource" createVehicleLocal _pos;
_smoke setParticleParams [
    ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 7, 48],
    "", "Billboard", 1, 8,
    [0, 0, 0.5],       // position offset
    [0, 0, 1.5],       // velocity
    1, 1.2, 1, 0.1,
    [2, 4, 8],          // size over time
    [
        [1.0, 0.5, 0.0, 0.6],   // orange start
        [1.0, 0.6, 0.1, 0.4],   // orange mid
        [0.8, 0.4, 0.0, 0.1],   // fade
        [0.6, 0.3, 0.0, 0.0]    // gone
    ],
    [0.5, 1], 1, 0, "", "", _smoke
];
_smoke setParticleRandom [0.5, [1, 1, 0.3], [0.5, 0.5, 0.3], 0, 0.3, [0, 0, 0, 0], 0, 0];
_smoke setDropInterval 0.08;

// Auto-cleanup after 45 seconds
[{
    params ["_smoke"];
    if (!isNull _smoke) then { deleteVehicle _smoke };
}, [_smoke], 45] call CBA_fnc_waitAndExecute;
