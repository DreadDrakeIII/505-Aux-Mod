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
    class OLI_240rnd_CM_Custom: CMFlareLauncher
	{
		displayName="Countermeasures";
		displayNameShort="Countermeasures";
		magazines[]=
		{
			"240Rnd_CMFlare_Chaff_Magazine"
		};
        modes[]= {"Burst","Single","AIBurst"};
       
        class Single
        {
            soundBegin[] = {"sound",1};
            sounds[] = {"StandardSound"};
        };

		sounds[]=
		{
			"StandardSound"
		};
		class StandardSound
		{
			soundsetshot[]=
			{
				"OLI_CM_shot_soundSet"
			};
            soundbegin[] = {};
		};
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

class CfgSoundSets
{
	class OLI_CM_shot_soundSet
	{
		SoundShaders[]=
		{
			"OLI_CM_shot_soundShader"
		};
		volumeFactor=1.6;
		volumeCurve="InverseSquare2Curve";
		spatial=1;
		doppler=0;
		loop=0;
		sound3DProcessingType="ExplosionLight3DProcessingType";
		distanceFilter="explosionDistanceFreqAttenuationFilter";
		occlusionFactor=0.30000001;
		obstructionFactor=0;
	};
};

class CfgSoundShaders
{
	class OLI_CM_shot_soundShader
	{
		samples[]=
		{
			
			{
				"OLI_Vehicles\Data\sounds\flare.wss",
				1
			}
		};
		volume=1;
		range=1600;
	};
};