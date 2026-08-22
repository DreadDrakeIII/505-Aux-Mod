class CfgVehicles {
    class CLASS(Console_Base);
    class CLASS(Supply_Console): CLASS(Console_Base) {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "Resupply Terminal";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Utility);
    };
};
