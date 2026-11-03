#include "script_component.hpp"

PREP_RECOMPILE_START;
PREP_RECOMPILE_END;

["CAManBase", "init", {
    params ["_unit"];
    if ((typeOf _unit) select [0, 4] == "OLI_") then {
        _unit setSpeaker "NoVoice";
    };
}, true, [], true] call CBA_fnc_addClassEventHandler;

ADDON = true;
