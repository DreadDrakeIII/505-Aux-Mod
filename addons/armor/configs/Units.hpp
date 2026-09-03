class CLASS(Marine_CE_Rifleman): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;
    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Rifleman);

    displayName = "INF 01 Marine [Rifleman]";

    uniformClass = QCLASS(Uniform_CE);
    weapons[]= {
        "OLI_MA37",
        "TCP_optic_EVOSJ",
        "OLI_MA37_LAM",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA37",
        "TCP_optic_EVOSJ",
        "OLI_MA37_LAM",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Predef);
};
class CLASS(Marine_CE_Rifleman_Rolled): CLASS(Marine_CE_Rolled_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Rifleman);

    displayName = "INF 01 Marine [Rifleman]";

    uniformClass = QCLASS(Uniform_CE_Rolled);
    hiddenSelection[] = {"camo","camo1"};
    hiddenSelectionTextures[] = {QPATHTOF(data\uniforms\ce\marine\Marine_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformRolled_co.paa"};
    weapons[]= {
        "OLI_MA37",
        "TCP_optic_EVOSJ",
        "OLI_MA37_LAM",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA37",
        "TCP_optic_EVOSJ",
        "OLI_MA37_LAM",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest_V2), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest_V2), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Rifleman_Backpack_Predef);
};

class CLASS(Marine_CE_Autorifle): CLASS(Marine_CE_Rifleman) {
    displayName = "INF 02 Marine [Autorifle]";
    editorPreview = EDITOR_PREVIEW(Marine_Autorifle);

    magazines[] = {
        "OLI_100Rnd_95x40_Box",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_100Rnd_95x40_Box",
        "OLI_12Rnd_127x40_Mag"
    };

    weapons[]= {
        "OLI_M73",
        "TCP_optic_EVOSM",
        "TCP_acc_carryHandle_M731",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_M73",
        "TCP_optic_EVOSM",
        "TCP_acc_carryHandle_M731",
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
    backpack = QCLASS(Backpack_AutoRifle_Predef);
};

class CLASS(Marine_CE_Marksman): CLASS(Marine_CE_Rifleman) {
    displayName = "INF 03 Marine [Marksman]";
    editorPreview = EDITOR_PREVIEW(Marine_Marksman);

    weapons[]= {
        "OLI_MR10_LONGBOW",
        "OPTRE_BR55HB_Scope",
        "OLI_MEQ7",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MR10_LONGBOW",
        "OPTRE_BR55HB_Scope",
        "OLI_MEQ7",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_15Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_15Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Marksman_Predef);
};

class CLASS(Marine_CE_LAT): CLASS(Marine_CE_Rifleman) {
    displayName = "INF 04 Marine [Light AT]";
    editorPreview = EDITOR_PREVIEW(Marine_LAT);

    weapons[]= {
        "OLI_MA37",
        "TCP_optic_EVOSJ",
        "OLI_MA37_LAM",
        "OLI_M6C",
        "launch_MRAWS_green_F",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA37",
        "TCP_optic_EVOSJ",
        "OLI_MA37_LAM",
        "OLI_M6C",
        "launch_MRAWS_green_F",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag",
        "MRAWS_HEAT_F"
    };
    respawnMagazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag",
        "MRAWS_HEAT_F"
    };
    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_LAT_Predef);
};

class CLASS(Marine_CE_Grenadier): CLASS(Marine_CE_Rifleman) {
    displayName = "INF 05 Marine [Grenadier]";
    editorPreview = EDITOR_PREVIEW(Marine_Grenadier);

    weapons[]= {
        "OLI_MA37GL",
        "TCP_optic_EVOSJ",
        "OLI_MA37_LAM",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA37GL",
        "TCP_optic_EVOSJ",
        "OLI_MA37_LAM",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag",
        "1Rnd_HE_Grenade_shell"
    };
    respawnMagazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag",
        "1Rnd_HE_Grenade_shell"
    };
    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Armour_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Grenadier_Predef);
};

