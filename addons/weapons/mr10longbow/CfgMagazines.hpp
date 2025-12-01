class CfgMagazines {
    class CLASS(Mag_Base);

    // ===============================
    // 15Rnd 9.5xVX2 Magazine (MR10 Longbow)
    // ===============================
    class CLASS(15Rnd_95xVX2_Mag): CLASS(Mag_Base) {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(15Rnd_95xVX2_Mag);
        author = AUTHOR;

        displayName = "[505th] 9.5×VX2 15Rnd Mag";
        displayNameShort = "9.5×VX2 • 15Rnd";
        descriptionShort = "Low-capacity magazine • Hi-Power • 9.5×VX2 Ball";

        model = "\A3\weapons_F\ammo\mag_univ.p3d";
        picture = "\A3\Weapons_F_Mark\Data\UI\M_338_CA.paa";

        // Uses high-power ammo
        ammo = QCLASS(95xVX2_Ball);

        count = 15;                // low-cap
        initSpeed = 1400;           // muzzle velocity (m/s)
        tracersEvery = 0;
        lastRoundsTracer = 2;
        mass = 10;                 // slightly heavier round
    };
};
