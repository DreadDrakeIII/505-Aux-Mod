#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "SC_Fixed"
        };
        units[] = {
            QCLASS(G42_Renzan_Base),
            QCLASS(G42_Renzan)
        };
        weapons[] = {};
        skipWhenMissingDependencies = TRUE;
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
