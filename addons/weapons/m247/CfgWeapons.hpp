class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {

    class Rifle_Long_Base_F;
    class LMG_Mk200_F: Rifle_Long_Base_F {
        class WeaponSlotsInfo;
    };

    class OPTRE_M247: LMG_Mk200_F {
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

    class CLASS(M247): OPTRE_M247 {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M247);

        displayName = "[505th] M247 Heavy Machine Gun";
        descriptionShort = "Heavy Machine Gun • 9.5x40mm • 400Rnd box";
        picture = "\OPTRE_Weapons_MG\m247\data\icons\m247_icon.paa";
        model = "\OPTRE_Weapons_MG\m247\M247.p3d";


        modes[] = {"Single", "FullAuto"};
        magazines[] = {QCLASS(400Rnd_762x51_Box)};
        magazineWell[] = { QCLASS(Magwell_M247) };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 150;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "OPTRE_BR45_Scope",
                    "OPTRE_BR55HB_Scope_Grey",
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
					"jsrs_2025_navid_shot_soundset",
					"jsrs_2025_tailsystem_Magnum_rifle_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_navid_shot_silenced_soundset",
					"jsrs_2025_tailsystem_Magnum_rifle_silenced_soundset"
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
					"jsrs_2025_navid_shot_soundset",
					"jsrs_2025_tailsystem_Magnum_rifle_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_navid_shot_silenced_soundset",
					"jsrs_2025_tailsystem_Magnum_rifle_silenced_soundset"
				};
			};
		};
    };
};
