#include "..\script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;

        requiredAddons[] = {
            QUOTE(ADDON),
            "WBK_SciFiWeaponary",
            "OPTRE_JSRS_Sounds",
            "OPTRE_ACE_Compat"
            };
        units[] = {};
        weapons[] = {
            QCLASS(PUMA)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinesWells.hpp"
