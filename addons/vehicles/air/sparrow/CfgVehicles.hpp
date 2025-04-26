class CfgVehicles {
    class B_Heli_Light_01_dynamicLoadout_F;
    class CLASS(Sparrow): B_Heli_Light_01_dynamicLoadout_F {
        displayName = "AH-600 Sparrow";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Pilot);
        typicalCargo[] = {QCLASS(Marine_Pilot)};
        scope = 2;
        armor = 100;
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\sparrow\data\heli_light_01_ext_blufor_co.paa),
            "a3\air_f\heli_light_01\data\heli_light_01_dot_ca.paa"
        };
        weapons[] = {
            "CMFlareLauncher_Singles",
            "M134_minigun"
        };
        magazines[] = {
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "SmokeLauncherMag",
            "SmokeLauncherMag",
            "SmokeLauncherMag",
            "SmokeLauncherMag",
            "5000Rnd_762x51_Belt",
            "5000Rnd_762x51_Belt"
        };
    };
};