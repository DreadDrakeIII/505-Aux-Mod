#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QCLASS(main),
            "A3_Modules_F"
        };
        units[] = {
            QCLASS(Module_FullHealVehicle),
            QCLASS(Module_EjectOccupants)
        };
        weapons[] = {};
        VERSION_CONFIG;
    };
};

class CfgFactionClasses {
    class NO_CATEGORY;

    class CLASS(Zeus): NO_CATEGORY {
        displayName = "[505th] Zeus";
    };
};

class CfgFunctions {
    class OLI {
        class Zeus {
            tag = "OLI";

            class fullHealVehicle {
                file = "\BLU\OLI\addons\zeus\functions\fnc_fullHealVehicle.sqf";
            };

            class ejectOccupants {
                file = "\BLU\OLI\addons\zeus\functions\fnc_ejectOccupants.sqf";
            };
        };
    };
};

#include "CfgVehicles.hpp"