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
            QCLASS(Springbok_AA),
            QCLASS(Springbok_IFV),
            QCLASS(Springbok_MGS),
            QCLASS(Springbok_APC)
        };
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"