#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Vehicles_Warthog",
        };
        units[] = {
            QCLASS(Warthog_LRV),
            QCLASS(Warthog_AT_LRV),
            QCLASS(Warthog_Gauss_LRV),
            QCLASS(Warthog_AA),
            QCLASS(Warthog_FAV),
            QCLASS(Warthog_FAV_APC),
            QCLASS(Warthog_APC_MED),
            QCLASS(ARTE_Warthog_LRV),
            QCLASS(ARTE_Warthog_AT_LRV),
            QCLASS(ARTE_Warthog_TD_LRV),
            QCLASS(ARTE_Warthog_AA),
            QCLASS(Warthog_TT)
        };
        weapons[] = {};
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
