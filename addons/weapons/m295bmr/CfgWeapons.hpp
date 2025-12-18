class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {
    class Rifle_Base_F;
    class srifle_EBR_F: Rifle_Base_F {
        class WeaponSlotsInfo;
    };

    class OPTRE_M295_BMR: srifle_EBR_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
        };
        class Single: Mode_SemiAuto {};
        class FullAuto: Mode_FullAuto {};
    };

    class CLASS(M295_BMR): OPTRE_M295_BMR {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M295_BMR);

        displayName = "[505th] M295 BMR";
        descriptionShort = "Hi-Power Rifle • 7.62×V7 • 25-round magazine";
        picture = "\OPTRE_Weapons\DMR\icons\M392_CA.paa";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";

        magazines[] = { QCLASS(25Rnd_762xV7_Mag) };
        magazineWell[] = { QCLASS(Magwell_M295BMR) };
        modes[] = { "Single", "FullAuto" };

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
        };

        class FullAuto: FullAuto {
            displayName = "Full-Auto";
            reloadTime = 0.09;
        };
    };
};
