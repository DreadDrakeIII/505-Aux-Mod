// OLI_SUPPLY - SERVER ONLY. Validates the request, burns that option's
// cooldown, creates the crate and hands it to the requesting client to pick up.
//
// Crate cargo is never touched: whatever loot the class ships with is what
// the player gets.
//
// Arguments: 0: console <OBJECT>, 1: requesting unit <OBJECT>, 2: key <STRING>

params [["_console", objNull], ["_unit", objNull], ["_key", ""]];

if (!isServer) exitWith {};
if (isNull _console || {isNull _unit} || {!alive _unit} || {_key isEqualTo ""}) exitWith {};
if !(_unit isKindOf "CAManBase") exitWith {};
if !(isPlayer _unit) exitWith {};

// The object must actually be a console. Without this a client could nominate
// any nearby object and park the cooldown on a different rock every press.
if !(_console isKindOf "OLI_Supply_Console" || {_console getVariable ["OLI_Supply_IsConsole", false]}) exitWith {};

private _idx = OLI_Supply_Actions findIf {(_x select 0) == _key};
if (_idx < 0) exitWith {};

(OLI_Supply_Actions select _idx) params ["", "_name", "", "", "_classVar", "", "_cdVar", "", "_enabledVar"];

// Option turned off in the addon options. The client should not have shown an
// action for it at all, so this only catches a stale action or a forged event.
if !(missionNamespace getVariable [_enabledVar, true]) exitWith {
    ["OLI_Supply_message", [format ["%1 resupply is disabled on this mission", _name]], _unit] call CBA_fnc_targetEvent;
};

// Range guard. Generous multiple of the action radius so lag never trips it,
// tight enough that a replayed event from across the map spawns nothing.
private _maxRange = (missionNamespace getVariable ["OLI_Supply_ActionRadius", 4]) * OLI_Supply_ServerRangeFactor;
if (_unit distance _console > _maxRange) exitWith {};

// Cooldown is per console AND per option, shared by all players, checked here
// as well as on the client so a client cannot simply skip it.
private _cdName = [_key] call OLI_Supply_fnc_cooldownVar;
private _end = _console getVariable [_cdName, 0];
if (CBA_missionTime < _end) exitWith {
    ["OLI_Supply_message", [format ["%1 resupply recharging - %2", _name, [_end - CBA_missionTime] call OLI_Supply_fnc_formatTime]], _unit] call CBA_fnc_targetEvent;
};

private _class = missionNamespace getVariable [_classVar, ""];

if (_class isEqualTo "" || {!isClass (configFile >> "CfgVehicles" >> _class)}) exitWith {
    diag_log format ["[OLI_Supply] '%1' is not a CfgVehicles class - check CBA setting %2", _class, _classVar];
    ["OLI_Supply_message", [format ["%1 unavailable - crate class '%2' is not loaded", _name, _class]], _unit] call CBA_fnc_targetEvent;
};

// Burn this option's cooldown before creating anything. Public so every
// client - including one that joins later - renders the same counter.
private _cd = missionNamespace getVariable [_cdVar, 0];
if (_cd > 0) then {
    _console setVariable [_cdName, CBA_missionTime + _cd, true];
};

// Spawn the crate FROZEN, and on the player's own footprint rather than in
// front of them. A live PhysX object created 1.2 m ahead lands inside the
// console's collision geometry when the player is close and looking down;
// PhysX resolves that intersection by launching the crate, which reads in
// game as it blowing up on the floor. Frozen it cannot intersect anything,
// and the player's own position is by definition a clear spot to stand.
// fn_startCarry thaws it the moment ACE actually has it on their shoulder.
private _crate = createVehicle [_class, _unit modelToWorld [0, 0, 0], [], 0, "CAN_COLLIDE"];
_crate enableSimulationGlobal false;
_crate setDir (getDir _unit);
_crate setVariable ["OLI_Supply_Crate", _key, true];
_crate setVariable ["OLI_Supply_Source", _console, true];

// Global + JIP: anyone can pick the crate up later, including players who
// connect after it was spawned. ACE clears the JIP entry when the crate is
// deleted, so this does not leak. Position and direction are left nil on
// purpose, so a crate class with its own tuned ACE carry offset keeps it.
private _ignoreWeight = missionNamespace getVariable ["OLI_Supply_IgnoreWeight", true];
[_crate, true, nil, nil, _ignoreWeight, true] call ace_dragging_fnc_setCarryable;

// netId rather than the object itself: the event can outrun the crate's
// creation packet on a busy server, and a null object reference would not
// heal itself.
["OLI_Supply_startCarry", [_unit, netId _crate], _unit] call CBA_fnc_targetEvent;

// Safety net: if the client never confirms the carry - hands full, dropped
// connection, crate never replicated - thaw it anyway rather than leaving a
// frozen crate hanging in the world.
[{
    params ["_crate"];
    if (!isNull _crate && {!simulationEnabled _crate}) then {
        _crate enableSimulationGlobal true;
    };
}, [_crate], 6] call CBA_fnc_waitAndExecute;
