class CfgMagazines {
    class CLASS(Mag_Base);

    class CLASS(25Rnd_762xV7_Mag): CLASS(Mag_Base) {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(25Rnd_762xV7_Mag);
        author = AUTHOR;

        displayName = "[505th] 7.62xV7 25Rnd Mag";
        displayNameShort = "7.62×51mm 25Rnd";
        descriptionShort = "High-capacity magazine • 7.62×V7 Ball";

        model = "\OPTRE_Weapons\ammoPacketsV2\data\7.62x51\762x51_25rnd.p3d";
        picture = "\OPTRE_weapons\ar\icons\magazine.paa";

        ammo = QCLASS(762xV7_Ball);
        count = 25;
        initSpeed = 1000;
        tracersEvery = 0;
        lastRoundsTracer = 5;
        mass = 10;
    };
};
