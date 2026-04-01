class cfgMagazineWells {
    // ================================
    // M98 HARVESTER MAGAZINE WELL
    // Allows weapon to accept any of the 3 ammo types
    // ================================
    class CLASS(Magwell_M98_Harvester_II) {
        CLASS(147x114)[] = {
            QCLASS(5Rnd_147x114_APFSDS_Magv2),
            QCLASS(5Rnd_147x114_HVAP_Magv2),
            QCLASS(5Rnd_147x114_HEDP_Magv2)
        };
    };
};
