class CfgPatches
{
	class OLI_Aux_Armor
	{
		units[]=
		{
			"OLI_unit"
		};
		weapons[]=
		{
			"OLI_Uniform",
			"OLI_HELMET",
			"OLI_Armour_Vest",
			"OLI_Armour_Vest_V2",
			"OLI_Armour_Vest_NSV2",
			"OLI_Armour_Vest_NS",
			"OLI_Armour_Vest_Pouch",
			"OLI_Armour_Vest_V2Pouch",
			"OLI_Armour_Vest_NSV2Pouch",
			"OLI_Armour_Vest_NSPouch",
			"OLI_Armour_Medic_Vest",
			"OLI_Armour_Medic_Vest_V2",
			"OLI_Armour_Medic_Vest_NSV2",
			"OLI_Armour_Medic_Vest_NS",
			"OLI_Armour_Medic_Vest_Pouch",
			"OLI_Armour_Medic_Vest_V2Pouch",
			"OLI_Armour_Medic_Vest_NSV2Pouch",
			"OLI_Armour_Medic_Vest_NSPouch",
			"OLI_Armour_SL_Vest",
			"OLI_Armour_SL_Vest_V2",
			"OLI_Armour_SL_Vest_NSV2",
			"OLI_Armour_SL_Vest_NS",
			"OLI_Armour_SL_Vest_Pouch",
			"OLI_Armour_SL_Vest_V2Pouch",
			"OLI_Armour_SL_Vest_NSV2Pouch",
			"OLI_Armour_SL_Vest_NSPouch",
			"OLI_Armour_PL_Vest",
			"OLI_Armour_PL_Vest_V2",
			"OLI_Armour_PL_Vest_NSV2",
			"OLI_Armour_PL_Vest_NS",
			"OLI_Armour_PL_Vest_Pouch",
			"OLI_Armour_PL_Vest_V2Pouch",
			"OLI_Armour_PL_Vest_NSV2Pouch",
			"OLI_Armour_PL_Vest_NSPouch"
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Characters_F",
			"A3_Data_F_Mark",
			"Rogue_CEMarine"
		};
	};
};

class CfgVehicles
{
	class Rogue_CEUniform_inf_B;

