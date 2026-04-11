class Mode_SemiAuto;
class Mode_FullAuto;
class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;
class GL_Muzzle;

class CfgWeapons {

    class TCP_arifle_MA37_GL;

    class CLASS(MA37GL): TCP_arifle_MA37_GL {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(MA37GL);

        displayName = "[505th] MA37-GL";
        descriptionShort = "Assault Rifle with Grenade Launcher developed by Blackreach Armory";
        picture = "\TCP\Weapons\Rifles\MA37\data\ui\icon_arifle_MA37_GL_X_ca.paa";

        modes[] = {"Single", "FullAuto"};
        magazines[] = {QCLASS(40Rnd_762x51_Mag)};
        magazineWell[] = { QCLASS(Magwell_MA37) };

        class LinkedItems {
            class Cows {
                slot = "CowsSlot"; // Required slot name
                item = "TCP_optic_EVOSJ"; // Classname of the optic
            };

            class Pointer {
                slot = "PointerSlot"; // Required slot name
                item = "TCP_acc_pointer_lam_MA37"; // Classname of the pointer
            };

            class Muzzle {
                slot = "MuzzleSlot"; // Required slot name
                item = "TCP_muzzle_brake_762_01"; // Classname of the Muzzle
            };
        };
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 92;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "TCP_optic_EVOSJ"
                };
            };

            class PointerSlot: PointerSlot {
                compatibleItems[] = {
                    "TCP_acc_pointer_lam_MA37",
                    "TCP_acc_pointer_lam_MA37_IR"
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "TCP_muzzle_brake_762_01"
                };
            };

            class GL_Muzzle: GL_Muzzle {
                compatibleItems[] = {
                    "TCP_1Rnd_40_Shell_Signal_Green",
                    "TCP_1Rnd_40_Shell_Signal_Red",
                    "TCP_1Rnd_40_Shell_Signal_White",
                    "TCP_1Rnd_40_Shell_Signal_Yellow",
                    "TCP_1Rnd_40_Shell_HE",
                    "TCP_1Rnd_40_Shell_Smoke_Blue",
                    "TCP_1Rnd_40_Shell_Smoke_Green",
                    "TCP_1Rnd_40_Shell_Smoke_Red",
                    "TCP_1Rnd_40_Shell_Smoke_White",
                    "TCP_1Rnd_40_Shell_Smoke_Yellow",
                    "TCP_1Rnd_40_Shell_Smoke_Orange",
                    "TCP_1Rnd_40_Shell_Smoke_Purple",
                    "TCP_1Rnd_40_Shell_TD"
                };
             };
        };

        class Single: Mode_SemiAuto
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

		class FullAuto: Mode_FullAuto
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
