#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QCLASS(main),
            "ace_medical_treatment",
            "ace_medical_engine",
            "ace_medical_gui",
            "ace_common",
            "cba_settings"
        };
        units[] = {};
        weapons[] = {
            "OLI_TacticalTraumaKit",
            "OLI_BiofoamCanister",
            "OLI_BoneKnittingPolymer",
            "OLI_Polypseudomorphine",
            "OLI_EpiXAutoinjector",
            "OLI_CombatStim",
            "OLI_NecroClearVial",
            "OLI_NecrosisTestingKit",
            "OLI_EndurexBoosterInhaler"
        };
        VERSION_CONFIG;
    };
};


class Extended_PreInit_EventHandlers {
    class OLI_TacticalTraumaKit {
        init = "call compile preprocessFileLineNumbers '\BLU\OLI\addons\ttk\XEH_preInit.sqf'";
    };
};

class Extended_PostInit_EventHandlers {
    class OLI_TacticalTraumaKit {
        init = "call compile preprocessFileLineNumbers '\BLU\OLI\addons\ttk\XEH_postInit.sqf'";
    };
};


class CfgFunctions {
    class OLI {
        tag = "OLI";
        class Biofoam {
            file = "\BLU\OLI\addons\ttk\biofoam";
            class biofoamTreat {};
            class canBiofoam {};
        };
        class BonePolyseal {
            file = "\BLU\OLI\addons\ttk\bone_polyseal";
            class bonePolyseal {};
        };
        class CombatStim {
            file = "\BLU\OLI\addons\ttk\combat_stim";
            class stimTreat {};
            class stimLocal {};
            class canStim {};
        };
        class NecrosisMonitor {
            file = "\BLU\OLI\addons\ttk\necrosis_monitor";
            class necrosisTestingKit {};
            class canNecrosisTestingKit {};
            class updateNecrosisOverlay {};
            class necrosisTracker {};
        };
        class NecroClear {
            file = "\BLU\OLI\addons\ttk\NecroClear";
            class NecroClearTreat {};
            class NecroClearLocal {};
            class canNecroClear {};
        };
        class TacticalTraumaKit {
            file = "\BLU\OLI\addons\ttk\tactical_trauma_kit";
            class treatLimb {};
            class canTreatLimb {};
        };
        class Endurex {
            file = "\BLU\OLI\addons\ttk\Endurex";
            class EndurexTreat {};
            class EndurexLocal {};
            class canEndurex {};
        };
    };
};


class CfgWeapons {
    class ACE_ItemCore;
    class CBA_MiscItem_ItemInfo;

