class CfgVehicles {
    //===============================
    // G42 RENZAN BOMBER
    //===============================
    class SC_Fixed_Bomber_01;
    class CLASS(G42_Renzan_Base): SC_Fixed_Bomber_01 {
        SCOPE_HIDDEN;
        displayName = "G42 Renzan Heavy Bomber (Base)";
        side = OPFOR;
        faction = QFACTION(Innie);
        crew = "TCP_O_INS_M_Soldier_Engineer";
        editorSubcategory = QEDSUBCAT(Planes);
        hiddenSelections[] = {"camo1","camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(innie\data\g42\Body_co.paa),
            QPATHTOF(innie\data\g42\Details_co.paa)
        };
    };

    class CLASS(G42_Renzan): CLASS(G42_Renzan_Base) {
        SCOPE_PUBLIC;
        displayName = "[Innie] G42 Renzan Heavy Bomber";
    };
};
