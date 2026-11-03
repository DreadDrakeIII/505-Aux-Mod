#define SOSE_LINKED_ITEMS_COMMON QCLASS(SOSE_Armour), "OLI_MedScanner_Mask", "ItemMap", "TCP_UGPS", "TCP_ANPRC55", "ItemCompass", "TCP_Watch", "OPTRE_NVG"
#define SOSE_LINKED_ITEMS QCLASS(SOSE_Helmet), SOSE_LINKED_ITEMS_COMMON
#define SOSE_LINKED_ITEMS_OFFICER "OLI_Beret_Black", SOSE_LINKED_ITEMS_COMMON

#define SOSE_ITEMS \
    ITEM_5("ACE_elasticBandage"), "ACE_tourniquet", "ACE_MapTools", "ACE_IR_Strobe_Item", \
    "ItemcTabHCam", "ACE_EntrenchingTool", "ACE_Flashlight_XL50", ITEM_5("ACE_CableTie"), \
    "ItemAndroid", "WBK_HeadLampItem_Double"

#define SOSE_MAGAZINES_COMMON \
    "kat_Painkiller", ITEM_5("TCP_M21_Smoke"), ITEM_3("TCP_M21_SmokeBlue"), "Laserbatteries"

#define SOSE_MAGAZINES "OLI_40Rnd_762x51_Mag", SOSE_MAGAZINES_COMMON

class CfgVehicles {
    /////////////////////Base Unit/////////////////////
    class CLASS(BLUFOR_Unit_Base);
    class CLASS(SOSE_Unit_Base): CLASS(BLUFOR_Unit_Base) {
        SCOPE_HIDDEN;

        author = AUTHOR;
        faction = QFACTION(SOSE);
        side = BLUFOR;

        genericNames = QCLASS(SOSE_Operator);
        editorSubcategory = QEDSUBCAT(SOSE_INF);
        modelSides[] = {BLUFOR};

        // Body = TKE CSTR undersuit (TKE_CSTRUni_inf_B)
        model = "\TKE_Kuiper_Engagements\TKE_SpecOPS\TKE_CSTRUni.p3d";
        uniformClass = QCLASS(SOSE_Uniform);
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(sosei\data\textures\infantry\SOSE_UniPants_co.paa),
            QPATHTOF(sosei\data\textures\infantry\SOSE_UniTop_co.paa)
        };

