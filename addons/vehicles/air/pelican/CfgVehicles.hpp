class CfgVehicles {
    class Splits_UNSC_D77_TC_Pelican;
    class CLASS(Pelican): Splits_UNSC_D77_TC_Pelican {
        SCOPE_PUBLIC;
        displayName = "[505th] D77-TC Pelican";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        gunnerType = QCLASS(Marine_Rifleman_CE);
        typicalCargo[] = {QCLASS(Marine_Heli_Pilot)};
        GetInAction = "pilot_Heli_Light_02_Enter";
        GetOutAction = "pilot_Heli_Light_02_Exit";
        weapons[] = {
            "CMFlareLauncher",
            "Splits_missiles_Anvil1"
        };
        magazines[] = {
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "240Rnd_CMFlare_Chaff_Magazine",
            "Splits_60Rnd_Anvil1_missiles",
            "Splits_60Rnd_Anvil1_missiles",
            "Splits_60Rnd_Anvil1_missiles",
            "Splits_60Rnd_Anvil1_missiles",
            "Splits_60Rnd_Anvil1_missiles",
            "Laserbatteries"
        };

        hiddenSelections[] = {"camo1","camo2","camo3"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\pelican\data\textures\505th_Pelican_body_co.paa),
            QPATHTOF(air\pelican\data\textures\505th_Pelican_wings_and_gear_co.paa),
            QPATHTOF(air\pelican\data\textures\505th_Pelican_weaponry_co.paa)
        };
        icon = "OPTRE_Vehicles\Pelican\Data\icon.paa";
    };
};
