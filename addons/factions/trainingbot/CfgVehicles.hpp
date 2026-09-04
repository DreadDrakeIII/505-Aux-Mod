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
        model = "Uniforms\warbot.p3d";
        uniformClass = QCLASS(TRNE_Light_Uniform);
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {
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

        linkedItems[] = {QCLASS(TRNE_Head), "19th_invisible_Vest", "OPTRE_NVGT_C", "", LINKED_ITEMS_RADIO};
        respawnLinkedItems[] = {QCLASS(TRNE_Head), "19th_invisible_Vest", "OPTRE_NVGT_C", "", LINKED_ITEMS_RADIO};
        backpack = QCLASS(TRNE_Light_Rifleman_Predef);
    };
    class CLASS(TRNE_Light_LMG): CLASS(TRNE_Light_Unit_Base) {
        SCOPE_PUBLIC;

        displayName = "02: Training Bot(M247)";

        weapons[] = {
            QCLASS(M247),
            QCLASS(M6G),
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            QCLASS(M247),
            QCLASS(M6G),
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };

        linkedItems[] = {QCLASS(TRNE_Faceshield), "19th_invisible_Vest", "OPTRE_NVGT_C", "", LINKED_ITEMS_RADIO};
        respawnLinkedItems[] = {QCLASS(TRNE_Faceshield), "19th_invisible_Vest", "OPTRE_NVGT_C", "", LINKED_ITEMS_RADIO};
        backpack = QCLASS(TRNE_Light_LMG_Predef);
    };
    class CLASS(TRNE_Light_AT): CLASS(TRNE_Light_Unit_Base) {
        SCOPE_PUBLIC;

        displayName = "03: Training Bot(AT)";

        weapons[] = {
            QCLASS(MA37),
            QCLASS(M6G),
            "TCP_launch_M41",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            QCLASS(MA37),
            QCLASS(M6G),
            "TCP_launch_M41",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };

        linkedItems[] = {QCLASS(TRNE_Head), "19th_invisible_Vest", "OPTRE_NVGT_C", "", LINKED_ITEMS_RADIO};
        respawnLinkedItems[] = {QCLASS(TRNE_Head), "19th_invisible_Vest", "OPTRE_NVGT_C", "", LINKED_ITEMS_RADIO};
        backpack = QCLASS(TRNE_Light_AT_Predef);
    };
    ///////////////////Backpack////////////////////////
    class SC_Backpack_Warbot;
    class CLASS(TRNE_Light_Backpack): SC_Backpack_Warbot {
        SCOPE_HIDDEN;

        displayName = "[TRNE] Trainingbot Backpack";
        model = "sc_equipment\data\warbot\gen2_backpack.p3d";
        hiddenSelections[] = {"camo_backpack"};
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
    class CLASS(TRNE_Light_LMG_Predef): CLASS(TRNE_Light_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_400Rnd_762x51_Box,10);
            MAG_XX(OLI_8Rnd_127x40_Mag,12);
            MAG_XX(OPTRE_M9_Frag,4);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(Laserbatteries,1);
        };
    };
    class CLASS(TRNE_Light_AT_Predef): CLASS(TRNE_Light_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_40Rnd_762x51_Mag,10);
            MAG_XX(OLI_8Rnd_127x40_Mag,12);
            MAG_XX(TCP_2Rnd_102mm_Mag_HEAP,3);
            MAG_XX(OPTRE_M9_Frag,4);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(Laserbatteries,1);
        };
    };

};
