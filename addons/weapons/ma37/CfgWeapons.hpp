class Mode_SemiAuto;
class Mode_FullAuto;
class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;

class CfgWeapons {
    class TCP_arifle_MA37;

    class CLASS(MA37): TCP_arifle_MA37 {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(MA37);

        displayName = "[505th] MA37";
        descriptionShort = "Assault Rifle developed by Blackreach Armory";
        picture = "\TCP\Weapons\Rifles\MA37\data\ui\icon_arifle_MA37_X_ca.paa";
        model = "\TCP\Weapons\Rifles\MA37\MA37.p3d";

        modes[] = {"Single", "FullAuto"};
        magazines[] = {QCLASS(40Rnd_762x51_Mag)};
        magazineWell[] = {QCLASS(Magwell_MA37)};

        class FlashLight {};
        class TCP_weaponTypes {};

        reloadMagazineSound[] = {"\BLU\OLI\addons\weapons\ma37\data\sound\ma37_reload.ogg",1,1};

        class LinkedItems {
            class Cows {
                slot = "CowsSlot";
                item = "TCP_optic_EVOSJ";
            };
            class Pointer {
                slot = "PointerSlot";
                item = "OLI_MA37_LAM";
            };
            class Muzzle {
                slot = "MuzzleSlot";
                item = "TCP_muzzle_brake_762_01";
            };
        };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 92;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "TCP_optic_EVOSJ"
                };
            };

            class PointerSlot: PointerSlot {
                compatibleItems[] = {
                    "OLI_MA37_LAM",
                    "OLI_MA37_LAM_IR",
                    "OLI_MA37_LAM_FL"
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "TCP_muzzle_brake_762_01"
                };
            };
        };

        class Single: Mode_SemiAuto {
            displayName = "Semi";
            reloadTime = 0.092307702;
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {
                    "OPTRE_MA5C_SoundSet",
                    "jsrs_2025_tailsystem_762mm_rifle_soundset"
                };
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {
                    "jsrs_2025_ak12_shot_silenced_soundset",
                    "jsrs_2025_tailsystem_762mm_rifle_silenced_soundset"
                };
            };
        };

        class FullAuto: Mode_FullAuto {
            displayName = "Full Auto";
            reloadTime = 0.092307702;
            class BaseSoundModeType;
            class StandardSound: BaseSoundModeType {
                soundSetShot[] = {
                    "OPTRE_MA5C_SoundSet",
                    "jsrs_2025_tailsystem_762mm_rifle_soundset"
                };
            };
            class SilencedSound: BaseSoundModeType {
                soundSetShot[] = {
                    "jsrs_2025_ak12_shot_silenced_soundset",
                    "jsrs_2025_tailsystem_762mm_rifle_silenced_soundset"
                };
            };
        };
    };

    class CLASS(MA37_NoLight): CLASS(MA37) {
        SCOPE_HIDDEN;
        baseWeapon = QCLASS(MA37);
        class Flashlight {};
    };
};
