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
            "OPTRE_Core"
        };
        units[] = {
            QCLASS(IRON_Unit_Base),
            QCLASS(IRON_Unit_Rifleman),
            QCLASS(IRON_Unit_SL),
            QCLASS(IRON_Unit_Autorifleman),
            QCLASS(IRON_Unit_Marksman),
            QCLASS(IRON_Unit_AT),
            QCLASS(IRON_Unit_Medic),
            QCLASS(IRON_Backpack),
            QCLASS(IRON_Backpack_Predef),
            QCLASS(IRON_Backpack_AR),
            QCLASS(IRON_Backpack_Marksman),
            QCLASS(IRON_Backpack_AT),
            QCLASS(IRON_Backpack_Medic)
        };
        weapons[] = {
            QCLASS(IRON_Helmet_Base),
            QCLASS(IRON_Cap),
            QCLASS(IRON_Boonie),
            QCLASS(IRON_Uniform_Base),
            QCLASS(IRON_Uniform),
            QCLASS(IRON_Vest_Base),
            QCLASS(IRON_Vest),
            QCLASS(IRON_Vest_Heavy)
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
