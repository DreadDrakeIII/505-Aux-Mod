class CfgVehicles {
    class B_T_VTOL_01_armed_F;
    class CLASS(Widow_Armed): B_T_VTOL_01_armed_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "[505th] V/AC-220 Widow";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\widow\data\textures\vtol_01_ext01_505_co.paa),
            QPATHTOF(air\widow\data\textures\vtol_01_ext02_505_co.paa),
            QPATHTOF(air\widow\data\textures\vtol_01_ext03_505_co.paa),
            QPATHTOF(air\widow\data\textures\vtol_01_ext04_505_co.paa),
            QPATHTOF(air\widow\data\textures\vtol_01_signs_CA.paa),
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

    class B_T_VTOL_01_infantry_F;
    class CLASS(Widow): B_T_VTOL_01_infantry_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "[505th] V/C-220 Widow";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\widow\data\textures\vtol_01_ext01_505_co.paa),
            QPATHTOF(air\widow\data\textures\vtol_01_ext02_505_co.paa),
            QPATHTOF(air\widow\data\textures\vtol_01_ext03_505_co.paa),
            QPATHTOF(air\widow\data\textures\vtol_01_ext04_505_co.paa),
            QPATHTOF(air\widow\data\textures\vtol_01_signs_CA.paa),
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