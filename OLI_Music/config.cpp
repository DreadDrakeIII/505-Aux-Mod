class CfgPatches
{
	class OLI_Music
	{
		name="OLI Music Pack";
		author="Winter";
		requiredaddons[]={
			"OLI_Core"
		};
		requiredversion=0.1;
		units[]={};
		weapons[]={};
	};
};
class CfgMusicClasses
{
    class OLI_Calm
    {
        displayName="505th Calm Music";
    };
	class OLI_Sad
    {
        displayName="505th Sad Music";
    };
	class OLI_505_Battle
    {
        displayName="505th Battle Music";
    };
	//class OLI_StarWars
   // {
    //    displayName="505th Star Wars Music";
   // };
	class OLI_Radio
    {
        displayName="505th Radio";
    };
};

class CfgMusic
{
	
	/////////////////////
	//////OLI_Calm//////
	/////////////////////
	
	
	
	/////////////////////
	//OLI_Sad//
	/////////////////////
	class BuryingTheDead
	{
		name="Burying The Dead";
		musicClass="OLI_Sad";
		sound[]=
        {
            "OLI_Music\Data\BuryingTheDead.ogg",
            db+0,
            1
        };
		duration=129;
	};
	class Norman
	{
		name="Norman";
		musicClass="OLI_Sad";
		sound[]=
        {
            "OLI_Music\Data\Norman.ogg",
            db+0,
            1
        };
		duration=171;
	};
	
	////////////////////////
	//OLI_505_Battle//
	///////////////////////
	class The_Final_Battle
	{
		name="The Final Battle";
		musicClass="OLI_505_Battle";
		sound[]=
        {
            "OLI_Music\Data\The Final Battle.ogg",
            db+0,
            1
        };
		duration=207;
	};
	class Barbarian_Horde
	{
		name="Barbarian Horde";
		musicClass="OLI_505_Battle";
		sound[]=
        {
            "OLI_Music\Data\BarbarianHorde.ogg",
            db+0,
            1
        };
		duration=633;
	};

	/////////////
	//OLI_Radio//
	/////////////
	class BURN
	{
		name="Burn";
		musicClass="OLI_Radio";
		sound[]=
        {
            "OLI_Music\Data\BURN.ogg",
            db+0,
            1
        };
		duration=202;
	};
	class Hoist_The_Colours_x_Hes_a_Pirate
	{
		name="Hoist The Colours x He's a Pirate";
		musicClass="OLI_Radio";
		sound[]=
        {
            "OLI_Music\Data\Hoist The Colours x He's a Pirate.ogg",
            db+0,
            1
        };
		duration=295;
	};
	class Unravel_EPIC
	{
		name="Unravel  EPIC";
		musicClass="OLI_Radio";
		sound[]=
        {
            "OLI_Music\Data\Unravel  EPIC.ogg",
            db+0,
            1
        };
		duration=260;
	};
};
