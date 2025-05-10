class CFGVehicles {
    class OPTRE_M808B2;
    class CLASS(Sundevil): OPTRE_M808B2 {
        SCOPE_PUBLIC;

        displayName = "[505th] M808B2 Sun Devil";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Anti_Air);
        crew = QCLASS(Marine_Rifleman_CE);
        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "camo4",
            "camo5",
            "camo6"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\sundevil\data\textures\505th_body_lopo_co.paa),
            QPATHTOF(land\sundevil\data\textures\505th_cing_dv_m808s_co.paa),
            QPATHTOF(land\sundevil\data\textures\505th_cing_rt_m808s_co.paa),
            QPATHTOF(land\sundevil\data\textures\505th_turretbase_lopo_co.paa),
            QPATHTOF(land\sundevil\data\textures\505th_sun_devil_head_lopo_co.paa),
            QPATHTOF(land\sundevil\data\textures\505th_sun_devil_gun_lopo_co.paa)
        };
    };
};