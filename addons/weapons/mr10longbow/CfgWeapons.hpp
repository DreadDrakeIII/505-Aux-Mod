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

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 130; // slightly heavier - hi-power long-range rifle

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "OPTRE_BR45_Scope",
                    "OPTRE_BR55HB_Scope",
                    "optic_DMS",
                    "TCP_optic_M11VERO_Blue",
                    "TCP_optic_M11VERO",
                    "TCP_optic_M81ERO_Blue",
                    "TCP_optic_EVOSJ",
                    "TCP_optic_EVOSJ1",
                    "TCP_optic_M27RCO",
                    "TCP_optic_M43RCO",
                    "TCP_optic_M43RCO_CRS",
                    "TCP_optic_M43RCO_CRS_CUP",
                    "TCP_optic_M43RCO_CUP",
                    "TCP_optic_EVOSD",
                    "TCP_optic_M5BSLSV_Blue",
                    "TCP_optic_M5BSLSV",
                    "TCP_optic_M81ERO_Blue",
                    "TCP_optic_M81ERO"
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

        class Single: Single {
                displayName="Single";
                reloadTime=0.12;
                class BaseSoundModeType;
                class StandardSound: BaseSoundModeType {
                soundSetShot[]= {
                "DMR02_Shot_SoundSet",
                "jsrs_2025_tailsystem_magnum_rifle_soundset"
                };
            };
                class SilencedSound: BaseSoundModeType {
                soundSetShot[]= {
                "DMR02_silencerShot_SoundSet",
                "jsrs_2025_tailsystem_magnum_rifle_silenced_soundset"
                };
            };
        };
    };
};
