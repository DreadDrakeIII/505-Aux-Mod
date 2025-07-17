class CfgVehicles {
    class FIR_C130J_Blank;
    class CLASS(C130J): FIR_C130J_Blank {
        SCOPE_PUBLIC;

        displayName = "[505th] C-130J";
        side = BLUFOR;
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Planes);
        crew = QCLASS(Marine_Jet_Pilot);
        weapons[] = {
            "CMFlareLauncher"
        };
        magazines[] = {
            "300Rnd_CMFlare_Chaff_Magazine",
            "300Rnd_CMFlare_Chaff_Magazine",
            "300Rnd_CMFlare_Chaff_Magazine",
            "300Rnd_CMFlare_Chaff_Magazine",
            "300Rnd_CMFlare_Chaff_Magazine"
        };
        hiddenSelections[] = {
            "camo1",
            "camo1_R",
            "camo2",
            "camo2_R",
            "fueltank_center",
            "decal_nose",
            "decal_wing",
            "decal_tail",
            "insignia"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\c130\data\textures\505th_C130_Body_L_co.paa),
            QPATHTOF(air\c130\data\textures\505th_C130_Body_R_co.paa),
            QPATHTOF(air\c130\data\textures\505th_C130_Wings_co.paa),
            QPATHTOF(air\c130\data\textures\505th_C130_Wings_co.paa),
            QPATHTOF(air\c130\data\textures\505th_C130_FuelTank_co.paa)
        };
    };
};
