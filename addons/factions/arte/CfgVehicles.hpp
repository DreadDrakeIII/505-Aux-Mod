class CfgVehicles {
    class CLASS(OPFOR_Unit_Base);
    class CLASS(Wolf_Unit_Base): CLASS(OPFOR_Unit_Base) {
        SCOPE_HIDDEN;
        faction = QFACTION(ARTE);

        genericNames = QCLASS(Wolf_Soldier);
        modelSides[] = {ALL_SIDES};
        editorSubcategory = QEDSUBCAT(Wolf_INF);

        items[] = {
            ITEM_20("ACE+elasticBandage"),
            ITEM_4("ACE_tourniquet"),
            "FirstAidKit"
        };
        respawnItems[] = {
            ITEM_20("ACE+elasticBandage"),
            ITEM_4("ACE_tourniquet"),
            "FirstAidKit"
        };
        model = "\A3\Characters_F_Beta\INDEP\ia_soldier_01.p3d";
        uniformClass = QCLASS(Wolf_Uniform);
        hiddenSelections[] = {"Camo","insignia"};
        hiddenSelectionsTextures[] = {"\TKE_BDU\Textures\MDTFsweater.paa"};
    };
    class CLASS(Jager_Unit_Base): CLASS(OPFOR_Unit_Base) {
        SCOPE_HIDDEN;
        faction = QFACTION(ARTE);

        genericNames = QCLASS(Jager_Soldier);
        modelSides[] = {ALL_SIDES};
        editorSubcategory = QEDSUBCAT(Jager_INF);

        items[] = {
            ITEM_20("ACE+elasticBandage"),
            ITEM_4("ACE_tourniquet"),
            "FirstAidKit"
        };
        respawnItems[] = {
            ITEM_20("ACE+elasticBandage"),
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
            ITEM_20("ACE+elasticBandage"),
            ITEM_4("ACE_tourniquet"),
            "FirstAidKit"
        };
        respawnItems[] = {
            ITEM_20("ACE+elasticBandage"),
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

};
