class CfgPatches {
    class 505th_Brandings {
        units[] = {};
        weapons[] = {};
        requiredAddons[] = {"1st_MEU_patch_main_loadingScreens"};
    };
};

class RscPicture {};
class RscStandardDisplay {};
class RscText {};
class RscActiveText {};
class RscActivePicture: RscActiveText {};
class RscButton {};

class RscDisplayLoading {
    class Variants {
        class LoadingOne {
            idd = 250;
            class controls {
                class LoadingPic: RscPicture {
                    idc = 1;
                    x = "SafeZoneX";
                    y = "SafeZoneY";
                    h = "SafeZoneH";
                    w = "SafeZoneW";
                    text = "\BLU\OLI\addons\brandings\textures\505th_Loading_menu.paa";
                };
            };
        };
    };
};

class RscDisplayStart: RscStandardDisplay {
    class controls {
        class LoadingPic: RscPicture {
            idc = 1;
            x = "SafeZoneX";
            y = "SafeZoneY";
            h = "SafeZoneH";
            w = "SafeZoneW";
            text = "\BLU\OLI\addons\brandings\textures\505th_Loading_menu.paa";
        };
    };
};

class RscDisplayMain: RscStandardDisplay {
    enableDisplay = 0;
    delete Spotlight;
    class Controls {
        delete Spotlight1;
        delete Spotlight2;
        delete Spotlight3;
        delete BackgroundSpotlightRight;
        delete BackgroundSpotlightLeft;
        delete BackgroundSpotlight;

        class Logo: RscPicture {
            idc = -1;
            x = 0.375;    // centered (0.5 - 0.25/2)
            y = -0.375;     // near top, below menu bar
            w = 0.25;
            h = 0.35;
            text = "\BLU\OLI\addons\brandings\textures\505th_logo.paa";
        };

        class LogoButton: RscButton {
            idc = -1;
            x = 0.375;
            y = -0.375;
            w = 0.25;
            h = 0.35;
            text = "";
            colorBackground[] = {0, 0, 0, 0};
            colorBackgroundActive[] = {1, 1, 1, 0.1};
            colorBorder[] = {0, 0, 0, 0};
            tooltip = "Join 505th Server";
            action = "connectToServer ['217.217.25.53', 2472, '505th'];";
        };
    };
    class controlsBackground {
        class LoadingPic: RscPicture {
            idc = 1;
            x = "SafeZoneX";
            y = "SafeZoneY";
            h = "SafeZoneH";
            w = "SafeZoneW";
            text = "\BLU\OLI\addons\brandings\textures\505th_mainmenu.paa";
        };
    };
};
