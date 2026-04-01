class Single;
class FullAuto;
class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;

class CfgWeapons {
    class WRS_Weapon_AUG_BLACK;

    class CLASS(WRS14BULLDOG): WRS_Weapon_AUG_BLACK {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(WRS14BULLDOG);

        displayName = "[505th] WRS-14 Bulldog";
        descriptionShort = "The WRS-14 Bulldog is a compact assault rifle developed by Blackreach Armory Industries.";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";

        modes[] = { "Single", "FullAuto" };
        magazines[] = { QCLASS(40rnd_65x39_LDUR) };
        magazineWell[] = {QCLASS(Magwell_Wrs14Bulldog)};

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 81;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "Optre_Evo_Sight_Riser",
                    "OPTRE_M12_Optic",
                    "Optre_Recon_Sight",
                    "Optre_Recon_Sight_Red",
                    "TCP_optic_M11VERO_Blue",
                    "TCP_optic_M11VERO",
                    "TCP_optic_M81ERO_Blue",
                    "TCP_optic_EVOSJ",
                    "TCP_optic_EVOSJ1",
                    "TCP_optic_M27RCO",
                    "TCP_optic_M43RCO",
                    "TCP_optic_M43RCO_CRS",
                    "TCP_optic_M43RCO_CRS_CUP",
                    "TCP_optic_M43RCO_CUP",
                    "TCP_optic_EVOSD",
                    "TCP_optic_M5BSLSV_Blue",
                    "TCP_optic_M5BSLSV",
                    "TCP_optic_M81ERO_Blue",
                    "TCP_optic_M81ERO"

                };
            };

            class PointerSlot: PointerSlot {
                class CompatibleItems {
                    ATTACHMENTS_POINTER_BASE
                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {};
            };
        };

        class Single: Single {
            displayName = "Semi";
        };

        class FullAuto: FullAuto {
            displayName = "Full Auto";
        };
    };
};
