class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class ArgumentsBaseUnits {
            class Units;
        };
        class ModuleDescription;
    };

    class MSW_ModuleMinesweeperIED: Module_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "505th Minesweeper";
        category = "MSW_MinesweeperIEDCategory";
        icon = "\A3\ui_f\data\IGUI\Cfg\simpleTasks\types\mine_ca.paa";
        function = "MSW_fnc_moduleApplyIED";
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;

        curatorCanAttach = 1;
        curatorRequiredObject = 1;
        curatorRequiredObjectClass = "All";

        class Arguments: ArgumentsBaseUnits {
            class Units: Units {};
            class Difficulty {
                displayName = "Difficulty";
                description = "Minesweeper difficulty preset, changes the amount of bombs in the field.";
                typeName = "STRING";
                defaultValue = "medium"; // Minecount per difficulty is changed in \IED\init_minefield.sqf

                class Values {
                    class Easy {
                        name = "Easy";
                        value = "easy";
                    };
                    class Medium {
                        name = "Medium";
                        value = "medium";
                    };
                    class Hard {
                        name = "Hard";
                        value = "hard";
                    };
                };
            };
        };

        class ModuleDescription: ModuleDescription {
            description = "Turns object into minesweeper IEDs.";
            sync[] = {};
        };
    };
};
