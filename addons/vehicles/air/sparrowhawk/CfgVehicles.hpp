class CfgVehicles {
    class OPTRE_AV22_Sparrowhawk;
    class OPTRE_AV22A_Sparrowhawk;
    class OPTRE_AV22B_Sparrowhawk;
    class OPTRE_AV22C_Sparrowhawk;
    class CLASS(AV22_Sparrowhawk): OPTRE_AV22_Sparrowhawk {
        SCOPE_PUBLIC;

        displayName = "AV-22 Sparrowhawk";
        side = BLUFOR;
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        magazines[] = {
            "OPTRE_2500Rnd_50mm_HE2",
            "OPTRE_2500Rnd_50mm_HE2",
            "OPTRE_2500Rnd_50mm_HE2",
            "OPTRE_2500Rnd_50mm_APFSDS",
            "OPTRE_2500Rnd_50mm_APFSDS",
            "OPTRE_2500Rnd_50mm_APFSDS",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine"
        };
    };

    class CLASS(AV22A_Sparrowhawk): OPTRE_AV22A_Sparrowhawk {
        SCOPE_PUBLIC;

        displayName = "AV-22A Sparrowhawk";
        side = BLUFOR;
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        magazines[] = {
            "OPTRE_2000Rnd_30mm_HE",
            "OPTRE_2000Rnd_30mm_HE",
            "OPTRE_2000Rnd_30mm_HE",
            "OPTRE_2000Rnd_30mm_HE",
            "OPTRE_2000Rnd_30mm_HE",
            "OPTRE_2000Rnd_30mm_HE",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine"
        };
    };

    class CLASS(AV22B_Sparrowhawk): OPTRE_AV22B_Sparrowhawk {
        SCOPE_PUBLIC;
        displayName = "AV-22B Sparrowhawk";
        side = BLUFOR;
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        magazines[] = {
            "OPTRE_2500Rnd_50mm_HE2",
            "OPTRE_2500Rnd_50mm_HE2",
            "OPTRE_2500Rnd_50mm_HE2",
            "OPTRE_2500Rnd_50mm_APFSDS",
            "OPTRE_2500Rnd_50mm_APFSDS",
            "OPTRE_2500Rnd_50mm_APFSDS",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
        };
    };

    class CLASS(AV22C_Sparrowhawk): OPTRE_AV22C_Sparrowhawk {
        SCOPE_PUBLIC;
        displayName = "AV-22C Sparrowhawk";
        side = BLUFOR;
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        magazines[] = {
            "OPTRE_2000Rnd_30mm_HE",
            "OPTRE_2000Rnd_30mm_HE",
            "OPTRE_2000Rnd_30mm_HE",
            "OPTRE_2000Rnd_30mm_HE",
            "OPTRE_2000Rnd_30mm_HE",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
            "168Rnd_CMFlare_Chaff_Magazine",
        };
    };
};
