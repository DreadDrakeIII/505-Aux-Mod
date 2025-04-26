class CfgVehicles {
    class B_Heli_Transport_03_F;
    class CLASS(Harpoon): B_Heli_Transport_03_F {
        displayName = "CH-447 Harpoon";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Pilot);
        typicalCargo[] = {QCLASS(Marine_Pilot)};
        scope = 2;
        scopeCurator = 2;
        armor = 100; //Default 40
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\harpoon\data\heli_transport_03_ext01_co.paa),
            QPATHTOF(air\harpoon\data\heli_transport_03_ext02_co.paa)
        };
        weapons[]=
		{
			"CMFlareLauncher_Singles",
			//"SmokeLauncher",
		};
		magazines[]=
		{
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
		};
    };
};