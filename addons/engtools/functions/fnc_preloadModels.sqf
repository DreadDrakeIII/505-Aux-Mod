#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_preloadModels
 *
 * Warms the geometry LOD cache for every buildable class at mission start.
 *
 * THE BUG THIS FIXES:
 *   The first time a player builds a particular object, it can drift up
 *   to several metres from where the ghost was — but the second time in
 *   the same spot, it places correctly. The root cause is a combination
 *   of cold-cache LOD streaming and early bounding-box reads: when
 *   createVehicleLocal is called on an unseen class, the engine may
 *   return a proxy bounding box (too large / offset) for the first few
 *   frames while it's still loading the real geometry. The ghost preview
 *   math uses boundingBoxReal to compute placement offsets, so a proxy
 *   box gives a wrong ghost position, which is then faithfully applied
 *   to the real object by createBuiltObject.
 *
 * THE FIX:
 *   On mission start (once), spawn each buildable class far underground,
 *   read its boundingBoxReal (forces a geometry load), wait a frame for
 *   LOD to upgrade, read it again, then delete. After this, the engine's
 *   LOD cache is warm and subsequent createVehicleLocal returns an
 *   already-loaded model with a correct bounding box.
 *
 * COST:
 *   18 classes, ~50ms spread over ~1.5s. Runs in a spawned thread during
 *   mission load so players don't see a hitch. Each object is created
 *   one at a time with a sleep between to avoid hammering the CPU.
 *
 * IDEMPOTENT:
 *   Uses a mission-namespace flag so it only runs once per mission.
 *   Calling twice is a no-op.
 */

// Guard — one preload per mission
if (!isNil QGVAR(preloadDone)) exitWith {};
GVAR(preloadDone) = true;

if (!hasInterface) exitWith {};  // only clients need this

[] spawn {
    // Sentinel position: 10km east, 100m below ground. Far from any map
    // play area, far below any map that might have underground interiors.
    // Absolute worst case: a player sees a wall flicker 10km away for
    // one frame. Acceptable.
    private _sentinel = [worldSize + 10000, 5000, -100];

    private _classes = ["All"] call FUNC(getBuildableClasses);
    private _count = count _classes;
    diag_log format ["[OLI_engtools] preloadModels: warming %1 classes", _count];

    private _warmed = 0;
    private _failed = [];

    {
        _x params ["_cls"];

        // Create, read bounding box (forces LOD evaluation), wait one
        // tick for LOD upgrade, read again, delete. The double-read is
        // the key — first read triggers LOD request, second confirms
        // the real geometry is resident.
        private _obj = _cls createVehicleLocal _sentinel;

        if (!isNull _obj) then {
            _obj enableSimulation false;
            _obj allowDamage false;
            _obj hideObject true;

            // First bounding-box read — triggers LOD request if cold
            private _bb1 = boundingBoxReal _obj;

            // Yield one frame so the engine can process the load
            uiSleep 0.05;

            // Second read — the one we actually "cache" by using
            private _bb2 = boundingBoxReal _obj;

            deleteVehicle _obj;
            _warmed = _warmed + 1;
        } else {
            _failed pushBack _cls;
        };

        // Spread load across frames — ~50ms per class = ~1s total
        uiSleep 0.05;
    } forEach _classes;

    diag_log format [
        "[OLI_engtools] preloadModels: complete (%1/%2 warmed)%3",
        _warmed, _count,
        if (count _failed > 0) then { format [", FAILED: %1", _failed] } else { "" }
    ];
};
