class CLASS(Marine_Rifleman_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Rifleman);

    displayName = "INF 01 Marine [Rifleman]";

    uniformClass = QCLASS(Uniform_CE);
    weapons[]= {
        "OLI_MA5C",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA5C",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Predef);
};
class CLASS(Marine_Rifleman_Rolled_CE): CLASS(Marine_CE_Rolled_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Rifleman);

    displayName = "INF 01 Marine [Rifleman]";

    uniformClass = QCLASS(Uniform_CE_Rolled);
    hiddenSelection[] = {"camo","camo1"};
    hiddenSelectionTextures[] = {QPATHTOF(data\uniforms\ce\marine\Marine_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformRolled_co.paa"};
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
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest_V2), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest_V2), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Rifleman_Backpack_Predef);
};

class CLASS(Marine_Autorifle_CE): CLASS(Marine_Rifleman_CE) {
    displayName = "INF 02 Marine [Autorifle]";
    editorPreview = EDITOR_PREVIEW(Marine_Autorifle);

    magazines[] = {
        "OPTRE_100Rnd_95x40_Box_Tracer"
    };

    respawnMagazines[] = {
        "OPTRE_100Rnd_95x40_Box_Tracer"
    };

    weapons[]= {
        "OLI_M73",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_M73",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Predef);
};

class CLASS(Marine_Marksman_CE): CLASS(Marine_Rifleman_CE) {
    displayName = "INF 03 Marine [Marksman]";
    editorPreview = EDITOR_PREVIEW(Marine_Marksman);

    weapons[]= {
        "OLI_MR10_LONGBOW",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MR10_LONGBOW",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Marksman_Predef);
};

class CLASS(Marine_LAT_CE): CLASS(Marine_Rifleman_CE) {
    displayName = "INF 04 Marine [Light AT]";
    editorPreview = EDITOR_PREVIEW(Marine_LAT);

    weapons[]= {
        "OLI_MA5C",
        "OLI_M6C",
        "launch_MRAWS_green_F",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA5C",
        "OLI_M6C",
        "launch_MRAWS_green_F",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_LAT_Predef);
};

class CLASS(Marine_Grenadier_CE): CLASS(Marine_Rifleman_CE) {
    displayName = "INF 05 Marine [Grenadier]";
    editorPreview = EDITOR_PREVIEW(Marine_Grenadier);

    weapons[]= {
        "OLI_MA5CGL",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA5CGL",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Grenadier_Predef);
};

class CLASS(Corpsman_Rifleman_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Corpsman);

    displayName = "INF 07 Corpsman";

    uniformClass = QCLASS(Uniform_Corpsman_CE);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\medic\Medic_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    weapons[]= {
        "OLI_MA5C",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA5C",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Armour_Corpsman_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Armour_Corpsman_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(MedicalBackpack_Predef);
};

class CLASS(Corpsman_Rifleman_CE_Rolled): CLASS(Marine_CE_Rolled_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Rifleman);

    displayName = "INF 07 Corpsman";

    uniformClass = QCLASS(Uniform_CE_Corpsman_Rolled);
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
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Armour_Corpsman_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Armour_Corpsman_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
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
        "OLI_VK78_COMMANDO",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_VK78_COMMANDO",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_SL), QCLASS(CE_Armour_SL_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_SL), QCLASS(CE_Armour_SL_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};

class CLASS(Marine_SquadLead_CE_Rolled): CLASS(Marine_CE_Rolled_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Squadlead);

    displayName = "INF 08 Marine [Squadlead]";

    uniformClass = QCLASS(Uniform_CE_SL_Rolled);
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
        QCLASS(CE_HELMET_SL), QCLASS(CE_Armour_SL_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_SL), QCLASS(CE_Armour_SL_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
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
        "OLI_VK78_COMMANDO",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_VK78_COMMANDO",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_PL), QCLASS(CE_Armour_PL_Vest_NSV2), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_PL), QCLASS(CE_Armour_PL_Vest_NSV2), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};

class CLASS(Marine_PlatoonLead_CE_Rolled): CLASS(Marine_CE_Rolled_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_PlatoonLead);

    displayName = "INF 09 Marine [Platoonlead]";

    uniformClass = QCLASS(Uniform_CE_PL_Rolled);
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
        QCLASS(CE_HELMET_PL), QCLASS(CE_Armour_PL_Vest_NSV2), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_PL), QCLASS(CE_Armour_PL_Vest_NSV2), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};

class CLASS(Marine_FR_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    // Editor Propertiesaa
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_FR);

    displayName = "INF 10 Marine [Force Recon]";

    uniformClass = QCLASS(Uniform_FR_CE);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {
        QPATHTOF(data\uniforms\ce\forcerecon\Force_Recon_UniformP_co.paa),
        QPATHTOF(data\uniforms\ce\forcerecon\Force_Recon_UniformT_CO.paa)
    };

