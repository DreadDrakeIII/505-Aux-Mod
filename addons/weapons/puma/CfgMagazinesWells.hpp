class cfgMagazineWells {
    // ================================
    // Puma MAGAZINE WELL
    // Allows weapon to accept any of the 3 ammo types
    // ================================
    class CLASS(Magwell_PUMA) {
        CLASS(45ACP_Ball)[] = {
            QCLASS(16Rnd_45ACP_Mag)
        };
    };
};
