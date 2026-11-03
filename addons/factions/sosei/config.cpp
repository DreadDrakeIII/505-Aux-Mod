#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            QCLASS(weapons),
            QCLASS(gears),
            QCLASS(weapons_mraws),
            "TKE_SpecOps",          // CSTR helmet / armour / undersuit
            "TKE_General_Gear",     // CSTR rucksack
            "TKE_Wheeled_C"         // Paladin APC family
        };
        units[] = {
            QCLASS(SOSE_Unit_Base),
            QCLASS(SOSE_Rifleman),
            QCLASS(SOSE_LAT),
            QCLASS(SOSE_AA),
            QCLASS(SOSE_LMG),
            QCLASS(SOSE_Officer),
            QCLASS(SOSE_Rucksack),
            QCLASS(SOSE_Rifleman_Predef),
            QCLASS(SOSE_LAT_Predef),
            QCLASS(SOSE_AA_Predef),
            QCLASS(SOSE_LMG_Predef),
            QCLASS(SOSE_Officer_Predef),
            QCLASS(SOSE_Type142_APC),
            QCLASS(SOSE_Type142_IFV),
            QCLASS(SOSE_Type142_IFV_XLR),
            QCLASS(SOSE_Type142_SPG),
            QCLASS(SOSE_Type142_AA)
        };
        weapons[] = {
            QCLASS(SOSE_Helmet),
            QCLASS(SOSE_Helmet_Officer),
            QCLASS(SOSE_Armour),
            QCLASS(SOSE_Uniform),
            QCLASS(SOSE_MA37),
            QCLASS(SOSE_M73),
            QCLASS(SOSE_VK78)
        };
        VERSION_CONFIG;

        skipWhenMissingDependencies = TRUE;
    };
};

#include "CfgWeapons.hpp"
#include "CfgEditorSubCategories.hpp"
#include "CfgVehicles.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgGroups.hpp"
#include "CfgWorlds.hpp"
