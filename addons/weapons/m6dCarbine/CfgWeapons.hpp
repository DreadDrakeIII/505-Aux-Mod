class Single;
class Burst;
class FullAuto;
class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;

class CfgWeapons {
    class OPTRE_M6D_Carbine_Black_F;

    class CLASS(M6D_CARBINE): OPTRE_M6D_Carbine_Black_F {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M6D_CARBINE);

        displayName = "[505th] M6D Carbine";
        descriptionShort = "M6D Carbine Submachine Gun developed by Blackreach Armory Industries";

        model = "\OPTRE_Weapons_Pistols\M6D_Carbine\m6d_carbine.p3d";
        picture = "\OPTRE_Weapons_Pistols\M6D_Carbine\Data\icons\weapon\black.paa";

        modes[] = {"Single", "Burst", "FullAuto"};
        magazines[] = { QCLASS(40Rnd_127x40_Mag) };
        magazineWell[] = { QCLASS(Magwell_M6D_CARBINE) };


        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 33;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "OPTRE_M6D_Scope_Black"
                };
            };

            class PointerSlot: PointerSlot {
                compatibleItems[] = {
                    "OPTRE_M6D_Carbine_Flashlight",
                    "OPTRE_M6D_Carbine_IR",
                    "OPTRE_M6D_Carbine_Vis_Red"
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "OPTRE_M6D_Carbine_Brake",
                    "OPTRE_M6D_Carbine_Suppressor"
                };
            };
        };

        		class Single: Single
		{
			displayName="Semi";
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[] =
                {
                    "OPTRE_M6_Pistol_Shot_SoundSet",
                    "4Five_Tail_SoundSet",
                    "4Five_InteriorTail_SoundSet"
                };
			};
			class SilencedSound: BaseSoundModeType
			{
				SoundSetShot[] =
                {
                    "4Five_silencerShot_SoundSet",
                    "4Five_silencerTail_SoundSet",
                    "4Five_silencerInteriorTail_SoundSet"
                };
			};
		};

        class Burst: Burst
		{
			displayName="Burst";
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				SoundSetShot[] =
                {
                    "SMGPDW2000_Shot_SoundSet",
                    "SMGPDW2000_Tail_SoundSet",
                    "SMGPDW2000_InteriorTail_SoundSet"
                };
			};
			class SilencedSound: BaseSoundModeType
			{
				SoundSetShot[] =
                {
                    "SMGPDW2000_silencerShot_SoundSet",
                    "SMGPDW2000_silencerTail_SoundSet",
                    "SMGPDW2000_silencerInteriorTail_SoundSet"
                };
			};
		};

		class FullAuto: FullAuto
		{
			displayName="Full Auto";
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[] =
                {
                    "OPTRE_M6_Pistol_Shot_SoundSet",
                    "4Five_Tail_SoundSet",
                    "4Five_InteriorTail_SoundSet"
                };
			};
			class SilencedSound: BaseSoundModeType
			{
				SoundSetShot[] =
                {
                    "4Five_silencerShot_SoundSet",
                    "4Five_silencerTail_SoundSet",
                    "4Five_silencerInteriorTail_SoundSet"
                };
			};
		};
    };
};
