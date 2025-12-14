class CfgMagazines {
    class OPTRE_8Rnd_127x40_Mag;

    class CLASS(12Rnd_127x40_Mag): OPTRE_8Rnd_127x40_Mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(12Rnd_127x40_Mag);
        author = AUTHOR;

        displayname = "[505th] 12Rnd 12.7x40mm Magazine";
        displaynameshort = "12.7x40mm";
        descriptionshort = "12 Round Magazine<br/>12.7x40mm<br/>";

        // Keep vanilla OPTRE models
        model = "\OPTRE_Weapons\Ammo\BR55Ammo.p3d";
        picture = "\A3\Weapons_F\Data\UI\M_30Rnd_45ACP_CA.paa";

        ammo = QCLASS(127x40_Ball);
        count = 12;
        initSpeed = 600;
        tracersEvery = 0;
        lastRoundsTracer = 2;
        mass = 7;
    };
};