class CLASS(Marine_CE_Corpsman): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Corpsman);

    displayName = "INF 06 Corpsman";

    uniformClass = QCLASS(Uniform_CE_Corpsman);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\medic\Medic_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    weapons[]= {
        "OLI_MA37",
        "TCP_optic_EVOSJ",
        "OLI_MA37_LAM",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA37",
        "TCP_optic_EVOSJ",
        "OLI_MA37_LAM",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Armour_Corpsman_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Armour_Corpsman_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(MedicalBackpack_Predef);
};

class CLASS(Corpsman_CE_Rifleman_Rolled): CLASS(Marine_CE_Rolled_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Rifleman);

    displayName = "INF 06 Corpsman";

    uniformClass = QCLASS(Uniform_CE_Corpsman_Rolled);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\medic\Medic_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformRolled_co.paa"};

    weapons[]= {
        "OLI_MA37",
        "TCP_optic_EVOSJ",
        "OLI_MA37_LAM",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA37",
        "TCP_optic_EVOSJ",
        "OLI_MA37_LAM",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Armour_Corpsman_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Armour_Corpsman_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(MedicalBackpack_Predef);
};

class CLASS(Marine_CE_SquadLead): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Squadlead);

    displayName = "INF 07 Marine [Squadlead]";

    uniformClass = QCLASS(Uniform_CE_SL);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\sl\SL_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    weapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSJ",
        "TCP_rail_ammoCounter_VK78",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSJ",
        "TCP_rail_ammoCounter_VK78",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_SL), QCLASS(CE_Armour_SL_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_SL), QCLASS(CE_Armour_SL_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};

class CLASS(Marine_CE_SquadLead_Rolled): CLASS(Marine_CE_Rolled_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_Squadlead);

    displayName = "INF 07 Marine [Squadlead]";

    uniformClass = QCLASS(Uniform_CE_SL_Rolled);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\sl\SL_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformRolled_co.paa"};

    weapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSJ",
        "TCP_rail_ammoCounter_VK78",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSJ",
        "TCP_rail_ammoCounter_VK78",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_SL), QCLASS(CE_Armour_SL_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_SL), QCLASS(CE_Armour_SL_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};

class CLASS(Marine_CE_PlatoonLead): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_PlatoonLead);

    displayName = "INF 08 Marine [Platoonlead]";

    uniformClass = QCLASS(Uniform_CE_PL);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\pl\PL_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    weapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSJ",
        "TCP_rail_ammoCounter_VK78",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSJ",
        "TCP_rail_ammoCounter_VK78",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_PL), QCLASS(CE_Armour_PL_Vest_NSV2), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_PL), QCLASS(CE_Armour_PL_Vest_NSV2), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};

class CLASS(Marine_CE_PlatoonLead_Rolled): CLASS(Marine_CE_Rolled_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_PlatoonLead);

    displayName = "INF 08 Marine [Platoonlead]";

    uniformClass = QCLASS(Uniform_CE_PL_Rolled);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\pl\PL_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformRolled_co.paa"};

    weapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSJ",
        "TCP_rail_ammoCounter_VK78",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSJ",
        "TCP_rail_ammoCounter_VK78",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_PL), QCLASS(CE_Armour_PL_Vest_NSV2), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_PL), QCLASS(CE_Armour_PL_Vest_NSV2), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};

