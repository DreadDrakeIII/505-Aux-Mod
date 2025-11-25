class CfgMagazines {
    class OPTRE_100Rnd_95x40_Box;

    class CLASS(100Rnd_95x40_Box): OPTRE_100Rnd_95x40_Box {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(100Rnd_95x40_Box);
        author = AUTHOR;

        displayName = "[505th] 100Rnd 9.5x40mm Box";
        displayNameShort = "100Rnd 9.5x40mm Box";
        descriptionShort = "100 Rounds Box • 9.5x40mm Ball";

        // Keep vanilla OPTRE models
        model = "\OPTRE_Weapons\ammoPacketsV2\data\9.5x40\9.5x40_100rnd.p3d";
        modelSpecial = "\OPTRE_Weapons_MG\m73\m73_mag_proxy.p3d";  // THIS IS THE KEY!
        picture = "\OPTRE_Weapons_MG\m247\data\icons\magazine.paa";

        hiddenSelections[] = {"camo1"};
        hiddenSelectionsTextures[] = {"\OPTRE_Weapons_MG\m73\data\M73_100rndBox_co.paa"};

        ammo = QCLASS(LMG_95_40_Ball);
        count = 100;
        initSpeed = 950;
        tracersEvery = 0;
        lastRoundsTracer = 5;
        mass = 30;
    };
};
