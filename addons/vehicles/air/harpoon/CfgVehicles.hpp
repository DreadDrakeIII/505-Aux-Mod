class CfgVehicles {
    class B_Heli_Transport_03_F;
    class CLASS(Harpoon): B_Heli_Transport_03_F {
        SCOPE_PUBLIC;
        displayName = "CH-447 Harpoon";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Heli_Pilot_Helmet);
        typicalCargo[] = {QCLASS(Heli_Pilot_Helmet)};
        armor = 100; //Default 40
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\harpoon\data\textures\heli_transport_03_ext01_co.paa),
            QPATHTOF(air\harpoon\data\textures\heli_transport_03_ext02_co.paa)
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