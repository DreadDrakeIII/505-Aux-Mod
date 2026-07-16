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

    class CLASS(KCS) {
        author = AUTHOR;
        name = "505th Auxilary Mod - Zeus (KCS Casualty Spawner)";
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QCLASS(main),
            "cba_xeh",
            "ace_interact_menu",
            "ace_medical",
            "ace_medical_engine",
            "ace_medical_status",
            "ace_medical_treatment",
            "A3_Props_F_Enoch_Military_Equipment",
            "A3_Structures_F_Mil_Helipads"
        };
        units[] = {
            QCLASS(KCS_Computer),
            QCLASS(KCS_TrainingSpot)
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

    class KCS {
        tag = QCLASS(KCS);

        class main {
            file = "\BLU\OLI\addons\zeus\functions\kcs";

            class preInit {
                preInit = 1;
            };
            class postInit {
                postInit = 1;
            };
            class getSpawnArea {};
            class createPatient {};
            class applyRandomWounds {};
            class addFracture {};
            class applyKat {};
            class menuChildren {};
            class addComputer {};
            class clearPatients {};
            class livePatients {};
        };
    };
};

#include "CfgVehicles.hpp"
