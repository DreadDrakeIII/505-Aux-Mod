class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class CfgWeapons {

    class Rifle_Base_F;
    class Rifle_Short_Base_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };

    class OPTRE_M7: Rifle_Short_Base_F {
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

    class CLASS(M7_Caseless): OPTRE_M7 {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M7_Caseless);

        displayName = "[505th] M7 Caseless";
        descriptionShort = "The M7/Caseless Submachine Gun (M7/SMG) is a personal defense weapon developed and manufactured by Misriah Armory.";

        model = "\OPTRE_Weapons\SMG\SMG.p3d";
        picture = "\OPTRE_weapons\smg\icons\smg.paa";

        modes[] = {"Single","Burst","FullAuto"};
        magazines[] = {QCLASS(60Rnd_9x21_Mag)};
        magazineWell[] = { QCLASS(Magwell_M7_Caseless) };


        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 30;

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
                compatibleItems[] = {
                    "OPTRE_Ma5Suppressor",
                    "OPTRE_M247a1_Flashhider"
                };
            };
        };

        class Single: Single {
            displayName = "Single";
        };
        class FullAuto: FullAuto {
            displayName = "Full Auto";
        };
        class Burst: Burst {
            displayName = "3-Round Burst";
        };
    };

};
