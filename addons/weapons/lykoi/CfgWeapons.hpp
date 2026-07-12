class CfgWeapons {
    class Launcher;
    class Launcher_Base_F: Launcher {};
    class launch_RPG7_F: Launcher_Base_F {
        class WeaponSlotsInfo;
    };
    class OPTRE_M44_Lykoi_Semi_Disposable_AT: launch_RPG7_F {};
    class OPTRE_M44_Lykoi_Semi_Disposable_AT_Grey: OPTRE_M44_Lykoi_Semi_Disposable_AT {};

    // BASE — shared properties, hidden from Arsenal
    class CLASS(M44_Lykoi_Base_Grey): OPTRE_M44_Lykoi_Semi_Disposable_AT_Grey {
        SCOPE_PRIVATE;
        author = AUTHOR;

        displayName = "[505th] M44 Lykoi Disposable AT (Grey)";
        baseWeapon = QCLASS(M44_Lykoi_Base_Grey);

        magazines[] = {"OPTRE_M44_Lykoi_HEAT_mag"};
        magazineWell[] = {};
        magazineReloadTime = 0.1;
        reloadMagazineSound[] = {"", 1, 1};

        class EventHandlers {};

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = MASS_LAUNCHER;
        };
    };

    // DISPOSABLE — fires via CBA, hidden from Arsenal
    class CLASS(M44_Lykoi_Disposable_Grey): CLASS(M44_Lykoi_Base_Grey) {
        SCOPE_HIDDEN;
        baseWeapon = QCLASS(M44_Lykoi_Disposable_Grey);

        class EventHandlers: EventHandlers {
            fired = QUOTE(_this call CBA_fnc_firedDisposable);
        };
    };

    // LOADED — what players pick up, visible in Arsenal
    class CLASS(M44_Lykoi_Loaded_Grey): CLASS(M44_Lykoi_Disposable_Grey) {
        SCOPE_PUBLIC;

        magazines[] = {"CBA_FakeLauncherMagazine"};

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = MASS_LAUNCHER + MASS_MAGAZINE;
        };
    };

    // USED — replaces loaded after firing, then auto-removed by postInit EH
    class CLASS(M44_Lykoi_Used_Grey): CLASS(M44_Lykoi_Disposable_Grey) {
        SCOPE_HIDDEN;

        displayName = "[505th] M44 Lykoi Disposable AT (Grey) [USED]";
        magazines[] = {"CBA_FakeLauncherMagazine"};

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = MASS_LAUNCHER;
        };
    };
};
