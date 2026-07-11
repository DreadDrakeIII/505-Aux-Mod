#include "script_component.hpp"

class CfgPatches {
    class SUBADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        addonRootClass = QUOTE(ADDON);
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QUOTE(ADDON),
            "OPTRE_Weapons_AT",
            "cba_main"
        };
        units[] = {};
        weapons[] = {
            QCLASS(M44_Lykoi_Base_Grey),
            QCLASS(M44_Lykoi_Disposable_Grey),
            QCLASS(M44_Lykoi_Loaded_Grey),
            QCLASS(M44_Lykoi_Used_Grey)
        };
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CBA_DisposableLaunchers.hpp"
