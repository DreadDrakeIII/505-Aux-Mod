// OLI_SUPPLY - postInit: server authority + client action wiring.

// ---------------------------------------------------------------------------
// SERVER: the only machine allowed to create crates, register a console or
// move a cooldown.
// ---------------------------------------------------------------------------
if (isServer) then {
    ["OLI_Supply_request", {_this call OLI_Supply_fnc_spawnCrate}] call CBA_fnc_addEventHandler;

    // Crates spawn with simulation off so PhysX cannot launch them out of the
    // console geometry. The carrying client says when it is safe to thaw.
    ["OLI_Supply_carryStarted", {
        params ["_netId"];
        private _crate = objectFromNetId _netId;
        if (isNull _crate) exitWith {};
        if (!simulationEnabled _crate) then {_crate enableSimulationGlobal true};
    }] call CBA_fnc_addEventHandler;
};

// ---------------------------------------------------------------------------
// CLIENTS
// ---------------------------------------------------------------------------
if (hasInterface) then {
    if (isNil "OLI_Supply_LocalConsoles") then {OLI_Supply_LocalConsoles = []};
    OLI_Supply_Wired = false;

    ["OLI_Supply_startCarry", {_this call OLI_Supply_fnc_startCarry}] call CBA_fnc_addEventHandler;

    // raised (with JIP) by OLI_Supply_fnc_registerConsole for props that are
    // not the shipped console class
    ["OLI_Supply_addActions", {
        params ["_console"];
        [_console] call OLI_Supply_fnc_addActions;
    }] call CBA_fnc_addEventHandler;

    ["OLI_Supply_message", {
        params ["_text"];
        [_text] call ace_common_fnc_displayTextStructured;
    }] call CBA_fnc_addEventHandler;

    // The action radius is baked into addAction, so wait for server-forced CBA
    // settings before attaching anything. "CBA_settingsInitialized" is an
    // EVENT, not a variable - CBA raises it one frame after postInit. The
    // timer is a safety net so a missed event can never leave the consoles
    // dead; fn_wireConsoles is one-shot, so only the first trigger counts.
    ["CBA_settingsInitialized", {call OLI_Supply_fnc_wireConsoles}] call CBA_fnc_addEventHandler;
    [{call OLI_Supply_fnc_wireConsoles}, [], 3] call CBA_fnc_waitAndExecute;
};
