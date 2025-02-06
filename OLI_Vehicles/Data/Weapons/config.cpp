class CfgPatches
{
	class OLI_VEHICLE_WEAPONS
	{
		author="Winter";
		requiredAddons[]=
		{
			"A3_Air_F",
			"A3_Data_F",
			"A3_Weapons_F",
			"A3_Characters_F",
			"A3_Data_F_Tank_Loadorder",
			"OLI_Core"
		};
		requiredVersion=0.1;
		ammo[]=
		{
			"OLI_Flare_ammo"
		};
		magazines[]=
		{
			"OLI_Flare_CM_mag"
		};
		weapons[]=
		{
			"OLI_Flare_Countermeasure"
		};
		units[]={};
		skipWhenMissingDependencies = 1;
	};
};
class CfgWeapons
{
    class CMFlareLauncher;  // Base class for countermeasure systems

    class OLI_Flare_Countermeasure: CMFlareLauncher
    {
        displayName = "Illumination Countermeasure Flares";
        displayNameShort = "Illum Flares";
        descriptionShort = "Illumination countermeasure system for night operations.";
        
        magazines[] = { "OLI_Flare_CM_mag" };  // Links to the countermeasure magazine
        autoFire = 1;  // Automatically fire if triggered
        reloadTime = 0.5;  // Fire rate
        burst = 1;  // Fires one flare at a time
        soundBurst = 0;  // Prevents sound looping
    };
};

class CfgAmmo
{
    class FlareCore;
    class Flare_82mm_AMOS_White: FlareCore
    {
        model = "\A3\Weapons_f\ammo\UGL_Flare";
        brightness = 6000;
        timeToLive = 300;  // How long the flare stays in the air
        intensity = 15000;
        flareSize = 100;
        triggerTime = 0.1;
        fuseDistance = 5; 
    };

    class OLI_Flare_ammo: Flare_82mm_AMOS_White
    {
        displayName = "Illumination Flare";
        displayNameShort = "Illum Flare";
		airFriction = 0.25;  // Increases air resistance to slow descent (default ~0.1)
        gravityFactor = 0.2;  // Reduces gravity effect to make it float longer (default ~1)
        
        timeToLive = 300;  // Keeps flare active longer in the air
    };
};

class CfgMagazines
{
    class 240Rnd_CMFlare_Chaff_Magazine;  // Base class for countermeasure magazines

    class OLI_Flare_CM_mag: 240Rnd_CMFlare_Chaff_Magazine
    {
        displayName = "Illumination CM Flares";
        ammo = "OLI_Flare_ammo";
        count = 15;  // Number of flares available
        initSpeed = 75;  // Launch speed of flares
        mass = 10;
    };
}