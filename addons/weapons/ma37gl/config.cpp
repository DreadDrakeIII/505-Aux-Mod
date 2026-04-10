#include "..\script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;

        requiredAddons[] = {
            QUOTE(ADDON),
            "TCP_Compat_OPTRE_Weapons_Rifles_MA37",
            "TCP_Weapons_Rifles_MA37",
            "TCP_Compat_ACE_Weapons_Rifles_MA37",
            "jsrs2025_config_c"
            };
        units[] = {};
        weapons[] = {
            QCLASS(MA37GL)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
