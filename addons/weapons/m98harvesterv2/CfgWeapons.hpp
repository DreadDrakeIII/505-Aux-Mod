class Mode_SemiAuto;
class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;
class UnderBarrelSlot;

class CfgWeapons {
    class TCP_srifle_SRS99;

    // ================================
    // M98 HARVESTER II - Anti-Material Rifle
    // Heavy sniper rifle for anti-material support
    // ================================
    class CLASS(M98_HARVESTER_II): TCP_srifle_SRS99 {
        SCOPE_PUBLIC;
        author = AUTHOR;

        baseWeapon = QCLASS(M98_HARVESTER_II);

        // User-facing information
        displayName = "[505th] M98 Harvester II";
        descriptionShort = "M98 Harvester II is an upgraded version of the M98 Harvester developed by Blackreach Armory Industries.";

        picture = "\TCP\Weapons\LongRangeRifles\SRS99\data\ui\icon_srifle_SRS99_X_ca.paa";


        // Behaviour / performance
        modes[] = { "Single" };

        // Magazine: Varies of magazines
        magazines[] = { QCLASS(5Rnd_147x114_APFSDS_Magv2),
                        QCLASS(5Rnd_147x114_HVAP_Magv2),
                        QCLASS(5Rnd_147x114_HEDP_Magv2)
                      };
        magazineWell[] = {QCLASS(Magwell_M98_Harvester_II)};

        reloadMagazineSound[] = {"\BLU\OLI\addons\weapons\m98harvesterv2\data\sound\m98h_reload.ogg",1,1};

        class LinkedItems {
            class Cows {
                slot = "CowsSlot"; // Required slot name
                item = "TCP_optic_Oracle_N"; // Classname of the optic
            };

            class Pointer {
                slot = "PointerSlot"; // Required slot name
                item = ""; // Classname of the pointer
            };

            class Muzzle {
                slot = "MuzzleSlot"; // Required slot name
                item = "TCP_muzzle_brake_127_02"; // Classname of the muzzle
            };
        };

        // Weapon handling
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 284;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    QCLASS(M98HA_Scope),
                    "TCP_optic_Oracle_N"
                };
            };

            class PointerSlot: PointerSlot {
                compatibleItems[] = {};
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "TCP_muzzle_brake_127_02",
                    "TCP_muzzle_snds_523_01"
                };
            };

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {};
            };
        };

        class Single: Mode_SemiAuto
		{
			displayName="Semi";
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"OPTRE_SniperRifle_SoundSet",
					"jsrs_2025_tailsystem_50bmg_rifle_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"DMR05_silencerShot_SoundSet",
					"jsrs_2025_tailsystem_50bmg_rifle_silenced_soundset"
				};
			};
		};
    };
};
