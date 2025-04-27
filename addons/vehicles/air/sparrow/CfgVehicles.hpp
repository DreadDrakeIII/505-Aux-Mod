class CfgVehicles {
    class B_Heli_Light_01_dynamicLoadout_F;
    class CLASS(Sparrow): B_Heli_Light_01_dynamicLoadout_F {
        SCOPE_PUBLIC;
        displayName = "AH-600 Sparrow";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Heli_Pilot_Helmet);
        typicalCargo[] = {QCLASS(Heli_Pilot_Helmet)};
        armor = 100;
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\sparrow\data\textures\heli_light_01_ext_blufor_co.paa),
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