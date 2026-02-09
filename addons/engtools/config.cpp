#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        author = AUTHOR;
        url = "";
        units[] = {};
        weapons[] = {
            QCLASS(Combat_Engineer_Toolkit)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Functions_F", "cba_main", "cba_xeh", QCLASS(main), "OPTRE_Core"};
        version = VERSION;
        versionStr = QUOTE(VERSION_STR);
        versionAr[] = {VERSION_AR};
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call compile preprocessFileLineNumbers QQPATHTOF(XEH_preInit.sqf));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call compile preprocessFileLineNumbers QQPATHTOF(XEH_postInit.sqf));
    };
};

class RscText {
    deletable = 0;
    fade = 0;
    access = 0;
    type = 0;
    idc = -1;
    colorBackground[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    text = "";
    fixedWidth = 0;
    x = 0;
    y = 0;
    h = 0.037;
    w = 0.3;
    style = 0;
    shadow = 1;
    colorShadow[] = {0,0,0,0.5};
    font = "RobotoCondensed";
    SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    linespacing = 1;
};

class RscStructuredText {
    deletable = 0;
    fade = 0;
    access = 0;
    type = 13;
    idc = -1;
    style = 0;
    colorText[] = {1,1,1,1};
    class Attributes {
        font = "RobotoCondensed";
        color = "#ffffff";
        align = "left";
        shadow = 1;
    };
    x = 0;
    y = 0;
    h = 0.035;
    w = 0.1;
    text = "";
    size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    shadow = 1;
};

class RscPicture {
    deletable = 0;
    fade = 0;
    access = 0;
    type = 0;
    idc = -1;
    style = 48;
    colorBackground[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    font = "TahomaB";
    sizeEx = 0;
    lineSpacing = 0;
    text = "";
    fixedWidth = 0;
    shadow = 0;
    x = 0;
    y = 0;
    w = 0.2;
    h = 0.15;
};

class RscButton {
    deletable = 0;
    fade = 0;
    access = 0;
    type = 1;
    text = "";
    colorText[] = {1,1,1,1};
    colorDisabled[] = {1,1,1,0.25};
    colorBackground[] = {0,0,0,0.5};
    colorBackgroundDisabled[] = {0,0,0,0.5};
    colorBackgroundActive[] = {0,0,0,1};
    colorFocused[] = {0,0,0,1};
    colorShadow[] = {0,0,0,0};
    colorBorder[] = {0,0,0,1};
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
    idc = -1;
    style = 2;
    x = 0;
    y = 0;
    w = 0.095589;
    h = 0.039216;
    shadow = 2;
    font = "RobotoCondensed";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    offsetX = 0;
    offsetY = 0;
    offsetPressedX = 0;
    offsetPressedY = 0;
    borderSize = 0;
};

#define ST_CENTER 0x02
#define ST_PICTURE 48

class GVAR(dialog) {
    idd = IDD_ENGINEER_DIALOG;
    movingEnable = 1;
    enableSimulation = 1;
    
    class ControlsBackground {
        class Background: RscText {
            idc = -1;
            x = "0.15 * safezoneW + safezoneX";
            y = "0.10 * safezoneH + safezoneY";
            w = "0.70 * safezoneW";
            h = "0.75 * safezoneH";
            colorBackground[] = {0.05,0.05,0.08,0.95};
        };
        class HeaderBar: RscText {
            idc = -1;
            x = "0.15 * safezoneW + safezoneX";
            y = "0.10 * safezoneH + safezoneY";
            w = "0.70 * safezoneW";
            h = "0.04 * safezoneH";
            colorBackground[] = {0.8,0.4,0,1};
        };
    };
    
    class Controls {
        class Title: RscText {
            idc = 1000;
            text = "505TH COMBAT ENGINEERING";
            x = "0.15 * safezoneW + safezoneX";
            y = "0.105 * safezoneH + safezoneY";
            w = "0.68 * safezoneW";
            h = "0.03 * safezoneH";
            colorText[] = {1,1,1,1};
            font = "PuristaMedium";
            sizeEx = 0.035;
            style = ST_CENTER;
        };
        
