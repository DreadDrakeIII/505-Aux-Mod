class CLASS(Marine_Rifleman_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Rifleman);

    displayName = "INF 01 Marine [Rifleman]";

    uniformClass = QCLASS(Uniform_CE);
    weapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Predef);
};

class CLASS(Marine_Rifleman_Rolled_CE): CLASS(Marine_CE_Base) {
    SCOPE_PRIVATE;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Rifleman);

    displayName = "INF 01 Marine [Rifleman]";

    uniformClass = QCLASS(Uniform_CE_Rolled);
    weapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest_V2), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest_V2), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Rifleman_Backpack_Predef);
};

class CLASS(Marine_Autorifle_CE): CLASS(Marine_Rifleman_CE) {
    displayName = "INF 02 Marine [Autorifle]";
    editorPreview = EDITOR_PREVIEW(Marine_Autorifle);

    weapons[]= {
        "OPTRE_M73",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_M73",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Predef);
};

class CLASS(Marine_Marksman_CE): CLASS(Marine_Rifleman_CE) {
    displayName = "INF 03 Marine [Marksman]";
    editorPreview = EDITOR_PREVIEW(Marine_Marksman);

    weapons[]= {
        "srifle_DMR_02_F",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "srifle_DMR_02_F",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Marksman_Predef);
};

class CLASS(Marine_LAT_CE): CLASS(Marine_Rifleman_CE) {
    displayName = "INF 04 Marine [Light AT]";
    editorPreview = EDITOR_PREVIEW(Marine_Marksman);

    weapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "launch_MRAWS_green_F",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "launch_MRAWS_green_F",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_LAT_Predef);
};

class CLASS(Marine_Grenadier_CE): CLASS(Marine_Rifleman_CE) {
    displayName = "INF 05 Marine [Grenadier]";
    editorPreview = EDITOR_PREVIEW(Marine_Marksman);

    weapons[]= {
        "OPTRE_MA5AGL",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_MA5AGL",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Grenadier_Predef);
};

class CLASS(Marine_Breacher_CE): CLASS(Marine_Rifleman_CE) {
    displayName = "INF 06 Marine [Breacher]";
    editorPreview = EDITOR_PREVIEW(Marine_Marksman);

    weapons[]= {
        "OPTRE_MA5AGL",
        "Police_Bat",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_MA5AGL",
        "Police_Bat",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Breacher_Predef);
};

class CLASS(Corpsman_Rifleman_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Rifleman);

    displayName = "INF 07 Corpsman";

    uniformClass = QCLASS(Uniform_Corpsman_CE);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\medic\Medic_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    weapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Armour_Corpsman_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Armour_Corpsman_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(MedicalBackpack_Predef);
};

class CLASS(Corpsman_Rifleman_CE_Rolled): CLASS(Marine_CE_Base) {
    SCOPE_PRIVATE;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Rifleman);

    displayName = "INF 07 Corpsman";

    uniformClass = QCLASS(Uniform_Corpsman_CE_Rolled);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\medic\Medic_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformRolled_co.paa"};

    weapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Armour_Corpsman_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Armour_Corpsman_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(MedicalBackpack_Predef);
};

class CLASS(Marine_SquadLead_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Squadlead);

    displayName = "INF 08 Marine [Squadlead]";

    uniformClass = QCLASS(Uniform_SL_CE);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\sl\SL_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    weapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_SL), QCLASS(CE_Armour_SL_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_SL), QCLASS(CE_Armour_SL_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};

class CLASS(Marine_SquadLead_CE_Rolled): CLASS(Marine_CE_Base) {
    SCOPE_PRIVATE;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Squadlead);

    displayName = "INF 08 Marine [Squadlead]";

    uniformClass = QCLASS(Uniform_SL_CE_Rolled);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\sl\SL_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformRolled_co.paa"};

    weapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_SL), QCLASS(CE_Armour_SL_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_SL), QCLASS(CE_Armour_SL_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};

