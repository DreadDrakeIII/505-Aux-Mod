class CfgVehicles {
    class OPTRE_M411_APC_UNSC;
    class OPTRE_M412_IFV_UNSC;
    class OPTRE_M413_MGS_UNSC;
    class CLASS(Bison_Transport): OPTRE_M411_APC_UNSC {
        SCOPE_PUBLIC;

        displayName = "M410 Bison (Transport)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(APCs);
        crew = QCLASS(Marine_Tank_Crew);
        typicalCargo[] = {QCLASS(Marine_Rifleman_CE)};
    };

    class CLASS(Bison_IFV): OPTRE_M412_IFV_UNSC {
        SCOPE_PUBLIC;

        displayName = "M411 Bison (IFV)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(APCs);
        crew = QCLASS(Marine_Tank_Crew);
        typicalCargo[] = {QCLASS(Marine_Rifleman_CE)};
    };

    class CLASS(Bison_MGS): OPTRE_M413_MGS_UNSC {
        SCOPE_PUBLIC;

        displayName = "M412 Bison (MGS)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(APCs);
        crew = QCLASS(Marine_Tank_Crew);
        typicalCargo[] = {QCLASS(Marine_Rifleman_CE)};
    };
};
