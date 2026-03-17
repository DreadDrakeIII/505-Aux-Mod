class CfgWeapons {
    class Rogue_CEHelmet;
    class CLASS(Marine_Helmet_Base): Rogue_CEHelmet {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Marine Helmet EP (Base)";
    };

    class Rogue_CEHelmetV2;
    class CLASS(Marine_Helmet_V2_Base): Rogue_CEHelmetV2 {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Marine Helmet (Base)";
    };

    class Rogue_CEFieldCap_base;
    class CLASS(FieldCap_Base): Rogue_CEFieldCap_base {
        author = "505th Aux Team";
        scope = 1;
        displayName = "[505th] Field Cap (Base)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CECapGrey_co.paa"};
    };

    class TKE_UCNPilotHelm_BASE;
    class CLASS(505th_Jet_Pilot_Helmet_Base): TKE_UCNPilotHelm_BASE {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Jet Pilot Helmet (Base)";
    };

    class H_PilotHelmetHeli_B;
    class CLASS(505th_Heli_Pilot_Helmet_Base): H_PilotHelmetHeli_B {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Heli Pilot Helmet (Base)";
        hiddenSelections[] = {"camo"};
    };

    class H_CrewHelmetHeli_B;
    class CLASS(505th_Heli_Crew_Helmet_Base): H_CrewHelmetHeli_B {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Heli Crew Helmet (Base)";
        hiddenSelections[] = {"camo"};
    };

    class TKE_UCMCHelmClosed;
    class CLASS(505th_Black_Ops_Helmet_Base): TKE_UCMCHelmClosed {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Black Ops Helmet (Base)";
    };

    class Rogue_CEBoonie;
    class CLASS(Boonie_Base): Rogue_CEBoonie {
        author = "505th Aux Team";
        scope = 1;
        displayName = "[505th] Boonie Hat (Base)";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEBooniehat_co.paa"};
    };

// =========================================================================
// ============================ CHJ252 Helmets =============================
// =========================================================================
    class CH252_Helmet_Green;
    class CLASS(CHJ252_WL_Helmet_Base): CH252_Helmet_Green {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] CHJ252 Woodland Helmet (Base)";
    };


    class CH252_Helmet_EyePiece_Green;
    class CLASS(CHJ252_WL_Helmet_V2_Base): CH252_Helmet_EyePiece_Green {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] CHJ252 Woodland Helmet EP (Base)";
    };

    #include "configs\Helmets.hpp"


    class UniformItem;
    class Rogue_CEUniform_U_B;
    class CLASS(Uniform_CE_Base): Rogue_CEUniform_U_B {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Marine Uniform (Base)";
        uniformType = "Neopren";
    };

    class Rogue_CEUniformRolled_U_B;
    class CLASS(Uniform_CE_Rolled_Base): Rogue_CEUniformRolled_U_B {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Marine Uniform Rolled (Base)";
        uniformType = "Neopren";
    };

    class TKE_CombatUniMerc_U_B;
    class CLASS(Uniform_Pilot_Base): TKE_CombatUniMerc_U_B {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Pilot Uniform (Base)";
    };

    class CLASS(Uniform_BlackOps_Base): TKE_CombatUniMerc_U_B {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Black Ops Uniform (Base)";
    };