        class CloseButton: RscButton {
            idc = 1001;
            text = "X";
            x = "0.83 * safezoneW + safezoneX";
            y = "0.105 * safezoneH + safezoneY";
            w = "0.02 * safezoneW";
            h = "0.03 * safezoneH";
            colorText[] = {1,1,1,1};
            colorBackground[] = {0.6,0.1,0.1,1};
            colorBackgroundActive[] = {0.8,0.2,0.2,1};
            font = "PuristaMedium";
            sizeEx = 0.03;
            action = "closeDialog 0;";
        };
        
        // Preview Panel
        class PreviewBackground: RscText {
            idc = -1;
            x = "0.66 * safezoneW + safezoneX";
            y = "0.15 * safezoneH + safezoneY";
            w = "0.18 * safezoneW";
            h = "0.30 * safezoneH";
            colorBackground[] = {0.1,0.1,0.15,1};
        };
        class PreviewLabel: RscText {
            idc = -1;
            text = "PREVIEW";
            x = "0.66 * safezoneW + safezoneX";
            y = "0.155 * safezoneH + safezoneY";
            w = "0.18 * safezoneW";
            h = "0.025 * safezoneH";
            colorText[] = {0.8,0.4,0,1};
            font = "PuristaMedium";
            sizeEx = 0.022;
            style = ST_CENTER;
        };
        class PreviewImage: RscPicture {
            idc = IDC_PREVIEW_IMAGE;
            x = "0.67 * safezoneW + safezoneX";
            y = "0.185 * safezoneH + safezoneY";
            w = "0.16 * safezoneW";
            h = "0.14 * safezoneH";
            text = "";
            style = ST_PICTURE;
        };
        class PreviewName: RscText {
            idc = IDC_PREVIEW_NAME;
            text = "Hover for preview";
            x = "0.66 * safezoneW + safezoneX";
            y = "0.33 * safezoneH + safezoneY";
            w = "0.18 * safezoneW";
            h = "0.025 * safezoneH";
            colorText[] = {1,1,1,1};
            font = "PuristaMedium";
            sizeEx = 0.020;
            style = ST_CENTER;
        };
        class PreviewDesc: RscStructuredText {
            idc = IDC_PREVIEW_DESC;
            x = "0.66 * safezoneW + safezoneX";
            y = "0.36 * safezoneH + safezoneY";
            w = "0.18 * safezoneW";
            h = "0.08 * safezoneH";
            size = 0.018;
        };
        
        // COLUMN 1 - OPTRE BARRIERS
        class LabelOPTREBarriers: RscText {
            idc = -1;
            text = "OPTRE BARRIERS";
            x = "0.16 * safezoneW + safezoneX";
            y = "0.15 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.025 * safezoneH";
            colorText[] = {0.8,0.4,0,1};
            font = "PuristaMedium";
            sizeEx = 0.022;
        };
        
