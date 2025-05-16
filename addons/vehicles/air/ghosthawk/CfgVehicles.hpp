class CfgVehicles {
    class B_Heli_Transport_01_F;
    class CLASS(Ghosthawk): B_Heli_Transport_01_F {
        SCOPE_PUBLIC;

        displayName = "[505th] UH-240 Ghost Hawk";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        gunnerType = QCLASS(Marine_Heli_Crew);
        hiddenSelections[] = {
            "camo1",
            "camo2"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\ghosthawk\data\textures\505th_heli_transport_01_ext01_CO.paa),
            QPATHTOF(air\ghosthawk\data\textures\505th_heli_transport_01_ext02_CO.paa)
        };
    };

    class CLASS(ONI_GhostHawk): CLASS(Ghosthawk) {
        SCOPE_PUBLIC;

        displayName = "[ONI] UH-240 Ghost Hawk";
        faction = QFACTION(ONI);
        editorSubcategory = QEDSUBCAT(Helicopters);
        crew = QCLASS(Marine_Heli_Pilot);
        gunnerType = QCLASS(Marine_Heli_Crew);
        hiddenSelections[] = {
            "camo1",
            "camo2"
        };
        hiddenSelectionsTextures[] = {
            QPATHTOF(air\ghosthawk\data\textures\ONI_heli_transport_01_ext01_CO.paa),
            QPATHTOF(air\ghosthawk\data\textures\ONI_heli_transport_01_ext02_CO.paa)
        };
    };
};