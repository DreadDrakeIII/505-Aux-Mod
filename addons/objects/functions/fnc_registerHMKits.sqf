/*
    Corpsman & Hospital Coordinator Loadouts
    Author: 505th Dev Team
*/

params ["_locker"];

sleep 1;

[
    _locker,
    "Corpsman",
    [["OLI_MA5C","","OLI_MEQ7","",["OLI_32Rnd_762x51_Mag",32],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_Uniform_CE_Corpsman",[["ACE_CableTie",5],["ACE_EarPlugs",1],["ACE_IR_Strobe_Item",1],["ACE_Flashlight_XL50",1],["ACE_EntrenchingTool",1],["ACE_MapTools",1],["acex_intelitems_notepad",1,1],["ACE_Chemlight_HiGreen",5,1],["OPTRE_M8_Flare",1,1],["OPTRE_M8_Flare_White",1,1],["OLI_32Rnd_762x51_Mag",4,32],["OLI_8Rnd_127x40_Mag",3,8]]],["OLI_CE_Armour_Corpsman_Vest",[["ItemcTabHCam",1],["ItemAndroid",1],["OLI_32Rnd_762x51_Mag",6,32]]],["OLI_MedicalBackpack",[["ACE_quikclot",10],["ACE_adenosine",2],["ACE_epinephrine",2],["ACE_splint",2],["ACE_tourniquet",1],["kat_EACA",2],["kat_Pulseoximeter",5],["kat_Armband_Medic_Goggles",1],["kat_accuvac",1],["kat_X_AED",1],["kat_BVM",1],["kat_stethoscope",1],["ACE_surgicalKit",1],["kat_IV_16",2],["kat_AFAK",5],["kat_Painkiller",2,4],["OPTRE_M2_Smoke",2,1],["OPTRE_M9_Frag",3,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMET_CorpsmanV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],

    ["OLI_MA5C","OLI_M7_Caseless","OLI_BR45B","OLI_M295_BMR","OLI_M6G","OLI_M6G","OLI_MHG16","kat_CarryStretcherBag","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OPTRE_M7_Sight","OLI_MEQ7","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMET_CorpsmanV2","OLI_CE_HELMET_Corpsman","OLI_Uniform_CE_Corpsman","OLI_Uniform_CE_Corpsman_Rolled","OLI_CE_Armour_Corpsman_Vest","OLI_CE_Armour_Corpsman_Vest_NSV2","OLI_CE_Armour_Corpsman_Vest_V2","OLI_CE_Armour_Corpsman_Vest_NS","OLI_CE_Armour_Corpsman_Vest_V2Pouch","OLI_CE_Armour_Corpsman_Vest_NSV2Pouch","OLI_CE_Armour_Corpsman_Vest_NSPouch","OLI_CE_Armour_Corpsman_Vest_Pouch","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Glasses_MedScanner","OLI_Stealth_Mask_Goggle"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _locker,
    "Hospital Coordinator",
    [["OLI_MA5C","","OLI_MEQ7","",["OLI_32Rnd_762x51_Mag",32],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OLI_Uniform_CE_Corpsman",[["ACE_CableTie",5],["ACE_EarPlugs",1],["ACE_IR_Strobe_Item",1],["ACE_Flashlight_XL50",1],["ACE_EntrenchingTool",1],["ACE_MapTools",1],["acex_intelitems_notepad",1,1],["ACE_Chemlight_HiGreen",5,1],["OPTRE_M8_Flare",1,1],["OPTRE_M8_Flare_White",1,1],["OLI_32Rnd_762x51_Mag",4,32],["OLI_8Rnd_127x40_Mag",3,8]]],["OLI_CE_Armour_Corpsman_Vest",[["ItemcTab",1],["ItemcTabHCam",1],["OLI_32Rnd_762x51_Mag",6,32]]],["OLI_MedicalBackpack",[["ACE_quikclot",10],["ACE_adenosine",2],["ACE_epinephrine",2],["ACE_splint",2],["ACE_tourniquet",1],["kat_EACA",2],["kat_Pulseoximeter",5],["kat_Armband_Medic_Goggles",1],["kat_accuvac",1],["kat_X_AED",1],["kat_BVM",1],["kat_stethoscope",1],["ACE_surgicalKit",1],["kat_IV_16",2],["kat_AFAK",1],["OPTRE_OQ_38_Wren_Drone_Snow_Item",1],["kat_Painkiller",2,4],["OPTRE_M2_Smoke",2,1],["OPTRE_M9_Frag",3,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMET_CorpsmanV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],

    ["OLI_MA5C","OLI_MA37K","OLI_M7_Caseless","OLI_CPW","OLI_BR45B","OLI_M295_BMR","OLI_M6G","OLI_M6G","OLI_MHG16","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OPTRE_M7_Sight","OLI_MEQ7","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMET_CorpsmanV2","OLI_CE_HELMET_Corpsman","OLI_Uniform_CE_Corpsman","OLI_Uniform_CE_Corpsman_Rolled","OLI_CE_Armour_Corpsman_Vest","OLI_CE_Armour_Corpsman_Vest_NSV2","OLI_CE_Armour_Corpsman_Vest_V2","OLI_CE_Armour_Corpsman_Vest_NS","OLI_CE_Armour_Corpsman_Vest_V2Pouch","OLI_CE_Armour_Corpsman_Vest_NSV2Pouch","OLI_CE_Armour_Corpsman_Vest_NSPouch","OLI_CE_Armour_Corpsman_Vest_Pouch","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Glasses_MedScanner","OLI_Stealth_Mask_Goggle"],
    "true",
    {}
] spawn Wbk_AddKit;
