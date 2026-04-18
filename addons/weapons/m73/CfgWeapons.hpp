class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {

    class Rifle_Base_F;
    class Rifle_Long_Base_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };

    class TCP_LMG_M731: Rifle_Long_Base_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
            class UnderBarrelSlot;
        };

        class Single: Mode_SemiAuto {
                    };
        class FullAuto: Mode_FullAuto {
                    };
    };

    class CLASS(M73): TCP_LMG_M731 {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M73);

        displayName = "[505th] M73 Light Machine Gun";
        descriptionShort = "Light Machine Gun developed by Blackreach Armory";
        picture = "\TCP\Weapons\Machineguns\M731\data\ui\icon_lmg_M731_X_ca.paa";

        modes[] = {"Single", "FullAuto"};
        magazines[] = {QCLASS(100Rnd_95x40_Box)};
        magazineWell[] = { QCLASS(Magwell_M73) };

        class LinkedItems {
            class Cows {
                slot = "CowsSlot"; // Required slot name
                item = "TCP_optic_EVOSM"; // Classname of the optic
            };

            class Pointer {
                slot = "PointerSlot"; // Required slot name
                item = "TCP_acc_carryHandle_M731"; // Classname of the pointer
            };

            class Muzzle {
                slot = "MuzzleSlot"; // Required slot name
                item = "TCP_muzzle_brake_762_01"; // Classname of the silencer
            };
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 75;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "TCP_optic_EVOSM",
                    "TCP_optic_M11VERO",
                    "TCP_optic_M81ERO"
                };
            };

            class PointerSlot: PointerSlot {
                compatibleItems[] = {
                    "TCP_acc_carryHandle_M731",
                    "OLI_ANPEQ6G",
                    "OLI_ANPEQ6G_VL"

                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "TCP_muzzle_brake_762_01"
                };
            };

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {
                    "TCP_bipod_01"
                };
            };
        };

        class Single: Single
		{
			displayName="Semi";
			reloadTime=0.075000003;
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_zafir_shot_soundset",
					"jsrs_2025_tailsystem_762mm_lmg_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"SyndikatLMG_silencerShot_SoundSet",
					"jsrs_2025_tailsystem_762mm_lmg_silenced_soundset"
				};
			};
		};

		class FullAuto: FullAuto
		{
			displayName="Full Auto";
			reloadTime=0.1;
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_zafir_shot_soundset",
					"jsrs_2025_tailsystem_762mm_lmg_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"SyndikatLMG_silencerShot_SoundSet",
					"jsrs_2025_tailsystem_762mm_lmg_silenced_soundset"
				};
			};
		};
    };
};
