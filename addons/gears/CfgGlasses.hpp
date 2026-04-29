// ============================================================================
// ==============================505th Facewears===============================
// ============================================================================
// Tactical Combat Mask with Glasses with TCP HUD overlay
// Tactical Glasses with TCP HUD overlay
// Medical Scanner Glasses with TCP HUD overlay
// ============================================================================

class CfgGlasses {
    #include "declarations.hpp"

    class CLASS(Tactical_Combat_Mask): TCP_G_BalaclavaTacticalGlasses_Black_Blue {
    SCOPE_PUBLIC;
    author = AUTHOR;

    displayName = "[505th] Tactical Combat Mask (Glasses)";
    descriptionShort = "Tactical Combat Mask with integrated HUD Glasses.";

    tcp_visrRscTitlesClass = "RscTCPVisrODST";

    TCP_visrClasses[] = {"OLI_Tactical_Combat_Mask","OLI_Tactical_Combat_Mask_DP"};

    ACE_Color[] = {0, 0, 0};
    ACE_DustPath = "\z\ace\addons\goggles\textures\fx\dust\%1.paa";
    ACE_Overlay = "";
    ACE_OverlayCracked = "\z\ace\addons\goggles\textures\HUD\Cracked.paa";
    ACE_OverlayDirt = "A3\Ui_f\data\igui\rsctitles\HealthTextures\dust_upper_ca.paa";
    ACE_Protection = 1;
    ACE_Resistance = 2;
    ACE_TintAmount = 0;
};

class CLASS(Tactical_Combat_Mask_DP): TCP_G_BalaclavaTacticalGlasses_Black_Blue_DP {
    SCOPE_HIDDEN;
    author = AUTHOR;

    displayName = "[505th] Tactical Combat Mask (Glasses) Depolarized";
    descriptionShort = "Tactical Combat Mask with integrated HUD Glasses.";

    tcp_visrRscTitlesClass = "RscTCPVisrODST";

    TCP_visrClasses[] = {"OLI_Tactical_Combat_Mask","OLI_Tactical_Combat_Mask_DP"};

    ACE_Color[] = {0, 0, 0};
    ACE_DustPath = "\z\ace\addons\goggles\textures\fx\dust\%1.paa";
    ACE_Overlay = "";
    ACE_OverlayCracked = "\z\ace\addons\goggles\textures\HUD\Cracked.paa";
    ACE_OverlayDirt = "A3\Ui_f\data\igui\rsctitles\HealthTextures\dust_upper_ca.paa";
    ACE_Protection = 1;
    ACE_Resistance = 2;
    ACE_TintAmount = 0;
};

    class CLASS(Tactical_Glasses): TCP_G_TacticalGlasses_Blue {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "[505th] Tactical Glasses";
        descriptionShort = "Tactical glasses with integrated TCP HUD.";

        tcp_visrRscTitlesClass = "RscTCPVisrODST";

        TCP_visrClasses[] = {"OLI_Tactical_Glasses","OLI_Tactical_Glasses_DP"};

        ACE_Color[] = {0, 0, 0};
        ACE_DustPath = "\z\ace\addons\goggles\textures\fx\dust\%1.paa";
        ACE_Overlay = "";
        ACE_OverlayCracked = "\z\ace\addons\goggles\textures\HUD\Cracked.paa";
        ACE_OverlayDirt = "A3\Ui_f\data\igui\rsctitles\HealthTextures\dust_upper_ca.paa";
        ACE_Protection = 1;
        ACE_Resistance = 2;
        ACE_TintAmount = 0;
    };

    class CLASS(Tactical_Glasses_DP): TCP_G_TacticalGlasses_Blue_DP {
        SCOPE_HIDDEN;
        author = AUTHOR;

        displayName = "[505th] Tactical Glasses (Depolarized)";
        descriptionShort = "Tactical glasses with integrated TCP HUD.";