        class BtnM72S: RscButton {
            idc = 2001;
            text = "M72S Barrier";
            x = "0.16 * safezoneW + safezoneX";
            y = "0.18 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['Land_OPTRE_M72S_barrier', 'M72S Barrier', 'UNSC fortification.'] call OLI_engtools_fnc_updatePreview;";
            action = "['Land_OPTRE_M72S_barrier'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnRidgcoOne: RscButton {
            idc = 2002;
            text = "Barrier One";
            x = "0.16 * safezoneW + safezoneX";
            y = "0.21 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['OPTRE_Ridgco_Barrier_One', 'Ridgway Barrier 1', 'Single block.'] call OLI_engtools_fnc_updatePreview;";
            action = "['OPTRE_Ridgco_Barrier_One'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnRidgcoThree: RscButton {
            idc = 2003;
            text = "Barrier Three";
            x = "0.16 * safezoneW + safezoneX";
            y = "0.24 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['OPTRE_Ridgco_Barrier_Three', 'Ridgway Barrier 3', 'Three blocks.'] call OLI_engtools_fnc_updatePreview;";
            action = "['OPTRE_Ridgco_Barrier_Three'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnRidgcoFour: RscButton {
            idc = 2004;
            text = "Barrier Four";
            x = "0.16 * safezoneW + safezoneX";
            y = "0.27 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['OPTRE_Ridgco_Barrier_Four', 'Ridgway Barrier 4', 'Four blocks.'] call OLI_engtools_fnc_updatePreview;";
            action = "['OPTRE_Ridgco_Barrier_Four'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnRidgcoFive: RscButton {
            idc = 2005;
            text = "Barrier Five";
            x = "0.16 * safezoneW + safezoneX";
            y = "0.30 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['OPTRE_Ridgco_Barrier_Five', 'Ridgway Barrier 5', 'Five blocks.'] call OLI_engtools_fnc_updatePreview;";
            action = "['OPTRE_Ridgco_Barrier_Five'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnRidgcoTower: RscButton {
            idc = 2006;
            text = "Barrier Tower";
            x = "0.16 * safezoneW + safezoneX";
            y = "0.33 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['OPTRE_Ridgco_Barrier_Tower', 'Ridgway Tower', 'Elevated position.'] call OLI_engtools_fnc_updatePreview;";
            action = "['OPTRE_Ridgco_Barrier_Tower'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnRidgcoTunnel: RscButton {
            idc = 2007;
            text = "Barrier Tunnel";
            x = "0.16 * safezoneW + safezoneX";
            y = "0.36 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['OPTRE_Ridgco_Barrier_Tunnel', 'Ridgway Tunnel', 'Covered passage.'] call OLI_engtools_fnc_updatePreview;";
            action = "['OPTRE_Ridgco_Barrier_Tunnel'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        
        // COLUMN 2 - OPTRE WALLS & RAMPS
        class LabelOPTREWalls: RscText {
            idc = -1;
            text = "WALLS & RAMPS";
            x = "0.32 * safezoneW + safezoneX";
            y = "0.15 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.025 * safezoneH";
            colorText[] = {0.8,0.4,0,1};
            font = "PuristaMedium";
            sizeEx = 0.022;
        };
        
        class BtnRidgcoRamp: RscButton {
            idc = 2011;
            text = "Barrier Ramp";
            x = "0.32 * safezoneW + safezoneX";
            y = "0.18 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['OPTRE_Ridgco_Barrier_Ramp', 'Ridgway Ramp', 'Access ramp.'] call OLI_engtools_fnc_updatePreview;";
            action = "['OPTRE_Ridgco_Barrier_Ramp'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnRidgcoCorner: RscButton {
            idc = 2012;
            text = "Corner";
            x = "0.32 * safezoneW + safezoneX";
            y = "0.21 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['OPTRE_Ridgco_Barrier_Corner', 'Ridgway Corner', '90° corner.'] call OLI_engtools_fnc_updatePreview;";
            action = "['OPTRE_Ridgco_Barrier_Corner'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnRidgcoCornerInv: RscButton {
            idc = 2013;
            text = "Corner Inverted";
            x = "0.32 * safezoneW + safezoneX";
            y = "0.24 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['OPTRE_Ridgco_Barrier_Corner_Inverted', 'Corner Inverted', 'Inverted corner.'] call OLI_engtools_fnc_updatePreview;";
            action = "['OPTRE_Ridgco_Barrier_Corner_Inverted'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnRidgcoWallShort: RscButton {
            idc = 2014;
            text = "Wall Short";
            x = "0.32 * safezoneW + safezoneX";
            y = "0.27 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['OPTRE_Ridgco_Barrier_Wall_Short', 'Wall Short', 'Short wall section.'] call OLI_engtools_fnc_updatePreview;";
            action = "['OPTRE_Ridgco_Barrier_Wall_Short'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnRidgcoWallLong: RscButton {
            idc = 2015;
            text = "Wall Long";
            x = "0.32 * safezoneW + safezoneX";
            y = "0.30 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['OPTRE_Ridgco_Barrier_Wall_Long', 'Wall Long', 'Long wall section.'] call OLI_engtools_fnc_updatePreview;";
            action = "['OPTRE_Ridgco_Barrier_Wall_Long'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnRidgcoWallRamp: RscButton {
            idc = 2016;
            text = "Wall Ramp";
            x = "0.32 * safezoneW + safezoneX";
            y = "0.33 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['OPTRE_Ridgco_Barrier_Wall_Ramp', 'Wall Ramp', 'Wall with ramp.'] call OLI_engtools_fnc_updatePreview;";
            action = "['OPTRE_Ridgco_Barrier_Wall_Ramp'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        
        // COLUMN 3 - TKE FORTIFICATIONS
        class LabelTKE: RscText {
            idc = -1;
            text = "TKE FORTIFICATIONS";
            x = "0.48 * safezoneW + safezoneX";
            y = "0.15 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.025 * safezoneH";
            colorText[] = {0.8,0.4,0,1};
            font = "PuristaMedium";
            sizeEx = 0.022;
        };
        
