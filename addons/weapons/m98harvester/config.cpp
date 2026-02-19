#include "..\script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;

        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Weapons_Sniper",
            "OPTRE_ACE_Compat",
            "jsrs2025_config_c",
            "OPTRE_Weapons_Ammo"
            };

        units[] = {};
        weapons[] = { QCLASS(M98_HARVESTER) };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinesWells.hpp"
