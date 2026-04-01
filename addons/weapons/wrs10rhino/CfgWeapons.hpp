class Single;
class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;

class CfgWeapons {
    class WRS_Weapon_ShockGun_Black;

    class CLASS(WRS10RHINO): WRS_Weapon_ShockGun_Black {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(WRS10RHINO);

        displayName = "[505th] WRS-10 RHINO";
        descriptionShort = "The WRS-10 RHINO is a energy weapon developed by Blackreach Armory Industries.";
        picture = "\WBK_SciFi_Weaponary\icons\rhino.paa";
        cartridgePos = "nabojnicestart";
        cartridgeVel = "nabojniceend";

        modes[] = { "Single" };
        magazines[] = { QCLASS(coolant_cartridge) };
        magazineWell[] = {QCLASS(Magwell_WRS10RHINO)};

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 310;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
                    "Optre_Recon_Sight",
                    "Optre_Recon_Sight_Green",
                    "Optre_Recon_Sight_Red",
                    "Optre_Evo_Sight_Riser",
                    "OPTRE_M12_Optic",
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
                class CompatibleItems {};
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {};
            };
        };

        class Single: Single {
            displayName = "Semi";
        };
    };
};
