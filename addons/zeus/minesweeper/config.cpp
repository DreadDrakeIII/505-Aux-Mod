#include "\BLU\OLI\addons\zeus\minesweeper\IED\defines.hpp"
#include "\BLU\OLI\addons\zeus\minesweeper\IED\minesweeper.hpp"

class CfgPatches
{
    class 505th_minesweeper_ied
    {
        units[] = { "505th_ModuleMinesweeperIED" };
        weapons[] = {};
        requiredVersion = 1.58;
        requiredAddons[] = { "A3_Modules_F", "zen_dialog" };
    };
};

class CfgFactionClasses
{
    class NO_CATEGORY;
    class 505th_MinesweeperIEDCategory: NO_CATEGORY
    {
        displayName = "505th Minesweeper IED";
    };
};

class CfgFunctions
{
    class 505th
    {
        class Functions
        {
            file = "\BLU\OLI\addons\zeus\minesweeper\functions";
            class initShoterIED { preInit = 1; };
            class Minesweeper {};
            class moduleApplyIED {};
        };
    };
};

class CfgVehicles
{
    class Logic;
    class Module_F: Logic
    {
        class ArgumentsBaseUnits
        {
            class Units;
        };
        class ModuleDescription;
    };

    class 505th_ModuleMinesweeperIED: Module_F
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "Minesweeper IED";
        category = "505th_MinesweeperIEDCategory";
        icon = "\A3\ui_f\data\IGUI\Cfg\simpleTasks\types\mine_ca.paa";
        function = "505th_fnc_moduleApplyIED";
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;

        curatorCanAttach = 1;
        curatorRequiredObject = 1;
        curatorRequiredObjectClass = "All";

        class Arguments: ArgumentsBaseUnits
        {
            class Units: Units {};
        };

        class ModuleDescription: ModuleDescription
        {
            description = "Turns object into minesweeper IED. Opens ZEN dialog for settings.";
            sync[] = {};
        };
    };
};
