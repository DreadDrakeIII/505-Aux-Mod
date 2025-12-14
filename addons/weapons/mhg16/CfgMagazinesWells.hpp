class cfgMagazineWells {
    // ================================
    // MHG-16 MAGAZINE WELL
    // Allows weapon to accept any of the 3 ammo types
    // ================================
    class CLASS(Magwell_MHG16) {
        CLASS(45ACP_Ball)[] = {
            QCLASS(12Rnd_45ACP_Mag)
        };
    };
};
