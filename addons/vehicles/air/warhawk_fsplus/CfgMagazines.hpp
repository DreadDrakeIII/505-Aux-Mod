class CfgMagazines {
    class PylonMissile_Bomb_GBU12_x1;
    class PylonRack_Bomb_GBU12_x2;

    // Thermobaric Bomb (Heavy) - unguided FAE, Fire Support PLUS.
    // Re-opened with original parents, Warhawk wing tag appended only.
    class PHAN_FAEBomb_Unguided_Heavy_Mag: PylonMissile_Bomb_GBU12_x1 {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing)};
    };
    class PHAN_FAEBomb_Unguided_Heavy_Mag_x2: PylonRack_Bomb_GBU12_x2 {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing)};
    };
    class PHAN_FAEBomb_Unguided_Heavy_Mag_x3: PylonRack_Bomb_GBU12_x2 {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing)};
    };
    class PHAN_FAEBomb_Unguided_Heavy_Mag_x4: PylonRack_Bomb_GBU12_x2 {
        hardpoints[] += {QCLASS(Warhawk_HP_Wing)};
    };
};
