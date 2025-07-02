class CfgVehicles {
    class Land_OPTRE_AFB_sign;
    class CLASS(AFB_Sign_1): Land_OPTRE_AFB_sign {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "[505th] Airbase Sign (BJL)";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Signs);

        hiddenSelections[] = {"Sign"};
        hiddenSelectionsMaterials[] = {QPATHTOF(data\signs\AirbaseSign_NOHQ.paa)};
        hiddenSelectionsTextures[] = {QPATHTOF(data\signs\AirbaseSign1_CO.paa)};
    };
};
