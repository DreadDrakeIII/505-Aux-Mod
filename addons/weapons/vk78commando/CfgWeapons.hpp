class Mode_SemiAuto;
class Mode_FullAuto;
class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;
class UnderBarrelSlot;

class CfgWeapons {
    class TCP_srifle_VK78_Gray;

    class CLASS(VK78_COMMANDO): TCP_srifle_VK78_Gray {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(VK78_COMMANDO);

        // User-facing
        displayName = "[505th] VK78 Commando (Hi-Power)";
        descriptionShort = "Hi-Power Rifle • 9.5×VX2 • 20Rnd magazine • High penetration • Long range";
        picture = "\TCP\Weapons\LongRangeRifles\VK78\data\ui\icon_srifle_VK78_Gray_X_ca.paa";

        // Behaviour / performance
        modes[] = { "Single", "FullAuto" };

        // Magazine: low capacity 20 rnd 9.5 VX2
        magazines[] = { QCLASS(20Rnd_95xVX2_Mag) };
        magazineWell[] = { QCLASS(Magwell_VK78_COMMANDO) };

        class LinkedItems {
            class Cows {
                slot = "CowsSlot"; // Required slot name
                item = ""; // Classname of the optic
            };

            class Pointer {
                slot = "PointerSlot"; // Required slot name
                item = "TCP_rail_ammoCounter_VK78"; // Classname of the pointer
            };

            class Muzzle {
                slot = "MuzzleSlot"; // Required slot name
                item = "TCP_muzzle_brake_762_01"; // Classname of the muzzle
            };
        };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 85; // slightly heavier - hi-power rifle

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "TCP_optic_M11VERO_Blue",
                    "TCP_optic_M11VERO",
                    "TCP_optic_M27RCO",
                    "TCP_optic_M43RCO_CUP",
                    "TCP_optic_EVOSD"
                };
            };

            class PointerSlot: PointerSlot {
                compatibleItems[] = {
                    "TCP_rail_ammoCounter_VK78",
                    "TCP_acc_flashlight_M6G",
                    "TCP_acc_pointer_lam_M6G"
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "TCP_muzzle_brake_762_01"
                };
            };

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {};
            };
        };

        class Single: Mode_SemiAuto
		{
			displayName="Semi";
			reloadTime=0.12;
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"Msbs65_01_Shot_SoundSet",
					"jsrs_2025_tailsystem_762mm_dmr_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"Msbs65_01_Shot_Silencer_SoundSet",
					"jsrs_2025_tailsystem_762mm_dmr_silenced_soundset"
				};
			};
		};

		class FullAuto: Mode_FullAuto
		{
			displayName="Full Auto";
			reloadTime=0.14;
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"Msbs65_01_Shot_SoundSet",
					"jsrs_2025_tailsystem_762mm_dmr_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"Msbs65_01_Shot_Silencer_SoundSet",
					"jsrs_2025_tailsystem_762mm_dmr_silenced_soundset"
				};
			};
		};
    };
};
