#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        author = AUTHOR;
        url = "";
        units[] = { QCLASS(Module_AddResources), QCLASS(Module_SupplyDrop), QCLASS(EngineerSupplyCrate), QCLASS(EngineerSupplyPallet) };
        weapons[] = { QCLASS(Combat_Engineer_Toolkit) };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Functions_F","cba_main","cba_xeh",QCLASS(main),"OPTRE_Core",QCLASS(Objects)};
        version = VERSION;
        versionStr = QUOTE(VERSION_STR);
        versionAr[] = {VERSION_AR};
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON { init = QUOTE(call compile preprocessFileLineNumbers QQPATHTOF(XEH_preInit.sqf)); };
};
class Extended_PostInit_EventHandlers {
    class ADDON { init = QUOTE(call compile preprocessFileLineNumbers QQPATHTOF(XEH_postInit.sqf)); };
};

// =============================================================================
//   ZEUS MODULE – Add Engineer Resources
// =============================================================================
class CfgVehicles {
    class Module_F;

    class CLASS(Module_AddResources): Module_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "Add Engineer Resources";
        category = QCLASS(Zeus);
        function = QFUNC(zeusAddResources);
        functionPriority = 1;
        isGlobal = 1;     // run on server
        isTriggerActivated = 0;
        isDisposable = 1;  // delete after use
        curatorCanAttach = 1;

        author = AUTHOR;
        icon = "\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\repair_ca.paa";

        class Attributes {
            class Units {
                property = QCLASS(Module_AddResources_Units);
                control = "Units";
                displayName = "Synced Units";
                expression = "";
            };
        };

        class ModuleDescription {
            description = "Place on a player to add engineer build resources. A dialog will ask for the amount.";
        };
    };

// =============================================================================
//   ZEUS MODULE – Airdrop Engineer Supplies
// =============================================================================

    class CLASS(Module_SupplyDrop): Module_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "Airdrop Engineer Supplies";
        category = QCLASS(Zeus);
        function = QFUNC(zeusSupplyDrop);
        functionPriority = 1;
        isGlobal = 0;     // run on Zeus client (UI selection)
        isTriggerActivated = 0;
        isDisposable = 1;
        curatorCanAttach = 0;

        author = AUTHOR;
        icon = "\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\supply_ca.paa";

        class ModuleDescription {
            description = "Place on map to airdrop supplies. Pallet spawns at 200m, parachutes down with wind drift. Orange smoke marks landing.";
        };
    };

// =============================================================================
//   ENGINEER SUPPLY CRATE – Small (50 resources)
// =============================================================================

    class Land_TCP_Space_Crate_01_Blue;

    class CLASS(EngineerSupplyCrate): Land_TCP_Space_Crate_01_Blue {
        scope = 2;
        scopeCurator = 2;
        author = AUTHOR;

        displayName = "Engineer Supply Crate";
        descriptionShort = "Contains 50 engineer build resources. Engineers only - ACE interact to collect.";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Resupply);

        // ACE Cargo — fits 6 slots so 4 fit inside the large pallet (24 slots)
        ace_cargo_canLoad = 1;
        ace_cargo_size = 6;

        // ACE Dragging / Carrying
        ace_dragging_canDrag = 1;
        ace_dragging_dragDirection = 0;
        ace_dragging_carryDirection = 90;
        ace_dragging_dragPosition[] = {0, 1.2, 0};
        ace_dragging_carryPosition[] = {0, 2, 0};
        ace_dragging_canCarry = 1;
        ace_dragging_ignoreWeight = 1;
        ace_dragging_ignoreWeightCarry = 1;

        class EventHandlers {
            // Fires on Eden/Zeus placement and debug console spawn
            init = QUOTE(if (hasInterface || isServer) then { [_this select 0] call FUNC(initSupplyCrate); };);
        };
    };

