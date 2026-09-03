class CfgGroups {
    class East {
        class FACTION(ARTE) {
            name = "[505th] Artemis";

            /////////////////////////// Wolf - line infantry ///////////////////////////
            class CLASS(ARTE_Wolf_INF) {
                name = "Infantry - Wolf";

                class ARTE_Wolf_RifleSquad {
                    faction = QFACTION(ARTE);
                    name = "Wolf Rifle Squad";
                    icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
                    side = OPFOR;

                    class Object0 {
                        side = OPFOR;
                        vehicle = QCLASS(Wolf_Rifleman);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        rank = "CORPORAL";
                        position[] = {5, -5, 0};
                    };
                    class Object2: Object0 {
                        rank = "PRIVATE";
                        position[] = {-5, -5, 0};
                    };
                    class Object3: Object2 {
                        position[] = {10, -10, 0};
                    };
                    class Object4: Object2 {
                        vehicle = QCLASS(Wolf_Grenadier);
                        position[] = {-10, -10, 0};
                    };
                    class Object5: Object2 {
                        vehicle = QCLASS(Wolf_Marksman);
                        position[] = {15, -15, 0};
                    };
                    class Object6: Object2 {
                        vehicle = QCLASS(Wolf_AT);
                        position[] = {-15, -15, 0};
                    };
                };

                class ARTE_Wolf_AssaultSquad: ARTE_Wolf_RifleSquad {
                    name = "Wolf Assault Squad";
                    class Object0: Object0 {};
                    class Object1: Object1 {};
                    class Object2: Object2 {};
                    class Object3: Object3 {};
                    class Object4: Object4 {};
                    class Object5: Object5 {
                        vehicle = QCLASS(Wolf_Grenadier);
                    };
                    class Object6: Object6 {
                        vehicle = QCLASS(Wolf_Rifleman);
                    };
                };

                class ARTE_Wolf_AntiTankSquad: ARTE_Wolf_RifleSquad {
                    name = "Wolf Anti-Tank Squad";
                    icon = "\A3\ui_f\data\map\markers\nato\o_mech_inf.paa";
                    class Object0: Object0 {};
                    class Object1: Object1 {};
                    class Object2: Object2 {};
                    class Object3: Object3 {
                        vehicle = QCLASS(Wolf_AT);
                    };
                    class Object4: Object4 {
                        vehicle = QCLASS(Wolf_AT);
                    };
                    class Object5: Object5 {};
                    class Object6: Object6 {};
                };

                class ARTE_Wolf_AntiAirSquad: ARTE_Wolf_RifleSquad {
                    name = "Wolf Anti-Air Squad";
                    icon = "\A3\ui_f\data\map\markers\nato\o_support.paa";
                    class Object0: Object0 {};
                    class Object1: Object1 {};
                    class Object2: Object2 {};
                    class Object3: Object3 {
                        vehicle = QCLASS(Wolf_AA);
                    };
                    class Object4: Object4 {
                        vehicle = QCLASS(Wolf_AA);
                    };
                    class Object5: Object5 {};
                    class Object6: Object6 {};
                };

                class ARTE_Wolf_FireTeam {
                    faction = QFACTION(ARTE);
                    name = "Wolf Fire Team";
                    icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
                    side = OPFOR;

                    class Object0 {
                        side = OPFOR;
                        vehicle = QCLASS(Wolf_Rifleman);
                        rank = "CORPORAL";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        rank = "PRIVATE";
                        position[] = {5, -5, 0};
                    };
                    class Object2: Object1 {
                        vehicle = QCLASS(Wolf_Grenadier);
                        position[] = {-5, -5, 0};
                    };
                    class Object3: Object1 {
                        vehicle = QCLASS(Wolf_Marksman);
                        position[] = {10, -10, 0};
                    };
                };
            };

            //////////////////////// Jager - special forces ////////////////////////
            class CLASS(ARTE_Jager_INF) {
                name = "Special Forces - Jager";

                class ARTE_Jager_Team {
                    faction = QFACTION(ARTE);
                    name = "Jager Team";
                    icon = "\A3\ui_f\data\map\markers\nato\o_recon.paa";
                    side = OPFOR;

                    class Object0 {
                        side = OPFOR;
                        vehicle = QCLASS(Jager_Rifleman);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        rank = "CORPORAL";
                        position[] = {5, -5, 0};
                    };
                    class Object2: Object0 {
                        rank = "PRIVATE";
                        position[] = {-5, -5, 0};
                    };
                    class Object3: Object2 {
                        vehicle = QCLASS(Jager_LMG);
                        position[] = {10, -10, 0};
                    };
                    class Object4: Object2 {
                        vehicle = QCLASS(Jager_AT);
                        position[] = {-10, -10, 0};
                    };
                    class Object5: Object2 {
                        vehicle = QCLASS(Jager_Sniper);
                        position[] = {15, -15, 0};
                    };
                    class Object6: Object2 {
                        vehicle = QCLASS(Jager_Bismark);
                        position[] = {-15, -15, 0};
                    };
                };

                class ARTE_Jager_AssaultTeam: ARTE_Jager_Team {
                    name = "Jager Assault Team";
                    class Object0: Object0 {};
                    class Object1: Object1 {};
                    class Object2: Object2 {};
                    class Object3: Object3 {};
                    class Object4: Object4 {};
                    class Object5: Object5 {
                        vehicle = QCLASS(Jager_Bismark);
                    };
                    class Object6: Object6 {};
                };

                class ARTE_Jager_ReconTeam {
                    faction = QFACTION(ARTE);
                    name = "Jager Recon Team";
                    icon = "\A3\ui_f\data\map\markers\nato\o_recon.paa";
                    side = OPFOR;

                    class Object0 {
                        side = OPFOR;
                        vehicle = QCLASS(Jager_Rifleman);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        rank = "PRIVATE";
                        vehicle = QCLASS(Jager_LMG);
                        position[] = {5, -5, 0};
                    };
                    class Object2: Object1 {
                        vehicle = QCLASS(Jager_Sniper);
                        position[] = {-5, -5, 0};
                    };
                    class Object3: Object1 {
                        vehicle = QCLASS(Jager_Rifleman);
                        position[] = {10, -10, 0};
                    };
                };

                class ARTE_Jager_SniperTeam {
                    faction = QFACTION(ARTE);
                    name = "Jager Sniper Team";
                    icon = "\A3\ui_f\data\map\markers\nato\o_recon.paa";
                    side = OPFOR;

                    class Object0 {
                        side = OPFOR;
                        vehicle = QCLASS(Jager_Sniper);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        vehicle = QCLASS(Jager_Rifleman);
                        rank = "CORPORAL";
                        position[] = {4, -4, 0};
                    };
                };
            };

            //////////////////////////// Motorized ////////////////////////////
            class CLASS(ARTE_Motorized) {
                name = "Motorized";

                class ARTE_Warthog_Patrol {
                    faction = QFACTION(ARTE);
                    name = "Warthog Patrol";
                    icon = "\A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
                    side = OPFOR;

                    class Object0 {
                        side = OPFOR;
                        vehicle = QCLASS(ARTE_Warthog_LRV);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        rank = "CORPORAL";
                        position[] = {0, -20, 0};
                    };
                };

                class ARTE_Warthog_AT_Section: ARTE_Warthog_Patrol {
                    name = "Warthog Anti-Tank Section";
                    class Object0: Object0 {};
                    class Object1: Object1 {
                        vehicle = QCLASS(ARTE_Warthog_AT_LRV);
                    };
                };

                class ARTE_Warthog_AA_Section: ARTE_Warthog_Patrol {
                    name = "Warthog Anti-Air Section";
                    icon = "\A3\ui_f\data\map\markers\nato\o_support.paa";
                    class Object0: Object0 {};
                    class Object1: Object1 {
                        vehicle = QCLASS(ARTE_Warthog_AA);
                    };
                };

                class ARTE_Warthog_HeavySection {
                    faction = QFACTION(ARTE);
                    name = "Warthog Heavy Section";
                    icon = "\A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
                    side = OPFOR;

                    class Object0 {
                        side = OPFOR;
                        vehicle = QCLASS(ARTE_Warthog_LRV);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        rank = "CORPORAL";
                        vehicle = QCLASS(ARTE_Warthog_TD_LRV);
                        position[] = {0, -20, 0};
                    };
                    class Object2: Object1 {
                        vehicle = QCLASS(ARTE_Warthog_AT_LRV);
                        position[] = {0, -40, 0};
                    };
                    class Object3: Object1 {
                        vehicle = QCLASS(ARTE_Warthog_AA);
                        position[] = {0, -60, 0};
                    };
                };

                class ARTE_Mule_LogisticsConvoy {
                    faction = QFACTION(ARTE);
                    name = "Mule Logistics Convoy";
                    icon = "\A3\ui_f\data\map\markers\nato\o_support.paa";
                    side = OPFOR;

                    class Object0 {
                        side = OPFOR;
                        vehicle = QCLASS(ARTE_Warthog_LRV);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        rank = "PRIVATE";
                        vehicle = QCLASS(Mule_Transport);
                        position[] = {0, -25, 0};
                    };
                    class Object2: Object1 {
                        vehicle = QCLASS(Mule_Ammo);
                        position[] = {0, -50, 0};
                    };
                    class Object3: Object1 {
                        vehicle = QCLASS(Mule_Fuel);
                        position[] = {0, -75, 0};
                    };
                    class Object4: Object1 {
                        vehicle = QCLASS(Mule_Medical);
                        position[] = {0, -100, 0};
                    };
                };
            };
        };
    };
};
