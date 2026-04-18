class CfgWeapons {
    class Launcher_Base_F;
    class OPTRE_M44_Lykoi_Semi_Disposable_AT: Launcher_Base_F {
        class WeaponSlotsInfo;
        class Single;
    };

    class CLASS(M44_Lykoi_Disposable_base): OPTRE_M44_Lykoi_Semi_Disposable_AT {
        SCOPE_PRIVATE;
        author = AUTHOR;

        displayName = "[505th] M44-Lykoi (Base)";

        modes[]    = {"Single"};
        magazines[] = {QCLASS(M44_Lykoi_HEAT)};
        magazineWell[] = {};

        class EventHandlers {};

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = MASS_LAUNCHER;
        };

        class Single: Single {
                reloadTime = 1.5; // time it takes to "reload" (switch from loaded to used state)
        };
    };

    class CLASS(M44_Lykoi_Disposable): CLASS(M44_Lykoi_Disposable_base) {
        SCOPE_HIDDEN;
        displayName     = "[505th] M44-Lykoi (Disposable)";
        descriptionShort = "Single-use Rocket Tube";

        baseWeapon = QCLASS(M44_Lykoi_Disposable);

        magazineReloadTime = 1.5; // time it takes to "reload" (switch from loaded to used state)

        class EventHandlers: EventHandlers {
            fired = QUOTE(_this call CBA_fnc_firedDisposable);
        };
    };

    class CLASS(M44_Lykoi_Loaded): CLASS(M44_Lykoi_Disposable) {
        SCOPE_PUBLIC;
        displayName     = "[505th] M44-Lykoi";
        descriptionShort = "Single-use Rocket Tube (Loaded)";


         magazines[] = {"CBA_FakeLauncherMagazine"}; // prevents the player from having the actual magazine in their inventory, as the rocket is "loaded" into the launcher itself

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = MASS_LAUNCHER + MASS_MAGAZINE;
        };
    };

    class CLASS(M44_Lykoi_Used): CLASS(M44_Lykoi_Disposable) {
        SCOPE_HIDDEN;
        displayName     = "[505th] M44-Lykoi (Used)";
        descriptionShort = "Used Rocket Tube";


        magazines[] = {"CBA_FakeLauncherMagazine"};

        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = MASS_LAUNCHER;
        };

        class EventHandlers: EventHandlers {
        fired = "";
        };
    };
};