// =============================================================================
//   ENGINEER SUPPLY PALLET – Large (4x small crates, 200 resources total)
// =============================================================================

    class Land_TCP_Space_Crate_Pallet_Large_01_Blue;

    class CLASS(EngineerSupplyPallet): Land_TCP_Space_Crate_Pallet_Large_01_Blue {
        scope = 2;
        scopeCurator = 2;
        author = AUTHOR;

        displayName = "Engineer Supply Pallet";
        descriptionShort = "Contains 4x Engineer Supply Crates (200 resources total). Sling-load and deliver to engineers.";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Resupply);

        // ACE Cargo — 24 slots holds exactly 4x small crates (6 slots each)
        ace_cargo_size = 24;
        ace_cargo_canLoad = 1;
        ace_cargo_blockUnloadCarry = 0;
        ace_cargo_space = 24;
        ace_cargo_hasCargo = 1;

        // ACE Dragging / Carrying — pallet is too heavy to carry
        ace_dragging_canDrag = 0;
        ace_dragging_canCarry = 0;

        class EventHandlers {
            init = QUOTE(if (isServer) then { [_this select 0] call FUNC(initSupplyPallet); };);
        };
    };
};

// =============================================================================
//   BASE CLASSES
// =============================================================================

class RscText {
    deletable=0; fade=0; access=0; type=0; idc=-1;
    colorBackground[] = {0,0,0,0};
    colorText[] = {0.85,0.90,0.88,1};
    text=""; fixedWidth=0; x=0; y=0; h=0.037; w=0.3;
    style=0; shadow=0;
    font="PuristaMedium";
    SizeEx=0.022;
    linespacing=1;
};

class RscStructuredText {
    deletable=0; fade=0; access=0; type=13; idc=-1;
    style=0;
    colorText[] = {0.85,0.90,0.88,1};
    class Attributes {
        font="PuristaMedium"; color="#D9E6DC"; align="left"; shadow=0;
    };
    x=0; y=0; h=0.035; w=0.1; text="";
    size=0.022; shadow=0;
};

class RscPicture {
    deletable=0; fade=0; access=0; type=0; idc=-1;
    style=48;
    colorBackground[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    font="TahomaB"; sizeEx=0; lineSpacing=0;
    text=""; fixedWidth=0; shadow=0; x=0; y=0; w=0.2; h=0.15;
};

class RscButton {
    deletable=0; fade=0; access=0; type=1; idc=-1;
    style=0x02;
    colorText[] = {0.85,0.90,0.88,1};
    colorBackground[] = {0.08,0.12,0.16,0.97};
    colorBackgroundActive[] = {0.14,0.28,0.34,1};
    colorBackgroundDisabled[] = {0.05,0.07,0.09,0.7};
    colorTextDisabled[] = {0.35,0.35,0.35,1};
    colorFocused[] = {0.14,0.28,0.34,1};
    colorShadow[] = {0,0,0,0};
    colorBorder[] = {0.18,0.42,0.24,0.55};
    borderSize=0.0;
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
    soundPush[]  = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
    soundEscape[]= {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
    x=0; y=0; w=0.3; h=0.04;
    font="PuristaMedium"; sizeEx=0.026; text=""; action="";
};

// =============================================================================
//   DIALOG  –  COMBAT ENGINEER TABLET
// =============================================================================

class GVAR(dialog) {
    idd = IDD_ENGINEER_DIALOG;
    movingEnable = 1;
    enableSimulation = 1;
    onLoad = "[] spawn {sleep 0.05; [] call OLI_engtools_fnc_updateEngineerStatus;}";

    class ControlsBackground {

        // ── Main body ──────────────────────────────────────────────────────────
        class Body: RscText {
            idc=-1;
            x=DIALOG_X; y=DIALOG_Y; w=DIALOG_W; h=DIALOG_H;
            colorBackground[] = {0.06,0.08,0.11,0.97};
        };

        // ── Header bar ────────────────────────────────────────────────────────
        class HeaderBG: RscText {
            idc=-1;
            x=DIALOG_X; y=DIALOG_Y;
            w=DIALOG_W; h="0.060 * safezoneH";
            colorBackground[] = {0.09,0.13,0.17,1.0};
        };
        class HeaderAccent: RscText {
            idc=-1;
            x=DIALOG_X; y="0.103 * safezoneH + safezoneY";
            w=DIALOG_W; h="0.003 * safezoneH";
            colorBackground[] = {0.20,0.55,0.28,0.90};
        };

