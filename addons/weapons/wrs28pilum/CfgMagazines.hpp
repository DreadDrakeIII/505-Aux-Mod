class CfgMagazines {
    class WRS_Sniper_Magazine;
    class WRS_Sniper_Magazine_AP;

    class CLASS(UC_CELL): WRS_Sniper_Magazine {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(UC_CELL);
        author = AUTHOR;

        displayname = "[505th] 5Rnd UC Cell (HE)";
        displaynameshort = "UC Cell (HE)";
        descriptionshort = "5 Round Unstable Cell developed by Blackreach Armory Industries";

        ammo = QCLASS(HE_CELL);
        initSpeed = 1250;
        count = 6;
        mass = 12;
    };

    class CLASS(CC_CELL): WRS_Sniper_Magazine_AP {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(CC_CELL);
        author = AUTHOR;

        displayname = "[505th] 5Rnd CC Cell (AP)";
        displaynameshort = "CC Cell (AP)";
        descriptionshort = "5 Round Concentrated Cell developed by Blackreach Armory Industries";

        ammo = QCLASS(AP_CELL);
        initSpeed = 1400;
        count = 6;
        mass = 12;
    };
};
