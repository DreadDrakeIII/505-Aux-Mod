#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "sc_equipment",
        };
        units[] = {
            QCLASS(TRNE_Light_Unit_Base),
            QCLASS(TRNE_Light_Rifleman),
            QCLASS(TRNE_Light_Backpack),
            QCLASS(TRNE_Light_Rifleman_Predef)
        };
        weapons[] = {
            QCLASS(Uniform_Base),
            QCLASS(TRNE_Light_Uniform),
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
