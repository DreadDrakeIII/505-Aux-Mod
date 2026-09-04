class CfgWeapons {
    ////////////////////Helmets Base///////////////////
    class CLASS(OPFOR_Helmet_Base);
    class CLASS(Helmet_Base): CLASS(OPFOR_Helmet_Base) {
        class ItemInfo;
    };
    //////////////////////Helmets//////////////////////
    class CLASS(TRNE_Head): CLASS(Helmet_Base) {
        SCOPE_PUBLIC;

        displayName = "[505th] TRNE Head (No Faceshield)";
        model = "sc_newequipment2\WarbotHead.p3d";
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(trainingbot\data\textures\TrainingBot_Head_co.paa),
            ""
        };
        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo","camo1"};
            uniformModel = "sc_newequipment2\WarbotHead.p3d";
        };
    };
    class CLASS(TRNE_Faceshield): CLASS(TRNE_Head) {
        SCOPE_PUBLIC;

        displayName = "[505th] TRNE Head (Faceshield)";
        model = "sc_newequipment2\WarbotHead.p3d";
        hiddenSelections[] = {"camo","camo1"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(trainingbot\data\textures\TrainingBot_Head_co.paa),
            QPATHTOF(trainingbot\data\textures\TrainingBot_Faceshield_co.paa)
        };
        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo","camo1"};
            uniformModel = "sc_newequipment2\WarbotHead.p3d";
        };
    };
    ////////////////////Uniform Base///////////////////
    class CLASS(OPFOR_Uniform_Base);
    class CLASS(Uniform_Base): CLASS(OPFOR_Uniform_Base){
        class ItemInfo;
    };
    //////////////////////Uniforms/////////////////////
    class CLASS(TRNE_Light_Uniform): CLASS(Uniform_Base) {
        SCOPE_HIDDEN;

        displayName = "[505th] TRNE_Light Uniform";

        class ItemInfo: ItemInfo {
            uniformClass = QCLASS(TRNE_Light_Unit_Base);
        };
    };
};
