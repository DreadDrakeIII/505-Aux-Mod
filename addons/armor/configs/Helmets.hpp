class CLASS(CE_HELMET): CLASS(Marine_Helmet_Base) {
	author = "505th Aux Team";
	scope = 2;
	scopeCurator = 2;
    scopeArsenal = 2;
	displayName = "[505] Marine Helmet [Eyepiece]";
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEHelmet_co.paa"};
};
class CLASS(CE_HELMETV2): CLASS(Marine_Helmet_V2_Base) {
	author = "505th Aux Team";
	scope = 2;
	scopeCurator = 2;
    scopeArsenal = 2;
	displayName = "[505] Marine Helmet";
	hiddenSelectionsTextures[] = {"\Rogue_CEMarine\data\Rogue_CEHelmet_co.paa"};
};
class CLASS(CE_HELMET_Corpsman): CLASS(CE_HELMET) {
	author = "505th Aux Team";
	scope = 2;
	scopeCurator = 2;
    scopeArsenal = 2;
	displayName = "[505] Corpsman Helmet [Eyepiece]";
	hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\Medic_Helmet_co.paa)};
};
class CLASS(CE_HELMET_CorpsmanV2): CLASS(CE_HELMETV2) {
	author = "505th Aux Team";
	scope = 2;
	scopeCurator = 2;
    scopeArsenal = 2;
	displayName = "[505] Corpsman Helmet";
	hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\Medic_Helmet_co.paa)};
};
class CLASS(CE_HELMET_SL): CLASS(CE_HELMET) {
	author = "505th Aux Team";
	scope = 2;
	scopeCurator = 2;
    scopeArsenal = 2;
	displayName = "[505] Marine Squad Lead Helmet [Eyepiece]";
	hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\SL_Helmet_co.paa)};
};
class CLASS(CE_HELMET_SLV2): CLASS(CE_HELMETV2) {
	author = "505th Aux Team";
	scope = 2;
	scopeCurator = 2;
	displayName = "[505] Marine Squad Lead Helmet";
	hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\SL_Helmet_co.paa)};
};
class CLASS(CE_HELMET_PL): CLASS(CE_HELMET) {
	author = "505th Aux Team";
	scope = 2;
	scopeCurator = 2;
    scopeArsenal = 2;
	displayName = "[505] Marine Platoon Lead Helmet [Eyepiece]";
	hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\PL_Helmet_co.paa)};
};
class CLASS(CE_HELMET_PLV2): CLASS(CE_HELMETV2) {
	author = "505th Aux Team";
	scope = 2;
	scopeCurator = 2;
    scopeArsenal = 2;
	displayName = "[505] Marine Platoon Lead Helmet";
	hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\PL_Helmet_co.paa)};
};
////////////////////Custom Helms////////////////////
class CLASS(CE_Adamant_HELMET): CLASS(CE_HELMETV2) {
	author = "505th Aux Team";
	scope = 2;
	scopeCurator = 2;
    scopeArsenal = 2;
	displayName = "[505] Custom Helmet (Adamant)";
    optreHUDStyle = "Glasses";
	hiddenSelectionsTextures[]  = {QPATHTOF(data\helmets\ce\Dexus_Helmet_co.paa)};
};
class CLASS(CE_Crawford_HELMET): CLASS(CE_HELMETV2) {
	author = "505th Aux Team";
	scope = 2;
	scopeCurator = 2;
    scopeArsenal = 2;
	displayName = "[505] Custom Helmet (Crawford)";
	hiddenSelectionsTextures[]  = {QPATHTOF(data\helmets\ce\Anvil_Helmet_co.paa)};
};
//////////////////////Field Caps/////////////////////
class CLASS(CE_FieldCap_505th): CLASS(FieldCap_Base) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Field Cap";
    hiddenSelections[] = {"camo"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\fieldcap\505th_CECap_co.paa)};
};
/////////////////////Pilot Helms/////////////////////
class CLASS(Pilot_Helmet): CLASS(505th_Pilot_Helmet_Base) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Pilot Helmet";
};