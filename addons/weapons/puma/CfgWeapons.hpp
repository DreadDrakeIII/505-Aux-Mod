class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;

class CfgWeapons {
    class WBK_SciFi_Pistol_Black;

    class CLASS(PUMA): WBK_SciFi_Pistol_Black {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(PUMA);

        displayName = "[505th] Puma";
        descriptionShort = "Light rapid firing pistol";

        modes[] = {"Single", "FullAuto"};
        magazines[] = {QCLASS(16Rnd_45ACP_Mag)};
        magazineWell[] = {QCLASS(Magwell_PUMA)};

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 24;
            holsterOffset = "holster";
            holsterScale = 0.95;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {};
            };

            class PointerSlot: PointerSlot {
                compatibleItems[] = {
                    "acc_flashlight_pistol"
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "muzzle_snds_acp"
                };
            };
        };
    };
};
