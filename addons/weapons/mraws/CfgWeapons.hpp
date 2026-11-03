class CfgWeapons {
    class Launcher_Base_F;
    class launch_MRAWS_green_F: Launcher_Base_F {
        class WeaponSlotsInfo;
        class Single;
    };
    class CLASS(M20_Lawbringer): launch_MRAWS_green_F {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "[505th] M20 Lawbringer";

        modes[] = {"Single"};
        muzzles[] = {"this"};
        magazines[] = {"MRAWS_HEAT_F","MRAWS_HE_F","MRAWS_HEAT55_F","WNZ_EMP_MAAWS_Mag"};
        magazineWell[] = {"CBA_Carl_Gustaf"};

        class EventHandlers;

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = MASS_LAUNCHER;
        };
    };

    // 505th Light AT - MRAWS (rail) firing HEAT / HE
    class launch_MRAWS_green_rail_F;
    class CLASS(M20_Lawbringer_LAT): launch_MRAWS_green_rail_F {
        SCOPE_PUBLIC;
        author = AUTHOR;
        displayName = "[505th] M20 Lawbringer (LAT)";
        baseWeapon = QCLASS(M20_Lawbringer_LAT);

        magazines[] = {QCLASS(M20_HEAT75), QCLASS(M20_HE44), QCLASS(M20_WP)};
        magazineWell[] = {};

        hiddenSelectionsTextures[] = {
            QPATHTOF(mraws\data\M20_LAT_01_co.paa),
            QPATHTOF(mraws\data\M20_LAT_02_co.paa)
        };
    };
};
