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

        ace_cargo_canLoad = FALSE;
        ace_cargo_noRename = TRUE;
        ace_cargo_size = 1;

        ace_dragging_canDrag = FALSE;
        ace_dragging_dragDirection = 0;
        ace_dragging_carryDirection = 90;
        ace_dragging_dragPosition[] = {0,1.2,0};
        ace_dragging_carryPosition[] = {0,2,0};

        ace_dragging_canCarry = FALSE;

        ace_dragging_ignoreWeight = FALSE;
        ace_dragging_ignoreWeightCarry = FALSE;
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
