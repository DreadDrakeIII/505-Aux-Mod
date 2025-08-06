class CfgVehicles {
    class FIR_AV8B_NA_Blank;
    class CLASS(AV8B): FIR_AV8B_NA_Blank {
        SCOPE_PUBLIC;

        displayName = "AV-8B Harrier II";
        side = BLUFOR;
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Planes);
        crew = QCLASS(Marine_Jet_Pilot);
        weapons[] = {
            "FIR_MasterArm",
            "FIR_GAU12",
            "FIR_CMLauncher"
        };
        magazines[] = {
            "FIR_GAU12_300rnd_M",
            "FIR_GAU12_300rnd_M",
            "FIR_GAU12_300rnd_M",
            "FIR_GAU12_300rnd_M",
            "FIR_GAU12_300rnd_M",
            "FIR_240rnd_CMFlare_Chaff_Magazine",
            "FIR_240rnd_CMFlare_Chaff_Magazine",
            "FIR_240rnd_CMFlare_Chaff_Magazine",
            "FIR_240rnd_CMFlare_Chaff_Magazine",
            "FIR_240rnd_CMFlare_Chaff_Magazine"
        };
        hiddenSelections[] = {
            "camo1",
            "camo2",
            "cam_tracking",
            "insignia",
            "decal_nose",
            "decal_wing",
            "decal_tail",
            "mfd_overlay",
            "map",
            "mirror_1_tex",
            "mirror_2_tex",
            "mirror_3_tex",
            "plate_name_1",
            "plate_name_3",
            "plate_number"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\harrier\data\textures\505th_Harrier_body_co.paa),
            QPATHTOF(air\harrier\data\textures\505th_Harrier_wing_co.paa)
        };
    };
};
