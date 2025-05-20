class CfgVehicles {
    class O_Plane_Fighter_02_F;
    class CLASS(Buzzard): O_Plane_Fighter_02_F {
        SCOPE_PRIVATE;

        displayName = "[505th] Buzzard";
        side = BLUFOR;
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Planes);
        crew = QCLASS(Marine_Jet_Pilot);
        hiddenSelections[] = {
            "Camo_01",
            "Camo_02",
            "",
            "number_01",
            "number_02",
            "number_03"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\buzzard\data\textures\505th_01_fuselage_co.paa),
            QPATHTOF(air\buzzard\data\textures\505th_02_fuselage_co.paa),
            QPATHTOF(air\buzzard\data\textures\505th_01_fuselage_co.paa),
            "a3\air_f_jets\plane_fighter_02\data\Numbers\Fighter_02_number_02_co.paa",
            "a3\air_f_jets\plane_fighter_02\data\Numbers\Fighter_02_number_00_co.paa",
            "a3\air_f_jets\plane_fighter_02\data\Numbers\Fighter_02_number_01_co.paa"
        };
    };
};