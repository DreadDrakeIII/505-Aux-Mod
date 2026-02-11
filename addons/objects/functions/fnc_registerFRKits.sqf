/*
    505th Expeditionary Force - FR Kit Registration Function
    Registers all FR kits with WBK Arsenal system

    Params:
        _locker - The locker object to register kits to
*/

params ["_locker"];

// Wait for object to be ready
sleep 1;

// systemChat "[505th] Registering FR WBK Kits...";

[
    _locker,
    "Rifleman",
    [["OLI_BR45B","","OLI_MEQ7","",["OLI_32Rnd_95x40_Mag",32],[],"OPTRE_BR45Grip"],[],["OLI_PUMA","","acc_flashlight_pistol","",["OLI_16Rnd_45ACP_Mag",16],[],""],["OLI_Uniform_CE_FR_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["ACE_MapTools",1],["ACE_ATragMX",1],["ACE_Kestrel4500",1],["ACE_microDAGR",1],["ACE_RangeCard",1],["kat_Painkiller",1,4],["acex_intelitems_notepad",1,1],["Laserbatteries",2,1],["OPTRE_M2_Smoke_Blue",2,1],["OPTRE_M2_Smoke_Red",2,1],["OPTRE_M2_Smoke",3,1],["OLI_32Rnd_95x40_Mag",4,32],["OLI_16Rnd_45ACP_Mag",3,16],[["OPTRE_Smartfinder","","","",[],[],""],1]]],["OLI_CE_Armour_ForceRecon_Vest_V2",[["OPTRE_M9_Frag",4,1],["OLI_32Rnd_95x40_Mag",6,32]]],["OLI_Invisible_Backpack_CE",[["KAT_Empty_bloodIV_250",1],["kat_IFAK",1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMET_FRV2","OPTRE_HUD_g_Glasses",["OLI_Vector","","","",[],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OLI_BR45B","OLI_PUMA","OPTRE_MA5Suppressor","Optre_Recon_Sight","Optre_Recon_Sight_Green","Optre_Recon_Sight_Red","OLI_CE_HELMET_FRV2","OLI_CE_HELMET_FR","ReconCloaks_H_SniperHoodSpec_taiga","OLI_Uniform_CE_FR","OLI_Uniform_CE_FR_Rolled","OLI_CE_Armour_ForceRecon_Vest","OLI_CE_Armour_ForceRecon_Vest_V2","OLI_CE_Armour_ForceRecon_Vest_NS","OLI_CE_Armour_ForceRecon_Vest_V2Pouch","OLI_CE_Armour_ForceRecon_Vest_NSV2Pouch","OLI_CE_Armour_ForceRecon_Vest_Pouch","OLI_CE_Armour_ForceRecon_Vest_NSV2","OLI_BackpackLR_CE_FR","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "LAT",
    [["OLI_BR45B","","OLI_MEQ7","",["OLI_32Rnd_95x40_Mag",32],[],"OPTRE_BR45Grip"],["MEU_M57_Pilum_blk","","","meu_optic_pilum",["MEU_M57_Pilum_HEAT_Mag",2],["MEU_M57_Pilum_SpottingMag",40],""],["OLI_PUMA","","acc_flashlight_pistol","",["OLI_16Rnd_45ACP_Mag",16],[],""],["OLI_Uniform_CE_FR",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["ACE_MapTools",1],["ACE_ATragMX",1],["ACE_Kestrel4500",1],["ACE_microDAGR",1],["ACE_RangeCard",1],["kat_Painkiller",1,4],["acex_intelitems_notepad",1,1],["Laserbatteries",2,1],["OLI_32Rnd_95x40_Mag",5,32],["OPTRE_M2_Smoke_Blue",2,1],["OPTRE_M2_Smoke_Red",2,1],["OPTRE_M2_Smoke",3,1],[["OPTRE_Smartfinder","","","",[],[],""],1]]],["OLI_CE_Armour_ForceRecon_Vest_Pouch",[["OLI_16Rnd_45ACP_Mag",3,16],["OPTRE_M9_Frag",4,1],["OLI_32Rnd_95x40_Mag",5,32]]],["OLI_Backpack_LR_CE_FR",[["KAT_Empty_bloodIV_250",1],["kat_IFAK",1],["MEU_M57_Pilum_HEAT_Mag",2,2],["MEU_M57_Pilum_HE_Mag",2,2],["MEU_M57_Pilum_AP_Mag",2,2],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMET_FRV2","OPTRE_HUD_g_Glasses",["OLI_Vector","","","",[],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OLI_BR45B","OLI_PUMA","OPTRE_MA5Suppressor","Optre_Recon_Sight","Optre_Recon_Sight_Green","Optre_Recon_Sight_Red","OLI_CE_HELMET_FRV2","OLI_CE_HELMET_FR","ReconCloaks_H_SniperHoodSpec_taiga","OLI_Uniform_CE_FR","OLI_Uniform_CE_FR_Rolled","OLI_CE_Armour_ForceRecon_Vest","OLI_CE_Armour_ForceRecon_Vest_V2","OLI_CE_Armour_ForceRecon_Vest_NS","OLI_CE_Armour_ForceRecon_Vest_V2Pouch","OLI_CE_Armour_ForceRecon_Vest_NSV2Pouch","OLI_CE_Armour_ForceRecon_Vest_Pouch","OLI_CE_Armour_ForceRecon_Vest_NSV2","OLI_BackpackLR_CE_FR","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Sniper",
    [["OLI_VTR93_Vindicta","","","OLI_VTR_Scope",["OLI_10Rnd_HDUR",10],[],""],[],["OLI_PUMA","","acc_flashlight_pistol","",["OLI_16Rnd_45ACP_Mag",16],[],""],["OLI_Uniform_CE_FR",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["ACE_MapTools",1],["ACE_microDAGR",1],["ACE_ATragMX",1],["ACE_Kestrel4500",1],["ACE_RangeCard",1],["kat_Painkiller",1,4],["acex_intelitems_notepad",1,1],["Laserbatteries",2,1],["OPTRE_M2_Smoke_Blue",2,1],["OPTRE_M2_Smoke_Red",2,1],["OPTRE_M2_Smoke",3,1],["OLI_16Rnd_45ACP_Mag",3,16],[["OPTRE_Smartfinder","","","",[],[],""],1]]],["OLI_CE_Armour_ForceRecon_Vest_NS",[["OPTRE_M9_Frag",4,1],["OLI_10Rnd_HDUR",4,10]]],["OLI_Invisible_Backpack_CE",[["KAT_Empty_bloodIV_250",1],["kat_IFAK",1],["OLI_10Rnd_HDUR",6,10],[["UNSC_Knife","","","",[],[],""],1]]],"ReconCloaks_H_SniperHoodSpec_taiga","OLI_Stealth_Mask_Goggle",["OLI_Vector","","","",[],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OLI_VTR93_Vindicta","OLI_PUMA","OPTRE_MA5Suppressor","OLI_CE_HELMET_FRV2","OLI_CE_HELMET_FR","ReconCloaks_H_SniperHoodSpec_taiga","OLI_Uniform_CE_FR","OLI_Uniform_CE_FR_Rolled","OLI_CE_Armour_ForceRecon_Vest","OLI_CE_Armour_ForceRecon_Vest_V2","OLI_CE_Armour_ForceRecon_Vest_NS","OLI_CE_Armour_ForceRecon_Vest_V2Pouch","OLI_CE_Armour_ForceRecon_Vest_NSV2Pouch","OLI_CE_Armour_ForceRecon_Vest_Pouch","OLI_CE_Armour_ForceRecon_Vest_NSV2","OLI_BackpackLR_CE_FR","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask"],
    "true",
    {}
] spawn Wbk_AddKit;

// Add your other FR kits below (Rifleman, Marksman, LAT, Corpsman, Breacher, etc.)

// systemChat "[505th] FR Kits registered successfully!";
