class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class CfgWeapons {

    class Rifle_Base_F;
    class Rifle_Short_Base_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };

    class hgun_PDW2000_F: Rifle_Short_Base_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
        };

        class Single: Mode_SemiAuto {
                    };
        class Burst: Mode_Burst {
                    };
        class FullAuto: Mode_FullAuto {
                    };
    };

    class CLASS(CPW): hgun_PDW2000_F {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(CPW);

        displayName = "[505th] CPW";
        descriptionShort = "CPW Submachine Gun";

        model = "\A3\Weapons_F_gamma\Smgs\pdw2000\pdw2000_F.p3d";
        picture = "\A3\Weapons_F_gamma\Smgs\pdw2000\data\UI\gear_pdw2X_X_CA.paa";

        modes[] = {"Single","Burst","FullAuto"};
        magazines[] = {QCLASS(30Rnd_9x21_Mag)};
        magazineWell[] = { QCLASS(Magwell_CPW) };


        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 33;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "OPTRE_M7_Sight"
                };
            };

            class PointerSlot: PointerSlot {
                class CompatibleItems {};
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "muzzle_snds_L"
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
					"jsrs_2025_pdw2000_shot_soundset",
					"jsrs_2025_tailsystem_acp_smg_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_pdw2000_shot_silenced_soundset",
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
					"jsrs_2025_pdw2000_shot_soundset",
					"jsrs_2025_tailsystem_acp_smg_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_pdw2000_shot_silenced_soundset",
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
					"jsrs_2025_pdw2000_shot_soundset",
					"jsrs_2025_tailsystem_acp_smg_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_pdw2000_shot_silenced_soundset",
					"jsrs_2025_tailsystem_acp_smg_silenced_soundset"
				};
			};
		};
    };

};
