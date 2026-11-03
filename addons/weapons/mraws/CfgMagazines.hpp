class CfgMagazines {
    class MRAWS_HEAT_F;
    class MRAWS_HE_F;

    class CLASS(M20_HEAT75): MRAWS_HEAT_F {
        author = AUTHOR;
        displayName = "[505th] M20 HEAT 75 Round";
        displayNameShort = "HEAT 75";
        descriptionShort = "Tandem HEAT anti-armour round";
        ammo = QCLASS(R_M20_HEAT75);
    };
    class CLASS(M20_HE44): MRAWS_HE_F {
        author = AUTHOR;
        displayName = "[505th] M20 HE 44 Round";
        displayNameShort = "HE 44";
        descriptionShort = "High-explosive round";
        ammo = QCLASS(R_M20_HE44);
    };
    class CLASS(M20_WP): MRAWS_HE_F {
        author = AUTHOR;
        displayName = "[505th] M20 WP Round";
        displayNameShort = "WP";
        descriptionShort = "White phosphorus round - smoke screen";
        ammo = QCLASS(R_M20_WP);
    };
};
