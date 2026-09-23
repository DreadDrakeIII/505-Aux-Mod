/*
    File: fn_updateAceScrollBlock.sqf
    Purpose:
    Recomputes whether ACE's scroll-wheel self-interaction should be blocked,
    from two independent reasons:
      - the 505th comms wheel (this addon's own UI) being open
      - (if enabled) the player being inside any vehicle seat - driver,
        gunner, cargo, turret - so scrolling to zoom optics or cycle weapons
        does not also pop ACE's menu

    The actual ace_interact_menu_fnc_blockMouseWheel call only fires when the
    combined result changes, so this is safe to call as often as needed -
    including every frame from fn_configureVehicleScrollBlock's PFH - without
    spamming ACE.
*/

private _uiOpen = missionNamespace getVariable ["FEF_UI_Open", false];

private _vehicleBlock = false;
if (missionNamespace getVariable ["FEF_VehicleScroll_BlockInVehicle", true]) then {
    _vehicleBlock = (vehicle player) != player;
};

private _shouldBlock = _uiOpen || _vehicleBlock;
private _isBlocked   = missionNamespace getVariable ["FEF_AceScroll_Blocked", false];

if (_shouldBlock != _isBlocked) then {
    [_shouldBlock] call ace_interact_menu_fnc_blockMouseWheel;
    missionNamespace setVariable ["FEF_AceScroll_Blocked", _shouldBlock];
};
