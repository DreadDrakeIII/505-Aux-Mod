#include "..\script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;

        requiredAddons[] = {
            QUOTE(ADDON),
            "TCP_Weapons_Machineguns_M731",
            "TCP_Compat_ACE_Weapons_Machineguns_M731",
            "jsrs2025_config_c"
            };
        units[] = {};
        weapons[] = {
            QCLASS(M73)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinesWells.hpp"
