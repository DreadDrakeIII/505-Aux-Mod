class CfgVehicles {
    class OPTRE_Frigate_UNSC;
    class CLASS(Frigate_Innie_Blank): OPTRE_Frigate_UNSC {
        SCOPE_PUBLIC;
        author = AUTHOR;

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(StaticShips);

        displayName = "Paris Frigate (Blank)";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(ships\data\Innie\decals_blank_ca.paa),
            QPATHTOF(ships\data\Innie\Paris_Innie_Back_co.paa),
            QPATHTOF(ships\data\Innie\Paris_Innie_Front_co.paa),
            "OPTRE_Frigate\data\Armament_co.paa"
        };
    };

    class CLASS(Frigate_Innie): CLASS(Frigate_Innie_Blank) {
        displayName = "Paris Class Frigate (Innie)";
        hiddenSelections[] = {"camo1","camo2","camo3","camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(ships\data\Innie\decals_in2_ca.paa),
            QPATHTOF(ships\data\Innie\Paris_Innie_Back_co.paa),
            QPATHTOF(ships\data\Innie\Paris_Innie_Front_co.paa),
            "OPTRE_Frigate\data\Armament_co.paa"
        };
    };
};