        // ── Options row background ────────────────────────────────────────────
        class OptionsBG: RscText {
            idc=-1;
            x=DIALOG_X; y="0.307 * safezoneH + safezoneY";
            w=DIALOG_W; h="0.046 * safezoneH";
            colorBackground[] = {0.05,0.07,0.09,0.85};
        };
        class OptionsTopLine: RscText {
            idc=-1;
            x=DIALOG_X; y="0.307 * safezoneH + safezoneY";
            w=DIALOG_W; h="0.002 * safezoneH";
            colorBackground[] = {0.20,0.55,0.28,0.45};
        };
        class OptionsBotLine: RscText {
            idc=-1;
            x=DIALOG_X; y="0.355 * safezoneH + safezoneY";
            w=DIALOG_W; h="0.002 * safezoneH";
            colorBackground[] = {0.20,0.55,0.28,0.45};
        };

        // ── Status bar background ─────────────────────────────────────────────
        class StatusAccentTop: RscText {
            idc=-1;
            x=DIALOG_X; y="0.676 * safezoneH + safezoneY";
            w=DIALOG_W; h="0.002 * safezoneH";
            colorBackground[] = {0.20,0.55,0.28,0.35};
        };
        class StatusBG: RscText {
            idc=-1;
            x=DIALOG_X; y="0.680 * safezoneH + safezoneY";
            w=DIALOG_W; h="0.060 * safezoneH";
            colorBackground[] = {0.04,0.06,0.08,0.95};
        };

        // ── Faded watermark ───────────────────────────────────────────────────
        class Watermark: RscPicture {
            idc=-1;
            style=48;
            x="0.36 * safezoneW + safezoneX";
            y="0.26 * safezoneH + safezoneY";
            w="0.28 * safezoneW"; h="0.50 * safezoneH";
            colorText[] = {1,1,1,0.10};
            text=PATH_LOGO_ENG;
        };

    }; // ControlsBackground

    class Controls {

        // ── 505th logo ────────────────────────────────────────────────────────
        class Logo505: RscPicture {
            idc=-1; style=48;
            x="0.082 * safezoneW + safezoneX";
            y="0.044 * safezoneH + safezoneY";
            w="0.030 * safezoneW"; h="0.054 * safezoneH";
            colorText[] = {1,1,1,1};
            text=PATH_LOGO_505;
        };

        // ── Title ─────────────────────────────────────────────────────────────
        class Title: RscText {
            idc=-1;
            text="COMBAT ENGINEER TABLET";
            x="0.140 * safezoneW + safezoneX";
            y="0.050 * safezoneH + safezoneY";
            w="0.55 * safezoneW"; h="0.036 * safezoneH";
            colorText[] = {0.90,0.95,0.88,1.0};
            font="PuristaBold"; sizeEx=0.036; style=0x00;
        };
        class SubTitle: RscText {
            idc=-1;
            text="505th EXPEDITIONARY FORCE  //  UNITED NATIONS SPACE COMMAND";
            x="0.140 * safezoneW + safezoneX";
            y="0.086 * safezoneH + safezoneY";
            w="0.55 * safezoneW"; h="0.020 * safezoneH";
            colorText[] = {0.30,0.60,0.36,0.80};
            font="PuristaMedium"; sizeEx=0.018; style=0x00;
        };

        // ── Resource display (top-right, next to close button) ────────────────
        class ResourceDisplay: RscText {
            idc=IDC_RESOURCE_DISPLAY;
            text="⬡ ---";
            x="0.780 * safezoneW + safezoneX";
            y="0.050 * safezoneH + safezoneY";
            w="0.110 * safezoneW"; h="0.040 * safezoneH";
            colorText[] = {1.0,0.75,0.20,1.0};
            colorBackground[] = {0.08,0.06,0.02,0.80};
            font="PuristaBold"; sizeEx=0.028; style=0x02;
        };

        // ── Close button ──────────────────────────────────────────────────────
        class CloseButton: RscButton {
            idc=1001; text="X";
            x="0.894 * safezoneW + safezoneX";
            y="0.048 * safezoneH + safezoneY";
            w="0.028 * safezoneW"; h="0.040 * safezoneH";
            colorText[] = {1,1,1,1};
            colorBackground[] = {0.45,0.10,0.10,1};
            colorBackgroundActive[] = {0.65,0.14,0.12,1};
            colorBorder[] = {0.60,0.14,0.12,1};
            font="PuristaBold"; sizeEx=0.022;
            action="closeDialog 0;";
        };

