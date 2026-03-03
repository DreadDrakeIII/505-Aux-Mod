#include "..\script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;

        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Weapons_AR",
            "jsrs2025_config_c"
            };

        units[] = {};
        weapons[] = { QCLASS(MA5CGL) };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
