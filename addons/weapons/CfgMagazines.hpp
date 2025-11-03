class OPTRE_32Rnd_762x51_Mag;
class OPTRE_36Rnd_95x40_Mag;
class OPTRE_32Rnd_762x51_Mag_Tracer;
class OPTRE_32Rnd_762x51_Mag_Tracer_Yellow;

class CfgMagazines {
    // class OPTRE_32Rnd_762x51_Mag: OPTRE_32Rnd_762x51_Mag {
    //     SCOPE_HIDDEN;
    //     descriptionShort = "HIDDEN";
    // };

    // class OPTRE_36Rnd_95x40_Mag: OPTRE_36Rnd_95x40_Mag {
    //     SCOPE_HIDDEN;
    //     descriptionShort = "HIDDEN";
    // };

    // class OPTRE_32Rnd_762x51_Mag_Tracer: OPTRE_32Rnd_762x51_Mag_Tracer {
    //     SCOPE_HIDDEN;
    //     descriptionShort = "HIDDEN";
    // };

    // class OPTRE_32Rnd_762x51_Mag_Tracer_Yellow: OPTRE_32Rnd_762x51_Mag_Tracer_Yellow {
    //     SCOPE_HIDDEN;
    //     descriptionShort = "HIDDEN";
    // };

    class CA_Magazine;

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
