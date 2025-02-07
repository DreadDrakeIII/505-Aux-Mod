#define MAG_XX(a,b) class xx##a {magazine = a; count = b;}
#define WEAP_XX(a,b) class xx##a {weapon = a; count = b;}
#define ITEM_XX(a,b) class xx##a {name = a; count = b;}
class CfgPatches
{
	class OLI_resupply
	{
		author="Cold Winter Productions";
		requiredAddons[]=
		{

		};
		requiredVersion=0.1;
		units[]=
		{
			"OLI_resupplyBox_LAW",
		};
		weapons[]={};
		skipWhenMissingDependencies = 1;
	};
};

class CfgVehicles
{
	class OPTRE_Ammo_SupplyPod_Empty;

	
	class OLI_resupplyBox_LAW: OPTRE_Ammo_SupplyPod_Empty
	{
		scope=2;
		scopeCurator=2;
		editorCategory = "OLI_Objects";
		editorSubCategory = "OLI_resupply_subcat";
		displayname="505th Resupply Box (LAW)";
		maximumLoad=10000;
		ace_dragging_canDrag = 1;
		ace_dragging_ignoreWeight=1;
        ace_dragging_ignoreWeightCarry=1;
		ace_cargo_size = 1; 
        ace_cargo_canLoad = 1;

		class TransportWeapons
		{
			class _xx_DMNS_M96_LAW
			{
				weapon ="DMNS_M96_LAW";
				count=5;
			};
		};
	};
	
	//class TCI_LAAT_BOX: ls_stimbox
	//{
	//	scope=2;
	//	scopeCurator=2;
	//	author="Cold Winter Productions";
	//	displayName="Repair Box";
	//	editorCategory = "TCI_Objects";
	//	editorSubCategory = "TCI_resupply_subcat";
	//	hiddenselections[]=
	//	{
	//		"body1",
	//		"body2",
	//		"screen"
	//	};
	//	hiddenselectionstextures[]=
	//	{
	//		"LS_statics_props\stimbox\data\body1_co.paa",
	//		"LS_statics_props\stimbox\data\body2_co.paa",
	//		"LS_statics_props\stimbox\data\screen_co.paa"
	//	};
	//	ace_refuel_fuelCargo=250;
		//ace_rearm_defaultSupply=999999999999;
		//ace_cargo_space=350;
		//ace_cargo_hasCargo=1;
	//	ace_repair_canRepair=1;
	//	ace_refuel_hooks[]=
	//	{
	//		{0.0,0.0,0.0},
	//		{0.0,0.0,0.0},
	//	};
	//	ace_dragging_canDrag = 1;
	//	ace_cargo_size = 1; 
    //    ace_cargo_canLoad = 1;
	//};
};
//		class TransportItems