#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "SC_Fixed",
            QCLASS(vehicles_pelican),
            "A3_Air_F_Jets_Plane_Fighter_04"
        };
        units[] = {
            QCLASS(G42_Renzan_Base),
            QCLASS(G42_Renzan),
            QCLASS(K172_Panther_Base),
            QCLASS(K172_Panther_AA),
            QCLASS(K172_Panther_Gun)
        };
        weapons[] = {};
        skipWhenMissingDependencies = TRUE;
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
#include "CfgFactionClasses.hpp"
