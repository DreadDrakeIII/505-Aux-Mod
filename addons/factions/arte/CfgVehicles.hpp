class CfgVehicles {

    //======================================================================
    // INFANTRY  -  Wolf line troops and Jager special forces
    //======================================================================
    class CLASS(OPFOR_Unit_Base);
    class CLASS(Wolf_Unit_Base): CLASS(OPFOR_Unit_Base) {
        SCOPE_HIDDEN;
        faction = QFACTION(ARTE);

        genericNames = QCLASS(Wolf_Soldier);
        modelSides[] = {ALL_SIDES};
        editorSubcategory = QEDSUBCAT(Wolf_INF);

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
        model = "\A3\Characters_F_Beta\INDEP\ia_soldier_01.p3d";
        uniformClass = QCLASS(Wolf_Uniform);
        hiddenSelections[] = {"Camo","insignia"};
    };
    class CLASS(Jager_Unit_Base): CLASS(OPFOR_Unit_Base) {
        SCOPE_HIDDEN;
        faction = QFACTION(ARTE);

        genericNames = QCLASS(Jager_Soldier);
        modelSides[] = {ALL_SIDES};
        editorSubcategory = QEDSUBCAT(Jager_INF);

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
        model = "\TKE_Kuiper_Engagements\TKE_Rogue_Uniform\TKE_Rogue_UniformRolled.p3d";
        uniformClass = QCLASS(Jager_Rolled_Uniform);
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {"TKE_Kuiper_Engagements\TKE_Rogue_Uniform\data\TKE_Rogue_Uni_pantsArmy_co.paa","TKE_Kuiper_Engagements\TKE_Rogue_Uniform\data\TKE_Rogue_RolledUniArmy_co.paa"};
    };
    class CLASS(Jager_Unit_02_Base): CLASS(OPFOR_Unit_Base) {
        SCOPE_HIDDEN;
        faction = QFACTION(ARTE);

        genericNames = QCLASS(Jager_Soldier);
        modelSides[] = {ALL_SIDES};
        editorSubcategory = QEDSUBCAT(Jager_INF);

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
        model = "\TKE_Kuiper_Engagements\TKE_Rogue_Uniform\TKE_Rogue_Uniform.p3d";
        uniformClass = QCLASS(Jager_Uniform);
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {"TKE_Kuiper_Engagements\TKE_Rogue_Uniform\data\TKE_Rogue_Uni_pantsArmy_co.paa","TKE_Kuiper_Engagements\TKE_Rogue_Uniform\data\TKE_Rogue_RolledUniArmy_co.paa"};
    };
    /////////////////////Wolf//////////////////////////
    class CLASS(Wolf_Rifleman): CLASS(Wolf_Unit_Base) {
        SCOPE_PUBLIC;

        displayName = "INF 01 Rifleman";

        weapons[] = {
            "arifle_CTAR_ghex_F",
            "TKE_MDPistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            "arifle_CTAR_ghex_F",
            "TKE_MDPistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };

        linkedItems[] = {QCLASS(Wolf_Cap), "V_CarrierRigKBT_01_light_Olive_F", "ACE_NVG_Wide_Green", "G_Bandanna_blk", LINKED_ITEMS_RADIO};
        respawnLinkedItems[] = {QCLASS(Wolf_Cap), "V_CarrierRigKBT_01_light_Olive_F", "ACE_NVG_Wide_Green", "G_Bandanna_blk", LINKED_ITEMS_RADIO};
        backpack = QCLASS(Wolf_Rifleman_Predef);
    };
    class CLASS(Wolf_Marksman): CLASS(Wolf_Rifleman) {
        SCOPE_PUBLIC;

        displayName = "INF 02 Marksman";

        weapons[] = {
            "srifle_DMR_07_ghex_F",
            "TKE_MDPistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            "srifle_DMR_07_ghex_F",
            "TKE_MDPistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };

        linkedItems[] = {
            QCLASS(Wolf_Boonie), "V_SmershVest_01_F", "ACE_NVG_Wide_Green", "G_Bandanna_blk", LINKED_ITEMS_RADIO
        };
        respawnLinkedItems[] = {
            QCLASS(Wolf_Boonie), "V_SmershVest_01_F", "ACE_NVG_Wide_Green", "G_Bandanna_blk", LINKED_ITEMS_RADIO
        };
        backpack = QCLASS(Wolf_Marksman_Predef);
    };
    class CLASS(Wolf_AT): CLASS(Wolf_Rifleman) {
        SCOPE_PUBLIC;

        displayName = "INF 03 Rifleman (AT)";

        weapons[] = {
            "arifle_CTAR_ghex_F",
            "TKE_MDPistol",
            "OPTRE_M41_SSR",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            "arifle_CTAR_ghex_F",
            "TKE_MDPistol",
            "OPTRE_M41_SSR",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };

        linkedItems[] = {
            QCLASS(Wolf_Cap), "V_CarrierRigKBT_01_light_Olive_F", "ACE_NVG_Wide_Green", "G_Bandanna_blk", LINKED_ITEMS_RADIO
        };
        respawnLinkedItems[] = {
            QCLASS(Wolf_Cap), "V_CarrierRigKBT_01_light_Olive_F", "ACE_NVG_Wide_Green", "G_Bandanna_blk", LINKED_ITEMS_RADIO
        };
        backpack = QCLASS(Wolf_AT_Predef);
    };
    class CLASS(Wolf_AA): CLASS(Wolf_Rifleman) {
        SCOPE_PUBLIC;

        displayName = "INF 04 Rifleman (AA)";

        weapons[] = {
            "arifle_CTAR_ghex_F",
            "TKE_MDPistol",
            "launch_B_Titan_tna_F",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            "arifle_CTAR_ghex_F",
            "TKE_MDPistol",
            "launch_B_Titan_tna_F",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };

        linkedItems[] = {
            QCLASS(Wolf_Cap), "V_CarrierRigKBT_01_light_Olive_F", "ACE_NVG_Wide_Green", "G_Bandanna_blk", LINKED_ITEMS_RADIO
        };
        respawnLinkedItems[] = {
            QCLASS(Wolf_Cap), "V_CarrierRigKBT_01_light_Olive_F", "ACE_NVG_Wide_Green", "G_Bandanna_blk", LINKED_ITEMS_RADIO
        };
        backpack = QCLASS(Wolf_AA_Predef);
    };
    class CLASS(Wolf_Grenadier): CLASS(Wolf_Rifleman) {
        SCOPE_PUBLIC;

        displayName = "INF 05 Grenadier";

        weapons[] = {
            "arifle_AK12_GL_lush_F",
            "TKE_MDPistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            "arifle_AK12_GL_lush_F",
            "TKE_MDPistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };

        linkedItems[] = {
            QCLASS(Wolf_Cap), "V_SmershVest_01_F", "ACE_NVG_Wide_Green", "G_Bandanna_blk", LINKED_ITEMS_RADIO
        };
        respawnLinkedItems[] = {
            QCLASS(Wolf_Cap), "V_SmershVest_01_F", "ACE_NVG_Wide_Green", "G_Bandanna_blk", LINKED_ITEMS_RADIO
        };
        backpack = QCLASS(Wolf_Grenadier_Predef);
    };
    ////////////////////Jaeger/////////////////////////
    class CLASS(Jager_Rifleman): CLASS(Jager_Unit_Base) {
        SCOPE_PUBLIC;

        displayName = "SF 01 Rifleman";

        weapons[] = {
            "TKE_ARX12FCF",
            "WBK_SciFi_Pistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            "TKE_ARX12FCF",
            "WBK_SciFi_Pistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };

        linkedItems[] = {
            QCLASS(Jager_Helmet_01), "TKE_UCMCArmour6_2Camo2", "TKE_UCMCNvgCamo2", "G_Balaclava_TI_blk_F", LINKED_ITEMS_RADIO
        };
        respawnLinkedItems[] = {
            QCLASS(Jager_Helmet_01), "TKE_UCMCArmour6_2Camo2", "TKE_UCMCNvgCamo2", "G_Balaclava_TI_blk_F", LINKED_ITEMS_RADIO
        };
        backpack = QCLASS(Jager_Rifleman_Predef);
    };
    class CLASS(Jager_AT): CLASS(Jager_Rifleman) {
        SCOPE_PUBLIC;

        displayName = "SF 02 Rifleman (AT)";

        weapons[] = {
            "TKE_ARX12FCF",
            "WBK_SciFi_Pistol",
            "MEU_M57_Pilum_blk",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            "TKE_ARX12FCF",
            "WBK_SciFi_Pistol",
            "MEU_M57_Pilum_blk,",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };

        linkedItems[] = {
            QCLASS(Jager_Helmet_01), "TKE_UCMCArmour6_2Camo2", "TKE_UCMCNvgCamo2", "G_Balaclava_TI_blk_F", LINKED_ITEMS_RADIO
        };
        respawnLinkedItems[] = {
            QCLASS(Jager_Helmet_01), "TKE_UCMCArmour6_2Camo2", "TKE_UCMCNvgCamo2", "G_Balaclava_TI_blk_F", LINKED_ITEMS_RADIO
        };
        backpack = QCLASS(Jager_AT_Predef);
    };
    class CLASS(Jager_LMG): CLASS(Jager_Unit_Base) {
        SCOPE_PUBLIC;

        displayName = "SF 03 Light MG";

        weapons[] = {
            "TKE_UCNMMG",
            "WBK_SciFi_Pistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            "TKE_UCNMMG",
            "WBK_SciFi_Pistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };

        linkedItems[] = {
            QCLASS(Jager_Helmet_01), "TKE_UCMCArmour6_2Camo2", "TKE_UCMCNvgCamo2", "G_Balaclava_TI_blk_F", LINKED_ITEMS_RADIO
        };
        respawnLinkedItems[] = {
            QCLASS(Jager_Helmet_01), "TKE_UCMCArmour6_2Camo2", "TKE_UCMCNvgCamo2", "G_Balaclava_TI_blk_F", LINKED_ITEMS_RADIO
        };
        backpack = QCLASS(Jager_LMG_Predef);
    };
    class CLASS(Jager_Sniper): CLASS(Jager_Unit_02_Base) {
        SCOPE_PUBLIC;

        displayName = "SF 04 Sniper";

        weapons[] = {
            "OPTRE_SRM77_S1",
            "WBK_SciFi_Pistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            "OPTRE_SRM77_S1",
            "WBK_SciFi_Pistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };

        linkedItems[] = {
            QCLASS(Jager_Helmet_02), "TKE_UCMCArmour6_3ArmyV3", "TKE_UCMCNvgCamo2", "G_Balaclava_TI_blk_F", LINKED_ITEMS_RADIO
        };
        respawnLinkedItems[] = {
            QCLASS(Jager_Helmet_02), "TKE_UCMCArmour6_3ArmyV3", "TKE_UCMCNvgCamo2", "G_Balaclava_TI_blk_F", LINKED_ITEMS_RADIO
        };
        backpack = QCLASS(Jager_Sniper_Predef);
    };
    class CLASS(Jager_Bismark): CLASS(Jager_Unit_Base) {
        SCOPE_PUBLIC;

        displayName = "SF 05 Bismark Trooper";

        weapons[] = {
            "WRS_Weapon_LMG",
            "WBK_SciFi_Pistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };
        respawnWeapons[] = {
            "WRS_Weapon_LMG",
            "WBK_SciFi_Pistol",
            "OPTRE_Smartfinder",
            "Throw",
            "Put"
        };

        linkedItems[] = {
            QCLASS(Jager_Helmet_03), "TKE_UCMCArmour2_1Camo2", "TKE_UCMCNvgCamo2", "G_Balaclava_TI_blk_F", LINKED_ITEMS_RADIO
        };
        respawnLinkedItems[] = {
            QCLASS(Jager_Helmet_03), "TKE_UCMCArmour2_1Camo2", "TKE_UCMCNvgCamo2", "G_Balaclava_TI_blk_F", LINKED_ITEMS_RADIO
        };
        backpack = QCLASS(Jager_Bismark_Predef);
    };
    ///////////////////Backpack////////////////////////
    class B_FieldPack_oli;
    class TKE_AlicePackUCNArmy;
    class CLASS(Wolf_Backpack): B_FieldPack_oli {
        SCOPE_PUBLIC;

        displayName = "[ARTE] Wolf Backpack";
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Gorod";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {
            "\A3\weapons_f\ammoboxes\bags\data\backpack_gorod_oli_co.paa"
        };
    };
    class CLASS(Jager_Backpack): TKE_AlicePackUCNArmy {
        SCOPE_PUBLIC;

        displayName = "[ARTE] Jager Backpack";
        model = "\TKE_Kuiper_Engagements\TKE_MD\TKE_AlicePackUCN.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {
            "\TKE_Kuiper_Engagements\TKE_MD\data\TKE_AlicePackUCNArmy_co.paa"
        };
    };
    class CLASS(Wolf_Rifleman_Predef): CLASS(Wolf_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(30Rnd_580x42_Mag_F,10);
            MAG_XX(TKE_MDPistol_mag,12);
            MAG_XX(OPTRE_M9_Frag,4);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(Laserbatteries,1);
        };
    };
    class CLASS(Wolf_AT_Predef): CLASS(Wolf_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(30Rnd_580x42_Mag_F,10);
            MAG_XX(TKE_MDPistol_mag,12);
            MAG_XX(OPTRE_M41_Twin_HEAT,2);
            MAG_XX(OPTRE_M9_Frag,4);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(Laserbatteries,1);
        };
    };
    class CLASS(Wolf_AA_Predef): CLASS(Wolf_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(30Rnd_580x42_Mag_F,10);
            MAG_XX(TKE_MDPistol_mag,12);
            MAG_XX(ace_missile_manpad_stinger_man,1);
            MAG_XX(OPTRE_M9_Frag,4);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(Laserbatteries,1);
        };
    };
    class CLASS(Wolf_Marksman_Predef): CLASS(Wolf_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(20Rnd_650x39_Cased_Mag_F,10);
            MAG_XX(TKE_MDPistol_mag,5);
            MAG_XX(OPTRE_M9_Frag,4);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(Laserbatteries,1);
        };
    };
    class CLASS(Wolf_Grenadier_Predef): CLASS(Wolf_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(30Rnd_762x39_AK12_Mag_F,10);
            MAG_XX(1Rnd_HE_Grenade_shell,9);
            MAG_XX(TKE_MDPistol_mag,5);
            MAG_XX(OPTRE_M9_Frag,4);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(Laserbatteries,1);
        };
    };
    class CLASS(Jager_Rifleman_Predef): CLASS(Jager_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(TKE_ARX12_62x35_mag,10);
            MAG_XX(WRS_Puma_Magazine,5);
            MAG_XX(OPTRE_M9_Frag,3);
            MAG_XX(KAT_M7A3,3);
            MAG_XX(ACE_M84,3);
            MAG_XX(Chemlight_red,2);
            MAG_XX(SmokeShellRed,1);
            MAG_XX(SmokeShell,1);
            MAG_XX(Laserbatteries,1);
        };
    };
    class CLASS(Jager_AT_Predef): CLASS(Jager_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(TKE_ARX12_62x35_mag,10);
            MAG_XX(WRS_Puma_Magazine,5);
            MAG_XX(MEU_M57_Pilum_HEAT_Mag,2);
            MAG_XX(OPTRE_M9_Frag,3);
            MAG_XX(KAT_M7A3,3);
            MAG_XX(ACE_M84,3);
            MAG_XX(Chemlight_red,2);
            MAG_XX(SmokeShellRed,1);
            MAG_XX(SmokeShell,1);
            MAG_XX(Laserbatteries,1);
        };
    };
    class CLASS(Jager_LMG_Predef): CLASS(Jager_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(TKE_100rnd_ucnmmg_mag,10);
            MAG_XX(WRS_Puma_Magazine,5);
            MAG_XX(OPTRE_M9_Frag,3);
            MAG_XX(KAT_M7A3,3);
            MAG_XX(ACE_M84,3);
            MAG_XX(Chemlight_red,2);
            MAG_XX(SmokeShellRed,1);
            MAG_XX(SmokeShell,1);
            MAG_XX(Laserbatteries,1);
        };
    };
    class CLASS(Jager_Sniper_Predef): CLASS(Jager_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OPTRE_10Rnd_127x99_noTracer,10);
            MAG_XX(WRS_Puma_Magazine,5);
            MAG_XX(OPTRE_M9_Frag,3);
            MAG_XX(KAT_M7A3,3);
            MAG_XX(ACE_M84,3);
            MAG_XX(Chemlight_red,2);
            MAG_XX(SmokeShellRed,1);
            MAG_XX(SmokeShell,1);
            MAG_XX(Laserbatteries,1);
        };
    };
    class CLASS(Jager_Bismark_Predef): CLASS(Jager_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(200Rnd_556x45_Box_Tracer_F,5);
            MAG_XX(WRS_Puma_Magazine,5);
            MAG_XX(OPTRE_M9_Frag,3);
            MAG_XX(KAT_M7A3,3);
            MAG_XX(ACE_M84,3);
            MAG_XX(Chemlight_red,2);
            MAG_XX(SmokeShellRed,1);
            MAG_XX(SmokeShell,1);
            MAG_XX(Laserbatteries,1);
        };
    };


    //=====================
    // VEHICLES
    //=====================

    //=====================
    // MULE
    //=====================
    class OPTRE_m1015_mule_ins;
    class OPTRE_m1015_mule_cover_ins;
    class OPTRE_m1015_mule_mlr_ins;
    class OPTRE_m1015_mule_ammo_ins;
    class OPTRE_m1015_mule_fuel_ins;
    class OPTRE_m1015_mule_medical_ins;
    class OPTRE_m1015_mule_repair_ins;
    class CLASS(Mule_Transport): OPTRE_m1015_mule_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(arte\data\mule\Artemis_Mule_Cab_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_Kuz_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_Interior_co.paa),
        };
    };
    class CLASS(Mule_Covered): OPTRE_m1015_mule_cover_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule (Covered)";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3",};
        hiddenSelectionsTextures[] = {
            QPATHTOF(arte\data\mule\Artemis_Mule_Cab_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_Kuz_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_Interior_co.paa),
        };
    };

    class CLASS(Mule_MRL): OPTRE_m1015_mule_mlr_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule (MLR)";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(arte\data\mule\Artemis_Mule_Cab_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_Interior_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_MRL_co.paa),
        };
    };

    class CLASS(Mule_Ammo): OPTRE_m1015_mule_ammo_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule (Ammo)";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(arte\data\mule\Artemis_Mule_Cab_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_Repair_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_Interior_co.paa),
        };
    };

    class CLASS(Mule_Fuel): OPTRE_m1015_mule_fuel_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule (Fuel)";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(arte\data\mule\Artemis_Mule_Cab_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_Fuel_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_Interior_co.paa),
        };
    };

    class CLASS(Mule_Medical): OPTRE_m1015_mule_medical_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule (Medical)";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(arte\data\mule\Artemis_Mule_Cab_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_Kuz_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_Interior_co.paa),
        };
    };

    class CLASS(Mule_Repair): OPTRE_m1015_mule_repair_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule (Repair)";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(arte\data\mule\Artemis_Mule_Cab_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_Repair_co.paa),
            QPATHTOF(arte\data\mule\Artemis_Mule_Interior_co.paa),
        };
    };

    //===============================
    // WARTHOG
    //===============================
    class OPTRE_M12_LRV_ins;
    class CLASS(ARTE_Warthog_LRV): OPTRE_M12_LRV_ins {
        SCOPE_PUBLIC;

        displayName = "M12 LAAG Warthog";
        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Wolf_Rifleman);
        typicalCargo[] = {QCLASS(Wolf_Rifleman)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "camo_details",
            "camo_interior",
            "camo_turret_decal",
            "camo_sight",
            "camo_doors"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(arte\data\warthog\Artemis_M12HogMaav_extupper_co.paa),
            "\OPTRE_Vehicles\Warthog\data\night\M12HogMaav_extunder_night_co.paa",
            QPATHTOF(arte\data\warthog\Artemis_m12_turret_co.paa),
            "",
            "\OPTRE_Vehicles\warthog\data\m12hogmaav_interior_co.paa",
            "",
            "\OPTRE_Vehicles\warthog\data\turrets\sight_co.paa",
            ""
        };
    };

    class OPTRE_M12A1_LRV_ins;
    class CLASS(ARTE_Warthog_AT_LRV): OPTRE_M12A1_LRV_ins {
        SCOPE_PUBLIC;

        displayName = "M12A1 AT Warthog";
        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Wolf_Rifleman);
        typicalCargo[] = {QCLASS(Wolf_Rifleman)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "camo_details",
            "camo_interior",
            "camo_turret",
            "camo_turret_decals",
            "camo_doors"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(arte\data\warthog\Artemis_M12HogMaav_extupper_co.paa),
            "\OPTRE_Vehicles\Warthog\data\night\M12HogMaav_extunder_night_co.paa",
            QPATHTOF(arte\data\warthog\Artemis_m12_turret_co.paa),
            "",
            "\OPTRE_Vehicles\warthog\data\m12hogmaav_interior_co.paa",
            "\OPTRE_Vehicles\warthog\data\turrets\m39_turret_co.paa",
            "",
            "",
        };
    };

    class OPTRE_M12_TD_ins;
    class CLASS(ARTE_Warthog_TD_LRV): OPTRE_M12_TD_ins {
        SCOPE_PUBLIC;

        displayName = "M12 TD Warthog";
        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Wolf_Rifleman);
        typicalCargo[] = {QCLASS(Wolf_Rifleman)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "Camo4",
            "Camo5",
            "Camo6",
            "camo_details",
            "camo_interior",
            "camo_console"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(arte\data\warthog\Artemis_M12HogMaav_extupper_co.paa),
            "\OPTRE_Vehicles\Warthog\data\night\M12HogMaav_extunder_night_co.paa",
            "\OPTRE_Vehicles\Warthog\data\night\transp_lopo_night_co.paa",
            "\OPTRE_Vehicles\Warthog\data\night\hog_apc_night_co.paa",
            "\OPTRE_Weapons_Turrets\fg75\data\cannon_co.paa",
            "\OPTRE_Weapons_Turrets\fg75\data\carriage_co.paa",
            "",
            "\OPTRE_Vehicles\Warthog\data\m12hogmaav_interior_co.paa",
            "\OPTRE_Weapons_Turrets\fg75\data\console_co.paa"

        };
    };

    class OPTRE_M12R_AA_ins;
    class CLASS(ARTE_Warthog_AA): OPTRE_M12R_AA_ins {
        SCOPE_PUBLIC;

        displayName = "M12R AA Warthog";
        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Wolf_Rifleman);
        typicalCargo[] = {QCLASS(Wolf_Rifleman)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "camo_details",
            "camo_interior",
            "camo_doors"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(arte\data\warthog\Artemis_M12HogMaav_extupper_co.paa),
            "\OPTRE_Vehicles\Warthog\data\night\M12HogMaav_extunder_night_co.paa",
            QPATHTOF(arte\data\warthog\Artemis_m79_turret_co.paa),
            "",
            "\OPTRE_Vehicles\warthog\data\m12hogmaav_interior_co.paa",
            ""
        };
    };

};
