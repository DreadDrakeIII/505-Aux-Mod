class Single;
class WeaponSlotsInfo;
class CowsSlot;
class PointerSlot;
class MuzzleSlot;

class CfgWeapons {
    class WRS_Weapon_Sniper_Black;

    class CLASS(WRS28_Pilum): WRS_Weapon_Sniper_Black {
        SCOPE_PUBLIC;
        author = AUTHOR;
        baseWeapon = QCLASS(WRS28_Pilum);

        displayName = "[505th] WRS-28 PILUM";
        descriptionShort = "The WRS-28 PILUM is a energy weapon developed by Blackreach Armory Industries.";

        modes[] = {"Single"};
        magazines[] = {QCLASS(UC_CELL),QCLASS(CC_CELL)};
        magazineWell[] = { QCLASS(Magwell_WRS28) };

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 310;

            class CowsSlot: CowsSlot {
                compatibleItems[] = {
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
                compatibleItems[] = {

                };
            };

            class MuzzleSlot: MuzzleSlot {
                compatibleItems[] = {

                };
            };
        };

        class Single: Single
		{
			displayName="Semi";
		};
    };
};
