class CfgMagazines {
    class CLASS(Mag_Base);

    class CLASS(32Rnd_762x51_Mag): CLASS(Mag_Base) {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(32Rnd_762x51_Mag);
        author = AUTHOR;

        displayName = "[505th] 32Rnd 7.62x51mm Mag";
        displayNameShort = "32Rnd 7.62×51mm";
        descriptionShort = "32 Rounds magazine • 7.62×51mm Ball";

        model = "\OPTRE_Weapons\ammoPacketsV2\data\7.62x51\762x51_32rnd.p3d";
        picture = "\OPTRE_weapons\ar\icons\magazine.paa";

        ammo = QCLASS(762x51_Ball);
        count = 32;
        initSpeed = 870;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 10;
    };
};
