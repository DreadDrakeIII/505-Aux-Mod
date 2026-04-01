class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {
    class Rifle_Base_F;
    class DMR_03_base_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class OPTRE_COMMANDO: DMR_03_base_F {
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

    // ================================
    // VK78 Commando - Hi-Power Rifle
    // ================================
    class CLASS(VK78_COMMANDO): OPTRE_COMMANDO {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(VK78_COMMANDO);

        // User-facing
        displayName = "[505th] VK78 Commando (Hi-Power)";
        descriptionShort = "Hi-Power Rifle • 9.5×VX2 • 20Rnd magazine • High penetration • Long range";
        picture = "\OPTRE_Weapons\Commando\icons\vk78o_icon.paa";
        model = "\OPTRE_Weapons\Commando\Commando.p3d";

        // Behaviour / performance
        modes[] = { "Single", "FullAuto" };

        // Magazine: low capacity 20 rnd 9.5 VX2
        magazines[] = { QCLASS(20Rnd_95xVX2_Mag) };
        magazineWell[] = { QCLASS(Magwell_VK78_COMMANDO) };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 85; // slightly heavier - hi-power rifle

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

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {};
            };
        };

        class Single: Single
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

		class FullAuto: FullAuto
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
