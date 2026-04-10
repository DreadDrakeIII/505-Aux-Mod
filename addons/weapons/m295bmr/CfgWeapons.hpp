class Mode_SemiAuto;
class Mode_Burst;

class CfgWeapons {
    class Rifle_Base_F;
    class srifle_EBR_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };

    class OPTRE_M295_BMR: srifle_EBR_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
        };
        class Single: Mode_SemiAuto {};
        class Burst: Mode_Burst {};
    };

    class CLASS(M295_BMR): OPTRE_M295_BMR {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M295_BMR);

        displayName = "[505th] M295 BMR";
        descriptionShort = "Hi-Power Rifle • 7.62×V7 • 25-round magazine";
        picture = "\OPTRE_Weapons\DMR\icons\M392_CA.paa";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";

        magazines[] = { QCLASS(25Rnd_762xV7_Mag) };
        magazineWell[] = { QCLASS(Magwell_M295BMR) };
        modes[] = { "Single", "Burst" };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 75;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "OPTRE_BR45_Scope",
                    "OPTRE_BR55HB_Scope",
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
        };

        class Single: Single
		{
			displayName="Semi";
			reloadTime=0.15000001;
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_DMR_SoundSet",
					"jsrs_2025_tailsystem_762mm_dmr_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"DMR05_silencerShot_SoundSet",
					"jsrs_2025_tailsystem_762mm_dmr_silenced_soundset"
				};
			};
		};

		class Burst: Burst
		{
			displayName="Burst";
			reloadTime=0.090000004;
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_DMR_SoundSet",
					"jsrs_2025_tailsystem_762mm_dmr_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"DMR05_silencerShot_SoundSet",
					"jsrs_2025_tailsystem_762mm_dmr_silenced_soundset"
				};
			};
		};
    };
};
