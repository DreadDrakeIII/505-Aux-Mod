class CfgPatches
{
	class W505_Core
	{
		author= "Cold Winter Productions";
		requiredaddons[]=
		{
		};
		requiredversion=0.1;
		units[]={};
		weapons[]=
		{

		
		};
	};
};

class CfgFactionClasses
{
	class TCI_Fac
	{
		displayName="Clone Insurrectionists";
		side=1;
	};
	class TCI_Fac_opfor
	{
		displayName="(TCI) Imperial Units";
		side=0;
	};
};
class CfgEditorCategories
{
	class TCI_Objects
	{
		scope=2;
		scopeCurator=2;
		displayName="TCI Assets";
	};
		class TCI_Imp_trooper
	{
		displayname="(TCI) Galactic Empire";
		side=0;
		scopecurator=2;
		scope=2;
	};
};
class CfgEditorSubcategories
{
	class TCI_INF
	{
		scope=2;
		scopeCurator=2;
		displayName="Troopers";
	};
	class TCI_Landcraft
	{
		scope=2;
		scopeCurator=2;
		displayName="Landcraft";
	};
	class TCI_Aircraft_RTW
	{
		scope=2;
		scopeCurator=2;
		displayName="Aircraft (Rotary Wing)";
	};
	class TCI_Aircraft_FXW
	{
		scope=2;
		scopeCurator=2;
		displayName="Aircraft (Fixed Wing)";
	};
	class TCI_Helmets_Props_subcat
	{
		scope=2;
		scopeCurator=2;
		displayname="Helmet Props (Rank)";
	};
	class TCI_Helmets_Props_cus_subcat
	{
		scope=2;
		scopeCurator=2;
		displayname="Helmet Props (Custom)";
	};
	class TCI_Flags_subcat
	{
		scope=2;
		scopeCurator=2;
		displayname="Flags";
	};
	class TCI_Ships_subcat
	{
		scope=2;
		scopeCurator=2;
		displayname="Ships";
	};
	class TCI_Ship_Parts_subcat
	{
		scope=2;
		scopeCurator=2;
		displayname="Ship Parts";
	};
	class TCI_resupply_subcat
	{
		scope=2;
		scopeCurator=2;
		displayname="Resupply Crates";
	};
	class TCI_gonk_subcat
	{
		scope=2;
		scopeCurator=2;
		displayname="Gonks";
	};
		class TCI_Imp_trooper_subcat
	{
		scope=2;
		scopeCurator=2;
		displayname="(TCI) Stormtroopers";
	};
	class TCI_Imp_scout_trooper_subcat
	{
		scope=2;
		scopeCurator=2;
		displayname="Scout Troopers";
	};
	class TCI_Imp_snow_trooper_subcat
	{
		scope=2;
		scopeCurator=2;
		displayname="Snowtroopers";
	};
	class TCI_IMP_GND_VEHIC
	{
		scope=2;
		scopeCurator=2;
		displayname="Ground Vehicles";
	};
};
class CfgMarkerClasses
{
	class TCI_MapMarker_Classes
	{
		scope=2;
		scopeCurator=2;
		Priority=1
		displayName="TCI Markers";
	};
};