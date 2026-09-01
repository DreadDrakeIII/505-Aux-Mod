class CfgVehicles {
    class Wheeled_APC_F;
    class APC_Wheeled_01_base_F: Wheeled_APC_F {
        class Turrets;
    };
    class B_APC_Wheeled_01_base_F: APC_Wheeled_01_base_F {};
    class B_APC_Wheeled_01_cannon_F: B_APC_Wheeled_01_base_F {
        class Turrets: Turrets {
            class MainTurret;
        };
    };

    class CLASS(Dingo): B_APC_Wheeled_01_cannon_F {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "LISV16 Dingo";
        side = BLUFOR;
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(APCs);
        crew = QCLASS(Marine_Tank_Crew);
        typicalCargo[] = {QCLASS(Marine_Tank_Crew)};

        // --- armor / HP ---
        armor = 1200;
        armorStructural = 2.0;

        // --- engine / handling ---
        maxSpeed = 150;
        enginePower = 2000;
        engineMOI = 1.0;
        maxOmega = 3000;
        idleRpm = 600;
        redRpm = 6900;
        peakTorque = 3000;
        torqueCurve[] = {
            {0, 0.3},
            {0.178, 0.5},
            {0.25, 0.85},
            {0.4, 0.95},
            {0.5, 1},
            {0.625, 0.95},
            {0.75, 0.7},
            {1, 0.5}
        };
        dampingRateFullThrottle = 0.08;
        dampingRateZeroThrottleClutchDisengaged = 0.35;
        dampingRateZeroThrottleClutchEngaged = 2;

        // --- ACE turret / damage compatibility ---
        ace_vehicle_damage_turretDetonationProb = 0.2;
        ace_vehicle_damage_turretFireProb = 0.2;
        ace_vehicle_damage_hullDetonationProb = 0.1;
        ace_vehicle_damage_hullFireProb = 0.3;
        ace_vehicle_damage_engineDetonationProb = 0.2;
        ace_vehicle_damage_engineFireProb = 0.5;

        ace_fcs_enabled = 1;
        ace_fcs_minDistance = 100;
        ace_fcs_maxDistance = 3000;

        ace_hunterkiller = 1;

        class Turrets: Turrets {
            class MainTurret: MainTurret {
                weapons[] = {
                    "autocannon_40mm_CTWS",
                    "LMG_coax"
                };
                magazines[] = {
                    "60Rnd_40mm_GPR_Tracer_Red_shells",
                    "60Rnd_40mm_GPR_Tracer_Red_shells",
                    "60Rnd_40mm_GPR_Tracer_Red_shells",
                    "60Rnd_40mm_GPR_Tracer_Red_shells",
                    "40Rnd_40mm_APFSDS_Tracer_Red_shells",
                    "40Rnd_40mm_APFSDS_Tracer_Red_shells",
                    "40Rnd_40mm_APFSDS_Tracer_Red_shells",
                    "40Rnd_40mm_APFSDS_Tracer_Red_shells",
                    "200Rnd_762x51_Belt",
                    "200Rnd_762x51_Belt",
                    "200Rnd_762x51_Belt",
                    "200Rnd_762x51_Belt",
                    "200Rnd_762x51_Belt"
                };
            };
        };

        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\dingo\data\textures\505th_Dingo_EXT1_co.paa),
            QPATHTOF(land\dingo\data\textures\505th_Dingo_EXT2_co.paa),
            QPATHTOF(land\dingo\data\textures\505th_Dingo_Wheel_co.paa)
        };
    };
};
