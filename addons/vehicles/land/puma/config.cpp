#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "DMNS_Vehicles_M511_Springbok"
        };
        units[] = {
            QCLASS(Puma_AA),
            QCLASS(Puma_IFV),
            QCLASS(Puma_MGS),
            QCLASS(Puma_APC)
        };
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
