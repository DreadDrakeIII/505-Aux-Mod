params ["_index"];

private _menuId       = missionNamespace getVariable ["FEF_UI_CurrentMenu", "main"];
private _menus        = missionNamespace getVariable ["FEF_Menus", createHashMap];
private _items        = _menus getOrDefault [_menuId, []];
private _scrollOffset = missionNamespace getVariable ["FEF_UI_ScrollOffset", 0];

private _actualIndex = _index + _scrollOffset;

if (_actualIndex < 0 || {_actualIndex >= count _items}) exitWith {};

private _entry = _items select _actualIndex;
_entry params ["_label", "_actionType", "_payload"];
_actionType = toLower _actionType;

switch (_actionType) do {
    case "submenu": {
        missionNamespace setVariable ["FEF_UI_SelectedIndex", 0];
        missionNamespace setVariable ["FEF_UI_ScrollOffset", 0];
        [_payload, true] call FEF_fnc_renderMenu;
    };

    case "back": {
        missionNamespace setVariable ["FEF_UI_SelectedIndex", 0];
        missionNamespace setVariable ["FEF_UI_ScrollOffset", 0];
        [_payload, true] call FEF_fnc_renderMenu;
    };

    case "group": {
        _payload params ["_message", ["_voiceKey", ""]];
        // sendGroupMessage handles distribution via remoteExec to the group object — call once locally
        [_message, player, _voiceKey] call FEF_fnc_sendGroupMessage;
        [] call FEF_fnc_closeUI;
    };

    case "downalert": {
        [player] call FEF_fnc_sendFriendlyDownAlert;
        [] call FEF_fnc_closeUI;
    };

    case "reinsert": {
        [_payload, player] call FEF_fnc_sendReinsertRequest;
        [] call FEF_fnc_closeUI;
    };

    case "close": {
        [] call FEF_fnc_closeUI;
    };

    default {
        [] call FEF_fnc_closeUI;
    };
};
