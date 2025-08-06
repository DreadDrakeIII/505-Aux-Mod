#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "A3_Armor_F_Tank_AFV_Wheeled_01",
            "tfar_external_intercom",
            "ace_realisticnames",
            "ace_vehicle_damage"
        };
        units[] = {
            QCLASS(Apex_Base),
            QCLASS(Apex)
        };
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
