class CfgVehicles {
    class B_T_VTOL_01_infantry_F;
    class CLASS(Widow): B_T_VTOL_01_infantry_F {
        SCOPE_PUBLIC;
        displayName = "V/C-220 Widow";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Heli_Pilot_Helmet);
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\widow_infantry\data\textures\vtol_01_ext01_505_co.paa),
            QPATHTOF(air\widow_infantry\data\textures\vtol_01_ext02_505_co.paa),
            QPATHTOF(air\widow_infantry\data\textures\vtol_01_ext03_505_co.paa),
            QPATHTOF(air\widow_infantry\data\textures\vtol_01_ext04_505_co.paa),
            QPATHTOF(air\widow_infantry\data\textures\vtol_01_signs_CA.paa),
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