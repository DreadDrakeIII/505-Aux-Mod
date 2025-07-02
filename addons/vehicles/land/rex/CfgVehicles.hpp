class CfgVehicles {
    class B_UGV_01_F;
    class CLASS(Rex_Unarmed): B_UGV_01_F {
        SCOPE_PUBLIC;
        displayName = "[505th] 200-Rex (Unarmed)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Drones);
        crew = "B_UAV_AI";
        armor = 90;
        hiddenSelections[] = {"camo1","camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\rex\data\textures\505th_Rex_EXT1_co.paa),
            QPATHTOF(land\rex\data\textures\505th_Rex_INT_co.paa),
            QPATHTOF(land\rex\data\textures\505th_Turret_co.paa)
        };
    };

class B_UGV_01_rcws_F;
class CLASS(Rex_Armed): B_UGV_01_rcws_F {
    SCOPE_PUBLIC;
    displayName = "[505th] 220-Rex (Armed)";
    faction = QFACTION(505th);
    editorSubcategory = QEDSUBCAT(Drones);
    crew = "B_UAV_AI";
    armor = 90;
    hiddenSelections[] = {"camo1","camo2","camo3"};
    hiddenSelectionsTextures[] = {
        QPATHTOF(land\rex\data\textures\505th_Rex_EXT1_co.paa),
        QPATHTOF(land\rex\data\textures\505th_Rex_INT_co.paa),
        QPATHTOF(land\rex\data\textures\505th_Turret_co.paa)
        };
    };
};
