class CfgMagazines {
    class VehicleMagazine;
    class magazine_Fighter01_Gun20mm_AA_x450;

    // --- Gun ---
    class CLASS(Warhawk_Mag_Gun20mm_x3000): magazine_Fighter01_Gun20mm_AA_x450 {
        displayName = "20 mm x3000";
        descriptionShort = "Rounds: 3000";
        count = 3000;
    };

    // AIM-9X
    class FIR_AIM9X_P_1rnd_M: VehicleMagazine {
        hardpoints[] += {QCLASS(Warhawk_HP_BaySide), QCLASS(Warhawk_HP_BayCenter)};
    };
    class FIR_AIM9X_LAU115_P_1rnd_M: FIR_AIM9X_P_1rnd_M {
        hardpoints[] += {QCLASS(Warhawk_HP_Wingtip), QCLASS(Warhawk_HP_Wing)};
    };
    class FIR_AIM9X_LAU115_P_2rnd_M: FIR_AIM9X_P_1rnd_M {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing)};
    };

    // Hydra 70 (M151 HE)
    class FIR_Hydra_P_7rnd_M: VehicleMagazine {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing)};
    };
    class FIR_Hydra_P_14rnd_M: FIR_Hydra_P_7rnd_M {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing)};
    };
    class FIR_Hydra_LAU130_P_19rnd_M: FIR_Hydra_P_7rnd_M {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing)};
    };

    // GBU-54 LJDAM (250 lb)
    class FIR_GBU54_P_1rnd_M: VehicleMagazine {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing), QCLASS(Warhawk_HP_BayCenter)};
    };
    class FIR_GBU54_P_2rnd_M: FIR_GBU54_P_1rnd_M {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing)};
    };
    class FIR_GBU54_P_3rnd_M: FIR_GBU54_P_1rnd_M {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing)};
    };

    // GBU-55 LJDAM (1000 lb)
    class FIR_GBU55_P_1rnd_M: VehicleMagazine {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing)};
    };

    // GBU-56 LJDAM (2000 lb)
    class FIR_GBU56_P_1rnd_M: VehicleMagazine {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing)};
    };

    // AGM-114 Hellfire x4 (wing + centre bay)
    class FIR_AGM114_Base_P_4rnd_M: VehicleMagazine {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing), QCLASS(Warhawk_HP_BayCenter)};
    };
};
