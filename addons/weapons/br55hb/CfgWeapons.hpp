class Mode_SemiAuto;
class Mode_Burst;

class CfgWeapons {
    class Rifle_Base_F;
    class arifle_Mk20_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class TCP_srifle_BR55HB: arifle_Mk20_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
            class UnderBarrelSlot;
        };

        class Single: Mode_SemiAuto {
        };
        class Burst: Mode_Burst {
        };
    };

    class CLASS(BR55HB): TCP_srifle_BR55HB {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(BR55HB);

        displayName = "[505th] BR55HB Battle Rifle";
        descriptionShort = "Hi-Power Rifle developed by Blackreach Armory";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";

        modes[] = { "Single", "Burst" };
        magazines[] = { QCLASS(36Rnd_95x40_Mag) };
        magazineWell[] = {QCLASS(Magwell_BR55HB)};

        reloadMagazineSound[] = {"\BLU\OLI\addons\weapons\br55hb\data\sound\br55hb_reload.ogg",1,1};

        class LinkedItems {
            class Cows {
                slot = "CowsSlot"; // Required slot name
                item = ""; // Classname of the optic
            };

            class Pointer {
                slot = "PointerSlot"; // Required slot name
                item = "OLI_ANPEQ6G_VL"; // Classname of the pointer
            };

            class Muzzle {
                slot = "MuzzleSlot"; // Required slot name
                item = "TCP_muzzle_brake_95_01"; // Classname of the Muzzle
            };
        };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 45;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "Optre_Recon_Sight",
                    "Optre_Recon_Sight_Green",
                    "Optre_Recon_Sight_Red",
                    "TCP_optic_M11VERO_Blue",
                    "TCP_optic_M11VERO",
                    "TCP_optic_M27RCO",
                    "TCP_optic_M43RCO",
                    "TCP_optic_M43RCO_CUP",
                    "TCP_optic_EVOSD"

                };
            };

            class PointerSlot: PointerSlot {
                compatibleItems[] = {
                    "OLI_ANPEQ6G",
                    "OLI_ANPEQ6G_VL"
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "TCP_muzzle_brake_95_01"
                };
            };

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {
                };
            };
        };

        class Single: Single {
            displayName = "Semi";
            reloadTime = 0.0923077;
            class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_Battlerifle_SoundSet",
					"jsrs_2025_tailsystem_762mm_rifle_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"Msbs65_01_Shot_Silencer_SoundSet",
					"jsrs_2025_tailsystem_762mm_rifle_silenced_soundset"
				};
			};
        };

        class Burst: Burst {
            displayName = "Burst";
            reloadTime = 0.0923077;
            class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_Battlerifle_SoundSet",
					"jsrs_2025_tailsystem_762mm_rifle_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"Msbs65_01_Shot_Silencer_SoundSet",
					"jsrs_2025_tailsystem_762mm_rifle_silenced_soundset"
				};
			};
        };
    };
};
