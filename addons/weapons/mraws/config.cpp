#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;

        requiredAddons[] = {
            QUOTE(ADDON),
            "A3_Weapons_F_Tank",
            "A3_Weapons_F_Tank_Launchers_MRAWS"
        };
        units[] = {};
        weapons[] = {
            QCLASS(M20_Lawbringer),
            QCLASS(M20_Lawbringer_LAT)
        };
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
