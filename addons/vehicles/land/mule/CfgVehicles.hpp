class CfgVehicles {
    class OPTRE_m1015_mule_ins;
    class OPTRE_m1015_mule_cover_ins;
    class OPTRE_m1015_mule_mlr_ins;
    class OPTRE_m1015_mule_ammo_ins;
    class OPTRE_m1015_mule_fuel_ins;
    class OPTRE_m1015_mule_medical_ins;
    class OPTRE_m1015_mule_repair_ins;
    class CLASS(Mule_Transport): OPTRE_m1015_mule_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Cab_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Kuz_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Interior_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Chassis_2_co.paa)
        };
    };
    class CLASS(Mule_Covered): OPTRE_m1015_mule_cover_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule (Covered)";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Cab_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Kuz_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Interior_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Chassis_2_co.paa)
        };
    };

    class CLASS(Mule_MRL): OPTRE_m1015_mule_mlr_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule (MLR)";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Cab_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Interior_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_MRL_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Chassis_2_co.paa)
        };
    };

    class CLASS(Mule_Ammo): OPTRE_m1015_mule_ammo_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule (Ammo)";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Cab_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Repair_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Interior_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Chassis_2_co.paa)
        };
    };

    class CLASS(Mule_Fuel): OPTRE_m1015_mule_fuel_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule (Fuel)";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Cab_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Fuel_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Interior_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Chassis_2_co.paa)
        };
    };

    class CLASS(Mule_Medical): OPTRE_m1015_mule_medical_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule (Medical)";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Cab_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Kuz_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Interior_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Chassis_2_co.paa)
        };
    };

    class CLASS(Mule_Repair): OPTRE_m1015_mule_repair_ins {
        SCOPE_PUBLIC;

        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);

        displayName = "M1015 Mule (Repair)";
        crew = QCLASS(Wolf_Rifleman);
        side = OPFOR;

        terrainCoef = 2.5;
        maxSpeed = 120;
        enginePower = 412;

        hiddenSelections[] ={"Camo1","Camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Cab_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Repair_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Interior_co.paa),
            QPATHTOF(land\mule\data\textures\Artemis_Mule_Chassis_2_co.paa)
        };
    };
};
