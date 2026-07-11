/*
    Corpsman & Hospital Coordinator Loadouts
    Author: 505th Dev Team
*/

params ["_locker"];

sleep 1;

[
    _locker,
    "Navy Corpsman",
    [["OLI_MA37_NoLight","TCP_muzzle_brake_762_01","OLI_MA37_LAM","TCP_optic_EVOSJ",["OLI_40Rnd_762x51_Mag",40],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_CBUU_Woodland_1",[["ACE_tourniquet",2],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",3,4],["ACE_Chemlight_HiGreen",5,1]]],["OLI_M43_Medic_Olive_1",[["kat_accuvac",1],["kat_X_AED",1],["kat_Pulseoximeter",1],["ACE_adenosine",2],["kat_BVM",1],["kat_EACA",2],["kat_stethoscope",1]]],["TCP_B_Medic_1_M43_Medium_Rucksack_Medical_M2_Buttpack_Olive_M43A",[["kat_IV_16",2],["kat_AFAK",5],["ACE_quikclot",10],["OLI_TacticalTraumaKit",1],["OLI_NecrosisTestingKit",1],["OLI_EndurexBoosterInhaler",10],["OLI_NecroClearVial",10],["OPTRE_M9_Frag",4,1],["TCP_M21_SmokeBlue",3,1],["TCP_M21_Smoke",5,1],["OPTRE_M8_Flare_Blue",5,1],["OPTRE_M8_Flare_White",5,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CH43A_Medic_Helmet_Olive","OLI_Tactical_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG_HURS"]],
    ["OLI_MA37_NoLight","OLI_BR55HB","OLI_M6G","OLI_M6C","OLI_MHG16","OLI_40Rnd_762x51_Mag","OLI_36Rnd_95x40_Mag","OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag","TCP_optic_M27RCO","TCP_muzzle_brake_762_01","TCP_muzzle_brake_95_01","OLI_ANPEQ6G","OLI_CH43A_Medic_Helmet_Olive","TCP_H_Helmet_ECH43A_Olive_Blue","TCP_H_boonieHat_Olive","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black","OLI_MedScanner_Mask","OLI_Tactical_Glasses","OLI_MedScanner_Glasses","OLI_CBUU_Woodland_1","OLI_CBUU_Woodland_2","TCP_B_Medic_1_M43_Medium_Rucksack_Medical_M2_Buttpack_Olive_M43A","TCP_B_Medic_2_M43_Medium_Rucksack_Medical_M2_Buttpack_Olive"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Navy Coordinator",
    [["OLI_MA37_NoLight","TCP_muzzle_brake_762_01","OLI_MA37_LAM","TCP_optic_EVOSJ",["OLI_40Rnd_762x51_Mag",40],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_CBUU_Woodland_1",[["ACE_tourniquet",2],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",3,4],["ACE_Chemlight_HiGreen",5,1],["OPTRE_M2_Smoke",2,1],["OPTRE_M8_Flare",1,1],["OPTRE_M8_Flare_White",1,1],["OLI_40Rnd_762x51_Mag",8,40]]],["OLI_M43_Medic_Olive_1",[["kat_accuvac",1],["kat_X_AED",1],["kat_Pulseoximeter",1],["ACE_adenosine",2],["kat_BVM",1],["kat_EACA",2],["kat_stethoscope",1],["OLI_8Rnd_127x40_Mag",3,8],["OLI_40Rnd_762x51_Mag",2,40]]],["TCP_B_Medic_1_M43_Medium_Rucksack_Medical_M2_Buttpack_Olive_M43A",[["kat_IV_16",2],["kat_AFAK",1],["ACE_quikclot",10],["OLI_TacticalTraumaKit",1],["OLI_NecrosisTestingKit",1],["OLI_EndurexBoosterInhaler",3],["OLI_NecroClearVial",3],["ItemcTab",1],["OPTRE_OQ_38_Wren_Drone_Snow_Item",3],["ACE_UAVBattery",5],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CH43A_Medic_Helmet_Olive","OLI_Tactical_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","TCP_UGPS","TCP_ANPRC55","ItemCompass","TCP_Watch","OPTRE_NVG_HURS"]],
    ["OLI_MA37_NoLight","OLI_BR55HB","OLI_M6G","OLI_M6C","OLI_MHG16","OLI_40Rnd_762x51_Mag","OLI_36Rnd_95x40_Mag","OLI_8Rnd_127x40_Mag","OLI_12Rnd_127x40_Mag","OLI_12Rnd_45ACP_Mag","TCP_optic_M27RCO","TCP_muzzle_brake_762_01","TCP_muzzle_brake_95_01","OLI_ANPEQ6G","OLI_CH43A_Medic_Helmet_Olive","TCP_H_Helmet_ECH43A_Olive_Blue","TCP_H_boonieHat_Olive","OLI_Tactical_Combat_Mask","TCP_G_Balaclava_Black","OLI_MedScanner_Mask","OLI_Tactical_Glasses","OLI_MedScanner_Glasses","OLI_CBUU_Woodland_1","OLI_CBUU_Woodland_2","TCP_B_Medic_1_M43_Medium_Rucksack_Medical_M2_Buttpack_Olive_M43A","TCP_B_Medic_2_M43_Medium_Rucksack_Medical_M2_Buttpack_Olive"],
    "true",
    {}
] spawn Wbk_AddKit;
