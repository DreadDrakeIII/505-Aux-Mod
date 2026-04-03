class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {
    class Rifle_Base_F;
    class arifle_Mk20_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class OPTRE_BR45GL: arifle_Mk20_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
            class GL_Muzzle;

        };

        class Single: Mode_SemiAuto {
        };
        class FullAuto: Mode_FullAuto {
        };
    };

    class CLASS(BR45GL): OPTRE_BR45GL {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(BR45GL);

        displayName = "[505th] BR45-GL Battle Rifle";
        descriptionShort = "Hi-Power Rifle • 9.5x40 • 32-round mag • 40mm GL";

        model = "\OPTRE_Weapons\BR\BR45GL";
        picture = "\OPTRE_weapons\br\icons\br45_icon.paa";

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

            class GL_Muzzle: GL_Muzzle {
                displayName = "GL";
                magazines[] = {
                    "1Rnd_HE_Grenade_shell",
                    "UGL_FlareGreen_F",
                    "UGL_FlareCIR_F",
                    "UGL_FlareRed_F",
                    "UGL_FlareWhite_F",
                    "UGL_FlareYellow_F",
                    "UGL_FlareGreen_Illumination_F",
                    "UGL_FlareRed_Illumination_F",
                    "UGL_FlareWhite_Illumination_F",
                    "UGL_FlareYellow_Illumination_F",
                    "1Rnd_SmokeBlue_Grenade_shell",
                    "1Rnd_SmokeGreen_Grenade_shell",
                    "1Rnd_SmokeOrange_Grenade_shell",
                    "1Rnd_SmokePurple_Grenade_shell",
                    "1Rnd_SmokeRed_Grenade_shell",
                    "1Rnd_Smoke_Grenade_shell",
                    "1Rnd_SmokeYellow_Grenade_shell"
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
