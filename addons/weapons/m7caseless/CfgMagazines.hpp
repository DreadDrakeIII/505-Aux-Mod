class CfgMagazines {
    class OPTRE_60Rnd_5x23mm_Mag;

    class CLASS(60Rnd_5x23_Mag): OPTRE_60Rnd_5x23mm_Mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(60Rnd_5x23_Mag);
        author = AUTHOR;

        displayname = "[505th] 60Rnd 5x23mm Caseless Magazine";
        displaynameshort = "5x23mm";
        descriptionshort = "60 Round Caseless Magazine<br/>5x23mm<br/>";

        model = "\OPTRE_Weapons\ammoPacketsV2\data\5x23\5x23mm_60rnd.p3d";
        picture = "\OPTRE_weapons\smg\icons\magazine.paa";

        ammo = QCLASS(5x23_Caseless);
        count = 60;
        initSpeed = 620;
        tracersEvery = 0;
        lastRoundsTracer = 2;
        mass = 10;
    };
};
