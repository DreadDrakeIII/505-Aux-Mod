class CfgMagazines {
    class WRS_Puma_Magazine;

    class CLASS(16Rnd_45ACP_Mag): WRS_Puma_Magazine {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(16Rnd_45ACP_Mag);
        author = AUTHOR;

        displayname = "[505th] 16Rnd .45ACP Magazine";
        displaynameshort = ".45ACP";
        descriptionshort = "16 Round Magazine<br/>.45ACP<br/>";

        ammo = QCLASS(45ACP_Ball);
        count = 16;
        mass = 6;
    };
};
