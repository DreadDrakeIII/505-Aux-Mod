#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_zeusAddResources
 * Zeus module — Add Engineer Resources to a side pool.
 * Step 1: Choose side (BLUFOR / OPFOR / INDFOR)
 * Step 2: Choose amount (+25 / +50 / +100 / +200)
 */

params [
    ["_logic", objNull, [objNull]],
    ["_units", [], [[]]],
    ["_activated", true, [true]]
];

if (!_activated) exitWith {};

deleteVehicle _logic;

private _curatorDisplay = findDisplay 312;
if (isNull _curatorDisplay) exitWith {
    hint parseText "<t color='#FF4444'>Zeus display not found.</t>";
};

// ── Shared cleanup helper ────────────────────────────────────────────────────
// Controls are tracked in a variable on each created ctrl; cleanup deletes all.

// ── Step 1: Side selection ───────────────────────────────────────────────────
private _allControls = [];

private _bg = _curatorDisplay ctrlCreate ["RscText", -1];
_bg ctrlSetPosition [0.33 * safezoneW + safezoneX, 0.32 * safezoneH + safezoneY, 0.34 * safezoneW, 0.28 * safezoneH];
_bg ctrlSetBackgroundColor [0.05, 0.08, 0.05, 0.96];
_bg ctrlCommit 0;
_allControls pushBack _bg;

private _border = _curatorDisplay ctrlCreate ["RscText", -1];
_border ctrlSetPosition [0.33 * safezoneW + safezoneX, 0.32 * safezoneH + safezoneY, 0.34 * safezoneW, 0.003 * safezoneH];
_border ctrlSetBackgroundColor [0.20, 0.55, 0.28, 0.90];
_border ctrlCommit 0;
_allControls pushBack _border;

private _title = _curatorDisplay ctrlCreate ["RscStructuredText", -1];
_title ctrlSetPosition [0.335 * safezoneW + safezoneX, 0.328 * safezoneH + safezoneY, 0.33 * safezoneW, 0.05 * safezoneH];
_title ctrlSetStructuredText parseText
    "<t size='1.1' color='#FFA500' align='center'>ADD ENGINEER RESOURCES</t><br/><t size='0.9' color='#AAAAAA' align='center'>Select a side pool to add resources</t>";
_title ctrlCommit 0;
_allControls pushBack _title;

// Current pool display
private _poolInfo = _curatorDisplay ctrlCreate ["RscStructuredText", -1];
_poolInfo ctrlSetPosition [0.335 * safezoneW + safezoneX, 0.375 * safezoneH + safezoneY, 0.33 * safezoneW, 0.04 * safezoneH];
private _bluRes  = [WEST]        call FUNC(getSideResources);
private _redRes  = [EAST]        call FUNC(getSideResources);
private _grnRes  = [INDEPENDENT] call FUNC(getSideResources);
_poolInfo ctrlSetStructuredText parseText format [
    "<t size='0.85' align='center'><t color='#5599FF'>BLU: %1</t>  <t color='#FF5555'>OPF: %2</t>  <t color='#55CC66'>IND: %3</t></t>",
    _bluRes, _redRes, _grnRes
];
_poolInfo ctrlCommit 0;
_allControls pushBack _poolInfo;

// Side buttons
private _sides = [
    ["BLUFOR",  WEST,        [0.08, 0.18, 0.45, 1.0], [0.14, 0.28, 0.65, 1.0]],
    ["OPFOR",   EAST,        [0.40, 0.08, 0.08, 1.0], [0.60, 0.12, 0.10, 1.0]],
    ["INDFOR",  INDEPENDENT, [0.10, 0.30, 0.14, 1.0], [0.18, 0.50, 0.24, 1.0]]
];

private _btnW   = 0.095 * safezoneW;
private _btnGap = 0.008 * safezoneW;
private _totalW = (count _sides) * _btnW + ((count _sides) - 1) * _btnGap;
private _startX = (0.33 * safezoneW + safezoneX) + (0.34 * safezoneW - _totalW) / 2;
private _btnY   = 0.43 * safezoneH + safezoneY;

