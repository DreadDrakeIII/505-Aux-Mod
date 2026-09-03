class CfgVehicles {
    class Module_F;

    class CLASS(Module_FullHealVehicle): Module_F {
        SCOPE_PUBLIC;
        displayName = "Full Heal Vehicle";
        category = QCLASS(Zeus);
        function = "OLI_fnc_fullHealVehicle";
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 1;
        curatorCanAttach = 1;
        author = AUTHOR;
        icon = "\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\repair_ca.paa";

        class ModuleDescription {
            description = "Place on a vehicle to fully repair all hit points and refuel it.";
            sync[] = {};
        };
    };

    class CLASS(Module_EjectOccupants): Module_F {
        SCOPE_PUBLIC;
        displayName = "Eject All Occupants";
        category = QCLASS(Zeus);
        function = "OLI_fnc_ejectOccupants";
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 1;
        curatorCanAttach = 1;
        author = AUTHOR;
        icon = "\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\move_ca.paa";

        class ModuleDescription {
            description = "Place on a vehicle to force all crew and passengers out.";
            sync[] = {};
        };
    };

    class Land_MultiScreenComputer_01_olive_F;
    class CLASS(KCS_Computer): Land_MultiScreenComputer_01_olive_F {
        author = AUTHOR;
        SCOPE_PUBLIC;
        displayName = "KCS Training Computer";

        class ACE_Actions {
            class ACE_MainActions {
                selection = "";
                distance = 5;
                condition = "true";

                class OLI_KCS_Root {
                    displayName = "Casualty Spawner";
                    condition = "true";
                    statement = "";
                    insertChildren = "[_target, _player] call OLI_KCS_fnc_menuChildren";
                    distance = 5;
                };
            };
        };
    };

    class Land_JumpTarget_F;
    class CLASS(KCS_TrainingSpot): Land_JumpTarget_F {
        author = AUTHOR;
        SCOPE_PUBLIC;
        displayName = "KCS Training Spot";
    };
};
