class CA_Magazine;

class CfgMagazines {
    class CLASS(Mag_Base): CA_Magazine {
        SCOPE_PRIVATE;
        author = AUTHOR;

        displayName = "";
        displayNameShort = "";
        descriptionShort = "";

        model = "\A3\weapons_F\ammo\mag_univ.p3d";
        modelSpecial = "";
        modelSpecialIsProxy = FALSE;
    };
};