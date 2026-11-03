class CfgGroups {
    class West {
        class FACTION(SOSE) {
            name = "[505th] Sosei";

            class CLASS(SOSE_Infantry) {
                name = "Infantry";

                class SOSE_RifleSquad {
                    faction = QFACTION(SOSE);
                    name = "Sosei Rifle Squad";
                    icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
                    side = BLUFOR;

                    class Object0 {
                        side = BLUFOR;
                        vehicle = QCLASS(SOSE_Officer);
                        rank = "LIEUTENANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "SERGEANT";
                        position[] = {5, -5, 0};
                    };
                    class Object2: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {-5, -5, 0};
                    };
                    class Object3: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {10, -10, 0};
                    };
                    class Object4: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {-10, -10, 0};
                    };
                    class Object5: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {15, -15, 0};
                    };
                    class Object6: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {-15, -15, 0};
                    };
                    class Object7: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {20, -20, 0};
                    };
                    class Object8: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {-20, -20, 0};
                    };
                };

                class SOSE_WeaponsSquad {
                    faction = QFACTION(SOSE);
                    name = "Sosei Weapons Squad";
                    icon = "\A3\ui_f\data\map\markers\nato\b_support.paa";
                    side = BLUFOR;

                    class Object0 {
                        side = BLUFOR;
                        vehicle = QCLASS(SOSE_Officer);
                        rank = "LIEUTENANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "SERGEANT";
                        position[] = {5, -5, 0};
                    };
                    class Object2: Object1 {
                        vehicle = QCLASS(SOSE_LMG);
                        rank = "CORPORAL";
                        position[] = {-5, -5, 0};
                    };
                    class Object3: Object1 {
                        vehicle = QCLASS(SOSE_LMG);
                        rank = "PRIVATE";
                        position[] = {10, -10, 0};
                    };
                    class Object4: Object1 {
                        vehicle = QCLASS(SOSE_LAT);
                        rank = "PRIVATE";
                        position[] = {-10, -10, 0};
                    };
                    class Object5: Object1 {
                        vehicle = QCLASS(SOSE_AA);
                        rank = "PRIVATE";
                        position[] = {15, -15, 0};
                    };
                    class Object6: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {-15, -15, 0};
                    };
                    class Object7: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {20, -20, 0};
                    };
                    class Object8: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {-20, -20, 0};
                    };
                };

                class SOSE_Patrol {
                    faction = QFACTION(SOSE);
                    name = "Sosei Patrol";
                    icon = "\A3\ui_f\data\map\markers\nato\b_recon.paa";
                    side = BLUFOR;

                    class Object0 {
                        side = BLUFOR;
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "CORPORAL";
                        position[] = {5, -5, 0};
                    };
                    class Object2: Object1 {
                        vehicle = QCLASS(SOSE_LMG);
                        rank = "PRIVATE";
                        position[] = {-5, -5, 0};
                    };
                    class Object3: Object1 {
                        vehicle = QCLASS(SOSE_LAT);
                        rank = "PRIVATE";
                        position[] = {10, -10, 0};
                    };
                };
            };

            class CLASS(SOSE_Armoured) {
                name = "Armoured";

                class SOSE_ArmoredPatrol {
                    faction = QFACTION(SOSE);
                    name = "Sosei Armored Patrol";
                    icon = "\A3\ui_f\data\map\markers\nato\b_armor.paa";
                    side = BLUFOR;

                    class Object0 {
                        side = BLUFOR;
                        vehicle = QCLASS(SOSE_Type142_IFV);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        vehicle = QCLASS(SOSE_Type142_APC);
                        rank = "CORPORAL";
                        position[] = {0, -25, 0};
                    };
                };

                class SOSE_IFVSection {
                    faction = QFACTION(SOSE);
                    name = "Sosei IFV Section";
                    icon = "\A3\ui_f\data\map\markers\nato\b_mech_inf.paa";
                    side = BLUFOR;

                    class Object0 {
                        side = BLUFOR;
                        vehicle = QCLASS(SOSE_Type142_IFV);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        vehicle = QCLASS(SOSE_Type142_IFV);
                        rank = "CORPORAL";
                        position[] = {0, -25, 0};
                    };
                };

                class SOSE_IFVXLRSection {
                    faction = QFACTION(SOSE);
                    name = "Sosei IFV/XLR Section";
                    icon = "\A3\ui_f\data\map\markers\nato\b_mech_inf.paa";
                    side = BLUFOR;

                    class Object0 {
                        side = BLUFOR;
                        vehicle = QCLASS(SOSE_Type142_IFV_XLR);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        vehicle = QCLASS(SOSE_Type142_IFV_XLR);
                        rank = "CORPORAL";
                        position[] = {0, -25, 0};
                    };
                };

                class SOSE_MortarSection {
                    faction = QFACTION(SOSE);
                    name = "Sosei Mortar Section";
                    icon = "\A3\ui_f\data\map\markers\nato\b_mortar.paa";
                    side = BLUFOR;

                    class Object0 {
                        side = BLUFOR;
                        vehicle = QCLASS(SOSE_Type142_SPG);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        vehicle = QCLASS(SOSE_Type142_SPG);
                        rank = "CORPORAL";
                        position[] = {0, -25, 0};
                    };
                };

                class SOSE_AASection {
                    faction = QFACTION(SOSE);
                    name = "Sosei AA Section";
                    icon = "\A3\ui_f\data\map\markers\nato\b_antiair.paa";
                    side = BLUFOR;

                    class Object0 {
                        side = BLUFOR;
                        vehicle = QCLASS(SOSE_Type142_AA);
                        rank = "SERGEANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        vehicle = QCLASS(SOSE_Type142_AA);
                        rank = "CORPORAL";
                        position[] = {0, -25, 0};
                    };
                };

                class SOSE_MechRifleSquad {
                    faction = QFACTION(SOSE);
                    name = "Sosei Mechanized Rifle Squad";
                    icon = "\A3\ui_f\data\map\markers\nato\b_mech_inf.paa";
                    side = BLUFOR;

                    class Object0 {
                        side = BLUFOR;
                        vehicle = QCLASS(SOSE_Officer);
                        rank = "LIEUTENANT";
                        position[] = {0, 0, 0};
                        dir = 0;
                    };
                    class Object1: Object0 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "SERGEANT";
                        position[] = {5, -5, 0};
                    };
                    class Object2: Object1 {
                        vehicle = QCLASS(SOSE_Type142_APC);
                        rank = "CORPORAL";
                        position[] = {0, 25, 0};
                    };
                    class Object3: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {-5, -5, 0};
                    };
                    class Object4: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {10, -10, 0};
                    };
                    class Object5: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {-10, -10, 0};
                    };
                    class Object6: Object1 {
                        vehicle = QCLASS(SOSE_Rifleman);
                        rank = "PRIVATE";
                        position[] = {15, -15, 0};
                    };
                    class Object7: Object1 {
                        vehicle = QCLASS(SOSE_LMG);
                        rank = "PRIVATE";
                        position[] = {-15, -15, 0};
                    };
                    class Object8: Object1 {
                        vehicle = QCLASS(SOSE_LAT);
                        rank = "PRIVATE";
                        position[] = {20, -20, 0};
                    };
                };
            };
        };
    };
};
