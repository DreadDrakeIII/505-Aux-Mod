class CfgPatches
{
	class OLI_Weapons_m96
	{
		Author = "Winter";
		units[]={};
		requiredAddons[]=
		{
			"DMNS_Weapons_Launchers"
		};
		weapons[]=
		{
			"OLI_M96"
		};
		units[]={};
		
	};
};
class CowsSlot;
class UnderBarrelSlot;
class MuzzleSlot;
class PointerSlot;
class FullAuto;
class CfgWeapons
{
	class DMNS_M96_LAW;
	
	class OLI_M96: DMNS_M96_LAW
	{
		Author= "Winter";
		displayName="505th M96 LAW";
		baseWeapon= "OLI_M96";
		magazines[]=
		{
			"DMNS_M96_HEAT"
		};
	};
};