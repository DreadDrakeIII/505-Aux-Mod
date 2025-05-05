class CfgVehicles {
    class DMNS_UNSC_Nightingale;
    class CLASS(Nightingale): DMNS_UNSC_Nightingale {
        SCOPE_PUBLIC;
        displayName = "[505th] EV-41 Nightingale";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine__Heli_Pilot);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        armor = 560; //Default 140
        hiddenSelections[] = {"main rotor static","tail rotor static","camo1","clan","clan_text","insignia"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\nightingale\data\textures\505th_nightingale_base2_co.paa),
            QPATHTOF(air\nightingale\data\textures\505th_nightingale_base2_co.paa),
            QPATHTOF(air\nightingale\data\textures\505th_nightingale_base_co.paa)
        };
        icon = "\OPTRE_Vehicles_Air\Falcon\data\icon.paa";
    };

    class CLASS(ONI_Nightingale): DMNS_UNSC_Nightingale {
        SCOPE_PUBLIC;
        displayName = "[ONI] EV-44 Nightingale";
        faction = QFACTION(ONI);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine__Heli_Pilot);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};

        soundEngineOffExt[] = {"jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\uh80_ghosthawk\ext_off.ogg",1,1,300};
        soundEngineOffInt[] = {"jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\uh80_ghosthawk\int_off.ogg",1,1};
        soundEngineOnExt[] = {"jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\uh80_ghosthawk\ext_start.ogg",1,1,300};
        soundEngineOnInt[] = {"jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\uh80_ghosthawk\int_start.ogg",1,1};

        armor = 560; //Default 140

        hiddenSelections[] = {"camo1","clan","clan_text","insignia"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\nightingale\data\textures\ONI_nightingale_base_co.paa)
        };
        icon = "\OPTRE_Vehicles_Air\Falcon\data\icon.paa";
    };
};