class CfgVehicles {
    class SC_Fixed_Bomber_01;
    class CLASS(G42_Renzan_Base): SC_Fixed_Bomber_01 {
        scope = 1;
        scopeCurator = 1;
        displayName = "G42 Renzan Heavy Bomber (Base)";
        side = OPFOR;
        faction = QFACTION(Innie);
        crew = "OPTRE_Ins_URF_Crewman";
        editorSubcategory = QEDSUBCAT(Planes);
        hiddenSelections[] = {"camo1","camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\renzanbomber\data\textures\innie\Body_co.paa),
            QPATHTOF(air\renzanbomber\data\textures\innie\Detials_co.paa)
        };
    };

    class CLASS(G42_Renzan): CLASS(G42_Renzan_Base) {
        scope = 2;
        scopeCurator = 2;
        displayName = "G42 Renzan Heavy Bomber";
    };
};
