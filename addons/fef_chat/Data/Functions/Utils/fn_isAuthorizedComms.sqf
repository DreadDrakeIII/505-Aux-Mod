/*
 * Returns true if the unit is authorised to use restricted comms channels.
 * Authorised roles: Squad Leader, Pilot, Co-Pilot
 */
params [["_unit", player]];

if (isNull _unit) exitWith { false };

// Group/squad leader check
if (_unit isEqualTo leader group _unit) exitWith { true };

// Vehicle pilot check
private _vehicle = vehicle _unit;
if (!isNull _vehicle && _vehicle != _unit) then {
    private _roleStr = toLower (str (assignedVehicleRole _unit));
    if (_roleStr find "pilot" >= 0) exitWith { true };
};

false
