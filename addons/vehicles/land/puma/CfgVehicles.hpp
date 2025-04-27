class CfgVehicles {
    class DMNS_M511_Springbok_AA;
    class CLASS(Puma_AA): DMNS_M511_Springbok_AA {
        SCOPE_PRIVATE;
        displayName = "[505th] M513-Puma (AA)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(APCs);
        crew = QCLASS(Marine_Rifleman_CE);
        armor = 950;
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\puma\data\textures\505th_M511_Body_co.paa),
            "DMNS\DMNS_Armour\M511_Springbok\Data\M511_Interior_co.paa",
            QPATHTOF(land\puma\data\textures\505th_M511_Details_co.paa),
            QPATHTOF(land\puma\data\textures\505th_AA_co.paa)
        };
    };

class DMNS_M511_Springbok_IFV;
class CLASS(Puma_IFV): DMNS_M511_Springbok_IFV {
    SCOPE_PRIVATE;
    displayName = "[505th] M512-Puma (IFV)";
    faction = QFACTION(505th);
    editorSubcategory = QEDSUBCAT(APCs);
    crew = QCLASS(Marine_Rifleman_CE);
    armor = 950;
    hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4","Camo5"};
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
    SCOPE_PRIVATE;
    displayName = "[505th] M511-Puma (MGS)";
    faction = QFACTION(505th);
    editorSubcategory = QEDSUBCAT(APCs);
    crew = QCLASS(Marine_Rifleman_CE);
    armor = 950;
    hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
    hiddenSelectionsTextures[] = {
            QPATHTOF(land\puma\data\textures\505th_M511_Body_co.paa),
            "DMNS\DMNS_Armour\M511_Springbok\Data\M511_Interior_co.paa",
            QPATHTOF(land\puma\data\textures\505th_M511_Details.co.paa),
            QPATHTOF(land\puma\data\textures\505th_M511_MGS_co.paa),
        };
    };
    class DMNS_M511_Springbok_APC;
    class CLASS(Puma_APC): DMNS_M511_Springbok_APC {
        SCOPE_PRIVATE;
        displayName = "[505th] M510-Puma (Transport)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(APCs);
        crew = QCLASS(Marine_Rifleman_CE);
        armor = 950;
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\puma\data\textures\505th_M511_Body_co.paa),
            "DMNS\DMNS_Armour\M511_Springbok\Data\M511_Interior_co.paa",
            QPATHTOF(land\puma\data\textures\505th_M511_Details.co.paa),
            QPATHTOF(land\puma\data\textures\505th_M511_M247H_co.paa),
        };
    };
};