class CfgVehicles {
    class CLASS(OPFOR_Unit_Base);
    class CLASS(TRNE_Light_Unit_Base): CLASS(OPFOR_Unit_Base) {
        SCOPE_HIDDEN;
        faction = QFACTION(TRNE);

        genericNames = QCLASS(TRNE_Bots);
        modelSides[] = {ALL_SIDES};
        editorSubcategory = QEDSUBCAT(TRNE_Light_INF);

        items[] = {
            ITEM_20("ACE_elasticBandage"),
            ITEM_4("ACE_tourniquet"),
            "FirstAidKit"
        };
        respawnItems[] = {
            ITEM_20("ACE_elasticBandage"),
            ITEM_4("ACE_tourniquet"),
            "FirstAidKit"
        };
        model = "sc_equipment\data\warbot\gen2_light.p3d";
        uniformClass = QCLASS(TRNE_Light_Uniform);
        hiddenSelections[] = {"camo_head","camo_torso","camo_legs"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(trainingbot\data\textures\TrainingBot_Head_co.paa),
            QPATHTOF(trainingbot\data\textures\TrainingBot_Torso_co.paa),
            QPATHTOF(trainingbot\data\textures\TrainingBot_Legs_co.paa)
        };
    };
    /////////////////////TRNE_Light//////////////////////////
    class CLASS(TRNE_Light_Rifleman): CLASS(TRNE_Light_Unit_Base) {
        SCOPE_PUBLIC;

        displayName = "01: Training Bot(MA37)";

        weapons[] = {
            QCLASS(MA37),
            QCLASS(M6G),
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            QCLASS(MA37),
            QCLASS(M6G),
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };

        linkedItems[] = {LINKED_ITEMS_RADIO};
        respawnLinkedItems[] = {LINKED_ITEMS_RADIO};
        backpack = QCLASS(TRNE_Light_Rifleman_Predef);
    };
    ///////////////////Backpack////////////////////////
    class SC_Backpack_Warbot;
    class CLASS(TRNE_Light_Backpack): SC_Backpack_Warbot {
        SCOPE_HIDDEN;

        displayName = "[TRNE] Trainingbot Backpack";
        model = "sc_equipment\data\warbot\gen2_backpack.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {
            "sc_equipment\data\warbot\textures\backpack_co.paa"
        };
    };
    class CLASS(TRNE_Light_Rifleman_Predef): CLASS(TRNE_Light_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_40Rnd_762x51_Mag,10);
            MAG_XX(OLI_8Rnd_127x40_Mag,12);
            MAG_XX(OPTRE_M9_Frag,4);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(Laserbatteries,1);
        };
    };

};
