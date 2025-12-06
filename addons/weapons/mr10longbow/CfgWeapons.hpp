class Mode_SemiAuto;

class CfgWeapons {
    class Rifle_Long_Base_F;
    class DMR_02_base_F: Rifle_Long_Base_F {
        class WeaponSlotsInfo;
    };
    class srifle_DMR_02_F: DMR_02_base_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
            class UnderBarrelSlot;
        };

        class Single: Mode_SemiAuto {
            class StandardSound;
        };
    };

    // ================================
    // MR10 Longbow - Hi-Power Long Range Sniper Rifle
    // ================================
    class CLASS(MR10_LONGBOW): srifle_DMR_02_F {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(MR10_LONGBOW);

        // User-facing
        displayName = "[505th] MR10 Longbow ";
        descriptionShort = "9.5×VX2 • 15Rnd magazine • High penetration • Long range";
        picture = "\A3\Weapons_F_Mark\LongRangeRifles\DMR_02\Data\UI\gear_DMR_02_X_CA";
        model = "\A3\Weapons_F_Mark\LongRangeRifles\DMR_02\DMR_02_F.p3d";
        reloadMagazineSound[] = {"\OPTRE_Wbk_WeaponImprovements\reload\battleRifle_reload.ogg",2,1,25};

        // Behaviour / performance
        modes[] = { "Single" };

        // Magazine: low capacity 15 rnd 9.5 VX2
        magazines[] = { QCLASS(15Rnd_95xVX2_Mag) };
        magazineWell[] = { QCLASS(Magwell_MR10_LONGBOW) };

        // Tighter base dispersion for long-range accuracy (great range)
        dispersion = 0.00018;          // base dispersion (weapon)
        maxZeroing = 1800;              // extended zeroing (great range)
        discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800};
        discreteDistanceInitIndex = 0; // default 100m
        maxRange=1800;
        maxRangeToHit=1750;

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 130; // slightly heavier - hi-power long-range rifle

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
            reloadTime = 0.12;

            class StandardSound: StandardSound {
                soundSetShot[] = {"DMR02_Shot_SoundSet","DMR02_tail_SoundSet","DMR02_InteriorTail_SoundSet"};
            };
        };
    };
};
