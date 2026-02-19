class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {

    class Rifle_Base_F;
    class arifle_MX_Base_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };

    class OPTRE_MA5C: arifle_MX_Base_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
        };

        class Single: Mode_SemiAuto {
            class StandardSound;
        };
        class FullAuto: Mode_FullAuto {
            class StandardSound;
        };
    };

    class CLASS(MA5C): OPTRE_MA5C {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(MA5C);

        displayName = "[505th] MA5C Assault Rifle";
        descriptionShort = "General Purpose Assault Rifle • 7.62×51mm • 32Rnd Magazine";
        picture = "\OPTRE_weapons\ar\icons\ma5c_icon.paa";
        model = "\OPTRE_Weapons\AR\MA5C.p3d";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";

        modes[] = {"Single", "FullAuto"};
        magazines[] = {QCLASS(32Rnd_762x51_Mag)};
        magazineWell[] = {QCLASS(Magwell_MA5C)};

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
        };

        class Single: Single
		{
			displayName="Semi";
			reloadTime=0.092307702;
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_MA5C_SoundSet",
					"jsrs_2025_tailsystem_762mm_rifle_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_ak12_shot_silenced_soundset",
					"jsrs_2025_tailsystem_762mm_rifle_silenced_soundset"
				};
			};
		};

		class FullAuto: FullAuto
		{
			displayName="Full Auto";
			reloadTime=0.092307702;
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_MA5C_SoundSet",
					"jsrs_2025_tailsystem_762mm_rifle_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_ak12_shot_silenced_soundset",
					"jsrs_2025_tailsystem_762mm_rifle_silenced_soundset"
				};
			};
		};
    };
};
