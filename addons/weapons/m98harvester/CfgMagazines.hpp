class CfgMagazines {
    class TCP_4Rnd_127x99_Mag_APFSDS_Tracer_Green;

    // ================================
    // M98 HARVESTER MAGAZINES
    // 5-round magazines for anti-material ammo
    // ================================

    // ================================
    // APFSDS MAGAZINE (Best for armor penetration)
    // ================================
    class CLASS(5Rnd_147x114_APFSDS_Mag) : TCP_4Rnd_127x99_Mag_APFSDS_Tracer_Green {
        SCOPE_PUBLIC;
        baseMagazine = QCLASS(5Rnd_147x114_APFSDS_Mag);
        author = AUTHOR;

        displayName = "[505th] 5Rnd M98H APFSDS";
        displayNameShort = "14.7×114mm APFSDS • 5Rnd";
        descriptionShort = "Anti-Material Magazine • APFSDS Rounds • Maximum Penetration • 5 Rounds";

        model = "\A3\weapons_F\ammo\mag_univ.p3d";
        picture = "TCP\weapons\ammo\127x99\Ball\data\ui\icon_127x99mm_CA.paa";


        // Ammunition type
        ammo = QCLASS(147x114_APFSDS);

        // Magazine properties
        count = 5;                     // 5 rounds (anti-material standard)
        initSpeed = 1400;              // very fast muzzle velocity
        tracersEvery = 1;              // no tracers (armor-piercing rounds)
        lastRoundsTracer = 0;          // no tracer rounds
        mass = 8;                      // weight in kg

        // Magazine well compatibility
        magazineWell[] = {QCLASS(Magwell_M98_Harvester)};
    };

    // ================================
    // HVAP MAGAZINE (Balanced - armor penetration + velocity)
    // ================================
    class CLASS(5Rnd_147x114_HVAP_Mag): CLASS(5Rnd_147x114_APFSDS_Mag) {
        displayName = "[505th] 5Rnd M98H HVAP";
        displayNameShort = "14.7×114mm HVAP • 5Rnd";
        descriptionShort = "Anti-Material Magazine • HVAP Rounds • Balanced Penetration • 5 Rounds";
        tracersEvery = 1;              // no tracers (armor-piercing rounds)
        lastRoundsTracer = 0;          // no tracer rounds

        ammo = QCLASS(147x114_HVAP);
        initSpeed = 1200;               // balanced velocity (slightly slower than APFSDS)
        mass = 8;
    };

    // ================================
    // HEDP MAGAZINE (High Explosive - anti-personnel/structure)
    // ================================
    class CLASS(5Rnd_147x114_HEDP_Mag): CLASS(5Rnd_147x114_APFSDS_Mag) {
        displayName = "[505th] 5Rnd M98H HEDP";
        displayNameShort = "14.7×114mm HEDP • 5Rnd";
        descriptionShort = "Anti-Material Magazine • HEDP Rounds • Explosive Payload • 5 Rounds";
        tracersEvery = 1;              // no tracers (armor-piercing rounds)
        lastRoundsTracer = 0;          // no tracer rounds

        ammo = QCLASS(147x114_HEDP);
        initSpeed = 1200;               // same velocity as HVAP
        mass = 12;                      // slightly heavier due to explosive payload
    };
};
