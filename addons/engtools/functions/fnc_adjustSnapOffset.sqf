#include "..\script_component.hpp"
/*
 * Function: OLI_engtools_fnc_adjustSnapOffset
 * Adjusts snap placement offsets and updates the tablet display.
 *
 * Parameters:
 *   _axis  : String – "side", "fwd", or "reset"
 *   _delta : Number – amount to add (positive or negative)
 *
 * Side  = offset along the wall's long axis  (left / right of the wall line)
 * Fwd   = offset along the wall's facing dir (push in / pull out from face)
 *
 * Step: ±0.05m  |  Clamp: ±5.00m each axis
 *
 * Usage:
 *   ['side', 0.05] call FUNC(adjustSnapOffset)   // nudge right
 *   ['fwd', -0.05] call FUNC(adjustSnapOffset)   // nudge backward
 *   ['reset', 0]   call FUNC(adjustSnapOffset)   // zero both
 */

params [["_axis", "side", [""]], ["_delta", 0, [0]]];

// Init globals if needed
if (isNil "OLI_engtools_snapOfs_side") then { OLI_engtools_snapOfs_side = 0; };
if (isNil "OLI_engtools_snapOfs_fwd")  then { OLI_engtools_snapOfs_fwd  = 0; };

switch (_axis) do {
    case "side": {
        OLI_engtools_snapOfs_side = (OLI_engtools_snapOfs_side + _delta);
        // Round to nearest 0.05 to avoid float drift, clamp to ±5.00m
        OLI_engtools_snapOfs_side = ((round (OLI_engtools_snapOfs_side * 20)) / 20) max -5.0 min 5.0;
    };
    case "fwd": {
        OLI_engtools_snapOfs_fwd  = (OLI_engtools_snapOfs_fwd + _delta);
        OLI_engtools_snapOfs_fwd  = ((round (OLI_engtools_snapOfs_fwd * 20)) / 20) max -5.0 min 5.0;
    };
    case "reset": {
        OLI_engtools_snapOfs_side = 0;
        OLI_engtools_snapOfs_fwd  = 0;
    };
};

// ── Update tablet display ─────────────────────────────────────────────────────
disableSerialization;
private _display = findDisplay IDD_ENGINEER_DIALOG;
if (!isNull _display) then {

    private _sideCtrl = _display displayCtrl IDC_SNAPOFS_SIDE_DISP;
    private _fwdCtrl  = _display displayCtrl IDC_SNAPOFS_FWD_DISP;
    private _statCtrl = _display displayCtrl IDC_SNAPOFS_STATUS;

    // Format value: show sign explicitly e.g. "+0.15m" / "-0.10m" / "0.00m"
    private _fmtSide = if (OLI_engtools_snapOfs_side > 0) then {
        format ["+%1m", OLI_engtools_snapOfs_side]
    } else {
        format ["%1m", OLI_engtools_snapOfs_side]
    };
    private _fmtFwd = if (OLI_engtools_snapOfs_fwd > 0) then {
        format ["+%1m", OLI_engtools_snapOfs_fwd]
    } else {
        format ["%1m", OLI_engtools_snapOfs_fwd]
    };

    if (!isNull _sideCtrl) then { _sideCtrl ctrlSetText _fmtSide; };
    if (!isNull _fwdCtrl)  then { _fwdCtrl  ctrlSetText _fmtFwd;  };

    // Status line – highlights if offset is non-zero
    if (!isNull _statCtrl) then {
        private _isZero = (OLI_engtools_snapOfs_side == 0 && OLI_engtools_snapOfs_fwd == 0);
        if (_isZero) then {
            _statCtrl ctrlSetText "Side: 0.00m  Fwd: 0.00m  |  Note results per object type";
            _statCtrl ctrlSetTextColor [0.40, 0.60, 0.70, 0.80];
        } else {
            _statCtrl ctrlSetText format [
                "ACTIVE  Side: %1  Fwd: %2  |  Note good values per object",
                _fmtSide, _fmtFwd
            ];
            _statCtrl ctrlSetTextColor [1.0, 0.90, 0.40, 1.0];   // yellow when active
        };
    };
};

// ── Also show a quick in-world hint if currently in build mode ────────────────
if (!isNil QGVAR(buildingObject) && { !isNull GVAR(buildingObject) }) then {
    private _isZero = (OLI_engtools_snapOfs_side == 0 && OLI_engtools_snapOfs_fwd == 0);
    if (_isZero) then {
        hintSilent parseText "<t color='#00AAFF'>SNAP OFFSET</t><t color='#888888'> reset to zero</t>";
    } else {
        hintSilent parseText format [
            "<t color='#FFEE44'>SNAP OFFSET</t><br/><t color='#AAAAAA'>Side: </t><t color='#00AAFF'>%1</t>   <t color='#AAAAAA'>Fwd: </t><t color='#FFA500'>%2</t>",
            OLI_engtools_snapOfs_side, OLI_engtools_snapOfs_fwd
        ];
    };
};
