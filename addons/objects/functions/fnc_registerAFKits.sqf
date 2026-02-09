/*
    File: fn_oliafloadouts.sqf
    Author: 505th Dev Team
    Description:
        Registers all 505th WBK kits (Armor Locker version).
*/

params ["_locker"];

// Wait for object to be ready
sleep 1;

// systemChat "[505th] Registering AF WBK Kits...";

[
    _locker,
    "Pilot",
    [["OPTRE_M7","","OPTRE_M6G_Flashlight","",["OPTRE_60Rnd_5x23mm_Mag",60],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OPTRE_UNSC_Army_Uniform_R_BLK_SlimLeg",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",1,1]]],["FIR_pilot_vest",[["OPTRE_60Rnd_5x23mm_Mag",5,60],["OLI_8Rnd_127x40_Mag",3,8]]],["OLI_Invisible_Backpack_CE",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["ToolKit",1],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"OLI_Heli_Crew_Helmet","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
    ["TKE_UCNPilotHelm_BASE","H_PilotHelmetHeli_B","H_CrewHelmetHeli_B","hgun_PDW2000_F","OPTRE_M6D_Carbine_Black_F","SMG_05_F","OLI_M6G","OPTRE_M7","OLI_MEQ7"],
    "true",
    {}
] spawn Wbk_AddKit;

[
  _locker,
  "JTAC",
  [["OLI_MA5C","","OLI_MEQ7","",["OLI_32Rnd_762x51_Mag",32],[],""],[],["OLI_M6G","","","",["OLI_8Rnd_127x40_Mag",8],[],""],["OPTRE_UNSC_Army_Uniform_R_BLK_SlimLeg",[["ACE_elasticBandage",5],["ACE_tourniquet",1],["ACE_MapTools",1],["ACE_IR_Strobe_Item",1],["ItemcTabHCam",1],["ACE_EntrenchingTool",1],["ACE_Flashlight_XL50",1],["ACE_CableTie",5],["kat_Painkiller",1,4],["Laserbatteries",1,1]]],["OPTRE_UNSC_M52A_Armor3_URB",[["OLI_8Rnd_127x40_Mag",3,8]]],["19thANPRC419",[["kat_IFAK",1],["KAT_Empty_bloodIV_250",1],["ToolKit",1],["OPTRE_M9_Frag",4,1],[["UNSC_Knife","","","",[],[],""],1]]],"OPTRE_UNSC_VX16_Helmet_Mask","OPTRE_HUD_In_Glasses",["OPTRE_Smartfinder","","","",["Laserbatteries",1],[],""],["ItemMap","B_UavTerminal","TFAR_anprc152","ItemCompass","ItemWatch","OPTRE_NVG"]],
  ["OLI_MA5C","OLI_BR45B","OLI_M295_BMR","OLI_M6G","19_UNSC_M6C","TKE_MDPistolBlack","Optre_Evo_Sight_Riser","OPTRE_M12_Optic","OLI_MEQ7","OPTRE_UNSC_VX16_Helmet_Mask","OPTRE_UNSC_VX16_HelmetNV","OPTRE_UNSC_VX16_HelmetV","OPTRE_UNSC_VX16_Helmet","OPTRE_UNSC_VX16_Helmet_MaskV","Rogue_CEBoonieGrey","Rogue_CEBoonie","H_Watchcap_blk","H_Bandanna_gry","OPTRE_HUD_In_Glasses","OPTRE_HUD_g_Glasses","OPTRE_EyePiece","OLI_Stealth_Mask_Goggle","OLI_Stealth_Mask"],
"true",
{}
] spawn Wbk_AddKit;

// systemChat "[505th] Pilot Kits registered successfully!";
