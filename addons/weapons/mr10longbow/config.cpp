#include "..\script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;

        requiredAddons[] = {
            QUOTE(ADDON),
            "A3_Weapons_F_Mark_LongRangeRifles_DMR_02",
            "cba_jr",
            "ace_realisticweights",
            "1st_MEU_patch_weapons_meu_rework_longguns",
            "jsrs2025_config_c"
            };

        units[] = {};
        weapons[] = { QCLASS(MR10_LONGBOW) };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazinesWells.hpp"
