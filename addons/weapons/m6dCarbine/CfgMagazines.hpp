class CfgMagazines {
    class OPTRE_26Rnd_127x40_Mag_Tracer;

    class CLASS(40Rnd_127x40_Mag): OPTRE_26Rnd_127x40_Mag_Tracer {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(40Rnd_127x40_Mag);
        author = AUTHOR;

        displayname = "[505th] 40Rnd 12.7x40mm Magazine";
        displaynameshort = "12.7x40mm Magazine";
        descriptionshort = "40 Round Magazine developed by Blackreach Armory Industries<br/>12.7x40mm<br/>";

        model = "\OPTRE_Weapons\ammoPacketsV2\data\12.7x40\12.7x40mm_26_T.p3d";
        picture = "\OPTRE_Weapons_Pistols\M6D\Data\icons\magazine\bigstick\Gray.paa";

        ammo = QCLASS(127x40_Tracer);
        count = 40;
        initSpeed = 620;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 7;
    };
};
