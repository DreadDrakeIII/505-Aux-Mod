#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Weapons",
            "OPTRE_Weapons_BR",
            "A3_Weapons_F"
        };
        units[] = {};
        weapons[] = {
            QCLASS(LR_MEQ7_ATTACHMENT),
            QCLASS(FL_MEQ7_ATTACHMENT),
            QCLASS(MEQ7),
            QCLASS(M98H_Scope)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
