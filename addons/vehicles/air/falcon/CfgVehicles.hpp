class CfgVehicles {
    class OPTRE_UNSC_falcon_S;
    class OPTRE_UNSC_falcon_armed;

    class CLASS(Falcon): OPTRE_UNSC_falcon_S {
        SCOPE_PUBLIC;

        displayName = "UH-144 Falcon";

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
    };
        class CLASS(Falcon_Armed): OPTRE_UNSC_falcon_armed {
        SCOPE_PUBLIC;

        displayName = "UH-144 Falcon Armed";

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
    };
};
