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
            QGVAR(c5),
            QGVAR(c130),
            QGVAR(condor),
            QGVAR(f16),
            QGVAR(falcon),
            QGVAR(ghosthawk),
            QGVAR(harpoon),
            QGVAR(harrier),
            QGVAR(hornet),
            QGVAR(nightingale),
            QGVAR(pelican),
            QGVAR(sparrow),
            QGVAR(sparrowhawk),
            QGVAR(vulture),
            QGVAR(warhawk),
            QGVAR(wasp),
            QGVAR(widow),
            QGVAR(wyvern),
            // Land
            QGVAR(apex),
            QGVAR(bison),
            QGVAR(oryx),
            QGVAR(puma),
            QGVAR(rex),
            QGVAR(scorpion),
            QGVAR(stallion),
            QGVAR(sundevil),
            QGVAR(warthog),
        };
        units[] = {};
        weapons[] = {};
    };
};
