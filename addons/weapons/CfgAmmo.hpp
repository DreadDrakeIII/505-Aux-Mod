class CfgAmmo {
    // --- Base classes ---
    class B_762x51_Ball;
    class B_45ACP_Ball;
    class B_9x21_Ball;
    class OPTRE_B_127x40_Ball;
    class B_145x114_HVAP;
    class B_145x114_HEAP;
    class B_145x114_APFSDS;
    class B_127x108_Ball;

    // OPTRE Custom Ammunition
    // --- 7.62x51mm Ball ---
    class CLASS(762x51_Ball): B_762x51_Ball {
        cartridge = "FxCartridge_762";
        airFriction = -0.00105;
        caliber = 1.6;
        hit = 11.6;
        tracerScale = 1.2;
        typicalSpeed = 870;
    };
    // --- 9.5x40mm Ball ---
    class CLASS(95_40_Ball): B_762x51_Ball {
        cartridge = "FxCartridge_93x64_Ball";
        airFriction = -0.0009;
        caliber = 4;
        hit = 13;
        typicalSpeed = 950;
        timeToLive = 6;
        tracerScale = 1.2;
    };

    // --- 9.5x40mm Ball For LMG M73 ---
    class CLASS(LMG_95_40_Ball): B_762x51_Ball {
        cartridge = "FxCartridge_93x64_Ball";
        airFriction = -0.0009;
        caliber = 4;
        hit = 13;
        typicalSpeed = 950;
        timeToLive = 6;
        tracerScale = 1.2;
    };
    // --- 7.62xV7 Ball (for M295 BMR) ---
    class CLASS(762xV7_Ball): B_762x51_Ball {
        cartridge = "FxCartridge_762";
        caliber = 1.6;
        hit = 11.6;
        typicalSpeed = 1000;
        airFriction = -0.00060;
        timeToLive = 10;
        tracerScale = 1.0;
    };
    // --- 9.5xVX2 Ball (for VK78 Commando) ---
    class CLASS(95xVX2_Ball): B_762x51_Ball {
        cartridge = "FxCartridge_65";

        // --- Ballistics / Performance ---
        hit = 20;                    // more kinetic impact (was 18)
        caliber = 2.5;               // stronger armor penetration
        typicalSpeed = 850;          // muzzle velocity (m/s)
        airFriction = -0.00075;      // retains velocity better
        timeToLive = 10;
        // --- Tracer visuals ---
        tracerScale = 1.2;
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
        typicalSpeed = 2000;           // very fast velocity (m/s)
        airFriction = -0.0001;       // excellent velocity retention
        timeToLive = 20;               // flight time before disappearing
        tracerScale = 3;             // white tracer (armor-piercing)
        model = "\A3\Weapons_f\Data\bullettracer\tracer_white";
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
        typicalSpeed = 1800;            // high velocity (m/s)
        airFriction = -0.0001;        // excellent velocity retention
        timeToLive = 20;
        tracerScale = 3;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
    };

    // ================================
    // 3. HEDP - High Explosive Dual Purpose
    // Anti-personnel + anti-structure
    // ================================
    class CLASS(147x114_HEDP): B_145x114_HEAP {
        cartridge = "FxCartridge_127";

        // --- Ballistics / Performance ---
        hit = 250;                      // very high damage (more impact than HVAP)
        caliber = 60;                 // high armor penetration (explosive focus)
        typicalSpeed = 1800;            // same velocity as HVAP
        airFriction = -0.0001;
        timeToLive = 20;
        // --- Explosive properties ---
        explosive = 1;              // high explosive content
        indirectHit = 60;              // blast damage
        indirectHitRange = 4;          // blast radius (3 meters)
        explosionEffects = "ExploAmmoExplosion";
        craterEffects = "ExploAmmoCrater";
        tracerScale = 4;             // larger tracer (red - HE round)

        model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
    };

    // ================================
    // VTR-93 Vindicta AMMUNITION (12.7x108mm)
    // Heavy Depleted Uranium Round
    // ================================
    class CLASS(127x108_HDUR): B_127x108_Ball {
        cartridge = "FxCartridge_127";

        // --- Ballistics / Performance ---
        hit = 80;
        caliber = 10.0;
        typicalSpeed = 980;            // high velocity (m/s)
        airFriction = -0.0001;        // excellent velocity retention
        timeToLive = 20;
        tracerScale = 3;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
    };

    // ================================
    // Pistol Ammo Config
    // ================================

    class CLASS(127x40_Ball): OPTRE_B_127x40_Ball {
        cartridge = "FxCartridge_small";
        hit = 16;
        caliber = 2;
        typicalSpeed = 620;
        airFriction = -0.002;
        timeToLive = 6;
        tracerScale = 1.3;
    };

    class CLASS(45ACP_Ball): B_45ACP_Ball {
        cartridge = "FxCartridge_9mm";
        hit = 5;
        caliber = 1.4;
        typicalSpeed = 280;
        airFriction = -0.00082143;
        timeToLive = 6;
        tracerScale = 0.6;
    };

    class CLASS(9x21_Ball): B_9x21_Ball {
        cartridge = "FxCartridge_9mm";
        hit = 5;
        caliber = 1.2;
        typicalSpeed = 380;
        airFriction = -0.00211064;
        timeToLive = 6;
        tracerScale = 0.5;
    };
};
