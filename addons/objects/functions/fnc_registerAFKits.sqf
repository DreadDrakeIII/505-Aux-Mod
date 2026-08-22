/*
    Air Force Loadouts
    Author: 505th Dev Team
*/

params ["_locker"];

sleep 1;

[
    _locker,
    "Navy Pilot",
    [["OLI_M7_Caseless","","OLI_MEQ7","OPTRE_M7_Sight",["OLI_60Rnd_5x23_Mag",60],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_CBUU_Urban_1",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["ItemAndroid",1],["WBK_HeadLampItem_Double",1],["kat_Painkiller",1,4]]],["OLI_M43_Kevlar_Black_1",[["OLI_60Rnd_5x23_Mag",3,60],["OLI_8Rnd_127x40_Mag",3,8]]],["TCP_B_Utility_Rig_Black",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],["OPTRE_M8_Flare_Green",2,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_Heli_Pilot_Helmet","OLI_Tactical_Combat_Mask",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG"]],
    ["OLI_M6G","OLI_M6C","OLI_MHG16","OLI_ANPEQ6G","OLI_Jet_Pilot_Helmet","OLI_Tactical_Glasses","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Navy JTAC",
    [["OLI_MA37_NoLight","TCP_muzzle_brake_762_01","OLI_MA37_LAM","TCP_optic_EVOSJ",["OLI_40Rnd_762x51_Mag",40],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_CBUU_Urban_1",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4]]],["TCP_V_M43A_GungnirL_3_Black",[]],["TCP_B_RTO_1_ANPRC171_Patrol_M2_Buttpack_Black_M43A",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["WBK_HeadLampItem_Double",1],["ItemAndroid",1],["OPTRE_M9_Frag",4,1],["TCP_M21_Smoke",5,1],["TCP_M21_SmokeBlue",3,1],[["UNSC_Knife","","","",[],[],""],1]]],"TCP_H_Helmet_CH43A_Black_ChinstrapOffset","OLI_Tactical_Combat_Mask",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG_HURS"]],
    ["OLI_MA37_NoLight","OLI_BR55HB","OLI_M6G","OLI_M6C","OLI_MHG16","OLI_40Rnd_762x51_Mag","OLI_36Rnd_95x40_Mag","OLI_12Rnd_127x40_Mag","OLI_8Rnd_127x40_Mag","OLI_16Rnd_45ACP_Mag","OLI_12Rnd_45ACP_Mag","TCP_optic_M27RCO","TCP_muzzle_brake_762_01","TCP_muzzle_brake_95_01","OLI_ANPEQ6G","OLI_Tactical_Glasses","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black"],
    "true",
    {}
] spawn Wbk_AddKit;
