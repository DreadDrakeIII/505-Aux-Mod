#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Vehicles_Sparrowhawk"
        };
        units[] = {
            QCLASS(AV22_Sparrowhawk),
            QCLASS(AV22A_Sparrowhawk),
            QCLASS(AV22B_Sparrowhawk),
            QCLASS(AV22C_Sparrowhawk)
        };
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
