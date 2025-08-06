class CfgVehicles {
    class DMNS_M511_Springbok_AA;
    class CLASS(Puma_AA): DMNS_M511_Springbok_AA {
        SCOPE_PUBLIC;
        displayName = "M513-Puma (AA)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(APCs);
        crew = QCLASS(Marine_Tank_Crew);
        armor = 950;
        hiddenSelections[] = {"Camo1","Camo2","Camo3","otochlaven","z_gatling","otocvez","clan","clan_text","insignia","_Ammobox","_Axe","_Cans","_FireExtinguisher","_Shovel"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\puma\data\textures\505th_M511_Body_co.paa),
            "DMNS\DMNS_Armour\M511_Springbok\Data\M511_Interior_co.paa",
            QPATHTOF(land\puma\data\textures\505th_M511_Details.co.paa),
            QPATHTOF(land\puma\data\textures\505th_M511_AA_co.paa),
            QPATHTOF(land\puma\data\textures\505th_M511_AA_co.paa),
            QPATHTOF(land\puma\data\textures\505th_M511_AA_co.paa)
        };
    };

class DMNS_M511_Springbok_IFV;
class CLASS(Puma_IFV): DMNS_M511_Springbok_IFV {
    SCOPE_PUBLIC;
    displayName = "M512-Puma (IFV)";
    faction = QFACTION(505th);
    editorSubcategory = QEDSUBCAT(APCs);
    crew = QCLASS(Marine_Tank_Crew);
    armor = 950;
    hiddenSelections[] = {"Camo1","Camo2","Camo3","otochlaven","otocvez","clan","clan_text","insignia","_Ammobox","_Axe","_Cans","_FireExtinguisher","_Shovel"};
    hiddenSelectionsTextures[] = {
            QPATHTOF(land\puma\data\textures\505th_M511_Body_co.paa),
            "DMNS\DMNS_Armour\M511_Springbok\Data\M511_Interior_co.paa",
            QPATHTOF(land\puma\data\textures\505th_M511_Details.co.paa),
            QPATHTOF(land\puma\data\textures\505th_M511_IFV_co.paa),
            QPATHTOF(land\puma\data\textures\505th_M511_AA_co.paa)
        };
    };
class DMNS_M511_Springbok_MGS;
class CLASS(Puma_MGS): DMNS_M511_Springbok_MGS {
    SCOPE_PUBLIC;
    displayName = "M511-Puma (MGS)";
    faction = QFACTION(505th);
    editorSubcategory = QEDSUBCAT(APCs);
    crew = QCLASS(Marine_Tank_Crew);
    armor = 950;
    hiddenSelections[] = {"Camo1","Camo2","Camo3","door_1_1","commanders_gun","otochlaven","otocvez","clan","clan_text","insignia","_Ammobox","_Axe","_Cans","_FireExtinguisher","_Shovel"};
    hiddenSelectionsTextures[] = {
            QPATHTOF(land\puma\data\textures\505th_M511_Body_co.paa),
            "DMNS\DMNS_Armour\M511_Springbok\Data\M511_Interior_co.paa",
            QPATHTOF(land\puma\data\textures\505th_M511_Details_co.paa),
            QPATHTOF(land\puma\data\textures\505th_M511_Details_co.paa),
            QPATHTOF(land\puma\data\textures\505th_M511_Wheels_co.paa),
            QPATHTOF(land\puma\data\textures\505th_M511_MGS_co.paa),
            QPATHTOF(land\puma\data\textures\505th_M511_MGS_co.paa),
        };
    };
    class DMNS_M511_Springbok_APC;
    class CLASS(Puma_APC): DMNS_M511_Springbok_APC {
        SCOPE_PUBLIC;
        displayName = "M510-Puma (Transport)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(APCs);
        crew = QCLASS(Marine_Tank_Crew);
        armor = 950;
        hiddenSelections[] = {"Camo1","Camo2","Camo3","otochlaven","otocvez","clan","clan_text","insignia","_Ammobox","_Axe","_Cans","_FireExtinguisher","_Shovel"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\puma\data\textures\505th_M511_Body_co.paa),
            "DMNS\DMNS_Armour\M511_Springbok\Data\M511_Interior_co.paa",
            QPATHTOF(land\puma\data\textures\505th_M511_Details_co.paa),
            QPATHTOF(land\puma\data\textures\505th_M511_M247H.co.paa),
            QPATHTOF(land\puma\data\textures\505th_M511_M247H.co.paa)
        };
    };
};
