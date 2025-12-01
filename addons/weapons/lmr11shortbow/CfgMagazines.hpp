class CfgMagazines {
    class CLASS(Mag_Base);

    // ===============================
    // 30Rnd 7.62x51mm Magazine (LMR11 Shortbow)
    // ===============================
    class CLASS(30Rnd_762x51_Mag): CLASS(Mag_Base) {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(30Rnd_762x51_Mag);
        author = AUTHOR;

        displayName = "[505th] 30Rnd 7.62x51mm Mag";
        displayNameShort = "7.62x51mm • 30Rnd";
        descriptionShort = "High-capacity magazine • 7.62x51mm Ball";

        model = "\OPTRE_Weapons\ammoPacketsV2\data\7.62x51\762x51_15rnd.p3d";
        picture = "\OPTRE_weapons\ar\icons\magazine.paa";

        // Uses high-power ammo
        ammo = QCLASS(762x51_Ball);

        count = 30;                // low-cap
        initSpeed = 1400;           // muzzle velocity (m/s)
        tracersEvery = 0;
        lastRoundsTracer = 2;
        mass = 10;                 // slightly heavier round
    };
};
