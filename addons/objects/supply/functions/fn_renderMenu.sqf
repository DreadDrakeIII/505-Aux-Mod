// OLI_SUPPLY - draws the resupply menu overlay (top-left panel), mirroring
// the visual style of the 505th comms wheel (addons/fef_chat) - same panel
// size, header/footer bars, accent-coloured rows and scroll-highlight
// behaviour, just anchored top-left instead of top-right.
//
// Called on open, on scroll/keyboard navigation, and every 0.25s from
// fn_titleLoop while the menu is open, so cooldown countdowns stay live
// without the menu having to be closed and reopened.
//
// Only the options switched ON in the addon options are listed - same rule
// the old per-crate scroll actions followed. Colours and names come straight
// from OLI_Supply_Actions (see fn_preInit.sqf), so this never needs editing
// when a crate type is added, renamed or recoloured there.
//
// Arguments: 0: reset selection to the top? <BOOL> (default false)

params [["_resetSelection", false]];

disableSerialization;

if !(missionNamespace getVariable ["OLI_Supply_UI_Open", false]) exitWith {};

private _console = missionNamespace getVariable ["OLI_Supply_UI_Console", objNull];
if (isNull _console) exitWith { [] call OLI_Supply_fnc_closeMenu; };

private _items = OLI_Supply_Actions select {
    missionNamespace getVariable [(_x select 8), true]
};
private _itemCount = count _items;

private _selectedIndex = missionNamespace getVariable ["OLI_Supply_UI_SelectedIndex", 0];
if (_resetSelection) then { _selectedIndex = 0; };

if (_itemCount <= 0) then {
    _selectedIndex = 0;
} else {
    if (_selectedIndex >= _itemCount) then { _selectedIndex = _itemCount - 1; };
    if (_selectedIndex < 0) then { _selectedIndex = 0; };
};
missionNamespace setVariable ["OLI_Supply_UI_SelectedIndex", _selectedIndex];

private _visibleCount = 6;
private _scrollOffset = missionNamespace getVariable ["OLI_Supply_UI_ScrollOffset", 0];

if (_resetSelection) then { _scrollOffset = 0; };
if (_selectedIndex < _scrollOffset) then { _scrollOffset = _selectedIndex; };
if (_selectedIndex >= (_scrollOffset + _visibleCount)) then {
    _scrollOffset = _selectedIndex - _visibleCount + 1;
};
missionNamespace setVariable ["OLI_Supply_UI_ScrollOffset", _scrollOffset];

// Delete old controls
private _oldCtrls = missionNamespace getVariable ["OLI_Supply_UI_Controls", []];
{ ctrlDelete _x; } forEach _oldCtrls;

private _display = findDisplay 46;
private _newCtrls = [];

// Layout - mirrors fef_chat's panel exactly (addons/fef_chat/Data/Functions/UI/fn_renderMenu.sqf),
// just anchored top-LEFT instead of top-right. fef_chat leaves a 0.010
// safezone margin on the right (1 - 0.810 - 0.180); this leaves the same
// margin on the left.
private _panelX  = 0.010;
private _panelY  = 0.155;
private _panelW  = 0.180;
private _headerH = 0.055;
private _btnH    = 0.048;
private _btnGap  = 0.003;
private _accentW = 0.006;
private _footerH = 0.034;

// "#RRGGBB" -> [r,g,b,1], each channel 0..1. Used against OLI_Supply_Actions'
// colour field and OLI_Supply_ColorCooldown, both already hex strings.
// Written with string select rather than parseNumber, which does not
// reliably parse "0x.."-style strings in SQF.
private _hexToRgb = {
    params ["_hex"];
    private _digits = "0123456789ABCDEF";
    private _byte = {
        params ["_pair"];
        private _hi = _digits find (toUpper (_pair select [0, 1]));
        private _lo = _digits find (toUpper (_pair select [1, 1]));
        ((_hi max 0) * 16 + (_lo max 0)) / 255
    };
    [
        [_hex select [1, 2]] call _byte,
        [_hex select [3, 2]] call _byte,
        [_hex select [5, 2]] call _byte,
        1
    ]
};

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
_title ctrlSetText "RESUPPLY";
_title ctrlSetFont "PuristaBold";
_title ctrlSetFontHeight 0.026;
_title ctrlCommit 0;
_newCtrls pushBack _title;

// Rows
for "_i" from 0 to (_visibleCount - 1) do {
    private _itemIdx = _i + _scrollOffset;
    private _btnY = _panelY + _headerH + (_btnGap * (_i + 1)) + (_btnH * _i);

    private _accent = _display ctrlCreate ["RscText", -1];
    _accent ctrlSetPosition [
        _panelX * safezoneW + safezoneX,
        _btnY * safezoneH + safezoneY,
        _accentW * safezoneW,
        _btnH * safezoneH
    ];

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
        (_items select _itemIdx) params ["_key", "_name", "_color", "", "", "", "_cdVar"];

        private _cdName = [_key] call OLI_Supply_fnc_cooldownVar;
        private _remaining = ((_console getVariable [_cdName, 0]) - CBA_missionTime) max 0;
        private _onCooldown = _remaining > 0;

        private _label = _name;
        private _rowColor = _color;
        if (_onCooldown) then {
            _label = format ["%1  [%2]", _name, [_remaining] call OLI_Supply_fnc_formatTime];
            _rowColor = OLI_Supply_ColorCooldown;
        };

        private _isSelected = _itemIdx isEqualTo _selectedIndex;
        private _btnColor = if (_isSelected) then {
            [0.20, 0.35, 0.45, 1.0]
        } else {
            [0.12, 0.14, 0.16, 0.90]
        };

        _btn ctrlSetBackgroundColor _btnColor;
        _btn ctrlSetText format ["  %1", _label];
        _accent ctrlSetBackgroundColor ([_rowColor] call _hexToRgb);
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
private _footerY = _panelY + _headerH + (_btnGap * (_visibleCount + 1)) + (_btnH * _visibleCount) + 0.003;
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

private _footerText = if (_itemCount <= 0) then {
    "NO OPTIONS ENABLED    ESC CLOSE"
} else {
    if (_itemCount > _visibleCount) then {
        format ["SCROLL SELECT    SPACE/ENTER CONFIRM    ESC CLOSE    %1/%2", _selectedIndex + 1, _itemCount]
    } else {
        "SCROLL SELECT    SPACE/ENTER CONFIRM    ESC CLOSE"
    };
};
_footer ctrlSetText _footerText;
_footer ctrlCommit 0;
_newCtrls pushBack _footer;

missionNamespace setVariable ["OLI_Supply_UI_Controls", _newCtrls];
