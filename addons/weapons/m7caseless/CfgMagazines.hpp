class CfgMagazines {
    class CLASS(Mag_Base);

    class CLASS(60Rnd_9x21_Mag): CLASS(Mag_Base) {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(60Rnd_9x21_Mag);
        author = AUTHOR;

        displayname = "[505th] 60Rnd 9x21mm Magazine";
        displaynameshort = "9x21mm";
        descriptionshort = "60 Round Magazine<br/>9x21mm<br/>";

        model = "\OPTRE_Weapons\ammoPacketsV2\data\5x23\5x23mm_60rnd.p3d";
        picture = "\OPTRE_weapons\smg\icons\magazine.paa";

        ammo = QCLASS(9x21_Ball);
        count = 60;
        initSpeed = 620;
        tracersEvery = 0;
        lastRoundsTracer = 2;
        mass = 10;
    };
};
