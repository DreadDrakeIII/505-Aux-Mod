class CfgVehicles {
    class FIR_F16C_Blank;
    class CLASS(F16): FIR_F16C_Blank {
        SCOPE_PUBLIC;

        displayName = "[505th] F-16";
        side = BLUFOR;
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Planes);
        crew = QCLASS(Marine_Jet_Pilot);
        magazines[] = {
            "FIR_M61A2_511rnd_M",
            "FIR_M61A2_511rnd_M",
            "FIR_M61A2_511rnd_M",
            "FIR_240rnd_CMFlare_Chaff_Magazine",
            "FIR_240rnd_CMFlare_Chaff_Magazine",
            "FIR_240rnd_CMFlare_Chaff_Magazine",
            "FIR_240rnd_CMFlare_Chaff_Magazine",
            "FIR_240rnd_CMFlare_Chaff_Magazine"
        };
        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "camo4",
            "insignia",
            "decal_nose",
            "decal_wing",
            "decal_tail",
            "mfd_overlay2",
            "mfd_tad",
            "tad",
            "sms_1",
            "sms_2",
            "sms_3",
            "sms_4",
            "sms_5",
            "sms_6",
            "sms_7",
            "sms_8",
            "sms_9",
            "ded_freq_1",
            "ded_freq_2",
            "ded_freq_3",
            "map",
            "rendertarget0",
            "plate_name_1",
            "plate_name_2",
            "plate_number"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\f16\data\textures\505th_body_co.paa),
            QPATHTOF(air\f16\data\textures\505th_wings_co.paa),
            QPATHTOF(air\f16\data\textures\505th_tail_co.paa)
        };
    };
};
