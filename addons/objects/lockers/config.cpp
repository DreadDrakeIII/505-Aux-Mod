#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "TKE_Props",
            "OPTRE_BW_WeaponRack",
            "OPTRE_BW_Locker",
            "OPTRE_UNSC_Structure_Containers"
        };
        units[] = {
            QCLASS(Locker_Base),
            QCLASS(Locker_CE),
            QCLASS(Locker_CE_FR)
        };
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
