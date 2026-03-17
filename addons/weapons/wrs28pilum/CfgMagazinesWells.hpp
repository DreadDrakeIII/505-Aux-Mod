class cfgMagazineWells {
    // ================================
    // WRS-28 Pilum Cell WELL
    // Allows weapon to accept any of the 3 ammo types
    // ================================
    class CLASS(Magwell_WRS28) {
        CLASS(CELL)[] = {
            QCLASS(UC_CELL),
            QCLASS(CC_CELL)
        };
    };
};
