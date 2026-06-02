#include "..\script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;

        requiredAddons[] = {
            QUOTE(ADDON),
            "TCP_Weapons_LongRangeRifles_SRS99",
            "TCP_Compat_ACE_Weapons_Rifles_SRS99",
            "TCP_Weapons_Ammo_127x99_APFSDS",
            "jsrs2025_config_c"
            };

        units[] = {};
        weapons[] = { QCLASS(M98_HARVESTER) };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinesWells.hpp"
