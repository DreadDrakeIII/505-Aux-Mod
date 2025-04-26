class CfgVehicles {
    class B_Plane_CAS_01_dynamicLoadout_F;
    class CLASS(Condor): B_Plane_CAS_01_dynamicLoadout_F {
        displayName = "A-310 Condor";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Planes);
        crew = QCLASS(Marine_Pilot);
        weapons[]=
		{
			"Gatling_30mm_Plane_CAS_01_F",
			"Laserdesignator_pilotCamera",
		};
		magazines[]=
		{
			"1000Rnd_Gatling_30mm_Plane_CAS_01_F",
			"1000Rnd_Gatling_30mm_Plane_CAS_01_F",
            "1000Rnd_Gatling_30mm_Plane_CAS_01_F",
			"Laserbatteries",
			"240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
		};
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\condor\data\textures\plane_cas_01_ext01_505th_CO.paa),
            QPATHTOF(air\condor\data\textures\plane_cas_01_ext02_505th_CO)
        };
    };
};