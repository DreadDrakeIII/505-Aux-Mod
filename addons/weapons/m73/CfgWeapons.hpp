class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {

    class Rifle_Long_Base_F;
    class LMG_Mk200_F: Rifle_Long_Base_F {
        class WeaponSlotsInfo;
    };

    class OPTRE_M73: LMG_Mk200_F {
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

    class CLASS(M73): OPTRE_M73 {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M73);

        displayName = "[505th] M73 Light Machine Gun";
        descriptionShort = "Light Machine Gun • 9.5x40mm • 100Rnd box";
        picture = "\OPTRE_Weapons_MG\m73\data\icons\M73_1.paa";
        model = "\OPTRE_Weapons_MG\m73\M73.p3d";

        modes[] = {"Single", "FullAuto"};
        magazines[] = {QCLASS(100Rnd_95x40_Box)};
        magazineWell[] = { QCLASS(Magwell_M73) };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 75;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "Optre_Evo_Sight_Riser",
                    "OPTRE_M12_Optic"
                };
            };

            class PointerSlot: PointerSlot {
                class CompatibleItems {
                    ATTACHMENTS_POINTER_BASE
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "OPTRE_Ma5Suppressor",
                    "OPTRE_M247a1_Flashhider"
                };
            };

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {
                    "bipod_01_F_blk"
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
