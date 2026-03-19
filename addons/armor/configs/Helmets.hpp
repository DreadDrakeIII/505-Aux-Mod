
class CLASS(CE_HELMET): CLASS(Marine_Helmet_Base) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Marine Helmet [Eyepiece]";
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEHelmet_co.paa"};
};
class CLASS(CE_HELMETV2): CLASS(Marine_Helmet_V2_Base) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Marine Helmet";
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEHelmet_co.paa"};
};
class CLASS(CE_HELMET_Corpsman): CLASS(CE_HELMET) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Corpsman Helmet [Eyepiece]";
    hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\Medic_Helmet_co.paa)};
};
class CLASS(CE_HELMET_CorpsmanV2): CLASS(CE_HELMETV2) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Corpsman Helmet";
    hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\Medic_Helmet_co.paa)};
};
class CLASS(CE_HELMET_SL): CLASS(CE_HELMET) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Squad Lead Helmet [Eyepiece]";
    hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\SL_Helmet_co.paa)};
};
class CLASS(CE_HELMET_SLV2): CLASS(CE_HELMETV2) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Squad Lead Helmet";
    hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\SL_Helmet_co.paa)};
};
class CLASS(CE_HELMET_PL): CLASS(CE_HELMET) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Platoon Lead Helmet [Eyepiece]";
    hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\PL_Helmet_co.paa)};
};
class CLASS(CE_HELMET_PLV2): CLASS(CE_HELMETV2) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Platoon Lead Helmet";
    hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\PL_Helmet_co.paa)};
};
class CLASS(CE_HELMET_FR): CLASS(CE_HELMET) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Force Recon Helmet [Eyepiece]";
    hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\Force_Recon_Helmet_co.paa)};
};
class CLASS(CE_HELMET_FRV2): CLASS(CE_HELMETV2) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Force Recon Helmet";
    hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\Force_Recon_Helmet_co.paa)};
};
////////////////////Custom Helms////////////////////
class CLASS(CE_HELMET_Adamant): CLASS(CE_HELMETV2) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Custom Helmet (Adamant)";
    optreHUDStyle = "Glasses";
    hiddenSelectionsTextures[]  = {QPATHTOF(data\helmets\ce\Dexus_Helmet_co.paa)};
};
class CLASS(CE_HELMET_Crawford): CLASS(CE_HELMETV2) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Custom Helmet (Crawford)";
    hiddenSelectionsTextures[]  = {QPATHTOF(data\helmets\ce\Anvil_Helmet_co.paa)};
};
//////////////////////Field Caps/////////////////////
class CLASS(CE_FieldCap_505th): CLASS(FieldCap_Base) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Field Cap (Logo)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\fieldcap\505th_CECap_co.paa)};
};
class CLASS(CE_FieldCap_Grey): CLASS(FieldCap_Base) {
    author = AUTHOR;
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Field Cap (Grey)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CECapGrey_co.paa"};
};
class CLASS(CE_FieldCap_Camo): CLASS(FieldCap_Base) {
    author = AUTHOR;
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Field Cap (Camo)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CECapCamo_co.paa"};
};
/////////////////////Boonie Hats/////////////////////
class CLASS(CE_BoonieHat_Grey): CLASS(Boonie_Base) {
    author = AUTHOR;
    SCOPE_PUBLIC;
    displayName = "[505th] Boonie Hat (Grey)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEBooniehatGrey_co.paa"};
};
class CLASS(CE_BoonieHat_Camo): CLASS(Boonie_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] Boonie Hat (Camo)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEBooniehat_co.paa"};
};
/////////////////////Pilot Helms/////////////////////
class CLASS(Jet_Pilot_Helmet): CLASS(505th_Jet_Pilot_Helmet_Base) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Jet Pilot Helmet";
};
class CLASS(Heli_Pilot_Helmet): CLASS(505th_Heli_Pilot_Helmet_Base) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Heli Pilot Helmet";
};
class CLASS(Heli_Crew_Helmet): CLASS(505th_Heli_Crew_Helmet_Base) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Heli Crew Helmet";
};
class CLASS(Tuna_Pilot_Helmet): CLASS(Heli_Pilot_Helmet) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Custom Helmet (Tuna)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\pilot\Tuna_Helmet_co.paa)};
};
class CLASS(Malarkey_Pilot_Helmet): CLASS(Heli_Crew_Helmet) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Custom Helmet (Malarkey)";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\pilot\Malarkey_Helmet_co.paa)};
};
///////////////////Black Ops Helms///////////////////
class CLASS(Black_Ops_Helmet): CLASS(505th_Black_Ops_Helmet_Base) {
    author = "505th Aux Team";
    scope = 0;
    scopeCurator = 0;
    scopeArsenal = 0;
    displayName = "[505th] Black Ops Helmet";
};
// ===========================================================================
// ============================ CH252 Helmets ================================
// ===========================================================================
class CLASS(EVCH252_Helmet_DES): CLASS(EVCH252_Helmet_DES_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] EVCH252 Helmet Arid";

    hiddenSelections[] = {
        "camo1",
        "camo2",
        "camo3",
        "camo4",
        "camo5",
        "camo6",
        "Camo7",
        "Camo8",
        "Camo9",
        "EyePiece",
        "EyePieceGlass",
        "VisorGlasses"
    };

    hiddenSelectionsTextures[] = {
        QPATHTOF(data\helmets\evch252\desert\evch252_helmet_des_co.paa),                 // camo1
        QPATHTOF(data\helmets\evch252\desert\evch252_helmet_des_co.paa),                 // camo2
        QPATHTOF(data\helmets\evch252\desert\evch252_helmet_des_co.paa),                 // camo3

        "MA_Armor\data\Helmets\CH252\data\MA_HelmetAccessories_A_CO.paa",                // camo4
        "MA_Armor\data\Helmets\CH252\data\MA_HelmetAccessories_A_CO.paa",                // camo5
        "MA_Armor\data\Helmets\CH252\data\MA_HelmetAccessories_A_CO.paa",                // camo6

        "MA_Armor\data\Helmets\CH252\data\VaccumCollar\Tan\VacSeal_Tan_CO.paa",          // Camo7

        QPATHTOF(data\helmets\evch252\desert\evch252_helmet_des_facemodule_co.paa),      // Camo8
        QPATHTOF(data\helmets\evch252\desert\evch252_helmet_des_facemodule_co.paa)       // Camo9
    };
};
class CLASS(EVCH252_Helmet_WDL): CLASS(EVCH252_Helmet_WDL_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] EVCH252 Helmet Woodland";
};

