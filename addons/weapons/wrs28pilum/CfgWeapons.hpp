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
                    "OPTRE_M12_Optic"
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
