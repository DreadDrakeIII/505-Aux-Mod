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
};