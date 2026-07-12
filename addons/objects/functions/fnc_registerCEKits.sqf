/*
    CE Loadout
    Author: 505th Dev Team
*/

params ["_locker"];

sleep 1;

[
    _locker,
    "Marine Rifleman",
    [["OLI_MA37_NoLight","TCP_muzzle_brake_762_01","OLI_MA37_LAM","TCP_optic_EVOSJ",["OLI_40Rnd_762x51_Mag",40],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag",8],[],""],["OLI_CBUU_Woodland_1",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["ItemAndroid",1],["WBK_HeadLampItem_Double",1],["kat_Painkiller",1,4],["TCP_M21_Smoke",5,1],["TCP_M21_SmokeBlue",3,1]]],["OLI_M43_Heavy_Olive_1",[]],["TCP_B_Rifleman_1_M43_Medium_Rucksack_Olive",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OLI_EndurexBoosterInhaler",3],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CH43A_Helmet_Olive","OLI_Tactical_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG_HURS"]],
    ["OLI_MA37_NoLight","OLI_BR55HB","OLI_M6G","OLI_M6C","OLI_MHG16","OLI_40Rnd_762x51_Mag","OLI_36Rnd_95x40_Mag","OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","TCP_optic_M43RCO","TCP_muzzle_brake_762_01","TCP_muzzle_brake_95_01","OLI_ANPEQ6G","TCP_H_Helmet_ECH43A_Olive_Blue","OLI_CH43A_Helmet_Olive","TCP_H_boonieHat_Olive","H_Watchcap_blk","H_Bandanna_gry","OLI_Tactical_Glasses","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black","OLI_CBUU_Woodland_1","OLI_CBUU_Woodland_2","TCP_B_Rifleman_1_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_2_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_3_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_4_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_5_M43_Medium_Rucksack_Olive"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Marine LAT",
    [["OLI_MA37_NoLight","TCP_muzzle_brake_762_01","OLI_MA37_LAM","TCP_optic_EVOSJ",["OLI_40Rnd_762x51_Mag",40],[],""],["MEU_Cricket","","","",["OPTRE_1Rnd_50x137_HEAT",1],[],""],["OLI_M6G","","","TCP_optic_KFA_M6G",[],[],""],["OLI_CBUU_Woodland_1",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["ItemAndroid",1],["WBK_HeadLampItem_Double",1],["kat_Painkiller",1,4],["TCP_M21_Smoke",5,1],["TCP_M21_SmokeBlue",3,1]]],["OLI_M43_Heavy_Olive_1",[]],["TCP_B_Rifleman_1_M43_Medium_Rucksack_Olive",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OLI_EndurexBoosterInhaler",3],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CH43A_Helmet_Olive","OLI_Tactical_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG_HURS"]],
    ["OLI_MA37","OLI_BR55HB","OLI_M6G","OLI_M6C","OLI_MHG16","OLI_40Rnd_762x51_Mag","OLI_36Rnd_95x40_Mag","OPTRE_1Rnd_50x137_HEAT","OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag","TCP_optic_M43RCO","TCP_muzzle_brake_762_01","TCP_muzzle_brake_95_01","OLI_ANPEQ6G","TCP_H_Helmet_ECH43A_Olive_Blue","OLI_CH43A_Helmet_Olive","TCP_H_boonieHat_Olive","H_Watchcap_blk","H_Bandanna_gry","OLI_Tactical_Glasses","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black","OLI_CBUU_Woodland_1","OLI_CBUU_Woodland_2","TCP_B_Rifleman_1_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_2_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_3_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_4_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_5_M43_Medium_Rucksack_Olive"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Marine Grenadier",
    [["OLI_MA37GL","TCP_muzzle_brake_762_01","OLI_MA37_LAM","TCP_optic_EVOSJ",["OLI_40Rnd_762x51_Mag",40],["TCP_1Rnd_40_Shell_HE",1],""],[],["OLI_M6G","","","",[],[],""],["OLI_CBUU_Woodland_1",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4]]],["OLI_M43_Heavy_Olive_1",[]],["TCP_B_Grenadier_1_M43_Medium_Rucksack_Olive_M43A",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OLI_EndurexBoosterInhaler",3],["ItemAndroid",1],["WBK_HeadLampItem_Double",1],["OPTRE_M9_Frag",4,1],["TCP_M21_SmokeBlue",3,1],["TCP_M21_Smoke",5,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CH43A_Helmet_Olive","OLI_Tactical_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG_HURS"]],
    ["OLI_MA37GL","OLI_BR45GL","OLI_M6G","OLI_M6C","OLI_MHG16","OLI_40Rnd_762x51_Mag","OLI_36Rnd_95x40_Mag","OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag","TCP_1Rnd_40_Shell_HE","TCP_1Rnd_40_Shell_Smoke_White","TCP_1Rnd_40_Shell_Smoke_Blue","TCP_1Rnd_40_Shell_Smoke_Red","TCP_1Rnd_40_Shell_Signal_Red","TCP_1Rnd_40_Shell_Signal_Green","TCP_optic_M43RCO","TCP_muzzle_brake_762_01","TCP_muzzle_brake_95_01","OLI_ANPEQ6G","TCP_H_Helmet_ECH43A_Olive_Blue","OLI_CH43A_Helmet_Olive","TCP_H_boonieHat_Olive","H_Watchcap_blk","H_Bandanna_gry","OLI_Tactical_Glasses","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black","OLI_CBUU_Woodland_1","OLI_CBUU_Woodland_2","TCP_B_Grenadier_1_M43_Medium_Rucksack_Olive","TCP_B_Grenadier_2_M43_Medium_Rucksack_Olive"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Marine Marksman",
    [["OLI_MR10_LONGBOW","","OLI_MEQ7","TCP_optic_M43RCO_CRS_CUP",["OLI_15Rnd_95xVX2_Mag",15],[],"bipod_01_F_blk"],[],["OLI_M6G","","","",[],[],""],["OLI_CBUU_Woodland_1",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4]]],["OLI_M43_Heavy_Olive_1",[]],["TCP_B_Marksman_1_M43_Medium_Rucksack_Olive_M43A",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OLI_EndurexBoosterInhaler",3],["ItemAndroid",1],["WBK_HeadLampItem_Double",1],["OPTRE_M9_Frag",4,1],["TCP_M21_SmokeBlue",3,1],["TCP_M21_Smoke",5,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CH43A_Helmet_Olive","OLI_Tactical_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG_CNM_MVI_HURS"]],
    ["OLI_MR10_LONGBOW","OLI_LMR11_SHORTBOW","OLI_M6G","OLI_M6C","OLI_MHG16","OLI_15Rnd_95xVX2_Mag","OLI_30Rnd_762x51_Mag","OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag","TCP_optic_M43RCO","TCP_optic_M43RCO_CRS_CUP","OLI_ANPEQ6G","TCP_H_Helmet_ECH43A_Olive_Blue","OLI_CH43A_Helmet_Olive","TCP_H_boonieHat_Olive","H_Watchcap_blk","H_Bandanna_gry","OLI_Tactical_Glasses","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black","OLI_CBUU_Woodland_2","OLI_CBUU_Woodland_1","TCP_B_Marksman_1_M43_Medium_Rucksack_Olive","TCP_B_Marksman_2_M43_Medium_Rucksack_Olive","TCP_B_Marksman_3_M43_Medium_Rucksack_Olive"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Marine RTO",
    [["OLI_MA37_NoLight","TCP_muzzle_brake_762_01","OLI_MA37_LAM","TCP_optic_EVOSJ",["OLI_40Rnd_762x51_Mag",40],[],""],[],["OLI_M6G","","","",[],[],""],["OLI_CBUU_Woodland_1",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4]]],["OLI_M43_Heavy_Olive_1",[]],["TCP_B_RTO_1_ANPRC171_Olive",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OLI_EndurexBoosterInhaler",3],["WBK_HeadLampItem_Double",1],["ItemAndroid",1],["OPTRE_M9_Frag",4,1],["TCP_M21_SmokeBlue",3,1],["TCP_M21_Smoke",5,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CH43A_Helmet_Olive","OLI_Tactical_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG_HURS"]],
    ["OLI_MA37_NoLight","OLI_BR55HB","OLI_M6G","OLI_M6C","OLI_MHG16","OLI_40Rnd_762x51_Mag","OLI_36Rnd_95x40_Mag","OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag","TCP_optic_M43RCO","TCP_muzzle_brake_762_01","TCP_muzzle_brake_95_01","OLI_ANPEQ6G","TCP_H_Helmet_ECH43A_Olive_Blue","OLI_CH43A_Helmet_Olive","TCP_H_boonieHat_Olive","H_Watchcap_blk","H_Bandanna_gry","OLI_Tactical_Glasses","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black","OLI_CBUU_Woodland_1","OLI_CBUU_Woodland_2","TCP_B_RTO_1_ANPRC171_Olive","TCP_B_RTO_1_ANPRC171_Patrol_Olive"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Marine Weapon Specialist",
    [["OLI_MA37_NoLight","TCP_muzzle_brake_762_01","OLI_MA37_LAM","TCP_optic_EVOSJ",["OLI_40Rnd_762x51_Mag",40],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag",8],[],""],["OLI_CBUU_Woodland_1",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["KAT_Empty_bloodIV_250",1],["OLI_EndurexBoosterInhaler",3],["kat_IFAK",1],["WBK_HeadLampItem_Double",1],["ItemAndroid",1],["kat_Painkiller",1,4],["OPTRE_M9_Frag",4,1],["OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag",2,8],["TCP_M21_SmokeBlue",3,1],["TCP_M21_Smoke",3,1],[["UNSC_Knife","","","",[],[],""],1]]],["OLI_M43_Heavy_Olive_1",[["OLI_40Rnd_762x51_Mag",9,40]]],["OPTRE_M20_Universal_Tripod_Bag_Support",[]],"OLI_CH43A_Helmet_Olive","OLI_Tactical_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG_HURS"]],
    ["OLI_MA37","OLI_BR55HB","OLI_M6G","OLI_M6C","OLI_MHG16","OLI_40Rnd_762x51_Mag","OLI_36Rnd_95x40_Mag","OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag","TCP_optic_M43RCO","TCP_muzzle_brake_762_01","TCP_muzzle_brake_95_01","OLI_ANPEQ6G","TCP_H_Helmet_ECH43A_Olive_Blue","OLI_CH43A_Helmet_Olive","TCP_H_boonieHat_Olive","H_Watchcap_blk","H_Bandanna_gry","OLI_Tactical_Glasses","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black","OLI_CBUU_Woodland_1","OLI_CBUU_Woodland_2","OPTRE_M460_AGL_Bag_Weapon","OPTRE_AIE_486H_Bag_Weapon","OPTRE_M20_Universal_Tripod_Bag_Support"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Marine HAT",
    [["OLI_MA37_NoLight","TCP_muzzle_brake_762_01","OLI_MA37_LAM","TCP_optic_EVOSJ",["OLI_40Rnd_762x51_Mag",40],[],""],["OPTRE_M41_SSR","","","",["OPTRE_M41_Twin_HEAT_SACLOS",2],[],""],["OLI_M6G","","","",[],[],""],["OLI_CBUU_Woodland_1",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["WBK_HeadLampItem_Double",1],["ItemAndroid",1],["kat_Painkiller",1,4]]],["OLI_M43_Heavy_Olive_1",[]],["TCP_B_Ammo_Bearer_1_M43_Medium_Rucksack_Patrol_Olive_M43A",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OLI_EndurexBoosterInhaler",3],["OPTRE_M9_Frag",4,1],["TCP_M21_SmokeBlue",3,1],["TCP_M21_Smoke",5,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CH43A_Helmet_Olive","OLI_Tactical_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG_HURS"]],
    ["OLI_MA37_NoLight","OLI_BR55HB","OLI_M6G","OLI_M6C","OLI_MHG16","OLI_40Rnd_762x51_Mag","OLI_36Rnd_95x40_Mag","OPTRE_M41_Twin_HEAT_SACLOS","OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag","TCP_optic_M43RCO","TCP_muzzle_brake_762_01","TCP_muzzle_brake_95_01","OLI_ANPEQ6G","TCP_H_Helmet_ECH43A_Olive_Blue","OLI_CH43A_Helmet_Olive","TCP_H_boonieHat_Olive","H_Watchcap_blk","H_Bandanna_gry","OLI_Tactical_Glasses","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black","OLI_CBUU_Woodland_1","OLI_CBUU_Woodland_2","TCP_B_Rifleman_1_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_2_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_3_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_4_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_5_M43_Medium_Rucksack_Olive"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Marine NCO",
    [["OLI_MA37_NoLight","TCP_muzzle_brake_762_01","OLI_MA37_LAM","TCP_optic_EVOSJ",["OLI_40Rnd_762x51_Mag",40],[],""],[],["OLI_M6G","","","",[],[],""],["OLI_CBUU_Woodland_1",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["ItemAndroid",1],["WBK_HeadLampItem_Double",1],["kat_Painkiller",1,4],["acex_intelitems_notepad",1,1],["ACE_Chemlight_HiYellow",5,1],["OPTRE_ELB47_Strobe",5,1]]],["OLI_M43_Heavy_Olive_1",[]],["TCP_B_NCO_1_M43_Medium_Rucksack_Olive_M43A",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["ItemcTab",1],["OLI_EndurexBoosterInhaler",3],["OPTRE_M9_Frag",4,1],["TCP_M21_SmokeBlue",3,1],["TCP_M21_Smoke",5,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CH43A_Helmet_Olive","OLI_Tactical_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG_HURS"]],
    ["OLI_MA37","OLI_BR55HB","OLI_VK78_COMMANDO","OLI_MA37K","OLI_M6G","OLI_40Rnd_762x51_Mag","OLI_32Rnd_762x51_Mag","OLI_36Rnd_95x40_Mag","OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag","OLI_M6C","OLI_MHG16","Optre_Evo_Sight_Riser", "OPTRE_M12_Optic","TCP_optic_M43RCO","TCP_optic_M11VERO","TCP_optic_M81ERO","TCP_muzzle_brake_762_01","TCP_muzzle_brake_95_01","OLI_ANPEQ6G","TCP_H_Helmet_ECH43A_Olive_Blue","OLI_CH43A_Helmet_Olive","TCP_H_boonieHat_Olive","H_Watchcap_blk","H_Bandanna_gry","OLI_Tactical_Glasses","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black","OLI_CBUU_Woodland_1","OLI_CBUU_Woodland_2","TCP_B_NCO_1_M43_Medium_Rucksack_Olive","TCP_B_NCO_2_M43_Medium_Rucksack_Olive","TCP_B_NCO_3_M43_Medium_Rucksack_Olive_M43A"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Marine LMG",
    [["OLI_M73","TCP_muzzle_brake_762_01","TCP_acc_carryHandle_M731","TCP_optic_EVOSM",["OLI_100Rnd_95x40_Box",100],[],""],[],["OLI_M6G","","","",[],[],""],["OLI_CBUU_Woodland_1",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["ItemAndroid",1],["WBK_HeadLampItem_Double",1],["kat_Painkiller",1,4]]],["OLI_M43_Heavy_Olive_1",[]],["TCP_B_Autorifleman_1_M43_Medium_Rucksack_Patrol_Olive",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OLI_EndurexBoosterInhaler",3],["TCP_optic_EVOSD",1],["OPTRE_M9_Frag",4,1],["TCP_M21_SmokeBlue",3,1],["TCP_M21_Smoke",5,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CH43A_Helmet_Olive","OLI_Tactical_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG_HURS"]],
    ["OLI_M73","OLI_M6G","OLI_M6C","OLI_MHG16","OLI_100Rnd_95x40_Box","OLI_400Rnd_95x40_Box","OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag","TCP_optic_M11VERO","OLI_ANPEQ6G","TCP_H_Helmet_ECH43A_Olive_Blue","OLI_CH43A_Helmet_Olive","TCP_H_boonieHat_Olive","H_Watchcap_blk","H_Bandanna_gry","OLI_Tactical_Glasses","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black","OLI_CBUU_Woodland_1","OLI_CBUU_Woodland_2","TCP_B_Autorifleman_1_M43_Medium_Rucksack_Patrol_Olive","TCP_B_Autorifleman_2_M43_Medium_Rucksack_Patrol_Olive"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Marine Combat Engineer",
    [["OLI_MA37","TCP_muzzle_brake_762_01","OLI_MA37_LAM","TCP_optic_EVOSJ",["OLI_40Rnd_762x51_Mag",40],[],""],[],["OLI_M6G","","","",[],[],""],["OLI_CBUU_Woodland_1",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["ItemAndroid",1],["WBK_HeadLampItem_Double",1],["kat_Painkiller",1,4],["TCP_M21_Smoke",5,1],["TCP_M21_SmokeBlue",3,1]]],["OLI_M43_Heavy_Olive_1",[]],["TCP_B_Engineer_1_M43_Medium_Rucksack_Engineer_M2_Buttpack_Olive_M43A",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OLI_Combat_Engineer_Toolkit",1],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CH43A_Helmet_Olive","OLI_Tactical_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG_HURS"]],
    ["OLI_MA37_NoLight","OLI_BR55HB","OLI_M6G","OLI_M6C","OLI_MHG16","OLI_40Rnd_762x51_Mag","OLI_36Rnd_95x40_Mag","OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag","TCP_optic_M43RCO","TCP_muzzle_brake_762_01","TCP_muzzle_brake_95_01","OLI_ANPEQ6G","TCP_H_Helmet_ECH43A_Olive_Blue","OLI_CH43A_Helmet_Olive","TCP_H_boonieHat_Olive","H_Watchcap_blk","H_Bandanna_gry","OLI_Tactical_Glasses","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black","OLI_CBUU_Woodland_1","OLI_CBUU_Woodland_2","TCP_B_Rifleman_1_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_2_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_3_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_4_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_5_M43_Medium_Rucksack_Olive","TCP_B_Engineer_1_M43_Medium_Rucksack_Engineer_Olive_M43A"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Marine AA",
    [["OLI_MA37_NoLight","TCP_muzzle_brake_762_01","OLI_MA37_LAM","TCP_optic_EVOSJ",["OLI_40Rnd_762x51_Mag",40],[],""],["MEU_Spkr_S108","","","",["MEU_SPKR108_SAM_AA",1],[],""],["OLI_M6G","","","",[],[],""],["OLI_CBUU_Woodland_1",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["WBK_HeadLampItem_Double",1],["ItemAndroid",1],["kat_Painkiller",1,4]]],["OLI_M43_Heavy_Olive_1",[]],["TCP_B_Ammo_Bearer_1_M43_Medium_Rucksack_Patrol_Olive_M43A",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OLI_EndurexBoosterInhaler",3],["OPTRE_M9_Frag",4,1],["TCP_M21_SmokeBlue",3,1],["TCP_M21_Smoke",5,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CH43A_Helmet_Olive","OLI_Tactical_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG"]],
    ["OLI_MA37_NoLight","OLI_BR55HB","OLI_M6G","OLI_M6C","OLI_MHG16","OLI_40Rnd_762x51_Mag","OLI_36Rnd_95x40_Mag","MEU_SPKR108_SAM_AA","OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag","TCP_optic_M43RCO","TCP_muzzle_brake_762_01","TCP_muzzle_brake_95_01","OLI_ANPEQ6G","TCP_H_Helmet_ECH43A_Olive_Blue","OLI_CH43A_Helmet_Olive","TCP_H_boonieHat_Olive","H_Watchcap_blk","H_Bandanna_gry","OLI_Tactical_Glasses","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black","OLI_CBUU_Woodland_1","OLI_CBUU_Woodland_2","TCP_B_Rifleman_1_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_2_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_3_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_4_M43_Medium_Rucksack_Olive","TCP_B_Rifleman_5_M43_Medium_Rucksack_Olive"],
    "true",
    {}
] spawn Wbk_AddKit;
