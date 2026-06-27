class CLASS(CE_Armour_Vest): CLASS(CE_Marine_Vest_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Marine Armor";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa","\Rogue_CEMarine\data\Rogue_CEArmour_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Vest_V2): CLASS(CE_Marine_VestV2_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Marine Armor (No Forearms)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa","\Rogue_CEMarine\data\Rogue_CEArmour_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Vest_NSV2): CLASS(CE_Marine_Vest_NSV2_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Marine Armor (No Forearms + Shoulders)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa","\Rogue_CEMarine\data\Rogue_CEArmour_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Vest_NS): CLASS(CE_Marine_Vest_NS_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Marine Armor (No Shoulders)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa","\Rogue_CEMarine\data\Rogue_CEArmour_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Vest_Pouch): CLASS(CE_Marine_Vest_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Marine Armor (Pouches)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa","\Rogue_CEMarine\data\Rogue_CEArmour_co.paa","\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Vest_V2Pouch): CLASS(CE_Marine_Vest_V2_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Marine Armor (Pouches + No Forearms)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa","\Rogue_CEMarine\data\Rogue_CEArmour_co.paa","\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Vest_NSV2Pouch): CLASS(CE_Marine_Vest_NSV2_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Marine Armor (Pouches + No Forearms/Shoulders)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa","\Rogue_CEMarine\data\Rogue_CEArmour_co.paa","\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Vest_NSPouch): CLASS(CE_Marine_Vest_NS_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Marine Armor (Pouches + No Shoulders)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa","\Rogue_CEMarine\data\Rogue_CEArmour_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
/////////////////////////////Corpsman Vests/////////////////////////////
class CLASS(CE_Armour_Corpsman_Vest): CLASS(CE_Marine_Vest_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Corpsman Armor";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Medic_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Corpsman_Vest_V2): CLASS(CE_Marine_VestV2_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Corpsman Armor (No Forearms)";
	hiddenSelections[] =  {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Medic_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Corpsman_Vest_NSV2): CLASS(CE_Marine_Vest_NSV2_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Corpsman Armor (No Forearms + Shoulders)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Medic_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Corpsman_Vest_NS): CLASS(CE_Marine_Vest_NS_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Corpsman Armor (No Shoulders)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Medic_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Corpsman_Vest_Pouch): CLASS(CE_Marine_Vest_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Corpsman Armor (Pouches)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Medic_Armour_co.paa),"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Corpsman_Vest_V2Pouch): CLASS(CE_Marine_Vest_V2_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Corpsman Armor (Pouches + No Forearms)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Medic_Armour_co.paa),"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Corpsman_Vest_NSV2Pouch): CLASS(CE_Marine_Vest_NSV2_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Corpsman Armor (Pouches + No Forearms/Shoulders)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Medic_Armour_co.paa),"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_Corpsman_Vest_NSPouch): CLASS(CE_Marine_Vest_NS_Pouch_Base)
{
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Corpsman Armor (Pouches + No Shoulders)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Medic_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
////////////////////////////////SL Vests////////////////////////////////
class CLASS(CE_Armour_SL_Vest): CLASS(CE_Marine_Vest_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Squad Lead Armor";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\SL_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_SL_Vest_V2): CLASS(CE_Marine_VestV2_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Squad Lead Armor (No Forearms)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\SL_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_SL_Vest_NSV2): CLASS(CE_Marine_Vest_NSV2_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Squad Lead Armor (No Forearms + Shoulders)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\SL_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_SL_Vest_NS): CLASS(CE_Marine_Vest_NS_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Squad Lead Armor (No Shoulders)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\SL_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_SL_Vest_Pouch): CLASS(CE_Marine_Vest_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Squad Lead Armor (Pouches)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\SL_Armour_co.paa),"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_SL_Vest_V2Pouch): CLASS(CE_Marine_Vest_V2_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Squad Lead Armor (Pouches + No Forearms)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\SL_Armour_co.paa),"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_SL_Vest_NSV2Pouch): CLASS(CE_Marine_Vest_NSV2_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Squad Lead Armor (Pouches + No Forearms/Shoulders)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\SL_Armour_co.paa),"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_SL_Vest_NSPouch): CLASS(CE_Marine_Vest_NSV2_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Squad Lead Armor (Pouches + No Shoulders)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\SL_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
////////////////////////////////PL Vests////////////////////////////////
class CLASS(CE_Armour_PL_Vest): CLASS(CE_Marine_Vest_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Platoon Lead Armor";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\PL_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_PL_Vest_V2): CLASS(CE_Marine_VestV2_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Platoon Lead Armor (No Forearms)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\PL_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_PL_Vest_NSV2): CLASS(CE_Marine_Vest_NSV2_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Platoon Lead Armor (No Forearms + Shoulders)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\PL_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_PL_Vest_NS): CLASS(CE_Marine_Vest_NS_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Platoon Lead Armor (No Shoulders)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\PL_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_PL_Vest_Pouch): CLASS(CE_Marine_Vest_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Platoon Lead Armor (Pouches)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\PL_Armour_co.paa),"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_PL_Vest_V2Pouch): CLASS(CE_Marine_Vest_V2_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Platoon Lead Armor (Pouches + No Forearms)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\PL_Armour_co.paa),"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_PL_Vest_NSV2Pouch): CLASS(CE_Marine_Vest_NSV2_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Platoon Lead Armor (Pouches + No Forearms/Shoulders)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\PL_Armour_co.paa),"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_PL_Vest_NSPouch): CLASS(CE_Marine_Vest_NS_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Platoon Lead Armor (Pouches + No Shoulders)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\PL_Armour_co.paa),"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
////////////////////////////////FR Vests////////////////////////////////
class CLASS(CE_Armour_ForceRecon_Vest): CLASS(CE_Marine_Vest_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Force Recon Armor Armor";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Force_Recon_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_ForceRecon_Vest_V2): CLASS(CE_Marine_VestV2_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Force Recon Armor Armor (No Forearms)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Force_Recon_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_ForceRecon_Vest_NSV2): CLASS(CE_Marine_Vest_NSV2_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Force Recon Armor (No Forearms + Shoulders)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Force_Recon_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_ForceRecon_Vest_NS): CLASS(CE_Marine_Vest_NS_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Force Recon Armor Armor (No Shoulders)";
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Force_Recon_Armour_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_ForceRecon_Vest_Pouch): CLASS(CE_Marine_Vest_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Force Recon Armor Armor (Pouches)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Force_Recon_Armour_co.paa),QPATHTOF(data\backpacks\FR_Pouches_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_ForceRecon_Vest_V2Pouch): CLASS(CE_Marine_Vest_V2_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Force Recon Armor Armor (Pouches + No Forearms)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Force_Recon_Armour_co.paa),QPATHTOF(data\backpacks\FR_Pouches_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_ForceRecon_Vest_NSV2Pouch): CLASS(CE_Marine_Vest_NSV2_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Force Recon Armor Armor (Pouches + No Forearms/Shoulders)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Force_Recon_Armour_co.paa),QPATHTOF(data\backpacks\FR_Pouches_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Armour_ForceRecon_Vest_NSPouch): CLASS(CE_Marine_Vest_NS_Pouch_Base) {
	author = "505th Aux Team";
	SCOPE_HIDDEN;
	displayName = "[505th] Force Recon Armor Armor (Pouches + No Shoulders)";
	hiddenSelections[] = {"camo","camo1","camo2"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\standard\Force_Recon_Armour_co.paa),QPATHTOF(data\backpacks\FR_Pouches_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
/////////////////////////////Scout Vests////////////////////////////////
class CLASS(CE_Armour_Scout_Vest): CLASS(CE_Scout_Vest_Base) {
    author = "505th Aux Team";
    SCOPE_HIDDEN;
    displayName = "[505th] Scout Armor";
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPaddingScout_co.paa","\Rogue_CEMarine\data\Rogue_CEArmour_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
//////////////////////////////Custom Vests//////////////////////////////
class CLASS(CE_Vest_Adamant_Pouches): CLASS(CE_Marine_Vest_Pouch_Base) {
    displayName = "[505th] Custom Armor (Adamant)";
    SCOPE_HIDDEN;
    hiddenSelections[] = {"camo","camo1","camo2"};
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\custom\Dexus_Armor_co.paa),"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Vest_Crawford): CLASS(CE_Marine_Vest_Base) {
    displayName = "[505th] Custom Armor (Crawford)";
    SCOPE_HIDDEN;
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\custom\Anvil_Armor_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Vest_Hoffman): CLASS(CE_Marine_Vest_Pouch_Base) {
    displayName = "[505th] Custom Armor (Hoffman)";
    SCOPE_HIDDEN;
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\custom\Hoffman_Armor_co.paa),"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Vest_Oliver): CLASS(CE_Marine_Vest_Base) {
    displayName = "[505th] Custom Armor (Oliver)";
    SCOPE_HIDDEN;
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\custom\Drake_Armor_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};

class CLASS(CE_Vest_Kain): CLASS(CE_Marine_Vest_Base) {
    displayName = "[505th] Custom Armor (Kain)";
    SCOPE_HIDDEN;
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\custom\Kain_Armor_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};

class CLASS(CE_Vest_FR_Davy): CLASS(CE_Marine_Vest_NSV2_Base) {
    displayName = "[505th] Custom Armor (Rend)";
	SCOPE_HIDDEN;
	hiddenSelections[] = {"camo","camo1"};
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\custom\Davy_FR_Armor_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};

class CLASS(CE_Vest_Doc): CLASS(CE_Marine_Vest_Base) {
    displayName = "[505th] Custom Armor (Doc)";
    SCOPE_HIDDEN;
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\custom\Doc_Armor_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};

class CLASS(CE_Vest_Saint): CLASS(CE_Armour_Corpsman_Vest) {
    displayName = "[505th] Custom Armor (Saint)";
    SCOPE_HIDDEN;
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\custom\Saint_Armor_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply250";
            vestType = "Rebreather";
        };
};
class CLASS(CE_Vest_Milan): CLASS(CE_Marine_Vest_NS_Base) {
    displayName = "[505th] Custom Armor (Milan)";
    SCOPE_HIDDEN;
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",QPATHTOF(data\vests\ce\custom\Milan_Armor_co.paa)};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};

///////////////////////////////Pilot Vest///////////////////////////////
class CLASS(Pilot_Vest): CLASS(Pilot_Vest_Base) {
    displayName = "[505th] Pilot Vest";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};
/////////////////////////////Black Ops Vest/////////////////////////////
class CLASS(BlackOps_Vest): CLASS(BlackOps_Vest_Base) {
    displayName = "[505th] Black Ops Vest";
    scope = 0;
    scopeCurator = 0;
    scopeArsenal = 0;
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};

// =========================================================================
// ============================ M43 Vests ==================================
// =========================================================================
class HitpointsProtectionInfo;
class CLASS(M43_Heavy_Olive_1): CLASS(M43_Heavy_Olive_1_Base) {
    displayName = "[505th] M43 Heavy (Olive 1)";
    SCOPE_PUBLIC;
    hiddenSelections[] = {"camo","camo1","camo2","camo3","decals"};
    hiddenSelectionsTextures[] = {
    QPATHTOF(data\vests\tcp\standard\m43a_vest_olive_01_co.paa),
    QPATHTOF(data\vests\tcp\standard\m43a_shoulders_gungnir_olive_co.paa),
    QPATHTOF(data\vests\tcp\standard\m43a_vest_olive_02_co.paa),
    QPATHTOF(data\vests\tcp\standard\m43a_vest_olive_03_co.paa),
    "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\data\camo\black\vest_M43_DecalSheet_CA.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        class HitpointsProtectionInfo: HitpointsProtectionInfo
        {
            class Neck
			{
				hitpointName	= "HitNeck";	// reference to the hit point class defined in the man base class
				armor			= 25;			// addition to armor of referenced hitpoint
				passThrough		= 0.2;			// multiplier of base passThrough defined in referenced hitpoint
			};
            class Chest
            {
                hitpointName = "HitChest";        // Reference to the hitpoint class defined in the man base class
                armor = 25;                     // Addition to armor of referenced hitpoint
                passThrough = 0.2;                 // Multiplier of base passThrough defined in referenced hitpoint
            };
            class Diaphragm
            {
                hitpointName = "HitDiaphragm";
                armor = 25;
                passThrough = 0.2;
            };
            class Abdomen
            {
                hitpointName = "HitAbdomen";
                armor = 25;
                passThrough = 0.2;
            };
            class Body
            {
                hitpointName = "HitBody";
                passThrough = 0.2;
            };
            class Arms //Shoulders added
            {
                hitpointName = "HitArms";
                armor = 25;
                passThrough = 0.2;
            };
            class Legs //Thighplates added
            {
                hitpointName = "HitLegs";
                armor = 25;
                passThrough = 0.2;
            };
        };
    };
};

class CLASS(M43_Medic_Olive_1): CLASS(M43_Heavy_Olive_1_Base) {
    displayName = "[505th] M43 Medic (Olive 1)";
    SCOPE_PUBLIC;
    hiddenSelections[] = {"camo","camo1","camo2","camo3","decals"};
    hiddenSelectionsTextures[] = {
    QPATHTOF(data\vests\tcp\standard\m43a_vest_olive_01_co.paa),
    QPATHTOF(data\vests\tcp\standard\m43a_medic_shoulders_gungnir_olive_co.paa),
    QPATHTOF(data\vests\tcp\standard\m43a_vest_olive_02_co.paa),
    QPATHTOF(data\vests\tcp\standard\m43a_vest_olive_03_co.paa),
    "\TCP\Characters\BLUFOR\UNSC\Army\Vests\M43A\data\camo\black\vest_M43_DecalSheet_CA.paa"};
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        class HitpointsProtectionInfo: HitpointsProtectionInfo
        {
            class Neck
			{
				hitpointName	= "HitNeck";	// reference to the hit point class defined in the man base class
				armor			= 25;			// addition to armor of referenced hitpoint
				passThrough		= 0.2;			// multiplier of base passThrough defined in referenced hitpoint
			};
            class Chest
            {
                hitpointName = "HitChest";        // Reference to the hitpoint class defined in the man base class
                armor = 25;                     // Addition to armor of referenced hitpoint
                passThrough = 0.2;                 // Multiplier of base passThrough defined in referenced hitpoint
            };
            class Diaphragm
            {
                hitpointName = "HitDiaphragm";
                armor = 25;
                passThrough = 0.2;
            };
            class Abdomen
            {
                hitpointName = "HitAbdomen";
                armor = 25;
                passThrough = 0.2;
            };
            class Body
            {
                hitpointName = "HitBody";
                passThrough = 0.2;
            };
            class Arms //Shoulders added
            {
                hitpointName = "HitArms";
                armor = 25;
                passThrough = 0.2;
            };
            class Legs //Thighplates added
            {
                hitpointName = "HitLegs";
                armor = 25;
                passThrough = 0.2;
            };
        };
    };
};

class CLASS(M43_Medium_Olive_1): CLASS(M43_Medium_Olive_1_Base) {
    displayName = "[505th] M43 Medium (Olive 1)";
    SCOPE_PUBLIC;
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};

class CLASS(M43_Kevlar_Black_1): CLASS(M43_Kevlar_Black_1_Base) {
    displayName = "[505th] M43 Kevlar (Black 1)";
    SCOPE_PUBLIC;
    class ItemInfo: ItemInfo {
            containerClass = "Supply100";
            vestType = "Rebreather";
        };
};