class CfgVehicles {
    class B_Plane_Fighter_01_F;
    class CLASS(Warhawk): B_Plane_Fighter_01_F {
        SCOPE_PUBLIC;
        displayName = "F/A-40 Warhawk";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Planes);
        crew = QCLASS(Marine_Jet_Pilot);
        typicalCargo[] = {QCLASS(Marine_Jet_Pilot)};
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

    class CLASS(Cursed_Warhawk): B_Plane_Fighter_01_F {
        SCOPE_PUBLIC;
        displayName = "F/A-404 Cursed Warhawk";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Planes);
        crew = QCLASS(Marine_Jet_Pilot);
        typicalCargo[] = {QCLASS(Marine_Jet_Pilot)};
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
