class CfgVehicles {
    class B_AFV_Wheeled_01_cannon_F;
    class CLASS(Apex_Base): B_AFV_Wheeled_01_cannon_F {
        SCOPE_HIDDEN;
        author = "505th Aux Team";

        displayName = "M310 Apex (Base)";
        side = BLUFOR;
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(APCs);
        crew = QCLASS(Marine_Tank_Crew);
        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "CamoNet",
            "CamoSlat"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\apex\data\textures\EXT1_co.paa),
            QPATHTOF(land\apex\data\textures\EXT2_co.paa),
            QPATHTOF(land\apex\data\textures\Wheel_co.paa),
            "a3\Armor_F\Data\camonet_NATO_Green_CO.paa",
            QPATHTOF(land\apex\data\textures\EXT3_co.paa)
        };
        textureList[] = {"505th", 1, "Green", 0, "Tan", 0};
        class TextureSources {
            class Main {
                author = AUTHOR;
                displayName = "505th";
                factions[] = {};
                textures[] = {
                    QPATHTOF(land\apex\data\textures\EXT1_co.paa),
                    QPATHTOF(land\apex\data\textures\EXT2_co.paa),
                    QPATHTOF(land\apex\data\textures\Wheel_co.paa),
                    "a3\Armor_F\Data\camonet_NATO_Green_CO.paa",
                    QPATHTOF(land\apex\data\textures\EXT3_co.paa)
                };
            };
            class Green: Main {
                displayName = "Green";
                textures[] = {
                    "a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_EXT1_green_CO.paa",
                    "a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_EXT2_green_CO.paa",
                    "a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_wheel_green_CO.paa",
                    "a3\Armor_F\Data\camonet_NATO_Green_CO.paa",
                    "A3\Armor_F_Tank\AFV_Wheeled_01\Data\afv_wheeled_01_EXT3_CO.paa"
                };
            };
            class Tan: Main {
                displayName = "Tan";
                textures[] = {
                    "a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_EXT1_CO.paa",
                    "a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_EXT2_CO.paa",
                    "a3\Armor_F_Tank\AFV_Wheeled_01\data\afv_wheeled_01_wheel_CO.paa",
                    "a3\Armor_F\Data\camonet_NATO_Desert_CO.paa",
                    "A3\Armor_F_Tank\AFV_Wheeled_01\Data\afv_wheeled_01_EXT3_sand_CO.paa"
                };
            };
        };
    };

    class CLASS(Apex): CLASS(Apex_Base) {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "M310 Apex";
    };
};
