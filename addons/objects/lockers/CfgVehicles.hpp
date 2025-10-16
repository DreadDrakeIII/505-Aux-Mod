class CfgVehicles {
    class Land_packing_crate_lg_blue;
    class Land_optre_milcrate_h2agray: Land_packing_crate_lg_blue {
    };
    class CLASS(Locker_Base): Land_optre_milcrate_h2agray {
        SCOPE_HIDDEN;
        author = AUTHOR;

        displayName = "Locker (Base)";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Utility);
    };

    class CLASS(Locker_CE): CLASS(Locker_Base) {
        SCOPE_PUBLIC;
        displayName = "CE Loadout Locker";
    };

    class CLASS(Locker_CE_FR): CLASS(Locker_Base) {
        SCOPE_PUBLIC;
        displayName = "FR Loadout Locker";
    };
};
