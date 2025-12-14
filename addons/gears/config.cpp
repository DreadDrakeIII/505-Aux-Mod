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
            "OPTRE_Hud",              // <-- OPTRE mod's HUD PBO
            "OPTRE_FunctionsLibrary"  // <-- OPTRE mod's Functions PBO
        };
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgGlasses.hpp"
#include "CfgOptreHudSchemes.hpp"
