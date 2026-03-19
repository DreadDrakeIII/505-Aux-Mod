class CfgVehicles {
    class Module_F;

    class CLASS(Module_FullHealVehicle): Module_F {
        scope = 2;
        scopeCurator = 2;
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
        scope = 2;
        scopeCurator = 2;
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
};