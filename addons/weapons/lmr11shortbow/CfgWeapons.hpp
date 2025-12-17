class Mode_SemiAuto;

class CfgWeapons {
    class Rifle_Base_F;
    class OPTRE_LongRifle_Base: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class OPTRE_M393_DMR: OPTRE_LongRifle_Base {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
            class UnderBarrelSlot;
        };

        class Single: Mode_SemiAuto {
            class StandardSound;
            class SilencedSound;
        };
    };

    // ================================
    // LMR11 Shortbow - Sniper Rifle
    // ================================
    class CLASS(LMR11_SHORTBOW): OPTRE_M393_DMR {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(LMR11_SHORTBOW);

        // User-facing
        displayName = "[505th] LMR11 Shortbow ";
        descriptionShort = "7.62x51mm • 30Rnd magazine • Sniper rifle";
        picture = "\OPTRE_Weapons\DMR\icons\M395_Icon.paa";
        model = "\OPTRE_Weapons\DMR\M395.p3d";

        hiddenSelections[] = {"camo","camo1","camo2"};
        hiddenSelectionsTextures[] = {"optre_weapons\dmr\data\mainbody1_co.paa","optre_weapons\dmr\data\mainbody2_co.paa","optre_weapons\dmr\data\muzzle_co.paa"};

        // Behaviour / performance
        modes[] = { "Single" };

        // Magazine: low capacity 15 rnd 9.5 VX2
        magazines[] = { QCLASS(30Rnd_762x51_Mag) };
        magazineWell[] = { QCLASS(Magwell_LMR11_SHORTBOW) };

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
            class StandardSound: StandardSound {
                closure1[] = {};
                closure2[] = {};
                begin1[] = {"\OPTRE_Weapons\DMR\Data\sounds\DMR_1.ogg",2.5,1,1500};
                soundSetShot[] = {"jsrs_rifle_shake_soundset","jsrs_mar10_shot_soundset","jsrs_mk18_shell_soundset","jsrs_7x62mm_reflector_soundset"};
                soundClosure[] = {"closure1",0.5,"closure2",0.5};
                weaponSoundEffect = "DefaultRifle";
            };
            class SilencedSound: SilencedSound {
                begin1[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_short_01",0.794328,1,400};
                begin2[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_short_02",0.794328,1,400};
                begin3[] = {"A3\Sounds_F\arsenal\weapons\Rifles\MX\Silencer_Mx_short_03",0.794328,1,400};
                closure1[] = {};
                closure2[] = {};
                soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin1",0.34};
                soundClosure[] = {"closure1",0.5,"closure2",0.5};
                SoundSetShot[] = {"jsrs_rifle_shake_soundset","jsrs_mar10_shot_silenced_soundset","jsrs_mk18_shell_soundset","jsrs_7x62mm_sd_reflector_soundset"};
                weaponSoundEffect = "DefaultRifle";
            };
        };
    };
};
