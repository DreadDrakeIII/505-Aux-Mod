class CfgMagazines {
    class OPTRE_36Rnd_95x40_Mag;

    class CLASS(32Rnd_95x40_Mag): OPTRE_36Rnd_95x40_Mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(32Rnd_95x40_Mag);
        author = AUTHOR;

        displayName = "[505th] 32Rnd 9.5x40mm Mag";
        displayNameShort = "9.5x40mm Mag";
        descriptionShort = "Calibre: 9.5x40mm • 32-round magazine";

        ammo = QCLASS(95_40_Ball);
        count = 32;
        initSpeed = 900;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 10;
    };
};
