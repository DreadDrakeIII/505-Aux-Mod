#include "script_component.hpp"

if (!hasInterface) exitWith {};

// Initialize engineer menu for local player (spawned for MP compatibility)
[] spawn {
    [] call FUNC(initEngineerMenu);
};

// Initialize resource system
[] spawn {
    [] call FUNC(initResources);
};

// Preload all buildable model LODs so the first placement of any object
// isn't affected by cold-cache bounding-box drift. Delayed 3s so it
// doesn't fight with other mission-start work for CPU.
[] spawn {
    sleep 3;
    [] call FUNC(preloadModels);
};
