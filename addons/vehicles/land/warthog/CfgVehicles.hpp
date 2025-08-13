class CfgVehicles {
    class OPTRE_M12_LRV;
    class CLASS(Warthog_LRV): OPTRE_M12_LRV {
        SCOPE_PUBLIC;

        displayName = "M12 LAAG Warthog";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCargo[] = {QCLASS(Marine_Rifleman_CE)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "camo_details",
            "camo_interior",
            "camo_turret_decal",
            "camo_sight",
            "camo_doors"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extupper_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extunder_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_m12_turret_co.paa),
            "",
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_interior_co.paa),
            "",
            "\OPTRE_Vehicles\warthog\data\turrets\sight_co.paa",
            QPATHTOF(land\warthog\data\textures\505th_apc_lopo_co.paa)
        };
    };

    class OPTRE_M12A1_LRV;
    class CLASS(Warthog_AT_LRV): OPTRE_M12A1_LRV {
        SCOPE_PUBLIC;

        displayName = "M12A1 AT Warthog";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCargo[] = {QCLASS(Marine_Rifleman_CE)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "camo_details",
            "camo_interior",
            "camo_turret",
            "camo_turret_decals",
            "camo_doors"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extupper_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extunder_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_m12_turret_co.paa),
            "",
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_interior_co.paa),
            "\OPTRE_Vehicles\warthog\data\turrets\m39_turret_co.paa",
            "",
            QPATHTOF(land\warthog\data\textures\505th_apc_lopo_co.paa)
        };
    };

    class OPTRE_M12G1_LRV;
    class CLASS(Warthog_Gauss_LRV): OPTRE_M12G1_LRV {
        SCOPE_PUBLIC;

        displayName = "M12G1 Gauss Warthog";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCargo[] = {QCLASS(Marine_Rifleman_CE)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "Camo4",
            "camo_details",
            "camo_interior",
            "camo_doors"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extupper_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extunder_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_m68_turret_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_m12_turret_co.paa),
            "",
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_interior_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_apc_lopo_co.paa)
        };
    };

    class OPTRE_M12R_AA;
    class CLASS(Warthog_AA): OPTRE_M12R_AA {
        SCOPE_PUBLIC;

        displayName = "M12R AA Warthog";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCargo[] = {QCLASS(Marine_Rifleman_CE)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "camo_details",
            "camo_interior",
            "camo_doors"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extupper_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extunder_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_m79_turret_co.paa),
            "",
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_interior_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_apc_lopo_co.paa)
        };
    };

    class OPTRE_M12_FAV;
    class CLASS(Warthog_FAV): OPTRE_M12_FAV {
        SCOPE_PUBLIC;

        displayName = "M12 FAV Warthog";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCargo[] = {QCLASS(Marine_Rifleman_CE)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "camo_details",
            "camo_interior",
            "camo_doors"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extupper_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extunder_co.paa),
            "",
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_interior_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_apc_lopo_co.paa),
        };
    };

    class OPTRE_M12_FAV_APC;
    class CLASS(Warthog_FAV_APC): OPTRE_M12_FAV_APC {
        SCOPE_PUBLIC;

        displayName = "M12 APC Warthog";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCargo[] = {QCLASS(Marine_Rifleman_CE)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "Camo4",
            "camo_details",
            "camo_interior",
            "camo_transport_details",
            "camo_net"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extupper_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extunder_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_transp_lopo_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_apc_lopo_co.paa),
            "",
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_interior_co.paa),
            "",
            "\OPTRE_Vehicles\warthog\data\warthog_transport_net_ca.paa"
        };
    };

    class OPTRE_M12_FAV_APC_MED;
    class CLASS(Warthog_APC_MED): OPTRE_M12_FAV_APC_MED {
        SCOPE_PUBLIC;

        displayName = "M12 APC Medical Warthog";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCargo[] = {QCLASS(Marine_Rifleman_CE)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "Camo4",
            "camo_details",
            "camo_interior",
            "camo_transport_details",
            "camo_net",
            "camo_medical"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extupper_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extunder_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_transp_lopo_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_apc_lopo_co.paa),
            "",
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_interior_co.paa),
            "",
            "\OPTRE_Vehicles\warthog\data\warthog_transport_net_ca.paa",
            "\OPTRE_Vehicles\warthog\data\medical_lopo_co.paa"
        };
    };

    class OPTRE_M813_TT;
    class CLASS(Warthog_TT): OPTRE_M813_TT {
        SCOPE_PUBLIC;

        displayName = "M813 Troop Transport";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Marine_Rifleman_CE);
        typicalCargo[] = {QCLASS(Marine_Rifleman_CE)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "camo_details",
            "camo_interior",
            "camo_net",
            "camo_transport_decal"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extupper_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_extunder_co.paa),
            QPATHTOF(land\warthog\data\textures\505th_transp_lopo_co.paa),
            "",
            QPATHTOF(land\warthog\data\textures\505th_M12HogMaav_interior_co.paa),
            "",
            "\OPTRE_Vehicles\warthog\data\warthog_transport_net_ca.paa",
            ""
        };
    };

    class OPTRE_M12_LRV_ins;
    class CLASS(ARTE_Warthog_LRV): OPTRE_M12_LRV_ins {
        SCOPE_PUBLIC;

        displayName = "M12 LAAG Warthog";
        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Wolf_Rifleman);
        typicalCargo[] = {QCLASS(Wolf_Rifleman)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "camo_details",
            "camo_interior",
            "camo_turret_decal",
            "camo_sight",
            "camo_doors"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\warthog\data\textures\Artemis_M12HogMaav_extupper_co.paa),
            "\OPTRE_Vehicles\Warthog\data\night\M12HogMaav_extunder_night_co.paa",
            QPATHTOF(land\warthog\data\textures\Artemis_m12_turret_co.paa),
            "",
            "\OPTRE_Vehicles\warthog\data\m12hogmaav_interior_co.paa",
            "",
            "\OPTRE_Vehicles\warthog\data\turrets\sight_co.paa",
            ""
        };
    };

    class OPTRE_M12A1_LRV_ins;
    class CLASS(ARTE_Warthog_AT_LRV): OPTRE_M12A1_LRV_ins {
        SCOPE_PUBLIC;

        displayName = "M12A1 AT Warthog";
        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Wolf_Rifleman);
        typicalCargo[] = {QCLASS(Wolf_Rifleman)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "camo_details",
            "camo_interior",
            "camo_turret",
            "camo_turret_decals",
            "camo_doors"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\warthog\data\textures\Artemis_M12HogMaav_extupper_co.paa),
            "\OPTRE_Vehicles\Warthog\data\night\M12HogMaav_extunder_night_co.paa",
            QPATHTOF(land\warthog\data\textures\Artemis_m12_turret_co.paa),
            "",
            "\OPTRE_Vehicles\warthog\data\m12hogmaav_interior_co.paa",
            "\OPTRE_Vehicles\warthog\data\turrets\m39_turret_co.paa",
            "",
            "",
        };
    };

    class OPTRE_M12_TD_ins;
    class CLASS(ARTE_Warthog_TD_LRV): OPTRE_M12_TD_ins {
        SCOPE_PUBLIC;

        displayName = "M12 TD Warthog";
        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Wolf_Rifleman);
        typicalCargo[] = {QCLASS(Wolf_Rifleman)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "Camo4",
            "Camo5",
            "Camo6",
            "camo_details",
            "camo_interior",
            "camo_console"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\warthog\data\textures\Artemis_M12HogMaav_extupper_co.paa),
            "\OPTRE_Vehicles\Warthog\data\night\M12HogMaav_extunder_night_co.paa",
            "\OPTRE_Vehicles\Warthog\data\night\transp_lopo_night_co.paa",
            "\OPTRE_Vehicles\Warthog\data\night\hog_apc_night_co.paa",
            "\OPTRE_Weapons_Turrets\fg75\data\cannon_co.paa",
            "\OPTRE_Weapons_Turrets\fg75\data\carriage_co.paa",
            "",
            "\OPTRE_Vehicles\Warthog\data\m12hogmaav_interior_co.paa",
            "\OPTRE_Weapons_Turrets\fg75\data\console_co.paa"

        };
    };

    class OPTRE_M12R_AA_ins;
    class CLASS(ARTE_Warthog_AA): OPTRE_M12R_AA_ins {
        SCOPE_PUBLIC;

        displayName = "M12R AA Warthog";
        faction = QFACTION(ARTE);
        editorSubcategory = QEDSUBCAT(Cars);
        crew = QCLASS(Wolf_Rifleman);
        typicalCargo[] = {QCLASS(Wolf_Rifleman)};
        hiddenSelections[] = {
            "Camo1",
            "Camo2",
            "Camo3",
            "camo_details",
            "camo_interior",
            "camo_doors"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\warthog\data\textures\Artemis_M12HogMaav_extupper_co.paa),
            "\OPTRE_Vehicles\Warthog\data\night\M12HogMaav_extunder_night_co.paa",
            QPATHTOF(land\warthog\data\textures\Artemis_m79_turret_co.paa),
            "",
            "\OPTRE_Vehicles\warthog\data\m12hogmaav_interior_co.paa",
            ""
        };
    };
};
