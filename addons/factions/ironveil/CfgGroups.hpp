class CfgGroups {
    class East {
        class FACTION(IRON) {
            name = "[505th] Ironveil PMC";

            class CLASS(IRON_Infantry) {
                name = "Infantry";

                class IRON_RifleSquad {
                    faction = QFACTION(IRON);
                    name = "Ironveil Rifle Squad";
                    icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
                    side = OPFOR;

                    class Object0 {
                        side = OPFOR;
                        vehicle = QCLASS(IRON_Unit_SL);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        vehicle = QCLASS(IRON_Unit_Rifleman);
                        rank = "PRIVATE";
                        position[] = {5, -5, 0};
                    };
                    class Object2: Object1 {
                        position[] = {-5, -5, 0};
                    };
                    class Object3: Object1 {
                        vehicle = QCLASS(IRON_Unit_Autorifleman);
                        rank = "CORPORAL";
                        position[] = {10, -10, 0};
                    };
                    class Object4: Object1 {
                        vehicle = QCLASS(IRON_Unit_Marksman);
                        position[] = {-10, -10, 0};
                    };
                    class Object5: Object1 {
                        vehicle = QCLASS(IRON_Unit_Medic);
                        position[] = {15, -15, 0};
                    };
                    class Object6: Object1 {
                        position[] = {-15, -15, 0};
                    };
                };

                class IRON_AntiArmorSquad: IRON_RifleSquad {
                    name = "Ironveil Anti-Armor Squad";
                    icon = "\A3\ui_f\data\map\markers\nato\o_mech_inf.paa";

                    class Object0: Object0 {};
                    class Object1: Object1 {};
                    class Object2: Object2 {};
                    class Object3: Object3 {
                        vehicle = QCLASS(IRON_Unit_AT);
                    };
                    class Object4: Object4 {
                        vehicle = QCLASS(IRON_Unit_AT);
                    };
                    class Object5: Object5 {};
                    class Object6: Object6 {};
                };

                // Standalone, NOT derived from IRON_RifleSquad: Arma counts inherited
                // Object4..Object6 too, so a derived 4-man team would still spawn 7.
                class IRON_FireTeam {
                    faction = QFACTION(IRON);
                    name = "Ironveil Fire Team";
                    icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
                    side = OPFOR;

                    class Object0 {
                        side = OPFOR;
                        vehicle = QCLASS(IRON_Unit_SL);
                        rank = "CORPORAL";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        vehicle = QCLASS(IRON_Unit_Rifleman);
                        rank = "PRIVATE";
                        position[] = {5, -5, 0};
                    };
                    class Object2: Object1 {
                        position[] = {-5, -5, 0};
                    };
                    class Object3: Object1 {
                        vehicle = QCLASS(IRON_Unit_Autorifleman);
                        position[] = {10, -10, 0};
                    };
                };
            };
        };
    };
};
