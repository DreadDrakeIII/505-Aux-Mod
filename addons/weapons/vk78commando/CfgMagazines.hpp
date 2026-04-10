class CfgMagazines {
    class TCP_20Rnd_65x48_Mag;

    // ===============================
    // 20Rnd 9.5xVX2 Magazine (VK78)
    // ===============================
    class CLASS(20Rnd_95xVX2_Mag): TCP_20Rnd_65x48_Mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(20Rnd_95xVX2_Mag);
        author = AUTHOR;

        displayName = "[505th] 9.5×VX2 20Rnd Mag";
        displayNameShort = "9.5×VX2 • 20Rnd";
        descriptionShort = "Low-capacity magazine • Hi-Power • 9.5×VX2 Ball";

        // Uses high-power ammo
        ammo = QCLASS(95xVX2_Ball);

        count = 20;                // low-cap
        initSpeed = 850;           // muzzle velocity (m/s)
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 14;                 // slightly heavier round
    };
};
