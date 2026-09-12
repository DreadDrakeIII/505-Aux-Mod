class CfgVehicles {
    class OPTRE_Frigate_UNSC;
    class CLASS(Frigate_Innie_Blank): OPTRE_Frigate_UNSC {
        SCOPE_PUBLIC;
        author = AUTHOR;

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(StaticShips);

        displayName = "01: Paris Class Frigate (Blank)";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(ships\data\textures\Innie\Blank\decals_blank_ca.paa),
            QPATHTOF(ships\data\textures\Innie\Base\Paris_Innie_Back_co.paa),
            QPATHTOF(ships\data\textures\Innie\Base\Paris_Innie_Front_co.paa),
            "OPTRE_Frigate\data\Armament_co.paa"
        };
    };

    class CLASS(Frigate_Aegis): CLASS(Frigate_Innie_Blank) {
        displayName = "02: Paris Class Frigate (Aegis)";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(ships\data\textures\Innie\Aegis\decals_in2_ca.paa),
            QPATHTOF(ships\data\textures\Innie\Base\Paris_Innie_Back_co.paa),
            QPATHTOF(ships\data\textures\Innie\Base\Paris_Innie_Front_co.paa),
            "OPTRE_Frigate\data\Armament_co.paa"
        };
    };

    class CLASS(Frigate_Ajax): CLASS(Frigate_Innie_Blank) {
        displayName = "03: Paris Class Frigate (Ajax)";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(ships\data\textures\Innie\Ajax\decals_in3_ca.paa),
            QPATHTOF(ships\data\textures\Innie\Ajax\Ajax_Back_co.paa),
            QPATHTOF(ships\data\textures\Innie\Ajax\Ajax_Front_co.paa),
            QPATHTOF(ships\data\textures\Innie\Ajax\Ajax_Armament_co.paa)
        };
    };
    class CLASS(Frigate_Sword): CLASS(Frigate_Innie_Blank) {
        displayName = "04: Paris Class Frigate (Sword)";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(ships\data\textures\Innie\Sword\decals_in4_ca.paa),
            QPATHTOF(ships\data\textures\Innie\Sword\Sword_Back_co.paa),
            QPATHTOF(ships\data\textures\Innie\Sword\Sword_Front_co.paa),
            QPATHTOF(ships\data\textures\Innie\Sword\Sword_Armament_co.paa)
        };
    };

    class CLASS(Frigate_Sosei): CLASS(Frigate_Innie_Blank) {
        displayName = "05: Paris Class Frigate (Sōsei Colony)";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4"};
        hiddenSelectionsTextures[] = {
            "",
            QPATHTOF(ships\data\textures\Sosei\Sosei_Back_co.paa),
            QPATHTOF(ships\data\textures\Sosei\Sosei_Front_co.paa),
            QPATHTOF(ships\data\textures\Sosei\Sosei_Armament_co.paa)
        };
    };

    class CLASS(Frigate_Takeda): CLASS(Frigate_Innie_Blank) {
        displayName = "06: Paris Class Frigate (Takeda Separatists)";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4"};
        hiddenSelectionsTextures[] = {
            "",
            QPATHTOF(ships\data\textures\Takeda\Takeda_Back_co.paa),
            QPATHTOF(ships\data\textures\Takeda\Takeda_Front_co.paa),
            QPATHTOF(ships\data\textures\Takeda\Takeda_Armament_co.paa)
        };
    };
};
