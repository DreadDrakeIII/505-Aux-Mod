#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_zeusAddResources
 * Zeus module function – adds engineer resources to a targeted unit.
 * Uses a scripted dialog (ctrlCreate) so no config dependency.
 */

params [
    ["_logic", objNull, [objNull]],
    ["_units", [], [[]]],
    ["_activated", true, [true]]
];

if (!_activated) exitWith {};

// Get the unit the module was placed on
private _target = objNull;

if (count _units > 0) then {
    _target = _units select 0;
};

if (isNull _target) then {
    _target = attachedTo _logic;
};

if (isNull _target || {!isPlayer _target}) then {
    private _near = (getPosATL _logic) nearEntities ["CAManBase", 5];
    _near = _near select {isPlayer _x};
    if (count _near > 0) then {
        _target = _near select 0;
    };
};

deleteVehicle _logic;

if (isNull _target || {!isPlayer _target}) exitWith {
    hint parseText "<t color='#FF4444'>Place module on a player unit to add resources.</t>";
};

// ── Build scripted dialog on the curator display ────────────────────────────
private _curatorDisplay = findDisplay 312; // Zeus display
if (isNull _curatorDisplay) exitWith {
    hint parseText "<t color='#FF4444'>Zeus display not found.</t>";
};

private _targetName = name _target;
private _currentRes = _target getVariable [QGVAR(resources), 0];

// Background overlay
private _bg = _curatorDisplay ctrlCreate ["RscText", -1];
_bg ctrlSetPosition [0.35 * safezoneW + safezoneX, 0.35 * safezoneH + safezoneY, 0.30 * safezoneW, 0.22 * safezoneH];
_bg ctrlSetBackgroundColor [0.05, 0.08, 0.05, 0.95];
_bg ctrlCommit 0;

// Border accent
private _border = _curatorDisplay ctrlCreate ["RscText", -1];
_border ctrlSetPosition [0.35 * safezoneW + safezoneX, 0.35 * safezoneH + safezoneY, 0.30 * safezoneW, 0.003 * safezoneH];
_border ctrlSetBackgroundColor [0.20, 0.55, 0.28, 0.90];
_border ctrlCommit 0;

// Title
private _title = _curatorDisplay ctrlCreate ["RscStructuredText", -1];
_title ctrlSetPosition [0.355 * safezoneW + safezoneX, 0.358 * safezoneH + safezoneY, 0.29 * safezoneW, 0.04 * safezoneH];
_title ctrlSetStructuredText parseText format [
    "<t size='1.1' color='#FFA500' align='center'>ADD ENGINEER RESOURCES</t><br/><t size='0.9' color='#AAAAAA' align='center'>%1  |  Current: %2</t>",
    _targetName, _currentRes
];
_title ctrlCommit 0;

// Amount buttons – 25, 50, 100, 200
private _amounts = [25, 50, 100, 200];
private _btnWidth = 0.065 * safezoneW;
private _btnGap   = 0.006 * safezoneW;
private _totalW   = (count _amounts) * _btnWidth + ((count _amounts) - 1) * _btnGap;
private _startX   = (0.35 * safezoneW + safezoneX) + (0.30 * safezoneW - _totalW) / 2;
private _btnY     = 0.44 * safezoneH + safezoneY;

private _allControls = [_bg, _border, _title];

{
    private _amount = _x;
    private _btnX = _startX + _forEachIndex * (_btnWidth + _btnGap);

    private _btn = _curatorDisplay ctrlCreate ["RscButton", -1];
    _btn ctrlSetPosition [_btnX, _btnY, _btnWidth, 0.035 * safezoneH];
    _btn ctrlSetText format ["+%1", _amount];
    _btn ctrlSetFont "PuristaBold";
    _btn ctrlSetFontHeight 0.024;
    _btn ctrlSetTextColor [0.85, 1.0, 0.85, 1];
    _btn ctrlSetBackgroundColor [0.10, 0.30, 0.14, 1];
    _btn ctrlSetActiveColor [0.18, 0.50, 0.24, 1];
    _btn ctrlCommit 0;

    _btn setVariable ["OLI_engtools_zeusAmount", _amount];
    _btn setVariable ["OLI_engtools_zeusTarget", _target];
    _btn setVariable ["OLI_engtools_zeusControls", _allControls];

    _btn ctrlAddEventHandler ["ButtonClick", {
        params ["_ctrl"];
        private _amount   = _ctrl getVariable "OLI_engtools_zeusAmount";
        private _target   = _ctrl getVariable "OLI_engtools_zeusTarget";
        private _controls = _ctrl getVariable "OLI_engtools_zeusControls";

        private _currentRes = _target getVariable [QGVAR(resources), 0];
        private _newRes = _currentRes + _amount;
        _target setVariable [QGVAR(resources), _newRes, true];

        hint parseText format [
            "<t color='#55CC66'>Added %1 resources to %2</t><br/><t color='#FFAA00'>New total: %3</t>",
            _amount, name _target, _newRes
        ];

        [parseText format ["<t color='#FFA500'>Zeus granted +%1 resources</t><br/><t color='#FFAA00'>Total: %2</t>", _amount, _newRes]]
            remoteExec ["hintSilent", _target];

        // Clean up all controls
        { ctrlDelete _x } forEach _controls;
    }];

    _allControls pushBack _btn;
} forEach _amounts;

// Cancel button
private _cancelBtn = _curatorDisplay ctrlCreate ["RscButton", -1];
_cancelBtn ctrlSetPosition [
    (0.35 * safezoneW + safezoneX) + (0.30 * safezoneW - 0.08 * safezoneW) / 2,
    0.49 * safezoneH + safezoneY,
    0.08 * safezoneW,
    0.030 * safezoneH
];
_cancelBtn ctrlSetText "CANCEL";
_cancelBtn ctrlSetFont "PuristaMedium";
_cancelBtn ctrlSetFontHeight 0.020;
_cancelBtn ctrlSetTextColor [1, 0.7, 0.7, 1];
_cancelBtn ctrlSetBackgroundColor [0.30, 0.08, 0.08, 1];
_cancelBtn ctrlSetActiveColor [0.50, 0.12, 0.10, 1];
_cancelBtn ctrlCommit 0;

_cancelBtn setVariable ["OLI_engtools_zeusControls", _allControls];
_cancelBtn ctrlAddEventHandler ["ButtonClick", {
    params ["_ctrl"];
    private _controls = _ctrl getVariable "OLI_engtools_zeusControls";
    { ctrlDelete _x } forEach _controls;
    ctrlDelete _ctrl;
    hint parseText "<t color='#888888'>Cancelled.</t>";
}];

_allControls pushBack _cancelBtn;

// Store controls ref on all buttons so cleanup catches everything
{
    if (!isNull _x) then {
        _x setVariable ["OLI_engtools_zeusControls", _allControls];
    };
} forEach _allControls;