        class BtnTKECover: RscButton {
            idc = 2021;
            text = "Deployable Cover";
            x = "0.48 * safezoneW + safezoneX";
            y = "0.18 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['land_TKE_DeployableCover', 'Deployable Cover', 'Portable cover.'] call OLI_engtools_fnc_updatePreview;";
            action = "['land_TKE_DeployableCover'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnTKEBunker: RscButton {
            idc = 2022;
            text = "Half Bunker";
            x = "0.48 * safezoneW + safezoneX";
            y = "0.21 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['land_TKE_HalfBunker', 'Half Bunker', 'Bunker position.'] call OLI_engtools_fnc_updatePreview;";
            action = "['land_TKE_HalfBunker'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnTKERoadBarrier: RscButton {
            idc = 2023;
            text = "Road Barrier";
            x = "0.48 * safezoneW + safezoneX";
            y = "0.24 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['land_TKE_RoadBarrier', 'Road Barrier', 'Traffic control.'] call OLI_engtools_fnc_updatePreview;";
            action = "['land_TKE_RoadBarrier'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnTKETankTrap: RscButton {
            idc = 2024;
            text = "Tank Trap";
            x = "0.48 * safezoneW + safezoneX";
            y = "0.27 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['land_TKE_TankTrap', 'Tank Trap', 'Anti-vehicle obstacle.'] call OLI_engtools_fnc_updatePreview;";
            action = "['land_TKE_TankTrap'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        class BtnTKELight: RscButton {
            idc = 2025;
            text = "Mil Light";
            x = "0.48 * safezoneW + safezoneX";
            y = "0.30 * safezoneH + safezoneY";
            w = "0.15 * safezoneW";
            h = "0.026 * safezoneH";
            colorBackground[] = {0.15,0.15,0.2,1};
            colorBackgroundActive[] = {0.8,0.4,0,1};
            sizeEx = 0.022;
            onMouseEnter = "['land_TKE_MilLight', 'Military Light', 'Illumination.'] call OLI_engtools_fnc_updatePreview;";
            action = "['land_TKE_MilLight'] call OLI_engtools_fnc_buildObject; closeDialog 0;";
        };
        
        
        // STATUS BAR
        class StatusBar: RscText {
            idc = -1;
            x = "0.15 * safezoneW + safezoneX";
            y = "0.53 * safezoneH + safezoneY";
            w = "0.70 * safezoneW";
            h = "0.025 * safezoneH";
            colorBackground[] = {0.08,0.08,0.1,1};
        };
        class StatusText: RscStructuredText {
            idc = IDC_STATUS_TEXT;
            x = "0.16 * safezoneW + safezoneX";
            y = "0.533 * safezoneH + safezoneY";
            w = "0.68 * safezoneW";
            h = "0.02 * safezoneH";
            size = 0.018;
        };
        
        class Instructions: RscText {
            idc = -1;
            text = "LMB: Place | Q/E: Rotate | Shift+RMB: Delete | ESC: Exit | Requires 505th Combat Engineer Toolkit";
            x = "0.15 * safezoneW + safezoneX";
            y = "0.56 * safezoneH + safezoneY";
            w = "0.70 * safezoneW";
            h = "0.02 * safezoneH";
            colorText[] = {0.6,0.6,0.6,1};
            font = "PuristaMedium";
            sizeEx = 0.018;
            style = ST_CENTER;
        };
    };
};

#include "CfgWeapons.hpp"
