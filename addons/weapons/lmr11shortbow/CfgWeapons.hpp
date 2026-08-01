class Mode_SemiAuto;
class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;
class UnderBarrelSlot;

class CfgWeapons {
    class TCP_srifle_M392;

    class CLASS(LMR11_SHORTBOW): TCP_srifle_M392 {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(LMR11_SHORTBOW);

        // User-facing
        displayName = "[505th] LMR11 Shortbow ";
        descriptionShort = "7.62x51mm • 30Rnd magazine • Sniper rifle";

        // Behaviour / performance
        modes[] = { "Single" };

        // Magazine: low capacity 15 rnd 9.5 VX2
        magazines[] = { QCLASS(30Rnd_762x51_Mag) };
        magazineWell[] = { QCLASS(Magwell_LMR11_SHORTBOW) };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 50; // Lighter short rifle

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
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
                compatibleItems[] = {
                    "OLI_ANPEQ6G",
                    "OLI_ANPEQ6G_VL"
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "TCP_muzzle_brake_762_03",
                    "TCP_muzzle_brake_762_01",
                    "TCP_muzzle_brake_762_02",
                };
            };

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {
                    "bipod_01_F_blk"
                };
            };
        };

        class Single: Mode_SemiAuto {

			displayName="Single";
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_cyrus_shot_soundset",
					"jsrs_2025_tailsystem_762mm_dmr_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"jsrs_2025_cyrus_shot_silenced_soundset",
					"jsrs_2025_tailsystem_762mm_dmr_silenced_soundset"
				};
			};
		};
    };
};