{
    _x params ["_label", "_side", "_bgColor", "_activeColor"];
    private _btnX = _startX + _forEachIndex * (_btnW + _btnGap);

    private _sideBtn = _curatorDisplay ctrlCreate ["RscButton", -1];
    _sideBtn ctrlSetPosition [_btnX, _btnY, _btnW, 0.038 * safezoneH];
    _sideBtn ctrlSetText _label;
    _sideBtn ctrlSetFont "PuristaBold";
    _sideBtn ctrlSetFontHeight 0.022;
    _sideBtn ctrlSetTextColor [0.9, 0.95, 0.9, 1];
    _sideBtn ctrlSetBackgroundColor _bgColor;
    _sideBtn ctrlSetActiveColor _activeColor;
    _sideBtn ctrlCommit 0;

    _sideBtn setVariable ["OLI_engtools_zeusSide",     _side];
    _sideBtn setVariable ["OLI_engtools_zeusLabel",    _label];
    _sideBtn setVariable ["OLI_engtools_zeusAllCtrl",  _allControls];
    _sideBtn setVariable ["OLI_engtools_zeusBgColor",  _bgColor];
    _sideBtn setVariable ["OLI_engtools_zeusActColor", _activeColor];
    _sideBtn setVariable ["OLI_engtools_zeusCurator",  _curatorDisplay];

    _sideBtn ctrlAddEventHandler ["ButtonClick", {
        params ["_ctrl"];
        private _side          = _ctrl getVariable "OLI_engtools_zeusSide";
        private _label         = _ctrl getVariable "OLI_engtools_zeusLabel";
        private _allControls   = _ctrl getVariable "OLI_engtools_zeusAllCtrl";
        private _bgColor       = _ctrl getVariable "OLI_engtools_zeusBgColor";
        private _activeColor   = _ctrl getVariable "OLI_engtools_zeusActColor";
        private _curatorDisplay = _ctrl getVariable "OLI_engtools_zeusCurator";

        // Remove step-1 controls
        { ctrlDelete _x } forEach _allControls;

        // ── Step 2: Amount selection ─────────────────────────────────────────
        private _allCtrl2 = [];

        private _bg2 = _curatorDisplay ctrlCreate ["RscText", -1];
        _bg2 ctrlSetPosition [0.33 * safezoneW + safezoneX, 0.32 * safezoneH + safezoneY, 0.34 * safezoneW, 0.28 * safezoneH];
        _bg2 ctrlSetBackgroundColor [0.05, 0.08, 0.05, 0.96];
        _bg2 ctrlCommit 0;
        _allCtrl2 pushBack _bg2;

        private _border2 = _curatorDisplay ctrlCreate ["RscText", -1];
        _border2 ctrlSetPosition [0.33 * safezoneW + safezoneX, 0.32 * safezoneH + safezoneY, 0.34 * safezoneW, 0.003 * safezoneH];
        _border2 ctrlSetBackgroundColor _bgColor;
        _border2 ctrlCommit 0;
        _allCtrl2 pushBack _border2;

        private _currentRes = [_side] call FUNC(getSideResources);

        private _title2 = _curatorDisplay ctrlCreate ["RscStructuredText", -1];
        _title2 ctrlSetPosition [0.335 * safezoneW + safezoneX, 0.328 * safezoneH + safezoneY, 0.33 * safezoneW, 0.05 * safezoneH];
        _title2 ctrlSetStructuredText parseText format [
            "<t size='1.1' color='#FFA500' align='center'>%1 POOL</t><br/><t size='0.9' color='#AAAAAA' align='center'>Current: %2  |  Select amount to add</t>",
            _label, _currentRes
        ];
        _title2 ctrlCommit 0;
        _allCtrl2 pushBack _title2;

        // Amount buttons
        private _amounts = [25, 50, 100, 200];
        private _btnWidth = 0.065 * safezoneW;
        private _btnGap2  = 0.006 * safezoneW;
        private _totalW2  = (count _amounts) * _btnWidth + ((count _amounts) - 1) * _btnGap2;
        private _startX2  = (0.33 * safezoneW + safezoneX) + (0.34 * safezoneW - _totalW2) / 2;
        private _btnY2    = 0.42 * safezoneH + safezoneY;

        {
            private _amount = _x;
            private _btnX2 = _startX2 + _forEachIndex * (_btnWidth + _btnGap2);

            private _amtBtn = _curatorDisplay ctrlCreate ["RscButton", -1];
            _amtBtn ctrlSetPosition [_btnX2, _btnY2, _btnWidth, 0.035 * safezoneH];
            _amtBtn ctrlSetText format ["+%1", _amount];
            _amtBtn ctrlSetFont "PuristaBold";
            _amtBtn ctrlSetFontHeight 0.024;
            _amtBtn ctrlSetTextColor [0.85, 1.0, 0.85, 1];
            _amtBtn ctrlSetBackgroundColor _bgColor;
            _amtBtn ctrlSetActiveColor _activeColor;
            _amtBtn ctrlCommit 0;

            _amtBtn setVariable ["OLI_engtools_zeusAmount",   _amount];
            _amtBtn setVariable ["OLI_engtools_zeusSide2",    _side];
            _amtBtn setVariable ["OLI_engtools_zeusLabel2",   _label];
            _amtBtn setVariable ["OLI_engtools_zeusAllCtrl2", _allCtrl2];

            _amtBtn ctrlAddEventHandler ["ButtonClick", {
                params ["_ctrl2"];
                private _amount2   = _ctrl2 getVariable "OLI_engtools_zeusAmount";
                private _side2     = _ctrl2 getVariable "OLI_engtools_zeusSide2";
                private _label2    = _ctrl2 getVariable "OLI_engtools_zeusLabel2";
                private _controls2 = _ctrl2 getVariable "OLI_engtools_zeusAllCtrl2";

                private _currentRes2 = [_side2] call FUNC(getSideResources);
                private _newRes      = _currentRes2 + _amount2;
                [_side2, _newRes] remoteExec [QFUNC(setSideResources), 2];

                hint parseText format [
                    "<t color='#55CC66'>Added %1 resources to %2 pool</t><br/><t color='#FFAA00'>New total: %3</t>",
                    _amount2, _label2, _newRes
                ];

                // Notify all players on that side
                {
                    if (side _x == _side2 && isPlayer _x) then {
                        [parseText format [
                            "<t color='#FFA500'>Zeus granted +%1 resources to %2 pool</t><br/><t color='#FFAA00'>New total: %3</t>",
                            _amount2, _label2, _newRes
                        ]] remoteExec ["hintSilent", _x];
                    };
                } forEach allPlayers;

                { ctrlDelete _x } forEach _controls2;
            }];

            _allCtrl2 pushBack _amtBtn;
        } forEach _amounts;

        // Back button
        private _backBtn = _curatorDisplay ctrlCreate ["RscButton", -1];
        _backBtn ctrlSetPosition [
            (0.33 * safezoneW + safezoneX) + (0.34 * safezoneW - 0.08 * safezoneW) / 2 - 0.045 * safezoneW,
            0.475 * safezoneH + safezoneY,
            0.075 * safezoneW,
            0.028 * safezoneH
        ];
        _backBtn ctrlSetText "BACK";
        _backBtn ctrlSetFont "PuristaMedium";
        _backBtn ctrlSetFontHeight 0.018;
        _backBtn ctrlSetTextColor [0.8, 0.8, 0.8, 1];
        _backBtn ctrlSetBackgroundColor [0.15, 0.15, 0.15, 1];
        _backBtn ctrlSetActiveColor [0.25, 0.25, 0.25, 1];
        _backBtn ctrlCommit 0;

        _backBtn setVariable ["OLI_engtools_zeusAllCtrl2", _allCtrl2];
        _backBtn ctrlAddEventHandler ["ButtonClick", {
            params ["_ctrl2"];
            private _controls2 = _ctrl2 getVariable "OLI_engtools_zeusAllCtrl2";
            { ctrlDelete _x } forEach _controls2;
            ctrlDelete _ctrl2;
            // Re-open step 1 (call the module function again without a logic object)
            [] call FUNC(zeusAddResources);
        }];
        _allCtrl2 pushBack _backBtn;

        // Cancel button
        private _cancelBtn2 = _curatorDisplay ctrlCreate ["RscButton", -1];
        _cancelBtn2 ctrlSetPosition [
            (0.33 * safezoneW + safezoneX) + (0.34 * safezoneW - 0.08 * safezoneW) / 2 + 0.040 * safezoneW,
            0.475 * safezoneH + safezoneY,
            0.075 * safezoneW,
            0.028 * safezoneH
        ];
        _cancelBtn2 ctrlSetText "CANCEL";
        _cancelBtn2 ctrlSetFont "PuristaMedium";
        _cancelBtn2 ctrlSetFontHeight 0.018;
        _cancelBtn2 ctrlSetTextColor [1, 0.7, 0.7, 1];
        _cancelBtn2 ctrlSetBackgroundColor [0.30, 0.08, 0.08, 1];
        _cancelBtn2 ctrlSetActiveColor [0.50, 0.12, 0.10, 1];
        _cancelBtn2 ctrlCommit 0;

        _cancelBtn2 setVariable ["OLI_engtools_zeusAllCtrl2", _allCtrl2];
        _cancelBtn2 ctrlAddEventHandler ["ButtonClick", {
            params ["_ctrl2"];
            private _controls2 = _ctrl2 getVariable "OLI_engtools_zeusAllCtrl2";
            { ctrlDelete _x } forEach _controls2;
            ctrlDelete _ctrl2;
            hint parseText "<t color='#888888'>Cancelled.</t>";
        }];
        _allCtrl2 pushBack _cancelBtn2;

        // Share allCtrl2 to all buttons for cleanup
        { _x setVariable ["OLI_engtools_zeusAllCtrl2", _allCtrl2]; } forEach _allCtrl2;
    }];

    _allControls pushBack _sideBtn;
} forEach _sides;

