#include "..\script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;

        requiredAddons[] = {
            QUOTE(ADDON),
            "TCP_Compat_OPTRE_Weapons_LongRangeRifles_M392",
            "TCP_Weapons_LongRangeRifles_M392",
            "TCP_Compat_ACE_Weapons_Rifles_M392",
            "jsrs2025_config_c"
            };

        units[] = {};
        weapons[] = { QCLASS(LMR11_SHORTBOW) };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinesWells.hpp"
