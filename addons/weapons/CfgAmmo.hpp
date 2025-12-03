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

        // ================================
    // M98 HARVESTER AMMUNITION (14.7×114mm)
    // ================================

    // ================================
    // 1. APFSDS - Armor Piercing Fin-Stabilized Discarding Sabot
    // Best for armor penetration (vehicles, fortifications)
    // ================================
    class CLASS(147x114_APFSDS): B_145x114_APFSDS {
        cartridge = "FxCartridge_127";

        // --- Ballistics / Performance ---
        hit = 120;                      // high kinetic impact (armor-piercing)
        caliber = 20;                 // excellent armor penetration
        typicalSpeed = 1400;           // very fast velocity (m/s)
        airFriction = -0.0001;       // excellent velocity retention
        deflecting = 0;               // resistant to ricochet
        timeToLive = 15;               // flight time before disappearing

        // --- Effects / AI ---
        audibleFire = 120;              // loud report (large caliber)
        visibleFire = 8;              // visible muzzle flash
        dangerRadiusHit = 20;          // AI notices impact from far
        dangerRadiusBulletClose = 20;  // AI reacts to near misses
        suppressionRadiusHit = 15;     // strong suppression
        suppressionRadiusBulletClose = 20;

        // --- Tracer visuals ---
        tracerScale = 3;             // white tracer (armor-piercing)
        tracerStartTime = 0;
        tracerEndTime = 15;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_white";

        // --- Camera shake on hit ---
        class CamShakeExplode {
            power = "(20^0.5)";
            duration = "((round (20^0.5))*0.2 max 0.2)";
            frequency = 20;
            distance = 13.416408;
        };

        class CamShakeHit {
            power = 20;
            duration = "((round (20^0.25))*0.2 max 0.2)";
            frequency = 20;
            distance = 1;
        };
    };

    // ================================
    // 2. HVAP - High Velocity Armor Piercing
    // Balanced: good armor penetration + good velocity
    // ================================
    class CLASS(147x114_HVAP): B_145x114_HVAP {
        cartridge = "FxCartridge_127";

        // --- Ballistics / Performance ---
        hit = 140;                     // moderate direct impact (more impact than APFSDS)
        caliber = 18.0;                 // strong armor penetration (less than APFSDS)
        typicalSpeed = 1300;            // high velocity (m/s)
        airFriction = -0.0001;        // excellent velocity retention
        deflecting = 0;               // resistant to ricochet
        timeToLive = 15;

        // --- Effects / AI ---
        audibleFire = 120;              // loud report (large caliber)
        visibleFire = 8;              // visible muzzle flash
        dangerRadiusHit = 30;
        dangerRadiusBulletClose = 20;
        suppressionRadiusHit = 15;
        suppressionRadiusBulletClose = 20;

        // --- Tracer visuals ---
        tracerScale = 3;
        tracerStartTime = 0;
        tracerEndTime = 15;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_red";

        // --- Camera shake on hit ---
        class CamShakeExplode {
            power = "(20^0.5)";
            duration = "((round (20^0.5))*0.2 max 0.2)";
            frequency = 20;
            distance = 13.416408;
        };

        class CamShakeHit {
            power = 20;
            duration = "((round (20^0.25))*0.2 max 0.2)";
            frequency = 20;
            distance = 1;
        };
    };

    // ================================
    // 3. HEDP - High Explosive Dual Purpose
    // Anti-personnel + anti-structure
    // ================================
    class CLASS(147x114_HEDP): B_145x114_HEAP {
        cartridge = "FxCartridge_127";

        // --- Ballistics / Performance ---
        hit = 180;                      // very high damage (more impact than HVAP)
        caliber = 40;                 // high armor penetration (explosive focus)
        typicalSpeed = 1300;            // same velocity as HVAP
        airFriction = -0.0001;        // excellent velocity retention
        deflecting = 0;               // resistant to ricochet
        timeToLive = 15;

        // --- Explosive properties ---
        explosive = 1;              // high explosive content
        indirectHit = 45;              // blast damage
        indirectHitRange = 3;          // blast radius (3 meters)

        // --- Effects / AI ---
        audibleFire = 120;              // loud report (large caliber)
        visibleFire = 8;              // visible muzzle flash
        dangerRadiusHit = 35;          // larger danger radius (explosion)
        dangerRadiusBulletClose = 20;
        suppressionRadiusHit = 20;     // strong suppression from blast
        suppressionRadiusBulletClose = 25;

        // --- Tracer visuals ---
        tracerScale = 4;             // larger tracer (red - HE round)
        tracerStartTime = 0;
        tracerEndTime = 15;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_red";

        // --- Explosive effects ---
        craterEffects = "ExploAmmoCrater";
        explosionEffects = "ExploAmmoExplosion";
        explosionSoundEffect = "DefaultExplosion";

        // --- Camera shake on hit ---
        class CamShakeExplode {
            power = "(20^0.5)";
            duration = "((round (20^0.5))*0.2 max 0.2)";
            frequency = 20;
            distance = 13.416408;
        };

        class CamShakeHit {
            power = 20;
            duration = "((round (20^0.25))*0.2 max 0.2)";
            frequency = 20;
            distance = 1;
        };
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
