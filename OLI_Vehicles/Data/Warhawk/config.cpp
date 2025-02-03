class CfgPatches
{
	class OLI_Aircraft_Warhawk
	{
		author="Cold Winter Productions";
		addonRootClass="OLI_Vehicle_Core";
		requiredAddons[]=
		{
			"OLI_Vehicle_Core",
			"OLI_Core"
		};
		requiredVersion=0.1;
		units[]=
		{
		"OLI_Warhawk"
		};
		weapons[]={};
		skipWhenMissingDependencies = 1;
	};
};
class CfgVehicles
{
	class B_Plane_Fighter_01_F;
	
/////////////////////////////////////////////////////////
	
	class OLI_Warhawk: B_Plane_Fighter_01_F
	{
        displayName = "F/A-40 Warhawk";
        faction = "OLI_Fac";
        editorsubcategory = "OLI_Aircraft_FXW";
        //crew = "TCI_unit";
		weapons[]=
		{

		};
		
		magazines[]=
		{

		};
		//armor=150;
       hiddenSelectionsTextures[]=
		{
			"OLI_Vehicles\Data\Warhawk\data\fighter_01_fuselage_01_co_2.paa",
			"OLI_Vehicles\Data\Warhawk\data\fighter_01_fuselage_02_co_2.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_glass_01_ca.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_01_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_02_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_03_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_05_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_01_ca.paa",
			"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_00_ca.paa",
			"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_01_ca.paa"
		};
   };
};
