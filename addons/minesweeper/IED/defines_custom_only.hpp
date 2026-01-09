// Custom UI classes for minesweeper - inherit from Arma 3 base classes

class RscSweeperText: RscText
{
    colorBackground[] = {0.3,0.3,0.3,0.8};
    colorText[] = {0.9,0.9,0.9,.95};
    sizeEx = 0.0600;
    style = ST_CENTER;
};

class RscMineTile: RscActiveText
{
    type = CT_ACTIVETEXT;
    style = 48;
    color[] = {1.0,1.0,1.0,.9};
    colorActive[] = {0.9,0.9,0.9,.9};
    colorText[] = {1.0,1.0,1.0,1.0};
    colorDisabled[] = {0.6,0.1,0.3,0};
    colorBackground[] = {0.94,0.94,0.94,1.0};
    colorBackgroundDisabled[] = {0,0,0,0};
    colorBackgroundActive[] = {0.15,0.35,0.55,0.7};
    colorFocused[] = {0.87,0.87,0.87,1.0};
    colorShadow[] = {0.023529,0,0.0313725,0};
    colorBorder[] = {0.023529,0,0.0313725,0};
    soundEnter[] = {"\ca\ui\data\sound\onover",0.09,1};
    soundPush[] = {"\ca\ui\data\sound\new1",0,0};
    soundClick[] = {"\ca\ui\data\sound\onclick",0.07,1};
    soundEscape[] = {"\ca\ui\data\sound\onescape",0.09,1};
    default = 0;
    text = "";
    size = 0.03921;
    sizeEx = 0.03921;
    font = "PuristaLight";
    shadow = 0;
    x = 0;
    y = 0;
    w = 0.095589;
    h = 0.039216;
    period = 1.2;
    periodFocus = 1.2;
    periodOver = 1.2;
};
