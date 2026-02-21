class Single;
class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;

class CfgWeapons {
    class TKE_MDPistolBlack;

    class CLASS(MHG16): TKE_MDPistolBlack {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(MHG16);

        displayName = "[505th] MHG-16";
        descriptionShort = "MHG-16 Pistol developed by Blackreach Armory Industries";

        modes[] = {"Single"};
        magazines[] = {QCLASS(12Rnd_45ACP_Mag)};
        magazineWell[]={QCLASS(Magwell_MHG16)};


        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 21;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                };
            };

            class PointerSlot: PointerSlot {
                class CompatibleItems {};
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                };
            };
        };
    };
    class Single: Single
		{
			displayName="Single";
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"WBK_TKE_MDPistol_SoundSet",
					"jsrs_2025_tailsystem_acp_pistol_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"4Five_silencerShot_SoundSet",
					"jsrs_2025_tailsystem_acp_pistol_silenced_soundset"
				};
			};
		};
};
