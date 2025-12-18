class CfgMagazines {
    class OPTRE_400Rnd_762x51_Box;

    class CLASS(400Rnd_762x51_Box): OPTRE_400Rnd_762x51_Box {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(400Rnd_762x51_Box);
        author = AUTHOR;

        displayName = "[505th] 400Rnd 7.62x51mm Box";
        displayNameShort = "400Rnd 7.62x51mm Box";
        descriptionShort = "400 Rounds Box • 7.62x51mm Ball";

        model = "\OPTRE_Weapons\ammoPacketsV2\data\7.62x51\762x51_100rnd.p3d";
        modelSpecial = "\OPTRE_Weapons_MG\m247\M247_Mag_Proxy.p3d";
        picture = "\OPTRE_Weapons_MG\m247\data\icons\magazine.paa";

        ammo = QCLASS(762x51_Ball);
        count = 400;
        initSpeed = 950;
        tracersEvery = 4;
        lastRoundsTracer = 5;
        mass = 96;
    };
};
