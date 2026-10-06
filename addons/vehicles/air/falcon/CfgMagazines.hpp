
class CfgMagazines {
    // Parents forward-declared so HEMTT's linter (L-C04) accepts the re-opens below.
    class OPTRE_1Rnd_Anvil1_missiles;
    class OPTRE_2000Rnd_30mm_HE;
    class PylonMissile_1Rnd_Mk82_F;

    // Falcon pylon whitelist (same pattern as the Warhawk).
    // The Falcon pylons only accept the two tags below, so a magazine shows up in the
    // pylon picker ONLY if it is tagged here. Tags are appended with +=, nothing is removed.
    // Wing = upper pylons, Belly = lower pylons.

    // --- Anvil I ---
    class OPTRE_16Rnd_Anvil1_missiles: OPTRE_1Rnd_Anvil1_missiles {
        hardpoints[] += {QCLASS(Falcon_HP_Wing)};
    };
    class OPTRE_8Rnd_Anvil1_missiles: OPTRE_1Rnd_Anvil1_missiles {
        hardpoints[] += {QCLASS(Falcon_HP_Wing), QCLASS(Falcon_HP_Belly)};
    };

    // --- Minigun (HE is a child of AP, so AP must be re-opened first) ---
    class OPTRE_Minigun_Pylon_AP_x2000_Magazine: OPTRE_2000Rnd_30mm_HE {
        hardpoints[] += {QCLASS(Falcon_HP_Wing), QCLASS(Falcon_HP_Belly)};
    };
    class OPTRE_Minigun_Pylon_HE_x1000_Magazine: OPTRE_Minigun_Pylon_AP_x2000_Magazine {
        hardpoints[] += {QCLASS(Falcon_HP_Wing), QCLASS(Falcon_HP_Belly)};
    };

    // --- Mortar dropper ---
    class OPTRE_5Rnd_Mortar_Bomb_Pylon: PylonMissile_1Rnd_Mk82_F {
        hardpoints[] += {QCLASS(Falcon_HP_Wing), QCLASS(Falcon_HP_Belly)};
    };
};
