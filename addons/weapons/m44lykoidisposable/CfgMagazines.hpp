class CfgMagazines {
    class OPTRE_M44_Lykoi_HEAT_mag;

    // ================================
    // M44 Lykoi Disposable Rockets
    // ================================

    // ================================
    // HEAT ROCKET (High Explosive Anti-Tank - maximum armor penetration)
    // ================================
    class CLASS(M44_Lykoi_HEAT) : OPTRE_M44_Lykoi_HEAT_mag {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(M44_Lykoi_HEAT);
        author = AUTHOR;

        displayName = "[505th] M44-Lykoi HEAT";
        displayNameShort = "HEAT";
        descriptionShort = "M44-Lykoi HEAT Disposable Rocket";

        // Magazine properties
        count = 1;                     // one round
        mass = MASS_MAGAZINE;
    };
};
