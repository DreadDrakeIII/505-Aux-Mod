#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "TKE_UCN",
            "TKE_BDU",
            "TKE_Rogue_Uniform",
        };
        units[] = {
            QCLASS(Wolf_Unit_Base),
            QCLASS(Jager_Unit_Base),
            QCLASS(Jager_Unit_02_Base),
            QCLASS(Wolf_Rifleman),
            QCLASS(Wolf_AT),
            QCLASS(Wolf_AA),
            QCLASS(Wolf_Marksman),
            QCLASS(Wolf_Grenadier),
            QCLASS(Jager_Rifleman),
            QCLASS(Jager_AT),
            QCLASS(Jager_LMG),
            QCLASS(Jager_Sniper),
            QCLASS(Jager_Bismark),
            QCLASS(Wolf_Backpack),
            QCLASS(Jager_Backpack),
            QCLASS(Wolf_Rifleman_Predef),
            QCLASS(Wolf_Marksman_Predef),
            QCLASS(Wolf_AT_Predef),
            QCLASS(Wolf_AA_Predef),
            QCLASS(Wolf_Grenadier_Predef),
            QCLASS(Jager_Rifleman_Predef),
            QCLASS(Jager_AT_Predef),
            QCLASS(Jager_LMG_Predef),
            QCLASS(Jager_Sniper_Predef),
            QCLASS(Jager_Bismark_Predef)
        };
        weapons[] = {
            QCLASS(Helmet_Base),
            QCLASS(Wolf_Cap),
            QCLASS(Wolf_Boonie),
            QCLASS(Jager_Helmet_01),
            QCLASS(Jager_Helmet_02),
            QCLASS(Jager_Helmet_03),
            QCLASS(Uniform_Base),
            QCLASS(Wolf_Uniform),
            QCLASS(Jager_Rolled_Uniform),
            QCLASS(Jager_Uniform),
            QCLASS(Vest_Base),
            QCLASS(Wolf_Vest_01),
            QCLASS(Wolf_Vest_02),
            QCLASS(Jager_Vest_01),
            QCLASS(Jager_Vest_02),
            QCLASS(Jager_Vest_03),
        };
        VERSION_CONFIG;

        skipWhenMissingDependencies = TRUE;
    };
};

#include "CfgWeapons.hpp"
#include "CfgEditorSubCategories.hpp"
#include "CfgVehicles.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgWorlds.hpp"
