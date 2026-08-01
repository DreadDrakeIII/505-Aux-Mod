class CfgMagazines {
    class TCP_15Rnd_762x51_Mag_BTHP;

    // ===============================
    // 30Rnd 7.62x51mm Magazine (LMR11 Shortbow)
    // ===============================
    class CLASS(30Rnd_762x51_Mag): TCP_15Rnd_762x51_Mag_BTHP {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(30Rnd_762x51_Mag);
        author = AUTHOR;

        displayName = "[505th] 30Rnd Shortbow Mag";
        displayNameShort = "7.62x51mm • 30Rnd";
        descriptionShort = "High-capacity magazine • 7.62x51mm Ball";

        picture = "\TCP\Weapons\Ammo\762x51\Ball\data\ui\icon_762x51mm_15rnd_CA.paa";

        // Uses high-power ammo
        ammo = QCLASS(762x51_Ball);

        count = 30;                // low-cap
        initSpeed = 790;           // muzzle velocity (m/s)
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 16.7992;                 // double amount of 15rnd mag (8.3996) + 0.0001 for rounding error
    };
};