	class OLI_unit: Rogue_CEUniform_inf_B
	{
		author="Cold Winter Productions";
		displayName="505th Marine";
		faction="OLI_Fac";
		editorSubcategory="OLI_INF";
		uniformclass="OLI_Uniform";
		scope=2;
		scopeCurator=2;
		hiddenSelectionsTextures[]=
		{
			"\Rogue_CEMarine\data\Rogue_CEUniformP_co.paa",
			"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"
		};
		linkedItems[]=
		{
			"OLI_HELMETV2",
			"OLI_Armour_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
		respawnLinkedItems[]=
		{
			"OLI_HELMETV2",
			"OLI_Armour_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
	};

	class OLI_Medic: OLI_unit
	{
		author="Cold Winter Productions";
		displayName="505th Marine Medic";
		uniformclass="OLI_Uniform_Medic";
		hiddenSelectionsTextures[]=
		{
			"OLI_Armor\Data\Medic\Medic_UniformP_co.paa",
			"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"
		};
		linkedItems[]=
		{
			"OLI_HELMET_Medic",
			"OLI_Armour_Medic_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
		respawnLinkedItems[]=
		{
			"OLI_HELMET_Medic",
			"OLI_Armour_Medic_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
	};
	class OLI_SL: OLI_unit
	{
		author="Cold Winter Productions";
		displayName="505th Marine Squad Lead";
		uniformclass="OLI_Uniform_SL";
		hiddenSelectionsTextures[]=
		{
			"OLI_Armor\Data\SL\SL_UniformP_co.paa",
			"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"
		};
		linkedItems[]=
		{
			"OLI_HELMET_SL",
			"OLI_Armour_SL_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
		respawnLinkedItems[]=
		{
			"OLI_HELMET_SL",
			"OLI_Armour_SL_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
	};
	class OLI_PL: OLI_unit
	{
		author="Cold Winter Productions";
		displayName="505th Marine Platoon Lead";
		uniformclass="OLI_Uniform_PL";
		hiddenSelectionsTextures[]=
		{
			"OLI_Armor\Data\PL\PL_UniformP_co.paa",
			"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"
		};
		linkedItems[]=
		{
			"OLI_HELMET_PL",
			"OLI_Armour_PL_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
		respawnLinkedItems[]=
		{
			"OLI_HELMET_PL",
			"OLI_Armour_PL_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
	};

	////////////////////Custom////////////////////
	class OLI_Drake_Unit: OLI_unit
	{
		author="Cold Winter Productions";
		displayName="505th Marine Drake";
		uniformclass="OLI_Drake_Uniform";
		hiddenSelectionsTextures[]=
		{
			"\Rogue_CEMarine\data\Rogue_CEUniformP_co.paa",
			"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"
		};
		linkedItems[]=
		{
			"OLI_HELMETV2",
			"OLI_Armour_Drake_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
		respawnLinkedItems[]=
		{
			"OLI_HELMETV2",
			"OLI_Armour_Drake_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
	};
	class OLI_Adamant_Unit: OLI_unit
	{
		scope=2;
		scopeCurator=2;
		author="Cold Winter Productions";
		displayName="505th Marine Adamant";
		uniformclass="OLI_Uniform";
		hiddenSelectionsTextures[]=
		{
			"OLI_Armor\Data\Custom\Adamant\Dexus_UniformP_co.paa",
			"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"
		};
		linkedItems[]=
		{
			"OLI_Adamant_HELMET",
			"OLI_Armour_Adamant_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
		respawnLinkedItems[]=
		{
			"OLI_Adamant_HELMET",
			"OLI_Armour_Adamant_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
	};
    class OLI_Crawford_Unit: OLI_unit
	{
		scope=2;
		scopeCurator=2;
		author="Cold Winter Productions";
		displayName="505th Marine Crawford";
		uniformclass="OLI_Crawford_Uniform";
		hiddenSelectionsTextures[]=
		{
			"OLI_Armor\Data\Custom\Anvil\Anvil_UniformP_co.paa",
			"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"
		};
		linkedItems[]=
		{
			"OLI_Crawford_HELMET",
			"OLI_Armour_Crawford_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
		respawnLinkedItems[]=
		{
			"OLI_Crawford_HELMET",
			"OLI_Armour_Crawford_Vest",
			"ItemMap",
			"ItemCompass",
			"ItemWatch"
		};
	};


};


class CfgWeapons
{
	////////////////////UNIFORMS////////////////////
	class UniformItem;
	class Rogue_CEUniform_U_B;

		class OLI_Uniform: Rogue_CEUniform_U_B //(uniform class)
		{
		author="Cold Winter Productions";
		displayName="505th Marine Uniform";
		scope=2;
		scopeCurator=2;
		scopeArsenal=2;
			class ItemInfo: UniformItem
			{
				uniformClass="OLI_unit";
				containerClass="Supply150";
				mass=40;
			};
		};
		class OLI_Uniform_Medic: OLI_Uniform
		{
		author="Cold Winter Productions";
		displayName="505th Marine Uniform Medic";
			class ItemInfo: UniformItem
			{
				uniformClass="OLI_Medic";
				containerClass="Supply150";
				mass=40;
			};
		};
        class OLI_Adamant_Uniform: OLI_Uniform
		{
		author="Cold Winter Productions";
		displayName="505th Marine Uniform (Adamant)";
		scope=2;
		scopeCurator=2;
		scopeArsenal=2;
			class ItemInfo: UniformItem
			{
				uniformClass="OLI_Adamant_Uniform";
				containerClass="Supply150";
				mass=40;
			};
		};
        class OLI_Anvil_Uniform: OLI_Uniform
		{
		author="Cold Winter Productions";
		displayName="505th Marine Uniform (Crawford)";
		scope=2;
		scopeCurator=2;
		scopeArsenal=2;
			class ItemInfo: UniformItem
			{
				uniformClass="OLI_Crawford_Uniform";
				containerClass="Supply150";
				mass=40;
			};
		};
        class OLI_Drake_Uniform: OLI_Uniform
		{
		author="Cold Winter Productions";
		displayName="505th Marine Uniform (Drake)";
		scope=2;
		scopeCurator=2;
		scopeArsenal=2;
			class ItemInfo: UniformItem
			{
				uniformClass="OLI_Drake_Uniform";
				containerClass="Supply150";
				mass=40;
			};
		};

	////////////////////HELMETS////////////////////
	class Rogue_CEHelmetV2;
	class Rogue_CEHelmet;

	class OLI_HELMETV2: Rogue_CEHelmetV2
	{
		author="Cold Winter Productions";
		scope=2;
		scopeCurator=2;
		displayName="505th Marine Helmet";
		hiddenSelectionsTextures[]=
		{
			"\Rogue_CEMarine\data\Rogue_CEHelmet_co.paa"
		};
	};
	class OLI_HELMET: Rogue_CEHelmet
	{
		author="Cold Winter Productions";
		scope=2;
		scopeCurator=2;
		displayName="505th Marine Helmet (Eyepiece)";
		hiddenSelectionsTextures[]=
		{
			"\Rogue_CEMarine\data\Rogue_CEHelmet_co.paa"
		};
	};
	class OLI_HELMET_Medic: OLI_HELMET
	{
		author="Cold Winter Productions";
		scope=2;
		scopeCurator=2;
		displayName="505th Marine Medic Helmet (Eyepiece)";
		hiddenSelectionsTextures[]=
		{
			"OLI_Armor\Data\Medic\Medic_CEHelmet_co.paa"
		};
	};
	class OLI_HELMET_MedicV2: OLI_HELMETV2
	{
		author="Cold Winter Productions";
		scope=2;
		scopeCurator=2;
		displayName="505th Marine Medic Helmet";
		hiddenSelectionsTextures[]=
		{
			"OLI_Armor\Data\Medic\Medic_CEHelmet_co.paa"
		};
	};
	class OLI_HELMET_SL: OLI_HELMET
	{
		author="Cold Winter Productions";
		scope=2;
		scopeCurator=2;
		displayName="505th Marine Squad Lead Helmet";
		hiddenSelectionsTextures[]=
		{
			"OLI_Armor\Data\SL\SL_CEHelmet_co.paa"
		};
	};
	class OLI_HELMET_SLV2: OLI_HELMETV2
	{
		author="Cold Winter Productions";
		scope=2;
		scopeCurator=2;
		displayName="505th Marine Squad Lead Helmet (Eyepiece)";
		hiddenSelectionsTextures[]=
		{
			"OLI_Armor\Data\SL\SL_CEHelmet_co.paa"
		};
	};
	class OLI_HELMET_PL: OLI_HELMET
	{
		author="Cold Winter Productions";
		scope=2;
		scopeCurator=2;
		displayName="505th Marine Platoon Lead Helmet";
		hiddenSelectionsTextures[]=
		{
			"OLI_Armor\Data\PL\PL_CEHelmet_co.paa"
		};
	};
	class OLI_HELMET_PLV2: OLI_HELMETV2
	{
		author="Cold Winter Productions";
		scope=2;
		scopeCurator=2;
		displayName="505th Marine Platoon Lead Helmet (Eyepiece)";
		hiddenSelectionsTextures[]=
		{
			"OLI_Armor\Data\PL\PL_CEHelmet_co.paa"
		};
	};
	////////////////////Custom Helms////////////////////
	class OLI_Adamant_HELMET: OLI_HELMETV2
	{
		author="Cold Winter Productions";
		scope=2;
		scopeCurator=2;
		displayName="505th Marine Custom Helmet (Adamant)";
		hiddenSelectionsTextures[]=
		{
			"OLI_Armor\Data\Custom\Adamant\Dexus_Helmet_co.paa"
		};
	};
    class OLI_Anvil_HELMET: OLI_HELMETV2
	{
		author="Cold Winter Productions";
		scope=2;
		scopeCurator=2;
		displayName="505th Marine Custom Helmet (Anvil)";
		hiddenSelectionsTextures[]=
		{
			"OLI_Armor\Data\Custom\Anvil\Anvil_Helmet_co.paa"
		};
	};

	////////////////////VESTS////////////////////
	class Rogue_CEArmour;
	class Rogue_CEArmourV2;
	class Rogue_CEArmourNSV2;
	class Rogue_CEArmourNS;
	class Rogue_CEArmourPouch;
	class Rogue_CEArmourV2Pouch;
	class Rogue_CEArmourNSV2Pouch;
	class Rogue_CEArmourNSPouch;


		class OLI_Armour_Vest: Rogue_CEArmour
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Armor";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEArmour_co.paa"
			};
		};
		class OLI_Armour_Vest_V2: Rogue_CEArmourV2
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Armor (No Forearms)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEArmour_co.paa"
			};
		};
		class OLI_Armour_Vest_NSV2: Rogue_CEArmourNSV2
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Armor (No Forearms + Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEArmour_co.paa"
			};
		};
		class OLI_Armour_Vest_NS: Rogue_CEArmourNS
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Armor (No Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEArmour_co.paa"
			};
		};
		class OLI_Armour_Vest_Pouch: Rogue_CEArmourPouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Armor (Pouches)";
			hiddenSelections[]=
			{
				"camo",
				"camo1",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEArmour_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"
			};
		};
		class OLI_Armour_Vest_V2Pouch: Rogue_CEArmourV2Pouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Armor (Pouches + No Forearms)";
			hiddenSelections[]=
			{
				"camo",
				"camo1",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEArmour_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"
			};
		};
		class OLI_Armour_Vest_NSV2Pouch: Rogue_CEArmourNSV2Pouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Armor (Pouches + No Forearms/Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEArmour_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"
			};
		};
		class OLI_Armour_Vest_NSPouch: Rogue_CEArmourNSPouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Armor (Pouches + No Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEArmour_co.paa"
			};
		};

		////////////
		class OLI_Armour_Medic_Vest: OLI_Armour_Vest
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Medic Armor";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\Medic\Medic_CEArmour_co.paa"
			};
		};
		class OLI_Armour_Medic_Vest_V2: Rogue_CEArmourV2
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Medic Armor (No Forearms)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\Medic\Medic_CEArmour_co.paa"
			};
		};
		class OLI_Armour_Medic_Vest_NSV2: Rogue_CEArmourNSV2
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Medic Armor (No Forearms + Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\Medic\Medic_CEArmour_co.paa"
			};
		};
		class OLI_Armour_Medic_Vest_NS: Rogue_CEArmourNS
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Medic Armor (No Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\Medic\Medic_CEArmour_co.paa"
			};
		};
		class OLI_Armour_Medic_Vest_Pouch: Rogue_CEArmourPouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Medic Armor (Pouches)";
			hiddenSelections[]=
			{
				"camo",
				"camo1",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\Medic\Medic_CEArmour_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"
			};
		};
		class OLI_Armour_Medic_Vest_V2Pouch: Rogue_CEArmourV2Pouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Medic Armor (Pouches + No Forearms)";
			hiddenSelections[]=
			{
				"camo",
				"camo1",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\Medic\Medic_CEArmour_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"
			};
		};
		class OLI_Armour_Medic_Vest_NSV2Pouch: Rogue_CEArmourNSV2Pouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Medic Armor (Pouches + No Forearms/Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\Medic\Medic_CEArmour_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"
			};
		};
		class OLI_Armour_Medic_Vest_NSPouch: Rogue_CEArmourNSPouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Medic Armor (Pouches + No Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\Medic\Medic_CEArmour_co.paa"
			};
		};

		////////////
		class OLI_Armour_SL_Vest: OLI_Armour_Vest
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Squad Lead Armor";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\SL\SL_CEArmour_co.paa"
			};
		};
		class OLI_Armour_SL_Vest_V2: Rogue_CEArmourV2
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Squad Lead Armor (No Forearms)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\SL\SL_CEArmour_co.paa"
			};
		};
		class OLI_Armour_SL_Vest_NSV2: Rogue_CEArmourNSV2
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Squad Lead Armor (No Forearms + Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\SL\SL_CEArmour_co.paa"
			};
		};
		class OLI_Armour_SL_Vest_NS: Rogue_CEArmourNS
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Squad Lead Armor (No Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\SL\SL_CEArmour_co.paa"
			};
		};
		class OLI_Armour_SL_Vest_Pouch: Rogue_CEArmourPouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Squad Lead Armor (Pouches)";
			hiddenSelections[]=
			{
				"camo",
				"camo1",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\SL\SL_CEArmour_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"
			};
		};
		class OLI_Armour_SL_Vest_V2Pouch: Rogue_CEArmourV2Pouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Squad Lead Armor (Pouches + No Forearms)";
			hiddenSelections[]=
			{
				"camo",
				"camo1",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\SL\SL_CEArmour_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"
			};
		};
		class OLI_Armour_SL_Vest_NSV2Pouch: Rogue_CEArmourNSV2Pouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Squad Lead Armor (Pouches + No Forearms/Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\SL\SL_CEArmour_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"
			};
		};
		class OLI_Armour_SL_Vest_NSPouch: Rogue_CEArmourNSPouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Squad Lead Armor (Pouches + No Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\SL\SL_CEArmour_co.paa"
			};
		};

		////////////
		class OLI_Armour_PL_Vest: OLI_Armour_Vest
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Platoon Lead Armor";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\PL\PL_CEArmour_co.paa"
			};
		};
		class OLI_Armour_PL_Vest_V2: Rogue_CEArmourV2
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Platoon Lead Armor (No Forearms)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\PL\PL_CEArmour_co.paa"
			};
		};
		class OLI_Armour_PL_Vest_NSV2: Rogue_CEArmourNSV2
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Platoon Lead Armor (No Forearms + Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\PL\PL_CEArmour_co.paa"
			};
		};
		class OLI_Armour_PL_Vest_NS: Rogue_CEArmourNS
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Platoon Lead Armor (No Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\PL\PL_CEArmour_co.paa"
			};
		};
		class OLI_Armour_PL_Vest_Pouch: Rogue_CEArmourPouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Platoon Lead Armor (Pouches)";
			hiddenSelections[]=
			{
				"camo",
				"camo1",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\PL\PL_CEArmour_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"
			};
		};
		class OLI_Armour_PL_Vest_V2Pouch: Rogue_CEArmourV2Pouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Platoon Lead Armor (Pouches + No Forearms)";
			hiddenSelections[]=
			{
				"camo",
				"camo1",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\PL\PL_CEArmour_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"
			};
		};
		class OLI_Armour_PL_Vest_NSV2Pouch: Rogue_CEArmourNSV2Pouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Platoon Lead Armor (Pouches + No Forearms/Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1",
				"camo2"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\PL\PL_CEArmour_co.paa",
				"\Rogue_CEMarine\data\Rogue_CEPouches_co.paa"
			};
		};
		class OLI_Armour_PL_Vest_NSPouch: Rogue_CEArmourNSPouch
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Platoon Lead Armor (Pouches + No Shoulders)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\PL\PL_CEArmour_co.paa"
			};
		};

		class OLI_Armour_Drake_Vest: Rogue_CEArmour
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Custom Armor (Drake)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\Custom\Drake\Drake_Armor_co.paa"
			};
		};
		class OLI_Armour_Adamant_Vest: Rogue_CEArmour
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Custom Armor (Adamant)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\Custom\Adamant\Dexus_Armor_co.paa"
			};
		};
        class OLI_Armour_Anvil_Vest: Rogue_CEArmour
		{
			author="Cold Winter Productions";
			scope=2;
			displayName="505th Marine Custom Armor (Crawford)";
			hiddenSelections[]=
			{
				"camo",
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"\Rogue_CEMarine\data\Rogue_CEPadding_co.paa",
				"\OLI_Armor\Data\Custom\Anvil\Anvil_Armor_co.paa"
			};
		};
};
