class Mode_SemiAuto;
class Mode_FullAuto;
class UGL_F;

class CfgWeapons {
    class Rifle_Base_F;
    class arifle_Mk20_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class OPTRE_BR45: arifle_Mk20_F {
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

    class CLASS(BR45B): OPTRE_BR45 {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(BR45B);

        displayName = "[505th] BR45B Battle Rifle";
        descriptionShort = "Hi-Power Rifle • 9.5x40 • 32-round mag • Medium range";
        picture = "\OPTRE_weapons\br\icons\br45_icon.paa";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";

        modes[] = { "Single", "FullAuto" };
        magazines[] = { QCLASS(32Rnd_95x40_Mag) };
        magazineWell[] = {QCLASS(Magwell_BR45B)};
        dispersion = 0.00029;
        maxZeroing = 600;
        discreteDistance[] = {100,200,300,400,500,600};
        discreteDistanceInitIndex = 1;
        maxRange=600;
        maxRangeToHit=580;

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 45;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "Optre_Evo_Sight_Riser",
                    "OPTRE_M12_Optic",
                    "Optre_Recon_Sight",
                    "Optre_Recon_Sight_Red"

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

        class Single: Single {
            displayName = "Semi";
            reloadTime = 0.0923077;
            dispersion = 0.00075;
            soundContinuous = 0;
            recoil = "recoil_single_trg";
            recoilProne = "recoil_single_prone_trg";
            minRange = 2;
            minRangeProbab = 0.03;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 600;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2.0;
            aiRateOfFireDispersion = 1;
            aiRateOfFireDistance = 500;
        };

        class FullAuto: FullAuto {
            displayName = "Full Auto";
            reloadTime = 0.0923077;
            dispersion = 0.00085;
            soundContinuous = 0;
            recoil = "recoil_auto_trg";
            recoilProne = "recoil_auto_prone_trg";
            minRange = 2;
            minRangeProbab = 0.03;
            midRange = 300;
            midRangeProbab = 0.7;
            maxRange = 600;
            maxRangeProbab = 0.05;
            aiRateOfFire = 2.0;
            aiRateOfFireDispersion = 1;
            aiRateOfFireDistance = 500;
        };
    };

        class CLASS(BR45BGL): CLASS(BR45B) {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(BR45BGL);

        displayName = "[505th] BR45B-GL Battle Rifle";
        descriptionShort = "Hi-Power Rifle • 9.5x40 • 32-round mag • 40mm GL";

        model = "\OPTRE_Weapons\BR\BR45GL";
        picture = "\OPTRE_weapons\br\icons\br45_icon.paa";
        handAnim[] = {"OFP2_ManSkeleton","\OPTRE_Weapons\br\data\anim\br45gl.rtm","Spartan_ManSkeleton","\OPTRE_Weapons\br\data\anim\br45gl_spartan.rtm"};

        muzzles[] = {"this", "GL_Muzzle"};

        class GL_Muzzle: UGL_F {
            displayName = "GL";
            magazines[] = {
                "1Rnd_HE_Grenade_shell",
                "UGL_FlareGreen_F",
                "UGL_FlareCIR_F",
                "UGL_FlareRed_F",
                "UGL_FlareWhite_F",
                "UGL_FlareYellow_F",
                "UGL_FlareGreen_Illumination_F",
                "UGL_FlareRed_Illumination_F",
                "UGL_FlareWhite_Illumination_F",
                "UGL_FlareYellow_Illumination_F",
                "1Rnd_SmokeBlue_Grenade_shell",
                "1Rnd_SmokeGreen_Grenade_shell",
                "1Rnd_SmokeOrange_Grenade_shell",
                "1Rnd_SmokePurple_Grenade_shell",
                "1Rnd_SmokeRed_Grenade_shell",
                "1Rnd_Smoke_Grenade_shell",
                "1Rnd_SmokeYellow_Grenade_shell"
            };
        };
    };
};
