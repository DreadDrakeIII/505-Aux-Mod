/*
    File: fn_configureVehicleScrollBlock.sqf
    Purpose:
    Starts a lightweight per-frame watch (5 Hz) that keeps ACE's scroll-wheel
    self-interaction blocked for as long as the player is in any vehicle
    seat. Combined with the comms-wheel's own open/close calls via
    FEF_fnc_updateAceScrollBlock, so neither reason can accidentally unblock
    scroll while the other still needs it blocked.

    Toggle: FEF_VehicleScroll_BlockInVehicle (CBA setting, default true).
    One-shot - safe to call more than once, only the first call attaches the
    per-frame handler.
*/

if (!hasInterface) exitWith {};
if (missionNamespace getVariable ["FEF_VehicleScrollBlock_Wired", false]) exitWith {};
missionNamespace setVariable ["FEF_VehicleScrollBlock_Wired", true];

[{ call FEF_fnc_updateAceScrollBlock; }, 0.2, []] call CBA_fnc_addPerFrameHandler;
