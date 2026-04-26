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

// ===================================================================================================
// ============================ CH43/A, ECH35/J and ECH43/A Helmets BASE =============================
// ===================================================================================================
    class TCP_H_Helmet_CH43A_Olive;
    class CLASS(CH43A_Helmet_OLIVE_Base): TCP_H_Helmet_CH43A_Olive {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] CH43/A Helmet Olive (Base)";
    };


    class TCP_H_Helmet_ECH35J_Olive_Blue;
    class CLASS(ECH35J_Helmet_Olive_Blue_Base): TCP_H_Helmet_ECH35J_Olive_Blue {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] ECH35/J Helmet Olive Blue (Base)";
    };

    class TCP_H_Helmet_ECH43A_Olive_Blue;
    class CLASS(ECH43A_Helmet_OLIVE_Base): TCP_H_Helmet_ECH43A_Olive_Blue {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] ECH43/A Helmet Olive Blue (Base)";
    };


    #include "configs\Helmets.hpp"


    class UniformItem;
    class ItemInfo;
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
        uniformType = "Neopren";
    };

    class CLASS(Uniform_BlackOps_Base): TKE_CombatUniMerc_U_B {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] Black Ops Uniform (Base)";
        uniformType = "Neopren";
    };

// ==============================================================================
// ============================ CBUU Uniforms BASE ==============================
// ==============================================================================

// The Cole Protocol uniform items
class TCP_U_B_CBUU_TacShirt_Full_Gloves_Bloused_Kneepads_Woodland;
class TCP_U_B_CBUU_TacShirt_HalfRoll_Gloves_Kneepads_Woodland;
class TCP_U_B_CBUU_TacShirt_Full_Gloves_Bloused_Kneepads_Urban;

class CLASS(CBUU_Woodland_1_Base): TCP_U_B_CBUU_TacShirt_Full_Gloves_Bloused_Kneepads_Woodland {
    SCOPE_HIDDEN;
    author = AUTHOR;
    displayName = "[505th] CBUU Uniform Woodland 1 (Base)";
};

class CLASS(CBUU_Woodland_2_Base): TCP_U_B_CBUU_TacShirt_HalfRoll_Gloves_Kneepads_Woodland {
    SCOPE_HIDDEN;
    author = AUTHOR;
    displayName = "[505th] CBUU Uniform Woodland 2 (Base)";
};

class CLASS(CBUU_Urban_1_Base): TCP_U_B_CBUU_TacShirt_Full_Gloves_Bloused_Kneepads_Urban {
    SCOPE_HIDDEN;
    author = AUTHOR;
    displayName = "[505th] CBUU Uniform Urban 1 (Base)";
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

// ==============================================================================
// ============================ M43 Vests BASE ==================================
// ==============================================================================

    class TCP_V_M43A_GungnirL_3_1_Olive;
    class TCP_V_M43A_GungnirS_3_2_Olive;
    class TCP_V_M43A_Pads_1_Black;

    class CLASS(M43_Heavy_Olive_1_Base): TCP_V_M43A_GungnirL_3_1_Olive {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] M43 Heavy Olive 1 (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
    };

    class CLASS(M43_Medium_Olive_1_Base): TCP_V_M43A_GungnirS_3_2_Olive {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] M43 Medium Olive 1 (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
    };

    class CLASS(M43_Kevlar_Black_1_Base): TCP_V_M43A_Pads_1_Black {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] M43 Kevlar Black 1 (Base)";
        class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
    };

    #include "configs\Vests.hpp"
};
