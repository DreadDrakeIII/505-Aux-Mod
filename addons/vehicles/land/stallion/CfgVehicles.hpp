class CfgVehicles {
    class OPTRE_m1087_stallion_unsc;
    class OPTRE_m1087_stallion_cover_unsc;
    class B_Truck_01_ammo_F;
    class OPTRE_m1087_stallion_unsc_refuel;
    class OPTRE_m1087_stallion_unsc_repair;
    class OPTRE_m1087_stallion_unsc_medical;
    class OPTRE_m1087_stallion_device_unsc;
    class CLASS(Stallion_Open_Transport): OPTRE_m1087_stallion_unsc {
        SCOPE_PUBLIC;
        displayName = "M1087 Stallion";
        hiddenSelections[] = {"Camo1","Camo2","Camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT1_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT2_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_Cargo_co.paa)
        };
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCrew = QCLASS(Marine_Rifleman_CE);
    };
    class CLASS(Stallion_Covered_Transport): OPTRE_m1087_stallion_cover_unsc {
        SCOPE_PUBLIC;
        displayName = "M1087 Stallion (Covered)";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT1_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT2_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_Cargo_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_Cover_co.paa)
        };
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCrew = QCLASS(Marine_Rifleman_CE);
    };
    class CLASS(Stallion_Ammo): B_Truck_01_ammo_F {
        SCOPE_PUBLIC;
        displayName = "M1087 Stallion (Ammo)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCrew = QCLASS(Marine_Rifleman_CE);
        model = "\A3\Soft_F_EPC\Truck_03\Truck_03_box_F.p3d";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT1_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT2_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_Cargo_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Containers_co.paa)
        };
    };
    class CLASS(Stallion_Refuel): OPTRE_m1087_stallion_unsc_refuel {
        SCOPE_PUBLIC;
        displayName = "M1087 Stallion (Fuel)";
        hiddenSelections[] = {"Camo1","Camo2","Camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT1_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT2_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_Fuel_co.paa)
        };
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCrew = QCLASS(Marine_Rifleman_CE);
    };
    class CLASS(Stallion_Repair): OPTRE_m1087_stallion_unsc_repair {
        SCOPE_PUBLIC;
        displayName = "M1087 Stallion (Repair)";
        hiddenSelections[] = {"Camo1","Camo2","Camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT1_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT2_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_Repair_co.paa)
        };
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCrew = QCLASS(Marine_Rifleman_CE);
    };
    class CLASS(Stallion_Medical): OPTRE_m1087_stallion_unsc_medical {
        SCOPE_PUBLIC;
        displayName = "M1087 Stallion (Medical)";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT1_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT2_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_Cargo_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_Cover_co.paa)
        };
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCrew = QCLASS(Marine_Rifleman_CE);
    };
    class CLASS(Stallion_Device): OPTRE_m1087_stallion_device_unsc {
        SCOPE_PUBLIC;
        displayName = "M1087 Stallion (Device)";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4","Camo5"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT1_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_EXT2_co.paa),
            QPATHTOF(land\stallion\data\textures\505th_Stallion_Cargo_co.paa),
            "\A3\Structures_F_EPC\Items\Electronics\Data\The_Device_02_CO.paa",
            "\A3\Structures_F_EPC\Items\Electronics\Data\The_Device_03_CO.paa"
        };
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCrew = QCLASS(Marine_Rifleman_CE);
    };
};
