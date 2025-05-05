class CfgVehicles {
    class B_Heli_Transport_03_F;
    class CLASS(Harpoon): B_Heli_Transport_03_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "[505th] CH-447 Harpoon";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        armor = 100; //Default 40
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\harpoon\data\textures\heli_transport_03_ext01_co.paa),
            QPATHTOF(air\harpoon\data\textures\heli_transport_03_ext02_co.paa)
        };
        weapons[]=
		{
			"CMFlareLauncher_Singles",
            "Laserdesignator_pilotCamera",
			//"SmokeLauncher",
		};
		magazines[]=
		{
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
            "Laserbatteries",
            "Laserbatteries",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
		};
    };
};