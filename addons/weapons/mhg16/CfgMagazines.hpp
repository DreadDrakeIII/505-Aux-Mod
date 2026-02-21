class CfgMagazines {
    class TKE_MDPistol_mag;

    class CLASS(12Rnd_45ACP_Mag): TKE_MDPistol_mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(12Rnd_45ACP_Mag);
        author = AUTHOR;

        displayname = "[505th] 12Rnd .45 ACP Magazine";
        displaynameshort = ".45 ACP";
        descriptionshort = "12 Round Magazine<br/>.45 ACP<br/>";

        count = 12;
        initSpeed = 620;
        tracersEvery = 0;
        lastRoundsTracer = 2;
        mass = 6;
    };
};