    weapons[]= {
        "OLI_VTR93_Vindicta",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_VTR93_Vindicta",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_FRV2), QCLASS(CE_Armour_ForceRecon_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_FRV2), QCLASS(CE_Armour_ForceRecon_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_FR_Predef);
};

class CLASS(Marine_CE_FR_Rolled): CLASS(Marine_CE_Rolled_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_FR);

    displayName = "INF 10 Marine [Force Recon]";

    uniformClass = QCLASS(Uniform_CE_FR_Rolled);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {
        QPATHTOF(data\uniforms\ce\forcerecon\Force_Recon_UniformP_co.paa),
        QPATHTOF(data\uniforms\ce\forcerecon\Force_Recon_Uniform_RolledT_CO.paa)
    };

    weapons[]= {
        "OPTRE_M393_DMR",
        "OPTRE_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OPTRE_M393_DMR",
        "OPTRE_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_FRV2), QCLASS(CE_Armour_ForceRecon_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_FRV2), QCLASS(CE_Armour_ForceRecon_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_FR_Predef);
};

//////////////////////Custom Unit//////////////////////
class CLASS(Marine_Adamant_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    displayName = "J.Adamant";

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_Adamant_CE);

    identityTypes[] = {QCLASS(Adamant)};

    uniformClass = QCLASS(Adamant_Uniform_CE);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\custom\Dexus_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    weapons[]= {
        "OLI_M73",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_M73",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    linkedItems[] = {
        QCLASS(CE_Adamant_HELMET), QCLASS(CE_Vest_Adamant_Pouches), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_Adamant_HELMET), QCLASS(CE_Vest_Adamant_Pouches), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_AutoRifle_Predef);
};

class CLASS(Marine_Crawford_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_Crawford_CE);

    identityTypes[] = {QCLASS(Crawford)};

    displayName = "A.Crawford";

    weapons[]= {
        "OLI_VK78_COMMANDO",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_VK78_COMMANDO",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    uniformClass = QCLASS(Crawford_Uniform_CE);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\custom\Anvil_UniformP_co.paa),QPATHTOF(data\uniforms\ce\custom\Anvil_UniformT_co.paa)};

    linkedItems[] = {
        QCLASS(CE_Crawford_HELMET), QCLASS(CE_Vest_Crawford), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_Crawford_HELMET), QCLASS(CE_Vest_Crawford), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Rifleman_Backpack_Predef);
};

class CLASS(Marine_Oliver_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_Oliver_CE);

    identityTypes[] = {QCLASS(Oliver)};

    displayName = "D.Oliver";

    uniformClass = QCLASS(Oliver_Uniform_CE);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\custom\Drake_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    linkedItems[] = {
        QCLASS(CE_FieldCap_505th), QCLASS(CE_Vest_Oliver), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_FieldCap_505th), QCLASS(CE_Vest_Oliver), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};

class CLASS(Marine_Davy_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    displayName = "S.Davy";

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_Davy_CE);

    identityTypes[] = {QCLASS(Davy)};

    uniformClass = QCLASS(Uniform_CE_FR_Rolled);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {
        QPATHTOF(data\uniforms\ce\forcerecon\Force_Recon_UniformP_co.paa),
        QPATHTOF(data\uniforms\ce\forcerecon\Force_Recon_UniformT_CO.paa)
    };

    weapons[]= {
        "OLI_M98_Harvester",
        "OLI_M6G",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_M98_Harvester",
        "OLI_M6G",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_FRV2), QCLASS(CE_Vest_FR_Davy), "OPTRE_NVG", "OLI_DAVY_MASK", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_FRV2), QCLASS(CE_Vest_FR_Davy), "OPTRE_NVG", "OLI_DAVY_MASK", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Invisible_Backpack_CE);
};

class CLASS(Marine_Kain_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    displayName = "J.Kain";

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_Kain_CE);

    identityTypes[] = {QCLASS(Kain)};

    uniformClass = QCLASS(Uniform_CE);
    weapons[]= {
        "OLI_MA5C",
        "OLI_M6G",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA5C",
        "OLI_M6G",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Vest_Kain), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Vest_Kain), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Predef);
};

class CLASS(Marine_Doc_CE): CLASS(Marine_CE_Base) {
    SCOPE_PUBLIC;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_Doc_CE);

    identityTypes[] = {QCLASS(Doc)};

    displayName = "J.Doc";

    weapons[]= {
        "OLI_MA5C",
        "OLI_M6G",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA5C",
        "OLI_M6G",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };

    uniformClass = QCLASS(Doc_Uniform_CE);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {
        QPATHTOF(data\uniforms\ce\custom\Doc_UniformP_co.paa),
        QPATHTOF(data\uniforms\ce\custom\Doc_UniformT_co.paa)
        };

    linkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Vest_Doc), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Vest_Doc), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Rifleman_Backpack_Predef);
};
/////////////////////Crewman Units/////////////////////
// class CLASS(Marine_Jet_Pilot): CLASS(Pilot_Base) {
//     SCOPE_PUBLIC;

