class CfgMagazines {
    class WRS_Sniper_Magazine;
    class WRS_Sniper_Magazine_AP;

    class CLASS(UC_CELL): WRS_Sniper_Magazine {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(UC_CELL);
        author = AUTHOR;

        displayname = "[505th] UC Cell (HE)";
        displaynameshort = "UC Cell (HE)";
        descriptionshort = "SingleRound Unstable Cell developed by Blackreach Armory Industries";

        ammo = QCLASS(HE_CELL);
        initSpeed = 1250;
        count = 1;
        mass = 2;
    };

    class CLASS(CC_CELL): WRS_Sniper_Magazine_AP {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(CC_CELL);
        author = AUTHOR;

        displayname = "[505th] CC Cell (AP)";
        displaynameshort = "CC Cell (AP)";
        descriptionshort = "Single Round Concentrated Cell developed by Blackreach Armory Industries";

        ammo = QCLASS(AP_CELL);
        initSpeed = 1400;
        count = 1;
        mass = 2;
    };
};
