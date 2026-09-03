class CfgVehicles {
    /////////////////////Base Unit/////////////////////
    class CLASS(OPFOR_Unit_Base);
    class CLASS(IRON_Unit_Base): CLASS(OPFOR_Unit_Base) {
        SCOPE_HIDDEN;

        author = AUTHOR;
        faction = QFACTION(IRON);
        side = OPFOR;

        genericNames = QCLASS(IRON_Operator);
        editorSubcategory = QEDSUBCAT(IRON_INF);
        modelSides[] = {OPFOR};

        model = "\A3\Characters_F_Beta\INDEP\ia_soldier_01.p3d";
        uniformClass = QCLASS(IRON_Uniform);
        hiddenSelections[] = {"camo","insignia"};
        // TODO: retexture - add a .paa under data\textures\ and set hiddenSelectionsTextures here.

        items[] = {IRON_MEDICAL_ITEMS};
        respawnItems[] = {IRON_MEDICAL_ITEMS};

        linkedItems[] = {QCLASS(IRON_Cap), QCLASS(IRON_Vest), IRON_LINKED_ITEMS};
        respawnLinkedItems[] = {QCLASS(IRON_Cap), QCLASS(IRON_Vest), IRON_LINKED_ITEMS};
    };

    ///////////////////Infantry Roles//////////////////
    class CLASS(IRON_Unit_Rifleman): CLASS(IRON_Unit_Base) {
        SCOPE_HIDDEN;
        displayName = "IRON 01 Operator [Rifleman]";

        weapons[] = {"OLI_MA37", "OLI_M6C", "Throw", "Put"};
        respawnWeapons[] = {"OLI_MA37", "OLI_M6C", "Throw", "Put"};

        magazines[] = {"OLI_40Rnd_762x51_Mag", "OLI_12Rnd_127x40_Mag"};
        respawnMagazines[] = {"OLI_40Rnd_762x51_Mag", "OLI_12Rnd_127x40_Mag"};

        backpack = QCLASS(IRON_Backpack_Predef);
    };

    class CLASS(IRON_Unit_SL): CLASS(IRON_Unit_Rifleman) {
        displayName = "IRON 02 Operator [Team Leader]";
        icon = "iconManLeader";

        weapons[] = {"OLI_BR55HB", "OLI_M6G", "Throw", "Put"};
        respawnWeapons[] = {"OLI_BR55HB", "OLI_M6G", "Throw", "Put"};

        magazines[] = {"OLI_36Rnd_95x40_Mag", "OLI_8Rnd_127x40_Mag"};
        respawnMagazines[] = {"OLI_36Rnd_95x40_Mag", "OLI_8Rnd_127x40_Mag"};

        linkedItems[] = {QCLASS(IRON_Boonie), QCLASS(IRON_Vest_Heavy), IRON_LINKED_ITEMS};
        respawnLinkedItems[] = {QCLASS(IRON_Boonie), QCLASS(IRON_Vest_Heavy), IRON_LINKED_ITEMS};
    };

    class CLASS(IRON_Unit_Autorifleman): CLASS(IRON_Unit_Rifleman) {
        displayName = "IRON 03 Operator [Autorifleman]";
        icon = "iconManMG";

        weapons[] = {"OLI_M73", "OLI_M6C", "Throw", "Put"};
        respawnWeapons[] = {"OLI_M73", "OLI_M6C", "Throw", "Put"};

        magazines[] = {"OLI_100Rnd_95x40_Box", "OLI_12Rnd_127x40_Mag"};
        respawnMagazines[] = {"OLI_100Rnd_95x40_Box", "OLI_12Rnd_127x40_Mag"};

        linkedItems[] = {QCLASS(IRON_Cap), QCLASS(IRON_Vest_Heavy), IRON_LINKED_ITEMS};
        respawnLinkedItems[] = {QCLASS(IRON_Cap), QCLASS(IRON_Vest_Heavy), IRON_LINKED_ITEMS};
        backpack = QCLASS(IRON_Backpack_AR);
    };

    class CLASS(IRON_Unit_Marksman): CLASS(IRON_Unit_Rifleman) {
        displayName = "IRON 04 Operator [Marksman]";

        weapons[] = {"OLI_MR10_LONGBOW", "OLI_M6C", "Throw", "Put"};
        respawnWeapons[] = {"OLI_MR10_LONGBOW", "OLI_M6C", "Throw", "Put"};

        magazines[] = {"OLI_15Rnd_95xVX2_Mag", "OLI_12Rnd_127x40_Mag"};
        respawnMagazines[] = {"OLI_15Rnd_95xVX2_Mag", "OLI_12Rnd_127x40_Mag"};

        linkedItems[] = {QCLASS(IRON_Boonie), QCLASS(IRON_Vest), IRON_LINKED_ITEMS};
        respawnLinkedItems[] = {QCLASS(IRON_Boonie), QCLASS(IRON_Vest), IRON_LINKED_ITEMS};
        backpack = QCLASS(IRON_Backpack_Marksman);
    };

    class CLASS(IRON_Unit_AT): CLASS(IRON_Unit_Rifleman) {
        displayName = "IRON 05 Operator [Anti-Tank]";
        icon = "iconManAT";

        weapons[] = {"OLI_MA37", "OLI_M6C", "OLI_M20_Lawbringer", "Throw", "Put"};
        respawnWeapons[] = {"OLI_MA37", "OLI_M6C", "OLI_M20_Lawbringer", "Throw", "Put"};

        magazines[] = {"OLI_40Rnd_762x51_Mag", "OLI_12Rnd_127x40_Mag", "MRAWS_HEAT_F"};
        respawnMagazines[] = {"OLI_40Rnd_762x51_Mag", "OLI_12Rnd_127x40_Mag", "MRAWS_HEAT_F"};

        linkedItems[] = {QCLASS(IRON_Cap), QCLASS(IRON_Vest_Heavy), IRON_LINKED_ITEMS};
        respawnLinkedItems[] = {QCLASS(IRON_Cap), QCLASS(IRON_Vest_Heavy), IRON_LINKED_ITEMS};
        backpack = QCLASS(IRON_Backpack_AT);
    };

    class CLASS(IRON_Unit_Medic): CLASS(IRON_Unit_Rifleman) {
        displayName = "IRON 06 Operator [Medic]";
        icon = "iconManMedic";
        attendant = 1;

        weapons[] = {"OLI_M7_Caseless", "OLI_M6C", "Throw", "Put"};
        respawnWeapons[] = {"OLI_M7_Caseless", "OLI_M6C", "Throw", "Put"};

        magazines[] = {"OLI_60Rnd_5x23_Mag", "OLI_12Rnd_127x40_Mag"};
        respawnMagazines[] = {"OLI_60Rnd_5x23_Mag", "OLI_12Rnd_127x40_Mag"};

        backpack = QCLASS(IRON_Backpack_Medic);
    };

    /////////////////////Backpacks/////////////////////
    class B_FieldPack_oli;
    class CLASS(IRON_Backpack): B_FieldPack_oli {
        SCOPE_HIDDEN;

        author = AUTHOR;
        displayName = "[IRON] Ironveil Field Pack";
        hiddenSelections[] = {"camo"};
        // TODO: retexture - add a .paa under data\textures\ and set hiddenSelectionsTextures here.

        class TransportMagazines {};
        class TransportItems {};
        class TransportWeapons {};
    };

    class CLASS(IRON_Backpack_Predef): CLASS(IRON_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_40Rnd_762x51_Mag,6);
            MAG_XX(OLI_12Rnd_127x40_Mag,2);
            MAG_XX(OPTRE_M9_Frag,2);
            MAG_XX(OPTRE_M2_Smoke,2);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,20);
            ITEM_XX(ACE_tourniquet,2);
        };
    };

    class CLASS(IRON_Backpack_AR): CLASS(IRON_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_100Rnd_95x40_Box,4);
            MAG_XX(OLI_12Rnd_127x40_Mag,2);
            MAG_XX(OPTRE_M2_Smoke,2);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,20);
            ITEM_XX(ACE_tourniquet,2);
        };
    };

    class CLASS(IRON_Backpack_Marksman): CLASS(IRON_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_15Rnd_95xVX2_Mag,8);
            MAG_XX(OLI_12Rnd_127x40_Mag,2);
            MAG_XX(OPTRE_M2_Smoke,2);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,20);
            ITEM_XX(ACE_tourniquet,2);
        };
    };

    class CLASS(IRON_Backpack_AT): CLASS(IRON_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_40Rnd_762x51_Mag,4);
            MAG_XX(MRAWS_HEAT_F,2);
            MAG_XX(OPTRE_M2_Smoke,2);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,20);
            ITEM_XX(ACE_tourniquet,2);
        };
    };

    class CLASS(IRON_Backpack_Medic): CLASS(IRON_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_60Rnd_5x23_Mag,6);
            MAG_XX(OLI_12Rnd_127x40_Mag,2);
            MAG_XX(OPTRE_M2_Smoke,2);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(ACE_packingBandage,30);
            ITEM_XX(ACE_tourniquet,6);
            ITEM_XX(ACE_morphine,10);
            ITEM_XX(ACE_epinephrine,10);
            ITEM_XX(ACE_salineIV,6);
        };
    };
};
