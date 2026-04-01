class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {

    class Rifle_Base_F;
    class arifle_MX_Base_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };

    class OPTRE_MA5CGL: arifle_MX_Base_F {
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

    class CLASS(MA5CGL): OPTRE_MA5CGL {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(MA5CGL);

        displayName = "[505th] MA5C-GL Assault Rifle";
        descriptionShort = "Assault Rifle • 7.62×51mm • 32Rnd Magazine • 40mm GL";
        picture = "\OPTRE_weapons\ar\icons\ma5cgl_icon.paa";
        model = "\OPTRE_Weapons\AR\MA5CGL.p3d";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";

        modes[] = {"Single", "FullAuto"};
        magazines[] = {QCLASS(32Rnd_762x51_Mag)};
        magazineWell[] = {QCLASS(Magwell_MA5C)};

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 75;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
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
                magazines[] = {
                    "3Rnd_HE_Grenade_shell",
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

        class Single: Single
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

		class FullAuto: FullAuto
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
