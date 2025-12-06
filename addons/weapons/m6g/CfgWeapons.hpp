class Mode_SemiAuto;

class CfgWeapons {

    class Pistol_Base_F;
    class hgun_Pistol_heavy_01_F: Pistol_Base_F {
        class WeaponSlotsInfo;
    };

    class OPTRE_M6G: hgun_Pistol_heavy_01_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
        };

        class Single: Mode_SemiAuto {
                    };
    };

    class CLASS(M6G): OPTRE_M6G {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M6G);

        displayName = "[505th] M6G Magnum";
        descriptionShort = "12.7x40mm Magnum Pistol";
        picture = "\OPTRE_Weapons_Pistols\M6G\data\icons\m6g_icon.paa";
        pictureMjolnirHud = "\OPTRE_Suit_Scripts\textures\weaponIcons\Pistols\M6B_icon.paa";
        model = "\OPTRE_Weapons_Pistols\M6G\m6g.p3d";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";
        Eye = "OPTRE_EYE_HUD_AmmoCount_PistolSmart";
        Glasses = "OPTRE_GLASS_HUD_AmmoCount_PistolSmart";


        modes[] = {"Single", "FullAuto"};
        magazines[] = {QCLASS(8Rnd_127x40_Mag)};
        magazineWell[] = { QCLASS(Magwell_M6G) };


        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 20;
            holsterOffset = "holster";
            holsterScale = 0.95;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                };
            };

            class PointerSlot: PointerSlot {
                class CompatibleItems {
                    ATTACHMENTS_POINTER_BASE
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "OPTRE_Ma5Suppressor"
                };
            };
        };

        class Single: Single {
            displayName = "Single";
        };
    };

};
