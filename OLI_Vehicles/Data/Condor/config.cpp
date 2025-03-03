class CfgPatches
{
	class OLI_Aircraft_condor
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
		"OLI_condor"
		};
		weapons[]={};
		skipWhenMissingDependencies = 1;
	};
};
class CfgVehicles
{
	class B_Plane_CAS_01_dynamicLoadout_F;
	
/////////////////////////////////////////////////////////
	
	class OLI_condor: B_Plane_CAS_01_dynamicLoadout_F
	{
        displayName = "A-310 Condor";
        faction = "OLI_Fac";
        editorsubcategory = "OLI_Aircraft_FXW";
        crew = "OLI_JetPilot";
		weapons[]=
		{
			"Gatling_30mm_Plane_CAS_01_F",
			"Laserdesignator_pilotCamera",
			"OLI_240rnd_CM_Custom",
			//"OLI_Flare_Countermeasure"
		};
		magazines[]=
		{
			"1000Rnd_Gatling_30mm_Plane_CAS_01_F",
			"1000Rnd_Gatling_30mm_Plane_CAS_01_F",
			"Laserbatteries",
			"240Rnd_CMFlare_Chaff_Magazine",
			"OLI_Flare_CM_mag"
		};
		//armor=150;
       hiddenSelectionsTextures[]=
		{
			"OLI_Vehicles\Data\Condor\data\plane_cas_01_ext01_505th_CO.paa",
			"OLI_Vehicles\Data\Condor\data\plane_cas_01_ext02_505th_CO.paa"
		};
		 class EventHandlers
        {
            init = "[_this select 0] spawn {sleep 0.1; (_this select 0) setVariable ['CMFlareLauncher', 'OLI_Flare_Countermeasure']};";
        };
		soundLocked[]=
		{
			"OLI_Vehicles\Data\sounds\radarlock.ogg",
			3, //vol
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