class CfgMagazines {
    class WRS_Shockgun_Magazine;

    class CLASS(coolant_cartridge): WRS_Shockgun_Magazine {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(coolant_cartridge);
        author = AUTHOR;

        displayName = "[505th] 8 Rnd Energy Slugs";
        displayNameShort = "8 Rnd Energy Slugs";
        descriptionShort = "Coolant cartridge developed by Blackreach Armory Industries";

        ammo = QCLASS(shocking_round);
        count = 8;
        mass = 16;
    };
};