        // ── MODE TABS ─────────────────────────────────────────────────────────
        class ModeTabBuild: RscButton {
            idc=IDC_MODE_BUILD;
            text="BUILD MODE";
            x="0.154 * safezoneW + safezoneX";
            y="0.109 * safezoneH + safezoneY";
            w="0.33 * safezoneW"; h="0.034 * safezoneH";
            colorText[] = {0.88,1.0,0.88,1};
            colorBackground[] = {0.12,0.36,0.17,1.0};
            colorBackgroundActive[] = {0.18,0.50,0.24,1};
            colorBorder[] = {0.22,0.60,0.28,0.90};
            font="PuristaBold"; sizeEx=0.022;
            action="";
        };
        class ModeTabDemolish: RscButton {
            idc=IDC_MODE_DEMOLISH;
            text="DEMOLISH MODE";
            x="0.496 * safezoneW + safezoneX";
            y="0.109 * safezoneH + safezoneY";
            w="0.33 * safezoneW"; h="0.034 * safezoneH";
            colorText[] = {1.0,0.82,0.82,1};
            colorBackground[] = {0.22,0.07,0.07,1.0};
            colorBackgroundActive[] = {0.45,0.12,0.10,1};
            colorBorder[] = {0.55,0.12,0.10,0.90};
            font="PuristaBold"; sizeEx=0.022;
            action="[] call OLI_engtools_fnc_demolishMode; closeDialog 0;";
        };

        // ── PREVIEW PANEL ─────────────────────────────────────────────────────
        class PreviewImgBorder: RscText {
            idc=-1;
            x="0.442 * safezoneW + safezoneX";
            y="0.149 * safezoneH + safezoneY";
            w="0.116 * safezoneW"; h="0.116 * safezoneH";
            colorBackground[] = {0.18,0.42,0.22,0.50};
        };
        class PreviewImage: RscPicture {
            idc=IDC_PREVIEW_IMAGE; style=48;
            x="0.445 * safezoneW + safezoneX";
            y="0.152 * safezoneH + safezoneY";
            w="0.110 * safezoneW"; h="0.110 * safezoneH";
            colorText[] = {1,1,1,1};
            colorBackground[] = {0.06,0.09,0.12,1};
            text="";
        };
        class PreviewName: RscText {
            idc=IDC_PREVIEW_NAME;
            text="Hover an object to preview  |  Select to begin building";
            x="0.078 * safezoneW + safezoneX";
            y="0.268 * safezoneH + safezoneY";
            w="0.844 * safezoneW"; h="0.026 * safezoneH";
            colorText[] = {0.90,0.95,0.88,1.0};
            font="PuristaBold"; sizeEx=0.022; style=0x02;
        };
        class PreviewDesc: RscStructuredText {
            idc=IDC_PREVIEW_DESC;
            x="0.078 * safezoneW + safezoneX";
            y="0.296 * safezoneH + safezoneY";
            w="0.844 * safezoneW"; h="0.018 * safezoneH";
            text="<t color='#778877' align='center'>Select an object from the list to begin placement.</t>";
            size=0.018;
        };

