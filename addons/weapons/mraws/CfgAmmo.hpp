class CfgAmmo {
    class R_MRAAWS_HEAT_F;
    class R_MRAAWS_HE_F;

    // --- HEAT 75 (tandem HEAT, anti-armour) ---
    class CLASS(R_M20_HEAT75): R_MRAAWS_HEAT_F {};

    // --- HE 44 (anti-personnel / soft targets) ---
    class CLASS(R_M20_HE44): R_MRAAWS_HE_F {};

    // --- WP (white phosphorus) ---
    class CLASS(R_M20_WP): R_MRAAWS_HE_F {
        warheadName = "HE";
        hit = 40;
        indirectHit = 15;
        indirectHitRange = 4;
        explosive = 0.6;

        submunitionAmmo = "SmokeShellArty";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitSpeed = 0;
        submunitionParentSpeedCoef = 0;
        submunitionInitialOffset[] = {0, 0, -0.2};
        triggerOnImpact = 1;
        deleteParentWhenTriggered = 0;
    };
};
