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
            QGVAR(condor),
            QGVAR(harpoon),
            QGVAR(sparrow),
            QGVAR(warhawk),
            QGVAR(widow_armed),
            QGVAR(widow_infantry),
            // Land
            QGVAR(puma)
        };
        units[] = {};
        weapons[] = {};
    };
};