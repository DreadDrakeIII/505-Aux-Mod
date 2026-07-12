class CfgMagazines {
    class OPTRE_32Rnd_762x51_Mag;

    class CLASS(32Rnd_762x51_Mag): OPTRE_32Rnd_762x51_Mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(32Rnd_762x51_Mag);
        author = AUTHOR;

        displayName = "[505th] 32Rnd MA37K Mag";
        displayNameShort = "32Rnd 7.62x51mm Mag";
        descriptionShort = "32 Rounds Magazine developed by Blackreach Armory";

        ammo = QCLASS(762x51_Ball);
        count = 32;
        initSpeed = 870;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 10;
    };
};