// Cancel button (step 1)
private _cancelBtn1 = _curatorDisplay ctrlCreate ["RscButton", -1];
_cancelBtn1 ctrlSetPosition [
    (0.33 * safezoneW + safezoneX) + (0.34 * safezoneW - 0.08 * safezoneW) / 2,
    0.494 * safezoneH + safezoneY,
    0.08 * safezoneW,
    0.028 * safezoneH
];
_cancelBtn1 ctrlSetText "CANCEL";
_cancelBtn1 ctrlSetFont "PuristaMedium";
_cancelBtn1 ctrlSetFontHeight 0.018;
_cancelBtn1 ctrlSetTextColor [1, 0.7, 0.7, 1];
_cancelBtn1 ctrlSetBackgroundColor [0.30, 0.08, 0.08, 1];
_cancelBtn1 ctrlSetActiveColor [0.50, 0.12, 0.10, 1];
_cancelBtn1 ctrlCommit 0;

_cancelBtn1 setVariable ["OLI_engtools_zeusAllCtrl", _allControls];
_cancelBtn1 ctrlAddEventHandler ["ButtonClick", {
    params ["_ctrl"];
    private _controls = _ctrl getVariable "OLI_engtools_zeusAllCtrl";
    { ctrlDelete _x } forEach _controls;
    ctrlDelete _ctrl;
    hint parseText "<t color='#888888'>Cancelled.</t>";
}];
_allControls pushBack _cancelBtn1;

{ _x setVariable ["OLI_engtools_zeusAllCtrl", _allControls]; } forEach _allControls;
