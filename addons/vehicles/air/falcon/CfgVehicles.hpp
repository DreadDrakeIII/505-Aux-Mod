class CfgVehicles {
    class OPTRE_UNSC_falcon;
    class CLASS(Falcon): OPTRE_UNSC_falcon {
        SCOPE_PUBLIC;

        displayName = "[505th] UH-144 Falcon";

        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        gunnerType = QCLASS(Marine_Heli_Crew);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        armor = 180;
        magazines[] = {
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "Laserbatteries"
        };

        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "camoGlass",
            "camoGlassPilot",
            "camoDecal",
            "attach_gun",
            "attach_sideguns"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Main_co.paa),
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Attachments_co.paa),
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Interior_co.paa),
            "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa",
            "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa",
            QPATHTOF(air\vespoid\data\textures\505th_Falcon_Decal_ca.paa)
        };
    };

    class OPTRE_UNSC_falcon_S;
    class CLASS(Falcon_Armed): OPTRE_UNSC_falcon_S {
        SCOPE_PUBLIC;

        displayName = "[505th] UH-144S Falcon";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        gunnerType = QCLASS(Marine_Heli_Crew);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        armor = 180;
        magazines[] = {
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "Laserbatteries"
        };

        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "camoGlass",
            "camoGlassPilot",
            "camoDecal",
            "attach_gun",
            "attach_sideguns"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Main_co.paa),
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Attachments_co.paa),
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Interior_co.paa),
            "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa",
            "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa",
            QPATHTOF(air\vespoid\data\textures\505th_Falcon_Decal_ca.paa)
        };
    };
};
