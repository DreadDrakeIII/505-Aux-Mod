class CfgVehicles {
    class Helicopter_Base_H;
    class Heli_Transport_01_base_F: Helicopter_Base_H{};
    class B_Heli_Transport_01_F: Heli_Transport_01_base_F{
        class Turrets;
    };
    class CLASS(Ghosthawk_Base): B_Heli_Transport_01_F {
        SCOPE_PRIVATE;

        displayName = "UH-240 Ghost Hawk(Base)";
        faction = QFACTION(ONI);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        gunnerType = QCLASS(Marine_Heli_Crew);
        hiddenSelections[] = {
            "camo1",
            "camo2"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\ghosthawk\data\textures\ONI_heli_transport_01_ext01_CO.paa),
            QPATHTOF(air\ghosthawk\data\textures\ONI_heli_transport_01_ext02_CO.paa)
        };

        textureList[] = {"Main", 0, "ONI", 1};
        class TextureSources {
            class Main {
                author = AUTHOR;
                displayName = "505th";
                factions[] = {};
                textures[] = {
                    QPATHTOF(air\ghosthawk\data\textures\505th_heli_transport_01_ext01_CO.paa),
                    QPATHTOF(air\ghosthawk\data\textures\505th_heli_transport_01_ext02_CO.paa)
                };
            };
            class ONI: Main {
                displayName = "ONI";
                textures[] = {
                    QPATHTOF(air\ghosthawk\data\textures\ONI_heli_transport_01_ext01_CO.paa),
                    QPATHTOF(air\ghosthawk\data\textures\ONI_heli_transport_01_ext02_CO.paa)
                };
            };
        };

        class Turrets: Turrets {
            class CopilotTurret;
            class MainTurret;
            class PassengerTurret_01;
            class PassengerTurret_02;
            class PassengerTurret_03;
            class PassengerTurret_04;
            class RightDoorGun;
        };
    };

    class CLASS(ONI_GhostHawk): CLASS(Ghosthawk_Base) {
        SCOPE_PUBLIC;

        displayName = "UH-240 Ghost Hawk";

        class Turrets: Turrets {
            class CopilotTurret: CopilotTurret {};
            class MainTurret: MainTurret {
                gunnerType = QCLASS(Marine_Heli_Crew);
            };
            class PassengerTurret_01: PassengerTurret_01 {};
            class PassengerTurret_02: PassengerTurret_02 {};
            class PassengerTurret_03: PassengerTurret_03 {};
            class PassengerTurret_04: PassengerTurret_04 {};
            class RightDoorGun: RightDoorGun {
                gunnerType = QCLASS(Marine_Heli_Crew);
            };
        };
    };
};
