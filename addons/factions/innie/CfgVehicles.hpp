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
        crew = "OPTRE_Ins_URF_Crewman";
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
    class CLASS(Pelican_Base);
    class CLASS(Innie_Pelican): CLASS(Pelican_Base) {
        displayName = "[Innie] D77-TC Pelican";
        side = OPFOR;
        faction = QFACTION(Innie);
        crew = "OPTRE_Ins_URF_Crewman";
        editorSubcategory = QEDSUBCAT(Helicopters);
        hiddenSelections[] = {"camo1","camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(innie\data\pelican\Body_co.paa),
            QPATHTOF(innie\data\pelican\Wings_co.paa),
            QPATHTOF(innie\data\pelican\Weaponry_co.paa)
        };
    };
};
