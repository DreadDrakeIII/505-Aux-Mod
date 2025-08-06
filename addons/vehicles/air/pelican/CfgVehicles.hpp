class CfgVehicles {
    class Helicopter_Base_H;
    class Splits_Pelican_base: Helicopter_Base_H {
    };
    class Splits_UNSC_D77_TC_Pelican: Splits_Pelican_base {
        class Turrets;
    };
    class CLASS(Pelican_Base): Splits_UNSC_D77_TC_Pelican {
        scope = 1;
        scopeCurator = 1;
        displayName = "D77-TC Pelican (Base)";
        side = BLUFOR;
        faction = QFACTION(505th);
        crew = QCLASS(Marine_Heli_Pilot);
        editorSubcategory = QEDSUBCAT(Helicopters);
        GetInAction = "pilot_Heli_Light_02_Enter";
        GetOutAction = "pilot_Heli_Light_02_Exit";
        weapons[] = {
            "CMFlareLauncher",
            "Splits_missiles_Anvil1"
        };
        magazines[] = {
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "Splits_60Rnd_Anvil1_missiles",
            "Splits_60Rnd_Anvil1_missiles",
            "Splits_60Rnd_Anvil1_missiles",
            "Splits_60Rnd_Anvil1_missiles",
            "Splits_60Rnd_Anvil1_missiles",
            "Laserbatteries"
        };

        hiddenSelections[] = {"camo1","camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\pelican\data\textures\505th_Pelican_body_co.paa),
            QPATHTOF(air\pelican\data\textures\505th_Pelican_wings_and_gear_co.paa),
            QPATHTOF(air\pelican\data\textures\505th_Pelican_weaponry_co.paa)
        };
        textureList[] = {"Main", 1, "HA2Green", 0, "HA2Grey", 0, "HA2White", 0, "HW2Green", 0, "HW2Grey", 0, "HW2White", 0};
        class TextureSources {
            class Main {
                author = AUTHOR;
                displayName = "505th";
                factions[] = {};
                textures[] = {
                    QPATHTOF(air\pelican\data\textures\505th_Pelican_body_co.paa),
                    QPATHTOF(air\pelican\data\textures\505th_Pelican_wings_and_gear_co.paa),
                    QPATHTOF(air\pelican\data\textures\505th_Pelican_weaponry_co.paa)
                };
            };
            class HA2Green: Main {
                displayName = "HA2 Green";
                textures[] = {
                    "Splits\Splits_Vehicles\Pelican\data\H2_General\body_co.paa",
                    "Splits\Splits_Vehicles\Pelican\data\H2_General\wings_and_gear_co.paa",
                    "Splits\Splits_Vehicles\Pelican\data\H2_General\weaponry_co.paa"
                };
            };
            class HA2Grey: Main {
                displayName = "HA2 Grey";
                textures[] = {
                    "Splits\Splits_Vehicles\Pelican\data\H2_grey\body_co.paa",
                    "Splits\Splits_Vehicles\Pelican\data\H2_grey\wings_and_gear_co.paa",
                    "Splits\Splits_Vehicles\Pelican\data\H2_grey\weaponry_co.paa"
                };
            };
            class HA2White: Main {
                displayName = "HA2 White";
                textures[] = {
                    "Splits\Splits_Vehicles\Pelican\data\H2_General_winter\body_co.paa",
                    "Splits\Splits_Vehicles\Pelican\data\H2_General_winter\wings_and_gear_co.paa",
                    "Splits\Splits_Vehicles\Pelican\data\H2_General_winter\weaponry_co.paa"
                };
            };
            class HW2Green: Main {
                displayName = "HW2 Green";
                textures[] = {
                    "Splits\Splits_Vehicles\Pelican\data\HW2\body_co.paa",
                    "Splits\Splits_Vehicles\Pelican\data\HW2\wings_and_gear_co.paa",
                    "Splits\Splits_Vehicles\Pelican\data\HW2\weaponry_co.paa"
                };
            };
            class HW2Grey: Main {
                displayName = "HW2 Grey";
                textures[] = {
                    "Splits\Splits_Vehicles\Pelican\data\HW2_grey\body_co.paa",
                    "Splits\Splits_Vehicles\Pelican\data\HW2_grey\wings_and_gear_co.paa",
                    "Splits\Splits_Vehicles\Pelican\data\HW2_grey\weaponry_co.paa"
                };
            };
            class HW2White: Main {
                displayName = "HW2 White";
                textures[] = {
                    "Splits\Splits_Vehicles\Pelican\data\HW2_winter\body_co.paa",
                    "Splits\Splits_Vehicles\Pelican\data\HW2_winter\wings_and_gear_co.paa",
                    "Splits\Splits_Vehicles\Pelican\data\HW2_winter\weaponry_co.paa"
                };
            };
        };

        class Turrets: Turrets {
            class CargoTurret_01;
            class CargoTurret_02;
            class CargoTurret_03;
            class CargoTurret_04;
            class CargoTurret_05;
            class CargoTurret_06;
            class CargoTurret_07;
            class CargoTurret_08;
            class CargoTurret_09;
            class CargoTurret_10;
            class CargoTurret_11;
            class CargoTurret_12;
            class CargoTurret_13;
            class CargoTurret_14;
            class CargoTurret_15;
            class MainTurret;
            class RearDoorGun;
        };
        icon = "OPTRE_Vehicles\Pelican\Data\icon.paa";
    };

    class CLASS(Pelican): CLASS(Pelican_Base) {
        scope = 2;
        scopeCurator = 2;
        author = AUTHOR;

        displayName = "D77-TC Pelican";
        class Turrets: Turrets {
            class CargoTurret_01: CargoTurret_01 {};
            class CargoTurret_02: CargoTurret_02 {};
            class CargoTurret_03: CargoTurret_03 {};
            class CargoTurret_04: CargoTurret_04 {};
            class CargoTurret_05: CargoTurret_05 {};
            class CargoTurret_06: CargoTurret_06 {};
            class CargoTurret_07: CargoTurret_07 {};
            class CargoTurret_08: CargoTurret_08 {};
            class CargoTurret_09: CargoTurret_09 {};
            class CargoTurret_10: CargoTurret_10 {};
            class CargoTurret_11: CargoTurret_11 {};
            class CargoTurret_12: CargoTurret_12 {};
            class CargoTurret_13: CargoTurret_13 {};
            class CargoTurret_14: CargoTurret_14 {};
            class CargoTurret_15: CargoTurret_15 {};
            class MainTurret: MainTurret {};
            class RearDoorGun: RearDoorGun {
                gunnerType = QCLASS(Marine_Rifleman_CE);
            };
        };
    };
};
