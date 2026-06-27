class CfgMagazines {
    class TCP_100Rnd_762x51_Mag;
    class TCP_200Rnd_762x51_Mag;

    class CLASS(100Rnd_95x40_Box): TCP_100Rnd_762x51_Mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(100Rnd_95x40_Box);
        author = AUTHOR;

        displayName = "[505th] 100Rnd 9.5x40mm Box";
        displayNameShort = "100Rnd 9.5x40mm Box";
        descriptionShort = "100 Rounds Box developed by Blackreach Armory";

        ammo = QCLASS(LMG_95_40_Ball);
        count = 100;
        initSpeed = 950;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 30;
    };

    class CLASS(400Rnd_95x40_Box): TCP_200Rnd_762x51_Mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(400Rnd_95x40_Box);
        author = AUTHOR;

        displayName = "[505th] 400Rnd 9.5x40mm Box";
        displayNameShort = "400Rnd 9.5x40mm Box";
        descriptionShort = "400 Rounds Box developed by Blackreach Armory";

        ammo = QCLASS(LMG_95_40_Ball);
        count = 400;
        initSpeed = 950;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 60;
    };
};
