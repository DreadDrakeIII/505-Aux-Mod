#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        author = AUTHOR;
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QCLASS(main),
            "cba_xeh",
            "cba_settings",
            "ace_common",
            "ace_medical",
            "ace_medical_engine",
            "ace_medical_status",
            "ace_medical_statemachine",
            "ace_medical_treatment",
            "ace_medical_gui"
        };
        units[] = {};
        weapons[] = {
            "OLI_TacticalTraumaKit",
            "OLI_BoneKnittingPolymer",
            "OLI_Polypseudomorphine",
            "OLI_EpiXAutoinjector",
            "OLI_CombatStim",
            "OLI_NecroClearVial",
            "OLI_NecrosisTestingKit",
            "OLI_EndurexBoosterInhaler"
        };
        magazines[] = {
            "OLI_BiofoamCanister",
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

// Patient-local state resume: whenever a unit becomes local to this
// machine, restart any TTK effect loops (Endurex/Flatline/NecroClear/
// necrosis tracking) that are still publicly flagged active.
class Extended_Local_EventHandlers {
    class CAManBase {
        class OLI_TacticalTraumaKit {
            local = "_this call OLI_fnc_handleLocality";
        };
    };
};


class CfgFunctions {
    class OLI {
        tag = "OLI";
        class Biofoam {
            file = "\BLU\OLI\addons\ttk\biofoam";
            class canBiofoam {};
            class treatBiofoam {};
            class biofoamLocal {};
        };
        class TacticalTraumaKit {
            file = "\BLU\OLI\addons\ttk\tactical_trauma_kit";
            class canTTK {};
            class treatTTK {};
            class ttkLocal {};
            class getTTKTime {};
        };
        class BonePolyseal {
            file = "\BLU\OLI\addons\ttk\bone_polyseal";
            class treatPolyseal {};
            class polysealLocal {};
            class polysealApply {};
        };
        class NecroClear {
            file = "\BLU\OLI\addons\ttk\NecroClear";
            class canNecroClear {};
            class treatNecroClear {};
            class necroClearLocal {};
        };
        class NecrosisMonitor {
            file = "\BLU\OLI\addons\ttk\necrosis_monitor";
            class necrosisStart {};
            class necrosisTest {};
        };
        class Endurex {
            file = "\BLU\OLI\addons\ttk\Endurex";
            class canEndurex {};
            class treatEndurex {};
            class endurexLocal {};
            class endurexStop {};
        };
        class CombatStim {
            file = "\BLU\OLI\addons\ttk\combat_stim";
            class canFlatline {};
            class treatFlatline {};
            class flatlineLocal {};
            class flatlineStop {};
        };
        class GUI {
            file = "\BLU\OLI\addons\ttk\gui";
            class updateBodyImage {};
        };
        class Common {
            file = "\BLU\OLI\addons\ttk\common";
            class handleLocality {};
        };
    };
};

class CfgMagazines {
    class CA_Magazine;
    class OLI_BiofoamCanister: CA_Magazine {
        author = "505th";
        scope = 2;
        displayName = "[505th] Biofoam Canister";
        descriptionShort = "Pressurized canister that deploys a self-sealing, antimicrobial polymer to seal wounds, halt bleeding, and stabilize internal damage. Initial application induces severe pain.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_biofoam.paa";
        ammo = "";
        count = 10;
        initSpeed = 0;
        mass = 20;
        ACE_isMedicalItem = 1;
        ACE_asItem = 1;
    };
};

class CfgWeapons {
    class ACE_ItemCore;
    class CBA_MiscItem_ItemInfo;

    class ACE_tourniquet: ACE_ItemCore {
        displayName = "[505th] Auto-Tourniquet";
        descriptionShort = "Auto-cinching tourniquet system with LED display and emergency release.";
        picture = "\BLU\OLI\addons\ttk\img\ui_tourniquet.paa";
    };

    class OLI_TacticalTraumaKit: ACE_ItemCore {
        author = "505th";
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

    class OLI_BoneKnittingPolymer: ACE_ItemCore {
        author = "505th";
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
        author = "505th";
        displayName = "[505th] Polymorph Autoinjector";
        descriptionShort = "Potent analgesic. Injects a controlled dose of polypseudomorphine. Do not combine with morphine.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_morph.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };

    class OLI_EpiXAutoinjector: ACE_ItemCore {
        author = "505th";
        displayName = "[505th] Epinephrex Autoinjector";
        descriptionShort = "Cardiovascular stimulant. Injects a controlled dose of carboxyepinephrine. Do not combine with epinephrine.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_epi.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };

    class OLI_NecroClearVial: ACE_ItemCore {
        author = "505th";
        displayName = "[505th] NecroClear Vial";
        descriptionShort = "Necrolytic chelation agent. Rapidly treats tourniquet-induced necrosis via an established IV/IO line. Requires KAT medical.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_NecroClear.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };

    class OLI_NecrosisTestingKit: ACE_ItemCore {
        author = "505th";
        displayName = "[505th] Necrosis Testing Kit";
        descriptionShort = "Handheld assay for the Necrotide-B (NTB) ischemic biomarker. Reference: <1.48 umol/L nominal, 1.48-2.96 early, 2.96-4.44 moderate, 4.44-6.66 advanced, >6.66 CRITICAL. Requires KAT medical.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_necrosis_kit.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 2;
        };
    };

    class OLI_CombatStim: ACE_ItemCore {
        author = "505th";
        displayName = "[505th] Flatline Serum Autoinjector";
        descriptionShort = "HAZARDOUS. Massive adrenal/stimulant cocktail. Forces and maintains consciousness regardless of trauma, and restarts a stopped heart. The body pays the price when it wears off.";
        model = "\A3\Weapons_F\Items\Medikit";
        picture = "\BLU\OLI\addons\ttk\img\ui_stim.paa";
        scope = 2;
        scopeArsenal = 2;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };

    class OLI_EndurexBoosterInhaler: ACE_ItemCore {
        author = "505th";
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
        class Morphine;
        class Polypseudomorphine: Morphine {
            incompatibleMedication[] = {"Morphine"};
        };

        class Epinephrine;
        class EpiXAutoinjector: Epinephrine {
            incompatibleMedication[] = {"Epinephrine"};
        };
    };
};

class ACE_Medical_Treatment_Actions {
    class BasicBandage;
    class SurgicalKit;
    class Splint;
    class Morphine;
    class Epinephrine;
    class Painkillers;

    class BiofoamCanister: BasicBandage {
        displayName = "Apply Biofoam";
        displayNameProgress = "Spraying Biofoam...";
        category = "bandage";
        treatmentLocations = 0;
        allowedSelections[] = {"All"};
        allowSelfTreatment = 1;
        medicRequired = 0;
        treatmentTime = "OLI_biofoam_treatmentTime";
        items[] = {"OLI_BiofoamCanister"};
        consumeItem = 0;
        condition = "[_patient, _bodyPart] call OLI_fnc_canBiofoam";
        callbackSuccess = "OLI_fnc_treatBiofoam";
        litter[] = {};
    };

    class TacticalTraumaKit: SurgicalKit {
        displayName = "Use Tactical Trauma Kit";
        displayNameProgress = "Treating Injuries...";
        category = "advanced";
        treatmentLocations = 0;
        allowedSelections[] = {"All"};
        allowSelfTreatment = "OLI_TTK_selfCare";
        medicRequired = "OLI_TTK_medicRequired";
        treatmentTime = "OLI_fnc_getTTKTime";
        items[] = {"OLI_TacticalTraumaKit"};
        consumeItem = "OLI_TTK_consumeItem";
        condition = "[_patient, _bodyPart] call OLI_fnc_canTTK";
        callbackSuccess = "OLI_fnc_treatTTK";
        callbackStart = "";
        callbackProgress = "";
        litter[] = {};
    };

    class BoneKnittingPolymer: Splint {
        displayName = "Inject Bone Polyseal";
        displayNameProgress = "Injecting Polyseal...";
        treatmentTime = "OLI_polyseal_treatmentTime";
        items[] = {"OLI_BoneKnittingPolymer"};
        consumeItem = 1;
        callbackSuccess = "OLI_fnc_treatPolyseal";
        litter[] = {};
    };

    class Polypseudomorphine: Morphine {
        displayName = "Inject Polymorph";
        displayNameProgress = "Injecting Analgesic...";
        treatmentTime = "OLI_morph_treatmentTime";
        items[] = {"OLI_Polypseudomorphine"};
        litter[] = {};
    };

    class EpiXAutoinjector: Epinephrine {
        displayName = "Inject Epinephrex";
        displayNameProgress = "Injecting Adrenal Solution...";
        treatmentTime = "OLI_epi_treatmentTime";
        items[] = {"OLI_EpiXAutoinjector"};
        litter[] = {};
    };

    class NecroClearVial: Epinephrine {
        displayName = "Inject NecroClear";
        displayNameProgress = "Injecting NecroClear...";
        category = "medication";
        treatmentLocations = 0;
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = "OLI_NecroClear_selfUse";
        medicRequired = "OLI_NecroClear_medicRequired";
        treatmentTime = "OLI_NecroClear_treatmentTime";
        items[] = {"OLI_NecroClearVial"};
        consumeItem = 1;
        condition = "[_patient, _bodyPart] call OLI_fnc_canNecroClear";
        callbackSuccess = "OLI_fnc_treatNecroClear";
        litter[] = {};
    };

    class NecrosisTestingKit: SurgicalKit {
        displayName = "Assess Necrosis";
        displayNameProgress = "Testing Blood...";
        category = "examine";
        treatmentLocations = 0;
        allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        allowSelfTreatment = 1;
        medicRequired = "OLI_necrosisTestingKit_medicRequired";
        treatmentTime = 2;
        items[] = {"OLI_NecrosisTestingKit"};
        consumeItem = 0;
        condition = "OLI_hasKAT";
        callbackSuccess = "OLI_fnc_necrosisTest";
        callbackStart = "";
        callbackProgress = "";
        litter[] = {};
    };

    class CombatStim: Morphine {
        displayName = "Inject Flatline Serum";
        displayNameProgress = "Here goes nothing...";
        category = "medication";
        treatmentLocations = 0;
        allowedSelections[] = {"All"};
        allowSelfTreatment = "OLI_stim_selfUse";
        medicRequired = "OLI_stim_medicRequired";
        treatmentTime = "OLI_stim_treatmentTime";
        items[] = {"OLI_CombatStim"};
        consumeItem = 1;
        condition = "[_patient, _bodyPart] call OLI_fnc_canFlatline";
        callbackSuccess = "OLI_fnc_treatFlatline";
        litter[] = {};
    };

    class EndurexBoosterInhaler: Painkillers {
        displayName = "Actuate Endurex Booster";
        displayNameProgress = "Delivering Dose...";
        allowedSelections[] = {"Head"};
        allowSelfTreatment = "OLI_Endurex_selfUse";
        medicRequired = "OLI_Endurex_medicRequired";
        treatmentTime = "OLI_Endurex_treatmentTime";
        items[] = {"OLI_EndurexBoosterInhaler"};
        consumeItem = 1;
        condition = "[_patient, _bodyPart] call OLI_fnc_canEndurex";
        callbackSuccess = "OLI_fnc_treatEndurex";
        litter[] = {};
        sounds[] = {};
    };

    class ApplyTourniquet: BasicBandage {
        displayName = "Apply Auto-Tourniquet";
        displayNameProgress = "Tightening...";
    };

    class RemoveTourniquet: ApplyTourniquet {
        displayName = "Release Auto-Tourniquet";
        displayNameProgress = "Releasing...";
    };
};

// Flatline Serum hook: while OLI_flatlineActive is set on a unit, block
// ACE's own critical/fatal-vitals/fatal-injury transitions, and let the
// WakeUp transition fire regardless of vitals stability.
class ACE_Medical_StateMachine {
    class Default {
        class CriticalInjuryOrVitals {
            condition = "!(_this getVariable ['OLI_flatlineActive', false])";
        };
        class FatalVitals {
            condition = "!(_this getVariable ['OLI_flatlineActive', false])";
        };
        class FatalInjury {
            condition = "!(_this getVariable ['OLI_flatlineActive', false])";
        };
    };
    class Injured {
        class CriticalInjuryOrVitals {
            condition = "!(_this getVariable ['OLI_flatlineActive', false])";
        };
        class FatalVitals {
            condition = "!(_this getVariable ['OLI_flatlineActive', false])";
        };
        class FatalInjury {
            condition = "!(_this getVariable ['OLI_flatlineActive', false])";
        };
    };
    class Unconscious {
        class WakeUp {
            condition = "(_this call ace_medical_status_fnc_hasStableVitals) || {_this getVariable ['OLI_flatlineActive', false]}";
        };
        class FatalTransitions {
            condition = "!(_this getVariable ['OLI_flatlineActive', false])";
        };
        class FatalInjury {
            condition = "!(_this getVariable ['OLI_flatlineActive', false])";
        };
    };
};
