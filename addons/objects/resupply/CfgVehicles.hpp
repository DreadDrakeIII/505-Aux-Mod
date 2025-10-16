class CfgVehicles {
    class ReammoBox_F;
    class TKE_Crate1R: ReammoBox_F {
    };
    class CLASS(Resupply_Base): TKE_Crate1R {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "00: Crate";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Resupply);

        ace_cargo_canLoad = TRUE;
        ace_cargo_noRename = TRUE;
        ace_cargo_size = 1;

        ace_dragging_canDrag = TRUE;
        ace_dragging_dragDirection = 0;
        ace_dragging_carryDirection = 90;
        ace_dragging_dragPosition[] = {0,1.2,0};
        ace_dragging_carryPosition[] = {0,2,0};

        ace_dragging_canCarry = TRUE;

        ace_dragging_ignoreWeight = TRUE;
        ace_dragging_ignoreWeightCarry = TRUE;
    };

    class CLASS(CE_Loadout): CLASS(Resupply_Base) {
        displayName = "CE Loadout Crate";
        model = "\TKE_Kuiper_Engagements\TKE_Props\TKE_SupplyCrate.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            "\TKE_Kuiper_Engagements\TKE_Props\data\TKE_SupplyCrate_co.paa"
        };
    };

    class CLASS(Resupply_SquadAmmo): CLASS(Resupply_Base) {
        displayName = "01: Ammo Crate (Squad)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(resupply\data\textures\Squad_Ammo_Crate_co.paa)
        };

        class TransportMagazines {
            // Primary Ammo
            MAG_XX(OPTRE_32Rnd_762x51_Mag,40);
            MAG_XX(OPTRE_36Rnd_95x40_Mag,40);
            MAG_XX(OPTRE_25Rnd_762x51_Mag,40);
            MAG_XX(DMNS_100Rnd_762x51_Mag,40);
            MAG_XX(OPTRE_100Rnd_95x40_Box,40);
            MAG_XX(OPTRE_60Rnd_5x23mm_Mag,40);
            MAG_XX(Laserbatteries,40);
            MAG_XX(OPTRE_20Rnd_86x70_Mag,40);
            MAG_XX(OPTRE_26Rnd_127x40_Mag_Tracer,40);
            MAG_XX(30Rnd_9x21_Mag_SMG_02,40);

            // UGL Ammo
            MAG_XX(1Rnd_HE_MEU_shell,20);
            MAG_XX(OPTRE_1Rnd_Smoke_Grenade_shell,20);
            MAG_XX(UGL_FlareWhite_Illumination_F,20);
            MAG_XX(UGL_FlareGreen_F,20);
            MAG_XX(UGL_FlareCIR_F,20);
            MAG_XX(UGL_FlareRed_F,20);
            MAG_XX(OPTRE_signalSmokeB,20);
            MAG_XX(OPTRE_signalSmokeG,20);
            MAG_XX(OPTRE_signalSmokeP,20);
            MAG_XX(OPTRE_signalSmokeR,20);
            MAG_XX(UGL_FlareWhite_F,20);

            // Secondary Ammo
            MAG_XX(12Rnd_127x40_m6_SAPHE,40);
            MAG_XX(OPTRE_8Rnd_127x40_Mag,40);

            // Launcher Ammo
            MAG_XX(OPTRE_1Rnd_50x137_HEAT,2);

            // Grenades
            MAG_XX(OPTRE_M9_Frag,8);
        };
    };

    class CLASS(Resupply_PlatoonAmmo): CLASS(Resupply_SquadAmmo) {
        displayName = "02: Ammo Crate (Platoon)";
        ace_cargo_size = 2;
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(resupply\data\textures\Platoon_Ammo_Crate_co.paa)
        };

        class TransportMagazines {
            // Primary Ammo
            MAG_XX(OPTRE_32Rnd_762x51_Mag,160);
            MAG_XX(OPTRE_36Rnd_95x40_Mag,160);
            MAG_XX(OPTRE_25Rnd_762x51_Mag,160);
            MAG_XX(DMNS_100Rnd_762x51_Mag,160);
            MAG_XX(OPTRE_100Rnd_95x40_Box,160);
            MAG_XX(OPTRE_60Rnd_5x23mm_Mag,160);
            MAG_XX(Laserbatteries,160);
            MAG_XX(OPTRE_20Rnd_86x70_Mag,160);

            // UGL Ammo
            MAG_XX(1Rnd_HE_MEU_shell,80);
            MAG_XX(OPTRE_1Rnd_Smoke_Grenade_shell,80);
            MAG_XX(UGL_FlareWhite_Illumination_F,80);
            MAG_XX(UGL_FlareGreen_F,80);
            MAG_XX(UGL_FlareCIR_F,80);
            MAG_XX(UGL_FlareRed_F,80);
            MAG_XX(OPTRE_signalSmokeB,80);
            MAG_XX(OPTRE_signalSmokeG,80);
            MAG_XX(OPTRE_signalSmokeP,80);
            MAG_XX(OPTRE_signalSmokeR,80);
            MAG_XX(UGL_FlareWhite_F,80);

            // Secondary Ammo
            MAG_XX(12Rnd_127x40_m6_SAPHE,160);
            MAG_XX(OPTRE_8Rnd_127x40_Mag,160);

            // Launcher Ammo
            MAG_XX(OPTRE_1Rnd_50x137_HEAT,20);

            // Grenades
            MAG_XX(OPTRE_M9_Frag,32);
        };
    };

    class CLASS(Resupply_SquadMedical): CLASS(Resupply_Base) {
        displayName = "03: Medical Crate (Squad)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(resupply\data\textures\Squad_Medical_Crate_co.paa)
        };

        class TransportItems {
            // Bandages
            ITEM_XX(ACE_elasticBandage,60);
            ITEM_XX(ACE_packingBandage,40);
            ITEM_XX(ACE_quickclot,30);
            ITEM_XX(kat_chestSeal,10);

            // Fluid
            ITEM_XX(kat_bloodIV_O_N,5);
            ITEM_XX(kat_bloodIV_O_N_500,5);
            ITEM_XX(kat_bloodIV_O_N_250,10);

            // Drugs
            ITEM_XX(ACE_morphine,5);
            ITEM_XX(ACE_epinephrine,5);
            ITEM_XX(kat_Painkiller,10);

            // Misc
            ITEM_XX(ACE_tourniquet,12);
            ITEM_XX(ACE_Splint,4);
            ITEM_XX(ACE_Banana,1);
            ITEM_XX(ItemcTab,5);
        };

        class TransportMagazines {
            MAG_XX(OPTRE_M2_Smoke_Purple,5);
        };
    };
    class CLASS(Resupply_PlatoonMedical): CLASS(Resupply_SquadMedical) {
        displayName = "04: Medical Crate (Platoon)";
        ace_cargo_size = 2;
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(resupply\data\textures\Platoon_Medical_Crate_co.paa)
        };

        class TransportItems {
            // Bandages
            ITEM_XX(ACE_elasticBandage,300);
            ITEM_XX(ACE_packingBandage,120);
            ITEM_XX(ACE_quickclot,80);
            ITEM_XX(kat_chestSeal,40);

            // Fluid
            ITEM_XX(kat_bloodIV_O_N,40);
            ITEM_XX(kat_bloodIV_O_N_500,40);
            ITEM_XX(kat_bloodIV_O_N_250,60);

            // Drugs
            ITEM_XX(ACE_morphine,26);
            ITEM_XX(ACE_epinephrine,26);
            ITEM_XX(kat_Painkiller,40);

            // Misc
            ITEM_XX(ACE_tourniquet,24);
            ITEM_XX(ACE_Splint,16);
            ITEM_XX(ItemcTab,5);
        };

        class TransportMagazines {
            MAG_XX(OPTRE_M2_Smoke_Purple,10);
        };
    };

    class CLASS(Resupply_Explosives): CLASS(Resupply_Base) {
        displayName = "05: Explosives Crate";
        ace_cargo_size = 4;
        model = "\TKE_Kuiper_Engagements\TKE_Props\TKE_SupplyCrate.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(resupply\data\textures\Explosives_Crate_co.paa)
        };

        class TransportMagazines {
            // Grenades
            MAG_XX(OPTRE_M9_Frag,64);
            MAG_XX(OPTRE_M2_Smoke,64);
            MAG_XX(OPTRE_M2_Smoke_Blue,64);
            MAG_XX(OPTRE_M2_Smoke_Green,64);
            MAG_XX(OPTRE_M2_Smoke_Orange,64);
            MAG_XX(OPTRE_M2_Smoke_Red,64);
            MAG_XX(OPTRE_M2_Smoke_Yellow,64);
        };

        class TransportItems {
            // Mines
            ITEM_XX(APERSMineDispenser_Mag,40);
            ITEM_XX(OPTRE_1Rnd_50x137_HEAT,40);
            ITEM_XX(C7_Remote_Mag,40);
            ITEM_XX(M168_Remote_Mag,40);
            ITEM_XX(ACE_M26_Clacker,10);
        };
    };

    class CLASS(Resupply_Rockets): CLASS(Resupply_Base) {
        displayName = "06: Rockets Crate";
        ace_cargo_size = 4;
        model = "\TKE_Kuiper_Engagements\TKE_Props\TKE_SupplyCrate.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            "\TKE_Kuiper_Engagements\TKE_Props\data\TKE_SupplyCrate_co.paa"
        };

        class TransportWeapons {
            // Grenades
            WEAP_XX(DMNS_M96_LAW,10);
        };
    };
};
