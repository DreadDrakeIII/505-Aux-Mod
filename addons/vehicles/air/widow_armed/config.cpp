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
            "jsrs_soundmod_complete_edition"
            ,"ace_interaction",
            "ace_cargo"
        };
        units[] = {
            QCLASS(Widow_Armed)
        };
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"