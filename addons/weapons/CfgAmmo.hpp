class CfgAmmo {
    // --- Base classes ---
    class B_762x51_Ball;
    class B_45ACP_Ball;
    class B_9x21_Ball;
    class OPTRE_B_127x40_Ball;
    class OPTRE_B_127x40_Tracer;
    class OPTRE_B_5x23_Caseless;
    class B_145x114_HVAP;
    class B_145x114_HEAP;
    class B_145x114_APFSDS;
    class B_127x108_Ball;
    class WBK_B_40mm_GPR_Tracer_Red;
    class WBK_B_40mm_APFSDS_Tracer_Red;
    class Shocking_rounds_isntit;
    class B_338_NM_Ball;
    class B_65x39_Caseless_green;

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

    // --- 338 Ball For LMG Cerberus ---
    class CLASS(338_Ball): B_338_NM_Ball {
        cartridge = "FxCartridge_93x64_Ball";
        airFriction = -0.0009;
        caliber = 4;
        hit = 16;
        typicalSpeed = 950;
        timeToLive = 6;
        tracerScale = 1.2;
        ACE_ballisticCoefficients[] = {0.381};
        ACE_muzzleVelocities[] = {790, 807, 820};
        ACE_barrelLengths[] = {508, 609.6, 660.4};
        ACE_bulletLength = 43.18;
        ACE_bulletMass = 19.44;
        ACE_dragModel = 7;
    };

    // ================================
    // WRS - 14 Bulldog Ammo Config
    // ================================
    class CLASS(65x39_LDUR): B_65x39_Caseless_green {
        airFriction = -0.0009;
        caliber = 1.6;
        hit = 14;
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
        timeToLive = 20;               // flight time before disappearing
        tracerScale = 3;             // white tracer (armor-piercing)
        model = "\A3\Weapons_f\Data\bullettracer\tracer_white";
        ACE_ballisticCoefficients[] = {0.92};
        ACE_muzzleVelocities[] = {1950, 2000, 2050};
        ACE_barrelLengths[] = {700, 760, 820};
        ACE_dragModel = 1;
        ACE_bulletLength = 50;
        ACE_bulletMass = 65;
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
        typicalSpeed = 1200;            // high velocity (m/s)
        airFriction = -0.0001;        // excellent velocity retention
        timeToLive = 20;
        tracerScale = 3;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
        ACE_ballisticCoefficients[] = {0.92};
        ACE_muzzleVelocities[] = {1950, 2000, 2050};
        ACE_barrelLengths[] = {700, 760, 820};
        ACE_dragModel = 1;
        ACE_bulletLength = 50;
        ACE_bulletMass = 65;
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
        typicalSpeed = 1200;            // same velocity as HVAP
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
        ACE_ballisticCoefficients[] = {0.92};
        ACE_muzzleVelocities[] = {1950, 2000, 2050};
        ACE_barrelLengths[] = {700, 760, 820};
        ACE_dragModel = 1;
        ACE_bulletLength = 50;
        ACE_bulletMass = 65;
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
        typicalSpeed = 980;
        airFriction = -0.0001;
        timeToLive = 20;
        tracerScale = 3;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
        ACE_ballisticCoefficients[]={0.84};
        ACE_muzzleVelocities[] = {980, 981};
        ACE_barrelLengths[] = {720, 760};
        ACE_dragModel=1;
        ACE_bulletLength=64.516;
        ACE_bulletMass=48.6;

    };

    // ================================
    // Energy Weapon Ammo Config
    // ================================

    // ================================
    // WRS-28 PILUM AMMUNITION (Unstable Cell (HE))
    // ================================
    class CLASS(HE_CELL): WBK_B_40mm_GPR_Tracer_Red {
        cartridge = "FxCartridge_556";

        // --- Ballistics / Performance ---
        hit=220;
        caliber = 70;
        typicalSpeed = 1250;
        airFriction = -0.00008;
        timeToLive = 25;
        explosive = 1;              // high explosive content
        indirectHit = 100;              // blast damage
        indirectHitRange = 6;          // 6m blast radius
        explosionEffects = "ExploAmmoExplosion";
        craterEffects = "ExploAmmoCrater";

        // --- Tracer ---
        tracerScale = 4;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
    };

    // ================================
    // WRS-28 PILUM AMMUNITION (Concentrated Cell (AP))
    // ================================
    class CLASS(AP_CELL): WBK_B_40mm_APFSDS_Tracer_Red {
        cartridge = "FxCartridge_556";

        // --- Ballistics / Performance ---
        hit=400;
        caliber = 100;
        typicalSpeed = 1400;
        airFriction = -0.00006;
        timeToLive = 25;
        // --- Tracer ---
        tracerScale = 3;
        model = "\A3\Weapons_f\Data\bullettracer\tracer_white";

        // --- ACE Advanced Ballistics ---
        ACE_ballisticCoefficients[] = {0.98};
        ACE_muzzleVelocities[] = {1370, 1400, 1430};
        ACE_barrelLengths[] = {700, 760, 820};
        ACE_dragModel = 1;
        ACE_bulletLength = 60;
        ACE_bulletMass = 80;
    };

    // ================================
    // WRS-10 RHINO AMMUNITION (Coolant Cartridge)
    // ================================
    class CLASS(shocking_round): Shocking_rounds_isntit {
        caliber = 3;
        hit = 25;
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
        hit = 16;
        caliber = 2;
        typicalSpeed = 620;
        airFriction = -0.02;
        timeToLive = 6;
        tracerScale = 1.3;
    };

    class CLASS(9x21_Ball): B_9x21_Ball {
        cartridge = "FxCartridge_9mm";
        hit = 16;
        caliber = 2;
        typicalSpeed = 620;
        airFriction = -0.002;
        timeToLive = 6;
        tracerScale = 1.3;
    };

    // ================================
    // SMG Ammo Config
    // ================================

    // CPW, MPK5 — 9x21mm
    class CLASS(SMG_9x21_Ball): B_9x21_Ball {
        cartridge = "FxCartridge_9mm";
        hit = 16;
        caliber = 2;
        typicalSpeed = 620;
        airFriction = -0.002;
        timeToLive = 6;
        tracerScale = 1.3;
    };

    // M7 Caseless — 5x23mm Caseless
    class CLASS(5x23_Caseless): OPTRE_B_5x23_Caseless {
        hit = 16;
        caliber = 2;
        typicalSpeed = 620;
        airFriction = -0.002;
        timeToLive = 6;
        tracerScale = 1.3;
    };

    // M6D Carbine — 12.7x40mm Tracer
    class CLASS(127x40_Tracer): OPTRE_B_127x40_Tracer {
        hit = 16;
        caliber = 2;
        typicalSpeed = 620;
        airFriction = -0.002;
        timeToLive = 6;
        tracerScale = 1.3;
    };
};
