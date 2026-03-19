class CfgMagazines {
    class WRS_Ar1_Magazine;

    class CLASS(40rnd_65x39_LDUR): WRS_Ar1_Magazine {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(40rnd_65x39_LDUR);
        author = AUTHOR;

        displayName = "[505th] 40Rnd 6.5x39mm LDUR Mag";
        displayNameShort = "40Rnd 6.5mm LDUR";
        descriptionShort = "Light Depleted Uranium rounds magazine developed by Blackreach Armory Industries.";

        ammo = QCLASS(65x39_LDUR);
        count = 40;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 9;
    };
};
