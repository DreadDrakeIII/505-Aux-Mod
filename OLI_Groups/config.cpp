class cfgpatches
{
	class TCI_groups
	{
		author="Cold Winter Productions";
		units[]=
		{
		"OLI_HeliPilot",
		"OLI_JetPilot"
			
		};
		weapons[]={};
		requiredversion=0.1;
		requiredaddons[]=
		{
			"OLI_Core"
		};
	};
};


class cfgvehicles
{
	class B_Fighter_Pilot_F;
	
	class OLI_HeliPilot: B_Fighter_Pilot_F
		{
			displayName="505th Heli Pilot";
			faction="OLI_Fac";
			editorcategory="OLI_INF";
			scope=2;									
			scopeCurator = 2;
			side=1;
			uniformClass="OPTRE_FC_Marines_Uniform_BLK";
			backpack="";
			weapons[]=
			{
				"OPTRE_M6B",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"OPTRE_M6B",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"OPTRE_8Rnd_127x40_Mag",
				"OPTRE_8Rnd_127x40_Mag",
				"OPTRE_8Rnd_127x40_Mag",
				"OPTRE_8Rnd_127x40_Mag"
			};
			respawnMagazines[]=
			{
				"OPTRE_8Rnd_127x40_Mag",
				"OPTRE_8Rnd_127x40_Mag",
				"OPTRE_8Rnd_127x40_Mag",
				"OPTRE_8Rnd_127x40_Mag"
			};
			items[]=
			{
				"ACE_fieldDressing",
				"ACE_fieldDressing",
				"ACE_fieldDressing",
				"ACE_fieldDressing",
				"ACE_elasticBandage",
				"ACE_elasticBandage",
				"ACE_elasticBandage",
				"ACE_elasticBandage",
				"ACE_elasticBandage",
				"ACE_elasticBandage",
				"ACE_fieldDressing"
			};
			linkedItems[]=
			{
				"OPTRE_UNSC_M52A_Armor3_URB",
				"H_PilotHelmetHeli_B",
				"ItemMap",
				"ItemCompass",
				"ItemWatch",
				"ItemRadio",
				"ItemGPS"
			};
		};
	class OLI_JetPilot: B_Fighter_Pilot_F
		{
			displayName="505th Jet Pilot";
			faction="OLI_Fac";
			editorcategory="OLI_INF";
			scope=2;									
			scopeCurator = 2;
			side=1;
			uniformClass="OPTRE_FC_Marines_Uniform_BLK";
			backpack="";
			weapons[]=
			{
				"OPTRE_M6B",
				"Throw",
				"Put"
			};
			respawnWeapons[]=
			{
				"OPTRE_M6B",
				"Throw",
				"Put"
			};
			magazines[]=
			{
				"OPTRE_8Rnd_127x40_Mag",
				"OPTRE_8Rnd_127x40_Mag",
				"OPTRE_8Rnd_127x40_Mag",
				"OPTRE_8Rnd_127x40_Mag"
			};
			respawnMagazines[]=
			{
				"OPTRE_8Rnd_127x40_Mag",
				"OPTRE_8Rnd_127x40_Mag",
				"OPTRE_8Rnd_127x40_Mag",
				"OPTRE_8Rnd_127x40_Mag"
			};
			items[]=
			{
				"ACE_fieldDressing",
				"ACE_fieldDressing",
				"ACE_fieldDressing",
				"ACE_fieldDressing",
				"ACE_elasticBandage",
				"ACE_elasticBandage",
				"ACE_elasticBandage",
				"ACE_elasticBandage",
				"ACE_elasticBandage",
				"ACE_elasticBandage",
				"ACE_fieldDressing"
			};
			linkedItems[]=
			{
				"OPTRE_UNSC_M52A_Armor3_URB",
				"H_PilotHelmetFighter_B",
				"ItemMap",
				"ItemCompass",
				"ItemWatch",
				"ItemRadio",
				"ItemGPS"
			};
		};

};