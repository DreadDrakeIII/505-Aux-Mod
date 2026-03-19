class CfgMagazines {
    class TKE_100rnd_ucnmmg_mag;

    class CLASS(100_338_box): TKE_100rnd_ucnmmg_mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(100_338_box);
        author = AUTHOR;

        displayname = "[505th] 100Rnd 338 Box";
        displaynameshort = "338 Box";
        descriptionshort = "100 Round 338 Box developed by Blackreach Armory Industries";

        ammo = QCLASS(338_Ball);
        initSpeed = 950;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        count = 100;
        mass = 30;
    };
};
