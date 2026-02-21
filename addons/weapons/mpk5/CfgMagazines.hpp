class CfgMagazines {
    class CLASS(Mag_Base);

    class CLASS(32Rnd_9x21_Mag): CLASS(Mag_Base) {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(32Rnd_9x21_Mag);
        author = AUTHOR;

        displayname = "[505th] 32Rnd 9x21mm Magazine";
        displaynameshort = "9x21mm Magazine";
        descriptionshort = "32 Round Magazine developed by Blackreach Armory Industries<br/>9x21mm<br/>";

        model = "\A3\weapons_F\ammo\mag_univ.p3d";
        picture = "\A3\weapons_f\data\ui\M_30Rnd_9x21_CA.paa";

        ammo = QCLASS(9x21_Ball);
        count = 32;
        initSpeed = 620;
        tracersEvery = 0;
        lastRoundsTracer = 2;
        mass = 10;
    };
};
