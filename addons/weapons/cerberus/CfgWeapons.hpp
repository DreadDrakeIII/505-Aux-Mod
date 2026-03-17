class manual;
class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;
class UnderBarrelSlot;

class CfgWeapons {
    class TKE_UCNMMG;

    class CLASS(CERBERUS): TKE_UCNMMG {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(CERBERUS);

        displayName = "[505th] Cerberus LMG";
        descriptionShort = "Cerberus is Light Machine Gun developed by Blackreach Armory Industries for support combat operations.";

        modes[] = {"manual"};
        magazines[] = {QCLASS(100_338_box)};
        magazineWell[] = { QCLASS(Magwell_Cerberus) };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 220;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "Optre_Recon_Sight",
                    "Optre_Recon_Sight_Green",
                    "Optre_Recon_Sight_Red",
                    "Optre_Evo_Sight_Riser",
                    "OPTRE_M12_Optic"
                };
            };
            class PointerSlot: PointerSlot {
                compatibleItems[] = {};
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {};
            };
            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {
                    "bipod_01_F_blk"
                };
            };
        };
        class manual: manual
		{
			displayName="Full Auto";
			reloadTime=0.2;
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_zafir_shot_soundset",
					"jsrs_2025_tailsystem_762mm_lmg_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"SyndikatLMG_silencerShot_SoundSet",
					"jsrs_2025_tailsystem_762mm_lmg_silenced_soundset"
				};
			};
		};
    };
};