//     editorSubcategory = QEDSUBCAT(Crewmen);
//     editorPreview = EDITOR_PREVIEW(Marine_Pilot_Jet);

//     displayName = "AVI Jet Pilot";

//     uniformClass = QCLASS(Uniform_Pilot);
//     weapons[] = {
//         "OPTRE_M6D_Carbine_Black_F", "OPTRE_M319s", "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     respawnWeapons[] = {
//         "OPTRE_M6D_Carbine_Black_F", "OPTRE_M319s", "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     linkedItems[] = {
//         QCLASS(Jet_Pilot_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     respawnLinkedItems[] = {
//         QCLASS(Jet_Pilot_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     backpack = QCLASS(Pilot_Backpack_Predef);
// };
// class CLASS(Marine_Heli_Pilot): CLASS(Pilot_Base) {
//     SCOPE_PUBLIC;

//     editorSubcategory = QEDSUBCAT(Crewmen);
//     editorPreview = EDITOR_PREVIEW(Marine_Pilot_Heli);

//     displayName = "AVI Heli Pilot";

//     uniformClass = QCLASS(Uniform_Pilot);
//     weapons[] = {
//         "OPTRE_M6D_Carbine_Black_F", "OPTRE_M319s", "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     respawnWeapons[] = {
//         "OPTRE_M6D_Carbine_Black_F", "OPTRE_M319s", "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     linkedItems[] = {
//         QCLASS(Heli_Pilot_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     respawnLinkedItems[] = {
//         QCLASS(Heli_Pilot_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     backpack = QCLASS(Pilot_Backpack_Predef);
// };
// class CLASS(Marine_Heli_Crew): CLASS(Pilot_Base) {
//     SCOPE_PUBLIC;

//     editorSubcategory = QEDSUBCAT(Crewmen);
//     editorPreview = EDITOR_PREVIEW(Marine_Pilot_Heli);

//     displayName = "AVI Heli Crew";

//     uniformClass = QCLASS(Uniform_Pilot);
//     weapons[] = {
//         "OPTRE_M6D_Carbine_Black_F", "OPTRE_M319s", "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     respawnWeapons[] = {
//         "OPTRE_M6D_Carbine_Black_F", "OPTRE_M319s", "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     linkedItems[] = {
//         QCLASS(Heli_Crew_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     respawnLinkedItems[] = {
//         QCLASS(Heli_Crew_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     backpack = QCLASS(Pilot_Backpack_Predef);
// };
// class CLASS(Marine_Tank_Crew): CLASS(Pilot_Base) {
//     SCOPE_PUBLIC;

//     editorSubcategory = QEDSUBCAT(Crewmen);
//     editorPreview = EDITOR_PREVIEW(Marine_Tanker);

//     displayName = "ARMR Tank Crew";

//     uniformClass = QCLASS(Uniform_Pilot);
//     weapons[] = {
//         "OPTRE_M7", "TKE_MDPistolBlack", "Throw", "Put"
//     };
//     respawnWeapons[] = {
//         "OPTRE_M7", "TKE_MDPistolBlack", "Throw", "Put"
//     };
//     linkedItems[] = {
//         "OPTRE_UNSC_VX16_Helmet_Mask", QCLASS(CE_Armour_Scout_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     respawnLinkedItems[] = {
//         "OPTRE_UNSC_VX16_Helmet_Mask", QCLASS(CE_Armour_Scout_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     backpack = QCLASS(Tanker_Backpack_Predef);
// };
////////////////////BlackOp Units////////////////////
// class CLASS(Unit_BlackOps): CLASS(BlackOps_Base) {
//     SCOPE_PRIVATE;

//     editorSubcategory = QEDSUBCAT(SpecialForces);
//     faction = QFACTION(ONI);
//     editorPreview = EDITOR_PREVIEW(Unit_BlackOps);

//     displayName = " Black Ops";

//     uniformClass = QCLASS(Uniform_BlackOps);
//     weapons[] = {
//         "WRS_Weapon_AR_Black", "WBK_SciFi_Pistol_Black","muzzle_snds_acp","acc_flashlight_pistol", "OPTRE_Smartfinder"
//     };
//     respawnWeapons[] = {
//         "WRS_Weapon_AR_Black", "WBK_SciFi_Pistol_Black","muzzle_snds_acp","acc_flashlight_pistol", "OPTRE_Smartfinder",
//     };
//     linkedItems[] = {
//         QCLASS(Black_Ops_Helmet), QCLASS(BlackOps_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     respawnLinkedItems[] = {
//         QCLASS(Black_Ops_Helmet), QCLASS(BlackOps_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
//     };
//     backpack = QCLASS(BlackOps_Backpack_Predef);
// };