// =========================================================================
// ============================ CHJ252 Uniforms ============================
// =========================================================================
    class MA_Marine_BDU_Heavy_Woodland_NC;
    class CLASS(CHJ252_WL_Uniform_Heavy_Base): MA_Marine_BDU_Heavy_Woodland_NC {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] CHJ252 Woodland Heavy Uniform (Base)";
        hiddenSelections[]=
        {
            "Camo1",
            "Camo2",
            "Camo3",
            "Camo4",
            "Camo5",
            "Camo6",
            "Camo7",
            "Camo8",
            "Camo9",
            "Camo10",
    //     "Uni_Upper",
    //     "Uni_Lower",
            "Uni_Collar",
    //     "Armor_Underpad",
    //     "Armor_Straps",
    //     "Armor_Upper",
    //     "Armor_Lower",
    //     "Shoulders_Lower1",
            "Shoulders_Lower2",
    //     "Shoulders_Upper"
        };
    hiddenSelectionsTextures[]=
        {
            "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Woodland_TrooperUpperBDU_CO.paa",
            "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Woodland_TrooperLowerBDU_CO.paa",
            "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Woodland_TrooperCollar_CO.paa",
            "MA_Armor\data\Uniforms\Marine\data\Color_Variants\TrooperSoftpadding_CO.paa",
            "MA_Armor\data\Uniforms\Marine\data\Color_Variants\TrooperArmorStraps_CO.paa",
            "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Green_TrooperUpperArmor_CO.paa",
            "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Green_TrooperLowerArmor_CO.paa",
            "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Green_TrooperShoulders_CO.paa",
            "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Green_TrooperShoulders_CO.paa",
            "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Green_TrooperShoulders_CO.paa"
        };
    };

    class MA_Marine_BDU_NS_Woodland;
    class CLASS(CHJ252_WL_Uniform_NS_Base): MA_Marine_BDU_NS_Woodland {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] CHJ252 Woodland Uniform NS (Base)";
        hiddenSelections[]=
    {
        "Camo1",
        "Camo2",
        "Camo3",
        "Camo4",
        "Camo5",
        "Camo6",
        "Camo7",
        "Camo8",
        "Camo9",
        "Camo10",
 //     "Uni_Upper",
 //     "Uni_Lower",
 //     "Uni_Collar",
 //     "Armor_Underpad",
 //     "Armor_Straps",
 //     "Armor_Upper",
 //     "Armor_Lower",
        "Shoulders_Lower1",
        "Shoulders_Lower2",
        "Shoulders_Upper"
    };
    hiddenSelectionsTextures[]=
    {
        "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Woodland_TrooperUpperBDU_CO.paa",
        "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Woodland_TrooperLowerBDU_CO.paa",
        "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Woodland_TrooperCollar_CO.paa",
        "MA_Armor\data\Uniforms\Marine\data\Color_Variants\TrooperSoftpadding_CO.paa",
        "MA_Armor\data\Uniforms\Marine\data\Color_Variants\TrooperArmorStraps_CO.paa",
        "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Green_TrooperUpperArmor_CO.paa",
        "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Green_TrooperLowerArmor_CO.paa",
        "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Green_TrooperShoulders_CO.paa",
        "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Green_TrooperShoulders_CO.paa",
        "MA_Armor\data\Uniforms\Marine\data\Color_Variants\MA_Green_TrooperShoulders_CO.paa"
    };
    };

    #include "configs\Uniforms.hpp"

    class Rogue_CEArmour;
	class Rogue_CEArmourV2;
	class Rogue_CEArmourNSV2;
	class Rogue_CEArmourNS;
	class Rogue_CEArmourPouch;
	class Rogue_CEArmourV2Pouch;
	class Rogue_CEArmourNSV2Pouch;
	class Rogue_CEArmourNSPouch;
    class Rogue_CEArmourScout;
    class TKE_MDTFArmour1Grey;
    class TKE_UCMCArmour3_21st;
    class ItemInfo;

    class CLASS(CE_Marine_Vest_Base): Rogue_CEArmour {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Marine Vest (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
    };

    class CLASS(CE_Marine_VestV2_Base): Rogue_CEArmourV2 {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Marine Vest NF (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
    };

    class CLASS(CE_Marine_Vest_NSV2_Base): Rogue_CEArmourNSV2 {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Marine Vest NF+S (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
    };

    class CLASS(CE_Marine_Vest_NS_Base): Rogue_CEArmourNS {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Marine Vest NS (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
    };

    class CLASS(CE_Marine_Vest_Pouch_Base): Rogue_CEArmourPouch {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Marine Vest Pouches (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
    };

    class CLASS(CE_Marine_Vest_V2_Pouch_Base): Rogue_CEArmourV2Pouch {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Marine Vest Pouches + NF (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
    };

    class CLASS(CE_Marine_Vest_NSV2_Pouch_Base): Rogue_CEArmourNSV2Pouch {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Marine Vest Pouches + NF/S (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
    };

    class CLASS(CE_Marine_Vest_NS_Pouch_Base): Rogue_CEArmourNSPouch {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Marine Vest Pouches + NS (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
    };

    class CLASS(CE_Scout_Vest_Base): Rogue_CEArmourScout {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Scout Vest (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
    };

    class CLASS(Pilot_Vest_Base): TKE_MDTFArmour1Grey {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Pilot Vest (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };

    };

    class CLASS(BlackOps_Vest_Base): TKE_UCMCArmour3_21st {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Black Ops Vest (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
    };

    #include "configs\Vests.hpp"
};
