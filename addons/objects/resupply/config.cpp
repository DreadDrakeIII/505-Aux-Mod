#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Misc_Crates"
        };
        units[] = {
            QCLASS(Resupply_Base),
            QCLASS(Resupply_SquadAmmo),
            QCLASS(Resupply_PlatoonAmmo),
            QCLASS(Resupply_SquadMedical),
            QCLASS(Resupply_PlatoonMedical),
            QCLASS(Resupply_Explosives),
            QCLASS(Resupply_Rockets),
            QCLASS(CE_Loadout)
        };
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
