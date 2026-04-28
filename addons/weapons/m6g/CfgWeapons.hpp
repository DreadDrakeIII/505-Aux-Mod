class Mode_SemiAuto;

class CfgWeapons {

    class Pistol_Base_F;
    class hgun_Pistol_heavy_01_F: Pistol_Base_F {
        class WeaponSlotsInfo;
    };

    class TCP_hgun_Pistol_M6G: hgun_Pistol_heavy_01_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
            class UnderBarrelSlot;
        };

        class Single: Mode_SemiAuto {
                    };
    };

    class CLASS(M6G): TCP_hgun_Pistol_M6G {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M6G);

        displayName = "[505th] M6G Magnum";
        descriptionShort = "M6G `Magnum` Pistol developed by Blackreach Armory Industries";

        modes[] = {"Single"};

        magazines[] = {QCLASS(8Rnd_127x40_Mag)};
        magazineWell[] = { QCLASS(Magwell_M6G) };

        reloadMagazineSound[] = {"\BLU\OLI\addons\weapons\m6g\data\sound\m6g_reload.ogg",1,1};


        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 20;
            holsterOffset = "holster";
            holsterScale = 0.95;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "TCP_optic_KFA_M6G"
                };
            };

            class PointerSlot: PointerSlot {
                compatibleItems[] = {
                    "TCP_acc_pointer_lam_M6C2"
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "TCP_muzzle_snds_127_02"
                };
            };

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {
                    "TCP_bipod_handGuard_M6G"
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
					"OPTRE_M6_Pistol_Shot_SoundSet",
					"jsrs_2025_tailsystem_Magnum_rifle_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"4Five_silencerShot_SoundSet",
					"jsrs_2025_tailsystem_Magnum_rifle_silenced_soundset"
				};
			};
		};
	};
};
