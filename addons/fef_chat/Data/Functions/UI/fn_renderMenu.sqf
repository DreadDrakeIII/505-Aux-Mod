params [
    ["_menuId", "main"],
    ["_resetSelection", false]
];

disableSerialization;

if !(missionNamespace getVariable ["FEF_UI_Open", false]) exitWith {};

call FEF_fnc_configureMenus;

private _menus = missionNamespace getVariable ["FEF_Menus", createHashMap];
private _items = _menus getOrDefault [_menuId, []];

missionNamespace setVariable ["FEF_UI_CurrentMenu", _menuId];
missionNamespace setVariable ["FEF_UI_CurrentItems", _items];

private _selectedIndex = missionNamespace getVariable ["FEF_UI_SelectedIndex", 0];
if (_resetSelection) then { _selectedIndex = 0; };

private _itemCount = count _items;
if (_itemCount <= 0) then {
    _selectedIndex = 0;
} else {
    if (_selectedIndex >= _itemCount) then { _selectedIndex = _itemCount - 1; };
    if (_selectedIndex < 0) then { _selectedIndex = 0; };
};

missionNamespace setVariable ["FEF_UI_SelectedIndex", _selectedIndex];

private _visibleCount = 6;
private _scrollOffset = missionNamespace getVariable ["FEF_UI_ScrollOffset", 0];

if (_resetSelection) then { _scrollOffset = 0; };
if (_selectedIndex < _scrollOffset) then { _scrollOffset = _selectedIndex; };
if (_selectedIndex >= (_scrollOffset + _visibleCount)) then {
    _scrollOffset = _selectedIndex - _visibleCount + 1;
};

missionNamespace setVariable ["FEF_UI_ScrollOffset", _scrollOffset];

// Delete old controls
private _oldCtrls = missionNamespace getVariable ["FEF_UI_Controls", []];
{ ctrlDelete _x; } forEach _oldCtrls;

private _display = findDisplay 46;
private _newCtrls = [];

// Layout
private _panelX  = 0.810;
private _panelY  = 0.155;
private _panelW  = 0.180;
private _headerH = 0.055;
private _btnH    = 0.048;
private _btnGap  = 0.003;
private _accentW = 0.006;
private _footerH = 0.034;

// Background
private _bg = _display ctrlCreate ["RscText", -1];
_bg ctrlSetPosition [
    _panelX * safezoneW + safezoneX,
    _panelY * safezoneH + safezoneY,
    _panelW * safezoneW,
    0.420 * safezoneH
];
_bg ctrlSetBackgroundColor [0.09, 0.10, 0.11, 0.92];
_bg ctrlSetText "";
_bg ctrlCommit 0;
_newCtrls pushBack _bg;

// Header
private _header = _display ctrlCreate ["RscText", -1];
_header ctrlSetPosition [
    _panelX * safezoneW + safezoneX,
    _panelY * safezoneH + safezoneY,
    _panelW * safezoneW,
    _headerH * safezoneH
];
_header ctrlSetBackgroundColor [0.06, 0.07, 0.08, 0.98];
_header ctrlSetText "";
_header ctrlCommit 0;
_newCtrls pushBack _header;

// Title
private _title = _display ctrlCreate ["RscText", -1];
_title ctrlSetPosition [
    _panelX * safezoneW + safezoneX,
    (_panelY + 0.010) * safezoneH + safezoneY,
    _panelW * safezoneW,
    0.030 * safezoneH
];
_title ctrlSetBackgroundColor [0, 0, 0, 0];
_title ctrlSetTextColor [1, 1, 1, 1];
_title ctrlSetText "COMMUNICATION";
_title ctrlSetFont "PuristaBold";
_title ctrlSetFontHeight 0.026;
_title ctrlCommit 0;
_newCtrls pushBack _title;

