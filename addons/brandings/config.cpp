class CfgPatches {
    class 505th_Brandings {
        units[] = {};
        weapons[] = {};
        requiredAddons[] = {"1st_MEU_patch_main_loadingScreens", "cba_main", "OLI_music"};
    };
};

class Extended_DisplayLoad_EventHandlers {
    class RscDisplayMain {
        OLI_Brandings_MenuMusic = "diag_log format ['OLI_Brandings: DIAG hook fired, display0=%1', findDisplay 0]; uiNamespace setVariable ['OLI_Brandings_loadTime', diag_tickTime]; uiNamespace setVariable ['OLI_Brandings_done', false]; (_this select 0) displayAddEventHandler ['MouseMoving', {if (diag_tickTime - (uiNamespace getVariable ['OLI_Brandings_loadTime', diag_tickTime]) > 8 && {!(uiNamespace getVariable ['OLI_Brandings_done', false])}) then {uiNamespace setVariable ['OLI_Brandings_done', true]; diag_log format ['OLI_Brandings: DIAG mouse trigger, display0=%1', findDisplay 0]; private _oldStart = uiNamespace getVariable ['OLI_Brandings_startEH', -1]; if (_oldStart >= 0) then {removeMusicEventHandler ['MusicStart', _oldStart]}; private _oldStop = uiNamespace getVariable ['OLI_Brandings_stopEH', -1]; if (_oldStop >= 0) then {removeMusicEventHandler ['MusicStop', _oldStop]}; uiNamespace setVariable ['OLI_Brandings_startEH', addMusicEventHandler ['MusicStart', {params ['_music']; diag_log format ['OLI_Brandings: DIAG MusicStart %1 display0=%2', _music, findDisplay 0]; private _d = findDisplay 0; if (!isNull _d) then {private _c = uiNamespace getVariable ['OLI_Brandings_dbgCtrl', controlNull]; if (isNull _c) then {_c = _d ctrlCreate ['RscText', -1]; _c ctrlSetPosition [safeZoneX + 0.02, safeZoneY + 0.02, 1.5, 0.05]; uiNamespace setVariable ['OLI_Brandings_dbgCtrl', _c]}; _c ctrlSetText format ['MUSIC STARTED: %1', _music]; _c ctrlCommit 0}; if (_music != 'OLI_Music_Journey_To_Rome' && {!isNull findDisplay 0}) then {[] spawn {uiSleep 0.1; diag_log 'OLI_Brandings: DIAG override firing'; if (!isNull findDisplay 0) then {playMusic 'OLI_Music_Journey_To_Rome'}}}}]]; uiNamespace setVariable ['OLI_Brandings_stopEH', addMusicEventHandler ['MusicStop', {params ['_music']; diag_log format ['OLI_Brandings: DIAG MusicStop %1 display0=%2', _music, findDisplay 0]; if (_music == 'OLI_Music_Journey_To_Rome' && {!isNull findDisplay 0}) then {[_music] spawn {uiSleep 0.1; if (!isNull findDisplay 0) then {playMusic (_this select 0)}}}}]]; diag_log 'OLI_Brandings: DIAG EHs registered'; playMusic 'OLI_Music_Journey_To_Rome'}}]; playMusic 'OLI_Music_Journey_To_Rome'; [] spawn {uiSleep 0.5; diag_log 'OLI_Brandings: DIAG spawn survived'};";
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
            action = "connectToServer ['217.217.25.5', 2372, '505th'];";
        };
    };
    class controlsBackground {
        class LoadingPic: RscPicture {
            idc = 1;
            x = "SafeZoneX";
            y = "SafeZoneY";
            h = "SafeZoneH";
            w = "SafeZoneW";
            text = "\BLU\OLI\addons\brandings\textures\505th_mainmenu2.paa";
        };
    };
};
