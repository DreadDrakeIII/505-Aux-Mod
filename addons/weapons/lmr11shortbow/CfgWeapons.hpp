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

        class Single: Single
		{
			displayName="Single";
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_cyrus_shot_soundset",
					"jsrs_2025_tailsystem_762mm_dmr_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_cyrus_shot_silenced_soundset",
					"jsrs_2025_tailsystem_762mm_dmr_silenced_soundset"
				};
			};
		};
    };
};