    class ACE_tourniquet : ACE_ItemCore {
        displayName = "[505th] Auto-Tourniquet";
        descriptionShort = "Auto-cinching tourniquet system with LED display and emergency release.";
        picture = "\BLU\OLI\addons\ttk\img\ui_tourniquet.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 3;
        };
    };

    class OLI_TacticalTraumaKit: ACE_ItemCore {
        displayName = "[505th] Tactical Trauma Kit";
        descriptionShort = "Sutures bandaged wounds and alleviates underlying blunt-force trauma.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_ttk.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 15;
        };
    };

    class OLI_BiofoamCanister: ACE_ItemCore {
        displayName = "[505th] Biofoam Canister";
        descriptionShort = "Pressurized canister that deploys a self-sealing, antimicrobial polymer to seal wounds, halt bleeding, and stabilize internal damage. Initial application induces severe pain.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_biofoam.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 20;
        };
    };

    class OLI_BoneKnittingPolymer: ACE_ItemCore {
        displayName = "[505th] Bone Polyseal Autoinjector";
        descriptionShort = "Injects an osteo-reactive polymer compound that stabilizes fractured bones and promotes gradual structural repair. Notably painful for the patient.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_boneknit.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };

    class OLI_Polypseudomorphine: ACE_ItemCore {
        displayName = "[505th] Polymorph Autoinjector";
        descriptionShort = "Potent Analgesic. Injects a controlled dose of polypseudomorphine.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_morph.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };

    class OLI_EpiXAutoinjector: ACE_ItemCore {
        displayName = "[505th] Epinephrex Autoinjector";
        descriptionShort = "Cardiovascular stimulant. Injects a controlled dose of carboxyepinephrine.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_epi.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };

    class OLI_CombatStim: ACE_ItemCore {
        displayName = "[505th] Flatline Serum Autoinjector";
        descriptionShort = "HAZARDOUS. Promotes extreme cellular regeneration for a short duration, forcing the patient to remain conscious and endure all sustained trauma. High risk of total systemic failure upon expiration.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_stim.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };

    class OLI_NecroClearVial: ACE_ItemCore {
        displayName = "[505th] NecroClear vial";
        descriptionShort = "Necrolytic Chelation Agent. Rapidly treats tourniquet-induced necrosis using myotropic repair mechanisms.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_NecroClear.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };

    class OLI_NecrosisTestingKit: ACE_ItemCore {
        displayName = "[505th] Necrosis Testing Kit";
        descriptionShort = "Handheld kit capable of analyzing ischemic biomarkers in blood, enabling rapid assessment of tissue necrosis severity.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_necrosis_kit.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 2;
        };
    };

    class OLI_EndurexBoosterInhaler: ACE_ItemCore {
        displayName = "[505th] Endurex Booster Inhaler";
        descriptionShort = "Combat performance enhancer. Temporarily eliminates weapon sway and suppresses physical exhaustion. Does not treat injury.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_Endurex.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };
};


class ace_medical_treatment {
    class Medication {
        class Morphine {
            incompatibleMedication[] = {"Polypseudomorphine"};
        };
        class Polypseudomorphine: Morphine {
            incompatibleMedication[] = {"Morphine"};
        };

        class Epinephrine {
            incompatibleMedication[] = {"EpiXAutoinjector"};
        };
        class EpiXAutoinjector: Epinephrine {
            incompatibleMedication[] = {"Epinephrine"};
        };
    };
};

class ACE_Medical_Treatment_Actions {
    class SurgicalKit;
    class TacticalTraumaKit: SurgicalKit {
        displayName = "Use Tactical Trauma Kit";
        displayNameProgress = "Treating Injuries...";
        category = "advanced";
        treatmentLocations = 0;
        allowedSelections[] = {"All"};
        allowSelfTreatment = 1;
        medicRequired = 0;
        treatmentTime = "OLI_TTK_treatmentTime";
        items[] = {"OLI_TacticalTraumaKit"};
        consumeItem = 0;
        callbackSuccess = "OLI_fnc_treatLimb";
        callbackFailure = "";
        callbackProgress = "";
        condition = "[_medic, _patient, _bodyPart] call OLI_fnc_canTreatLimb";
        animationMedic = "Acts_Mediaing_ManipulateStand_Medikit4";
        animationMedicSelf = "";
        litter[] = {};
        // sounds[] = {
        //     {"\BLU\OLI\addons\ttk\sounds\ttk\01.ogg", 1, 1, 25},
        //     {"\BLU\OLI\addons\ttk\sounds\ttk\02.ogg", 1, 1, 25}
        // };
    };

    class BasicBandage;
    class BiofoamCanister: BasicBandage {
        displayName = "Apply Biofoam";
        displayNameProgress = "Spraying...";
        category = "bandage";
        treatmentLocations = 0;
        allowedSelections[] = {"All"};
        allowSelfTreatment = 1;
        medicRequired = 0;
        treatmentTime = "OLI_biofoam_treatmentTime";
        items[] = {"OLI_BiofoamCanister"};
        consumeItem = 1;
        callbackSuccess = "OLI_fnc_biofoamTreat";
        callbackFailure = "";
        callbackProgress = "";
        condition = "[_medic, _patient, _bodyPart] call OLI_fnc_canBiofoam";
        animationMedic = "Acts_Mediaing_ManipulateStand_Medikit4";
        animationMedicSelf = "";
        litter[] = {};
        // sounds[] = {
        //     {"\BLU\OLI\addons\ttk\sounds\biofoam\01.ogg", 1, 1, 25},
        //     {"\BLU\OLI\addons\ttk\sounds\biofoam\02.ogg", 1, 1, 25}
        // };
    };

    class Splint;
    class BoneKnittingPolymer: Splint {
        displayName = "Inject Bone Polyseal";
        displayNameProgress = "Injecting Polyseal...";
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        treatmentTime = "OLI_polyseal_treatmentTime";
        items[] = {"OLI_BoneKnittingPolymer"};
        consumeItem = 1;
        callbackSuccess = "OLI_fnc_bonePolyseal";
        // sounds[] = {
        //     {"\BLU\OLI\addons\ttk\sounds\polyseal\01.ogg", 1, 1, 25},
        //     {"\BLU\OLI\addons\ttk\sounds\polyseal\02.ogg", 1, 1, 25}
        // };
    };

    class Morphine;
    class Polypseudomorphine: Morphine {
        displayName = "Inject Polymorph";
        displayNameProgress = "Injecting Analgesic...";
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        treatmentTime = "OLI_morph_treatmentTime";
        items[] = {"OLI_Polypseudomorphine"};
        consumeItem = 1;
        // sounds[] = {
        //     {"\BLU\OLI\addons\ttk\sounds\polymorph\01.ogg", 1, 1, 25},
        //     {"\BLU\OLI\addons\ttk\sounds\polymorph\02.ogg", 1, 1, 25}
        // };
    };

    class Epinephrine;
    class EpiXAutoinjectorAutoinjector: Epinephrine {
        displayName = "Inject Epinephrex";
        displayNameProgress = "Injecting Adrenal Solution...";
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        treatmentTime = "OLI_epi_treatmentTime";
        items[] = {"OLI_EpiXAutoinjector"};
        consumeItem = 1;
        // sounds[] = {
        //     {"\BLU\OLI\addons\ttk\sounds\catephrine\01.ogg", 1, 1, 25},
        //     {"\BLU\OLI\addons\ttk\sounds\catephrine\02.ogg", 1, 1, 25}
        // };
    };

    class CombatStim: Morphine {
        displayName = "Inject Flatline Serum";
        displayNameProgress = "Here goes nothing...";
        category = "medication";
        treatmentLocations = 0;
        allowedSelections[] = {"All"};
        allowSelfTreatment = 1;
        medicRequired = 0;
        treatmentTime = "OLI_stim_treatmentTime";
        items[] = {"OLI_CombatStim"};
        consumeItem = 1;
        callbackSuccess = "OLI_fnc_stimTreat";
        callbackFailure = "";
        callbackProgress = "";
        condition = "[_medic, _patient, _bodyPart] call OLI_fnc_canStim";
        animationMedic = "Acts_Mediaing_ManipulateStand_Medikit4";
        animationMedicSelf = "";
        litter[] = {};
        // sounds[] = {
        //     {"\BLU\OLI\addons\ttk\sounds\pancea\01.ogg", 1, 1, 25},
        //     {"\BLU\OLI\addons\ttk\sounds\pancea\02.ogg", 1, 1, 25}
        // };
    };

    class NecroClearVial: Epinephrine {
        displayName = "Inject NecroClear";
        displayNameProgress = "Injecting NecroClear...";
        category = "advanced";
        treatmentLocations = 0;
        allowedSelections[] = {"All"};
        allowSelfTreatment = 1;
        medicRequired = 0;
        treatmentTime = "OLI_NecroClear_treatmentTime";
        items[] = {"OLI_NecroClearVial"};
        consumeItem = 1;
        callbackSuccess = "OLI_fnc_NecroClearTreat";
        callbackFailure = "";
        callbackProgress = "";
        condition = "[_medic, _patient, _bodyPart] call OLI_fnc_canNecroClear";
        animationMedic = "Acts_Mediaing_ManipulateStand_Medikit4";
        animationMedicSelf = "";
        litter[] = {};
        // sounds[] = {
        //     {"\BLU\OLI\addons\ttk\sounds\NecroClear\01.ogg", 1, 1, 25},
        //     {"\BLU\OLI\addons\ttk\sounds\NecroClear\02.ogg", 1, 1, 25}
        // };
    };

    class EndurexBoosterInhaler: Epinephrine {
        displayName = "Actuate Endurex Booster";
        displayNameProgress = "Delivering Dose...";
        category = "medication";
        treatmentLocations = 0;
        allowedSelections[] = {"head"};
        allowSelfTreatment = 1;
        medicRequired = 0;
        treatmentTime = "OLI_Endurex_treatmentTime";
        items[] = {"OLI_EndurexBoosterInhaler"};
        consumeItem = 1;
        callbackSuccess = "OLI_fnc_EndurexTreat";
        callbackFailure = "";
        callbackProgress = "";
        condition = "[_medic, _patient, _bodyPart] call OLI_fnc_canEndurex";
        animationMedic = "Acts_Mediaing_ManipulateStand_Medikit4";
        animationMedicSelf = "";
        litter[] = {};
        // sounds[] = {
        //     {"\BLU\OLI\addons\ttk\sounds\Endurex\01.ogg", 1, 1, 25},
        //     {"\BLU\OLI\addons\ttk\sounds\Endurex\02.ogg", 1, 1, 25}
        // };
    };

    class NecrosisTestingKit: SurgicalKit {
        displayName = "Assess Necrosis";
        displayNameProgress = "Testing Blood...";
        category = "examine";
        treatmentLocations = 0;
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = 0;
        treatmentTime = 2;
        items[] = {"OLI_NecrosisTestingKit"};
        consumeItem = 0;
        callbackSuccess = "OLI_fnc_necrosisTestingKit";
        callbackFailure = "";
        callbackProgress = "";
        condition = "[_medic, _patient, _bodyPart] call OLI_fnc_canNecrosisTestingKit";
        animationMedic = "";
        animationMedicSelf = "";
        litter[] = {};
        // sounds[] = {
        //     {"\BLU\OLI\addons\ttk\sounds\necrosis_test\01.ogg", 1, 1, 25},
        //     {"\BLU\OLI\addons\ttk\sounds\necrosis_test\02.ogg", 1, 1, 25}
        // };
    };

    class ApplyTourniquet {
        displayName = "Apply Auto-tourniquet";
        displayNameProgress = "Tightening...";
        treatmentTime = "OLI_tourni_applyTime";
        // sounds[] = {
        //     {"\BLU\OLI\addons\ttk\sounds\tourniquet_apply\01.ogg", 1, 1, 25},
        //     {"\BLU\OLI\addons\ttk\sounds\tourniquet_apply\02.ogg", 1, 1, 25}
        // };
    };

    class RemoveTourniquet {
        displayName = "Release Auto-tourniquet";
        displayNameProgress = "Releasing...";
        treatmentTime = "OLI_tourni_removeTime";
        // sounds[] = {
        //     {"\BLU\OLI\addons\ttk\sounds\tourniquet_release\01.ogg", 1, 1, 25},
        //     {"\BLU\OLI\addons\ttk\sounds\tourniquet_release\02.ogg", 1, 1, 25}
        // };
    };
};
