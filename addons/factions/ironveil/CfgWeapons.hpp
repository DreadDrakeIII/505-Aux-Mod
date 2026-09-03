class CfgWeapons {
    //////////////////////Headgear//////////////////////
    class CLASS(OPFOR_Helmet_Base);
    class CLASS(IRON_Helmet_Base): CLASS(OPFOR_Helmet_Base) {
        class ItemInfo;
    };

    class CLASS(IRON_Cap): CLASS(IRON_Helmet_Base) {
        SCOPE_HIDDEN;

        author = AUTHOR;
        displayName = "[IRON] Ironveil Field Cap";
        model = "\A3\Characters_F\Common\cappatrol";
        hiddenSelections[] = {"camo"};
        // TODO: retexture - drop a .paa in data\textures\ and point this at it.
        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo"};
            uniformModel = "\A3\Characters_F\Common\cappatrol";
        };
    };

    class CLASS(IRON_Boonie): CLASS(IRON_Helmet_Base) {
        SCOPE_HIDDEN;

        author = AUTHOR;
        displayName = "[IRON] Ironveil Boonie";
        model = "A3\Characters_F_EPB\Common\booniehat_hs.p3d";
        hiddenSelections[] = {"camo"};
        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"camo"};
            uniformModel = "A3\Characters_F_EPB\Common\booniehat_hs.p3d";
        };
    };

    //////////////////////Uniform//////////////////////
    class CLASS(OPFOR_Uniform_Base);
    class CLASS(IRON_Uniform_Base): CLASS(OPFOR_Uniform_Base) {
        class ItemInfo;
    };

    class CLASS(IRON_Uniform): CLASS(IRON_Uniform_Base) {
        SCOPE_HIDDEN;

        author = AUTHOR;
        displayName = "[IRON] Ironveil Combat Fatigues";

        class ItemInfo: ItemInfo {
            uniformClass = QCLASS(IRON_Unit_Base);
            containerClass = "Supply40";
            mass = 40;
        };
    };

    ///////////////////////Vests///////////////////////
    class CLASS(OPFOR_Vest_Base);
    class CLASS(IRON_Vest_Base): CLASS(OPFOR_Vest_Base) {
        class ItemInfo;
    };

    class CLASS(IRON_Vest): CLASS(IRON_Vest_Base) {
        SCOPE_HIDDEN;

        author = AUTHOR;
        displayName = "[IRON] Ironveil Carrier Rig";
        descriptionShort = "Armor Level III";
        modelSides[] = {OPFOR};

        model = "\A3\Characters_F_Enoch\Vests\V_Carrier_RigKBT_01_light_F.p3d";
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {"a3\characters_f_enoch\vests\data\carrierrigkbt_01_olive_co.paa"};

        class ItemInfo: ItemInfo {
            hiddenSelections[] = {"Camo"};
            uniformModel = "\A3\Characters_F_Enoch\Vests\V_Carrier_RigKBT_01_light_F.p3d";
            vestType = "Rebreather";
            containerClass = "Supply100";
            mass = 60;
            SC_VEST_HITPOINTS_MEDIUM;
        };
    };

    class CLASS(IRON_Vest_Heavy): CLASS(IRON_Vest_Base) {
        SCOPE_HIDDEN;

        author = AUTHOR;
        displayName = "[IRON] Ironveil Assault Rig";
        descriptionShort = "Armor Level IV";
        modelSides[] = {OPFOR};

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
            containerClass = "Supply120";
            mass = 80;
            SC_VEST_HITPOINTS_HEAVY;
        };
    };
};
