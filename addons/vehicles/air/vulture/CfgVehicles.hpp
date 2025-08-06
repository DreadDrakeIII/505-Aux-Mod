class CfgVehicles {
    class B_UAV_05_F;
    class CLASS(Vulture): B_UAV_05_F {
        SCOPE_PUBLIC;

        displayName = "UCAV Vulture";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Drones);
        crew = "B_UAV_AI";
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo_engine_fire"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\vulture\data\textures\505th_UAV05_fuselage_01_co.paa),
            QPATHTOF(air\vulture\data\textures\505th_UAV05_fuselage_02_co.paa),
            "A3\Air_F_Jets\UAV_05\Data\UAV05_engine_fire_ca.paa"
        };
    };
};
