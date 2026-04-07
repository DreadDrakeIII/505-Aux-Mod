params ["_display", "_key", "_shift", "_ctrl", "_alt"];

switch (_key) do {
    // ESC
    case 1: {
        private _menuId = missionNamespace getVariable ["FEF_UI_CurrentMenu", "main"];
        if (_menuId == "main") then {
            [] call FEF_fnc_closeUI;
        } else {
            missionNamespace setVariable ["FEF_UI_SelectedIndex", 0];
            missionNamespace setVariable ["FEF_UI_ScrollOffset", 0];
            ["main", true] call FEF_fnc_renderMenu;
        };
        true
    };

    // BACKSPACE
    case 14: {
        private _menuId = missionNamespace getVariable ["FEF_UI_CurrentMenu", "main"];
        if (_menuId == "main") then {
            [] call FEF_fnc_closeUI;
        } else {
            missionNamespace setVariable ["FEF_UI_SelectedIndex", 0];
            missionNamespace setVariable ["FEF_UI_ScrollOffset", 0];
            ["main", true] call FEF_fnc_renderMenu;
        };
        true
    };

    // ENTER
    case 28: {
        private _selectedIndex = missionNamespace getVariable ["FEF_UI_SelectedIndex", 0];
        [_selectedIndex] call FEF_fnc_onButtonClick;
        true
    };

    // SPACE
    case 57: {
        private _selectedIndex = missionNamespace getVariable ["FEF_UI_SelectedIndex", 0];
        [_selectedIndex] call FEF_fnc_onButtonClick;
        true
    };

    default { false };
};
