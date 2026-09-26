class CfgVehicles {
    class B_Plane_Fighter_01_F;
    class Components;

    // Adds the Thermobaric preset to the Warhawk's pylon preset list.
    // Re-opening rules (must match warhawk\CfgVehicles.hpp exactly):
    //   - CLASS(Warhawk) and Components keep their colon parents.
    //   - TransportPylonsComponent and Presets are re-opened WITHOUT a parent,
    //     because the Warhawk defines them without one. Adding ": Presets" here
    //     would re-parent them onto the vanilla Black Wasp versions and pull the
    //     vanilla presets/pylons back in.
    class CLASS(Warhawk): B_Plane_Fighter_01_F {
        class Components: Components {
            class TransportPylonsComponent {
                class Presets {
                    class Bomb_Thermobaric {
                        displayName = "Bomb Run: Thermobaric";
                        attachment[] = {
                            "FIR_AIM9X_LAU115_P_1rnd_M",            // Wingtip R
                            "FIR_AIM9X_LAU115_P_1rnd_M",            // Wingtip L
                            "PHAN_FAEBomb_Unguided_Heavy_Mag_x4",   // Wing R
                            "PHAN_FAEBomb_Unguided_Heavy_Mag_x4",   // Wing L
                            "FIR_AIM9X_P_1rnd_M",                   // Bay side R
                            "FIR_AIM9X_P_1rnd_M",                   // Bay side L
                            "FIR_GBU54_P_1rnd_M",                   // Centre 1
                            "FIR_GBU54_P_1rnd_M",                   // Centre 2
                            "FIR_GBU54_P_1rnd_M",                   // Centre 3
                            "FIR_GBU54_P_1rnd_M",                   // Centre 4
                            "FIR_GBU54_P_1rnd_M",                   // Centre 5
                            "FIR_GBU54_P_1rnd_M"                    // Centre 6
                        };
                    };
                };
            };
        };
    };
};
