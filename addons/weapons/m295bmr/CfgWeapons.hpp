class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {
    class Rifle_Base_F;
    class srifle_EBR_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };

    // --- Base OPTRE class ---
    class OPTRE_M295_BMR: srifle_EBR_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
        };
        class Single: Mode_SemiAuto {};
        class FullAuto: Mode_FullAuto {};
    };

    // --- EHB custom version ---
    class CLASS(M295_BMR): OPTRE_M295_BMR {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M295_BMR);

        displayName = "[505th] M295 BMR";
        descriptionShort = "Hi-Power Rifle • 7.62×V7 • 25-round magazine";
        picture = "\OPTRE_Weapons\DMR\icons\M392_CA.paa";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";

        magazines[] = { QCLASS(25Rnd_762x51_Mag) };
        modes[] = { "Single", "FullAuto" };

        dispersion = 0.00029;
        maxZeroing = 1600;
        discreteDistance[] = {100,200,300,400,500,600};
        discreteDistanceInitIndex = 0;

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 75;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "OPTRE_BR45_Scope",
                    "OPTRE_BR55HB_Scope",
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
                compatibleItems[] = {
                    "OPTRE_Ma5Suppressor",
                    "OPTRE_M247a1_Flashhider"
                };
            };
        };

        class Single: Single {
            displayName = "Semi-Auto";
            reloadTime = 0.15;
            dispersion = 0.00029;
            recoil = "recoil_ebr";
            recoilProne = "recoil_single_prone_ebr";
            soundContinuous = 0;

            minRange = 2;   minRangeProbab = 0.3;
            midRange = 300; midRangeProbab = 0.7;
            maxRange = 800; maxRangeProbab = 0.1;

            aiRateOfFire = 1.5;
            aiRateOfFireDispersion = 1;
            aiRateOfFireDistance = 500;
        };

        class FullAuto: FullAuto {
            displayName = "Full-Auto";
            reloadTime = 0.09;
            dispersion = 0.00033;
            recoil = "recoil_auto_primary_3outof10";
            recoilProne = "recoil_auto_prone_primary_3outof10";
            soundContinuous = 0;

            minRange = 0;   minRangeProbab = 0.9;
            midRange = 200; midRangeProbab = 0.7;
            maxRange = 400; maxRangeProbab = 0.05;

            aiRateOfFire = 0.1;
            aiRateOfFireDispersion = 1;
            aiRateOfFireDistance = 50;
        };
    };
};
