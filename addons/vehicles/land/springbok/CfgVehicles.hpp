class CfgVehicles {
    class DMNS_M511_Springbok_AA;
    class CLASS(Springbok_AA): DMNS_M511_Springbok_AA {
        displayName = "[505th] M511-Springbok (AA)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(APCs);
        crew = QCLASS(Marine_Rifleman_CE);
        armor = 950;
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\springbok\data\textures\505th_M511_Body_co.paa),
            "DMNS\DMNS_Armour\M511_Springbok\Data\M511_Interior_co.paa",
            QPATHTOF(land\springbok\data\textures\505th_M511_Details_co.paa),
            QPATHTOF(land\springbok\data\textures\505th_AA_co.paa)
        };
    };

class DMNS_M511_Springbok_IFV;
class CLASS(Springbok_IFV): DMNS_M511_Springbok_IFV {
    displayName = "[505th] M511-Springbok (IFV)";
    faction = QFACTION(505th);
    editorSubcategory = QEDSUBCAT(APCs);
    crew = QCLASS(Marine_Rifleman_CE);
    armor = 950;
    hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4","Camo5"};
    hiddenSelectionsTextures[] = {
            QPATHTOF(land\springbok\data\textures\505th_M511_Body_co.paa),
            "DMNS\DMNS_Armour\M511_Springbok\Data\M511_Interior_co.paa",
            QPATHTOF(land\springbok\data\textures\505th_M511_Details.co.paa),
            QPATHTOF(land\springbok\data\textures\505th_M511_IFV_co.paa),
            QPATHTOF(land\springbok\data\textures\505th_M511_AA_co.paa)
        };
    };
class DMNS_M511_Springbok_MGS;
class CLASS(Springbok_MGS): DMNS_M511_Springbok_MGS {
    displayName = "[505th] M511-Springbok (MGS)";
    faction = QFACTION(505th);
    editorSubcategory = QEDSUBCAT(APCs);
    crew = QCLASS(Marine_Rifleman_CE);
    armor = 950;
    hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
    hiddenSelectionsTextures[] = {
            QPATHTOF(land\springbok\data\textures\505th_M511_Body_co.paa),
            "DMNS\DMNS_Armour\M511_Springbok\Data\M511_Interior_co.paa",
            QPATHTOF(land\springbok\data\textures\505th_M511_Details.co.paa),
            QPATHTOF(land\springbok\data\textures\505th_M511_MGS_co.paa),
        };
    };
    class DMNS_M511_Springbok_APC;
    class CLASS(Springbok_APC): DMNS_M511_Springbok_APC {
        displayName = "[505th] M511-Springbok (Transport)";
        faction = QFACTION(505th);
        editorSubcategory = QEDSUBCAT(APCs);
        crew = QCLASS(Marine_Rifleman_CE);
        armor = 950;
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(land\springbok\data\textures\505th_M511_Body_co.paa),
            "DMNS\DMNS_Armour\M511_Springbok\Data\M511_Interior_co.paa",
            QPATHTOF(land\springbok\data\textures\505th_M511_Details.co.paa),
            QPATHTOF(land\springbok\data\textures\505th_M511_M247H_co.paa),
        };
    };
};