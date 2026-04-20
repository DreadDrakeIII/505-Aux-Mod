#define COMPONENT engtools
#define COMPONENT_BEAUTIFIED Engineering Tools

#include "\BLU\OLI\addons\main\script_mod.hpp"
#include "\BLU\OLI\addons\main\script_macros.hpp"

// Dialog IDD
#define IDD_ENGINEER_DIALOG 85050

// IDCs – options
#define IDC_PREVIEW_IMAGE       4001
#define IDC_PREVIEW_NAME        4002
#define IDC_PREVIEW_DESC        4003
#define IDC_STATUS_TEXT         3001
#define IDC_MODE_BUILD          3100
#define IDC_MODE_DEMOLISH       3101
#define IDC_TERRAIN_TOGGLE      3102
#define IDC_HEIGHT_DISPLAY      3103
#define IDC_HEIGHT_UP           3104
#define IDC_HEIGHT_DOWN         3105
#define IDC_HEIGHT_RESET        3106
#define IDC_SNAP_TOGGLE         3107
#define IDC_RESOURCE_DISPLAY    3108

// IDCs — build HUD controls (ctrlCreate on display 46)
#define IDC_BUILD_HUD_BG        3199
#define IDC_BUILD_HUD_ACCENT    3200
#define IDC_BUILD_HUD_STATUS    3201
#define IDC_BUILD_HUD_HINT      3202

// Image paths
#define PATH_LOGO_505  "\BLU\OLI\addons\engtools\data\505TH_Logo.paa"
#define PATH_LOGO_ENG  "\BLU\OLI\addons\engtools\data\eng_logo.paa"

// Resource defaults
#define DEFAULT_RESOURCE_COST 20
#define DEFAULT_BUILD_TIME 5
#define DEFAULT_DEMOLISH_TIME 5

// ── Layout ────────────────────────────────────────────────────────────────────
#define DIALOG_X  "0.07  * safezoneW + safezoneX"
#define DIALOG_Y  "0.04  * safezoneH + safezoneY"
#define DIALOG_W  "0.86  * safezoneW"
#define DIALOG_H  "0.74  * safezoneH"

// 3 equal columns
#define COL1_X  "0.078 * safezoneW + safezoneX"
#define COL2_X  "0.366 * safezoneW + safezoneX"
#define COL3_X  "0.654 * safezoneW + safezoneX"
#define BTN_W   "0.280 * safezoneW"
#define BTN_H   "0.036 * safezoneH"

// Button rows – headers at 0.358, ROW1 starts at 0.384, step 0.039
#define ROW1_Y  "0.384 * safezoneH + safezoneY"
#define ROW2_Y  "0.423 * safezoneH + safezoneY"
#define ROW3_Y  "0.462 * safezoneH + safezoneY"
#define ROW4_Y  "0.501 * safezoneH + safezoneY"
#define ROW5_Y  "0.540 * safezoneH + safezoneY"
#define ROW6_Y  "0.579 * safezoneH + safezoneY"
#define ROW7_Y  "0.618 * safezoneH + safezoneY"
