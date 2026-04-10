class CfgMagazines {
    class TCP_32Rnd_762x51_Mag;

    class CLASS(40Rnd_762x51_Mag): TCP_32Rnd_762x51_Mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(40Rnd_762x51_Mag);
        author = AUTHOR;

        displayName = "[505th] 40Rnd 7.62x51mm Mag";
        displayNameShort = "40Rnd 7.62x51mm Mag";
        descriptionShort = "40 Rounds Magazine developed by Blackreach Armory";

        ammo = QCLASS(762x51_Ball);
        count = 40;
        initSpeed = 870;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 10;
    };
};
