class CfgVehicles {
    class DMNS_UNSC_Nightingale;
    class CLASS(Nightingale): DMNS_UNSC_Nightingale {
        SCOPE_PUBLIC;
        displayName = "EV-41 Nightingale";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine__Heli_Pilot);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        armor = 560; //Default 140
        hiddenSelections[] = {"camo1","clan","clan_text","insignia"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\nightingale\data\textures\505th_nightingale_base_co.paa)
        };
        icon = "\OPTRE_Vehicles_Air\Falcon\data\icon.paa";
    };
};