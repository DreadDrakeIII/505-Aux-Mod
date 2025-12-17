// ============================================================================
// 505th Gears - Stealth Balaclava with OPTRE HUD
// ============================================================================
// Balaclava stays visible + OPTRE HUD overlay appears on screen
// Both at the same time!
// ============================================================================

class CfgGlasses {

    class G_Balaclava_TI_G_blk_F;
    class G_Tactical_Clear;

    class CLASS(Stealth_Balaclava): G_Balaclava_TI_G_blk_F {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "[505th] Stealth Balaclava with google";
        descriptionShort = "Stealth balaclava with integrated OPTRE HUD goggle.";

        // OPTRE HUD Configuration - Required for OPTRE to recognize this
        optreHUDStyle = "Glasses";
        optreVarietys[] = {"", "", ""};

        // ACE Goggles Configuration
        ACE_Color[] = {0, 0, 0};
        ACE_DustPath = "\z\ace\addons\goggles\textures\fx\dust\%1.paa";
        ACE_Overlay = "\z\ace\addons\goggles\textures\HUD\CombatGoggles.paa";
        ACE_OverlayCracked = "\z\ace\addons\goggles\textures\HUD\CombatGogglesCracked.paa";
        ACE_OverlayDirt = "A3\Ui_f\data\igui\rsctitles\HealthTextures\dust_upper_ca.paa";
        ACE_Protection = 1;
        ACE_Resistance = 2;
        ACE_TintAmount = 0;
    };

    // Medical Scanner Glasses - BLUFOR ONLY
    class CLASS(Glasses_MedScanner): G_Tactical_Clear {
        SCOPE_PUBLIC;
        author = AUTHOR;
        side = 1; // BLUFOR only

        displayName = "[505th] Medical Scanner Glasses";
        descriptionShort = "Tactical glasses with integrated medical scanner. Displays friendly medical status.";

        ACE_Color[] = {0, 0, 0};
        ACE_DustPath = "\z\ace\addons\goggles\textures\fx\dust\%1.paa";
        ACE_Overlay = "\z\ace\addons\goggles\textures\HUD\CombatGoggles.paa";
        ACE_OverlayCracked = "\z\ace\addons\goggles\textures\HUD\CombatGogglesCracked.paa";
        ACE_OverlayDirt = "A3\Ui_f\data\igui\rsctitles\HealthTextures\dust_upper_ca.paa";
        ACE_Protection = 1;
        ACE_Resistance = 2;
        ACE_TintAmount = 0;
    };

    class CLASS(DAVY_MASK): CLASS(Stealth_Balaclava) {
        displayName = "[505th] DAVY Mask with google";


        hiddenSelections[] = {"camo1","camo2"};
        hiddenselectionsTextures[] = {
            QPATHTOF(textures\masks\davy_mask_co.paa),
            "\A3\Characters_F\Heads\Glasses\data\g_combat_ca.paa"
        };
    };
};
