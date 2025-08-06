class CfgVehicles {
    class B_Heli_Light_01_dynamicLoadout_F;
    class CLASS(Sparrow): B_Heli_Light_01_dynamicLoadout_F {
        displayName = "AH-600 Sparrow";
        scope = 2;
        scopeCurator = 2;
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        armor = 100;
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\sparrow\data\textures\heli_light_01_ext_blufor_co.paa),
            "a3\air_f\heli_light_01\data\heli_light_01_dot_ca.paa"
        };
        weapons[] = {
            "CMFlareLauncher_Singles",
            "Laserdesignator_mounted",
            "M134_minigun"
        };
        magazines[] = {
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "Laserbatteries",
            "Laserbatteries",
            "SmokeLauncherMag",
            "SmokeLauncherMag",
            "SmokeLauncherMag",
            "SmokeLauncherMag",
            "5000Rnd_762x51_Belt",
            "5000Rnd_762x51_Belt",
            "5000Rnd_762x51_Belt",
            "5000Rnd_762x51_Belt"
        };
    };

    class B_Heli_Light_01_F;
    class CLASS(Pidgeon): B_Heli_Light_01_F {
        displayName = "AH-610 Pigeon";
        scope = 2;
        scopeCurator = 2;
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        armor = 100;
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\sparrow\data\textures\heli_light_01_ext_blufor_co.paa),
            "a3\air_f\heli_light_01\data\heli_light_01_dot_ca.paa"
        };
        weapons[] = {
            "CMFlareLauncher_Singles",
            "Laserdesignator_mounted"
        };
        magazines[] = {
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "Laserbatteries",
            "Laserbatteries",
            "SmokeLauncherMag",
            "SmokeLauncherMag",
            "SmokeLauncherMag",
            "SmokeLauncherMag",
            "SmokeLauncherMag",
            "SmokeLauncherMag",
            "SmokeLauncherMag",
            "SmokeLauncherMag",
        };
    };
};
