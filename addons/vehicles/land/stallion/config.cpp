#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Vehicles_Misc"
        };
        units[] = {
            QCLASS(Stallion_Open_Transport),
            QCLASS(Stallion_Covered_Transport),
            QCLASS(Stallion_Ammo),
            QCLASS(Stallion_Refuel),
            QCLASS(Stallion_Repair),
            QCLASS(Stallion_Medical),
            QCLASS(Stallion_Device)
        };
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
