class Mode_SemiAuto;

class CfgWeapons {
    class Rifle_Base_F;
    class OPTRE_LongRifle_Base: Rifle_Base_F {
        class WeaponSlotsInfo;
    };
    class WRS_Weapon_Sniper_Bolt: OPTRE_LongRifle_Base {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot;
            class PointerSlot;
            class MuzzleSlot;
            class UnderBarrelSlot;
        };

        class Single: Mode_SemiAuto {};
    };

    // ================================
    // VTR-93 Vindicta - Sniper Rifle
    // ================================
    class CLASS(FG93_Vindicta): WRS_Weapon_Sniper_Bolt {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(VTR93_VINDICTA);

        // User-facing
        displayName = "[505th] VTR-93 Vindicta";
        descriptionShort = "7.62x51mm • 10Rnd HDUR • Sniper rifle";
        picture = "\WBK_SciFi_Weaponary\icons\boomslang.paa";
        model = "\WBK_SciFi_Weaponary\models\WBK_SciFi_Sniper_bolt.p3d";

        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\WBK_SciFi_Weaponary\textures\boomslang\WRS_Boomslang_Grey_CO.paa"};

        // Behaviour / performance
        modes[] = { "Single" };

        // Magazine: 10Rnd HDUR
        magazines[] = { QCLASS(10Rnd_HDUR) };
        magazineWell[] = {QCLASS(Magwell_VTR93Vindicta)};

        linkedItems[] = { QCLASS(VTR_Scope) };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 50; // Lighter short rifle

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    QCLASS(VTR_Scope)
                };
            };

            class PointerSlot: PointerSlot {
                compatibleItems[] = {};
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {};
            };

            class UnderBarrelSlot: UnderBarrelSlot {
                compatibleItems[] = {};
            };
        };

        //
        // Semi (single shot) - accurate, used for long-range engagements
        //
        class Single: Single {
            displayName = "Single";
        };
    };
};
