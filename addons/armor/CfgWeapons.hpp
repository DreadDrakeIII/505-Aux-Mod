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
// ============================ CH252 Helmets =============================
// =========================================================================
    class CH252_Helmet_Sealed_Tan;
    class CLASS(EVCH252_Helmet_DES_Base): CH252_Helmet_Sealed_Tan {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] EVCH252 Helmet Desert (Base)";
    };


    class CH252_Helmet_Sealed_Green;
    class CLASS(EVCH252_Helmet_WDL_Base): CH252_Helmet_Sealed_Green {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] EVCH252 Helmet Woodland (Base)";
    };

    class CLASS(EVCH252_Helmet_URB_Base): CH252_Helmet_Sealed_Green {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] EVCH252 Helmet Urban (Base)";
    };

    class HaloInf_Marine_WDL_two_headgear;
    class CLASS(CH252_Helmet_WDL_Base): HaloInf_Marine_WDL_two_headgear {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] CH252 Helmet Woodland (Base)";
    };

    class HaloInf_Marine_WDL_two_NV_headgear;
    class CLASS(CH252_Helmet_WDL_NV_Base): HaloInf_Marine_WDL_two_NV_headgear {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] CH252 Helmet Woodland NV (Base)";
    };

    class HaloInf_Marine_DES_headgear;
    class CLASS(CH252_Helmet_DES_Base): HaloInf_Marine_DES_headgear {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] CH252 Helmet Arid (Base)";
    };

    class HaloInf_Marine_DES_NV_headgear;
    class CLASS(CH252_Helmet_DES_NV_Base): HaloInf_Marine_DES_NV_headgear {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] CH252 Helmet Arid NV (Base)";
    };

    class HaloInf_Marine_URB_headgear;
    class CLASS(CH252_Helmet_URB_Base): HaloInf_Marine_URB_headgear {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] CH252 Helmet Urban (Base)";
    };

    class HaloInf_Marine_URB_NV_headgear;
    class CLASS(CH252_Helmet_URB_NV_Base): HaloInf_Marine_URB_NV_headgear {
        SCOPE_HIDDEN;
        author = AUTHOR;
        displayName = "[505th] CH252 Helmet Urban NV (Base)";
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

// =========================================================================
// ============================ CH252 Uniforms =============================
// =========================================================================

// TGE wearable uniform items
class haloinfmar_U_WDL_uniform;
class haloinfmar_U_URB_uniform;
class haloinfmar_U_DES_uniform;
class CLASS(CH252_Uniform_WDL_Base): haloinfmar_U_WDL_uniform {
    SCOPE_HIDDEN;
    author = AUTHOR;
    displayName = "[505th] CH252 Uniform Woodland (Base)";
};

class CLASS(CH252_Uniform_URB_Base): haloinfmar_U_URB_uniform {
    SCOPE_HIDDEN;
    author = AUTHOR;
    displayName = "[505th] CH252 Uniform Urban (Base)";
};

class CLASS(CH252_Uniform_DES_Base): haloinfmar_U_DES_uniform {
    SCOPE_HIDDEN;
    author = AUTHOR;
    displayName = "[505th] CH252 Uniform Desert (Base)";
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

    #include "configs\Vests.hpp"
};
