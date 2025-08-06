class CfgVehicles {
class B_T_UAV_03_dynamicLoadout_F;
class CLASS(Wyvern): B_T_UAV_03_dynamicLoadout_F {
    SCOPE_PUBLIC;
    displayName = "MQ-72 Wyvern";
    faction = QFACTION(505th);
    editorSubcategory = QEDSUBCAT(Drones);
    crew = "B_UAV_AI";
    hiddenSelections[] = {"Camo_1","Camo_2","Camo_3"};
    hiddenSelectionsTextures[] = {
        QPATHTOF(air\wyvern\data\textures\505th_UAV_03_1_co.paa),
        QPATHTOF(air\wyvern\data\textures\505th_UAV_03_2_co.paa),
        QPATHTOF(air\wyvern\data\textures\505th_UAV_03_1_co.paa)
        };
    };
};
