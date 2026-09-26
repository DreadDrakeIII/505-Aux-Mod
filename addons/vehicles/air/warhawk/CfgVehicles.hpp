class CfgVehicles {
    class B_Plane_Fighter_01_F;
    class Components;
    class CLASS(Warhawk): B_Plane_Fighter_01_F {
        SCOPE_PUBLIC;
        displayName = "F/A-40 Warhawk";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Planes);
        crew = QCLASS(Marine_Jet_Pilot);
        typicalCargo[] = {QCLASS(Marine_Jet_Pilot)};

        // --- Double the health ---
        armorLights = 5;        // Base is 1, x5
        armorStructural = 10;   // Base is 2, x5
        armor = 300;             // Base is 60, x5

        weapons[] = {
            QCLASS(Warhawk_Gun20mm),
            "Laserdesignator_pilotCamera",
            "CMFlareLauncher_Singles"
        };
        magazines[] = {
            QCLASS(Warhawk_Mag_Gun20mm_x3000),
            "Laserbatteries",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine"
        };
        // -------------------------

        hiddenSelectionsTextures[]=
		{
			QPATHTOF(air\warhawk\data\textures\fighter_01_fuselage_01_co_2.paa),
			QPATHTOF(air\warhawk\data\textures\fighter_01_fuselage_02_co_2.paa),
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_glass_01_ca.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_01_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_02_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_03_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_05_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_03_ca.paa",
			"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_01_ca.paa"
			//"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_01_ca.paa"
		};

        class Components: Components {
            class TransportPylonsComponent {
                UIPicture = "\A3\Air_F_Jets\Plane_Fighter_01\Data\UI\Fighter_01_3DEN_CA.paa";
                class pylons {
                    class pylon1 {
                        hardpoints[] = {QCLASS(Warhawk_HP_Wingtip)};
                        attachment = "FIR_AIM9X_LAU115_P_1rnd_M";
                        priority = 12;
                        maxweight = 300;
                        UIposition[] = {0.6, 0.45};
                    };
                    class pylon2: pylon1 {
                        UIposition[] = {0.05, 0.45};
                        mirroredMissilePos = 1;
                    };
                    class pylon3 {
                        hardpoints[] = {QCLASS(Warhawk_HP_Wing)};
                        attachment = "FIR_Hydra_LAU130_P_19rnd_M";
                        priority = 11;
                        maxweight = 1050;
                        UIposition[] = {0.55, 0.35};
                    };
                    class pylon4: pylon3 {
                        UIposition[] = {0.1, 0.35};
                        mirroredMissilePos = 3;
                    };
                    class pylonBayRight1 {
                        hardpoints[] = {QCLASS(Warhawk_HP_BaySide)};
                        attachment = "FIR_AIM9X_P_1rnd_M";
                        priority = 10;
                        maxweight = 1200;
                        UIposition[] = {0.5, 0.25};
                        bay = 2;
                    };
                    class pylonBayLeft1: pylonBayRight1 {
                        UIposition[] = {0.16, 0.25};
                        mirroredMissilePos = 5;
                        bay = 1;
                    };
                    class pylonBayCenter1 {
                        hardpoints[] = {QCLASS(Warhawk_HP_BayCenter)};
                        attachment = "FIR_AIM9X_P_1rnd_M";
                        priority = 9;
                        maxweight = 1200;
                        UIposition[] = {0.33, 0.3};
                        bay = 3;
                    };
                    class pylonBayCenter2: pylonBayCenter1 {
                        UIposition[] = {0.33, 0.35};
                        mirroredMissilePos = 7;
                    };
                    class pylonBayCenter3 {
                        hardpoints[] = {QCLASS(Warhawk_HP_BayCenter)};
                        attachment = "FIR_AIM9X_P_1rnd_M";
                        priority = 7;
                        maxweight = 1200;
                        UIposition[] = {0.33, 0.4};
                        bay = 3;
                    };
                    class pylonBayCenter4: pylonBayCenter3 {
                        UIposition[] = {0.33, 0.45};
                        mirroredMissilePos = 9;
                    };
                    class pylonBayCenter5 {
                        hardpoints[] = {QCLASS(Warhawk_HP_BayCenter)};
                        attachment = "FIR_GBU54_P_1rnd_M";
                        priority = 5;
                        maxweight = 1200;
                        UIposition[] = {0.33, 0.5};
                        bay = 3;
                    };
                    class pylonBayCenter6: pylonBayCenter5 {
                        UIposition[] = {0.33, 0.55};
                        mirroredMissilePos = 11;
                    };
                };
                class Bays {
                    class BayLeft1 {
                        bayOpenTime = 0.5;
                        openBayWhenWeaponSelected = 0;
                        autoCloseWhenEmptyDelay = 2;
                    };
                    class BayRight1 {
                        bayOpenTime = 0.5;
                        openBayWhenWeaponSelected = 0;
                        autoCloseWhenEmptyDelay = 2;
                    };
                    class BayCenter1 {
                        bayOpenTime = 0.5;
                        openBayWhenWeaponSelected = 0;
                        autoCloseWhenEmptyDelay = 3;
                    };
                };

                class Presets {
                    class Empty {
                        displayName = "$STR_empty";
                        attachment[] = {};
                    };
                    class Default {
                        displayName = "$STR_vehicle_default";
                        attachment[] = {
                            "FIR_AIM9X_LAU115_P_1rnd_M",
                            "FIR_AIM9X_LAU115_P_1rnd_M",
                            "FIR_Hydra_LAU130_P_19rnd_M",
                            "FIR_Hydra_LAU130_P_19rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M"
                        };
                    };

                    class AA {
                        displayName = "Air Superiority";
                        attachment[] = {
                            "FIR_AIM9X_LAU115_P_1rnd_M",    // Wingtip R
                            "FIR_AIM9X_LAU115_P_1rnd_M",    // Wingtip L
                            "FIR_AIM9X_LAU115_P_2rnd_M",    // Wing R
                            "FIR_AIM9X_LAU115_P_2rnd_M",    // Wing L
                            "FIR_AIM9X_P_1rnd_M",           // Bay side R
                            "FIR_AIM9X_P_1rnd_M",           // Bay side L
                            "FIR_AIM9X_P_1rnd_M",           // Centre 1
                            "FIR_AIM9X_P_1rnd_M",           // Centre 2
                            "FIR_AIM9X_P_1rnd_M",           // Centre 3
                            "FIR_AIM9X_P_1rnd_M",           // Centre 4
                            "FIR_AIM9X_P_1rnd_M",           // Centre 5
                            "FIR_AIM9X_P_1rnd_M"            // Centre 6
                        };
                    };
                    class CAS_Rockets {
                        displayName = "CAS: Rockets";
                        attachment[] = {
                            "FIR_AIM9X_LAU115_P_1rnd_M",
                            "FIR_AIM9X_LAU115_P_1rnd_M",
                            "FIR_Hydra_LAU130_P_19rnd_M",
                            "FIR_Hydra_LAU130_P_19rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_AGM114_Base_P_4rnd_M",
                            "FIR_AGM114_Base_P_4rnd_M",
                            "FIR_AGM114_Base_P_4rnd_M",
                            "FIR_AGM114_Base_P_4rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M"
                        };
                    };
                    class CAS_Hellfire {
                        displayName = "CAS: Hellfire";
                        attachment[] = {
                            "FIR_AIM9X_LAU115_P_1rnd_M",
                            "FIR_AIM9X_LAU115_P_1rnd_M",
                            "FIR_AGM114_Base_P_4rnd_M",
                            "FIR_AGM114_Base_P_4rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_AGM114_Base_P_4rnd_M",
                            "FIR_AGM114_Base_P_4rnd_M",
                            "FIR_AGM114_Base_P_4rnd_M",
                            "FIR_AGM114_Base_P_4rnd_M",
                            "FIR_AGM114_Base_P_4rnd_M",
                            "FIR_AGM114_Base_P_4rnd_M"
                        };
                    };
                    class Bomb_Heavy {
                        displayName = "Bomb Run: Heavy (GBU-56)";
                        attachment[] = {
                            "FIR_AIM9X_LAU115_P_1rnd_M",
                            "FIR_AIM9X_LAU115_P_1rnd_M",
                            "FIR_GBU56_P_1rnd_M",
                            "FIR_GBU56_P_1rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M"
                        };
                    };
                    class Bomb_Medium {
                        displayName = "Bomb Run: Medium (GBU-55)";
                        attachment[] = {
                            "FIR_AIM9X_LAU115_P_1rnd_M",
                            "FIR_AIM9X_LAU115_P_1rnd_M",
                            "FIR_GBU55_P_1rnd_M",
                            "FIR_GBU55_P_1rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M"
                        };
                    };
                    class Bomb_Precision {
                        displayName = "Bomb Run: Precision (GBU-54)";
                        attachment[] = {
                            "FIR_AIM9X_LAU115_P_1rnd_M",
                            "FIR_AIM9X_LAU115_P_1rnd_M",
                            "FIR_GBU54_P_3rnd_M",
                            "FIR_GBU54_P_3rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M"
                        };
                    };
                    class Stealth {
                        displayName = "Stealth Strike (internal only)";
                        attachment[] = {
                            "",
                            "",
                            "",
                            "",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_AIM9X_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M",
                            "FIR_GBU54_P_1rnd_M"
                        };
                    };
                };
            };
        };
        // -------------------------
    };

    class CLASS(Cursed_Warhawk): B_Plane_Fighter_01_F {
        SCOPE_PUBLIC;
        displayName = "F/A-404 Cursed Warhawk";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Planes);
        crew = QCLASS(Marine_Jet_Pilot);
        typicalCargo[] = {QCLASS(Marine_Jet_Pilot)};

        // --- Double the health ---
        armorLights = 5;        // Base is 1, x5
        armorStructural = 10;   // Base is 2, x5
        armor = 300;             // Base is 60, x5
        // -------------------------

        weapons[]=
		{
			"Gatling_30mm_Plane_CAS_01_F",
			"Laserdesignator_pilotCamera",
			"CMFlareLauncher_Singles",
		};
		magazines[]=
		{
			"1000Rnd_Gatling_30mm_Plane_CAS_01_F",
			"1000Rnd_Gatling_30mm_Plane_CAS_01_F",
            "1000Rnd_Gatling_30mm_Plane_CAS_01_F",
            "MG8_1174Rnd_Gau8_30mm",
            "MG8_1174Rnd_Gau8_30mm",
            "MG8_1174Rnd_Gau8_30mm",
			"Laserbatteries",
			"240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine"
		};
        hiddenSelectionsTextures[]=
		{
			QPATHTOF(air\warhawk\data\textures\fighter_01_fuselage_01_co_2.paa),
			QPATHTOF(air\warhawk\data\textures\fighter_01_fuselage_02_co_2.paa),
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_glass_01_ca.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_01_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_02_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_03_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_05_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_03_ca.paa",
			"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_01_ca.paa"
			//"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_01_ca.paa"
		};
    };

    class B_Plane_Fighter_01_Stealth_F;
    class CLASS(StealthHawk): B_Plane_Fighter_01_Stealth_F {
        SCOPE_PUBLIC;
        displayName = "F/A-41 Stealth Hawk";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Planes);
        crew = QCLASS(Marine_Jet_Pilot);
        typicalCargo[] = {QCLASS(Marine_Jet_Pilot)};

        // --- Double the health ---
        armorLights = 5;        // Base is 1, x5
        armorStructural = 10;   // Base is 2, x5
        armor = 300;             // Base is 60, x5
        // -------------------------

        weapons[]=
		{
			"weapon_Fighter_Gun20mm_AA",
			"Laserdesignator_pilotCamera",
			"CMFlareLauncher_Singles",
		};
		magazines[]=
		{
			"magazine_Fighter01_Gun20mm_AA_x450",
			"magazine_Fighter01_Gun20mm_AA_x450",
			"Laserbatteries",
			"240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine"
		};
        hiddenSelectionsTextures[]=
		{
			QPATHTOF(air\warhawk\data\textures\fighter_01_fuselage_01_co.paa),
			QPATHTOF(air\warhawk\data\textures\fighter_01_fuselage_02_co.paa),
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_glass_01_ca.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_01_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_02_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_03_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_05_co.paa",
			"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_03_ca.paa",
			"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_01_ca.paa"
			//"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_01_ca.paa"
		};
    };
};
