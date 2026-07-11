class CfgMagazines {
    class 30Rnd_9x21_Mag_SMG_02;

    class CLASS(32Rnd_9x21_Mag): 30Rnd_9x21_Mag_SMG_02 {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(32Rnd_9x21_Mag);
        author = AUTHOR;

        displayname = "[505th] 32Rnd MPK5 Magazine";
        displaynameshort = "9x21mm Magazine";
        descriptionshort = "32 Round Magazine developed by Blackreach Armory Industries<br/>9x21mm<br/>";

        model = "\A3\weapons_F\ammo\mag_univ.p3d";
        picture = "\A3\weapons_f\data\ui\M_30Rnd_9x21_CA.paa";

        ammo = QCLASS(SMG_9x21_Ball);
        count = 32;
        initSpeed = 620;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 10;
    };
};
