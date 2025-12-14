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
            "OPTRE_Weapons_Sniper",
            "OPTRE_Weapons_BR",
            "A3_Weapons_F",
            "cba_main",
            "ace_xm157",
            "ace_optics",
            "cba_optics",
            "ace_scopes"
        };
        units[] = {};
        weapons[] = {
            QCLASS(LR_MEQ7_ATTACHMENT),
            QCLASS(FL_MEQ7_ATTACHMENT),
            QCLASS(MEQ7),
            QCLASS(VTR_Scope),
            QCLASS(M98HA_Scope),
            QCLASS(M98H_Suppressor)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
