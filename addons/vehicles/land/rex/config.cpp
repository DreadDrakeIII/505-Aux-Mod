#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "A3_Drones_F_Soft_F_Gamma_UGV_01",
            "1st_MEU_patch_vehicles_land_pogv"
        };
        units[] = {
            QCLASS(Rex_Unarmed),
            QCLASS(Rex_Armed)
        };
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"