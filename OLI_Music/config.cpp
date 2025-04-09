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
    class OLI_505_Halo
    {
        displayName="505th Halo Music";
    };
    class OLI_VideoGame
    {
        displayName="505th Video Games";
    };
    class OLI_Songs
    {
        displayName="505th Songs";
    };
    class OLI_Soundtrack
    {
        displayName="505th Soundtrack";
    };
};

class CfgMusic
{

	/////////////////////
	//////OLI_Halo//////
	/////////////////////
    class BuryingTheDead
	{
		name="Halo Reach - Deliver Hope";
		musicClass="OLI_Halo";
		sound[]=
        {
            "OLI_Music\Data\DeliverHope.ogg",
            db+0,
            1
        };
		duration=137;
	};

    /////////////////////
	////OLI_VideoGame////
	/////////////////////



	/////////////////
	//OLI_505_Songs//
	/////////////////
	class BURN
	{
		name="Burn";
		musicClass="OLI_Songs";
		sound[]=
        {
            "OLI_Music\Data\BURN.ogg",
            db+0,
            1
        };
		duration=202;
	};
    class Norman
	{
		name="Norman";
		musicClass="OLI_Songs";
		sound[]=
        {
            "OLI_Music\Data\Norman.ogg",
            db+0,
            1
        };
		duration=171;
	};

    ////////////////////////
	//OLI_505_Soundtracks//
	///////////////////////
	class The_Final_Battle
	{
		name="The Final Battle";
		musicClass="OLI_Soundtrack";
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
		musicClass="OLI_Soundtrack";
		sound[]=
        {
            "OLI_Music\Data\BarbarianHorde.ogg",
            db+0,
            1
        };
		duration=633;
	};
    class Hoist_The_Colours_x_Hes_a_Pirate
	{
		name="Hoist The Colours x He's a Pirate";
		musicClass="OLI_Soundtrack";
		sound[]=
        {
            "OLI_Music\Data\Hoist The Colours x He's a Pirate.ogg",
            db+0,
            1
        };
		duration=295;
	};
    class BuryingTheDead
	{
		name="Burying The Dead";
		musicClass="OLI_Soundtrack";
		sound[]=
        {
            "OLI_Music\Data\BuryingTheDead.ogg",
            db+0,
            1
        };
		duration=129;
	};
    class TheBattle
	{
		name="Gladiator - The Battle";
		musicClass="OLI_Soundtrack";
		sound[]=
        {
            "OLI_Music\Data\The_Battle.ogg",
            db+0,
            1
        };
		duration=602;
	};
    class Unravel_EPIC
	{
		name="Unravel  EPIC";
		musicClass="OLI_Soundtrack";
		sound[]=
        {
            "OLI_Music\Data\Unravel  EPIC.ogg",
            db+0,
            1
        };
		duration=260;
	};
    class VictoryandDeath
	{
		name="Victory and Death";
		musicClass="OLI_Soundtrack";
		sound[]=
        {
            "OLI_Music\Data\VictoryandDeath.ogg",
            db+0,
            1
        };
		duration=62;
	};
    class TENET_Trucks_in_Place
	{
		name="TENET - Trucks in Place";
		musicClass="OLI_Soundtrack";
		sound[]=
        {
            "OLI_Music\Data\TENET_Trucks_in_Place.ogg",
            db+0,
            1
        };
		duration=332;
	};
    class TENET_Freeport
	{
		name="TENET - Freeport";
		musicClass="OLI_Soundtrack";
		sound[]=
        {
            "OLI_Music\Data\TENET_Freeport.ogg",
            db+0,
            1
        };
		duration=219;
	};
    class TENET_SATOR
	{
		name="TENET-SATOR[Dread]";
		musicClass="OLI_Soundtrack";
		sound[]=
        {
            "OLI_Music\Data\TENET_SATOR.ogg",
            db+0,
            1
        };
		duration=171;
	};
};
