class CfgWeapons {
    class CLASS(OPFOR_Helmet_Base);
    class CLASS(Helmet_Base): CLASS(OPFOR_Helmet_Base) {
        class ItemInfo;
    };
    //////////////////////Helmets//////////////////////
    class CLASS(Wolf_Cap): CLASS(Helmet_Base) {
        SCOPE_PUBLIC;

        displayName = "[ARTE] Wolf Cap";
        model = "\A3\Characters_F\Common\cappatrol";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\TKE_BDU\Textures\MDTFCamoV1milcap.paa"};
        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo"};
            uniformModel = "\A3\Characters_F\Common\cappatrol";
        };
    };

    class CLASS(Wolf_Boonie): CLASS(Helmet_Base) {
        SCOPE_PUBLIC;

        displayName = "[ARTE] Wolf Boonie";
        model = "A3\Characters_F_EPB\Common\booniehat_hs.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\TKE_BDU\Textures\MDTFCamoV1Booniehat.paa"};
        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo"};
            uniformModel = "A3\Characters_F_EPB\Common\booniehat_hs.p3d";
        };
    };

    class CLASS(Jager_Helmet_01): CLASS(Helmet_Base) {
        SCOPE_PUBLIC;

        displayName = "[ARTE] Jager Helmet 01";
        model = "\TKE_Kuiper_Engagements\TKE_UCN\TKE_UCMRHelmOpen.p3d";
        hiddenSelections[] = {
            "camo",
            "camo1"
        };
        hiddenSelectionsTextures[] = {
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCHelmCamo2_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMRHelmArmy_co.paa"
        };
        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo","camo1"};
            uniformModel = "\TKE_Kuiper_Engagements\TKE_UCN\TKE_UCMRHelmOpen.p3d";
        };
    };
    class CLASS(Jager_Helmet_02): CLASS(Helmet_Base) {
        SCOPE_PUBLIC;

        displayName = "[ARTE] Jager Helmet 02";
        model = "\TKE_Kuiper_Engagements\TKE_UCN\TKE_UCMRHelmOpenScrim.p3d";
        hiddenSelections[] = {
            "camo",
            "camo1"
        };
        hiddenSelectionsTextures[] = {
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCHelmCamo2_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMRHelmArmy_co.paa"
        };
        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo","camo1"};
            uniformModel = "\TKE_Kuiper_Engagements\TKE_UCN\TKE_UCMRHelmOpenScrim.p3d";
        };
    };
    class CLASS(Jager_Helmet_03): CLASS(Helmet_Base) {
        SCOPE_PUBLIC;

        displayName = "[ARTE] Jager Helmet 03";
        model = "\TKE_Kuiper_Engagements\TKE_UCN\TKE_UCMCHelmClosed.p3d";
        hiddenSelections[] = {
            "camo",
            "camo1",
            "camo2"
        };
        hiddenSelectionsTextures[] = {
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCHelmCamo2_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCHUD_co",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCPlateCamo2_co"
        };
        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo","camo1","camo2"};
            uniformModel = "\TKE_Kuiper_Engagements\TKE_UCN\TKE_UCMCHelmClosed.p3d";
        };
    };
    //////////////////////Uniform//////////////////////
    class CLASS(OPFOR_Uniform_Base);
    class CLASS(Uniform_Base): CLASS(OPFOR_Uniform_Base){
        class ItemInfo;
    };
    class CLASS(Wolf_Uniform): CLASS(Uniform_Base) {
        SCOPE_PUBLIC;

        displayName = "[ARTE] Wolf Uniform";

        class ItemInfo: ItemInfo {
            uniformClass = QCLASS(Wolf_Unit_Base);
        };
    };

    class CLASS(Jager_Rolled_Uniform): CLASS(Uniform_Base){
        SCOPE_PUBLIC;

        displayName = "[ARTE] Jager Uniform (Rolled)";

        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo","camo1"};
            uniformClass = QCLASS(Jager_Unit_Base);
        };
    };

    class CLASS(Jager_Uniform): CLASS(Uniform_Base){
        SCOPE_PUBLIC;

        displayName = "[ARTE] Jager Uniform";

        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo","camo1"};
            uniformClass = QCLASS(Jager_Unit_02_Base);
        };
    };
    ///////////////////////Vests///////////////////////
    class CLASS(OPFOR_Vest_Base);
    class CLASS(Vest_Base): CLASS(OPFOR_Vest_Base) {
        class ItemInfo;
    };
    class CLASS(Wolf_Vest_01): CLASS(Vest_Base) {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;

        displayName = "[ARTE] Wolf Vest 01";
        modelSides[] = {ALL_SIDES};

        model = "\A3\Characters_F_Enoch\Vests\V_Carrier_RigKBT_01_light_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {"a3\characters_f_enoch\vests\data\carrierrigkbt_01_olive_co.paa"};

        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"Camo"};
            uniformModel = "\A3\Characters_F_Enoch\Vests\V_Carrier_RigKBT_01_light_F.p3d";
            vestType = "Rebreather";
        };
    };
    class CLASS(Wolf_Vest_02): CLASS(Vest_Base) {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;

        displayName = "[ARTE] Wolf Vest 02";
        modelSides[] = {ALL_SIDES};

        model = "\A3\Characters_F_Enoch\Vests\V_SmershVest_01_F.p3d";
        hiddenSelections[] = {"Camo","Camo2","Radio1_hide"};
        hiddenSelectionsTextures[] = {
            "a3\Characters_F_Enoch\Vests\Data\smersh_co.paa",
            "a3\Characters_F_Enoch\Vests\Data\Smersh_miscellaneous_CO.paa"
        };

        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"Camo","Camo2","Radio1_hide"};
            uniformModel = "\A3\Characters_F_Enoch\Vests\V_SmershVest_01_F.p3d";
            vestType = "Rebreather";
        };
    };
    class CLASS(Jager_Vest_01): CLASS(Vest_Base) {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;

        displayName = "[ARTE] Jager Vest 01";
        modelSides[] = {ALL_SIDES};

        model = "\TKE_Kuiper_Engagements\TKE_UCN\TKE_UCMCArmour6_2.p3d";
        hiddenSelections[] = {
            "camo",
            "camo1",
            "camo2",
            "camo3",
            "camo4"
        };
        hiddenSelectionsTextures[] = {
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCArmourCamo2_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCArmourPCamo2_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCPouchesCamo2_2_co.paa",
            "",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_ArmourAddonArmyB_co.paa"
        };
        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4"};
            uniformModel ="\TKE_Kuiper_Engagements\TKE_UCN\TKE_UCMCArmour6_2.p3d";
            vestType = "Rebreather";
            class HitpointsProtectionInfo
        {
            class Legs {
                hitpointName = "HitLegs";
                armor = 40;
                passThrough = 0.5;
            };
            class Arms {
                hitpointName = "HitArms";
                armor = 40;
                passThrough = 0.4;
            };
            class Abdomen {
                hitpointName = "HitAbdomen";
                armor = 40;
                passThrough = 0.1;
            };
            class Body {
                hitpointName = "HitBody";
                armor = 40;
                passThrough = 0.6;
            };
            class Hands {
                hitpointName = "HitHands";
                armor = 40;
                passThrough = 0.6;
            };
            class Chest {
                hitpointName = "HitChest";
                armor = 40;
                passThrough = 0.095;
            };
            class Diaphragm {
                hitpointName = "HitDiaphragm";
                armor = 40;
                passThrough = 0.1;
            };
            class Neck {
                hitpointName = "HitNeck";
                armor = 40;
                passThrough = 0.1;
            };
            class Pelvis {
                hitpointName = "HitPelvis";
                armor = 40;
                passThrough = 0.3;
            };
        };
    };
};
    class CLASS(Jager_Vest_02): CLASS(Vest_Base) {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;

        displayName = "[ARTE] Jager Vest 02";
        modelSides[] = {ALL_SIDES};

        model = "\TKE_Kuiper_Engagements\TKE_UCN\TKE_UCMCArmour6_3.p3d";
        hiddenSelections[] = {
            "camo",
            "camo1",
            "camo2",
            "camo3",
            "camo4",
            "camo7",
            "camo8"
        };
        hiddenSelectionsTextures[] = {
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCArmourArmyV3_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCArmourPArmyV3_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCPouches_co.paa",
            "",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_ArmourAddonArmyB_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCNExtras_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_BinoUCN_co.paa"
        };
            class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4"};
            uniformModel ="\TKE_Kuiper_Engagements\TKE_UCN\TKE_UCMCArmour6_2.p3d";
            vestType = "Rebreather";
            class HitpointsProtectionInfo
        {
            class Legs {
                hitpointName = "HitLegs";
                armor = 40;
                passThrough = 0.5;
            };
            class Arms {
                hitpointName = "HitArms";
                armor = 40;
                passThrough = 0.4;
            };
            class Abdomen {
                hitpointName = "HitAbdomen";
                armor = 40;
                passThrough = 0.1;
            };
            class Body {
                hitpointName = "HitBody";
                armor = 40;
                passThrough = 0.6;
            };
            class Hands {
                hitpointName = "HitHands";
                armor = 40;
                passThrough = 0.6;
            };
            class Chest {
                hitpointName = "HitChest";
                armor = 40;
                passThrough = 0.095;
            };
            class Diaphragm {
                hitpointName = "HitDiaphragm";
                armor = 40;
                passThrough = 0.1;
            };
            class Neck {
                hitpointName = "HitNeck";
                armor = 40;
                passThrough = 0.1;
            };
            class Pelvis {
                hitpointName = "HitPelvis";
                armor = 40;
                passThrough = 0.3;
            };
        };
    };
};
    class CLASS(Jager_Vest_03): CLASS(Vest_Base) {
        scope = 2;
        scopeArsenal = 2;
        scopeCurator = 2;

        displayName = "[ARTE] Jager Vest 03";
        modelSides[] = {ALL_SIDES};

        model = "\TKE_Kuiper_Engagements\TKE_UCN\TKE_UCMCArmour2_1.p3d";
        hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4","camo5","camo6"};
        hiddenSelectionsTextures[] = {
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCArmourCamo2_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCArmourPCamo2_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCPouchesCamo2_2_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_ArmourAddonArmyB_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_ArmourAddonArmyB_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCArmourPCamo2_co.paa",
            "\TKE_Kuiper_Engagements\TKE_UCN\data\TKE_UCMCArmourCamo2_co.paa"
        };
        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4"};
            uniformModel ="\TKE_Kuiper_Engagements\TKE_UCN\TKE_UCMCArmour6_2.p3d";
            vestType = "Rebreather";
            class HitpointsProtectionInfo{
                    class Legs {
                hitpointName = "HitLegs";
                armor = 40;
                passThrough = 0.5;
            };
            class Arms {
                hitpointName = "HitArms";
                armor = 40;
                passThrough = 0.4;
            };
            class Abdomen {
                hitpointName = "HitAbdomen";
                armor = 40;
                passThrough = 0.1;
            };
            class Body {
                hitpointName = "HitBody";
                armor = 40;
                passThrough = 0.6;
            };
            class Hands {
                hitpointName = "HitHands";
                armor = 40;
                passThrough = 0.6;
            };
            class Chest {
                hitpointName = "HitChest";
                armor = 40;
                passThrough = 0.095;
            };
            class Diaphragm {
                hitpointName = "HitDiaphragm";
                armor = 40;
                passThrough = 0.1;
            };
            class Neck {
                hitpointName = "HitNeck";
                armor = 40;
                passThrough = 0.1;
            };
            class Pelvis {
                hitpointName = "HitPelvis";
                armor = 40;
                passThrough = 0.3;
            };
            };
        };
    };
};
