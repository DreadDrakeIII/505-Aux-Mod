#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Vehicles_Scorpion",
            "1st_MEU_patch_vehicles_land_scorpion"
        };
        units[] = {
            QCLASS(Scorpion),
            QCLASS(Scorpion_MB),
            QCLASS(Scorpion_Engineer),
            QCLASS(Scorpion_Arty),
            QCLASS(Scorpion_MB_Single),
            QCLASS(Scorpion_Single)
        };
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
