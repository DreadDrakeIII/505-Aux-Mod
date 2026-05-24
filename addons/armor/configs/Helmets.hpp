
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
// ==============================================================================================
// ============================ CH43/A, ECH35/J and ECH43/A Helmets =============================
// ==============================================================================================
class CLASS(CH43A_Helmet_Olive): CLASS(CH43A_Helmet_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] CH43/A Helmet (Olive)";
    picture = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_CH43A\data\ui\Olive\icon_headgear_CH43A_CA.paa";
    hiddenSelections[] = {"camo","decals"};
    hiddenSelectionsTextures[] = {
        QPATHTOF(data\helmets\tcp\ch43a_co.paa),
        "\TCP\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\black\vest_M43_DecalSheet_CA.paa"
    };
    class TCP_uniformDecals: TCP_uniformDecals {
        decalColor = "white";
    };
    class ItemInfo: ItemInfo {
        hiddenSelections[] = {"camo","decals"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\helmets\tcp\ch43a_co.paa),
            "\TCP\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\black\vest_M43_DecalSheet_CA.paa"
        };
        class HitpointsProtectionInfo: HitpointsProtectionInfo {
            class Head {
                hitpointName = "HitHead";
                armor = 23;
                passThrough = 0.2;
            };
        };
    };
};

class CLASS(CH43A_Medic_Helmet_Olive): CLASS(CH43A_Helmet_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] CH43/A Medic Helmet (Olive)";
    picture = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_CH43A\data\ui\Olive\icon_headgear_CH43A_CA.paa";
    hiddenSelections[] = {"camo","decals"};
    hiddenSelectionsTextures[] = {
        QPATHTOF(data\helmets\tcp\ch43a_medic_co.paa),
        "\TCP\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\black\vest_M43_DecalSheet_CA.paa"
    };
    class TCP_uniformDecals: TCP_uniformDecals {
        decalColor = "white";
    };
    class ItemInfo: ItemInfo {
        hiddenSelections[] = {"camo","decals"};
        hiddenSelectionsTextures[] = {
            QPATHTOF(data\helmets\tcp\ch43a_medic_co.paa),
            "\TCP\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\black\vest_M43_DecalSheet_CA.paa"
        };
        class HitpointsProtectionInfo: HitpointsProtectionInfo {
            class Head {
                hitpointName = "HitHead";
                armor = 23;
                passThrough = 0.2;
            };
        };
    };
};

class CLASS(ECH35J_Helmet_Olive_BV): CLASS(ECH35J_Helmet_Olive_Blue_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] ECH35/J Helmet BV (Olive)";
};

class CLASS(ECH43A_Helmet_Olive_BV): CLASS(ECH43A_Helmet_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    displayName = "[505th] ECH43/A Helmet BV (Olive)";
    picture = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\data\ui\Olive\icon_headgear_ECH43A_Blue_CA.paa";
    TCP_visrClasses[] = {
    "OLI_ECH43A_Helmet_Olive_BV",
    "OLI_ECH43A_Helmet_Olive_BV_DP"
};
    class TCP_uniformDecals: TCP_uniformDecals {
        decalColor = "white";
    };
    hiddenSelections[] = {"camo","camo1","decals"};
    hiddenSelectionsTextures[] = {
        "\TCP\characters\BLUFOR\UNSC\Army\Headgear\helmet_CH43A\data\camo\Olive\helmet_CH43A_CO.paa",
        "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\data\camo\Blue\helmet_ECH43A_Visor_CO.paa",
        "\TCP\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\white\vest_M43_DecalSheet_CA.paa"
    };
    class ItemInfo: ItemInfo {
        uniformModel = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\h_helmet_ECH43A_Blue.p3d";
        hiddenSelections[] = {"camo","camo1","decals"};
        hiddenSelectionsTextures[] = {
            "\TCP\characters\BLUFOR\UNSC\Army\Headgear\helmet_CH43A\data\camo\Olive\helmet_CH43A_CO.paa",
            "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\data\camo\Blue\helmet_ECH43A_Visor_CO.paa",
            "\TCP\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\white\vest_M43_DecalSheet_CA.paa"
        };
        class HitpointsProtectionInfo: HitpointsProtectionInfo {
            class Head {
                hitpointName = "HitHead";
                armor = 23;
                passThrough = 0.2;
            };
        };
    };
};

class CLASS(ECH43A_Helmet_Olive_BV_DP): CLASS(ECH43A_Helmet_DP_Base) {
    scope = 1;
    scopeArsenal = 0;
    author = AUTHOR;
    displayName = "[505th] ECH43/A Helmet BV DP (Olive)";
    picture = "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\data\ui\Olive\icon_headgear_ECH43A_Blue_CA.paa";
    TCP_visrClasses[] = {
    "OLI_ECH43A_Helmet_Olive_BV",
    "OLI_ECH43A_Helmet_Olive_BV_DP"
};
    class TCP_uniformDecals: TCP_uniformDecals {
        decalColor = "white";
    };
    hiddenSelections[] = {"camo","camo1","decals"};
    hiddenSelectionsTextures[] = {
        "\TCP\characters\BLUFOR\UNSC\Army\Headgear\helmet_CH43A\data\camo\Olive\helmet_CH43A_CO.paa",
        "\TCP\Characters\BLUFOR\UNSC\Army\Headgear\helmet_ECH43A\data\camo\Blue\helmet_ECH43A_Visor_CA.paa",
        "\TCP\characters\BLUFOR\UNSC\ARMY\Vests\M43A\data\camo\white\vest_M43_DecalSheet_CA.paa"
    };
};
