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
        SCOPE_PUBLIC;
        displayName = "Add Engineer Resources";
        category = QCLASS(Zeus);
        function = QFUNC(zeusAddResources);
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 1;
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
        SCOPE_PUBLIC;
        displayName = "Airdrop Engineer Supplies";
        category = QCLASS(Zeus);
        function = QFUNC(zeusSupplyDrop);
        functionPriority = 1;
        isGlobal = 0;
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
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "Engineer Supply Crate";
        descriptionShort = "Contains 50 engineer build resources. Engineers only - ACE interact to collect.";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Resupply);

        ace_cargo_canLoad = 1;
        ace_cargo_size = 6;

        ace_dragging_canDrag = 1;
        ace_dragging_dragDirection = 0;
        ace_dragging_carryDirection = 90;
        ace_dragging_dragPosition[] = {0, 1.2, 0};
        ace_dragging_carryPosition[] = {0, 2, 0};
        ace_dragging_canCarry = 1;
        ace_dragging_ignoreWeight = 1;
        ace_dragging_ignoreWeightCarry = 1;

        class EventHandlers {
            init = QUOTE(if (hasInterface || isServer) then { [_this select 0] call FUNC(initSupplyCrate); };);
        };
    };

// =============================================================================
//   ENGINEER SUPPLY PALLET – Large (4x small crates, 200 resources total)
// =============================================================================

    class Land_TCP_Space_Crate_Pallet_Large_01_Blue;

    class CLASS(EngineerSupplyPallet): Land_TCP_Space_Crate_Pallet_Large_01_Blue {
        SCOPE_PUBLIC;
        author = AUTHOR;

        displayName = "Engineer Supply Pallet";
        descriptionShort = "Contains 4x Engineer Supply Crates (200 resources total). Sling-load and deliver to engineers.";

        editorCategory = QEDCAT(Objects);
        editorSubcategory = QEDSUBCAT(Resupply);

        ace_cargo_size = 24;
        ace_cargo_canLoad = 1;
        ace_cargo_blockUnloadCarry = 0;
        ace_cargo_space = 24;
        ace_cargo_hasCargo = 1;

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

class OLI_RscText {
    deletable=0; fade=0; access=0; type=0; idc=-1;
    colorBackground[] = {0,0,0,0};
    colorText[] = {0.85,0.90,0.88,1};
    text=""; fixedWidth=0; x=0; y=0; h=0.037; w=0.3;
    style=0; shadow=0;
    font="PuristaMedium";
    SizeEx=0.022;
    linespacing=1;
};

class OLI_RscStructuredText {
    deletable=0; fade=0; access=0; type=13; idc=-1;
    style=0;
    colorText[] = {0.85,0.90,0.88,1};
    class Attributes {
        font="PuristaMedium"; color="#D9E6DC"; align="left"; shadow=0;
    };
    x=0; y=0; h=0.035; w=0.1; text="";
    size=0.022; shadow=0;
};

class OLI_RscPicture {
    deletable=0; fade=0; access=0; type=0; idc=-1;
    style=48;
    colorBackground[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    font="TahomaB"; sizeEx=0; lineSpacing=0;
    text=""; fixedWidth=0; shadow=0; x=0; y=0; w=0.2; h=0.15;
};

class OLI_RscButton {
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

class OLI_RscListBox {
    deletable=0; fade=0; access=0; type=5; idc=-1;
    colorBackground[]       = {0.04, 0.07, 0.05, 0.95};
    colorSelect[]           = {0.14, 0.38, 0.18, 1.0};
    colorSelectBackground[] = {0.10, 0.26, 0.13, 1.0};
    colorText[]             = {0.88, 0.98, 0.90, 1.0};
    colorDisabled[]         = {0.35, 0.40, 0.35, 0.50};
    colorScrollbar[]        = {0.12, 0.25, 0.14, 1.0};
    font="PuristaMedium"; sizeEx=0.022;
    rowHeight=0.035;
    x=0; y=0; w=0.3; h=0.2;
    maxHistoryDelay=1;
    onLBSelChanged="";
    onLBDblClick="";
    soundSelect[]  = {"",0,0};
    soundExpand[]  = {"",0,0};
    soundCollapse[]= {"",0,0};
};

// =============================================================================
//   DIALOG  –  COMBAT ENGINEER TABLET
// =============================================================================

class GVAR(dialog) {
    idd = IDD_ENGINEER_DIALOG;
    movingEnable = 1;
    enableSimulation = 1;
    onLoad = "[] spawn { disableSerialization; sleep 0.05; [] call OLI_engtools_fnc_updateEngineerStatus; };";
    onUnload = "if (isNil 'OLI_engtools_buildActive' || {!OLI_engtools_buildActive}) then { [false] call OLI_engtools_fnc_buildCameraAssist; ['hide'] call OLI_engtools_fnc_buildHUD; };";

    class ControlsBackground {

        class Body: OLI_RscText {
            idc=-1;
            x=DIALOG_X; y=DIALOG_Y; w=DIALOG_W; h=DIALOG_H;
            colorBackground[] = {0.06,0.08,0.11,0.97};
        };

        class HeaderBG: OLI_RscText {
            idc=-1;
            x=DIALOG_X; y=DIALOG_Y;
            w=DIALOG_W; h="0.060 * safezoneH";
            colorBackground[] = {0.09,0.13,0.17,1.0};
        };
        class HeaderAccent: OLI_RscText {
            idc=-1;
            x=DIALOG_X; y="0.103 * safezoneH + safezoneY";
            w=DIALOG_W; h="0.003 * safezoneH";
            colorBackground[] = {0.20,0.55,0.28,0.90};
        };

        // Column divider — thin vertical accent between list and preview.
        // Left column is x=0.23–0.49 (list + category buttons).
        // Right column is x=0.51–0.79 (preview panel).
        class ColumnDivider: OLI_RscText {
            idc=-1;
            x="0.499 * safezoneW + safezoneX"; y="0.170 * safezoneH + safezoneY";
            w="0.002 * safezoneW"; h="0.500 * safezoneH";
            colorBackground[] = {0.20,0.55,0.28,0.35};
        };

        // Left-column header bar — sits above list/category buttons
        class LeftColHeaderBG: OLI_RscText {
            idc=-1;
            x="0.230 * safezoneW + safezoneX"; y="0.165 * safezoneH + safezoneY";
            w="0.260 * safezoneW"; h="0.038 * safezoneH";
            colorBackground[] = {0.05,0.07,0.09,0.90};
        };
        class LeftColHeaderLine: OLI_RscText {
            idc=-1;
            x="0.230 * safezoneW + safezoneX"; y="0.203 * safezoneH + safezoneY";
            w="0.260 * safezoneW"; h="0.002 * safezoneH";
            colorBackground[] = {0.20,0.55,0.28,0.55};
        };

        // Right-column header bar — sits above preview panel
        class RightColHeaderBG: OLI_RscText {
            idc=-1;
            x="0.510 * safezoneW + safezoneX"; y="0.165 * safezoneH + safezoneY";
            w="0.280 * safezoneW"; h="0.038 * safezoneH";
            colorBackground[] = {0.05,0.07,0.09,0.90};
        };
        class RightColHeaderLine: OLI_RscText {
            idc=-1;
            x="0.510 * safezoneW + safezoneX"; y="0.203 * safezoneH + safezoneY";
            w="0.280 * safezoneW"; h="0.002 * safezoneH";
            colorBackground[] = {0.20,0.55,0.28,0.55};
        };

        class StatusAccentTop: OLI_RscText {
            idc=-1;
            x=DIALOG_X; y="0.676 * safezoneH + safezoneY";
            w=DIALOG_W; h="0.002 * safezoneH";
            colorBackground[] = {0.20,0.55,0.28,0.35};
        };
        class StatusBG: OLI_RscText {
            idc=-1;
            x=DIALOG_X; y="0.680 * safezoneH + safezoneY";
            w=DIALOG_W; h="0.060 * safezoneH";
            colorBackground[] = {0.04,0.06,0.08,0.95};
        };

        class Watermark: OLI_RscPicture {
            idc=-1;
            style=48;
            x="0.37 * safezoneW + safezoneX";
            y="0.26 * safezoneH + safezoneY";
            w="0.26 * safezoneW"; h="0.50 * safezoneH";
            colorText[] = {1,1,1,0.10};
            text=PATH_LOGO_ENG;
        };

    };

    class Controls {

        class Logo505: OLI_RscPicture {
            idc=-1; style=48;
            x="0.192 * safezoneW + safezoneX";
            y="0.044 * safezoneH + safezoneY";
            w="0.030 * safezoneW"; h="0.054 * safezoneH";
            colorText[] = {1,1,1,1};
            text=PATH_LOGO_505;
        };

        class Title: OLI_RscText {
            idc=-1;
            text="COMBAT ENGINEER TABLET";
            x="0.250 * safezoneW + safezoneX";
            y="0.050 * safezoneH + safezoneY";
            w="0.50 * safezoneW"; h="0.036 * safezoneH";
            colorText[] = {0.90,0.95,0.88,1.0};
            font="PuristaBold"; sizeEx=0.036; style=0x00;
        };
        class SubTitle: OLI_RscText {
            idc=-1;
            text="505th EXPEDITIONARY FORCE  //  UNITED NATIONS SPACE COMMAND";
            x="0.250 * safezoneW + safezoneX";
            y="0.086 * safezoneH + safezoneY";
            w="0.50 * safezoneW"; h="0.020 * safezoneH";
            colorText[] = {0.30,0.60,0.36,0.80};
            font="PuristaMedium"; sizeEx=0.018; style=0x00;
        };

        class ResourceDisplay: OLI_RscText {
            idc=IDC_RESOURCE_DISPLAY;
            text="⬡ ---";
            x="0.640 * safezoneW + safezoneX";
            y="0.050 * safezoneH + safezoneY";
            w="0.110 * safezoneW"; h="0.040 * safezoneH";
            colorText[] = {1.0,0.75,0.20,1.0};
            colorBackground[] = {0.08,0.06,0.02,0.80};
            font="PuristaBold"; sizeEx=0.028; style=0x02;
        };

        class CloseButton: OLI_RscButton {
            idc=1001; text="X";
            x="0.754 * safezoneW + safezoneX";
            y="0.048 * safezoneH + safezoneY";
            w="0.028 * safezoneW"; h="0.040 * safezoneH";
            colorText[] = {1,1,1,1};
            colorBackground[] = {0.45,0.10,0.10,1};
            colorBackgroundActive[] = {0.65,0.14,0.12,1};
            colorBorder[] = {0.60,0.14,0.12,1};
            font="PuristaBold"; sizeEx=0.022;
            action="closeDialog 0;";
        };

        class ModeTabBuild: OLI_RscButton {
            idc=IDC_MODE_BUILD;
            text="BUILD MODE";
            x="0.205 * safezoneW + safezoneX";
            y="0.109 * safezoneH + safezoneY";
            w="0.33 * safezoneW"; h="0.034 * safezoneH";
            colorText[] = {0.88,1.0,0.88,1};
            colorBackground[] = {0.12,0.36,0.17,1.0};
            colorBackgroundActive[] = {0.18,0.50,0.24,1};
            colorBorder[] = {0.22,0.60,0.28,0.90};
            font="PuristaBold"; sizeEx=0.022;
            action="";
        };
        class ModeTabDemolish: OLI_RscButton {
            idc=IDC_MODE_DEMOLISH;
            text="DEMOLISH MODE";
            x="0.487 * safezoneW + safezoneX";
            y="0.109 * safezoneH + safezoneY";
            w="0.33 * safezoneW"; h="0.034 * safezoneH";
            colorText[] = {1.0,0.82,0.82,1};
            colorBackground[] = {0.22,0.07,0.07,1.0};
            colorBackgroundActive[] = {0.45,0.12,0.10,1};
            colorBorder[] = {0.55,0.12,0.10,0.90};
            font="PuristaBold"; sizeEx=0.022;
            action="[] call OLI_engtools_fnc_demolishMode; closeDialog 0;";
        };

        // ─────────────────────────────────────────────────────────────────────
        //  TWO-COLUMN LAYOUT
        //
        //  Content area: y 0.16 → 0.67 (between mode tabs and status bar)
        //  Left column:  x 0.23 → 0.49  (list + category buttons)
        //  Right column: x 0.51 → 0.79  (preview panel)
        //
        //  List geometry: y 0.214 → 0.660 (0.446 tall), rowHeight 0.048.
        //  With font sizeEx 0.040 (2× previous), ~9 rows visible without
        //  scroll. Structure has 12 items → last 3 scroll into view. The
        //  scroll-vs-hover lock (see ObjList.onMouseZChanged) means hover
        //  imprecision during scroll isn't a problem — scroll takes full
        //  control until the user clicks somewhere else.
        //
        //  Bottom-left region (y 0.664 → 0.670) is reserved for future
        //  subcategory buttons. Left empty on purpose.
        // ─────────────────────────────────────────────────────────────────────

        // Left column header — "CATEGORY" in category-picker, "Category > X" in list view
        class LeftColTitle: OLI_RscText {
            idc = IDC_CAT_TITLE;
            text = "CATEGORY";
            x = "0.232 * safezoneW + safezoneX";
            y = "0.170 * safezoneH + safezoneY";
            w = "0.256 * safezoneW"; h = "0.030 * safezoneH";
            colorText[]       = {0.22, 0.65, 0.30, 1.0};
            colorBackground[] = {0, 0, 0, 0};
            font = "PuristaBold"; sizeEx = 0.024; style = 0x02;
        };

        // Breadcrumb label — shown in list view only (sits on top of LeftColTitle,
        // so hide one to show the other). Set dynamically by showObjectList.
        class CatLabel: OLI_RscText {
            idc = IDC_CAT_LABEL;
            text = "";
            x = "0.232 * safezoneW + safezoneX";
            y = "0.170 * safezoneH + safezoneY";
            w = "0.256 * safezoneW"; h = "0.030 * safezoneH";
            colorText[]       = {0.22, 0.65, 0.30, 1.0};
            colorBackground[] = {0, 0, 0, 0};
            font = "PuristaBold"; sizeEx = 0.024; style = 0x02;
        };

        // Right column header — "OBJECT PREVIEW"
        class RightColTitle: OLI_RscText {
            idc = -1;
            text = "OBJECT PREVIEW";
            x = "0.512 * safezoneW + safezoneX";
            y = "0.170 * safezoneH + safezoneY";
            w = "0.276 * safezoneW"; h = "0.030 * safezoneH";
            colorText[]       = {0.22, 0.65, 0.30, 1.0};
            colorBackground[] = {0, 0, 0, 0};
            font = "PuristaBold"; sizeEx = 0.024; style = 0x02;
        };

        // ── CATEGORY BUTTONS ──────────────────────────────────────────────────
        // Shown in category-picker view. Centered vertically in the left column.
        // Stacked: Barrier at y=0.320, Structure at 0.380, Misc at 0.440.
        // Below 0.500 is reserved for future subcategory buttons.

        class BtnCatBarrier: OLI_RscButton {
            idc = IDC_CAT_BARRIER;
            text = "Barrier";
            x = "0.236 * safezoneW + safezoneX";
            y = "0.320 * safezoneH + safezoneY";
            w = "0.248 * safezoneW"; h = "0.052 * safezoneH";
            colorText[]             = {0.90, 1.0, 0.92, 1.0};
            colorBackground[]       = {0.10, 0.22, 0.12, 1.0};
            colorBackgroundActive[] = {0.16, 0.36, 0.18, 1.0};
            colorBorder[]           = {0.22, 0.65, 0.30, 0.80};
            font = "PuristaBold"; sizeEx = 0.034;
            action = "[""Barrier""] call OLI_engtools_fnc_showObjectList;";
        };
        class BtnCatStructure: OLI_RscButton {
            idc = IDC_CAT_STRUCTURE;
            text = "Structure";
            x = "0.236 * safezoneW + safezoneX";
            y = "0.380 * safezoneH + safezoneY";
            w = "0.248 * safezoneW"; h = "0.052 * safezoneH";
            colorText[]             = {0.90, 1.0, 0.92, 1.0};
            colorBackground[]       = {0.10, 0.22, 0.12, 1.0};
            colorBackgroundActive[] = {0.16, 0.36, 0.18, 1.0};
            colorBorder[]           = {0.22, 0.65, 0.30, 0.80};
            font = "PuristaBold"; sizeEx = 0.034;
            action = "[""Structure""] call OLI_engtools_fnc_showObjectList;";
        };
        class BtnCatMisc: OLI_RscButton {
            idc = IDC_CAT_MISC;
            text = "Misc";
            x = "0.236 * safezoneW + safezoneX";
            y = "0.440 * safezoneH + safezoneY";
            w = "0.248 * safezoneW"; h = "0.052 * safezoneH";
            colorText[]             = {0.90, 1.0, 0.92, 1.0};
            colorBackground[]       = {0.10, 0.22, 0.12, 1.0};
            colorBackgroundActive[] = {0.16, 0.36, 0.18, 1.0};
            colorBorder[]           = {0.22, 0.65, 0.30, 0.80};
            font = "PuristaBold"; sizeEx = 0.034;
            action = "[""Misc""] call OLI_engtools_fnc_showObjectList;";
        };

        // ── [< Back] button — sits at top of list view, above the list ────────
        class BtnCategoryBack: OLI_RscButton {
            idc = IDC_CAT_BACK;
            text = "<  Back to Categories";
            x = "0.236 * safezoneW + safezoneX";
            y = "0.210 * safezoneH + safezoneY";
            w = "0.248 * safezoneW"; h = "0.040 * safezoneH";
            show = 0;
            colorText[]             = {0.80, 0.90, 0.82, 1.0};
            colorBackground[]       = {0.06, 0.10, 0.07, 1.0};
            colorBackgroundActive[] = {0.10, 0.18, 0.12, 1.0};
            colorBorder[]           = {0.22, 0.55, 0.28, 0.60};
            font = "PuristaBold"; sizeEx = 0.024;
            action = "[] call OLI_engtools_fnc_showCategories;";
        };

        // ── OBJECT LIST ───────────────────────────────────────────────────────
        // Scrollable listbox. y starts below the Back button (0.254), ends
        // above the reserved future-expand region (0.660). Font 2× previous.
        class ObjList: OLI_RscListBox {
            idc = IDC_OBJ_LIST;
            x = "0.236 * safezoneW + safezoneX";
            y = "0.254 * safezoneH + safezoneY";
            w = "0.248 * safezoneW";
            h = "0.406 * safezoneH";
            show = 0;
            colorBackground[]       = {0.04, 0.07, 0.05, 0.95};
            colorSelect[]           = {0.95, 1.00, 0.95, 1.0};
            colorSelectBackground[] = {0.14, 0.38, 0.18, 1.0};
            colorText[]             = {0.88, 0.98, 0.90, 1.0};
            colorDisabled[]         = {0.35, 0.40, 0.35, 0.50};
            font = "PuristaBold"; sizeEx = 0.040;
            rowHeight = 0.048;

            // ── HOVER ──────────────────────────────────────────────────────
            // Updates selection to follow cursor, UNLESS scroll lock is set.
            // Scroll lock is set by onMouseZChanged below and cleared by any
            // click on the dialog (clearScrollLock function).
            onMouseMoving = "
                disableSerialization;
                params ['_ctrl', '_xPos', '_yPos'];
                if (_ctrl getVariable ['OLI_scrollLock', false]) exitWith {};
                private _rh = 0.048;
                private _row = floor (_yPos / _rh);
                private _count = lbSize _ctrl;
                if (_row < 0 || _row >= _count) exitWith {};
                if ((lbCurSel _ctrl) isEqualTo _row) exitWith {};
                _ctrl lbSetCurSel _row;
            ";

            // ── CLICK ──────────────────────────────────────────────────────
            // Click anywhere on list = start placing. Clears scroll lock as
            // a side effect (click = user committed, scroll-preview is over).
            onMouseButtonClick = "
                disableSerialization;
                params ['_ctrl', '_button'];
                _ctrl setVariable ['OLI_scrollLock', false];
                if (_button != 0) exitWith {};
                private _idx = lbCurSel _ctrl;
                if (_idx < 0) exitWith {};
                private _cls = _ctrl lbData _idx;
                if (_cls isEqualTo '' || _cls isEqualTo 'HEADER') exitWith {};
                closeDialog 0;
                [_cls] spawn {
                    params ['_c'];
                    sleep 0.05;
                    [_c] call OLI_engtools_fnc_buildObject;
                };
            ";

            // ── SELECTION CHANGED ─────────────────────────────────────────
            // Drives the preview panel. Fires on mouse move, scroll wheel,
            // arrow keys, and lbSetCurSel — one handler, every source.
            onLBSelChanged = "
                disableSerialization;
                private _lb  = _this select 0;
                private _idx = _this select 1;
                if (_idx < 0) exitWith {};
                private _cls  = _lb lbData    _idx;
                private _name = _lb lbText    _idx;
                private _desc = _lb lbTooltip _idx;
                if (_cls isEqualTo '' || _cls isEqualTo 'HEADER') exitWith {};
                [_cls, _name, _desc] call OLI_engtools_fnc_updatePreview;
            ";
            onLBDblClick = "";

            // ── SCROLL WHEEL ─────────────────────────────────────────────
            // Sets OLI_scrollLock on the control so onMouseMoving stops
            // fighting the selection. Lock is cleared by clicking anywhere.
            onMouseZChanged = "
                disableSerialization;
                params ['_ctrl', '_scroll'];
                private _count = lbSize _ctrl;
                if (_count <= 0) exitWith {};
                _ctrl setVariable ['OLI_scrollLock', true];
                private _cur = lbCurSel _ctrl;
                if (_cur < 0) then { _cur = 0; };
                private _next = ((_cur - _scroll) max 0) min (_count - 1);
                if (_next isEqualTo _cur) exitWith {};
                _ctrl lbSetCurSel _next;
            ";

            // ── ENTER KEY ────────────────────────────────────────────────
            // Alternate commit. DIK 28 = Enter, 156 = NumEnter.
            onKeyDown = "
                disableSerialization;
                params ['_ctrl', '_key'];
                if !(_key in [28, 156]) exitWith {false};
                private _idx = lbCurSel _ctrl;
                if (_idx < 0) exitWith {false};
                private _cls = _ctrl lbData _idx;
                if (_cls isEqualTo '' || _cls isEqualTo 'HEADER') exitWith {false};
                closeDialog 0;
                [_cls] spawn {
                    params ['_c'];
                    sleep 0.05;
                    [_c] call OLI_engtools_fnc_buildObject;
                };
                true
            ";
        };

        // ── PREVIEW PANEL (RIGHT COLUMN) ──────────────────────────────────────
        // Panel background blends with dialog body (no green tint).
        // Image occupies top 60% of right column, name + cost + description
        // below. Shown empty with placeholder text when no selection.

        class PreviewImgBorder: OLI_RscText {
            idc = IDC_PREVIEW_IMG_BORDER;
            x = "0.514 * safezoneW + safezoneX";
            y = "0.214 * safezoneH + safezoneY";
            w = "0.272 * safezoneW"; h = "0.300 * safezoneH";
            colorBackground[] = {0.06,0.08,0.11,0.97};
        };
        class PreviewImage: OLI_RscPicture {
            idc = IDC_PREVIEW_IMAGE; style = 48;
            x = "0.518 * safezoneW + safezoneX";
            y = "0.218 * safezoneH + safezoneY";
            w = "0.264 * safezoneW"; h = "0.292 * safezoneH";
            colorText[]       = {1,1,1,1};
            colorBackground[] = {0.06,0.08,0.11,0.97};
            text = "";
        };
        class PreviewName: OLI_RscText {
            idc = IDC_PREVIEW_NAME;
            text = "";
            x = "0.514 * safezoneW + safezoneX";
            y = "0.524 * safezoneH + safezoneY";
            w = "0.272 * safezoneW"; h = "0.036 * safezoneH";
            colorText[] = {0.90,0.95,0.88,1.0};
            colorBackground[] = {0,0,0,0};
            font = "PuristaBold"; sizeEx = 0.030; style = 0x02;
        };
        class PreviewDesc: OLI_RscStructuredText {
            idc = IDC_PREVIEW_DESC;
            x = "0.514 * safezoneW + safezoneX";
            y = "0.566 * safezoneH + safezoneY";
            w = "0.272 * safezoneW"; h = "0.094 * safezoneH";
            text = "";
            size = 0.024;
            class Attributes {
                font = "PuristaMedium"; color = "#D9E6DC"; align = "center"; shadow = 0;
            };
        };

        // ── PLACEHOLDER (shown when nothing selected) ─────────────────────────
        // Different control from PreviewName so we can hide/show independently.
        class PreviewPlaceholder: OLI_RscStructuredText {
            idc = IDC_PREVIEW_PLACEHOLDER;
            x = "0.514 * safezoneW + safezoneX";
            y = "0.340 * safezoneH + safezoneY";
            w = "0.272 * safezoneW"; h = "0.080 * safezoneH";
            text = "<t align='center' color='#556655' size='1.2'>Pick a category<br/>to see object previews</t>";
            size = 0.024;
        };

        // ── LEGACY STUBS ──────────────────────────────────────────────────────
        // IDC_CAT_BUILD is still referenced by show/hide toggles in the
        // function files. Kept as an invisible 1px stub to avoid scrubbing
        // those references. Do not remove without also editing showObjectList
        // and showCategories.
        class BtnBuild: OLI_RscButton {
            idc = IDC_CAT_BUILD;
            text = "";
            x = "0.0 * safezoneW"; y = "0.0 * safezoneH";
            w = "0.001 * safezoneW"; h = "0.001 * safezoneH";
            show = 0;
            colorText[]             = {0,0,0,0};
            colorBackground[]       = {0,0,0,0};
            colorBackgroundActive[] = {0,0,0,0};
            colorBorder[]           = {0,0,0,0};
            font = "PuristaBold"; sizeEx = 0.001;
            action = "";
        };


        // ── STATUS BAR ────────────────────────────────────────────────────────
        class StatusText: OLI_RscStructuredText {
            idc=IDC_STATUS_TEXT;
            x=DIALOG_X; y="0.682 * safezoneH + safezoneY";
            w=DIALOG_W; h="0.026 * safezoneH";
            colorText[] = {0.60,0.80,0.65,1};
            text="<t align='center'>Initialising...</t>";
            size=0.018;
        };

        class ControlsHint: OLI_RscText {
            idc=-1;
            text="Hover / Scroll list = preview  |  Click or Enter = start placing  |  In placement: LMB=Place  RMB=Menu  Scroll=Rotate  ALT+Scr=Height  Ctrl+Scr=Dist  Q/E=Yaw  G=Gnd  F=Snap  Backspace=Reset";
            x=DIALOG_X; y="0.711 * safezoneH + safezoneY";
            w=DIALOG_W; h="0.018 * safezoneH";
            colorText[] = {0.26,0.40,0.30,0.65};
            colorBackground[] = {0.04,0.06,0.08,0.50};
            font="PuristaMedium"; sizeEx=0.015; style=0x02;
        };

    };
};

// =============================================================================
//   PiP TOP-DOWN CAMERA OVERLAY
//   Displayed during build mode via fnc_buildCameraAssist.
//   Adjust x/y/w/h on PiPDisplay to reposition/resize.
// =============================================================================

class RscTitles {

    // ── TOP-DOWN PiP CAMERA OVERLAY ───────────────────────────────────────────
    // Rendered by fnc_buildCameraAssist into render target "OLI_engtools_rtt".
    // Positioned top-right. Adjust x/y/w/h on PiPDisplay to move/resize.
    class OLI_engtools_BuildPiP {
        idd      = -1;
        duration = 1e10;
        fadein   = 0;
        fadeout  = 0;
        class controls {
            class PiPBorder : OLI_RscText {
                idc = -1;
                x = "(0.768 * safezoneW) + safezoneX";
                y = "(0.016 * safezoneH) + safezoneY";
                w = "0.154 * safezoneW";
                h = "0.154 * safezoneH";
                colorBackground[] = {0.20, 0.55, 0.28, 0.70};
            };
            class PiPDisplay : OLI_RscPicture {
                idc   = 1234;
                x = "(0.770 * safezoneW) + safezoneX";
                y = "(0.018 * safezoneH) + safezoneY";
                w = "0.150 * safezoneW";
                h = "0.150 * safezoneH";
                text  = "#(argb,512,512,1)r2t(OLI_engtools_rtt,1.0)";
                style = 48;
                colorBackground[] = {0, 0, 0, 1};
            };
            class PiPLabel : OLI_RscText {
                idc = -1;
                x = "(0.771 * safezoneW) + safezoneX";
                y = "(0.019 * safezoneH) + safezoneY";
                w = "0.070 * safezoneW";
                h = "0.014 * safezoneH";
                text = "TOP VIEW";
                colorText[]       = {0.20, 0.85, 0.30, 1.0};
                colorBackground[] = {0.04, 0.07, 0.05, 0.85};
                font   = "PuristaBold";
                sizeEx = 0.013;
                style  = 0;
            };
        };
    };

    // ── BUILD MODE HUD ────────────────────────────────────────────────────────
    // HUD controls are created dynamically via ctrlCreate on display 46
    // in fnc_buildHUD.sqf — no RscTitles class needed.
};

#include "CfgWeapons.hpp"
