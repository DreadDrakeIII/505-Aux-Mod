#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "A3_Air_F_Exp_VTOL_01",
            "A3_Sounds_F_Exp",
            "jsrs2025_config_c",
            "ace_interaction",
            "ace_cargo"
        };
        units[] = {
            QCLASS(Widow_Armed),
            QCLASS(Widow),
            QCLASS(Widow_Vehicle)
        };
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
