class CfgVehicles {
    class JK_B_US_C5M_Super_Galaxy_F;
    class CLASS(C5Galaxy): JK_B_US_C5M_Super_Galaxy_F {
        SCOPE_PUBLIC;

        displayName = "[505th] C-5 Galaxy";
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
            "300Rnd_CMFlare_Chaff_Magazine",
            "300Rnd_CMFlare_Chaff_Magazine",
            "300Rnd_CMFlare_Chaff_Magazine",
            "300Rnd_CMFlare_Chaff_Magazine",
            "300Rnd_CMFlare_Chaff_Magazine"
        };
        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "camo4",
            "camo5",
            "camo6",
            "camo7",
            "camo8",
            "camo9",
            "camo10",
            "camo11",
            "camo12",
            "camo13",
            "camo14",
            "camo15",
            "camo16",
            "camo17",
            "camo18",
            "camo19",
            "camo20",
            "camo21",
            "camo22"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\c5\data\textures\c5_body_front_l_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_front_r_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_front_roof_co.paa),
            QPATHTOF(air\c5\data\textures\c5a_body_fuel_slot_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_middle_l_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_middle_r_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_nose_cone_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_rear_l_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_rear_r_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_rear_roof_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_tail_l_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_tail_r_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_tail_top_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_wing_l_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_wing_r_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_wing_underside_l_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_wing_underside_r_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_rear_ramp_outside_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_engine_side_main_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_engine_pylon_l_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_bottom_middle_co.paa),
            QPATHTOF(air\c5\data\textures\c5_body_airmobility_co.paa)
        };
    };
};
