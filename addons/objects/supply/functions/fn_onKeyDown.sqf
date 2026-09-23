params ["_display", "_key", "_shift", "_ctrl", "_alt"];

switch (_key) do {
    // ESC
    case 1: {
        [] call OLI_Supply_fnc_closeMenu;
        true
    };

    // ENTER
    case 28: {
        private _selectedIndex = missionNamespace getVariable ["OLI_Supply_UI_SelectedIndex", 0];
        private _scrollOffset  = missionNamespace getVariable ["OLI_Supply_UI_ScrollOffset", 0];
        [_selectedIndex - _scrollOffset] call OLI_Supply_fnc_onSelect;
        true
    };

    // NUMPAD ENTER
    case 156: {
        private _selectedIndex = missionNamespace getVariable ["OLI_Supply_UI_SelectedIndex", 0];
        private _scrollOffset  = missionNamespace getVariable ["OLI_Supply_UI_ScrollOffset", 0];
        [_selectedIndex - _scrollOffset] call OLI_Supply_fnc_onSelect;
        true
    };

    // SPACE
    case 57: {
        private _selectedIndex = missionNamespace getVariable ["OLI_Supply_UI_SelectedIndex", 0];
        private _scrollOffset  = missionNamespace getVariable ["OLI_Supply_UI_ScrollOffset", 0];
        [_selectedIndex - _scrollOffset] call OLI_Supply_fnc_onSelect;
        true
    };

    // ALL OTHER KEYS - pass through so movement still works
    default { false };
};
