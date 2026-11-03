#include "..\script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;

        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Weapons_SMG",
            "OPTRE_ACE_Compat",
            "TCP_Compat_OPTRE_Weapons_SMGs_M7",
            "TCP_Weapons_SMGs_M7",
            "TCP_Compat_ACE_Weapons_SMGs_M7",
            "TCP_Weapons_Ammo_5x23_Ball",           // TCP_60Rnd_5x23_Mag
            "jsrs2025_config_c"
            };
        units[] = {};
        weapons[] = {
            QCLASS(M7_Caseless)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinesWells.hpp"
