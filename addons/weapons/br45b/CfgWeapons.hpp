class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {
    class Rifle_Base_F;
    class arifle_Mk20_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class OPTRE_BR45: arifle_Mk20_F {
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

    class CLASS(BR45B): OPTRE_BR45 {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(BR45B);

        displayName = "[505th] BR45B Battle Rifle";
        descriptionShort = "Hi-Power Rifle • 9.5x40 • 32-round mag • Medium range";
        picture = "\OPTRE_weapons\br\icons\br45_icon.paa";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";

        modes[] = { "Single", "FullAuto" };
        magazines[] = { QCLASS(32Rnd_95x40_Mag) };
        magazineWell[] = {QCLASS(Magwell_BR45B)};

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 45;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "Optre_Recon_Sight",
                    "Optre_Recon_Sight_Green",
                    "Optre_Recon_Sight_Red",
                    "Optre_Evo_Sight_Riser",
                    "OPTRE_M12_Optic",
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
                compatibleItems[] = {
                    "OPTRE_Ma5Suppressor",
                    "OPTRE_M247a1_Flashhider"
                };
            };

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {
                    "OPTRE_BR45Grip"
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

        class FullAuto: FullAuto {
            displayName = "Full Auto";
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