class CLASS(Marine_PlatoonLead_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_PlatoonLead);

    displayName = "INF 09 Marine [Platoonlead]";

    uniformClass = QCLASS(Uniform_PL_CE);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\pl\PL_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    weapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_PL), QCLASS(CE_Armour_PL_Vest_NSV2), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_PL), QCLASS(CE_Armour_PL_Vest_NSV2), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};

class CLASS(Marine_PlatoonLead_CE_Rolled): CLASS(Marine_CE_Base) {
    SCOPE_PRIVATE;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_PlatoonLead);

    displayName = "INF 09 Marine [Platoonlead]";

    uniformClass = QCLASS(Uniform_PL_CE_Rolled);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\pl\PL_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformRolled_co.paa"};

    weapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_MA5A",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_PL), QCLASS(CE_Armour_PL_Vest_NSV2), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_PL), QCLASS(CE_Armour_PL_Vest_NSV2), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};
////////////////////Custom Units////////////////////
class CLASS(Marine_Adamant_CE): CLASS(Marine_Rifleman_CE) {
    displayName = "J.Adamant";
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_Adamant_CE);

    uniformClass = QCLASS(Uniform_Adamant_CE);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\custom\Dexus_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    weapons[]= {
        "OPTRE_M73",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_M73",
        "OPTRE_M6B",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        QCLASS(CE_Adamant_HELMET), QCLASS(CE_Vest_Adamant_Pouches), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_Adamant_HELMET), QCLASS(CE_Vest_Adamant_Pouches), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_AutoRifle_Predef);
};

class CLASS(Marine_Crawford_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_Crawford_CE);

    displayName = "A.Crawford";

    uniformClass = QCLASS(Uniform_Crawford_CE);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\custom\Anvil_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    linkedItems[] = {
        QCLASS(CE_Crawford_HELMET), QCLASS(CE_Vest_Crawford), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_Crawford_HELMET), QCLASS(CE_Vest_Crawford), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Rifleman_Backpack_Predef);
};

class CLASS(Marine_Oliver_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_Crawford_CE);

    displayName = "D.Oliver";

    uniformClass = QCLASS(Uniform_Oliver_CE);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\custom\Drake_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    linkedItems[] = {
        QCLASS(CE_FieldCap_505th), QCLASS(CE_Vest_Oliver), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_FieldCap_505th), QCLASS(CE_Vest_Oliver), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};
////////////////////Crewman Units////////////////////
class CLASS(Marine_Jet_Pilot): CLASS(Pilot_Base) {
    SCOPE_PUBLIC;

    editorSubcategory = QEDSUBCAT(Crewmen);
    editorPreview = EDITOR_PREVIEW(Marine_Pilot);

    displayName = "[505th] Jet Pilot";

    uniformClass = QCLASS(Uniform_Pilot);
    weapons[] = {
        "OPTRE_M6D_Carbine_Black_F", "OPTRE_M6D_Carbine_Vis_Red", "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    respawnWeapons[] = {
        "OPTRE_M6D_Carbine_Black_F", "OPTRE_M6D_Carbine_Vis_Red", "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    linkedItems[] = {
        QCLASS(Jet_Pilot_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    respawnLinkedItems[] = {
        QCLASS(Jet_Pilot_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Pilot_Backpack);
};
class CLASS(Marine_Heli_Pilot): CLASS(Pilot_Base) {
    SCOPE_PUBLIC;

    editorSubcategory = QEDSUBCAT(Crewmen);
    editorPreview = EDITOR_PREVIEW(Marine_Pilot);

    displayName = "[505th] Heli Pilot";

    uniformClass = QCLASS(Uniform_Pilot);
    weapons[] = {
        "OPTRE_M6D_Carbine_Black_F", "OPTRE_M6D_Carbine_Vis_Red", "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    respawnWeapons[] = {
        "OPTRE_M6D_Carbine_Black_F", "OPTRE_M6D_Carbine_Vis_Red", "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    linkedItems[] = {
        QCLASS(Heli_Pilot_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    respawnLinkedItems[] = {
        QCLASS(Heli_Pilot_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", QCLASS(505th_Hud_Glasses), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Pilot_Backpack);
};