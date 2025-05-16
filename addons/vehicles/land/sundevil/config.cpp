#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Vehicles_M808B2",
            "OPTRE_JSRS_Sounds",
            "OPTRE_ACE_Compat"
        };
        units[] = {
            QCLASS(Sundevil),
            QCLASS(Sundevil_A1),
            QCLASS(Sundevil_Single),
            QCLASS(Sundevil_A1_Single)
        };
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"