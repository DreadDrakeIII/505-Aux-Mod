class CfgVehicles {
    class OPTRE_M808BM_UNSC;
    class CLASS(Scorpion_MB): OPTRE_M808BM_UNSC {
        SCOPE_PUBLIC;

        displayName = "[505th] M808B/M Scorpion MBT";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Tanks);
        crew = QCLASS(Marine_Rifleman_CE);
        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "camo4",
            "camo5",
            "camo6",
            "camo7",
            "camo8"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\scorpion\data\textures\505th_scorp_lopo_co.paa),
            QPATHTOF(land\scorpion\data\textures\505th_scorp_tur_wood_co.paa),
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\det_3_co.paa",
            "",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\scorp_net_wood_ca.paa",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\scorp_net_wood_ca.paa",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\mine_roller_co.paa",
            QPATHTOF(land\scorpion\data\textures\505th_scorpion_mg_co.paa)
        };
    };
    class OPTRE_M808B_UNSC;
    class CLASS(Scorpion): OPTRE_M808B_UNSC {
        SCOPE_PUBLIC;

        displayName = "[505th] M808B Scorpion MBT";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Tanks);
        crew = QCLASS(Marine_Rifleman_CE);
        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "camo4",
            "camo5",
            "camo6",
            "camo7"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\scorpion\data\textures\505th_scorp_lopo_co.paa),
            QPATHTOF(land\scorpion\data\textures\505th_scorp_tur_wood_co.paa),
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\det_3_co.paa",
            "",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\scorp_net_wood_ca.paa",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\scorp_net_wood_ca.paa",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\mine_roller_co.paa"
        };
    };
    class OPTRE_M808R_Engineer_UNSC;
    class CLASS(Scorpion_Engineer): OPTRE_M808R_Engineer_UNSC {
        SCOPE_PUBLIC;

        displayName = "[505th] M808E Scorpion (Engineer)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Tanks);
        crew = QCLASS(Marine_Rifleman_CE);
        hiddenSelections[] = {
            "camo_body",
            "camo_decal",
            "camo_mg",
            "camo_net",
            "camo_crane",
            "camo_shove",
            "camo_roller"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\scorpion\data\textures\505th_scorp_lopo_co.paa),
            "",
            QPATHTOF(land\scorpion\data\textures\505th_scorpion_mg_co.paa),
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\scorp_net_wood_ca.paa",
            QPATHTOF(land\scorpion\data\textures\505th_scorp_crane_co.paa),
            QPATHTOF(land\scorpion\data\textures\505th_scorp_shove_co.paa),
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\mine_roller_co.paa"
        };
    };

    class OPTRE_M875_SPH;
    class CLASS(Scorpion_Arty): OPTRE_M875_SPH {
        SCOPE_PUBLIC;

        displayName = "[505th] M875 Scorpion Self Propelled Howitzer";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Artillery);
        crew = QCLASS(Marine_Rifleman_CE);
        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "camo4",
            "camo5",
            "camo6",
            "camo7",
            "camo8"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\scorpion\data\textures\505th_scorp_lopo_co.paa),
            QPATHTOF(land\scorpion\data\textures\505th_scorp_art_co.paa),
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\scorp_net_wood_ca.paa",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\scorp_art_camo_ca.paa",
            "",
            QPATHTOF(land\scorpion\data\textures\505th_scorpion_mg_co.paa),
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\det_1_lopo_co.paa",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\det_3_co.paa"
        };
    };

    class OPTRE_M808BM_UNSC_Driverless;
    class CLASS(Scorpion_MB_Single): OPTRE_M808BM_UNSC_Driverless {
        SCOPE_PUBLIC;

        displayName = "[505th] M808B/M Scorpion MBT (Single)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Tanks_Single);
        crew = QCLASS(Marine_Rifleman_CE);
        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "camo4",
            "camo5",
            "camo6",
            "camo7",
            "camo8"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\scorpion\data\textures\505th_scorp_lopo_co.paa),
            QPATHTOF(land\scorpion\data\textures\505th_scorp_tur_wood_co.paa),
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\det_3_co.paa",
            "",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\scorp_net_wood_ca.paa",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\scorp_net_wood_ca.paa",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\mine_roller_co.paa",
            ""
        };
    };
    class OPTRE_M808B_UNSC_Driverless;
    class CLASS(Scorpion_Single): OPTRE_M808B_UNSC_Driverless {
        SCOPE_PUBLIC;

        displayName = "[505th] M808B Scorpion MBT (Single)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Tanks_Single);
        crew = QCLASS(Marine_Rifleman_CE);
        hiddenSelections[] = {
            "camo1",
            "camo2",
            "camo3",
            "camo4",
            "camo5",
            "camo6",
            "camo7"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\scorpion\data\textures\505th_scorp_lopo_co.paa),
            QPATHTOF(land\scorpion\data\textures\505th_scorp_tur_wood_co.paa),
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\det_3_co.paa",
            "",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\scorp_net_wood_ca.paa",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\scorp_net_wood_ca.paa",
            "OPTRE_Vehicles_Tracked\Scorpion\data\texture\mine_roller_co.paa"
        };
    };
};
