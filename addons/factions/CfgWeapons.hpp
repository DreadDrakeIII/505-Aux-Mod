class CfgWeapons {
    class HelmetBase;
    class Uniform_Base;
    class Vest_Base_F;
    class CLASS(BLUFOR_Helmet_Base): HelmetBase {
        SCOPE_PRIVATE;
        author = "505th Aux Team";
        displayName = "BLUFOR Helmet Base";
    };

    class CLASS(BLUFOR_Uniform_Base): Uniform_Base {
        SCOPE_PRIVATE;
        author = "505th Aux Team";
        displayName = "BLUFOR Uniform Base";
    };

    class CLASS(BLUFOR_Vest_Base): Vest_Base_F {
        SCOPE_PRIVATE;
        author = "505th Aux Team";
        displayName = "BLUFOR Vest Base";
    };

    class CLASS(OPFOR_Helmet_Base): HelmetBase {
        SCOPE_PRIVATE;
        author = AUTHOR;
        displayName = "OPFOR Helmet Base";
    };

    class CLASS(OPFOR_Uniform_Base): Uniform_Base {
        SCOPE_PRIVATE;
        author = AUTHOR;
        displayName = "OPFOR Uniform Base";
    };

    class CLASS(OPFOR_Vest_Base): Vest_Base_F {
        SCOPE_PRIVATE;
        author = AUTHOR;
        displayName = "OPFOR Vest Base";
        descriptionShort = "Armor Level III";
    };

    class CLASS(INDEP_Helmet_Base): HelmetBase {
        SCOPE_PRIVATE;
        author = AUTHOR;
        displayName = "INDEP Helmet Base";
    };

    class CLASS(INDEP_Uniform_Base): Uniform_Base {
        SCOPE_PRIVATE;
        author = AUTHOR;
        displayName = "INDEP Uniform Base";
    };

    class CLASS(INDEP_Vest_Base): Vest_Base_F {
        SCOPE_PRIVATE;
        author = AUTHOR;
        displayName = "INDEP Vest Base";
    };
};
