class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {
    class Rifle_Base_F;
    class arifle_Mk20_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class OPTRE_MA37K: arifle_Mk20_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
            class UnderBarrelSlot;
        };

        class Single: Mode_SemiAuto {};
        class FullAuto: Mode_FullAuto {};
    };

    class CLASS(MA37K): OPTRE_MA37K {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(MA37K);

        displayName = "[505th] MA37K Assault Rifle";
        descriptionShort = "General Purpose Assault Rifle • 7.62×51mm • 32Rnd Magazine";
        model = "\OPTRE_Weapons\MA37K\MA37K.p3d";
        picture = "\OPTRE_Weapons\MA37K\icons\ma37k_icon.paa";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";

        modes[] = { "Single", "FullAuto" };
        magazines[] = { QCLASS(32Rnd_762x51_Mag) };
        magazineWell[] = { QCLASS(Magwell_MA37K) };

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
        };

        class FullAuto: FullAuto {
            displayName = "Full Auto";
            reloadTime = 0.0923077;
        };
    };
};
