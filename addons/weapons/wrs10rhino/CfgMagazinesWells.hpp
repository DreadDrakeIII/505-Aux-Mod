class cfgMagazineWells {
    // ================================
    // WRS10RHINO CARTRIDGE WELL
    // Allows weapon to accept any of the 3 ammo types
    // ================================
    class CLASS(Magwell_WRS10RHINO) {
        CLASS(rhinocartridge)[] = {
            QCLASS(coolant_cartridge)
        };
    };
};
