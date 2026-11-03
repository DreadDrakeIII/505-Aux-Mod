class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;

class CfgWeapons {
    class TCP_SMG_M7;

    class CLASS(M7_Caseless): TCP_SMG_M7 {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(M7_Caseless);

        displayName = "[505th] M7 Caseless";
        descriptionShort = "The M7/Caseless Submachine Gun (M7/SMG) is a personal defense weapon developed and manufactured by Misriah Armory.";

        magazines[] = {QCLASS(60Rnd_5x23_Mag), "TCP_60Rnd_5x23_Mag"};
        magazineWell[] = { QCLASS(Magwell_M7_Caseless) };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 30;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "TCP_optic_M5BSLSV_Blue",
                    "TCP_optic_M5BSLSV",
                    "OPTRE_M7_Sight",
                    "TCP_optic_M11VERO_Blue",
                    "TCP_optic_M11VERO",
                    "TCP_optic_M81ERO_Blue",
                    "TCP_optic_M81ERO",
                    "TCP_optic_EVOSJ",
                    "TCP_optic_EVOSJ1",
                    "TCP_optic_EVOSD",
                    "TCP_optic_M27RCO",
                    "TCP_optic_M43RCO",
                    "TCP_optic_M43RCO_CRS",
                    "TCP_optic_M43RCO_CRS_CUP",
                    "TCP_optic_M43RCO_CUP"
                };
            };

            class PointerSlot: PointerSlot {
                class CompatibleItems {
                    ATTACHMENTS_POINTER_BASE
                    CLASS(ANPEQ6G) = TRUE;
                    CLASS(ANPEQ6G_VL) = TRUE;
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {
                    "TCP_muzzle_brake_762_01",
                    "TCP_muzzle_snds_523_01"
                };
            };
        };
    };
};
