class Single;
class Burst;
class FullAuto;
class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;

class CfgWeapons {
    class OPTRE_M7;

    class CLASS(M7_Caseless): OPTRE_M7 {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M7_Caseless);

        displayName = "[505th] M7 Caseless";
        descriptionShort = "The M7/Caseless Submachine Gun (M7/SMG) is a personal defense weapon developed and manufactured by Misriah Armory.";

        model = "\OPTRE_Weapons\SMG\SMG.p3d";
        picture = "\OPTRE_weapons\smg\icons\smg.paa";

        modes[] = {"Single","Burst","FullAuto"};
        magazines[] = {QCLASS(60Rnd_5x23_Mag)};
        magazineWell[] = { QCLASS(Magwell_M7_Caseless) };


        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 30;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "OPTRE_M7_Sight",
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
                    "OPTRE_M7_silencer"
                };
            };
        };

        class Single: Single
		{
			displayName="Semi";
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_SMG_SoundSet",
					"jsrs_2025_tailsystem_acp_smg_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_SMG_Silenced_SoundSet",
					"jsrs_2025_tailsystem_acp_smg_silenced_soundset"
				};
			};
		};

		class FullAuto: FullAuto
		{
			displayName="Full Auto";
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_SMG_SoundSet",
					"jsrs_2025_tailsystem_acp_smg_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_SMG_Silenced_SoundSet",
					"jsrs_2025_tailsystem_acp_smg_silenced_soundset"
				};
			};
		};

		class Burst: Burst
		{
			displayName="3-Round Burst";
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_SMG_SoundSet",
					"jsrs_2025_tailsystem_acp_smg_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_SMG_Silenced_SoundSet",
					"jsrs_2025_tailsystem_acp_smg_silenced_soundset"
				};
			};
		};
    };

};
