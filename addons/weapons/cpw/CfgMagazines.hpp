class CfgMagazines {
    class 30Rnd_9x21_Mag;

    class CLASS(30Rnd_9x21_Mag): 30Rnd_9x21_Mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(30Rnd_9x21_Mag);
        author = AUTHOR;

        displayname = "[505th] 30Rnd 9x21mm Magazine";
        displaynameshort = "9x21mm";
        descriptionshort = "30 Round Magazine<br/>9x21mm<br/>";

        model = "\A3\weapons_F\ammo\mag_univ.p3d";
        picture = "\A3\Weapons_F\Data\UI\M_30Rnd_45ACP_CA.paa";

        ammo = QCLASS(SMG_9x21_Ball);
        count = 30;
        initSpeed = 620;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 7;
    };
};
