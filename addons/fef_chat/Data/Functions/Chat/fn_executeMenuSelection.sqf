/*
 * Menu item format:
 * [label, actionType, payload]
 *
 * actionType:
 * - submenu   : payload = menuId
 * - group     : payload = [messageText, voiceKey]
 * - downAlert : payload = []
 * - back      : payload = menuId
 * - close     : payload = ""
 * - reinsert  : payload = 1..5
 */

params ["_menuId", "_selectionIndex"];

private _debug = missionNamespace getVariable ["FEF_Chat_Debug", false];

private _menus = missionNamespace getVariable ["FEF_Menus", createHashMap];
if (isNil { _menus get _menuId }) exitWith {
    if (_debug) then {
        systemChat format ["[FEF Chat] Unknown menu id in selection: %1", _menuId];
    };
};

private _items = _menus get _menuId;
private _item = _items param [_selectionIndex, []];
if (_item isEqualTo []) exitWith {
    if (_debug) then {
        systemChat format ["[FEF Chat] Invalid selection index %1 for menu %2", _selectionIndex, _menuId];
    };
};

_item params ["_label", "_actionType", "_payload"];
_actionType = toLower _actionType;

if (_debug) then {
    systemChat format ["[FEF Chat] Selected %1 | Type %2 | Menu %3", _label, _actionType, _menuId];
};

private _openMenuDelayed = {
    params ["_nextMenuId"];

    if (_nextMenuId isEqualTo "") exitWith {};

    [_nextMenuId] spawn {
        params ["_nextMenuId"];
        uiSleep 0.05;
        [_nextMenuId] call FEF_fnc_openMenuById;
    };
};

switch (_actionType) do {
    case "submenu": {
        [_payload] call _openMenuDelayed;
    };

    case "back": {
        [_payload] call _openMenuDelayed;
    };

    case "group": {
        if !(_payload isEqualType []) exitWith {
            if (_debug) then {
                systemChat format ["[FEF Chat] Invalid group payload for %1", _label];
            };
        };

        _payload params ["_message", ["_voiceKey", ""]];
        [_message, player, _voiceKey] call FEF_fnc_sendGroupMessage;
        showCommandingMenu "";
    };

    case "downalert": {
        [player] call FEF_fnc_sendFriendlyDownAlert;
        showCommandingMenu "";
    };

    case "reinsert": {
        [_payload, player] call FEF_fnc_sendReinsertRequest;
        showCommandingMenu "";
    };

    case "close": {
        showCommandingMenu "";
    };

    default {
        if (_debug) then {
            systemChat format ["[FEF Chat] Unknown action type: %1", _actionType];
        };
        showCommandingMenu "";
    };
};