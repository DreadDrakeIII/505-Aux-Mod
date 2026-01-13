class CfgPatches
{
	class OLI_advurbanrappelling
	{
		name = "Advanced Urban Rappelling";
		author = "505th Dev Team";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"A3_Modules_F"};
	};
};

class CfgNetworkMessages
{
	class AdvancedUrbanRappellingRemoteExecClient
	{
		module = "AdvancedUrbanRappelling";
		parameters[] = {"ARRAY","STRING","OBJECT","BOOL"};
	};

	class AdvancedUrbanRappellingRemoteExecServer
	{
		module = "AdvancedUrbanRappelling";
		parameters[] = {"ARRAY","STRING","BOOL"};
	};
};

class CfgFunctions
{
	class OLI
	{
		class AdvancedUrbanRappelling
		{
			file = "\BLU\OLI\addons\advurbanrappelling\functions";
			class advancedUrbanRappellingInit { postInit = 1; };
		};
	};
};

class CfgSounds
{
	class AUR_Rappel_Loop
	{
		name = "AUR_Rappel_Loop";
		sound[] = {"\BLU\OLI\addons\advurbanrappelling\sounds\AUR_Rappel_Loop.ogg", "db+5", 1};
		titles[] = {0, ""};
	};
	class AUR_Rappel_Start
	{
		name = "AUR_Rappel_Start";
		sound[] = {"\BLU\OLI\addons\advurbanrappelling\sounds\AUR_Rappel_Start.ogg", "db+10", 1};
		titles[] = {0, ""};
	};
	class AUR_Rappel_End
	{
		name = "AUR_Rappel_End";
		sound[] = {"\BLU\OLI\addons\advurbanrappelling\sounds\AUR_Rappel_End.ogg", "db+10", 1};
		titles[] = {0, ""};
	};
};

#include "CfgAnimations.hpp"