// Accent color logic
private _getAccentColor = {
    params ["_type", "_label"];
    private _lbl = toLower _label;
    switch (true) do {
        case (toLower _type == "downalert"):                          { [0.70, 0.13, 0.13, 1.0] };
        case (_lbl find "need medic" >= 0):                          { [0.70, 0.13, 0.13, 1.0] };
        case (_lbl find "friendly down" >= 0):                       { [0.70, 0.13, 0.13, 1.0] };
        case (_lbl find "medic" >= 0 && _lbl find "check" < 0):     { [0.70, 0.13, 0.13, 1.0] };
        case (_lbl find "ammo" >= 0):                                { [0.75, 0.45, 0.05, 1.0] };
        case (_lbl find "contact" >= 0):                             { [0.70, 0.60, 0.05, 1.0] };
        case (_lbl find "check" >= 0):                               { [0.10, 0.55, 0.25, 1.0] };
        case (_lbl find "squad" >= 0):                               { [0.20, 0.50, 0.70, 1.0] };
        case (_lbl find "fireteam" >= 0):                            { [0.30, 0.60, 0.55, 1.0] };
        case (_lbl find "medevac" >= 0):                             { [0.80, 0.10, 0.10, 1.0] };
        case (_lbl find "lz" >= 0):                                  { [0.10, 0.50, 0.80, 1.0] };
        case (toLower _type == "reinsert"):                          { [0.20, 0.45, 0.65, 1.0] };
        case (toLower _type == "back"):                              { [0.20, 0.20, 0.20, 1.0] };
        case (toLower _type == "submenu"):                           { [0.15, 0.40, 0.50, 1.0] };
        default                                                      { [0.25, 0.45, 0.30, 1.0] };
    };
};

// Buttons + accents
for "_i" from 0 to (_visibleCount - 1) do {
    private _itemIdx = _i + _scrollOffset;
    private _btnY = _panelY + _headerH + (_btnGap * (_i + 1)) + (_btnH * _i);

    // Accent bar
    private _accent = _display ctrlCreate ["RscText", -1];
    _accent ctrlSetPosition [
        _panelX * safezoneW + safezoneX,
        _btnY * safezoneH + safezoneY,
        _accentW * safezoneW,
        _btnH * safezoneH
    ];

    // Button text area
    private _btn = _display ctrlCreate ["RscText", -1];
    _btn ctrlSetPosition [
        (_panelX + _accentW) * safezoneW + safezoneX,
        _btnY * safezoneH + safezoneY,
        (_panelW - _accentW) * safezoneW,
        _btnH * safezoneH
    ];
    _btn ctrlSetFont "PuristaBold";
    _btn ctrlSetFontHeight 0.030;
    _btn ctrlSetTextColor [1, 1, 1, 1];

    if (_itemIdx < _itemCount) then {
        private _entry = _items select _itemIdx;
        _entry params ["_label", "_type", "_payload"];

        private _isSelected = _itemIdx isEqualTo _selectedIndex;
        private _isSubmenu  = toLower _type == "submenu";

        private _btnColor = if (_isSelected) then {
            [0.20, 0.35, 0.45, 1.0]
        } else {
            [0.12, 0.14, 0.16, 0.90]
        };

        _btn ctrlSetBackgroundColor _btnColor;
        _btn ctrlSetText format ["  %1%2", _label, if (_isSubmenu) then { "  >" } else { "" }];
        _accent ctrlSetBackgroundColor ([_type, _label] call _getAccentColor);
    } else {
        _btn ctrlSetBackgroundColor [0, 0, 0, 0];
        _btn ctrlSetText "";
        _accent ctrlSetBackgroundColor [0, 0, 0, 0];
    };

    _btn ctrlCommit 0;
    _accent ctrlCommit 0;
    _newCtrls pushBack _accent;
    _newCtrls pushBack _btn;
};

// Footer
private _footerY = _panelY + _headerH + (_btnGap * 7) + (_btnH * 6) + 0.003;
private _footer = _display ctrlCreate ["RscText", -1];
_footer ctrlSetPosition [
    _panelX * safezoneW + safezoneX,
    _footerY * safezoneH + safezoneY,
    _panelW * safezoneW,
    _footerH * safezoneH
];
_footer ctrlSetBackgroundColor [0.06, 0.07, 0.08, 0.98];
_footer ctrlSetTextColor [0.55, 0.60, 0.65, 0.90];
_footer ctrlSetFont "PuristaBold";
_footer ctrlSetFontHeight 0.016;

private _footerText = if (_itemCount > _visibleCount) then {
    format ["SCROLL SELECT    SPACE/ENTER CONFIRM    ESC CLOSE    %1/%2", _selectedIndex + 1, _itemCount]
} else {
    if (_menuId != "main") then {
        "SCROLL SELECT    SPACE/ENTER CONFIRM    ESC BACK"
    } else {
        "SCROLL SELECT    SPACE/ENTER CONFIRM    ESC CLOSE"
    };
};

_footer ctrlSetText _footerText;
_footer ctrlCommit 0;
_newCtrls pushBack _footer;

missionNamespace setVariable ["FEF_UI_Controls", _newCtrls];
