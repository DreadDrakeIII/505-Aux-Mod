#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            // Air
            QGVAR(buzzard),
            QGVAR(condor),
            QGVAR(falcon),
            QGVAR(harpoon),
            QGVAR(nightingale),
            QGVAR(sparrow),
            QGVAR(vulture),
            QGVAR(warhawk),
            QGVAR(wasp),
            QGVAR(widow),
            QGVAR(wyvern),
            // Land
            QGVAR(puma),
            QGVAR(rex),
            QGVAR(scorpion),
            QGVAR(sundevil),
            QGVAR(warthog),
        };
        units[] = {};
        weapons[] = {};
    };
};