class Mode_SemiAuto;

class CfgWeapons {

    class Pistol_Base_F;
    class apistol_19_UNSC_M6C_Base_F: Pistol_Base_F {
        class WeaponSlotsInfo;
    };

    class 19_UNSC_M6C: apistol_19_UNSC_M6C_Base_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
        };

        class Single: Mode_SemiAuto {
                    };
    };

    class CLASS(M6C): 19_UNSC_M6C {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M6C);

        displayName = "[505th] M6C";
        descriptionShort = "12.7x40mm";

        model = "Foundries\UNSC_F_Weapons\weapons\UNSC_M6C.p3d";
        picture = "Foundries\UNSC_F_Weapons\weapons\UI\M6c_UI.paa";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";

        modes[] = {"Single"};
        magazines[] = {QCLASS(12Rnd_127x40_Mag)};
        magazineWell[] = { QCLASS(Magwell_M6C) };


        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 20;
            holsterOffset = "holster";
            holsterScale = 0.95;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                };
            };

            class PointerSlot: PointerSlot {
                class CompatibleItems {};
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {};
            };
        };

        class Single: Single {
            displayName = "Single";
        };
    };

};
