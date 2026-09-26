#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "FIR_AirWeaponSystem_US",
            "MG8_core",
            "A3_Weapons_F_Jets",
            "A3_Air_F_Jets_Plane_Fighter_01"
        };
        units[] = {
            QCLASS(Warhawk),
            QCLASS(Cursed_Warhawk),
            QCLASS(StealthHawk)
        };
        weapons[] = {
            QCLASS(Warhawk_Gun20mm)
        };
        skipWhenMissingDependencies = 1;
        VERSION_CONFIG;
    };
};

#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
