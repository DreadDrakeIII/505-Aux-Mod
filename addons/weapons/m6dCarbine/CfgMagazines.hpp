class CfgMagazines {
    class CLASS(Mag_Base);

    class CLASS(26Rnd_9x21_Mag): CLASS(Mag_Base) {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(26Rnd_9x21_Mag);
        author = AUTHOR;

        displayname = "[505th] 26Rnd 9x21mm Magazine";
        displaynameshort = "9x21mm Magazine";
        descriptionshort = "26 Round Magazine developed by Blackreach Armory Industries<br/>9x21mm<br/>";

        model = "\OPTRE_Weapons\ammoPacketsV2\data\12.7x40\12.7x40mm_26_T.p3d";
        picture = "\OPTRE_Weapons_Pistols\M6D\Data\icons\magazine\bigstick\Gray.paa";

        ammo = QCLASS(9x21_Ball);
        count = 26;
        initSpeed = 620;
        tracersEvery = 2;
        lastRoundsTracer = 12;
        mass = 7;
    };
};
