#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        addonRootClass = QCLASS(main);  // 🔹 optional but good practice
        requiredAddons[] = {
            QCLASS(main),
            "A3_Weapons_F",
            "OPTRE_Weapons_Ammo"

        };
        units[] = {};
        weapons[] = {};
        magazines[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgMagazines.hpp"
