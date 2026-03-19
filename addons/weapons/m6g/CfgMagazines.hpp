class CfgMagazines {
    class OPTRE_8Rnd_127x40_Mag;

    class CLASS(8Rnd_127x40_Mag): OPTRE_8Rnd_127x40_Mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(8Rnd_127x40_Mag);
        author = AUTHOR;

        displayname = "[505th] 8Rnd 12.7x40mm Magazine";
        displaynameshort = "12.7x40mm";
        descriptionshort = "8 Round Magazine<br/>12.7x40mm<br/>";

        // Keep vanilla OPTRE models
        model = "\OPTRE_Weapons\ammoPacketsV2\data\12.7x40\12.7x40mm_8.p3d";
        modelSpecial = "\OPTRE_Weapons_Pistols\data\m6_magazine.p3d";
        picture = "\OPTRE_Weapons_Pistols\data\magazine.paa";

        ammo = QCLASS(127x40_Ball);
        count = 8;
        initSpeed = 620;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 5;
    };
};
