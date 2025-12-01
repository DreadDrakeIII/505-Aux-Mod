class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {

    class Rifle_Long_Base_F;
    class LMG_Mk200_F: Rifle_Long_Base_F {
        class WeaponSlotsInfo;
    };

    class OPTRE_M73: LMG_Mk200_F {
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

    class CLASS(M73): OPTRE_M73 {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M73);

        displayName = "[505th] M73 Light Machine Gun";
        descriptionShort = "Light Machine Gun • 9.5x40mm • 100Rnd box";
        picture = "\OPTRE_Weapons_MG\m73\data\icons\M73_1.paa";
        pictureMjolnirHud = "\OPTRE_Suit_Scripts\textures\weaponIcons\MachineGuns\M73_icon.paa";
        model = "\OPTRE_Weapons_MG\m73\M73.p3d";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";
        deployedPivot = "bipod";
        Eye = "OPTRE_EYE_HUD_AmmoCount_LMG";
        Glasses = "OPTRE_GLASS_HUD_AmmoCount_LMG";


        modes[] = {"Single", "FullAuto"};
        magazines[] = {QCLASS(100Rnd_95x40_Box)};
        dispersion = 0.00055;
        maxZeroing = 600;
        discreteDistance[] = {50,100,200,300,400,500,600};
        discreteDistanceInitIndex = 1;
        HUD_TotalPosibleBullet = 100;
        maxRecoilSway = 0.006;
        swayDecaySpeed = 1.5;
        maxRange=600;
        maxRangeToHit=580;

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 75;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "Optre_Evo_Sight_Riser",
                    "OPTRE_M12_Optic"
                };
            };

            class PointerSlot: PointerSlot {
                class CompatibleItems {
                    ATTACHMENTS_POINTER_BASE
                };
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

        class Single: Single {
            displayName = "Semi";
            reloadTime = 0.075;
            dispersion = 0.00060;
            soundContinuous = 0;
            recoil = "recoil_single_primary_3outof10";
            recoilProne = "recoil_single_primary_prone_3outof10";
            minRange = 2;
            minRangeProbab = 0.3;
            midRange = 250;  // Better mid-range
            midRangeProbab = 0.7;  // Better hit chance
            maxRange = 500;  // Longer range
            maxRangeProbab = 0.05;
            aiRateOfFire = 1.5;
            aiRateOfFireDispersion = 1;
            aiRateOfFireDistance = 600;
        };

        class FullAuto: FullAuto {
            displayName = "Full Auto";
            reloadTime = 0.1;
            dispersion = 0.00065;
            soundContinuous = 0;
            recoil = "recoil_auto_primary_3outof10";
            recoilProne = "recoil_auto_primary_prone_3outof10";
            minRange = 2;
            minRangeProbab = 0.9;
            midRange = 200;
            midRangeProbab = 0.7;  // Much better hit chance
            maxRange = 600;  // Longer range
            maxRangeProbab = 0.06;  // Better long range accuracy
            aiRateOfFire = 0.5;
            aiRateOfFireDispersion = 1;
            aiRateOfFireDistance = 600;
        };
    };

};
