class FEF_ChatDisplay {
    idd = FEF_CHAT_IDD;
    movingEnable = 0;
    enableSimulation = 1;
    enableDisplay = 1;
    mouseControl = 0;
    onUnload = "";

    class controlsBackground {
        class Background: FEF_RscText {
            idc = FEF_CHAT_BG;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.155 * safezoneH + safezoneY";
            w = "0.180 * safezoneW";
            h = "0.420 * safezoneH";
            colorBackground[] = FEF_CLR_PANEL;
        };

        class Header: FEF_RscText {
            idc = FEF_CHAT_HEADER;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.155 * safezoneH + safezoneY";
            w = "0.180 * safezoneW";
            h = "0.055 * safezoneH";
            colorBackground[] = FEF_CLR_HEADER;
        };

        class Accent1: FEF_RscText {
            idc = FEF_CHAT_ACCENT1;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.222 * safezoneH + safezoneY";
            w = "0.006 * safezoneW";
            h = "0.048 * safezoneH";
            colorBackground[] = {1,1,1,0};
        };
        class Accent2: FEF_RscText {
            idc = FEF_CHAT_ACCENT2;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.273 * safezoneH + safezoneY";
            w = "0.006 * safezoneW";
            h = "0.048 * safezoneH";
            colorBackground[] = {1,1,1,0};
        };
        class Accent3: FEF_RscText {
            idc = FEF_CHAT_ACCENT3;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.324 * safezoneH + safezoneY";
            w = "0.006 * safezoneW";
            h = "0.048 * safezoneH";
            colorBackground[] = {1,1,1,0};
        };
        class Accent4: FEF_RscText {
            idc = FEF_CHAT_ACCENT4;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.375 * safezoneH + safezoneY";
            w = "0.006 * safezoneW";
            h = "0.048 * safezoneH";
            colorBackground[] = {1,1,1,0};
        };
        class Accent5: FEF_RscText {
            idc = FEF_CHAT_ACCENT5;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.426 * safezoneH + safezoneY";
            w = "0.006 * safezoneW";
            h = "0.048 * safezoneH";
            colorBackground[] = {1,1,1,0};
        };
        class Accent6: FEF_RscText {
            idc = FEF_CHAT_ACCENT6;
            x = "0.810 * safezoneW + safezoneX";
            y = "0.477 * safezoneH + safezoneY";
            w = "0.006 * safezoneW";
            h = "0.048 * safezoneH";
            colorBackground[] = {1,1,1,0};
        };
    };

    class controls {
        class Title: FEF_RscText {
            idc = FEF_CHAT_TITLE;
            text = "COMMUNICATION";
            x = "0.810 * safezoneW + safezoneX";
            y = "0.162 * safezoneH + safezoneY";
            w = "0.180 * safezoneW";
            h = "0.030 * safezoneH";
            style = 2;
            sizeEx = 0.026;
            font = FEF_UI_FONT;
            colorText[] = FEF_CLR_TEXT;
        };

        // No onButtonClick — scroll + Space/Enter/Numpad Enter only
        // Removes mouse cursor appearing when UI opens
        class Button1: FEF_RscButton {
            idc = FEF_CHAT_BTN1;
            x = "0.816 * safezoneW + safezoneX";
            y = "0.222 * safezoneH + safezoneY";
            w = "0.174 * safezoneW";
            h = "0.048 * safezoneH";
            style = 0;
        };
        class Button2: FEF_RscButton {
            idc = FEF_CHAT_BTN2;
            x = "0.816 * safezoneW + safezoneX";
            y = "0.273 * safezoneH + safezoneY";
            w = "0.174 * safezoneW";
            h = "0.048 * safezoneH";
            style = 0;
        };
        class Button3: FEF_RscButton {
            idc = FEF_CHAT_BTN3;
            x = "0.816 * safezoneW + safezoneX";
            y = "0.324 * safezoneH + safezoneY";
            w = "0.174 * safezoneW";
            h = "0.048 * safezoneH";
            style = 0;
        };
        class Button4: FEF_RscButton {
            idc = FEF_CHAT_BTN4;
            x = "0.816 * safezoneW + safezoneX";
            y = "0.375 * safezoneH + safezoneY";
            w = "0.174 * safezoneW";
            h = "0.048 * safezoneH";
            style = 0;
        };
        class Button5: FEF_RscButton {
            idc = FEF_CHAT_BTN5;
            x = "0.816 * safezoneW + safezoneX";
            y = "0.426 * safezoneH + safezoneY";
            w = "0.174 * safezoneW";
            h = "0.048 * safezoneH";
            style = 0;
        };
        class Button6: FEF_RscButton {
            idc = FEF_CHAT_BTN6;
            x = "0.816 * safezoneW + safezoneX";
            y = "0.477 * safezoneH + safezoneY";
            w = "0.174 * safezoneW";
            h = "0.048 * safezoneH";
            style = 0;
        };

        class Footer: FEF_RscText {
            idc = FEF_CHAT_FOOTER;
            text = "SCROLL SELECT    SPACE/ENTER CONFIRM    ESC CLOSE";
            x = "0.810 * safezoneW + safezoneX";
            y = "0.528 * safezoneH + safezoneY";
            w = "0.180 * safezoneW";
            h = "0.034 * safezoneH";
            sizeEx = 0.016;
            style = 2;
            font = FEF_UI_FONT;
            colorText[] = FEF_CLR_FOOTER;
            colorBackground[] = FEF_CLR_HEADER;
        };
    };
};
