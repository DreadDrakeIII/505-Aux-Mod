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

    // ============================================================
    // 01: SQUAD AMMO CRATE
    // ============================================================
    class CLASS(Resupply_SquadAmmo): CLASS(Resupply_Base) {
        displayName = "01: Ammo Crate (Squad)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(resupply\data\textures\Squad_Ammo_Crate_co.paa)
        };

        class TransportMagazines {

            // ---- PRIMARY: Assault Rifles / Battle Rifles ----
            // MA37/MA37GL
            MAG_XX(CLASS(40Rnd_762x51_Mag),40);
            // LMR11 Shortbow| 7.62x51mm   | 30Rnd
            MAG_XX(CLASS(30Rnd_762x51_Mag),40);
            // VK78 Commando | 9.5xVX2     | 20Rnd
            MAG_XX(CLASS(20Rnd_95xVX2_Mag),40);
            // MR10 Longbow  | 9.5xVX2     | 15Rnd
            MAG_XX(CLASS(15Rnd_95xVX2_Mag),40);
            // BR55HB         | 7.62x51mm   | 36Rnd
            MAG_XX(CLASS(36Rnd_95x40_Mag),40);

            // ---- PRIMARY: SMGs ----
            // CPW           | 9x21mm      | 30Rnd
            MAG_XX(CLASS(30Rnd_9x21_Mag),40);
            // MPK-5         | 9x21mm      | 32Rnd
            MAG_XX(CLASS(32Rnd_9x21_Mag),40);
            // M7 Caseless   | 5x23mm      | 60Rnd
            MAG_XX(CLASS(60Rnd_5x23_Mag),40);
            // M6D Carbine   | 12.7x40mm   | 40Rnd
            MAG_XX(CLASS(40Rnd_127x40_Mag),40);

            // ---- PRIMARY: LMGs / HMGs ----
            // M73           | 9.5x40mm    | 100Rnd Box
            MAG_XX(CLASS(100Rnd_95x40_Box),40);

            // ---- PRIMARY: Sniper / Anti-Material ----

            // ---- PRIMARY: Energy Weapons ----

            // ---- SECONDARY: Pistols ----
            // M6G           | 12.7x40mm   | 8Rnd
            MAG_XX(CLASS(8Rnd_127x40_Mag),40);
            // M6C           | 12.7x40mm   | 12Rnd
            MAG_XX(CLASS(12Rnd_127x40_Mag),40);
            // MHG16         | .45 ACP     | 12Rnd
            MAG_XX(CLASS(12Rnd_45ACP_Mag),40);
            // PUMA          | .45 ACP     | 16Rnd
            MAG_XX(CLASS(16Rnd_45ACP_Mag),40);

            // ---- UGL Ammo ----
            MAG_XX(TCP_1Rnd_40_Shell_Signal_Green,20);
            MAG_XX(TCP_1Rnd_40_Shell_Signal_Red,20);
            MAG_XX(TCP_1Rnd_40_Shell_Signal_White,20);
            MAG_XX(TCP_1Rnd_40_Shell_Signal_Yellow,20);
            MAG_XX(TCP_1Rnd_40_Shell_HE,20);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_Blue,20);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_Green,20);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_Red,20);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_White,20);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_Yellow,20);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_Orange,20);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_Purple,20);
            MAG_XX(TCP_1Rnd_40_Shell_TD,20);
            MAG_XX(1Rnd_HE_Grenade_shell,20);
            MAG_XX(UGL_FlareGreen_F,20);
            MAG_XX(UGL_FlareCIR_F,20);
            MAG_XX(UGL_FlareRed_F,20);
            MAG_XX(UGL_FlareWhite_F,20);
            MAG_XX(UGL_FlareYellow_F,20);
            MAG_XX(UGL_FlareGreen_Illumination_F,20);
            MAG_XX(UGL_FlareRed_Illumination_F,20);
            MAG_XX(UGL_FlareWhite_Illumination_F,20);
            MAG_XX(UGL_FlareYellow_Illumination_F,20);
            MAG_XX(1Rnd_SmokeBlue_Grenade_shell,20);
            MAG_XX(1Rnd_SmokeGreen_Grenade_shell,20);
            MAG_XX(1Rnd_SmokeOrange_Grenade_shell,20);
            MAG_XX(1Rnd_SmokePurple_Grenade_shell,20);
            MAG_XX(1Rnd_SmokeRed_Grenade_shell,20);
            MAG_XX(1Rnd_Smoke_Grenade_shell,20);
            MAG_XX(1Rnd_SmokeYellow_Grenade_shell,20);

            // ---- Launcher Ammo ----
            // M41 SSR MAV/AW     | HEAT / SACLOS
            MAG_XX(OPTRE_M41_Twin_HEAT_SACLOS,2);
            // [1st] S-108 SAM
            MAG_XX(MEU_SPKR108_SAM_AA,2);
            // M40 "Rabbit" Launcher
            MAG_XX(OPTRE_1Rnd_50x137_HEAT,2);

            // ---- Grenades ----
            MAG_XX(OPTRE_M9_Frag,8);

            // ---- Misc ----
            // Laser Batteries
            MAG_XX(Laserbatteries,40);
        };
    };

    // ============================================================
    // 02: PLATOON AMMO CRATE
    // ============================================================
    class CLASS(Resupply_PlatoonAmmo): CLASS(Resupply_SquadAmmo) {
        displayName = "02: Ammo Crate (Platoon)";
        ace_cargo_size = 2;
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(resupply\data\textures\Platoon_Ammo_Crate_co.paa)
        };

        class TransportMagazines {

            // ---- PRIMARY: Assault Rifles / Battle Rifles ----
            // MA37/MA37GL
            MAG_XX(CLASS(40Rnd_762x51_Mag),160);
            // LMR11 Shortbow| 7.62x51mm   | 30Rnd
            MAG_XX(CLASS(30Rnd_762x51_Mag),160);
            // VK78 Commando | 9.5xVX2     | 20Rnd
            MAG_XX(CLASS(20Rnd_95xVX2_Mag),160);
            // MR10 Longbow  | 9.5xVX2     | 15Rnd
            MAG_XX(CLASS(15Rnd_95xVX2_Mag),160);
            // BR55HB         | 7.62x51mm   | 36Rnd
            MAG_XX(CLASS(36Rnd_95x40_Mag),160);

            // ---- PRIMARY: SMGs ----
            // CPW           | 9x21mm      | 30Rnd
            MAG_XX(CLASS(30Rnd_9x21_Mag),160);
            // MPK-5         | 9x21mm      | 32Rnd
            MAG_XX(CLASS(32Rnd_9x21_Mag),160);
            // M7 Caseless   | 5x23mm      | 60Rnd
            MAG_XX(CLASS(60Rnd_5x23_Mag),160);
            // M6D Carbine   | 12.7x40mm   | 40Rnd
            MAG_XX(CLASS(40Rnd_127x40_Mag),160);

            // ---- PRIMARY: LMGs / HMGs ----
            // M73           | 9.5x40mm    | 100Rnd Box
            MAG_XX(CLASS(100Rnd_95x40_Box),160);

            // ---- PRIMARY: Sniper / Anti-Material ----

            // ---- PRIMARY: Energy Weapons ----

            // ---- SECONDARY: Pistols ----
            // M6G           | 12.7x40mm   | 8Rnd
            MAG_XX(CLASS(8Rnd_127x40_Mag),160);
            // M6C           | 12.7x40mm   | 12Rnd
            MAG_XX(CLASS(12Rnd_127x40_Mag),160);
            // MHG16         | .45 ACP     | 12Rnd
            MAG_XX(CLASS(12Rnd_45ACP_Mag),160);
            // PUMA          | .45 ACP     | 16Rnd
            MAG_XX(CLASS(16Rnd_45ACP_Mag),160);

            // ---- UGL Ammo ----
            MAG_XX(TCP_1Rnd_40_Shell_Signal_Green,80);
            MAG_XX(TCP_1Rnd_40_Shell_Signal_Red,80);
            MAG_XX(TCP_1Rnd_40_Shell_Signal_White,80);
            MAG_XX(TCP_1Rnd_40_Shell_Signal_Yellow,80);
            MAG_XX(TCP_1Rnd_40_Shell_HE,80);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_Blue,80);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_Green,80);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_Red,80);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_White,80);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_Yellow,80);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_Orange,80);
            MAG_XX(TCP_1Rnd_40_Shell_Smoke_Purple,80);
            MAG_XX(TCP_1Rnd_40_Shell_TD,80);
            MAG_XX(1Rnd_HE_Grenade_shell,80);
            MAG_XX(UGL_FlareGreen_F,80);
            MAG_XX(UGL_FlareCIR_F,80);
            MAG_XX(UGL_FlareRed_F,80);
            MAG_XX(UGL_FlareWhite_F,80);
            MAG_XX(UGL_FlareYellow_F,80);
            MAG_XX(UGL_FlareGreen_Illumination_F,80);
            MAG_XX(UGL_FlareRed_Illumination_F,80);
            MAG_XX(UGL_FlareWhite_Illumination_F,80);
            MAG_XX(UGL_FlareYellow_Illumination_F,80);
            MAG_XX(1Rnd_SmokeBlue_Grenade_shell,80);
            MAG_XX(1Rnd_SmokeGreen_Grenade_shell,80);
            MAG_XX(1Rnd_SmokeOrange_Grenade_shell,80);
            MAG_XX(1Rnd_SmokePurple_Grenade_shell,80);
            MAG_XX(1Rnd_SmokeRed_Grenade_shell,80);
            MAG_XX(1Rnd_Smoke_Grenade_shell,80);
            MAG_XX(1Rnd_SmokeYellow_Grenade_shell,80);

            // ---- Launcher Ammo ----
            // M41 SSR MAV/AW     | HEAT / SACLOS
            MAG_XX(OPTRE_M41_Twin_HEAT_SACLOS,20);
            // [1st] S-108 SAM
            MAG_XX(MEU_SPKR108_SAM_AA,20);
            // M40 "Rabbit" Launcher
            MAG_XX(OPTRE_1Rnd_50x137_HEAT,20);

            // ---- Grenades ----
            MAG_XX(OPTRE_M9_Frag,32);

            // ---- Misc ----
            // Laser Batteries
            MAG_XX(Laserbatteries,160);
        };
    };

    // ============================================================
    // 03: SQUAD MEDICAL CRATE
    // ============================================================
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

    // ============================================================
    // 04: PLATOON MEDICAL CRATE
    // ============================================================
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

    // ============================================================
    // 05: EXPLOSIVES CRATE
    // ============================================================
    class CLASS(Resupply_Explosives): CLASS(Resupply_Base) {
        displayName = "05: Explosives Crate";
        ace_cargo_size = 4;
        model = "\TKE_Kuiper_Engagements\TKE_Props\TKE_SupplyCrate.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(resupply\data\textures\Explosives_Crate_co.paa)
        };

        class TransportMagazines {
            // Frag & Smoke Grenades
            MAG_XX(OPTRE_M9_Frag,64);
            MAG_XX(OPTRE_M2_Smoke,64);
            MAG_XX(OPTRE_M2_Smoke_Blue,64);
            MAG_XX(OPTRE_M2_Smoke_Green,64);
            MAG_XX(OPTRE_M2_Smoke_Orange,64);
            MAG_XX(OPTRE_M2_Smoke_Red,64);
            MAG_XX(OPTRE_M2_Smoke_Yellow,64);

            // Mines / Charges (magazines)
            MAG_XX(APERSMineDispenser_Mag,40);
            MAG_XX(C7_Remote_Mag,40);
            MAG_XX(M168_Remote_Mag,40);
        };

        class TransportItems {
            // Demolition Items
            ITEM_XX(ACE_M26_Clacker,10);
        };
    };

    // ============================================================
    // 06: ROCKETS CRATE
    // ============================================================
    class CLASS(Resupply_Rockets): CLASS(Resupply_Base) {
        displayName = "06: Rockets Crate";
        ace_cargo_size = 4;
        model = "\TKE_Kuiper_Engagements\TKE_Props\TKE_SupplyCrate.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {
            "\TKE_Kuiper_Engagements\TKE_Props\data\TKE_SupplyCrate_co.paa"
        };

        class TransportWeapons {
            // Launchers
            WEAP_XX(OPTRE_M44_Lykoi_Semi_Disposable_AT_Grey,10);
        };
    };
};