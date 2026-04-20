#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_buildHUD
 * Bottom-right build mode HUD — auto shown/hidden with build mode.
 * ctrlCreate on display 46 — no timing issues, always works.
 *
 * Parameters:
 *   _mode   - "show" | "update" | "hide"  [STRING]
 *   _status - status line structured text  [STRING, optional]
 *
 * Note: TAB is no longer used here — PiP camera and HUD auto-show
 * when an object is selected and auto-hide when build mode exits.
 */

params [
    ["_mode",   "update", [""]],
    ["_status", "",       [""]]
];

disableSerialization;
private _display = findDisplay 46;
if (isNull _display) exitWith {};

private _idcs = [IDC_BUILD_HUD_BG, IDC_BUILD_HUD_ACCENT, IDC_BUILD_HUD_STATUS, IDC_BUILD_HUD_HINT];

// ── HIDE ──────────────────────────────────────────────────────────────────────
if (_mode isEqualTo "hide") exitWith {
    { private _c = _display displayCtrl _x; if (!isNull _c) then { ctrlDelete _c; }; } forEach _idcs;
    GVAR(buildHUDActive) = false;
};

// ── SHOW ──────────────────────────────────────────────────────────────────────
if (_mode isEqualTo "show") exitWith {
    { private _c = _display displayCtrl _x; if (!isNull _c) then { ctrlDelete _c; }; } forEach _idcs;

    private _x  = 0.55 * safezoneW + safezoneX;
    private _w  = 0.45 * safezoneW;
    private _yT = 0.835 * safezoneH + safezoneY;
    private _h  = 0.160 * safezoneH;

    // Background
    private _bg = _display ctrlCreate ["RscText", IDC_BUILD_HUD_BG];
    _bg ctrlSetPosition [_x, _yT, _w, _h];
    _bg ctrlSetBackgroundColor [0.03, 0.05, 0.04, 0.93];
    _bg ctrlCommit 0;

    // Accent line
    private _accent = _display ctrlCreate ["RscText", IDC_BUILD_HUD_ACCENT];
    _accent ctrlSetPosition [_x, _yT, _w, 0.003 * safezoneH];
    _accent ctrlSetBackgroundColor [0.22, 0.65, 0.30, 1.0];
    _accent ctrlCommit 0;

    // Status line — updated every frame
    private _statusCtrl = _display ctrlCreate ["RscStructuredText", IDC_BUILD_HUD_STATUS];
    _statusCtrl ctrlSetPosition [_x + 0.008 * safezoneW, _yT + 0.006 * safezoneH, _w - 0.010 * safezoneW, 0.044 * safezoneH];
    _statusCtrl ctrlSetFont "PuristaBold";
    _statusCtrl ctrlSetFontHeight 0.034;
    _statusCtrl ctrlSetTextColor [1.0, 1.0, 1.0, 1.0];
    _statusCtrl ctrlSetStructuredText parseText "";
    _statusCtrl ctrlCommit 0;

    // Keybind hint — three lines, bright green
    private _hintCtrl = _display ctrlCreate ["RscStructuredText", IDC_BUILD_HUD_HINT];
    _hintCtrl ctrlSetPosition [_x + 0.008 * safezoneW, _yT + 0.056 * safezoneH, _w - 0.010 * safezoneW, 0.098 * safezoneH];
    _hintCtrl ctrlSetFont "PuristaMedium";
    _hintCtrl ctrlSetFontHeight 0.026;
    _hintCtrl ctrlSetTextColor [0.45, 0.90, 0.52, 1.0];
    _hintCtrl ctrlSetStructuredText parseText
        "<t>Scroll=Rotate | ALT+Scroll=Height | Ctrl+Scroll=Dist | PgUp/Dn=Height</t><br/><t>Q/E=Yaw | Shift+Q/E=Pitch | Ctrl+Q/E=Bank | SPACE=Slope | G=Gnd snap | Z/X=Nudge L/R | Shift+Z/X=Nudge F/B</t><br/><t>F=Obj snap | ALT=Terrain align | Backspace=Reset All | LMB=Place | RMB=Menu | Shift+RMB=Delete</t>";
    _hintCtrl ctrlCommit 0;

    GVAR(buildHUDActive) = true;
};

// ── UPDATE ────────────────────────────────────────────────────────────────────
if (!isNil QGVAR(buildHUDActive) && { GVAR(buildHUDActive) }) then {
    private _statusCtrl = _display displayCtrl IDC_BUILD_HUD_STATUS;
    if (!isNull _statusCtrl) then {
        _statusCtrl ctrlSetStructuredText parseText _status;
    };
};
