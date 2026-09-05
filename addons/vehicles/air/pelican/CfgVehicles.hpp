class CfgVehicles {
    class Helicopter_Base_H;
    class Splits_Pelican_base: Helicopter_Base_H {
    };
    class Splits_UNSC_D77_TC_Pelican: Splits_Pelican_base {
        class Turrets;
    };
    class CLASS(Pelican_Base): Splits_UNSC_D77_TC_Pelican {
        SCOPE_HIDDEN;
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
                    "Foundries\Splits_Vehicles\Pelican\data\H2_General\body_co.paa",
                    "Foundries\Splits_Vehicles\Pelican\data\H2_General\wings_and_gear_co.paa",
                    "Foundries\Splits_Vehicles\Pelican\data\H2_General\weaponry_co.paa"
        };
        textureList[] = {"HA2Green", 1, "HA2Grey", 0, "HA2White", 0, "HW2Green", 0, "HW2Grey", 0, "HW2White", 0};
        class TextureSources {
            class HA2Green {
                displayName = "HA2 Green";
                textures[] = {
                    "Foundries\Splits_Vehicles\Pelican\data\H2_General\body_co.paa",
                    "Foundries\Splits_Vehicles\Pelican\data\H2_General\wings_and_gear_co.paa",
                    "Foundries\Splits_Vehicles\Pelican\data\H2_General\weaponry_co.paa"
                };
            };
            class HA2Grey: HA2Green {
                displayName = "HA2 Grey";
                textures[] = {
                    "Foundries\Splits_Vehicles\Pelican\data\H2_grey\body_co.paa",
                    "Foundries\Splits_Vehicles\Pelican\data\H2_grey\wings_and_gear_co.paa",
                    "Foundries\Splits_Vehicles\Pelican\data\H2_grey\weaponry_co.paa"
                };
            };
            class HA2White: HA2Green {
                displayName = "HA2 White";
                textures[] = {
                     "Foundries\Splits_Vehicles\Pelican\data\H2_General_winter\body_co.paa",
                     "Foundries\Splits_Vehicles\Pelican\data\H2_General_winter\wings_and_gear_co.paa",
                     "Foundries\Splits_Vehicles\Pelican\data\H2_General_winter\weaponry_co.paa"
                };
            };
            class HW2Green: HA2Green {
                displayName = "HW2 Green";
                textures[] = {
                    "Foundries\Splits_Vehicles\Pelican\data\HW2\body_co.paa",
                    "Foundries\Splits_Vehicles\Pelican\data\HW2\wings_and_gear_co.paa",
                    "Foundries\Splits_Vehicles\Pelican\data\HW2\weaponry_co.paa"
                };
            };
            class HW2Grey: HA2Green {
                displayName = "HW2 Grey";
                textures[] = {
                     "Foundries\Splits_Vehicles\Pelican\data\HW2_grey\body_co.paa",
                     "Foundries\Splits_Vehicles\Pelican\data\HW2_grey\wings_and_gear_co.paa",
                     "Foundries\Splits_Vehicles\Pelican\data\HW2_grey\weaponry_co.paa"
                };
            };
            class HW2White: HA2Green {
                displayName = "HW2 White";
                textures[] = {
                     "Foundries\Splits_Vehicles\Pelican\data\HW2_winter\body_co.paa",
                     "Foundries\Splits_Vehicles\Pelican\data\HW2_winter\wings_and_gear_co.paa",
                     "Foundries\Splits_Vehicles\Pelican\data\HW2_winter\weaponry_co.paa"
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
        SCOPE_PUBLIC;
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
                gunnerType = QCLASS(Marine_CE_Rifleman);
            };
        };
    };
    class CLASS(Innie_Pelican): CLASS(Pelican_Base) {
        SCOPE_PUBLIC;
        displayName = "[Innie] D77-TC Pelican";
        side = OPFOR;
        faction = QFACTION(Innie);
        crew = "TCP_O_INS_M_Soldier_Engineer";
        editorSubcategory = QEDSUBCAT(Helicopters);
        hiddenSelectionsTextures[] = {
            QPATHTOEF(factions,innie\data\pelican\Body_co.paa),
            QPATHTOEF(factions,innie\data\pelican\Wings_co.paa),
            QPATHTOEF(factions,innie\data\pelican\Weaponry_co.paa)
        };
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
                gunnerType = "TCP_O_INS_M_Soldier_Engineer";
            };
        };
    };
};
