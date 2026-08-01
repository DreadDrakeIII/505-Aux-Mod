class CLASS(Backpack_CE): CLASS(Backpack_Base) {
        author = "505th Aux Team";
        displayName = "[505th] Combat Pack [Grey]";
        SCOPE_HIDDEN;
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\backpacks\505th_BackpackGrey_co.paa),QPATHTOF(data\backpacks\505th_PouchesGrey_co.paa)};
    };
    class CLASS(Backpack_CE_505): CLASS(Backpack_Base) {
        author = "505th Aux Team";
        displayName = "[505th] Combat Pack [Green]";
        SCOPE_HIDDEN;
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\backpacks\505th_Backpack_co.paa),QPATHTOF(data\backpacks\505th_Pouches_co.paa)};
    };
    class CLASS(Backpack_CE_FR): CLASS(Backpack_Base) {
        SCOPE_HIDDEN;
        author = "505th Aux Team";
        displayName = "[505th] Combat Pack [Force Recon]";
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\backpacks\FR_Backpack_co.paa),QPATHTOF(data\backpacks\FR_Pouches_co.paa)};
    };
    class CLASS(Backpack_Predef): CLASS(Backpack_CE_505) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_32Rnd_762x51_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
            MAG_XX(OPTRE_M9_Frag,4);
        };
      class TransportItems {
        ITEM_XX(ACE_elasticBandage,60);
        ITEM_XX(acex_intelitems_notepad,1);
        ITEM_XX(kat_Painkiller,5);
      };
    };
    class CLASS(Rifleman_Backpack_Predef): CLASS(Backpack_CE_505) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_32Rnd_762x51_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
            MAG_XX(OPTRE_M9_Frag,4);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };
    class CLASS(Backpack_AutoRifle_Predef): CLASS(Backpack_CE_505) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_100Rnd_95x40_Box,4);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
            MAG_XX(OPTRE_M9_Frag,4);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };
    class CLASS(Backpack_Marksman_Predef): CLASS(Backpack_CE_505) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_15Rnd_95xVX2_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
            MAG_XX(OPTRE_M9_Frag,4);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };
    class CLASS(Backpack_LAT_Predef): CLASS(Backpack_CE_505) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_32Rnd_762x51_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(MRAWS_HEAT_F,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
            MAG_XX(OPTRE_M9_Frag,4);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };
    class CLASS(Backpack_Grenadier_Predef): CLASS(Backpack_CE_505) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_32Rnd_762x51_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M9_Frag,4);
            MAG_XX(1Rnd_HE_Grenade_shell,25);
            MAG_XX(3Rnd_Smoke_Grenade_shell,4);
            MAG_XX(3Rnd_SmokeRed_Grenade_shell,4);
            MAG_XX(3Rnd_UGL_FlareWhite_F,4);
            MAG_XX(3Rnd_UGL_FlareGreen_F,1);
            MAG_XX(3Rnd_UGL_FlareRed_F,1);
            MAG_XX(3Rnd_UGL_FlareYellow_F,1);
            MAG_XX(3Rnd_UGL_FlareCIR_F,1);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };
    class CLASS(Backpack_Breacher_Predef): CLASS(Backpack_CE_505) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OPTRE_6Rnd_8Gauge_Pellets,6);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M9_Frag,4);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };
    class CLASS(BackpackLR_CE): CLASS(BackpackLR_Base) {
        author = "505th Aux Team";
        displayName = "[505th] Combat Pack LR [Grey]";
        SCOPE_HIDDEN;
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\backpacks\505th_BackpackGrey_co.paa),QPATHTOF(data\backpacks\505th_PouchesGrey_co.paa)};
    };
    class CLASS(BackpackLR_CE_505): CLASS(BackpackLR_CE) {
        author = "505th Aux Team";
        displayName = "[505th] Combat Pack LR [Green]";
        SCOPE_HIDDEN;
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\backpacks\505th_Backpack_co.paa),QPATHTOF(data\backpacks\505th_Pouches_co.paa)};
    };
    class CLASS(Backpack_LR_CE_FR): CLASS(BackpackLR_CE) {
        author = "505th Aux Team";
        displayName = "[505th] Combat Pack LR [Force Recon]";
        SCOPE_HIDDEN;
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\backpacks\FR_Backpack_co.paa),QPATHTOF(data\backpacks\FR_Pouches_co.paa)};
    };
    class CLASS(Invisible_Backpack_CE): CLASS(Backpack_Invis_Base) {
        author = "505th Aux Team";
        displayName = "[505th] Invisible Backpack";
        SCOPE_HIDDEN;
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_small_co.paa"};
    };
    class CLASS(LR_Antenna_CE): CLASS(LR_Antenna_Base) {
        author = "505th Aux Team";
        displayName = "[505th] LR Antenna";
        SCOPE_HIDDEN;
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEAntenna_co.paa"};
    };
    class CLASS(ScoutBackpack_CE): CLASS(Scout_Backpack_Base) {
        author = "505th Aux Team";
        displayName = "[505th] Scout Pack";
        SCOPE_HIDDEN;
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEBackpack_co.paa"};
    };
    class CLASS(MedicalBackpack): CLASS(Medical_Backpack_Base) {
        author = "505th Aux Team";
        displayName = "[505th] Medical Backpack";
        SCOPE_HIDDEN;
    };
    class CLASS(MedicalBackpack_Predef): CLASS(MedicalBackpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_32Rnd_762x51_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
        };

        class TransportItems {
            // Bandages
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(ACE_packingBandage,40);
            ITEM_XX(ACE_quickclot,30);

            // Fluid
            ITEM_XX(ACE_bloodIV,5);
            ITEM_XX(ACE_bloodIV_500,5);
            ITEM_XX(ACE_bloodIV_250,10);

            // Drugs
            ITEM_XX(ACE_morphine,5);
            ITEM_XX(ACE_epinephrine,5);

            // Misc
            ITEM_XX(ACE_tourniquet,12);
            ITEM_XX(ACE_Splint,4);
        };
    };
    class CLASS(Backpack_SL_PL_Predef): CLASS(BackpackLR_CE_505) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_20Rnd_95xVX2_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };
    class CLASS(Backpack_FR_Predef): CLASS(Backpack_LR_CE_FR) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_10Rnd_HDUR,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };
    class CLASS(Pilot_Backpack): CLASS(Pilot_Backpack_Base) {
        author = "505th Aux Team";
        displayName = "[505th] Pilot Pack";
        scope = 2;
        scopeCurator = 2;
        scopeArsenal = 2;
    };
    class CLASS(Pilot_Backpack_Predef): CLASS(Pilot_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_32Rnd_9x21_Mag,8);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
        };
        class TransportWeapons {
            WEAP_XX(UNSC_Knife,1);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
            ITEM_XX(ToolKit,1);
        };
    };
    class CLASS(Tanker_Backpack_Predef): CLASS(Pilot_Backpack) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_60Rnd_9x21_Mag,10);
            MAG_XX(OLI_12Rnd_9x21_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
        };
        class TransportWeapons {
            WEAP_XX(UNSC_Knife,1);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
            ITEM_XX(ToolKit,1);
        };
    };
    class CLASS(BlackOps_Backpack): CLASS(BlackOps_Backpack_Base) {
        author = "505th Aux Team";
        displayName = "[505th] Black Ops Backpack";
        scope = 0;
        scopeCurator = 0;
        scopeArsenal = 0;
    };
    class CLASS(BlackOps_Backpack_Predef): CLASS(BlackOps_Backpack_Base) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_32Rnd_95x40_Mag,20);
            MAG_XX(OLI_16Rnd_45ACP_Mag,20);
            MAG_XX(OPTRE_M9_Frag,5);
            MAG_XX(OPTRE_M2_Smoke,5);
            MAG_XX(OPTRE_M2_Smoke_Blue,5);
        };
        class TransportWeapons {
            WEAP_XX(Knife_kukri,1);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(kat_PainKiller,5);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(ACE_tourniquet,12);
        };
    };

    // ===========================================================================
    // ============================ M43 Backpacks ==================================
    // ===========================================================================
    class CLASS(M43_Rucksack_1_Olive): CLASS(M43_Rucksack_1_Olive_Base) {
        SCOPE_PUBLIC;
        author = "505th Aux Team";
        displayName = "[505th] M43 Rucksack 1 (Olive)";

    };
    class CLASS(M43_Rucksack_2_Olive): CLASS(M43_Rucksack_2_Olive_Base) {
        SCOPE_PUBLIC;
        author = "505th Aux Team";
        displayName = "[505th] M43 Rucksack 2 (Olive)";
    };
    class CLASS(M43_Rucksack_3_Olive): CLASS(M43_Rucksack_3_Olive_Base) {
        SCOPE_PUBLIC;
        author = "505th Aux Team";
        displayName = "[505th] M43 Rucksack 3 (Olive)";
    };
    class CLASS(M43_Rucksack_4_Olive): CLASS(M43_Rucksack_4_Olive_Base) {
        SCOPE_PUBLIC;
        author = "505th Aux Team";
        displayName = "[505th] M43 Rucksack 4 (Olive)";
    };
    class CLASS(M43_Rucksack_5_Olive): CLASS(M43_Rucksack_5_Olive_Base) {
        SCOPE_PUBLIC;
        author = "505th Aux Team";
        displayName = "[505th] M43 Rucksack 5 (Olive)";
    };
    class CLASS(Utility_Rig_Black): CLASS(Utility_Rig_Black_Base) {
        SCOPE_PUBLIC;
        author = "505th Aux Team";
        displayName = "[505th] Utility Rig (Black)";
    };
    class CLASS(M43A_ANPRC171_RTO_Buttpack_1_Olive): CLASS(M43A_ANPRC171_RTO_Buttpack_1_Olive_Base) {
        SCOPE_PUBLIC;
        author = "505th Aux Team";
        displayName = "[505th] M43A ANPRC171 RTO Buttpack 1 (Olive)";
    };
    class CLASS(M43A_ANPRC171_RTO_Buttpack_2_Olive): CLASS(M43A_ANPRC171_RTO_Buttpack_2_Olive_Base) {
        SCOPE_PUBLIC;
        author = "505th Aux Team";
        displayName = "[505th] M43A ANPRC171 RTO Buttpack 2 (Olive)";
    };
    class CLASS(M43A_ANPRC171_RTO_Buttpack_1_Black): CLASS(M43A_ANPRC171_RTO_Buttpack_1_Black_Base) {
        SCOPE_PUBLIC;
        author = "505th Aux Team";
        displayName = "[505th] M43A ANPRC171 RTO Buttpack 1 (Black)";
    };
    class CLASS(M43_Medic_Rucksack_Olive): CLASS(M43_Medic_Rucksack_Olive_Base) {
        SCOPE_PUBLIC;
        author = "505th Aux Team";
        displayName = "[505th] M43A Medic Rucksack (Olive)";
    };
    class CLASS(Riflemen_Predef): CLASS(M43_Rucksack_1_Olive) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_40Rnd_762x51_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
            MAG_XX(OPTRE_M9_Frag,4);
        };
      class TransportItems {
        ITEM_XX(ACE_elasticBandage,60);
        ITEM_XX(acex_intelitems_notepad,1);
        ITEM_XX(kat_Painkiller,5);
      };
    };
    class CLASS(Grenadier_Predef): CLASS(M43_Rucksack_2_Olive) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_40Rnd_762x51_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M9_Frag,4);
            MAG_XX(1Rnd_HE_Grenade_shell,25);
            MAG_XX(3Rnd_Smoke_Grenade_shell,4);
            MAG_XX(3Rnd_SmokeRed_Grenade_shell,4);
            MAG_XX(3Rnd_UGL_FlareWhite_F,4);
            MAG_XX(3Rnd_UGL_FlareGreen_F,1);
            MAG_XX(3Rnd_UGL_FlareRed_F,1);
            MAG_XX(3Rnd_UGL_FlareYellow_F,1);
            MAG_XX(3Rnd_UGL_FlareCIR_F,1);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };
    class CLASS(Autorifle_Predef): CLASS(M43_Rucksack_3_Olive) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_100Rnd_95x40_Box,4);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
            MAG_XX(OPTRE_M9_Frag,4);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };

    class CLASS(Ammobearer_Predef): CLASS(M43_Rucksack_4_Olive) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_40Rnd_762x51_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
            MAG_XX(OPTRE_M9_Frag,4);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };

    class CLASS(Rucksack_RTO_1_Predef): CLASS(M43A_ANPRC171_RTO_Buttpack_1_Olive) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_20Rnd_95xVX2_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };
    class CLASS(Rucksack_RTO_2_Predef): CLASS(M43A_ANPRC171_RTO_Buttpack_2_Olive) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_20Rnd_95xVX2_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };class CLASS(Rucksack_RTO_3_Predef): CLASS(M43A_ANPRC171_RTO_Buttpack_1_Black) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_20Rnd_95xVX2_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
        };
        class TransportItems {
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(acex_intelitems_notepad,1);
            ITEM_XX(kat_Painkiller,5);
        };
    };
    class CLASS(Medic_Ruckpack_Predef): CLASS(M43_Medic_Rucksack_Olive) {
        SCOPE_HIDDEN;

        class TransportMagazines {
            MAG_XX(OLI_32Rnd_762x51_Mag,9);
            MAG_XX(OLI_12Rnd_127x40_Mag,3);
            MAG_XX(OPTRE_M2_Smoke,4);
            MAG_XX(OPTRE_M2_Smoke_Blue,2);
        };

        class TransportItems {
            // Bandages
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(ACE_packingBandage,40);
            ITEM_XX(ACE_quickclot,30);

            // Fluid
            ITEM_XX(ACE_bloodIV,5);
            ITEM_XX(ACE_bloodIV_500,5);
            ITEM_XX(ACE_bloodIV_250,10);

            // Drugs
            ITEM_XX(ACE_morphine,5);
            ITEM_XX(ACE_epinephrine,5);

            // Misc
            ITEM_XX(ACE_tourniquet,12);
            ITEM_XX(ACE_Splint,4);
        };
    };
