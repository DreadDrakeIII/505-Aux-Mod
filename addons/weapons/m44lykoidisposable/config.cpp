#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Weapons_AT_M44_Lykoi"
        };
        units[] = {};
        weapons[] = {
            QCLASS(M44_Lykoi_Disposable_base),
            QCLASS(M44_Lykoi_Disposable),
            QCLASS(M44_Lykoi_Loaded),
            QCLASS(M44_Lykoi_Used)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CBA_DisposableLaunchers.hpp"
