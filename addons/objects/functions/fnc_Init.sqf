/*
  CE_fnc_Init.sqf
  Converted from '505th CE Loadouts Version 2'
  Usage:
    [] call CE_fnc_Init;           // defaults to player
    [lockerObject] call CE_fnc_Init; // use specific object (e.g., locker)
  Notes:
    - The original script used `this` for the target object. This function will
      substitute `_target` for those occurrences.
    - The function attempts to be safe: if you pass an array it will take the first element.
*/

params ["_target"]; // expects optional [object]
if (isArray _target) then {
    _target = if (count _target > 0) then {_target select 0} else {player};
} else {
    if (isNil "_target") then {_target = player};
};
private _owner = _target; // local alias for clarity
private _result = true;

try {

[
    _target,
    "Rifleman",
    [["OPTRE_MA5C","","OPTRE_BMR_Laser","",["OPTRE_32Rnd_762x51_Mag",32],[],""],[],["OPTRE_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_CE_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1]]],["OLI_CE_Armour_Vest_V2",[["OPTRE_8Rnd_127x40_AP_Mag",3,8],["OPTRE_32Rnd_762x51_Mag",10,32]]],["OLI_Invisible_Backpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OPTRE_MA5C","OPTRE_BR45","OPTRE_M295_BMR","OPTRE_Commando","OPTRE_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OPTRE_M7_Sight","OPTRE_BMR_Laser","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","Rogue_CEUniform_U_B","Rogue_CEUniformRolled_U_B","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","G_Balaclava_TI_blk_F","G_Balaclava_TI_G_blk_F"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _target,
    "Grenadier",
    [["OPTRE_MA5CGL","","OPTRE_BMR_Laser","",["OPTRE_32Rnd_762x51_Mag",32],[],""],[],["OPTRE_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_CE",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1]]],["OLI_CE_Armour_Vest_V2",[["OPTRE_8Rnd_127x40_AP_Mag",3,8],["OPTRE_32Rnd_762x51_Mag",10,32]]],["OLI_Invisible_Backpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],["UGL_FlareCIR_F",3,1],["UGL_FlareRed_F",3,1],["UGL_FlareWhite_F",3,1],["OPTRE_signalSmokeB",3,1],["OPTRE_signalSmokeG",3,1],["OPTRE_signalSmokeP",3,1],["OPTRE_signalSmokeR",3,1],["UGL_FlareGreen_F",3,1],["UGL_FlareWhite_Illumination_F",5,1],["OPTRE_1Rnd_Smoke_Grenade_shell",10,1],["1Rnd_HE_MEU_shell",20,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OPTRE_MA5CGL","OPTRE_BR45GL","OPTRE_Commando","OPTRE_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OPTRE_M7_Sight","OPTRE_BMR_Laser","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","Rogue_CEUniform_U_B","Rogue_CEUniformRolled_U_B","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","WNZ_EMP40mm_Grenade_Magazine","ACE_40mm_Pike","1Rnd_9Bang_MEU_shell","OPTRE_EyePiece","G_Balaclava_TI_blk_F","G_Balaclava_TI_G_blk_F"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _target,
    "Light Machine Gunner",
    [["OPTRE_M73","","OPTRE_BMR_Laser","",["OPTRE_100Rnd_95x40_Box",100],[],""],[],["OPTRE_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_CE",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1]]],["OLI_CE_Armour_Vest",[["OPTRE_8Rnd_127x40_AP_Mag",3,8],["OPTRE_100Rnd_95x40_Box",3,100]]],["OLI_Backpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],["OPTRE_100Rnd_95x40_Box",5,100],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["Dmns_M33_T","OPTRE_M73","OPTRE_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OPTRE_M7_Sight","OPTRE_BMR_Laser","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","Rogue_CEUniform_U_B","Rogue_CEUniformRolled_U_B","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","G_Balaclava_TI_blk_F","G_Balaclava_TI_G_blk_F"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _target,
    "Marksman",
    [["MEU_OPTRE_MRS10X","","OPTRE_BMR_Laser","OPTRE_BR55HB_Scope",["OPTRE_20Rnd_86x70_Mag",20],[],"bipod_01_F_blk"],[],["OPTRE_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_CE_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1]]],["Rogue_CEArmourScout",[["OPTRE_8Rnd_127x40_AP_Mag",3,8]]],["OLI_ScoutBackpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],["OPTRE_20Rnd_86x70_Mag",10,20],[["UNSC_Knife","","","",[],[],""],1]]],"Rogue_CEBoonieGrey","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["MEU_OPTRE_MRS10X","srifle_DMR_07_blk_F","OPTRE_M392_DMR","OPTRE_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_BR45_Scope","OPTRE_M12_Optic","OPTRE_M7_Sight","OPTRE_BMR_Laser","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","Rogue_CEUniform_U_B","Rogue_CEUniformRolled_U_B","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","G_Balaclava_TI_blk_F","G_Balaclava_TI_G_blk_F"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _target,
    "Light Anti Tank",
    [["OPTRE_MA5C","","OPTRE_BMR_Laser","",["OPTRE_32Rnd_762x51_Mag",32],[],""],["MEU_Cricket","","ACE_DBAL_A3_Red","",["OPTRE_1Rnd_50x137_HEAT",1],[],""],["OPTRE_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_CE_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1]]],["OLI_CE_Armour_Vest_V2",[["OPTRE_32Rnd_762x51_Mag",10,32],["OPTRE_8Rnd_127x40_AP_Mag",3,8]]],["OLI_Invisible_Backpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],["OPTRE_1Rnd_50x137_HEAT",5,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OPTRE_MA5C","OPTRE_BR45","OPTRE_M295_BMR","OPTRE_Commando","OPTRE_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OPTRE_M7_Sight","OPTRE_BMR_Laser","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","Rogue_CEUniform_U_B","Rogue_CEUniformRolled_U_B","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","G_Balaclava_TI_blk_F","G_Balaclava_TI_G_blk_F"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _target,
    "Corpsman",
    [["OPTRE_MA5C","","OPTRE_BMR_Laser","Optre_Evo_Sight_Riser",["OPTRE_32Rnd_762x51_Mag",32],[],""],[],["OPTRE_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_CE_Corpsman",[["ACE_CableTie",5],["ACE_EarPlugs",1],["ACE_IR_Strobe_Item",1],["ACE_Flashlight_XL50",1],["ACE_EntrenchingTool",1],["ACE_MapTools",1],["acex_intelitems_notepad",1,1],["ACE_Chemlight_HiGreen",5,1],["OPTRE_M8_Flare",1,1],["OPTRE_M8_Flare_White",1,1],["OPTRE_32Rnd_762x51_Mag",4,32]]],["OLI_CE_Armour_Corpsman_Vest",[["ItemcTab",1],["ItemcTabHCam",1],["OPTRE_32Rnd_762x51_Mag",6,32],["OPTRE_8Rnd_127x40_Mag",2,8]]],["OLI_MedicalBackpack",[["ACE_quikclot",10],["ACE_adenosine",2],["ACE_epinephrine",2],["ACE_splint",2],["ACE_tourniquet",1],["kat_EACA",2],["kat_Pulseoximeter",5],["kat_Armband_Medic_Goggles",1],["kat_accuvac",1],["kat_X_AED",1],["kat_BVM",1],["kat_stethoscope",1],["ACE_surgicalKit",1],["kat_IV_16",2],["kat_AFAK",1],["kat_Painkiller",2,4],["OPTRE_M2_Smoke",2,1],["OPTRE_M9_Frag",3,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMET_CorpsmanV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OPTRE_MA5C","OPTRE_BR45","OPTRE_M295_BMR","OPTRE_Commando","OPTRE_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OPTRE_M7_Sight","OPTRE_BMR_Laser","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMET_CorpsmanV2","OLI_CE_HELMET_Corpsman","OLI_Uniform_CE_Corpsman","OLI_Uniform_CE_Corpsman_Rolled","OLI_CE_Armour_Corpsman_Vest","OLI_CE_Armour_Corpsman_Vest_NSV2","OLI_CE_Armour_Corpsman_Vest_V2","OLI_CE_Armour_Corpsman_Vest_NS","OLI_CE_Armour_Corpsman_Vest_V2Pouch","OLI_CE_Armour_Corpsman_Vest_NSV2Pouch","OLI_CE_Armour_Corpsman_Vest_NSPouch","OLI_CE_Armour_Corpsman_Vest_Pouch","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","G_Balaclava_TI_blk_F","G_Balaclava_TI_G_blk_F"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _target,
    "Squad Leader",
    [["OPTRE_MA37K","","OPTRE_BMR_Laser","",["OPTRE_32Rnd_762x51_Mag",32],[],""],[],["OPTRE_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_CE_SL_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",4,1],["OPTRE_M2_Smoke_Red",4,1],["OPTRE_M2_Smoke_Green",4,1]]],["OLI_CE_Armour_SL_Vest_NSV2",[["OPTRE_8Rnd_127x40_AP_Mag",3,8],["OPTRE_32Rnd_762x51_Mag",10,32]]],["OLI_Backpack_CE_505",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["ItemcTab",1],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMET_SLV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OPTRE_MA37K","OPTRE_MA5C","OPTRE_BR45","OPTRE_M295_BMR","OPTRE_Commando","OPTRE_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OPTRE_M7_Sight","OPTRE_BMR_Laser","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMET_SLV2","OLI_CE_HELMET_SL","OLI_Uniform_CE_SL","OLI_Uniform_CE_SL_Rolled","OLI_CE_Armour_SL_Vest","OLI_CE_Armour_SL_Vest_NSV2","OLI_CE_Armour_SL_Vest_V2","OLI_CE_Armour_SL_Vest_NS","OLI_CE_Armour_SL_Vest_V2Pouch","OLI_CE_Armour_SL_Vest_NSV2Pouch","OLI_CE_Armour_SL_Vest_NSPouch","OLI_CE_Armour_SL_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","G_Balaclava_TI_blk_F","G_Balaclava_TI_G_blk_F"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _target,
    "Pilot",
    [["OPTRE_M7","","OPTRE_BMR_Laser","",["OPTRE_60Rnd_5x23mm_Mag",60],[],""],[],["OPTRE_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_Pilot",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1]]],["OLI_Pilot_Vest",[["OPTRE_8Rnd_127x40_AP_Mag",3,8],["OPTRE_60Rnd_5x23mm_Mag",5,60]]],["OLI_Invisible_Backpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["ToolKit",1],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_Heli_Crew_Helmet","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["TKE_UCNPilotHelm_BASE","H_PilotHelmetHeli_B","H_CrewHelmetHeli_B","TKE_Rogue_UniformMDTFGrey_U_B","TKE_Rogue_UniformRolledMDTFGrey_U_B","hgun_PDW2000_F","OPTRE_M6D_Carbine_Black_F","SMG_05_F","OPTRE_M7","OPTRE_BMR_Laser"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _target,
    "Platoon Leader",
    [["OPTRE_MA37K","","OPTRE_BMR_Laser","Optre_Evo_Sight_Riser",["OPTRE_32Rnd_762x51_Mag",32],[],""],[],["OPTRE_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_CE_PL",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",4,1],["OPTRE_M2_Smoke_Red",4,1],["OPTRE_M2_Smoke_Green",4,1]]],["OLI_CE_Armour_PL_Vest_NSV2",[["OPTRE_8Rnd_127x40_AP_Mag",3,8],["OPTRE_32Rnd_762x51_Mag",10,32]]],["OLI_LR_Antenna_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["ItemcTab",1],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_FieldCap_505th","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OPTRE_MA37K","OPTRE_MA5C","OPTRE_BR45","OPTRE_M295_BMR","OPTRE_Commando","OPTRE_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OPTRE_M7_Sight","OPTRE_BMR_Laser","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_FieldCap_505th","OLI_CE_HELMET_PLV2","OLI_CE_HELMET_PL","OLI_Uniform_CE_PL","OLI_Uniform_CE_PL_Rolled","OLI_CE_Armour_PL_Vest","OLI_CE_Armour_PL_Vest_NSV2","OLI_CE_Armour_PL_Vest_V2","OLI_CE_Armour_PL_Vest_NS","OLI_CE_Armour_PL_Vest_V2Pouch","OLI_CE_Armour_PL_Vest_NSV2Pouch","OLI_CE_Armour_PL_Vest_NSPouch","OLI_CE_Armour_PL_Vest_Pouch","OLI_LR_Antenna_CE","OLI_BackpackLR_CE","OLI_BackpackLR_CE_505","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","G_Balaclava_TI_blk_F","G_Balaclava_TI_G_blk_F"],
    "true",
    {}
] spawn Wbk_AddKit;

[

    _target,
    "Anti-Air",
    [["OPTRE_MA5C","","OPTRE_BMR_Laser","",["OPTRE_32Rnd_762x51_Mag",32],[],""],["launch_B_Titan_tna_F","","","",["ace_missile_manpad_stinger_man",1],[],""],["OPTRE_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_CE_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1]]],["OLI_CE_Armour_Vest_V2",[["OPTRE_32Rnd_762x51_Mag",10,32]]],["OLI_Backpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],["ace_missile_manpad_stinger_man",2,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OPTRE_MA5C","OPTRE_BR45","OPTRE_M295_BMR","OPTRE_Commando","OPTRE_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OPTRE_M7_Sight","OPTRE_BMR_Laser","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","Rogue_CEUniform_U_B","Rogue_CEUniformRolled_U_B","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","G_Balaclava_TI_blk_F","G_Balaclava_TI_G_blk_F"],
    "true",
    {}
] spawn Wbk_AddKit;

[
    _target,
    "Heavy Anti-Tank",
    [["OPTRE_MA5C","","","",["OPTRE_32Rnd_762x51_Mag",32],[],""],["OPTRE_M41_SSR","","","",["OPTRE_M41_Twin_HEAT_SACLOS",2],[],""],["OPTRE_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_CE_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1]]],["OLI_CE_Armour_Vest_V2",[["OPTRE_32Rnd_762x51_Mag",9,32]]],["OLI_Backpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],["OPTRE_M41_Twin_HEAT_SACLOS",3,2],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["OPTRE_MA5C","OPTRE_BR45","OPTRE_M295_BMR","OPTRE_Commando","OPTRE_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OPTRE_M7_Sight","OPTRE_BMR_Laser","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","Rogue_CEUniform_U_B","Rogue_CEUniformRolled_U_B","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","G_Balaclava_TI_blk_F","G_Balaclava_TI_G_blk_F"],
    "true",
    {}
] spawn Wbk_AddKit;

[
  _target,
  "Heavy Machine Gunner",
  [["OPTRE_M247","","OPTRE_BMR_Laser","OPTRE_BR55HB_Scope_Grey",["OPTRE_400Rnd_762x51_Box_Tracer",400],[],"bipod_01_F_blk"],[],["OPTRE_M6G","","","",["OPTRE_8Rnd_127x40_AP_Mag",8],[],""],["OLI_Uniform_CE_Rolled",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",2,1],["acex_intelitems_notepad",1,1],["OPTRE_M2_Smoke",4,1],["OPTRE_M2_Smoke_Blue",2,1]]],["OLI_CE_Armour_Vest_V2",[["OPTRE_8Rnd_127x40_AP_Mag",3,8]]],["OLI_Backpack_CE_505",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["OPTRE_M9_Frag",4,1],["OPTRE_400Rnd_762x51_Box_Tracer",2,400],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_CE_HELMETV2","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
  ["19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OPTRE_M7_Sight","OPTRE_BMR_Laser","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OLI_CE_HELMETV2","OLI_CE_HELMET","Rogue_CEUniform_U_B","Rogue_CEUniformRolled_U_B","OLI_CE_Armour_Vest","OLI_CE_Armour_Vest_NSV2","OLI_CE_Armour_Vest_V2","OLI_CE_Armour_Vest_NS","OLI_CE_Armour_Vest_V2Pouch","OLI_CE_Armour_Vest_NSV2Pouch","OLI_CE_Armour_Vest_NSPouch","OLI_CE_Armour_Vest_Pouch","OLI_Backpack_CE","OLI_Backpack_CE_505","OLI_Invisible_Backpack_CE","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","G_Balaclava_TI_blk_F","G_Balaclava_TI_G_blk_F"],
  "true",
  {}
] spawn Wbk_AddKit;


} catch {
    _result = false;
    diag_log format["CE_fnc_Init: caught error: %1", _this];
};
_result
