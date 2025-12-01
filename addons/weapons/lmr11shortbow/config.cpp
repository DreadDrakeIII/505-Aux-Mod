#include "..\script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;

        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Weapons_DMR",
            "OPTRE_ACE_Compat",
            "OPTRE_JSRS_Sounds"
            };

        units[] = {};
        weapons[] = { QCLASS(LMR11_SHORTBOW) };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