class CLASS(Marine_CE_FR): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(INF_CE);
    editorPreview = EDITOR_PREVIEW(Marine_FR);

    displayName = "INF 09 Marine [Force Recon]";

    uniformClass = QCLASS(Uniform_CE_FR);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {
        QPATHTOF(data\uniforms\ce\forcerecon\Force_Recon_UniformP_co.paa),
        QPATHTOF(data\uniforms\ce\forcerecon\Force_Recon_UniformT_CO.paa)
    };

    weapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSJ",
        "TCP_rail_ammoCounter_VK78",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSJ",
        "TCP_rail_ammoCounter_VK78",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_10Rnd_HDUR",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_10Rnd_HDUR",
        "OLI_12Rnd_127x40_Mag"
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
        "OLI_LMR11_SHORTBOW",
        "OPTRE_BR55HB_Scope",
        "OLI_MEQ7",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_LMR11_SHORTBOW",
        "OPTRE_BR55HB_Scope",
        "OLI_MEQ7",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_30Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_30Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
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
class CLASS(Marine_CE_Adamant): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;

    displayName = "J.Adamant";

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_CE_Adamant);

    identityTypes[] = {QCLASS(Adamant)};

    uniformClass = QCLASS(Uniform_CE_Adamant);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\custom\Dexus_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    weapons[]= {
        "OLI_M73",
        "TCP_optic_EVOSM",
        "TCP_acc_carryHandle_M731",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_M73",
        "TCP_optic_EVOSM",
        "TCP_acc_carryHandle_M731",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_100Rnd_95x40_Box",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_100Rnd_95x40_Box",
        "OLI_12Rnd_127x40_Mag"
    };
    linkedItems[] = {
        QCLASS(CE_HELMET_Adamant), QCLASS(CE_Vest_Adamant_Pouches), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_Adamant), QCLASS(CE_Vest_Adamant_Pouches), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_AutoRifle_Predef);
};

class CLASS(Marine_CE_Crawford): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_CE_Crawford);

    identityTypes[] = {QCLASS(Crawford)};

    displayName = "A.Crawford";

    weapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSJ",
        "TCP_rail_ammoCounter_VK78",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSJ",
        "TCP_rail_ammoCounter_VK78",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };

    uniformClass = QCLASS(Uniform_CE_Crawford);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\custom\Anvil_UniformP_co.paa),QPATHTOF(data\uniforms\ce\custom\Anvil_UniformT_co.paa)};

    linkedItems[] = {
        QCLASS(CE_HELMET_Crawford), QCLASS(CE_Vest_Crawford), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_Crawford), QCLASS(CE_Vest_Crawford), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Rifleman_Backpack_Predef);
};

class CLASS(Marine_CE_Crawford_Rolled): CLASS(Marine_CE_Rolled_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    uniformClass = QCLASS(Uniform_CE_Crawford_Rolled);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\custom\Anvil_UniformP_co.paa),QPATHTOF(data\uniforms\ce\custom\Anvil_Uniform_RolledT_co.paa)};
};

class CLASS(Marine_CE_Oliver): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_CE_Oliver);

    identityTypes[] = {QCLASS(Oliver)};

    displayName = "D.Oliver";

    uniformClass = QCLASS(Uniform_CE_Oliver);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\custom\Drake_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    weapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSM",
        "TCP_acc_carryHandle_M731",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_VK78_COMMANDO",
        "TCP_optic_EVOSM",
        "TCP_acc_carryHandle_M731",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };

    linkedItems[] = {
        QCLASS(CE_FieldCap_505th), QCLASS(CE_Vest_Oliver), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_FieldCap_505th), QCLASS(CE_Vest_Oliver), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};

class CLASS(Marine_CE_Davy): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;

    displayName = "S.Davy";

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_CE_Davy);

    identityTypes[] = {QCLASS(Davy)};

    uniformClass = QCLASS(Uniform_CE_FR_Rolled);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {
        QPATHTOF(data\uniforms\ce\forcerecon\Force_Recon_UniformP_co.paa),
        QPATHTOF(data\uniforms\ce\forcerecon\Force_Recon_UniformT_CO.paa)
    };

    weapons[]= {
        "OLI_M73",
        "TCP_optic_EVOSM",
        "TCP_acc_carryHandle_M731",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_M73",
        "TCP_optic_EVOSM",
        "TCP_acc_carryHandle_M731",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_100Rnd_95x40_Box",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_100Rnd_95x40_Box",
        "OLI_12Rnd_127x40_Mag"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_FRV2), QCLASS(CE_Vest_FR_Davy), "OPTRE_NVG", "OLI_Tactical_Combat_Mask", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_FRV2), QCLASS(CE_Vest_FR_Davy), "OPTRE_NVG", "OLI_Tactical_Combat_Mask", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Invisible_Backpack_CE);
};

