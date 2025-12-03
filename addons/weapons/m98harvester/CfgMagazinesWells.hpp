class cfgMagazineWells {
    // ================================
    // M98 HARVESTER MAGAZINE WELL
    // Allows weapon to accept any of the 3 ammo types
    // ================================
    class CLASS(Magwell_M98_Harvester) {
        CLASS(147x114)[] = {
            QCLASS(5Rnd_147x114_APFSDS_Mag),
            QCLASS(5Rnd_147x114_HVAP_Mag),
            QCLASS(5Rnd_147x114_HEDP_Mag)
        };
    };
};
