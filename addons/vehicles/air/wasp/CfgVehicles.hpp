class CfgVehicles {
    class B_UAV_02_dynamicLoadout_F;
    class CLASS(Wasp): B_UAV_02_dynamicLoadout_F {
        SCOPE_PUBLIC;
        displayName = "[505th] R50-Wasp";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Drones);
        crew = "B_UAV_AI";
        hiddenSelections[] = {"camo1"};
        hiddenSelectionsTextures[] = {QPATHTOF(air\wasp\data\textures\505th_uav_02_co.paa)};
    };
};