class CLASS(EVCH252_Helmet_URB): CLASS(EVCH252_Helmet_URB_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] EVCH252 Helmet Urban";
};

class CLASS(CH252_Helmet_WDL): CLASS(CH252_Helmet_WDL_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] CH252 Helmet Woodland";
};

class CLASS(CH252_Helmet_WDL_NV): CLASS(CH252_Helmet_WDL_NV_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] CH252 Helmet Woodland NV";
};

class CLASS(CH252_Helmet_DES): CLASS(CH252_Helmet_DES_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] CH252 Helmet Arid";
};

class CLASS(CH252_Helmet_DES_NV): CLASS(CH252_Helmet_DES_NV_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] CH252 Helmet Arid NV";
};

class CLASS(CH252_Helmet_URB): CLASS(CH252_Helmet_URB_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] CH252 Helmet Urban";
};

class CLASS(CH252_Helmet_URB_NV): CLASS(CH252_Helmet_URB_NV_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] CH252 Helmet Urban NV";
};

hiddenSelections[] = {"camo1","camo2","camo3","camo4","camo5","camo6","Camo7","Camo8","Camo9","EyePiece","EyePieceGlass","VisorGlasses"};
hiddenSelectionsTextures[] = {"MA_Armor\data\Helmets\CH252\data\MA_Tan_TrooperHelmet_CO.paa","MA_Armor\data\Helmets\CH252\data\MA_Tan_TrooperHelmet_CO.paa","MA_Armor\data\Helmets\CH252\data\MA_Tan_TrooperHelmet_CO.paa","MA_Armor\data\Helmets\CH252\data\MA_HelmetAccessories_A_CO.paa","MA_Armor\data\Helmets\CH252\data\MA_HelmetAccessories_A_CO.paa","MA_Armor\data\Helmets\CH252\data\MA_HelmetAccessories_A_CO.paa","MA_Armor\data\Helmets\CH252\data\VaccumCollar\Tan\VacSeal_Tan_CO.paa","MA_Armor\data\Helmets\CH252\data\SealedVisor\Blue_Visor\Desert\FaceModule_CO.paa","MA_Armor\data\Helmets\CH252\data\SealedVisor\Blue_Visor\Desert\FaceModule_CO.paa"};