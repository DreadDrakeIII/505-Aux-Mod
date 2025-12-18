class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;

class CfgWeapons {
    class TKE_MDPistolBlack;

    class CLASS(MHG16): TKE_MDPistolBlack {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(MHG16);

        displayName = "[505th] MHG-16";
        descriptionShort = "MHG-16 Pistol";

        modes[] = {"Single"};
        magazines[] = {QCLASS(12Rnd_9x21_Mag)};
        magazineWell[]={QCLASS(Magwell_MHG16)};


        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 21;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                };
            };

            class PointerSlot: PointerSlot {
                class CompatibleItems {};
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                };
            };
        };
    };
};
