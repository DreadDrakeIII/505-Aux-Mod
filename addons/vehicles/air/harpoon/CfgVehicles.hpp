class CfgVehicles {
    class Helicopter_Base_H;
    class Heli_Transport_03_base_F: Helicopter_Base_H {
        class Turrets;
        class pilotCamera;
    };
    class CLASS(Harpoon_Base): Heli_Transport_03_base_F {
        scope = 1;
        scopeCurator = 1;
        displayName = "CH-447 Harpoon (Base)";
        side = BLUFOR;
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        gunnerType = QCLASS(Marine_Heli_Crew);
        typicalCargo[] = {QCLASS(Marine_Heli_Crew)};
        armor = 100; //Default 40
        hiddenSelections[] = {
            "camo1",
            "camo2"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\harpoon\data\textures\heli_transport_03_ext01_co.paa),
            QPATHTOF(air\harpoon\data\textures\heli_transport_03_ext02_co.paa)
        };
        textureList[] = {"Main", 1, "Green", 0, "Black", 0};
        class TextureSources {
            class Main {
                author = AUTHOR;
                displayName = "505th";
                factions[] = {};
                textures[] = {
                    QPATHTOF(air\harpoon\data\textures\heli_transport_03_ext01_co.paa),
                    QPATHTOF(air\harpoon\data\textures\heli_transport_03_ext02_co.paa)
                };
            };
            class Green: Main {
                displayName = "Green";
                textures[] = {
                    "\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext01_co.paa",
                    "\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_co.paa"
                };
            };
            class Black: Main {
                displayName = "Black";
                textures[] = {
                    "\A3\Air_F_Heli\Heli_Transport_03\Data\Heli_Transport_03_ext01_black_CO.paa",
                    "\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_black_co.paa"
                };
            };
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
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "Laserbatteries",
            "Laserbatteries",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
			"SmokeLauncherMag",
		};

        class Turrets: Turrets {
            class CargoTurret_01;
            class CargoTurret_02;
            class CoPilotTurret;
            class MainTurret;
            class RightDoorGun;
        };

        class pilotCamera: pilotCamera {
            initTurn = 0;
            initElev = -10;
            maxTurn = 180;
            minTurn = -180;
            maxElev = 90;
            minElev = -10;

            maxXRotSpeed = 0.3;
            maxYRotSpeed = 0.3;

            ace_missileguidance_usePilotCameraForTargeting = TRUE;
        };
    };
    class CLASS(Harpoon): CLASS(Harpoon_Base) {
        scope = 2;
        scopeCurator = 2;
        author = AUTHOR;

        displayName = "CH-447 Harpoon";
        class Turrets: Turrets {
            class CargoTurret_01: CargoTurret_01 {};
            class CargoTurret_02: CargoTurret_02 {};
            class CoPilotTurret: CoPilotTurret {};
            class MainTurret: MainTurret {
                gunnerType = QCLASS(Marine_Heli_Crew);
            };
            class RightDoorGun: RightDoorGun {
                gunnerType = QCLASS(Marine_Heli_Crew);
            };
        };
    };
};
