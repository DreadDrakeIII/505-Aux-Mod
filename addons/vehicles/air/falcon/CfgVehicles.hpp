class CfgVehicles {
    class Helicopter_Base_H;
    class Heli_Light_01_base_F: Helicopter_Base_H{};
    class OPTRE_falcon_base: Heli_Light_01_base_F{};
    class OPTRE_falcon_base_unarmed: OPTRE_falcon_base{};
    class OPTRE_UNSC_falcon: OPTRE_falcon_base_unarmed{
        class Turrets;
    };
    class CLASS(Falcon_Base): OPTRE_UNSC_falcon {
        scope = 1;
        scopeCurator = 1;

        displayName = "UH-144 Falcon (Base)";

        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        gunnerType = QCLASS(Marine_Heli_Crew);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        armor = 180;
        magazines[] = {
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "Laserbatteries"
        };

        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "camoGlass",
            "camoGlassPilot",
            "camoDecal",
            "attach_gun",
            "attach_sideguns"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Main_co.paa),
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Attachments_co.paa),
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Interior_co.paa),
            "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa",
            "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa",
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Decal_ca.paa)
        };
        textureList[] = {"Main", 1, "Standard", 0, "Black", 0, "White", 0, "Tan", 0, "Green", 0, "Pink", 0};
        class TextureSources {
            class Main {
                author = AUTHOR;
                displayName = "505th";
                factions[] = {};
                textures[] = {
                    QPATHTOF(air\falcon\data\textures\505th_Falcon_Main_co.paa),
                    QPATHTOF(air\falcon\data\textures\505th_Falcon_Attachments_co.paa),
                    QPATHTOF(air\falcon\data\textures\505th_Falcon_Interior_co.paa),
                    "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa",
                    "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa",
                    QPATHTOF(air\falcon\data\textures\505th_Falcon_Decal_ca.paa)
                };
            };
            class Standard: Main {
                displayName = " Standard";
                textures[] = {
                    "\OPTRE_Vehicles_Air\falcon\data\falcon_main_co.paa",
                    "\OPTRE_Vehicles_Air\falcon\data\falcon_attachments_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Falcon_Interior_co.paa"
                };
            };
            class Black: Main {
                displayName = "Black";
                textures[] = {
                    "\OPTRE_Vehicles_Air\Falcon\data\Black\Falcon_Main_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Black\Falcon_Attachments_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Falcon_Interior_co.paa"
                };
            };
            class White: Main {
                displayName = "White";
                textures[] = {
                    "\OPTRE_Vehicles_Air\Falcon\data\White\Falcon_Main_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\White\Falcon_Attachments_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Falcon_Interior_co.paa"
                };
            };
            class Tan: Main {
                displayName = "Tan";
                textures[] = {
                    "\OPTRE_Vehicles_Air\Falcon\data\Tan\Falcon_Main_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Tan\Falcon_Attachments_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Falcon_Interior_co.paa"
                };
            };
            class Green: Main {
                displayName = "Green";
                textures[] = {
                    "\OPTRE_Vehicles_Air\Falcon\data\Green\Falcon_Main_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Green\Falcon_Attachments_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Falcon_Interior_co.paa"
                };
            };
            class Pink: Main {
                displayName = "Pink";
                textures[] = {
                    "\OPTRE_Vehicles_Air\Falcon\data\Pink\Falcon_Main_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Pink\Falcon_Attachments_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Falcon_Interior_co.paa"
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
            class CopilotTurret;
            class LeftDoorGun;
            class MainTurret;
            class RightDoorGun;
        };
    };

    class CLASS(Falcon): CLASS(Falcon_Base) {
        SCOPE_PUBLIC;

        displayName = "UH-144 Falcon";

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
            class CopilotTurret: CopilotTurret {};
            class LeftDoorGun: LeftDoorGun {};
            class MainTurret: MainTurret {};
            class RightDoorGun: RightDoorGun {};
        };
    };


    class OPTRE_UNSC_falcon_S: OPTRE_falcon_base{
        class Turrets;
    };
    class CLASS(Falcon_Armed_Base): OPTRE_UNSC_falcon_S {
        scope = 1;
        scopeCurator = 1;

        displayName = "UH-144S Falcon (Base)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        gunnerType = QCLASS(Marine_Heli_Crew);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        armor = 180;
        magazines[] = {
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "Laserbatteries"
        };

        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "camoGlass",
            "camoGlassPilot",
            "camoDecal",
            "attach_gun",
            "attach_sideguns"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Main_co.paa),
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Attachments_co.paa),
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Interior_co.paa),
            "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa",
            "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa",
            QPATHTOF(air\falcon\data\textures\505th_Falcon_Decal_ca.paa)
        };
        textureList[] = {"Main", 1, "Standard", 0, "Black", 0, "White", 0, "Tan", 0, "Green", 0, "Pink", 0};
        class TextureSources {
            class Main {
                author = AUTHOR;
                displayName = "505th";
                factions[] = {};
                textures[] = {
                    QPATHTOF(air\falcon\data\textures\505th_Falcon_Main_co.paa),
                    QPATHTOF(air\falcon\data\textures\505th_Falcon_Attachments_co.paa),
                    QPATHTOF(air\falcon\data\textures\505th_Falcon_Interior_co.paa),
                    "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa",
                    "\optre_vehicles_air\falcon\data\falcon_glass_ca.paa",
                    QPATHTOF(air\falcon\data\textures\505th_Falcon_Decal_ca.paa)
                };
            };
            class Standard: Main {
                displayName = " Standard";
                textures[] = {
                    "\OPTRE_Vehicles_Air\falcon\data\falcon_main_co.paa",
                    "\OPTRE_Vehicles_Air\falcon\data\falcon_attachments_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Falcon_Interior_co.paa"
                };
            };
            class Black: Main {
                displayName = "Black";
                textures[] = {
                    "\OPTRE_Vehicles_Air\Falcon\data\Black\Falcon_Main_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Black\Falcon_Attachments_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Falcon_Interior_co.paa"
                };
            };
            class White: Main {
                displayName = "White";
                textures[] = {
                    "\OPTRE_Vehicles_Air\Falcon\data\White\Falcon_Main_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\White\Falcon_Attachments_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Falcon_Interior_co.paa"
                };
            };
            class Tan: Main {
                displayName = "Tan";
                textures[] = {
                    "\OPTRE_Vehicles_Air\Falcon\data\Tan\Falcon_Main_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Tan\Falcon_Attachments_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Falcon_Interior_co.paa"
                };
            };
            class Green: Main {
                displayName = "Green";
                textures[] = {
                    "\OPTRE_Vehicles_Air\Falcon\data\Green\Falcon_Main_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Green\Falcon_Attachments_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Falcon_Interior_co.paa"
                };
            };
            class Pink: Main {
                displayName = "Pink";
                textures[] = {
                    "\OPTRE_Vehicles_Air\Falcon\data\Pink\Falcon_Main_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Pink\Falcon_Attachments_co.paa",
                    "\OPTRE_Vehicles_Air\Falcon\data\Falcon_Interior_co.paa"
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
            class CopilotTurret;
            class LeftDoorGun;
            class MainTurret;
            class RightDoorGun;
        };
    };

    class CLASS(Falcon_Armed): CLASS(Falcon_Armed_Base) {
        scope = 2;
        scopeCurator = 2;

        displayName = "UH-144S Falcon";

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
            class CopilotTurret: CopilotTurret {};
            class LeftDoorGun: LeftDoorGun {
                gunnerType = QCLASS(Marine_Rifleman_CE);
            };
            class MainTurret: MainTurret {};
            class RightDoorGun: RightDoorGun {
                gunnerType = QCLASS(Marine_Rifleman_CE);
            };
        };
    };
};
