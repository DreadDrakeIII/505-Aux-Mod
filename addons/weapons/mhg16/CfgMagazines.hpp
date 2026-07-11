class CfgMagazines {
    class TKE_MDPistol_mag;

    class CLASS(12Rnd_45ACP_Mag): TKE_MDPistol_mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(12Rnd_45ACP_Mag);
        author = AUTHOR;

        displayname = "[505th] 12Rnd MHG16 Magazine";
        displaynameshort = ".45 ACP";
        descriptionshort = "12 Round Magazine developed by Blackreach Armory Industries<br/>.45 ACP<br/>";

        count = 12;
        initSpeed = 620;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 6;
    };
};
