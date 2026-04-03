#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_zeusSupplyDrop
 * Zeus module — Airdrop an Engineer Supply Pallet.
 *
 * Zeus places the module on the map → pallet spawns at 200m altitude above that
 * position, attaches a parachute, drifts with wind, and pops orange smoke on landing.
 * The pallet auto-loads 4x Engineer Supply Crates via initSupplyPallet.
 *
 * Can also be called directly (no logic object) to show a selection UI
 * for drop type: Supply Pallet, or standalone Small Crate.
 */

params [
    ["_logic", objNull, [objNull]],
    ["_units", [], [[]]],
    ["_activated", true, [true]]
];

if (!_activated) exitWith {};

// Get drop position from where Zeus placed the module
private _dropPos = if (!isNull _logic) then {
    private _pos = getPos _logic;
    deleteVehicle _logic;
    _pos
} else {
    // Fallback — shouldn't happen with module placement
    [0, 0, 0]
};

if (_dropPos isEqualTo [0, 0, 0]) exitWith {
    hint parseText "<t color='#FF4444'>Invalid drop position.</t>";
};

// ── Zeus UI: Select drop type ────────────────────────────────────────────────
private _curatorDisplay = findDisplay 312;
if (isNull _curatorDisplay) exitWith {
    // No Zeus display — just do a pallet drop directly
    [_dropPos, "pallet"] call FUNC(executeSupplyDrop);
};

private _allControls = [];

// Background
private _bg = _curatorDisplay ctrlCreate ["RscText", -1];
_bg ctrlSetPosition [0.33 * safezoneW + safezoneX, 0.34 * safezoneH + safezoneY, 0.34 * safezoneW, 0.24 * safezoneH];
_bg ctrlSetBackgroundColor [0.05, 0.08, 0.05, 0.96];
_bg ctrlCommit 0;
_allControls pushBack _bg;

// Accent bar
private _border = _curatorDisplay ctrlCreate ["RscText", -1];
_border ctrlSetPosition [0.33 * safezoneW + safezoneX, 0.34 * safezoneH + safezoneY, 0.34 * safezoneW, 0.003 * safezoneH];
_border ctrlSetBackgroundColor [0.20, 0.55, 0.28, 0.90];
_border ctrlCommit 0;
_allControls pushBack _border;

// Title
private _title = _curatorDisplay ctrlCreate ["RscStructuredText", -1];
_title ctrlSetPosition [0.335 * safezoneW + safezoneX, 0.348 * safezoneH + safezoneY, 0.33 * safezoneW, 0.05 * safezoneH];
_title ctrlSetStructuredText parseText
    "<t size='1.1' color='#FFA500' align='center'>SUPPLY DROP</t><br/><t size='0.9' color='#AAAAAA' align='center'>Select what to airdrop</t>";
_title ctrlCommit 0;
_allControls pushBack _title;

// ── Drop type buttons ────────────────────────────────────────────────────────
private _dropTypes = [
    ["Supply Pallet (4x Crates)", "pallet",  [0.12, 0.36, 0.17, 1.0], [0.18, 0.50, 0.24, 1.0]],
    ["Single Supply Crate",       "crate",   [0.10, 0.14, 0.30, 1.0], [0.14, 0.20, 0.42, 1.0]]
];

private _btnW   = 0.155 * safezoneW;
private _btnGap = 0.008 * safezoneW;
private _totalW = (count _dropTypes) * _btnW + ((count _dropTypes) - 1) * _btnGap;
private _startX = (0.33 * safezoneW + safezoneX) + (0.34 * safezoneW - _totalW) / 2;
private _btnY   = 0.42 * safezoneH + safezoneY;

{
    _x params ["_label", "_type", "_bgColor", "_activeColor"];
    private _btnX = _startX + _forEachIndex * (_btnW + _btnGap);

    private _btn = _curatorDisplay ctrlCreate ["RscButton", -1];
    _btn ctrlSetPosition [_btnX, _btnY, _btnW, 0.040 * safezoneH];
    _btn ctrlSetText _label;
    _btn ctrlSetFont "PuristaBold";
    _btn ctrlSetFontHeight 0.020;
    _btn ctrlSetTextColor [0.9, 0.95, 0.9, 1];
    _btn ctrlSetBackgroundColor _bgColor;
    _btn ctrlSetActiveColor _activeColor;
    _btn ctrlCommit 0;

    _btn setVariable [QGVAR(zeusDropType), _type];
    _btn setVariable [QGVAR(zeusDropPos), _dropPos];
    _btn setVariable [QGVAR(zeusDropCtrls), _allControls];

    _btn ctrlAddEventHandler ["ButtonClick", {
        params ["_ctrl"];
        private _type     = _ctrl getVariable QGVAR(zeusDropType);
        private _pos      = _ctrl getVariable QGVAR(zeusDropPos);
        private _controls = _ctrl getVariable QGVAR(zeusDropCtrls);

        { ctrlDelete _x } forEach _controls;

        [_pos, _type] call FUNC(executeSupplyDrop);
    }];

    _allControls pushBack _btn;
} forEach _dropTypes;

// Cancel button
private _cancelBtn = _curatorDisplay ctrlCreate ["RscButton", -1];
_cancelBtn ctrlSetPosition [
    (0.33 * safezoneW + safezoneX) + (0.34 * safezoneW - 0.08 * safezoneW) / 2,
    0.48 * safezoneH + safezoneY,
    0.08 * safezoneW,
    0.028 * safezoneH
];
_cancelBtn ctrlSetText "CANCEL";
_cancelBtn ctrlSetFont "PuristaMedium";
_cancelBtn ctrlSetFontHeight 0.018;
_cancelBtn ctrlSetTextColor [1, 0.7, 0.7, 1];
_cancelBtn ctrlSetBackgroundColor [0.30, 0.08, 0.08, 1];
_cancelBtn ctrlSetActiveColor [0.50, 0.12, 0.10, 1];
_cancelBtn ctrlCommit 0;

_cancelBtn setVariable [QGVAR(zeusDropCtrls), _allControls];
_cancelBtn ctrlAddEventHandler ["ButtonClick", {
    params ["_ctrl"];
    private _controls = _ctrl getVariable QGVAR(zeusDropCtrls);
    { ctrlDelete _x } forEach _controls;
    hint parseText "<t color='#888888'>Cancelled.</t>";
}];
_allControls pushBack _cancelBtn;

// Share controls reference
{ _x setVariable [QGVAR(zeusDropCtrls), _allControls]; } forEach _allControls;
