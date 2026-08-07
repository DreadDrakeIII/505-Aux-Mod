class CfgMagazines {
    class OPTRE_8Rnd_127x40_Mag;

    class CLASS(12Rnd_127x40_Mag): OPTRE_8Rnd_127x40_Mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(12Rnd_127x40_Mag);
        author = AUTHOR;

        displayname = "[505th] 12Rnd M6C Magazine";
        displaynameshort = "12.7x40mm";
        descriptionshort = "12 Round Magazine<br/>12.7x40mm<br/>";

        // Keep vanilla OPTRE models
        model = "\OPTRE_Weapons\Ammo\BR55Ammo.p3d";
        picture = "\A3\Weapons_F\Data\UI\M_30Rnd_45ACP_CA.paa";

        ammo = QCLASS(127x40_Ball);
        count = 12;
        initSpeed = 620;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 7;
    };
};
