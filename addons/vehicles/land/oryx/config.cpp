#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Vehicles_Warthog",
        };
        units[] = {
            QCLASS(M493_APC),
            QCLASS(M493_AIE),
            QCLASS(M493_AIE_RCWS),
            QCLASS(M493_M37),
            QCLASS(M493_M37_RCWS),
            QCLASS(M494_APC)
        };
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"