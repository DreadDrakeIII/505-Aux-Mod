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
		"OLI_Sparrow"
		};
		weapons[]={};
		skipWhenMissingDependencies = 1;
	};
};
class CfgVehicles
{
	class B_Heli_Light_01_dynamicLoadout_F;
	
/////////////////////////////////////////////////////////
	
	class OLI_Sparrow: B_Heli_Light_01_dynamicLoadout_F
	{
        displayName = "AH-600 Sparrow";
        faction = "OLI_Fac";
        editorsubcategory = "OLI_Aircraft_RTW";
        crew = "OLI_HeliPilot";
		scope = 2
		armor=100; //Default 30
       hiddenSelectionsTextures[]=
		{
			"OLI_Vehicles\Data\Sparrow\data\Heli_Light_01_ext_Blufor_CO.paa",
			"a3\air_f\heli_light_01\data\heli_light_01_dot_ca.paa"
		};
		weapons[]=
		{
			"CMFlareLauncher_Singles",
			//"SmokeLauncher",
			"OLI_Flare_Countermeasure",
			"M134_minigun"
		};
		magazines[]=
		{
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
			"OLI_Flare_CM_mag",
			"5000Rnd_762x51_Belt",
			"5000Rnd_762x51_Belt"
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
