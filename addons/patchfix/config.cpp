#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "cba_settings",
            "Goko_ballistic_Impact",
            "SA_AdvancedSlingLoading"
        };
        units[] = {};
        weapons[] = {};
        VERSION_CONFIG;
    };
};

class CfgFunctions {
    class goko_player_patch {
        class core {
            file = "\BLU\OLI\addons\patchfix\functions";
            class postInit_overrideImpact { postInit = 1; };
            class preInit_registerSettings { preInit = 1; };
            class ropeLogInit { postInit = 1; };
        };
    };
};
