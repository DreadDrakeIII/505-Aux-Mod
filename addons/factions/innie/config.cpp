#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "SC_Fixed",
            QCLASS(vehicles_pelican)
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

#include "CfgVehicles.hpp"
#include "CfgFactionClasses.hpp"
