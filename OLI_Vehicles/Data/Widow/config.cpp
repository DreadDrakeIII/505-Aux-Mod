class CfgPatches
{
	class OLI_Aircraft_Widow
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
		"OLI_Widow"
		};
		weapons[]={};
		skipWhenMissingDependencies = 1;
	};
};
class CfgVehicles
{
	class B_T_VTOL_01_armed_F;
	
/////////////////////////////////////////////////////////
	
	class OLI_Widow: B_T_VTOL_01_armed_F
	{
        displayName = "V/AC-220 Widow";
        faction = "OLI_Fac";
        editorsubcategory = "OLI_Aircraft_RTW";
        //crew = "TCI_unit";
		//armor=150;
       hiddenSelectionsTextures[]=
		{
			"OLI_Vehicles\Data\widow\data\vtol_01_ext01_505_co.paa",
			"OLI_Vehicles\Data\widow\data\vtol_01_ext02_505_co.paa",
			"OLI_Vehicles\Data\widow\data\vtol_01_ext03_505_co.paa",
			"OLI_Vehicles\Data\widow\data\vtol_01_ext04_505_co.paa",
			"OLI_Vehicles\Data\widow\data\VTOL_01_signs_CA.paa"
		};
		weapons[]=
		{
			"CMFlareLauncher_Singles"
		};
		magazines[]=
		{
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine"
		};
   };
};
