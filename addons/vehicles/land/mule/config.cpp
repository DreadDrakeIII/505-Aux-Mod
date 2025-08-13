#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "A3_Soft_F_Gamma_Truck_02",
        };
        units[] = {
            QCLASS(Mule_Transport),
            QCLASS(Mule_Covered),
            QCLASS(Mule_MRL),
            QCLASS(Mule_Ammo),
            QCLASS(Mule_Fuel),
            QCLASS(Mule_Medical),
            QCLASS(Mule_Repair)
        };
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
