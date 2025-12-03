class Mode_SemiAuto;

class CfgWeapons {
    class Rifle_Base_F;
    class OPTRE_LongRifle_Base: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class OPTRE_SRS99D: OPTRE_LongRifle_Base {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
            class UnderBarrelSlot;
        };

        class Single: Mode_SemiAuto {
        };
    };

    // ================================
    // M98 HARVESTER - Anti-Material Rifle
    // Heavy sniper rifle for anti-material support
    // ================================
    class CLASS(M98_HARVESTER): OPTRE_SRS99D {
        SCOPE_PUBLIC;
        author = AUTHOR;

        model = "\OPTRE_Weapons\Sniper\SRS99D.p3d";
        baseWeapon = QCLASS(M98_HARVESTER);

        // User-facing information
        displayName = "[505th] M98 Harvester";
        descriptionShort = "14.7×114mm • 4Rnd magazine • Anti-Material • 2000m Range";
        picture = "\OPTRE_weapons\sniper\icons\sniper.paa";


        // Behaviour / performance
        modes[] = { "Single" };

        // Magazine: Varies of magazines
        magazines[] = { QCLASS(5Rnd_147x114_APFSDS_Mag),
                        QCLASS(5Rnd_147x114_HVAP_Mag),
                        QCLASS(5Rnd_147x114_HEDP_Mag)
                      };
        magazineWell[] = {QCLASS(Magwell_M98_Harvester)};

        // Zeroing and optics
        maxZeroing = 2000;
        discreteDistance[] = {100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1020,1040,1060,1080,1100,1120,1140,1160,1180,1200,1220,1240,1260,1280,1300,1320,1340,1360,1380,1400,1420,1440,1460,1480,1500,1520,1540,1560,1580,1600,1620,1640,1660,1680,1700,1720,1740,1760,1780,1800,1820,1840,1860,1880,1900,1920,1940,1960,1980,2000};
        discreteDistanceInitIndex = 0;

        // Particle effects
        class GunParticles {
            class FirstEffect {
                effectName = "SniperCloud";
                positionName = "Usti hlavne";
                directionName = "Konec hlavne";
            };
            class EffectShotCloud {
                positionName = "Nabojnicestart";
                directionName = "Nabojniceend";
                effectName = "CaselessAmmoCloud";
            };
        };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 100;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "OPTRE_SRS99_Scope"
                };
            };

            class PointerSlot: PointerSlot {
                compatibleItems[] = {};
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {};
            };

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {};
            };
        };

        //
        // Semi (single shot) - accurate, used for long-range engagements
        //
        class Single: Single {
            displayName = "Single";

            // Bolt-action characteristics
            reloadTime = 1.5;          // bolt-action reload time (faster than true sniper, slower than DMR)
            dispersion = 0.00029;      // tight accuracy
            soundContinuous = 0;       // semi-auto mode
            recoil = "recoil_single_gm6";
            recoilProne = "recoil_single_gm6";

            // AI targeting
            minRange = 10;
            minRangeProbab = 0.3;
            midRange = 800;
            midRangeProbab = 0.8;
            maxRange = 2000;
            maxRangeProbab = 0.4;

            // AI fire rate (sniper - slow, deliberate)
            aiRateOfFire = 4.0;        // fires every ~4 seconds
            aiRateOfFireDispersion = 0.8;
            aiRateOfFireDistance = 1000;
        };
    };
};
