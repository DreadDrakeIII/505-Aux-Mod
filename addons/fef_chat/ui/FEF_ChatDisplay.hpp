class FEF_ChatDisplay {
    idd = FEF_CHAT_IDD;
    movingEnable = 0;
    enableSimulation = 1;
    enableDisplay = 1;

    class controlsBackground {
        class Background: FEF_RscText {
            idc = FEF_CHAT_BG;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.155 * safezoneH + safezoneY";
            w = "0.180 * safezoneW";
            h = "0.620 * safezoneH";
            colorBackground[] = FEF_CLR_PANEL;
        };

        class Header: FEF_RscText {
            idc = FEF_CHAT_HEADER;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.155 * safezoneH + safezoneY";
            w = "0.180 * safezoneW";
            h = "0.085 * safezoneH";
            colorBackground[] = FEF_CLR_HEADER;
        };

        class Logo: FEF_RscPicture {
            idc = FEF_CHAT_LOGO;
            text = "BLU\OLI\addons\fef_chat\ui\assets\505TH_Logo.paa";
            style = 48;
            x = "0.814 * safezoneW + safezoneX";
            y = "0.160 * safezoneH + safezoneY";
            w = "0.050 * safezoneH";
            h = "0.050 * safezoneH";
        };

        class Accent1: FEF_RscText {
            idc = FEF_CHAT_ACCENT1;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.255 * safezoneH + safezoneY";
            w = "0.006 * safezoneW";
            h = "0.048 * safezoneH";
            colorBackground[] = {1,1,1,0};
        };
        class Accent2: FEF_RscText {
            idc = FEF_CHAT_ACCENT2;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.306 * safezoneH + safezoneY";
            w = "0.006 * safezoneW";
            h = "0.048 * safezoneH";
            colorBackground[] = {1,1,1,0};
        };
        class Accent3: FEF_RscText {
            idc = FEF_CHAT_ACCENT3;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.357 * safezoneH + safezoneY";
            w = "0.006 * safezoneW";
            h = "0.048 * safezoneH";
            colorBackground[] = {1,1,1,0};
        };
        class Accent4: FEF_RscText {
            idc = FEF_CHAT_ACCENT4;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.408 * safezoneH + safezoneY";
            w = "0.006 * safezoneW";
            h = "0.048 * safezoneH";
            colorBackground[] = {1,1,1,0};
        };
        class Accent5: FEF_RscText {
            idc = FEF_CHAT_ACCENT5;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.459 * safezoneH + safezoneY";
            w = "0.006 * safezoneW";
            h = "0.048 * safezoneH";
            colorBackground[] = {1,1,1,0};
        };
        class Accent6: FEF_RscText {
            idc = FEF_CHAT_ACCENT6;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.510 * safezoneH + safezoneY";
            w = "0.006 * safezoneW";
            h = "0.048 * safezoneH";
            colorBackground[] = {1,1,1,0};
        };
    };

    class controls {
        class Title: FEF_RscText {
            idc = FEF_CHAT_TITLE;
            text = "505TH";
            x = "0.872 * safezoneW + safezoneX";
            y = "0.162 * safezoneH + safezoneY";
            w = "0.110 * safezoneW";
            h = "0.030 * safezoneH";
            style = 0;
            sizeEx = 0.032;
            font = FEF_UI_FONT;
            colorText[] = FEF_CLR_TEXT;
        };

        class Subtitle: FEF_RscText {
            idc = FEF_CHAT_SUBTITLE;
            text = "COMMS";
            x = "0.810 * safezoneW + safezoneX";
            y = "0.194 * safezoneH + safezoneY";
            w = "0.180 * safezoneW";
            h = "0.022 * safezoneH";
            style = 2;
            sizeEx = 0.024;
            font = FEF_UI_FONT;
            colorText[] = FEF_CLR_SUBTITLE;
        };

        class Button1: FEF_RscButton {
            idc = FEF_CHAT_BTN1;
            onButtonClick = "[0] call FEF_fnc_onButtonClick;";
            x = "0.816 * safezoneW + safezoneX";
            y = "0.255 * safezoneH + safezoneY";
            w = "0.174 * safezoneW";
            h = "0.048 * safezoneH";
            style = 0;
        };
        class Button2: FEF_RscButton {
            idc = FEF_CHAT_BTN2;
            onButtonClick = "[1] call FEF_fnc_onButtonClick;";
            x = "0.816 * safezoneW + safezoneX";
            y = "0.306 * safezoneH + safezoneY";
            w = "0.174 * safezoneW";
            h = "0.048 * safezoneH";
            style = 0;
        };
        class Button3: FEF_RscButton {
            idc = FEF_CHAT_BTN3;
            onButtonClick = "[2] call FEF_fnc_onButtonClick;";
            x = "0.816 * safezoneW + safezoneX";
            y = "0.357 * safezoneH + safezoneY";
            w = "0.174 * safezoneW";
            h = "0.048 * safezoneH";
            style = 0;
        };
        class Button4: FEF_RscButton {
            idc = FEF_CHAT_BTN4;
            onButtonClick = "[3] call FEF_fnc_onButtonClick;";
            x = "0.816 * safezoneW + safezoneX";
            y = "0.408 * safezoneH + safezoneY";
            w = "0.174 * safezoneW";
            h = "0.048 * safezoneH";
            style = 0;
        };
        class Button5: FEF_RscButton {
            idc = FEF_CHAT_BTN5;
            onButtonClick = "[4] call FEF_fnc_onButtonClick;";
            x = "0.816 * safezoneW + safezoneX";
            y = "0.459 * safezoneH + safezoneY";
            w = "0.174 * safezoneW";
            h = "0.048 * safezoneH";
            style = 0;
        };
        class Button6: FEF_RscButton {
            idc = FEF_CHAT_BTN6;
            onButtonClick = "[5] call FEF_fnc_onButtonClick;";
            x = "0.816 * safezoneW + safezoneX";
            y = "0.510 * safezoneH + safezoneY";
            w = "0.174 * safezoneW";
            h = "0.048 * safezoneH";
            style = 0;
        };

        class Footer: FEF_RscText {
            idc = FEF_CHAT_FOOTER;
            text = "SCROLL  SELECT    SPACE/ENTER  CONFIRM    ESC  CLOSE";
            x = "0.810 * safezoneW + safezoneX";
            y = "0.700 * safezoneH + safezoneY";
            w = "0.180 * safezoneW";
            h = "0.040 * safezoneH";
            sizeEx = 0.016;
            style = 2;
            font = FEF_UI_FONT;
            colorText[] = FEF_CLR_FOOTER;
            colorBackground[] = FEF_CLR_HEADER;
        };
    };
};
