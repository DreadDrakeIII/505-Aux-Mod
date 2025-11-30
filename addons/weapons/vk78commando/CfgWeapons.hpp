class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {
    class Rifle_Base_F;
    class DMR_03_base_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class OPTRE_COMMANDO: DMR_03_base_F {
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

    // ================================
    // VK78 Commando - Hi-Power Rifle
    // ================================
    class CLASS(VK78_COMMANDO): OPTRE_COMMANDO {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(VK78_COMMANDO);

        // User-facing
        displayName = "[505th] VK78 Commando (Hi-Power)";
        descriptionShort = "Hi-Power Rifle • 9.5×VX2 • 20Rnd magazine • High penetration • Long range";
        picture = "\OPTRE_Weapons\Commando\icons\vk78o_icon.paa";
        model = "\OPTRE_Weapons\Commando\Commando.p3d";

        // Behaviour / performance
        modes[] = { "Single", "FullAuto" };

        // Magazine: low capacity 20 rnd 9.5 VX2
        magazines[] = { QCLASS(20Rnd_95xVX2_Mag) };

        // Tighter base dispersion for long-range accuracy (great range)
        dispersion = 0.00018;          // base dispersion (weapon)
        maxZeroing = 800;              // extended zeroing (great range)
        discreteDistance[] = {100,200,300,400,600,800};
        discreteDistanceInitIndex = 2; // default 300m

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 85; // slightly heavier - hi-power rifle

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

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {};
            };
        };

        //
        // Semi (single shot) - accurate, used for long-range engagements
        //
        class Single: Single {
            displayName = "Semi";
            reloadTime = 0.12;          // semi delay (comfortable semi follow-up)
            dispersion = 0.00012;       // very tight for single shots at range
            soundContinuous = 0;
            recoil = "recoil_single_sdar";
            recoilProne = "recoil_single_prone_sdar";
            minRange = 10;
            minRangeProbab = 0.05;
            midRange = 400;
            midRangeProbab = 0.9;
            maxRange = 1200;
            maxRangeProbab = 0.3;
            aiRateOfFire = 4.0;
            aiRateOfFireDispersion = 1;
            aiRateOfFireDistance = 800;
        };

        //
        // Full auto - slower cyclic rate to reflect "slower fire rate" spec
        //
        class FullAuto: FullAuto {
            displayName = "Full Auto";
            reloadTime = 0.14;          // slower cyclic rate (~430–500 RPM depending on engine math)
            dispersion = 0.00032;       // a bit wider in full auto
            soundContinuous = 0;
            recoil = "recoil_single_sdar";
            recoilProne = "recoil_single_prone_sdar";
            minRange = 0;
            minRangeProbab = 0.01;
            midRange = 200;
            midRangeProbab = 0.6;
            maxRange = 600;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2.0;
            aiRateOfFireDispersion = 1;
            aiRateOfFireDistance = 400;
        };
    };
};
