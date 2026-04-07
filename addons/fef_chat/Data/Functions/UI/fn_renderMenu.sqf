params [
    ["_menuId", "main"],
    ["_resetSelection", false]
];

disableSerialization;

private _display = findDisplay 88000;
if (isNull _display) exitWith {};

call FEF_fnc_configureMenus;

private _menus = missionNamespace getVariable ["FEF_Menus", createHashMap];
private _items = _menus getOrDefault [_menuId, []];

missionNamespace setVariable ["FEF_UI_CurrentMenu", _menuId];
missionNamespace setVariable ["FEF_UI_CurrentItems", _items];

private _selectedIndex = missionNamespace getVariable ["FEF_UI_SelectedIndex", 0];
if (_resetSelection) then {
    _selectedIndex = 0;
};

private _itemCount = count _items;
if (_itemCount <= 0) then {
    _selectedIndex = 0;
} else {
    if (_selectedIndex >= _itemCount) then { _selectedIndex = _itemCount - 1; };
    if (_selectedIndex < 0) then { _selectedIndex = 0; };
};

missionNamespace setVariable ["FEF_UI_SelectedIndex", _selectedIndex];

// Subtitle
private _subtitleCtrl = _display displayCtrl 88005;
private _subtitleText = switch (_menuId) do {
    case "main":            { "COMMS" };
    case "main_more":       { "MORE PAGE" };
    case "contact":         { "CONTACT" };
    case "medical_status":  { "MEDICAL STATUS" };
    case "reinsert":        { "REINSERT" };
    case "squad_comms":     { "SQUAD COMMS" };
    case "fireteam_comms":  { "FIRETEAM COMMS" };
    case "custom_1":        { "CUSTOM PAGE 1" };
    case "custom_2":        { "CUSTOM PAGE 2" };
    case "custom_3":        { "CUSTOM PAGE 3" };
    default                 { toUpper _menuId };
};
_subtitleCtrl ctrlSetText _subtitleText;

private _buttonIdcs = [88101, 88102, 88103, 88104, 88105, 88106];
private _accentIdcs = [88201, 88202, 88203, 88204, 88205, 88206];
private _visibleCount = 6;

// Sliding window — keep selected item visible
private _scrollOffset = missionNamespace getVariable ["FEF_UI_ScrollOffset", 0];

if (_resetSelection) then {
    _scrollOffset = 0;
};

// Adjust offset to keep selection in view
if (_selectedIndex < _scrollOffset) then {
    _scrollOffset = _selectedIndex;
};
if (_selectedIndex >= (_scrollOffset + _visibleCount)) then {
    _scrollOffset = _selectedIndex - _visibleCount + 1;
};

missionNamespace setVariable ["FEF_UI_ScrollOffset", _scrollOffset];

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
        case (toLower _type == "reinsert"):                          { [0.20, 0.45, 0.65, 1.0] };
        case (toLower _type == "back"):                              { [0.20, 0.20, 0.20, 1.0] };
        case (toLower _type == "submenu"):                           { [0.15, 0.40, 0.50, 1.0] };
        default                                                      { [0.25, 0.45, 0.30, 1.0] };
    };
};

private _getBtnColor = {
    params ["_isSelected"];
    if (_isSelected) exitWith { [0.20, 0.35, 0.45, 1.0] };
    [0.12, 0.14, 0.16, 0.90]
};

// Update footer to show scroll position when list is longer than 6
private _footerCtrl = _display displayCtrl 88006;
if (_itemCount > _visibleCount) then {
    _footerCtrl ctrlSetText format [
        "SCROLL SELECT    SPACE/ENTER CONFIRM    ESC CLOSE    %1/%2",
        _selectedIndex + 1,
        _itemCount
    ];
} else {
    _footerCtrl ctrlSetText "SCROLL SELECT    SPACE/ENTER CONFIRM    ESC CLOSE";
};

{
    private _idx        = _x;
    private _itemIdx    = _idx + _scrollOffset;
    private _btnCtrl    = _display displayCtrl (_buttonIdcs select _idx);
    private _accentCtrl = _display displayCtrl (_accentIdcs  select _idx);

    if (_itemIdx < _itemCount) then {
        private _entry = _items select _itemIdx;
        _entry params ["_label", "_type", "_payload"];

        private _isSelected = _itemIdx isEqualTo _selectedIndex;
        private _isSubmenu  = toLower _type == "submenu";

        private _displayText = format ["  %1%2",
            _label,
            if (_isSubmenu) then { "  >" } else { "" }
        ];

        _btnCtrl ctrlShow true;
        _btnCtrl ctrlEnable true;
        _btnCtrl ctrlSetText _displayText;
        _btnCtrl ctrlSetBackgroundColor ([_isSelected] call _getBtnColor);

        _accentCtrl ctrlShow true;
        _accentCtrl ctrlSetBackgroundColor ([_type, _label] call _getAccentColor);
    } else {
        _btnCtrl    ctrlShow false;
        _btnCtrl    ctrlEnable false;
        _btnCtrl    ctrlSetText "";
        _accentCtrl ctrlShow false;
    };

} forEach [0, 1, 2, 3, 4, 5];