        // ── OPTIONS ROW  (Level Terrain | Snap | Height) ─────────────────────
        class TerrainToggle: RscButton {
            idc=IDC_TERRAIN_TOGGLE;
            text="[ON] LEVEL TERRAIN";
            x="0.080 * safezoneW + safezoneX";
            y="0.313 * safezoneH + safezoneY";
            w="0.170 * safezoneW"; h="0.034 * safezoneH";
            colorText[] = {0.85,1.0,0.85,1};
            colorBackground[] = {0.10,0.36,0.16,1.0};
            colorBackgroundActive[] = {0.14,0.48,0.22,1};
            colorBorder[] = {0.20,0.60,0.28,0.80};
            font="PuristaBold"; sizeEx=0.020;
            action="[] call OLI_engtools_fnc_toggleTerrain;";
        };
        class SnapToggle: RscButton {
            idc=IDC_SNAP_TOGGLE;
            text="[OFF] SNAP";
            x="0.262 * safezoneW + safezoneX";
            y="0.313 * safezoneH + safezoneY";
            w="0.130 * safezoneW"; h="0.034 * safezoneH";
            colorText[] = {0.80,0.88,1.0,1};
            colorBackground[] = {0.10,0.14,0.30,1.0};
            colorBackgroundActive[] = {0.14,0.20,0.42,1};
            colorBorder[] = {0.20,0.28,0.60,0.80};
            font="PuristaBold"; sizeEx=0.020;
            action="[] call OLI_engtools_fnc_toggleSnap;";
        };
        class HeightLabel: RscText {
            idc=-1; text="HEIGHT:";
            x="0.408 * safezoneW + safezoneX";
            y="0.315 * safezoneH + safezoneY";
            w="0.060 * safezoneW"; h="0.030 * safezoneH";
            colorText[] = {0.50,0.75,0.55,1};
            font="PuristaBold"; sizeEx=0.020; style=0x02;
        };
        class HeightDown: RscButton {
            idc=IDC_HEIGHT_DOWN; text="−";
            x="0.472 * safezoneW + safezoneX";
            y="0.313 * safezoneH + safezoneY";
            w="0.030 * safezoneW"; h="0.034 * safezoneH";
            colorText[] = {1.0,0.80,0.50,1};
            colorBackground[] = {0.22,0.12,0.06,1};
            colorBackgroundActive[] = {0.35,0.18,0.08,1};
            font="PuristaBold"; sizeEx=0.028;
            action="[] call OLI_engtools_fnc_heightDown;";
        };
        class HeightDisplay: RscButton {
            idc=IDC_HEIGHT_DISPLAY; text="0.0m";
            x="0.505 * safezoneW + safezoneX";
            y="0.313 * safezoneH + safezoneY";
            w="0.070 * safezoneW"; h="0.034 * safezoneH";
            colorText[] = {0.95,0.95,0.75,1};
            colorBackground[] = {0.05,0.07,0.10,1};
            colorBackgroundActive[] = {0.05,0.07,0.10,1};
            colorBorder[] = {0.22,0.50,0.28,0.60};
            font="PuristaBold"; sizeEx=0.022; style=0x02;
            action="";
        };
        class HeightUp: RscButton {
            idc=IDC_HEIGHT_UP; text="+";
            x="0.578 * safezoneW + safezoneX";
            y="0.313 * safezoneH + safezoneY";
            w="0.030 * safezoneW"; h="0.034 * safezoneH";
            colorText[] = {0.50,1.0,0.55,1};
            colorBackground[] = {0.07,0.20,0.10,1};
            colorBackgroundActive[] = {0.10,0.32,0.16,1};
            font="PuristaBold"; sizeEx=0.028;
            action="[] call OLI_engtools_fnc_heightUp;";
        };
        class HeightReset: RscButton {
            idc=IDC_HEIGHT_RESET; text="RST";
            x="0.611 * safezoneW + safezoneX";
            y="0.313 * safezoneH + safezoneY";
            w="0.038 * safezoneW"; h="0.034 * safezoneH";
            colorText[] = {0.70,0.70,0.70,1};
            colorBackground[] = {0.10,0.12,0.14,1};
            colorBackgroundActive[] = {0.16,0.18,0.20,1};
            font="PuristaMedium"; sizeEx=0.018;
            action="OLI_engtools_buildHeight = 0; private _ctrl = findDisplay 85050 displayCtrl 3103; _ctrl ctrlSetText '0.0m';";
        };
        class HeightStepHint: RscText {
            idc=-1; text="(±0.10m)";
            x="0.656 * safezoneW + safezoneX";
            y="0.318 * safezoneH + safezoneY";
            w="0.065 * safezoneW"; h="0.024 * safezoneH";
            colorText[] = {0.32,0.50,0.36,0.70};
            font="PuristaMedium"; sizeEx=0.018; style=0x02;
        };
        // NOTE: Auto-level toggle removed (v10)

