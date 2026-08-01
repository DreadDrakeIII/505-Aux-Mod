class CfgMagazines {
    class TCP_36Rnd_95x40_Mag_Green;

    class CLASS(36Rnd_95x40_Mag): TCP_36Rnd_95x40_Mag_Green {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(36Rnd_95x40_Mag);

        author = AUTHOR;

        displayName = "[505th] 36Rnd BR55HB Mag";
        displayNameShort = "9.5x40mm Mag";
        descriptionShort = "9.5x40mm Magazine for BR55HB Battle Rifle developed by Blackreach Armory";

        ammo = QCLASS(95_40_Ball);
        count = 36;
        initSpeed = 900;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 10;
    };
};