class CLASS(Marine_CE_Kain): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;

    displayName = "J.Kain";

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_CE_Kain);

    identityTypes[] = {QCLASS(Kain)};

    uniformClass = QCLASS(Uniform_CE_Kain);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\custom\Kain_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    weapons[]= {
        "OLI_MA37",
        "OPTRE_M12_Optic",
        "OLI_MEQ7",
        "OLI_M6G",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA37",
        "OPTRE_M12_Optic",
        "OLI_MEQ7",
        "OLI_M6G",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_8Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_8Rnd_127x40_Mag"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Vest_Kain), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Vest_Kain), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Predef);
};

class CLASS(Marine_CE_Doc): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_CE_Doc);

    identityTypes[] = {QCLASS(Doc)};

    displayName = "J.Doc";

    weapons[]= {
        "OLI_MA37",
        "OPTRE_M12_Optic",
        "OLI_MEQ7",
        "OLI_M6G",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA37",
        "OPTRE_M12_Optic",
        "OLI_MEQ7",
        "OLI_M6G",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_8Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_8Rnd_127x40_Mag"
    };

    uniformClass = QCLASS(Uniform_CE_Doc);
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
    backpack = QCLASS(MedicalBackpack_Predef);
};
class CLASS(Marine_CE_Saint): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_CE_Saint);

    identityTypes[] = {QCLASS(Saint)};

    displayName = "B.Saint";

    weapons[]= {
        "OLI_MA37",
        "OPTRE_M12_Optic",
        "OLI_MEQ7",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA37",
        "OPTRE_M12_Optic",
        "OLI_MEQ7",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
    };

    uniformClass = QCLASS(Uniform_CE_Corpsman);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\medic\Medic_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    linkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Vest_Saint), "OPTRE_NVG", QCLASS(Stealth_Mask), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_Corpsman), QCLASS(CE_Vest_Saint), "OPTRE_NVG", QCLASS(Stealth_Mask), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(MedicalBackpack_Predef);
};
class CLASS(Marine_CE_Handler): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_CE_Handler);

    identityTypes[] = {QCLASS(Handler)};

    displayName = "H.Handler";

    uniformClass = QCLASS(Uniform_CE_SL);
    hiddenSelections[] = {"camo","camo1"};
    hiddenSelectionsTextures[] = {QPATHTOF(data\uniforms\ce\sl\SL_UniformP_co.paa),"\Rogue_CEMarine\data\Rogue_CEUniformT_co.paa"};

    weapons[]= {
        "OLI_VK78_COMMANDO",
        "OPTRE_M12_Optic",
        "OLI_MEQ7",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_VK78_COMMANDO",
        "OPTRE_M12_Optic",
        "OLI_MEQ7",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_20Rnd_95xVX2_Mag",
        "OLI_12Rnd_127x40_Mag"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET_SL), QCLASS(CE_Vest_Hoffman), "OPTRE_NVG", QCLASS(Stealth_Mask), MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET_SL), QCLASS(CE_Vest_Hoffman), "OPTRE_NVG", QCLASS(Stealth_Mask), MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_SL_PL_Predef);
};
class CLASS(Marine_CE_Milan): CLASS(Marine_CE_Base) {
    SCOPE_HIDDEN;

    // Editor Properties
    editorSubcategory = QEDSUBCAT(Customs);
    editorPreview = EDITOR_PREVIEW(Marine_CE_Milan);

    identityTypes[] = {QCLASS(Milan)};

    displayName = "A.Milan";

    uniformClass = QCLASS(Uniform_CE);

    weapons[]= {
        "OLI_MA37",
        "OPTRE_M12_Optic",
        "OLI_MEQ7",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    respawnWeapons[]= {
        "OLI_MA37",
        "OPTRE_M12_Optic",
        "OLI_MEQ7",
        "OLI_M6C",
        "OPTRE_Smartfinder",
        "Throw",
        "Put"
    };
    magazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_40Rnd_762x51_Mag",
        "OLI_12Rnd_127x40_Mag"
    };

    linkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Vest_Milan), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    RespawnLinkedItems[] = {
        QCLASS(CE_HELMET), QCLASS(CE_Vest_Milan), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Backpack_Predef);
};
///////////////////Crewman Units/////////////////////
class CLASS(Marine_Jet_Pilot): CLASS(Pilot_Base) {
    SCOPE_PUBLIC;

