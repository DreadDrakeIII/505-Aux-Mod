class CfgVehicles {
    class OPTRE_UNSC_falcon_S;
    class OPTRE_UNSC_falcon_armed;
    class Components;

    class CLASS(Falcon): OPTRE_UNSC_falcon_S {
        SCOPE_PUBLIC;

        displayName = "UH-144 Falcon";

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
    };
        class CLASS(Falcon_Armed): OPTRE_UNSC_falcon_armed {
        SCOPE_PUBLIC;

        displayName = "UH-144 Falcon Armed";

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

        class Components: Components {
            class TransportPylonsComponent {
                UIPicture = "\optre_vehicles_air\falcon\FalconPylonPic.paa";
                class pylons {
                    class WingPylonRight {
                        hardpoints[] = {"OPTRE_Hardpoint_UH144_Upper"};
                        attachment = "OPTRE_16Rnd_Anvil1_missiles";
                        bay = -1;
                        priority = 4;
                        UIposition[] = {0.1, 0.2};
                        turret[] = {-1};
                    };
                    class BellyPylonRight: WingPylonRight {
                        hardpoints[] = {"OPTRE_Hardpoint_UH144_Lower"};
                        attachment = "OPTRE_8Rnd_Anvil1_missiles";
                        priority = 3;
                        UIposition[] = {0.2, 0.40000001};
                    };
                    class WingPylonLeft: WingPylonRight {
                        UIposition[] = {"0.1+0.45", 0.2};
                        mirroredMissilePos = 1;
                    };
                    class BellyPylonLeft: BellyPylonRight {
                        mirroredMissilePos = 2;
                        UIposition[] = {"0.2+0.25", 0.40000001};
                    };
                    class Nose {
                        hardpoints[] = {"OPTRE_Hardpoint_UH144_Nose"};
                        attachment = "OPTRE_AIE_4000Rnd_762x51_M118_Belt_Tracer_Red_Pylon";
                        bay = -1;
                        priority = 4;
                        UIposition[] = {"0.2+0.125", 0.44999999};
                        turret[] = {-1};
                    };
                };
                class Presets {
                    class Default {
                        displayName = "Empty";
                        attachment[] = {};
                    };
                    class AnvilMissiles {
                        displayName = "CAS: Anvil I Missiles";
                        attachment[] = {
                            "OPTRE_16Rnd_Anvil1_missiles",
                            "OPTRE_8Rnd_Anvil1_missiles",
                            "OPTRE_16Rnd_Anvil1_missiles",
                            "OPTRE_8Rnd_Anvil1_missiles",
                            "OPTRE_AIE_4000Rnd_762x51_M118_Belt_Tracer_Red_Pylon"
                        };
                    };
                    class Chaingun {
                        displayName = "CAS: Chaingun Pods";
                        attachment[] = {
                            "OPTRE_Minigun_Pylon_AP_x2000_Magazine",
                            "OPTRE_Minigun_Pylon_HE_x1000_Magazine",
                            "OPTRE_Minigun_Pylon_AP_x2000_Magazine",
                            "OPTRE_Minigun_Pylon_HE_x1000_Magazine",
                            "OPTRE_AIE_4000Rnd_762x51_M118_Belt_Tracer_Red_Pylon"
                        };
                    };
                    class Mortar {
                        displayName = "Mortar Dropper";
                        attachment[] = {
                            "OPTRE_5Rnd_Mortar_Bomb_Pylon",
                            "OPTRE_5Rnd_Mortar_Bomb_Pylon",
                            "OPTRE_5Rnd_Mortar_Bomb_Pylon",
                            "OPTRE_5Rnd_Mortar_Bomb_Pylon",
                            "OPTRE_AIE_4000Rnd_762x51_M118_Belt_Tracer_Red_Pylon"
                        };
                    };
                    class Stealth {
                        displayName = "Stealth";
                        attachment[] = {
                            "OPTRE_AN_ALE_407_198Rnd_Chaff_Pylon",
                            "OPTRE_AN_ALE_407_198Rnd_Flare_Pylon",
                            "OPTRE_AN_ALE_407_198Rnd_Flare_Pylon",
                            "OPTRE_AN_ALE_407_198Rnd_Chaff_Pylon",
                            "OPTRE_SearchLight_Pylon"
                        };
                    };
                };
            };
        };
    };
};
