#include "..\script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;

        requiredAddons[] = {
            QUOTE(ADDON),
            "A3_Weapons_F_SMGs_Pdw2000",
            "jsrs2025_config_c",
            "ace_realisticnames",
            "ace_ballistics"
            };
        units[] = {};
        weapons[] = {
            QCLASS(CPW)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinesWells.hpp"
