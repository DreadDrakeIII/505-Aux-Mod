class CfgPatches {
    class 505th_minesweeper {
        name = "505th Minesweeper IED";
        author = "505th Dev Team";
        url = "";
        units[] = {"505th_ModuleMinesweeperIED_F"};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {
            "A3_Modules_F",
            "zen_main"
        };
    };
};

class CfgFunctions {
    class 505th_MinesweeperIED {
        tag = "MSIED";
        class Functions {
            file = "\BLU\OLI\addons\minesweeper\functions";
            class initIED {};
            class addDefuseAction {};
            class initMinefield {};
            class getField {};
            class tileClick {};
            class bombCount {};
            class uncover {};
            class detonate {};
            class detonateServer {};
            class sweeperTick {};
            class complete {};
            class completeServer {};
            class iedTick {};
            class moduleIED {};
            class zenInit {postInit = 1;};
            class zenModule {};
            class contextMenuInit {postInit = 1;};
            class preDefusalBeep {};
        };
    };
};

class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class ArgumentsBaseUnits {};
        class ModuleDescription {};
    };

    class 505th_ModuleMinesweeperIED_F: Module_F {
        scope = 2;
        displayName = "[505th] Minesweeper IED";
        icon = "\a3\modules_f\data\iconexplosive_ca.paa";
        category = "505th_MinesweeperIED";
        function = "MSIED_fnc_moduleIED";
        functionPriority = 1;
        isGlobal = 0;
        isTriggerActivated = 0;
        isDisposable = 0;
        is3DEN = 0;

        class Arguments {
            class Difficulty {
                displayName = "Difficulty";
                description = "Minesweeper difficulty level";
                typeName = "STRING";
                class values {
                    class Easy {
                        name = "Easy (9x9, 10 mines, 55s)";
                        value = "easy";
                        default = 1;
                    };
                    class Medium {
                        name = "Medium (12x12, 20 mines, 90s)";
                        value = "medium";
                    };
                    class Hard {
                        name = "Hard (16x16, 40 mines, 150s)";
                        value = "hard";
                    };
                };
            };

            class TriggerSide {
                displayName = "Trigger Side";
                description = "Which side triggers the IED";
                typeName = "STRING";
                class values {
                    class Everyone {
                        name = "Everyone";
                        value = "everyone";
                        default = 1;
                    };
                    class West {
                        name = "BLUFOR";
                        value = "west";
                    };
                    class East {
                        name = "OPFOR";
                        value = "east";
                    };
                    class Independent {
                        name = "Independent";
                        value = "resistance";
                    };
                    class Civilian {
                        name = "Civilian";
                        value = "civilian";
                    };
                };
            };
        };

        class ModuleDescription: ModuleDescription {
            description = "Place directly on an object to turn it into a 505th Minesweeper IED. Can only be disarmed by completing a minesweeper minigame. The module will automatically detect the object underneath it.";
            sync[] = {};
        };
    };
};

#include "gui\minesweeper.hpp"
