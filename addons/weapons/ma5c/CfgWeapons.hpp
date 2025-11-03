class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {
    class Rifle_Base_F;
    class arifle_Mk20_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class OPTRE_MA5C: arifle_Mk20_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
        };

        class Single: Mode_SemiAuto {
            class StandardSound;
        };
        class FullAuto: Mode_FullAuto {
            class StandardSound;
        };
    };

    class CLASS(MA5C): OPTRE_MA5C {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(MA5C);

        displayName = "[505th] MA5C Assault Rifle";
        descriptionShort = "General Purpose Assault Rifle • 7.62×51mm • 60Rnd Magazine";
        model = "\OPTRE_Weapons\AR\MA5C.p3d";
        picture = "\OPTRE_weapons\ar\icons\ma5c_icon.paa";
        HUD_TotalPosibleBullet = 32;
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";

        modes[] = { "Single", "FullAuto" };
        magazines[] = { QCLASS(32Rnd_762x51_Mag) };
        dispersion = 0.00029;
        maxZeroing = 400;
        discreteDistance[] = {50,100,200,300,400};
        discreteDistanceInitIndex = 0;

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 75;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "Optre_Evo_Sight_Riser",
                    "OPTRE_M12_Optic"
                };
            };

            class PointerSlot: PointerSlot {
                compatibleItems[] = {
                    "OPTRE_BMR_Laser"
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "OPTRE_Ma5Suppressor",
                    "OPTRE_M247a1_Flashhider"
                };
            };
        };

        class Single: Single {
            displayName = "Semi";
            reloadTime = 0.0923077;
            dispersion = 0.00075;
            soundContinuous = 0;
            recoil = "recoil_single_trg";
            recoilProne = "recoil_single_prone_trg";
            minRange = 2;
            minRangeProbab = 0.01;
            midRange = 200;
            midRangeProbab = 0.1;
            maxRange = 400;
            maxRangeProbab = 0.01;
            aiRateOfFire = 2.0;
            aiRateOfFireDispersion = 1;
            aiRateOfFireDistance = 500;

            class StandardSound: StandardSound {
                soundSetShot[] = {QCLASS(SoundSet_MA5CShot)};
            };
        };

        class FullAuto: FullAuto {
            displayName = "Full Auto";
            reloadTime = 0.0923077;
            dispersion = 0.00085;
            soundContinuous = 0;
            recoil = "recoil_auto_trg";
            recoilProne = "recoil_auto_prone_trg";
            minRange = 2;
            minRangeProbab = 0.01;
            midRange = 200;
            midRangeProbab = 0.1;
            maxRange = 400;
            maxRangeProbab = 0.01;
            aiRateOfFire = 2.0;
            aiRateOfFireDispersion = 1;
            aiRateOfFireDistance = 500;

            class StandardSound: StandardSound {
                soundSetShot[] = {QCLASS(SoundSet_MA5CShot)};
            };
        };
    };
};