    editorSubcategory = QEDSUBCAT(Crewmen);
    editorPreview = EDITOR_PREVIEW(Marine_Pilot_Jet);

    displayName = "AVI Jet Pilot";

    uniformClass = QCLASS(Uniform_Pilot);
    weapons[] = {
        "OLI_CPW", "OPTRE_M12_Optic", "OLI_M6C", "Throw", "Put"
    };
    respawnWeapons[] = {
        "OLI_CPW", "OPTRE_M12_Optic", "OLI_M6C", "Throw", "Put"
    };
    magazines[] = {
        "OLI_32Rnd_9x21_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_32Rnd_9x21_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    linkedItems[] = {
        QCLASS(Jet_Pilot_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    respawnLinkedItems[] = {
        QCLASS(Jet_Pilot_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Pilot_Backpack_Predef);
};
class CLASS(Marine_Heli_Pilot): CLASS(Pilot_Base) {
    SCOPE_PUBLIC;

    editorSubcategory = QEDSUBCAT(Crewmen);
    editorPreview = EDITOR_PREVIEW(Marine_Pilot_Heli);

    displayName = "AVI Heli Pilot";

    uniformClass = QCLASS(Uniform_Pilot);
    weapons[] = {
        "OLI_CPW", "OPTRE_M12_Optic", "OLI_M6C", "Throw", "Put"
    };
    respawnWeapons[] = {
        "OLI_CPW", "OPTRE_M12_Optic", "OLI_M6C", "Throw", "Put"
    };
    magazines[] = {
        "OLI_32Rnd_9x21_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_32Rnd_9x21_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    linkedItems[] = {
        QCLASS(Heli_Pilot_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    respawnLinkedItems[] = {
        QCLASS(Heli_Pilot_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Pilot_Backpack_Predef);
};
class CLASS(Marine_Heli_Crew): CLASS(Pilot_Base) {
    SCOPE_PUBLIC;

    editorSubcategory = QEDSUBCAT(Crewmen);
    editorPreview = EDITOR_PREVIEW(Marine_Pilot_Heli);

    displayName = "AVI Heli Crew";

    uniformClass = QCLASS(Uniform_Pilot);
    weapons[] = {
        "OLI_CPW", "OPTRE_M12_Optic", "OLI_M6C", "Throw", "Put"
    };
    respawnWeapons[] = {
        "OLI_CPW", "OPTRE_M12_Optic", "OLI_M6C", "Throw", "Put"
    };
    magazines[] = {
        "OLI_32Rnd_9x21_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    respawnMagazines[] = {
        "OLI_32Rnd_9x21_Mag",
        "OLI_12Rnd_127x40_Mag"
    };
    linkedItems[] = {
        QCLASS(Heli_Crew_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    respawnLinkedItems[] = {
        QCLASS(Heli_Crew_Helmet), QCLASS(Pilot_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Pilot_Backpack_Predef);
};
class CLASS(Marine_Tank_Crew): CLASS(Pilot_Base) {
    SCOPE_PUBLIC;

    editorSubcategory = QEDSUBCAT(Crewmen);
    editorPreview = EDITOR_PREVIEW(Marine_Tanker);

    displayName = "ARMR Tank Crew";

    uniformClass = QCLASS(Uniform_Pilot);
    weapons[] = {
        "OLI_M7_Caseless", "OPTRE_M12_Optic", "OLI_MEQ7", "OLI_MHG16", "Throw", "Put"
    };
    respawnWeapons[] = {
        "OLI_M7_Caseless", "OPTRE_M12_Optic", "OLI_MEQ7", "OLI_MHG16", "Throw", "Put"
    };
    magazines[] = {
        "OLI_60Rnd_9x21_Mag",
        "OLI_12Rnd_9x21_Mag"
    };
    respawnMagazines[] = {
        "OLI_60Rnd_9x21_Mag",
        "OLI_12Rnd_9x21_Mag"
    };
    linkedItems[] = {
        "OPTRE_UNSC_VX16_Helmet_Mask", QCLASS(CE_Armour_Scout_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    respawnLinkedItems[] = {
        "OPTRE_UNSC_VX16_Helmet_Mask", QCLASS(CE_Armour_Scout_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(Tanker_Backpack_Predef);
};
//////////////////BlackOp Units////////////////////
class CLASS(Unit_BlackOps): CLASS(BlackOps_Base) {
    SCOPE_PRIVATE;

    editorSubcategory = QEDSUBCAT(SpecialForces);
    faction = QFACTION(ONI);
    editorPreview = EDITOR_PREVIEW(Unit_BlackOps);

    displayName = " Black Ops";

    uniformClass = QCLASS(Uniform_BlackOps);
    weapons[] = {
        "OLI_BR55HB", "TCP_optic_M43RCO_CUP", "OLI_ANPEQ6G", "OLI_PUMA", "OPTRE_Smartfinder", "Throw", "Put"
    };
    respawnWeapons[] = {
        "OLI_BR55HB", "TCP_optic_M43RCO_CUP", "OLI_ANPEQ6G", "OLI_PUMA", "OPTRE_Smartfinder", "Throw", "Put"
    };
    magazines[] = {
        "OLI_36Rnd_95x40_Mag",
        "OLI_16Rnd_45ACP_Mag"
    };
    respawnMagazines[] = {
        "OLI_36Rnd_95x40_Mag",
        "OLI_16Rnd_45ACP_Mag"
    };
    linkedItems[] = {
        QCLASS(Black_Ops_Helmet), QCLASS(BlackOps_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    respawnLinkedItems[] = {
        QCLASS(Black_Ops_Helmet), QCLASS(BlackOps_Vest), "OPTRE_NVG", "OPTRE_HUD_In_Glasses", MARINE_LINKED_ITEMS_RADIO
    };
    backpack = QCLASS(BlackOps_Backpack_Predef);
};

class CLASS(Marine_TCP_Woodland_1): CLASS(Marine_TCP_Woodland_1_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    side = BLUFOR;
    faction = QFACTION(505th);
    editorSubcategory = QEDSUBCAT(INF_TCP);
    displayName = "Rifleman (Woodland 1)";
    uniformClass = QCLASS(CBUU_Woodland_1);

    hiddenSelectionsTextures[] = {
        "\TCP\Characters\BLUFOR\UNSC\Army\Uniforms\CBUU\data\camo\Woodland\CBUU_TacShirt_CO.paa",
        "\TCP\Characters\BLUFOR\UNSC\Army\Uniforms\CBUU\data\camo\Woodland\CBUU_Pants_CO.paa",
        "\TCP\Characters\BLUFOR\UNSC\Army\Uniforms\CBUU\data\camo\Black\CBUU_Gloves_CO.paa"
    };

    weapons[] = {"OLI_MA37","OPTRE_M12_Optic","OLI_MEQ7","OLI_M6C","OPTRE_Smartfinder","Throw","Put"};
    respawnWeapons[] = {"OLI_MA37","OPTRE_M12_Optic","OLI_MEQ7","OLI_M6C","OPTRE_Smartfinder","Throw","Put"};
    magazines[] = {"OLI_40Rnd_762x51_Mag","OLI_12Rnd_127x40_Mag"};
    respawnMagazines[] = {"OLI_40Rnd_762x51_Mag","OLI_12Rnd_127x40_Mag"};
    linkedItems[] = {QCLASS(ECH43A_Helmet_Olive_BV), QCLASS(M43_Heavy_Olive_1), "OPTRE_NVG", "", MARINE_LINKED_ITEMS_RADIO};
    respawnLinkedItems[] = {QCLASS(ECH43A_Helmet_Olive_BV), QCLASS(M43_Heavy_Olive_1), "OPTRE_NVG", "", MARINE_LINKED_ITEMS_RADIO};
    backpack = "OLI_Riflemen_Predef";
};

class CLASS(Marine_TCP_Woodland_2): CLASS(Marine_TCP_Woodland_2_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    side = BLUFOR;
    faction = QFACTION(505th);
    editorSubcategory = QEDSUBCAT(INF_TCP);
    displayName = "Rifleman (Woodland 2)";
    uniformClass = QCLASS(CBUU_Woodland_2);

    hiddenSelectionsTextures[] = {
        "\TCP\Characters\BLUFOR\UNSC\Army\Uniforms\CBUU\data\camo\Woodland\CBUU_TacShirt_CO.paa",
        "\TCP\Characters\BLUFOR\UNSC\Army\Uniforms\CBUU\data\camo\Woodland\CBUU_Pants_CO.paa",
        "\TCP\Characters\BLUFOR\UNSC\Army\Uniforms\CBUU\data\camo\Black\CBUU_Gloves_CO.paa"
    };

    weapons[] = {"OLI_MA37","OPTRE_M12_Optic","OLI_MEQ7","OLI_M6C","OPTRE_Smartfinder","Throw","Put"};
    respawnWeapons[] = {"OLI_MA37","OPTRE_M12_Optic","OLI_MEQ7","OLI_M6C","OPTRE_Smartfinder","Throw","Put"};
    magazines[] = {"OLI_40Rnd_762x51_Mag","OLI_12Rnd_127x40_Mag"};
    respawnMagazines[] = {"OLI_40Rnd_762x51_Mag","OLI_12Rnd_127x40_Mag"};
    linkedItems[] = {QCLASS(CH43A_Helmet_Olive), QCLASS(M43_Medium_Olive_1), "OPTRE_NVG", "TCP_G_BalaclavaTacticalGlasses_Black_Blue", MARINE_LINKED_ITEMS_RADIO};
    respawnLinkedItems[] = {QCLASS(CH43A_Helmet_Olive), QCLASS(M43_Medium_Olive_1), "OPTRE_NVG", "TCP_G_BalaclavaTacticalGlasses_Black_Blue", MARINE_LINKED_ITEMS_RADIO};
    backpack = "OLI_Riflemen_Predef";
};

class CLASS(Marine_TCP_Black_1): CLASS(Marine_TCP_Urban_1_Base) {
    SCOPE_PUBLIC;
    author = AUTHOR;
    side = BLUFOR;
    faction = QFACTION(505th);
    editorSubcategory = QEDSUBCAT(INF_TCP);
    displayName = "Rifleman (Black 1)";
    uniformClass = QCLASS(CBUU_Urban_1);

    hiddenSelectionsTextures[] = {
        "\TCP\Characters\BLUFOR\UNSC\Army\Uniforms\CBUU\data\camo\Urban\CBUU_TacShirt_CO.paa",
        "\TCP\Characters\BLUFOR\UNSC\Army\Uniforms\CBUU\data\camo\Urban\CBUU_Pants_CO.paa",
        "\TCP\Characters\BLUFOR\UNSC\Army\Uniforms\CBUU\data\camo\Black\CBUU_Gloves_CO.paa"
    };

    weapons[] = {"OLI_MA37","OPTRE_M12_Optic","OLI_MEQ7","OLI_M6C","OPTRE_Smartfinder","Throw","Put"};
    respawnWeapons[] = {"OLI_MA37","OPTRE_M12_Optic","OLI_MEQ7","OLI_M6C","OPTRE_Smartfinder","Throw","Put"};
    magazines[] = {"OLI_40Rnd_762x51_Mag","OLI_12Rnd_127x40_Mag"};
    respawnMagazines[] = {"OLI_40Rnd_762x51_Mag","OLI_12Rnd_127x40_Mag"};
    linkedItems[] = {QCLASS(CH43A_Helmet_Olive), QCLASS(M43_Kevlar_Black_1), "OPTRE_NVG", "TCP_G_BalaclavaTacticalGlasses_Black_Blue", MARINE_LINKED_ITEMS_RADIO};
    respawnLinkedItems[] = {QCLASS(CH43A_Helmet_Olive), QCLASS(M43_Kevlar_Black_1), "OPTRE_NVG", "TCP_G_BalaclavaTacticalGlasses_Black_Blue", MARINE_LINKED_ITEMS_RADIO};
    backpack = "";
};
