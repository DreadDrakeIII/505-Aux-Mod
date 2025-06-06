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
        crew = "OLI_JetPilot";
		weapons[]=
		{
			"weapon_Fighter_Gun20mm_AA",
			"Laserdesignator_pilotCamera",
			"CMFlareLauncher_Singles",
			"OLI_Flare_Countermeasure"
		};
		magazines[]=
		{
			"magazine_Fighter01_Gun20mm_AA_x450",
			"magazine_Fighter01_Gun20mm_AA_x450",
			"Laserbatteries",
			"240Rnd_CMFlare_Chaff_Magazine",
			"OLI_Flare_CM_mag"
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
			"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_03_ca.paa",
			"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_01_ca.paa"
			//"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_01_ca.paa"
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