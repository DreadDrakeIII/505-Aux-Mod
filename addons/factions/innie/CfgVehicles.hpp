class CfgVehicles {
    //===============================
    // G42 RENZAN BOMBER
    //===============================
    class SC_Fixed_Bomber_01;
    class CLASS(G42_Renzan_Base): SC_Fixed_Bomber_01 {
        SCOPE_HIDDEN;
        displayName = "G42 Renzan Heavy Bomber (Base)";
        side = OPFOR;
        faction = QFACTION(Innie);
        crew = "TCP_O_INS_M_Soldier_Engineer";
        editorSubcategory = QEDSUBCAT(Planes);
        hiddenSelections[] = {"camo1","camo2"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(innie\data\g42\Body_co.paa),
            QPATHTOF(innie\data\g42\Details_co.paa)
        };
    };

    class CLASS(G42_Renzan): CLASS(G42_Renzan_Base) {
        SCOPE_PUBLIC;
        displayName = "[Innie] G42 Renzan Heavy Bomber";
    };

    //===============================
    // K172 PANTHER
    //===============================
    class Components;
    class TransportPylonsComponent;
    class pylons;
    class Presets;
    class I_Plane_Fighter_04_F;
    class CLASS(K172_Panther_Base): I_Plane_Fighter_04_F {
        SCOPE_HIDDEN;
        displayName = "K172 Panther (Base)";
        side = OPFOR;
        faction = QFACTION(Innie);
        crew = "TCP_O_INS_M_Soldier_Engineer";
        editorSubcategory = QEDSUBCAT(Planes);
        hiddenSelections[] = {"Camo_01","Camo_02","Camo_03","number_01","number_02","number_03"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(innie\data\k172_panther\K172_Panther_fuselage_01_co.paa),
            QPATHTOF(innie\data\k172_panther\K172_Panther_fuselage_02_co.paa),
            QPATHTOF(innie\data\k172_panther\K172_Panther_misc_01_co.paa),
            "a3\air_f_jets\plane_fighter_04\data\Numbers\Fighter_04_number_04_ca.paa",
            "a3\air_f_jets\plane_fighter_04\data\Numbers\Fighter_04_number_04_ca.paa",
            "a3\air_f_jets\plane_fighter_04\data\Numbers\Fighter_04_number_08_ca.paa"
        };
    };

    class CLASS(K172_Panther_AA): CLASS(K172_Panther_Base) {
        SCOPE_PUBLIC;
        displayName = "[Innie] K172 Panther (AIM-X9)";
        class Components: Components {
            class TransportPylonsComponent: TransportPylonsComponent {
                class pylons: pylons {
                    class pylon1 { attachment = "PylonMissile_Missile_BIM9X_x1"; };
                    class pylon2 { attachment = "PylonMissile_Missile_BIM9X_x1"; };
                    class pylon3 { attachment = ""; };
                    class Pylon4 { attachment = ""; };
                    class pylon5 { attachment = ""; };
                    class Pylon6 { attachment = ""; };
                };
                class Presets: Presets {
                    class Empty;
                    class Default {
                        displayName = "AIM-X9 Loadout";
                        attachment[] = {
                            "PylonMissile_Missile_BIM9X_x1",
                            "PylonMissile_Missile_BIM9X_x1",
                            "","","",""
                        };
                    };
                    class AA: Default {};
                    class AT: Default {};
                    class CAS: Default {};
                };
            };
        };
    };

    // Gun only - every pylon cleared, every preset resolves to Empty.
    class CLASS(K172_Panther_Gun): CLASS(K172_Panther_Base) {
        SCOPE_PUBLIC;
        displayName = "[Innie] K172 Panther (Gun)";
        class Components: Components {
            class TransportPylonsComponent: TransportPylonsComponent {
                class pylons: pylons {
                    class pylon1 { attachment = ""; };
                    class pylon2 { attachment = ""; };
                    class pylon3 { attachment = ""; };
                    class Pylon4 { attachment = ""; };
                    class pylon5 { attachment = ""; };
                    class Pylon6 { attachment = ""; };
                };
                class Presets: Presets {
                    class Empty;
                    class Default: Empty {};
                    class AA: Empty {};
                    class AT: Empty {};
                    class CAS: Empty {};
                };
            };
        };
    };
};
