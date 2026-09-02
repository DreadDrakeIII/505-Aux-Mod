class CfgWeapons {
    class CLASS(OPFOR_Uniform_Base);
    class CLASS(Uniform_Base): CLASS(OPFOR_Uniform_Base){
        class ItemInfo;
    };
    //////////////////////Uniform//////////////////////
    class CLASS(TRNE_Light_Uniform): CLASS(Uniform_Base) {
        SCOPE_HIDDEN;

        displayName = "[505th] TRNE_Light Uniform";

        class ItemInfo: ItemInfo {
            uniformClass = QCLASS(TRNE_Light_Unit_Base);
        };
    };
};
