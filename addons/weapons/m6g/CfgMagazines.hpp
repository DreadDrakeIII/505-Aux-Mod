class CfgMagazines {
    class TCP_8Rnd_127x30_52_Mag;

    class CLASS(8Rnd_127x40_Mag): TCP_8Rnd_127x30_52_Mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(8Rnd_127x40_Mag);
        author = AUTHOR;

        displayname = "[505th] 8Rnd M6G Magazine";
        displaynameshort = "12.7x40mm";
        descriptionshort = "8 Round Magazine<br/>12.7x40mm<br/>";

        ammo = QCLASS(127x40_Ball);
        count = 8;
        initSpeed = 620;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 5;
    };
};
