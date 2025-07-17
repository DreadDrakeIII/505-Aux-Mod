class CfgVehicles {
    class OPTRE_UNSC_hornet_CAP;
    class OPTRE_UNSC_hornet_CAS;
    class CLASS(Hornet_CAP): OPTRE_UNSC_hornet_CAP {
        SCOPE_PUBLIC;
        displayName = "[505th] AV-14 Hornet (CAP)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        magazines[] = {
            "OPTRE_2000Rnd_20mm_HEIAP",
            "OPTRE_2000Rnd_20mm_HEIAP",
            "OPTRE_2000Rnd_20mm_HEIAP",
            "OPTRE_2000Rnd_20mm_HEIAP",
            "OPTRE_8Rnd_C2GMLS_missiles",
            "OPTRE_8Rnd_C2GMLS_missiles",
            "OPTRE_8Rnd_C2GMLS_missiles",
            "OPTRE_8Rnd_C2GMLS_missiles",
            "OPTRE_8Rnd_C2GMLS_missiles",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "Laserbatteries"
        };
    };

    class CLASS(Hornet_CAS): OPTRE_UNSC_hornet_CAS {
        SCOPE_PUBLIC;
        displayName = "[505th] AV-14 Hornet (CAS)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        magazines[] = {
            "OPTRE_2000Rnd_20mm_HEIAP",
            "OPTRE_2000Rnd_20mm_HEIAP",
            "OPTRE_2000Rnd_20mm_HEIAP",
            "OPTRE_2000Rnd_20mm_HEIAP",
            "OPTRE_8Rnd_C2GMLS_missiles",
            "OPTRE_8Rnd_C2GMLS_missiles",
            "OPTRE_8Rnd_C2GMLS_missiles",
            "OPTRE_8Rnd_C2GMLS_missiles",
            "OPTRE_8Rnd_C2GMLS_missiles",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "Laserbatteries"
        };
    };
};
