class CfgAmmo {
    // --- Base classes ---
    class B_762x51_Ball;
    class B_9x21_Ball;
    class OPTRE_B_127x40_Ball;


    // OPTRE Custom Ammunition
    // --- 7.62x51mm Ball ---
    class CLASS(762x51_Ball): B_762x51_Ball {
        cartridge = "FxCartridge_762";

        airFriction = -0.00105;
        audibleFire = 45;
        caliber = 1.6;
        deflecting = 20;
        dangerRadiusHit = 12;
        dangerRadiusBulletClose = 8;
        suppressionRadiusHit = 6;
        suppressionRadiusBulletClose = 8;
        hit = 11.6;
        tracerScale = 1.2;
        typicalSpeed = 870;
        visibleFire = 5;
    };
    // --- 9.5x40mm Ball ---
    class CLASS(95_40_Ball): B_762x51_Ball {
        cartridge = "FxCartridge_93x64_Ball";

        airFriction = -0.0009;
        audibleFire = 9;
        caliber = 4;
        deflecting = 15;
        dangerRadiusBulletClose = 10;
        dangerRadiusHit = 14;
        hit = 13;
        suppressionRadiusBulletClose = 8;
        suppressionRadiusHit = 10;
        typicalSpeed = 950;
        timeToLive        = 6;
        tracerScale       = 1.2;
        tracerStartTime   = 0.073;
        tracerEndTime     = 2.15957;
        visibleFire = 3;

    };

    // --- 9.5x40mm Ball For LMG M73 ---
    class CLASS(LMG_95_40_Ball): B_762x51_Ball {
        cartridge = "FxCartridge_93x64_Ball";

        airFriction = -0.0009;
        audibleFire = 9;
        caliber = 4;
        deflecting = 15;
        dangerRadiusBulletClose = 10;
        dangerRadiusHit = 14;
        hit = 13;
        suppressionRadiusBulletClose = 8;
        suppressionRadiusHit = 10;
        typicalSpeed = 950;
        timeToLive        = 6;
        tracerScale       = 1.2;
        tracerStartTime   = 0.073;
        tracerEndTime     = 2.15957;
        visibleFire = 3;

    };
    // --- 7.62xV7 Ball (for M295 BMR) ---
    class CLASS(762xV7_Ball): B_762x51_Ball {
        cartridge = "FxCartridge_762";

        audibleFire = 45;
        caliber = 1.6;
        deflecting = 20;
        dangerRadiusHit = 12;
        dangerRadiusBulletClose = 8;
        suppressionRadiusHit = 6;
        suppressionRadiusBulletClose = 8;
        hit = 11.6;
        typicalSpeed      = 1000;
        airFriction       = -0.00060;
        timeToLive        = 10;
        tracerScale       = 1.0;
        tracerStartTime   = 0.05;
        tracerEndTime     = 1.6;
        visibleFire = 5;
    };
    // --- 9.5xVX2 Ball (for VK78 Commando) ---
    class CLASS(95xVX2_Ball): B_762x51_Ball {
        cartridge = "FxCartridge_65";

        // --- Ballistics / Performance ---
        hit = 20;                    // more kinetic impact (was 18)
        caliber = 2.5;               // stronger armor penetration
        typicalSpeed = 850;          // muzzle velocity (m/s)
        airFriction = -0.00075;      // retains velocity better
        deflecting = 10;             // less prone to ricochet
        timeToLive = 10;

        // --- Effects / AI ---
        audibleFire = 45;
        visibleFire = 6;
        dangerRadiusHit = 20;
        dangerRadiusBulletClose = 10;
        suppressionRadiusHit = 8;
        suppressionRadiusBulletClose = 10;

        // --- Tracer visuals ---
        tracerScale = 1.2;
        tracerStartTime = 0.075;
        tracerEndTime = 1;
    };

    class CLASS(127x40_Ball): OPTRE_B_127x40_Ball {
        cartridge = "FxCartridge_small";

        // --- Ballistics / Performance ---
        hit = 16;
        caliber = 2;
        typicalSpeed = 620;
        airFriction = -0.002;
        deflecting = 25;
        timeToLive = 6;

        // --- Effects / AI ---
        audibleFire = 50;
        visibleFire = 3;
        dangerRadiusHit = 8;
        dangerRadiusBulletClose = 4;
        suppressionRadiusHit = 4;
        suppressionRadiusBulletClose = 2;

        // --- Tracer visuals ---
        tracerScale = 1.3;
        tracerStartTime = 0.075;
        tracerEndTime = 1;
    };

    class CLASS(9x21_Ball): B_9x21_Ball {
        cartridge = "FxCartridge_9mm";

        // --- Ballistics / Performance ---
        hit = 5;
        caliber = 1.2;
        typicalSpeed = 380;
        airFriction = -0.00211064;
        deflecting = 25;
        timeToLive = 6;

        // --- Effects / AI ---
        audibleFire = 30;
        visibleFire = 3;
        dangerRadiusHit = 8;
        dangerRadiusBulletClose = 4;
        suppressionRadiusHit = 4;
        suppressionRadiusBulletClose = 2;

        // --- Tracer visuals ---
        tracerScale = 0.5;
        tracerStartTime = 0.05;
        tracerEndTime = 1;
    };

};
