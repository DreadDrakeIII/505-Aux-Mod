// ============================================================================
// ==============================505th Facewears===============================
// ============================================================================
// Tactical Combat Mask with Glasses with TCP HUD overlay
// Tactical Glasses with TCP HUD overlay
// Medical Scanner Glasses with TCP HUD overlay
// ============================================================================

class CfgGlasses {

    class TCP_G_BalaclavaTacticalGlasses_Black_Blue;
    class TCP_G_TacticalGlasses_Blue;

    class CLASS(Tactical_Combat_Mask): TCP_G_BalaclavaTacticalGlasses_Black_Blue {
    SCOPE_PUBLIC;
    author = AUTHOR;

    displayName = "[505th] Tactical Combat Mask (Glasses)";
    descriptionShort = "Tactical Combat Mask with integrated HUD Glasses.";

    tcp_visrRscTitlesClass = "RscTCPVisrODST";

    TCP_visrClasses[] = {"TCP_G_BalaclavaTacticalGlasses_Black_Blue","TCP_G_BalaclavaTacticalGlasses_Black_Blue_DP"};

    ACE_Color[] = {0, 0, 0};
    ACE_DustPath = "\z\ace\addons\goggles\textures\fx\dust\%1.paa";
    ACE_Overlay = "";
    ACE_OverlayCracked = "\z\ace\addons\goggles\textures\HUD\Cracked.paa";
    ACE_OverlayDirt = "A3\Ui_f\data\igui\rsctitles\HealthTextures\dust_upper_ca.paa";
    ACE_Protection = 1;
    ACE_Resistance = 2;
    ACE_TintAmount = 0;
};

// Medical Scanner Glasses with TCP HUD overlay
    class CLASS(Tactical_Glasses): TCP_G_TacticalGlasses_Blue {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "[505th] Tactical Glasses";
        descriptionShort = "Tactical glasses with integrated TCP HUD.";

        tcp_visrRscTitlesClass = "RscTCPVisrODST";

        TCP_visrClasses[] = {"TCP_G_BalaclavaTacticalGlasses_Black_Blue","TCP_G_BalaclavaTacticalGlasses_Black_Blue_DP"};

        ACE_Color[] = {0, 0, 0};
        ACE_DustPath = "\z\ace\addons\goggles\textures\fx\dust\%1.paa";
        ACE_Overlay = "";
        ACE_OverlayCracked = "\z\ace\addons\goggles\textures\HUD\Cracked.paa";
        ACE_OverlayDirt = "A3\Ui_f\data\igui\rsctitles\HealthTextures\dust_upper_ca.paa";
        ACE_Protection = 1;
        ACE_Resistance = 2;
        ACE_TintAmount = 0;
    };

    // Medical Scanner Glasses with TCP HUD overlay
    class CLASS(MedScanner_Glasses): TCP_G_TacticalGlasses_Blue {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "[505th] Medical Scanner Glasses";
        descriptionShort = "Tactical glasses with integrated medical scanner and TCP HUD.";

        tcp_visrRscTitlesClass = "RscTCPVisrODST";

        TCP_visrClasses[] = {"TCP_G_BalaclavaTacticalGlasses_Black_Blue","TCP_G_BalaclavaTacticalGlasses_Black_Blue_DP"};

        ACE_Color[] = {0, 0, 0};
        ACE_DustPath = "\z\ace\addons\goggles\textures\fx\dust\%1.paa";
        ACE_Overlay = "";
        ACE_OverlayCracked = "\z\ace\addons\goggles\textures\HUD\Cracked.paa";
        ACE_OverlayDirt = "A3\Ui_f\data\igui\rsctitles\HealthTextures\dust_upper_ca.paa";
        ACE_Protection = 1;
        ACE_Resistance = 2;
        ACE_TintAmount = 0;
    };

    class CLASS(MedScanner_Mask): TCP_G_BalaclavaTacticalGlasses_Black_Blue {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "[505th] Medical Scanner Mask";
        descriptionShort = "Tactical Mask with Glasses with integrated medical scanner and TCP HUD.";

        tcp_visrRscTitlesClass = "RscTCPVisrODST";

        TCP_visrClasses[] = {"TCP_G_BalaclavaTacticalGlasses_Black_Blue","TCP_G_BalaclavaTacticalGlasses_Black_Blue_DP"};

        // ACE Goggles Configuration
        ACE_Color[] = {0, 0, 0};
        ACE_DustPath = "\z\ace\addons\goggles\textures\fx\dust\%1.paa";
        ACE_Overlay = "";
        ACE_OverlayCracked = "\z\ace\addons\goggles\textures\HUD\Cracked.paa";
        ACE_OverlayDirt = "A3\Ui_f\data\igui\rsctitles\HealthTextures\dust_upper_ca.paa";
        ACE_Protection = 1;
        ACE_Resistance = 2;
        ACE_TintAmount = 0;
    };

    //========================================================================
    //============================CUSTOM MASKS================================
    //========================================================================

    // class CLASS(Davy_Mask_Glasses): CLASS(Stealth_Mask_Glasses) {
    //     displayName = "[505th] Davy Mask with Glasses";


    //     hiddenSelections[] = {"camo","camo1","camo2"};
    //     hiddenSelectionsTextures[] = {
    //         "\TCP\characters\BLUFOR\UNSC\Army\Facewear\balaclava\data\camo\Black\g_Balaclava_CO.paa",
    //         "\TCP\characters\BLUFOR\UNSC\Army\Facewear\tacticalGlasses\data\camo\Black\g_TacticalGlasses_CO.paa",
    //         "\TCP\characters\BLUFOR\UNSC\Army\Facewear\tacticalGlasses\data\camo\Blue\g_TacticalGlasses_CO.paa"
    //     };
    // };
};
