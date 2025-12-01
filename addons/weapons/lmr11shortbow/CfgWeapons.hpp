class Mode_SemiAuto;

class CfgWeapons {
    class Rifle_Base_F;
    class OPTRE_LongRifle_Base: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class OPTRE_M392_DMR: OPTRE_LongRifle_Base {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
            class UnderBarrelSlot;
        };

        class Single: Mode_SemiAuto {};
    };

    // ================================
    // LMR11 Shortbow - Sniper Rifle
    // ================================
    class CLASS(LMR11_SHORTBOW): OPTRE_M392_DMR {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(LMR11_SHORTBOW);

        // User-facing
        displayName = "[505th] LMR11 Shortbow ";
        descriptionShort = "7.62x51mm • 30Rnd magazine • Sniper rifle";
        picture = "\OPTRE_Weapons\DMR\icons\M395_Icon.paa";
        model = "\OPTRE_Weapons\DMR\M395.p3d";

        // Behaviour / performance
        modes[] = { "Single" };

        // Magazine: low capacity 15 rnd 9.5 VX2
        magazines[] = { QCLASS(30Rnd_762x51_Mag) };

        // Tighter base dispersion for long-range accuracy (great range)
        dispersion = 0.00018;          // base dispersion (weapon)
        maxZeroing = 600;              // extended zeroing (great range)
        discreteDistance[] = {100,200,300,400,500,600};
        discreteDistanceInitIndex = 0; // default 100m
        maxRange=600;
        maxRangeToHit=550;

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 50; // Lighter short rifle

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "OPTRE_BR45_Scope",
                    "OPTRE_BR55HB_Scope",
                    "optic_DMS"
                };
            };

            class PointerSlot: PointerSlot {
                class CompatibleItems {
                    ATTACHMENTS_POINTER_BASE
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {};
            };

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {
                    "bipod_01_F_blk"
                };
            };
        };

        //
        // Semi (single shot) - accurate, used for long-range engagements
        //
        class Single: Single {
            displayName = "Single";
            reloadTime = 0.12;          // semi delay (comfortable semi follow-up)
            dispersion = 0.00012;       // very tight for single shots at range
            soundContinuous = 0;
            recoil = "recoil_single_sdar";
            recoilProne = "recoil_single_prone_sdar";
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 400;
            midRangeProbab = 0.9;
            maxRange = 1200;
            maxRangeProbab = 0.3;
            aiRateOfFire = 4.0;
            aiRateOfFireDispersion = 1;
            aiRateOfFireDistance = 800;
        };
    };
};
