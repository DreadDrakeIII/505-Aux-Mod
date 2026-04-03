class cfgMagazineWells {
    // ================================
    // BR55HB MAGAZINE WELL
    // Allows weapon to accept any of the 3 ammo types
    // ================================
    class CLASS(Magwell_BR55HB) {
        CLASS(TCP_95x40)[] = {
            QCLASS(36Rnd_95x40_Mag)
        };
    };
};
