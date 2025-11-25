class CfgMagazines {
    class CLASS(Mag_Base);

    class CLASS(32Rnd_95x40_Mag): CLASS(Mag_Base) {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(32Rnd_95x40_Mag);
        author = AUTHOR;

        displayName = "[505th] 32Rnd 9.5x40mm Mag";
        displayNameShort = "9.5x40mm Mag";
        descriptionShort = "Calibre: 9.5x40mm • 32-round magazine";

        // model = "\OPTRE_Weapons\ammoPacketsV2\data\95x40\95x40_32rnd.p3d";
        picture = "\OPTRE_weapons\br\icons\magazine.paa";

        ammo = QCLASS(95_40_Ball);
        count = 32;
        initSpeed = 900;
        tracersEvery = 0;
        lastRoundsTracer = 6;
        mass = 10;
    };
};
