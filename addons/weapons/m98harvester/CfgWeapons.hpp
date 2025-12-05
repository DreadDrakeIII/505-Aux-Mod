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

        linkedItems[] = { QCLASS(M98H_Scope) };

        // Weapon handling
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 100;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    QCLASS(M98H_Scope)
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
        };
    };
};
