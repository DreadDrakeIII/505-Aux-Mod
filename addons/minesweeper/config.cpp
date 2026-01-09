#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "MSW_ModuleMinesweeperIED"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QCLASS(main),
            "A3_Modules_F",
            "A3_UI_F"
        };
        author = "505th Dev Team";
        authors[] = {"505th Dev Team", "Rat"};
        url = "";
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgFunctions.hpp"
#include "CfgVehicles.hpp"

// Dialog definitions
#include "IED\minesweeper.hpp"
