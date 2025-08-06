class CfgVehicles {
    class Land_OPTRE_AFB_sign;
    class CLASS(AFB_Sign_1): Land_OPTRE_AFB_sign {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "505th Airbase Sign (BJL)";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Signs);

        hiddenSelections[] = {"Sign"};
        hiddenSelectionsMaterials[] = {QPATHTOF(data\signs\AirbaseSign_NOHQ.paa)};
        hiddenSelectionsTextures[] = {QPATHTOF(data\signs\AirbaseSign1_CO.paa)};
    };

    class CLASS(OP_Sign_1): Land_OPTRE_AFB_sign {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "505th Outpost Sign (NS)";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Signs);

        hiddenSelections[] = {"Sign"};
        hiddenSelectionsMaterials[] = {QPATHTOF(data\signs\AirbaseSign_NOHQ.paa)};
        hiddenSelectionsTextures[] = {QPATHTOF(data\signs\AirbaseSign2_CO.paa)};
    };

    class Banner_01_F;
    class CLASS(Banner_505th): Banner_01_F {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "505th Banner";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Flags);

        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {QPATHTOF(data\flags\505th_co.paa)};
    };

    class Flag_White_F;
    class CLASS(Flag_505th_Pole): Flag_White_F {
        SCOPE_PUBLIC;
        author = AUTHOR;

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Flags);

        displayName = "505th Flag (Pole)";

        class EventHandlers {
            init = QUOTE((_this select 0) setFlagTexture QQPATHTOF(data\flags\505th_co.paa));
        };
    };
    class CLASS(Flag_505th_Damaged_Pole): CLASS(Flag_505th_Pole) {
        displayName = "505th Damaged Flag (Pole)";
        class EventHandlers {
            init = QUOTE((_this select 0) setFlagTexture QQPATHTOF(data\flags\505th_Damaged_co.paa));
        };
    };
};
