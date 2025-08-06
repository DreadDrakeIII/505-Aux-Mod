
class CLASS(CE_HELMET): CLASS(Marine_Helmet_Base) {
	author = "505th Aux Team";
	scope = 2;
	scopeCurator = 2;
    scopeArsenal = 2;
	displayName = "[505th] Marine Helmet [Eyepiece]";
	hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\Helmet_co.paa)};
};
class CLASS(CE_HELMETV2): CLASS(Marine_Helmet_V2_Base) {
	author = "505th Aux Team";
	scope = 2;
	scopeCurator = 2;
    scopeArsenal = 2;
	displayName = "[505th] Marine Helmet";
	hiddenSelectionsTextures[] = {QPATHTOF(data\helmets\ce\Helmet_co.paa)};
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
class CLASS(CE_Adamant_HELMET): CLASS(CE_HELMETV2) {
	author = "505th Aux Team";
	scope = 2;
	scopeCurator = 2;
    scopeArsenal = 2;
	displayName = "[505th] Custom Helmet (Adamant)";
    optreHUDStyle = "Glasses";
	hiddenSelectionsTextures[]  = {QPATHTOF(data\helmets\ce\Dexus_Helmet_co.paa)};
};
class CLASS(CE_Crawford_HELMET): CLASS(CE_HELMETV2) {
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
///////////////////Black Ops Helms///////////////////
class CLASS(Black_Ops_Helmet): CLASS(505th_Black_Ops_Helmet_Base) {
    author = "505th Aux Team";
    scope = 2;
    scopeCurator = 2;
    scopeArsenal = 2;
    displayName = "[505th] Black Ops Helmet";
};
