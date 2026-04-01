class Single;
class FullAuto;
class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;

class CfgWeapons {
    class SMG_05_F;

    class CLASS(MPK5): SMG_05_F {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(MPK5);

        displayName = "[505th] MPK-5";
        descriptionShort = "The MPK-5 Submachine Gun is a compact personal defense weapon developed by Blackreach Armory Industries for close-quarters combat operations.";

        modes[] = {"Single","FullAuto"};
        magazines[] = {QCLASS(32Rnd_9x21_Mag)};
        magazineWell[] = { QCLASS(Magwell_MPK5) };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 40;

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
                    "muzzle_snds_9mm_long"
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
    };
};
