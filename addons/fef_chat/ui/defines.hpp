#define FEF_CHAT_IDD 88000

#define FEF_CHAT_BG 88001
#define FEF_CHAT_HEADER 88002
#define FEF_CHAT_TITLE 88004
#define FEF_CHAT_FOOTER 88006

#define FEF_CHAT_BTN1 88101
#define FEF_CHAT_BTN2 88102
#define FEF_CHAT_BTN3 88103
#define FEF_CHAT_BTN4 88104
#define FEF_CHAT_BTN5 88105
#define FEF_CHAT_BTN6 88106

#define FEF_CHAT_ACCENT1 88201
#define FEF_CHAT_ACCENT2 88202
#define FEF_CHAT_ACCENT3 88203
#define FEF_CHAT_ACCENT4 88204
#define FEF_CHAT_ACCENT5 88205
#define FEF_CHAT_ACCENT6 88206

#define FEF_UI_FONT "PuristaBold"

#define FEF_CLR_TEXT            {1,1,1,1}
#define FEF_CLR_PANEL           {0.09,0.10,0.11,0.92}
#define FEF_CLR_HEADER          {0.06,0.07,0.08,0.98}
#define FEF_CLR_BTN             {0.12,0.14,0.16,0.90}
#define FEF_CLR_BTN_SELECTED    {0.20,0.35,0.45,1}
#define FEF_CLR_BTN_DISABLED    {0.08,0.08,0.08,0.60}
#define FEF_CLR_FOOTER          {0.55,0.60,0.65,0.90}
#define FEF_CLR_MEDICAL         {0.70,0.13,0.13,0.96}
#define FEF_CLR_REINSERT        {0.20,0.45,0.65,0.96}
#define FEF_CLR_BACK            {0.20,0.20,0.20,0.96}

class FEF_RscText {
    access = 0;
    type = 0;
    idc = -1;
    style = 0;
    linespacing = 1;
    shadow = 0;
    font = FEF_UI_FONT;
    SizeEx = 0.032;
    colorBackground[] = {0,0,0,0};
    colorText[] = FEF_CLR_TEXT;
    text = "";
};

class FEF_RscPicture {
    access = 0;
    type = 0;
    idc = -1;
    style = 48;
    font = FEF_UI_FONT;
    sizeEx = 0;
    lineSpacing = 0;
    text = "";
    shadow = 0;
    colorBackground[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
};

class FEF_RscButton {
    access = 0;
    type = 1;
    style = 0;
    idc = -1;
    text = "";
    font = FEF_UI_FONT;
    sizeEx = 0.030;
    shadow = 0;
    borderSize = 0;

    colorText[] = FEF_CLR_TEXT;
    colorDisabled[] = {0.4,0.4,0.4,1};
    colorBackground[] = FEF_CLR_BTN;
    colorBackgroundDisabled[] = FEF_CLR_BTN_DISABLED;
    colorBackgroundActive[] = FEF_CLR_BTN_SELECTED;
    colorFocused[] = FEF_CLR_BTN_SELECTED;
    colorShadow[] = {0,0,0,0};
    colorBorder[] = {0,0,0,0};

    soundEnter[] = {"",0.1,1};
    soundPush[] = {"",0.1,1};
    soundClick[] = {"",0.1,1};
    soundEscape[] = {"",0.1,1};

    offsetX = 0;
    offsetY = 0;
    offsetPressedX = 0;
    offsetPressedY = 0;

    x = 0;
    y = 0;
    w = 0.2;
    h = 0.04;
};
