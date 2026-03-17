class CfgMagazines {
    class CLASS(Mag_Base);

    // ===============================
    // 10 Rnd 12.7x108mm HDUR Magazine (VTR-93 Vindicta)
    // ===============================
    class CLASS(10Rnd_HDUR): CLASS(Mag_Base) {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(10Rnd_HDUR);
        author = AUTHOR;

        displayName = "[505th] 10Rnd 12.7x108mm HDUR Mag";
        displayNameShort = "12.7x108mm HDUR • 10Rnd";
        descriptionShort = "High-capacity magazine • 12.7x108mm HDUR";

        model = "\A3\weapons_F\ammo\mag_univ.p3d";
        picture = "\A3\Weapons_F_EPA\Data\ui\M_5rnd_127x108_ball_CA.paa";

        // Uses high-power ammo
        ammo = QCLASS(127x108_HDUR);

        count = 10;                // doluble-cap
        initSpeed = 980;           // muzzle velocity (m/s)
        tracersEvery = 1;          // tracer every round
        lastRoundsTracer = 0;      // all rounds are tracers
        mass = 14;                 // slightly heavier round
    };
};