        // ── COLUMN HEADERS ────────────────────────────────────────────────────
        class ColHeader1: RscText {
            idc=-1; text="── OPTRE BARRIERS ──";
            x=COL1_X; y="0.360 * safezoneH + safezoneY";
            w=BTN_W;  h="0.024 * safezoneH";
            colorText[] = {0.22,0.65,0.32,1.0};
            font="PuristaBold"; sizeEx=0.020; style=0x02;
        };
        class ColHeader2: RscText {
            idc=-1; text="── WALLS & RAMPS ──";
            x=COL2_X; y="0.360 * safezoneH + safezoneY";
            w=BTN_W;  h="0.024 * safezoneH";
            colorText[] = {0.22,0.65,0.32,1.0};
            font="PuristaBold"; sizeEx=0.020; style=0x02;
        };
        class ColHeader3: RscText {
            idc=-1; text="── TKE EQUIPMENT ──";
            x=COL3_X; y="0.360 * safezoneH + safezoneY";
            w=BTN_W;  h="0.024 * safezoneH";
            colorText[] = {0.22,0.65,0.32,1.0};
            font="PuristaBold"; sizeEx=0.020; style=0x02;
        };

        // ── COL 1 – OPTRE BARRIERS ───────────────────────────────────────────
        class BtnM72S: RscButton { idc=2001; text="M72S Barrier";
            x=COL1_X; y=ROW1_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['Land_OPTRE_M72S_barrier','M72S Barrier','UNSC modular barrier section.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['Land_OPTRE_M72S_barrier'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnRidgcoOne: RscButton { idc=2002; text="Barrier One";
            x=COL1_X; y=ROW2_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['OPTRE_Ridgco_Barrier_One','Barrier One','Ridgco single barrier unit.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['OPTRE_Ridgco_Barrier_One'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnRidgcoThree: RscButton { idc=2003; text="Barrier Three";
            x=COL1_X; y=ROW3_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['OPTRE_Ridgco_Barrier_Three','Barrier Three','Ridgco triple-width barrier.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['OPTRE_Ridgco_Barrier_Three'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnRidgcoFour: RscButton { idc=2004; text="Barrier Four";
            x=COL1_X; y=ROW4_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['OPTRE_Ridgco_Barrier_Four','Barrier Four','Ridgco quad-width barrier.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['OPTRE_Ridgco_Barrier_Four'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnRidgcoFive: RscButton { idc=2005; text="Barrier Five";
            x=COL1_X; y=ROW5_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['OPTRE_Ridgco_Barrier_Five','Barrier Five','Ridgco five-wide barrier.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['OPTRE_Ridgco_Barrier_Five'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnRidgcoTower: RscButton { idc=2006; text="Barrier Tower";
            x=COL1_X; y=ROW6_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['OPTRE_Ridgco_Barrier_Tower','Barrier Tower','Elevated watch tower section.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['OPTRE_Ridgco_Barrier_Tower'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnRidgcoTunnel: RscButton { idc=2007; text="Barrier Tunnel";
            x=COL1_X; y=ROW7_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['OPTRE_Ridgco_Barrier_Tunnel','Barrier Tunnel','Covered tunnel passthrough.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['OPTRE_Ridgco_Barrier_Tunnel'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };

        // ── COL 2 – WALLS & RAMPS ────────────────────────────────────────────
        class BtnRidgcoRamp: RscButton { idc=2011; text="Barrier Ramp";
            x=COL2_X; y=ROW1_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['OPTRE_Ridgco_Barrier_Ramp','Barrier Ramp','Vehicle access ramp.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['OPTRE_Ridgco_Barrier_Ramp'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnRidgcoCorner: RscButton { idc=2012; text="Corner";
            x=COL2_X; y=ROW2_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['OPTRE_Ridgco_Barrier_Corner','Corner','Right-angle corner section.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['OPTRE_Ridgco_Barrier_Corner'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnRidgcoCornerInv: RscButton { idc=2013; text="Corner Inverted";
            x=COL2_X; y=ROW3_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['OPTRE_Ridgco_Barrier_Corner_Inverted','Corner Inverted','Inverse corner for inner walls.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['OPTRE_Ridgco_Barrier_Corner_Inverted'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnRidgcoWallShort: RscButton { idc=2014; text="Wall Short";
            x=COL2_X; y=ROW4_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['OPTRE_Ridgco_Barrier_Wall_Short','Wall Short','Short wall segment.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['OPTRE_Ridgco_Barrier_Wall_Short'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnRidgcoWallLong: RscButton { idc=2015; text="Wall Long";
            x=COL2_X; y=ROW5_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['OPTRE_Ridgco_Barrier_Wall_Long','Wall Long','Long wall segment.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['OPTRE_Ridgco_Barrier_Wall_Long'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnRidgcoWallRamp: RscButton { idc=2016; text="Wall Ramp";
            x=COL2_X; y=ROW6_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['OPTRE_Ridgco_Barrier_Wall_Ramp','Wall Ramp','OPTRE Ridgco wall ramp section.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['OPTRE_Ridgco_Barrier_Wall_Ramp'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnCol2Row7: RscButton { idc=2017; text="— empty —";
            x=COL2_X; y=ROW7_Y; w=BTN_W; h=BTN_H;
            colorText[] = {0.35,0.40,0.35,0.50};
            colorBackground[] = {0.06,0.08,0.07,0.60};
            colorBackgroundActive[] = {0.06,0.08,0.07,0.60};
            action=""; };

        // ── COL 3 – TKE EQUIPMENT ────────────────────────────────────────────
        class BtnTKECover: RscButton { idc=2021; text="Deployable Cover";
            x=COL3_X; y=ROW1_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['land_TKE_DeployableCover','Deployable Cover','Portable ballistic cover.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['land_TKE_DeployableCover'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnTKEBunker: RscButton { idc=2022; text="Half Bunker";
            x=COL3_X; y=ROW2_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['land_TKE_HalfBunker','Half Bunker','Partial bunker fortification.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['land_TKE_HalfBunker'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnTKERoad: RscButton { idc=2023; text="Road Barrier";
            x=COL3_X; y=ROW3_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['land_TKE_RoadBarrier','Road Barrier','Vehicle blocking road barrier.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['land_TKE_RoadBarrier'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnTKETrap: RscButton { idc=2024; text="Tank Trap";
            x=COL3_X; y=ROW4_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['land_TKE_TankTrap','Tank Trap','Anti-vehicle tank trap.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['land_TKE_TankTrap'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnTKELight: RscButton { idc=2025; text="Mil Light";
            x=COL3_X; y=ROW5_Y; w=BTN_W; h=BTN_H;
            onMouseEnter="['land_TKE_MilLight','Mil Light','TKE military light post.'] call OLI_engtools_fnc_updatePreview;";
            onMouseExit="[] call OLI_engtools_fnc_updatePreview;";
            action="['land_TKE_MilLight'] call OLI_engtools_fnc_buildObject; closeDialog 0;"; };
        class BtnCol3Row6: RscButton { idc=2026; text="— empty —";
            x=COL3_X; y=ROW6_Y; w=BTN_W; h=BTN_H;
            colorText[] = {0.35,0.40,0.35,0.50};
            colorBackground[] = {0.06,0.08,0.07,0.60};
            colorBackgroundActive[] = {0.06,0.08,0.07,0.60};
            action=""; };
        class BtnCol3Row7: RscButton { idc=2027; text="— empty —";
            x=COL3_X; y=ROW7_Y; w=BTN_W; h=BTN_H;
            colorText[] = {0.35,0.40,0.35,0.50};
            colorBackground[] = {0.06,0.08,0.07,0.60};
            colorBackgroundActive[] = {0.06,0.08,0.07,0.60};
            action=""; };

        // ── STATUS BAR ────────────────────────────────────────────────────────
        class StatusText: RscStructuredText {
            idc=IDC_STATUS_TEXT;
            x=DIALOG_X; y="0.682 * safezoneH + safezoneY";
            w=DIALOG_W; h="0.026 * safezoneH";
            colorText[] = {0.60,0.80,0.65,1};
            text="<t align='center'>Initialising...</t>";
            size=0.018;
        };

        // ── CONTROLS HINT ─────────────────────────────────────────────────────
        class ControlsHint: RscText {
            idc=-1;
            text="BUILD: LMB Place | Q/E Yaw | Shift+Q/E Pitch | Ctrl+Q/E Bank | ALT Terrain Snap | Scroll Distance | PgUp/PgDn Height | TAB Snap | Backspace Reset Tilt";
            x=DIALOG_X; y="0.711 * safezoneH + safezoneY";
            w=DIALOG_W; h="0.018 * safezoneH";
            colorText[] = {0.26,0.40,0.30,0.65};
            colorBackground[] = {0.04,0.06,0.08,0.50};
            font="PuristaMedium"; sizeEx=0.015; style=0x02;
        };

    }; // Controls
}; // dialog

#include "CfgWeapons.hpp"
