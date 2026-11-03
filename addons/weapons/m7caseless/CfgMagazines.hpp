class CfgMagazines {
    class TCP_60Rnd_5x23_Mag;

    class CLASS(60Rnd_5x23_Mag): TCP_60Rnd_5x23_Mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(60Rnd_5x23_Mag);
        author = AUTHOR;

        displayname = "[505th] 60Rnd M7 Caseless Magazine";
        displaynameshort = "5x23mm";
        descriptionshort = "60 Round Caseless Magazine<br/>5x23mm<br/>";

        ammo = QCLASS(5x23_Caseless);
        count = 60;
        initSpeed = 620;
        tracersEvery = 1;
        lastRoundsTracer = 0;
        mass = 10;
    };
};
