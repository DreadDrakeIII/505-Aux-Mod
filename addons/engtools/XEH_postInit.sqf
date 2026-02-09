#include "script_component.hpp"

if (!hasInterface) exitWith {};

// Initialize engineer menu for local player (spawned for MP compatibility)
[] spawn {
    [] call FUNC(initEngineerMenu);
};
