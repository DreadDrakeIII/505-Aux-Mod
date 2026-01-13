// Minesweeper GUI Definition
// Tiles are created dynamically by fn_initMinefield.sqf

#include "defines.hpp"

class MSIED_Minesweeper {
    idd = 55500;
    movingEnable = 1;
    onLoad = "uiNamespace setVariable ['MSIED_Minesweeper', _this select 0];";
    
    class Controls {
        // Background - position/size set dynamically
        class Background: MSIED_RscBackground {
            idc = 9999;
            x = "0.3 * safezoneW + safezoneX";
            y = "0.2 * safezoneH + safezoneY";
            w = "0.4 * safezoneW";
            h = "0.6 * safezoneH";
            colorBackground[] = {0.2, 0.2, 0.2, 0.9};
        };
        
        // Frame - position/size set dynamically
        class Frame: MSIED_RscFrame {
            idc = 9998;
            x = "0.3 * safezoneW + safezoneX";
            y = "0.2 * safezoneH + safezoneY";
            w = "0.4 * safezoneW";
            h = "0.6 * safezoneH";
        };
        
        // Timer display - position set dynamically
        class Timer: MSIED_RscSweeperText {
            idc = 1000;
            text = "999";
            x = "0.35 * safezoneW + safezoneX";
            y = "0.22 * safezoneH + safezoneY";
            w = "0.06 * safezoneW";
            h = "0.05 * safezoneH";
        };
        
        // Timer icon - position set dynamically
        class TimerIcon: MSIED_RscPicture {
            idc = 1002;
            text = "\BLU\OLI\addons\minesweeper\img\clock.paa";
            x = "0.41 * safezoneW + safezoneX";
            y = "0.22 * safezoneH + safezoneY";
            w = "0.04 * safezoneW";
            h = "0.05 * safezoneH";
        };
        
        // Mine counter - position set dynamically
        class MineCount: MSIED_RscSweeperText {
            idc = 1001;
            text = "999";
            x = "0.55 * safezoneW + safezoneX";
            y = "0.22 * safezoneH + safezoneY";
            w = "0.06 * safezoneW";
            h = "0.05 * safezoneH";
        };
        
        // Mine icon - position set dynamically
        class MineIcon: MSIED_RscPicture {
            idc = 1003;
            text = "\BLU\OLI\addons\minesweeper\img\mine.paa";
            x = "0.61 * safezoneW + safezoneX";
            y = "0.22 * safezoneH + safezoneY";
            w = "0.04 * safezoneW";
            h = "0.05 * safezoneH";
        };
    };
};
