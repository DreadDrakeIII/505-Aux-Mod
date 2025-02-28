class CfgPatches
{
	class OLI_Aircraft_Harpoon
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
		"OLI_Harpoon"
		};
		weapons[]={};
		skipWhenMissingDependencies = 1;
	};
};
class CfgVehicles
{
	class B_Heli_Transport_03_F;
	
/////////////////////////////////////////////////////////
	
	class OLI_Harpoon: B_Heli_Transport_03_F
	{
        displayName = "CH-447 Harpoon";
        faction = "OLI_Fac";
        editorsubcategory = "OLI_Aircraft_RTW";
        crew = "OLI_HeliPilot";
		scope = 2
		armor=100; //Default 40
       hiddenSelectionsTextures[]=
		{
			"OLI_Vehicles\Data\harpoon\data\heli_transport_03_ext01_co.paa",
			"OLI_Vehicles\Data\harpoon\data\heli_transport_03_ext02_co.paa"
		};
		weapons[]=
		{
			"CMFlareLauncher_Singles",
			//"SmokeLauncher",
			"OLI_Flare_Countermeasure"
		};
		magazines[]=
		{
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
			"OLI_Flare_CM_mag"
		};
		class EventHandlers
        {
            init = "[_this select 0] spawn {sleep 0.1; (_this select 0) setVariable ['CMFlareLauncher', 'OLI_Flare_Countermeasure']};";
        };
		soundLocked[]=
		{
			"OLI_Vehicles\Data\sounds\radarlock.ogg",
			2, //vol
			1 //playback
		};
		soundIncommingMissile[]=
		{
			"OLI_Vehicles\Data\sounds\launchwarn.wss",
			1.5,
			1
		};
   };
};
