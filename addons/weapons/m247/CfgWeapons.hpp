class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {

    class Rifle_Long_Base_F;
    class LMG_Mk200_F: Rifle_Long_Base_F {
        class WeaponSlotsInfo;
    };

    class OPTRE_M247: LMG_Mk200_F {
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

    class CLASS(M274): OPTRE_M247 {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M247);

        displayName = "[505th] M247 Heavy Machine Gun";
        descriptionShort = "Heavy Machine Gun • 9.5x40mm • 400Rnd box";
        picture = "\OPTRE_Weapons_MG\m247\data\icons\m247_icon.paa";
        pictureMjolnirHud = "\OPTRE_Suit_Scripts\textures\weaponIcons\MachineGuns\M247_icon.paa";
        model = "\OPTRE_Weapons_MG\m247\M247.p3d";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";
        deployedPivot = "bipod";
        Eye = "OPTRE_EYE_HUD_AmmoCount_LMG";
        Glasses = "OPTRE_GLASS_HUD_AmmoCount_LMG";


        modes[] = {"Single", "FullAuto"};
        magazines[] = {QCLASS(400Rnd_762x51_Box)};
        maxZeroing = 600;
        discreteDistance[] = {50,100,200,300,400,500,600};
        discreteDistanceInitIndex = 1;
        HUD_TotalPosibleBullet = 400;
        maxRecoilSway = 0.006;
        swayDecaySpeed = 1.5;
        maxRange=600;
        maxRangeToHit=580;

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 150;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "OPTRE_BR45_Scope",
                    "OPTRE_BR55HB_Scope_Grey"
                };
            };

            class PointerSlot: PointerSlot {
                class CompatibleItems {
                    ATTACHMENTS_POINTER_BASE
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                };
            };

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {
                    "bipod_01_F_blk"
                };
            };
        };

        class Single: Single {
            displayName = "Single";
        };

        class FullAuto: FullAuto {
            displayName = "Full Auto";
        };
    };

};
