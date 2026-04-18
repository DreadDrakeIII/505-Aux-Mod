#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QCLASS(main),
            "cba_main",
            "cba_xeh",
            "A3_Characters_F_Exp",
            "ace_goggles",
            "ace_vector",
            "OPTRE_Hud",
            "OPTRE_FunctionsLibrary",
            "TCP_Characters_BLUFOR_UNSC_Army_Facewear_balaclavaTacticalGlasses",
            "TCP_Functions"
        };
        units[] = {};
        weapons[] = {QCLASS(Vector)};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgGlasses.hpp"
#include "CfgWeapons.hpp"
