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
            QCLASS(TRNE_LightUnit_Base),
            QCLASS(TRNE_Light_Rifleman),
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
#include "CfgWorlds.hpp"
