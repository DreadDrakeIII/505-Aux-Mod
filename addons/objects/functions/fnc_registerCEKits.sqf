/*
    File: fn_oliceloadouts.sqf
    Author: 505th Dev Team
    Description:
        Registers all 505th WBK kits (Armor Locker version).
*/

params ["_locker"];

// Wait for object to be ready
sleep 1;

// systemChat "[EHB] Registering CE WBK Kits...";

[
    _locker,
    "Rifleman",
    [["OLI_MA5C","","OLI_MEQ7","",["OLI_32Rnd_762x51_Mag",32],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_Uniform_CE_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1],["OLI_8Rnd_127x40_Mag",3,8]]],["OLI_CE_Armour_Vest_V2",[["OLI_32Rnd_762x51_Mag",10,32]]],["OLI_Invisible_Backpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152_15","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OLI_MA5C","OLI_BR45B","OLI_M295_BMR","OLI_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OLI_MEQ7","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","OLI_Uniform_CE","OLI_Uniform_CE_Rolled","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Grenadier",
    [["OLI_MA5CGL","","OLI_MEQ7","",["OLI_32Rnd_762x51_Mag",32],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_Uniform_CE",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1],["OLI_8Rnd_127x40_Mag",3,8]]],["OLI_CE_Armour_Vest_V2Pouch",[["OLI_32Rnd_762x51_Mag",10,32]]],["OLI_Backpack_CE_505",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["UGL_FlareCIR_F",3,1],["UGL_FlareRed_F",3,1],["UGL_FlareWhite_F",3,1],["OPTRE_signalSmokeB",3,1],["OPTRE_signalSmokeG",3,1],["OPTRE_signalSmokeP",3,1],["OPTRE_signalSmokeR",3,1],["UGL_FlareGreen_F",3,1],["UGL_FlareWhite_Illumination_F",5,1],["OPTRE_1Rnd_Smoke_Grenade_shell",10,1],["1Rnd_HE_MEU_shell",20,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OLI_MA5CGL","OLI_BR45BGL","OLI_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OLI_MEQ7","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","OLI_Uniform_CE","OLI_Uniform_CE_Rolled","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","WNZ_EMP40mm_Grenade_Magazine","ACE_40mm_Pike","1Rnd_9Bang_MEU_shell","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Light Machine Gunner",
    [["OLI_M73","","OLI_MEQ7","",["OLI_100Rnd_95x40_Box",100],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_Uniform_CE",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1]]],["OLI_CE_Armour_Vest",[]],["OLI_Backpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],["OLI_100Rnd_95x40_Box",3,100],["OLI_8Rnd_127x40_Mag",3,8],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OLI_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OLI_MEQ7","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","OLI_Uniform_CE","OLI_Uniform_CE_Rolled","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Marksman",
    [["OLI_MR10_LONGBOW","","OLI_MEQ7","OPTRE_BR55HB_Scope",["OLI_15Rnd_95xVX2_Mag",15],[],"bipod_01_F_blk"],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_Uniform_CE_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1],["OLI_8Rnd_127x40_Mag",3,8]]],["Rogue_CEArmourScout",[["OLI_15Rnd_95xVX2_Mag",10,15]]],["OLI_ScoutBackpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"Rogue_CEBoonieGrey","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OLI_MR10_LONGBOW","OLI_LMR11_SHORTBOW","OLI_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_BR45_Scope","optic_DMS","OPTRE_M12_Optic","OLI_MEQ7","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","OLI_Uniform_CE","OLI_Uniform_CE_Rolled","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Light Anti Tank",
    [["OLI_MA5C","","OLI_MEQ7","",["OLI_32Rnd_762x51_Mag",32],[],""],["MEU_Cricket","","ACE_DBAL_A3_Red","",["OPTRE_1Rnd_50x137_HEAT",1],[],""],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_Uniform_CE_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1],["OLI_8Rnd_127x40_Mag",3,8]]],["OLI_CE_Armour_Vest_V2",[["OLI_32Rnd_762x51_Mag",10,32]]],["OLI_Invisible_Backpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],["OPTRE_1Rnd_50x137_HEAT",5,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OLI_MA5C","OLI_BR45B","OLI_M295_BMR","OLI_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OLI_MEQ7","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","OLI_Uniform_CE","OLI_Uniform_CE_Rolled","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Squad Leader",
    [["OLI_MA37K","","OLI_MEQ7","",["OLI_32Rnd_762x51_Mag",32],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_Uniform_CE_SL_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",4,1],["OPTRE_M2_Smoke_Red",4,1],["OPTRE_M2_Smoke_Green",4,1],["OLI_8Rnd_127x40_Mag",3,8]]],["OLI_CE_Armour_SL_Vest_NSV2",[["OLI_32Rnd_762x51_Mag",10,32]]],["OLI_Backpack_CE_505",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["ItemcTab",1],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMET_SLV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OLI_MA37K","OLI_MA5C","OLI_BR45B","OLI_M295_BMR","OLI_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OLI_MEQ7","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMET_SLV2","OLI_CE_HELMET_SL","OLI_Uniform_CE_SL","OLI_Uniform_CE_SL_Rolled","OLI_CE_Armour_SL_Vest","OLI_CE_Armour_SL_Vest_NSV2","OLI_CE_Armour_SL_Vest_V2","OLI_CE_Armour_SL_Vest_NS","OLI_CE_Armour_SL_Vest_V2Pouch","OLI_CE_Armour_SL_Vest_NSV2Pouch","OLI_CE_Armour_SL_Vest_NSPouch","OLI_CE_Armour_SL_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask","OLI_Stealth_Mask"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Platoon Leader",
    [["OLI_MA37K","","OLI_MEQ7","",["OLI_32Rnd_762x51_Mag",32],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_Uniform_CE_PL",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",4,1],["OPTRE_M2_Smoke_Red",4,1],["OPTRE_M2_Smoke_Green",4,1],["OLI_8Rnd_127x40_Mag",3,8]]],["OLI_CE_Armour_PL_Vest_NS",[["OLI_32Rnd_762x51_Mag",10,32]]],["OLI_LR_Antenna_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["ItemcTab",1],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_FieldCap_505th","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OLI_MA37K","OLI_MA5C","OLI_BR45B","OLI_M295_BMR","OLI_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OLI_MEQ7","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_FieldCap_505th","OLI_CE_HELMET_PLV2","OLI_CE_HELMET_PL","OLI_Uniform_CE_PL","OLI_Uniform_CE_PL_Rolled","OLI_CE_Armour_PL_Vest","OLI_CE_Armour_PL_Vest_NSV2","OLI_CE_Armour_PL_Vest_V2","OLI_CE_Armour_PL_Vest_NS","OLI_CE_Armour_PL_Vest_V2Pouch","OLI_CE_Armour_PL_Vest_NSV2Pouch","OLI_CE_Armour_PL_Vest_NSPouch","OLI_CE_Armour_PL_Vest_Pouch","OLI_LR_Antenna_CE","OLI_BackpackLR_CE","OLI_BackpackLR_CE_505","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask"],
    "true",
    {}
] spawn Wbk_AddKit;

[

    _locker,
    "Anti-Air",
    [["OLI_MA5C","","OLI_MEQ7","",["OLI_32Rnd_762x51_Mag",32],[],""],["MEU_Spkr_S108","","","",["MEU_SPKR108_SAM_AA",1],[],""],["OLI_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_CE_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1],["OLI_8Rnd_127x40_Mag",3,8]]],["OLI_CE_Armour_Vest_V2",[["OLI_32Rnd_762x51_Mag",10,32]]],["OLI_Backpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],["MEU_SPKR108_SAM_AA",5,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OLI_MA5C","OLI_BR45B","OLI_M295_BMR","OLI_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OLI_MEQ7","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","OLI_Uniform_CE","OLI_Uniform_CE_Rolled","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Heavy Anti-Tank",
    [["OLI_MA5C","","OLI_MEQ7","",["OLI_32Rnd_762x51_Mag",32],[],""],["OPTRE_M41_SSR","","","",["OPTRE_M41_Twin_HEAT_SACLOS",2],[],""],["OPTRE_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_CE_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1]]],["OLI_CE_Armour_Vest_V2",[["OLI_32Rnd_762x51_Mag",10,32]]],["OLI_Backpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],["OPTRE_M41_Twin_HEAT_SACLOS",3,2],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OLI_MA5C","OLI_BR45B","OLI_M295_BMR","OLI_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OLI_MEQ7","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","OLI_Uniform_CE","OLI_Uniform_CE_Rolled","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask"],
    "true",
    {}
] spawn Wbk_AddKit;

[
  _locker,
  "Weapons Specialist",
    [["OLI_MA5C","","OLI_MEQ7","",["OLI_32Rnd_762x51_Mag",32],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_Uniform_CE_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["KAT_Empty_bloodIV_250",1],["kat_IFAK",1],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",2,1],["OPTRE_M2_Smoke_Blue",1,1],["OLI_8Rnd_127x40_Mag",2,8],["OPTRE_M9_Frag",1,1],[["UNSC_Knife","","","",[],[],""],1]]],["OLI_CE_Armour_Vest_V2",[["OLI_32Rnd_762x51_Mag",10,32]]],[],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152_15","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OLI_MA5C","OLI_BR45B","OLI_M295_BMR","OLI_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OLI_MEQ7","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","OLI_Uniform_CE","OLI_Uniform_CE_Rolled","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OPTRE_M247T_Tripod_bag","OPTRE_M247T_Weapon_bag","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask"],
    "true",
  {}
] spawn Wbk_AddKit;

// systemChat "[505th] CE Kits registered successfully!";