        tcp_visrRscTitlesClass = "RscTCPVisrODST";

        TCP_visrClasses[] = {"OLI_Tactical_Glasses","OLI_Tactical_Glasses_DP"};

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

        TCP_visrClasses[] = {"OLI_MedScanner_Glasses","OLI_MedScanner_Glasses_DP"};

        ACE_Color[] = {0, 0, 0};
        ACE_DustPath = "\z\ace\addons\goggles\textures\fx\dust\%1.paa";
        ACE_Overlay = "";
        ACE_OverlayCracked = "\z\ace\addons\goggles\textures\HUD\Cracked.paa";
        ACE_OverlayDirt = "A3\Ui_f\data\igui\rsctitles\HealthTextures\dust_upper_ca.paa";
        ACE_Protection = 1;
        ACE_Resistance = 2;
        ACE_TintAmount = 0;
    };

     class CLASS(MedScanner_Glasses_DP): TCP_G_TacticalGlasses_Blue_DP {
        SCOPE_HIDDEN;
        author = AUTHOR;

        displayName = "[505th] Medical Scanner Glasses (Depolarized)";
        descriptionShort = "Tactical glasses with integrated medical scanner and TCP HUD.";

        tcp_visrRscTitlesClass = "RscTCPVisrODST";

        TCP_visrClasses[] = {"OLI_MedScanner_Glasses","OLI_MedScanner_Glasses_DP"};

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

        TCP_visrClasses[] = {"OLI_MedScanner_Mask","OLI_MedScanner_Mask_DP"};

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

    class CLASS(MedScanner_Mask_DP): TCP_G_BalaclavaTacticalGlasses_Black_Blue_DP {
        SCOPE_HIDDEN;
        author = AUTHOR;

        displayName = "[505th] Medical Scanner Mask";
        descriptionShort = "Tactical Mask with Glasses with integrated medical scanner and TCP HUD.";

        tcp_visrRscTitlesClass = "RscTCPVisrODST";

         TCP_visrClasses[] = {"OLI_MedScanner_Mask","OLI_MedScanner_Mask_DP"};

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

    class CLASS(Davy_Mask): TCP_G_BalaclavaTacticalGlasses_Black_Black {
        displayName = "[505th] Davy Mask with Glasses";

        tcp_visrRscTitlesClass = "RscTCPVisrODST";

        TCP_visrClasses[] = {"OLI_Davy_Mask","OLI_Davy_Mask_Red"};

        ACE_Color[] = {0, 0, 0};
        ACE_DustPath = "\z\ace\addons\goggles\textures\fx\dust\%1.paa";
        ACE_Overlay = "";
        ACE_OverlayCracked = "\z\ace\addons\goggles\textures\HUD\Cracked.paa";
        ACE_OverlayDirt = "A3\Ui_f\data\igui\rsctitles\HealthTextures\dust_upper_ca.paa";
        ACE_Protection = 1;
        ACE_Resistance = 2;
        ACE_TintAmount = 0;
    };

    class CLASS(Davy_Mask_Red): TCP_G_BalaclavaTacticalGlasses_Black_Red {
        SCOPE_HIDDEN;
        displayName = "[505th] Davy Mask with Glasses";


        TCP_visrClasses[] = {"OLI_Davy_Mask","OLI_Davy_Mask_Red"};


        // hiddenSelections[] = {"camo","camo1","camo2"};
        // hiddenSelectionsTextures[] = {
        //     "\TCP\characters\BLUFOR\UNSC\Army\Facewear\balaclava\data\camo\Black\g_Balaclava_CO.paa",
        //     "\TCP\characters\BLUFOR\UNSC\Army\Facewear\tacticalGlasses\data\camo\Black\g_TacticalGlasses_CO.paa",
        //     "\TCP\characters\BLUFOR\UNSC\Army\Facewear\tacticalGlasses\data\camo\Blue\g_TacticalGlasses_CO.paa"
        // };
    };
};