        linkedItems[] = {SOSE_LINKED_ITEMS};
        respawnLinkedItems[] = {SOSE_LINKED_ITEMS};
    };

    ///////////////////Infantry Roles//////////////////
    class CLASS(SOSE_Rifleman): CLASS(SOSE_Unit_Base) {
        SCOPE_PUBLIC;
        displayName = "Sosei Rifleman";

        weapons[] = {QCLASS(SOSE_MA37), "OPTRE_Smartfinder", "Throw", "Put"};
        respawnWeapons[] = {QCLASS(SOSE_MA37), "OPTRE_Smartfinder", "Throw", "Put"};

        magazines[] = {SOSE_MAGAZINES};
        respawnMagazines[] = {SOSE_MAGAZINES};

        items[] = {SOSE_ITEMS};
        respawnItems[] = {SOSE_ITEMS};

        backpack = QCLASS(SOSE_Rifleman_Predef);
    };

    class CLASS(SOSE_LAT): CLASS(SOSE_Rifleman) {
        displayName = "Sosei Rifleman (LAT)";
        icon = "iconManAT";

        weapons[] = {QCLASS(SOSE_MA37), "OLI_M20_Lawbringer_LAT", "OLI_M6G", "OPTRE_Smartfinder", "Throw", "Put"};
        respawnWeapons[] = {QCLASS(SOSE_MA37), "OLI_M20_Lawbringer_LAT", "OLI_M6G", "OPTRE_Smartfinder", "Throw", "Put"};

        magazines[] = {SOSE_MAGAZINES, "OLI_M20_HEAT75", ITEM_2("OLI_8Rnd_127x40_Mag")};
        respawnMagazines[] = {SOSE_MAGAZINES, "OLI_M20_HEAT75", ITEM_2("OLI_8Rnd_127x40_Mag")};

        backpack = QCLASS(SOSE_LAT_Predef);
    };

    class CLASS(SOSE_AA): CLASS(SOSE_Rifleman) {
        displayName = "Sosei Rifleman (AA)";
        icon = "iconManAT";

        weapons[] = {QCLASS(SOSE_MA37), "MEU_Spkr_S108", "OLI_M6G", "OPTRE_Smartfinder", "Throw", "Put"};
        respawnWeapons[] = {QCLASS(SOSE_MA37), "MEU_Spkr_S108", "OLI_M6G", "OPTRE_Smartfinder", "Throw", "Put"};

        magazines[] = {SOSE_MAGAZINES, "MEU_SPKR108_SAM_AA", ITEM_2("OLI_8Rnd_127x40_Mag")};
        respawnMagazines[] = {SOSE_MAGAZINES, "MEU_SPKR108_SAM_AA", ITEM_2("OLI_8Rnd_127x40_Mag")};

        backpack = QCLASS(SOSE_AA_Predef);
    };

    class CLASS(SOSE_LMG): CLASS(SOSE_Rifleman) {
        displayName = "Sosei Autorifleman (LMG)";
        icon = "iconManMG";

        weapons[] = {QCLASS(SOSE_M73), "OLI_M6G", "OPTRE_Smartfinder", "Throw", "Put"};
        respawnWeapons[] = {QCLASS(SOSE_M73), "OLI_M6G", "OPTRE_Smartfinder", "Throw", "Put"};

        magazines[] = {"OLI_400Rnd_95x40_Box", ITEM_2("OLI_8Rnd_127x40_Mag"), SOSE_MAGAZINES_COMMON};
        respawnMagazines[] = {"OLI_400Rnd_95x40_Box", ITEM_2("OLI_8Rnd_127x40_Mag"), SOSE_MAGAZINES_COMMON};

        backpack = QCLASS(SOSE_LMG_Predef);
    };

    class CLASS(SOSE_Officer): CLASS(SOSE_Rifleman) {
        displayName = "Sosei Officer";
        icon = "iconManOfficer";
        rank = "CAPTAIN";

        weapons[] = {QCLASS(SOSE_VK78), "OLI_M6C", "OPTRE_Smartfinder", "Throw", "Put"};
        respawnWeapons[] = {QCLASS(SOSE_VK78), "OLI_M6C", "OPTRE_Smartfinder", "Throw", "Put"};

        magazines[] = {"OLI_20Rnd_95xVX2_Mag", ITEM_2("OLI_12Rnd_127x40_Mag"), SOSE_MAGAZINES_COMMON};
        respawnMagazines[] = {"OLI_20Rnd_95xVX2_Mag", ITEM_2("OLI_12Rnd_127x40_Mag"), SOSE_MAGAZINES_COMMON};

        linkedItems[] = {SOSE_LINKED_ITEMS_OFFICER};
        respawnLinkedItems[] = {SOSE_LINKED_ITEMS_OFFICER};

        backpack = QCLASS(SOSE_Officer_Predef);
    };

    /////////////////////Backpacks/////////////////////
    class TKE_RuckSackCSTR;
    class CLASS(SOSE_Rucksack): TKE_RuckSackCSTR {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[Sosei] CSTR Rucksack";
        hiddenSelectionsTextures[] = {
            QPATHTOF(sosei\data\textures\infantry\SOSE_Rucksack_co.paa)
        };
    };
    class CLASS(SOSE_Rifleman_Predef): CLASS(SOSE_Rucksack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_40Rnd_762x51_Mag,8);
            MAG_XX(OPTRE_M9_Frag,1);
        };
        class TransportItems {
            ITEM_XX(efak_IFAK_2,1);
        };
    };

    class CLASS(SOSE_LAT_Predef): CLASS(SOSE_Rucksack) {
        SCOPE_HIDDEN;
        class TransportMagazines {
            MAG_XX(OLI_40Rnd_762x51_Mag,6);
            MAG_XX(OLI_M20_HE44,1);
            MAG_XX(OLI_M20_WP,1);
            MAG_XX(OPTRE_M9_Frag,1);
        };
        class TransportItems {
            ITEM_XX(efak_IFAK_2,1);
        };
    };
    class CLASS(SOSE_AA_Predef): CLASS(SOSE_Rucksack) {
        SCOPE_HIDDEN;
        class TransportMagazines {
            MAG_XX(OLI_40Rnd_762x51_Mag,6);
            MAG_XX(MEU_SPKR108_SAM_AA,1);
            MAG_XX(OPTRE_M9_Frag,1);
        };
        class TransportItems {
            ITEM_XX(efak_IFAK_2,1);
        };
    };
    class CLASS(SOSE_LMG_Predef): CLASS(SOSE_Rucksack) {
        SCOPE_HIDDEN;
        class TransportMagazines {
            MAG_XX(OLI_400Rnd_95x40_Box,1);
            MAG_XX(OPTRE_M9_Frag,1);
        };
        class TransportItems {
            ITEM_XX(efak_IFAK_2,1);
        };
    };
    class CLASS(SOSE_Officer_Predef): CLASS(SOSE_Rucksack) {
        SCOPE_HIDDEN;
        class TransportMagazines {
            MAG_XX(OLI_20Rnd_95xVX2_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M9_Frag,1);
        };
        class TransportItems {
            ITEM_XX(efak_IFAK_2,1);
            ITEM_XX(acex_intelitems_notepad,1);
        };
    };

    ////////////////////Vehicles - Type 142////////////////////
    class TKE_Paladin_Unarmed;
    class TKE_Paladin_Autocannon;
    class TKE_Paladin_AutocannonXLR;
    class TKE_Paladin_Arty;
    class TKE_Paladin_SPAAG;
    class CLASS(SOSE_Type142_APC): TKE_Paladin_Unarmed {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[Sosei] Type 142 APC";
        faction = QFACTION(SOSE);
        side = BLUFOR;
        editorSubcategory = QEDSUBCAT(SOSE_Armoured);
        crew = QCLASS(SOSE_Rifleman);
        typicalCargo[] = {QCLASS(SOSE_Rifleman)};
        textureList[] = {};
        hiddenSelectionsTextures[] = {
            QPATHTOF(sosei\data\textures\type142\SOSE_APC_Hull_co.paa)
        };
    };
    class CLASS(SOSE_Type142_IFV): TKE_Paladin_Autocannon {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[Sosei] Type 142 IFV";
        faction = QFACTION(SOSE);
        side = BLUFOR;
        editorSubcategory = QEDSUBCAT(SOSE_Armoured);
        crew = QCLASS(SOSE_Rifleman);
        typicalCargo[] = {QCLASS(SOSE_Rifleman)};
        textureList[] = {};
        hiddenSelectionsTextures[] = {
            QPATHTOF(sosei\data\textures\type142\SOSE_APC_Hull_co.paa),
            QPATHTOF(sosei\data\textures\type142\SOSE_APC_Turret40mm_co.paa)
        };
    };
    class CLASS(SOSE_Type142_IFV_XLR): TKE_Paladin_AutocannonXLR {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[Sosei] Type 142 IFV/XLR";
        faction = QFACTION(SOSE);
        side = BLUFOR;
        editorSubcategory = QEDSUBCAT(SOSE_Armoured);
        crew = QCLASS(SOSE_Rifleman);
        typicalCargo[] = {QCLASS(SOSE_Rifleman)};
        textureList[] = {};
        hiddenSelectionsTextures[] = {
            QPATHTOF(sosei\data\textures\type142\SOSE_APC_Hull_co.paa),
            QPATHTOF(sosei\data\textures\type142\SOSE_APC_Turret40mm_co.paa)
        };
    };
    class CLASS(SOSE_Type142_SPG): TKE_Paladin_Arty {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[Sosei] Type 142 SPG";
        faction = QFACTION(SOSE);
        side = BLUFOR;
        editorSubcategory = QEDSUBCAT(SOSE_Armoured);
        crew = QCLASS(SOSE_Rifleman);
        typicalCargo[] = {QCLASS(SOSE_Rifleman)};
        textureList[] = {};
        hiddenSelectionsTextures[] = {
            QPATHTOF(sosei\data\textures\type142\SOSE_APC_Hull_co.paa),
            QPATHTOF(sosei\data\textures\type142\SOSE_APC_TurretMortar_co.paa)
        };
    };
    class CLASS(SOSE_Type142_AA): TKE_Paladin_SPAAG {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[Sosei] Type 142 AA";
        faction = QFACTION(SOSE);
        side = BLUFOR;
        editorSubcategory = QEDSUBCAT(SOSE_Armoured);
        crew = QCLASS(SOSE_Rifleman);
        typicalCargo[] = {QCLASS(SOSE_Rifleman)};
        textureList[] = {};
        hiddenSelectionsTextures[] = {
            QPATHTOF(sosei\data\textures\type142\SOSE_APC_Hull_co.paa),
            QPATHTOF(sosei\data\textures\type142\SOSE_APC_TurretMortar_co.paa)
        };
    };
};
